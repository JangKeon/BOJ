# Greedy Algorithm

그리디 알고리즘의 대표적인 문제이다.

회의가 시작되는 시간과 끝나는 시간을 Pair를 이루어 저장해준다.  이후 끝나는 시간 순으로 정렬을 해주고 F_Time이라는 변수를 만들어 제일 최근에 끝난 회의의 종료 시간을 저장해준다. 이 때 주의해야할 점은 만약 종료 시간이 같은 회의가 있으면 시작 시간이 빠른 순으로 정렬을 해주어야 한다.

Ex) 

(1, 3) (4, 8) (8, 8) => 가능한 회의의 개수 : 3개

(1, 3) (8, 8) (4, 8) => 가능한 회의의 개수 : 2개

이제 vec[0] 에 있는 회의를 첫 회의로 잡고 회의의 개수만큼 반복하며 vec[i]의 시작시간이 최근 회의종료시간보다 크거나 같으면 회의종료시간을 갱신하고 가능한 회의의 갯수를 증가시킨다.