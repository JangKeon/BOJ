# Dynamic Programming

우선 dp[i][0,1,2] 를 각각 i번째에 있는 집에 R.G.B 색을 칠하는 값의 최솟값이라고 한다.

하나의 색깔을 택했을 때 양 옆에 해당 색 말고 다른 색깔이 와야 되기 때문에

각 단계에서의 최솟값은 해당 자리를 칠할 때의 cost + min(전 단계에서 칠할 수 있는 색깔 두 개 중의 코스트) 이다.

마지막 N 단계에서 dp[N][0] , dp[N][1] , dp[N][2] 중 최솟값을 구하는 게 결과값이다. 