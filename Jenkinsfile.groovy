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
        bat ".\\bin\\Win32\\release\\EveTest.exe"
    }
    

}