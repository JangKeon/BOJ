# Dynamic Programming

첫 시도 

행이 두 개 이기 때문에 vector[2]에 행별로 점수를 저장했다. 그리고 전체를 통틀어서 점화식 하나로 세우기 위해 

dp[n] = max(dp[i - 2] + score[~location[i - 1]][i - 1] + score[location[i - 1]][i], dp[i - 2] + score[~location[i - 1]][i]) 라는 내 머릿속만 알 수 있는 점화식을 세웠다(dp[n - 2] + 지그재그 순서대로 두 개, dp[n - 2] + 순서를 맞추지 않고 score[n] 하나).

하지만 문제가 풀리지 않았고 다른 방법을 찾아 시도 하게 된다...

두 번째 시도  

행이 두 개이기 때문에 행 별로 점화식을 세워주면 되는 것이었다.

따라서 dp[0][n]일 때와 dp[1][n]일 때의 점화식을 구해보면, 각각 dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + score[0][i] 과 dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + score[1] 로 쉽게 해결할 수 있었다.

