# 사고의 확장..?

생각지도 못하게 막힌 문제였다.

단순한 수 정렬이라고 생각해서 처음엔 vector에 넣고 sort()를 해주었다. 그런데 정답 처리가 안 되서 priority_queue를 사용해서 바로 정렬까지 되도록 했다.

하지만 그게 문제가 아니었다. 메모리가 8MB로 아주 적게 설정되어있었다. 

그제서야 입력되는 수가 10000 이하로 한정되어 있는 이유를 깨달았고, arr[10001] 을 선언해 입력되는 숫자마다 count 를 ++ 시켜주었다.

이후 1~10001까지 arr[i] 만큼 출력해주었다.