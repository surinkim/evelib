node {
    stage('Checkout') {
        checkout([$class: 'GitSCM',
              branches: [[name: '*/master']],
              doGenerateSubmoduleConfigurations: false,
              extensions: [[$class: 'SubmoduleOption',
                            disableSubmodules: false,
                            parentCredentials: false,
                            recursiveSubmodules: true,
                            reference: '',
                            trackingSubmodules: false]], 
              submoduleCfg: [], 
              userRemoteConfigs: [[url: 'https://github.com/surinkim/evelib.git']]])
    }

    stage('Build'){
        bat "msbuild eve.sln /t:Rebuild /p:Configuration=Debug;Platform=x86"
        bat "msbuild eve.sln /t:Rebuild /p:Configuration=Release;Platform=x86"
    }
    
    stage('Test'){
        bat ".\\bin\\Win32\\release\\EveTest.exe --gtest_output=xml:result.xml"
    }
    
    stage('Save Test Result'){
        
        step([$class: 'XUnitPublisher', testTimeMargin: '3000', thresholdMode:
            2,
            thresholds: [
             [$class: 'FailedThreshold', failureNewThreshold: '', failureThreshold: '0', unstableNewThreshold: '', unstableThreshold: ''],
             [$class: 'SkippedThreshold', failureNewThreshold: '', failureThreshold: '0', unstableNewThreshold: '', unstableThreshold: '']
            ],
            tools: [
             [$class: 'GoogleTestType', deleteOutputFiles: true, failIfNotNew: true, pattern: '\\**\\result.xml', skipNoTestFiles: false, stopProcessingIfError: true]
            ]
           ])
        
    }
    
    stage('Archive') {
        archiveArtifacts 'bin\\Win32\\Release\\Eve.lib'
    }

}