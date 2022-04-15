# DP

처음엔 동전의 종류마다 dp[n] = dp[n-value[i]] + 1 로 생각했다가, 이렇게 하면 같은 수의 반복은 체크할 수 없다는 것을 깨달았다.

따라서 동전의 종류만큼 for문, 그 안에 value[i] 부터 도달하고자 하는 k 값까의 for 문, 이중 for문 안에서 cost[j] = cost[j] + cost[j - value[i]] 가 점화식임을 구했다.
 