# 분할 정복

처음엔 Z.cpp의 방법으로 , 그 다음엔 Z+.cpp의 방법으로 풀이하였다.

Z.cpp에서는 1X1단위가 아닌 4X4 단위로 묶어서 Draw함수를 따로 만들어 풀었다.
 이 때 이중배열 동적할당을 통해서 전체 Map을 만들었는데, 이것이 문제풀이 실패의 원인이 되었다. 너무 큰 사이즈로 인해서 문제에서 요구하는 메모리를 초과하여 사용한 것이다.

따라서 Z+.cpp에서 다시 1X1 사이즈 단위로 묶었다. 이번엔 각 사분면 별로 돌면서 요구하는 x, y 좌표가 있는지 확인하고 없으면 현재 나눠진 size에 대해서 size*size 만큼을 결과에 더해주는 방식으로 풀이하였다.

두 방법 모두 분할 정복으로 풀었지만, 한 번 실패함으로 인해 메모리에 대한 생각과 어떻게 하면 효율적으로 코드를 짜는 것인지에 대한 공부가 되었다.  