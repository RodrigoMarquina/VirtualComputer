pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                echo 'Building..'
                sh "cmake -S ${WORKSPACE} -B ${WORKSPACE}/Build -DBUILD_TESTS=ON"
                dir("${WORKSPACE}/Build"){
                    sh 'make'
                }
            }
        }
        stage('Test') {
            steps {
                echo 'Testing..'
                dir("${WORKSPACE}/Build"){
                    sh 'ctest'
                }
            }
        }
    }
}
