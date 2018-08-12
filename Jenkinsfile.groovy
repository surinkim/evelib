node {

    stage('Checkout') {
        git branch: 'master',
            url: 'https://github.com/surinkim/evelib.git'
    }
    
    stage('Build'){
        bat "msbuild eve.sln /t:Rebuild /p:Configuration=Debug;Platform=x86"
        bat "msbuild eve.sln /t:Rebuild /p:Configuration=Release;Platform=x86"
    }
    
    stage('Test'){
        bat ".\\bin\\Win32\\release\\EveTest.exe --gtest_output=xml:result.xml"
    }
    
    stage('Publish Test Result'){
        
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


    
    

}