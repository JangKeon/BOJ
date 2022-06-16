# Floyd - Warshall

모든 마을에서 각 마을까지 가는 최소 거리를 구하는 것이므로 플로이드 와샬 알고리즘을 사용해야 한다.

먼저 모든 Map 을 큰 수로 초기화해준 다음 i와 j가 같은 map[i][j]는 0으로 초기화해준다.

다음으로 버스 노선들을 입력받고 가는데 드는 weight을 넣어주는데, 이 때 한 마을에서 다른 마을로 가는 경로가 여러가지가 있을 수 있다고 했으니

map[start][end] = min(weight, map[start][end])로 초기화해주어야한다.

이후 플로이드 와샬 알고리즘을 사용한다.

for (int k = 1; k <= n; k++) {

		for (int i = 1; i <= n; i++) {
		
			for (int j = 1; j <= n; j++) {
			
				if (map[i][k] + map[k][j] < map[i][j]) {
				
					map[i][j] = map[i][k] + map[k][j];
					
				}
				
			}
			
		}
		
	}
