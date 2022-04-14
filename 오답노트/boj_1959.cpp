/*
(n/2, n/2) 에서 시작하는 경우 상>우>하>좌 순으로 방향이 돌아가고
방향이 바뀌지 않은 상태로 최대 진행할 수 있는 칸 수는 1 1 2 2 3 3 4 4 ... 의 순열을 따른다!
=> 방향이 두번 바뀔 때마다 움직일 수 있는 칸이 1칸씩 늘어난다.

상우하좌 4개의 상태가 반복되기 때문에 모듈러 연산 사용하면 효과적!
d = (d+1) % 4; => 아 이게 d = d > 4 ? 1: 4; 이거랑 같은거

디렉션은 아래처럼 표현할 수 있음;
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

사용은
curR -= dr[dir];
curC -= dc[dir];
*/



//규칙찾으면 대충 이런 느낌
#include <stdio.h>
int main(){
	int  m,n;
	scanf("%d%d",&m,&n);
	if(m>n) printf("%lld\n",(long long)(n-1)*2+1);
	else printf("%lld\n",(long long)(m-1)*2);
	if (m==n){
		if(m%2==1) printf("%d %d",(m-1)/2+1,(m-1)/2+1);
		else printf("%d %d",(m)/2+1,(m)/2);
	}
	else{
		if(n>m){
			if(m%2==0) printf("%d %d",(m)/2+1,(m)/2);
			else printf("%d %d",(m-1)/2+1,(m-1)/2+1+n-m);
		}
		else{
			if(n%2==0) printf("%d %d",(n)/2+1,(n)/2);
			else printf("%d %d",(n-1)/2+1+m-n,(n-1)/2+1);
		}
	}
}