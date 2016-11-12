#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int bat[10];
int N;
int min;
int cnt; 
void drive(int n, int k, int e, int c);

int main(int argc, char *argv[]) {
	int tc, T;
	int i;
	
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(i = 1;i<N;i++)
		{
			scanf("%d", &bat[i]);	
		}
		min = 100;
		cnt;
		// 첫 번째 정류장 부터
		// cnt는 종점에 도착하는 횟수 확인 용.. 
		drive(1, N, 0, 0);
		printf("#%d %d %d\n", tc, min-1, cnt);
		// 두 번째 정류장 부터..첫 번째는 무조건 교체하므로.. 
		//drive(2, N, bat[1]-1, 0);
		//printf("#%d %d\n", tc, min);
		
	}
	
	return 0;
}

void drive(int n, int k, int e, int c)
{
	if( n == k )
	{
		cnt++;
		if(min>c)
			min = c;
	}
	else if( c >= min) // 이 조건이 있을 때와 없을 때 cnt 비교.. 
	{
		return;
	}
	else
	{
		// 교체
		drive(n+1, k, bat[n]-1, c+1);
		// 통과
		if(e>0) 
			drive(n+1, k, e-1, c);
	}
	
}
