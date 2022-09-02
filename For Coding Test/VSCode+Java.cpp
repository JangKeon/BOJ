/*[VSCode 에서 Spring Boot 실행시켰을 때 jdk 버전 오류 공유]

선행 과정 : 컴퓨터 - 설정 - 고급 설정에서 JAVA_HOME, MVN_HOME 환경변수 설정 필수

위와 같이 환경 변수를 설정해도 해결이 되지 않으면 "Configure Runtime for Language Server" 라는 오류 메세지가 나올 확률이 큽니다.
이는 VSCode 내 확장 프로그램인 RED HAT에서 jdk 버전을 11 이상을 사용해야만 하기 때문에 나오는 오류로, 참고자료3에 있는 Configure 확인 부분을 따라 하셔서 최신 jdk 버전을 다운로드 하시면 됩니다.
이후 VSCode에서 File > Preference > Settings 의 검색창에 "java.home"을 검색하면 "Edit in settings.json" 파일이 나올텐데 새로 받은 jdk의 경로를 지정해 주면 오류가 해결됩니다.

참고자료 :
1) https://sogno-ing.tistory.com/166 (환경변수 설정)
2) https://www.baeldung.com/maven-java-home-jdk-jre (JAVA_HOME path jre가 아닌 jdk로 설정)
3) https://velog.io/@leemr31/VS-Code%EC%97%90-java%ED%99%98%EA%B2%BD-%EC%84%B8%ED%8C%85%ED%95%98%EA%B8%B0Windows-OS (VSCode, Java 연동)
*/