# DFS

이중배열의 Map을 만드는 전형적인 DFS 문제 중 하나이다. 

단지에 집이 있는지 없는지를 나타내는 빌딩 이중 배열과 방문했는지 안 했는지를 나타내는 visit 이중 배열을 만들어 놓고 단지의 정보를 입력받는다. (여기서 단지가 1일 때 해당 위치가 아닌 x+1, y+1 의 위치에 집이 있다고 표시해준다. 탐색 시 패딩을 위해서.)

이후 연결되어 있는 집을 탐색하는데, 이 때 연결되어 있는 집이 몇 가구인지를 찾기 위해서 dfs 함수를 돌릴 때마다 cnt 가 +1 되도록 만들고 연결 되어 있는 집의 탐색이 모두 끝나면 vector에 cnt 값을 푸시해서 저장했다.

그리고 나는 main에서 dfs 함수가 실행될 때마다 result 의 값을 +1 해주는 걸로 전체 단지의 수를 구했는데, 생각해보니 그럴 필요 없이 vector의 size 자체가 단지수였다.
