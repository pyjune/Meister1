#include <stdio.h>
#include <stdlib.h>

// 순열에 사용할 숫자를 배열에 따로 저장하는 경우.. 
int A[10][10];
int used[10];
int p[10];
int arr[10]; // 순열을 만들 숫자 
int min;
void npr(int n, int k);

int main(int argc, char *argv[]) {
	int tc, T;
	int i, j;
	int N;
	
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d", &N);
		for(i=0;i<N-1;i++)
		{
			arr[i] = i+2; // 2~N까지 순열에 사용할 숫자 저장 
		} 
		for(i= 1; i<=N;i++)
		{
			 
			used[i] = 0;
			min = 0x7fffffff;
			for(j = 1; j<=N;j++)
			{
				scanf("%d", &A[i][j]);
			}	
		}
		npr(0, N-1); // N-1개의 순열 생성.. 
		printf("#%d %d\n", tc, min);
		
	}	
	
	return 0;
}

void npr(int n, int k)
{
	int i;
	int sum=0;
	if(n==k)
	{
		sum = A[1][p[0]];	
		// 일단 순열 생성 확인.. 
		for(i=0;i<k-1;i++)
		{
			sum += A[p[i]][p[i+1]];
			//printf("%d ", p[i]);
		}
		//printf("\n");
		sum+=A[p[i]][1];
		if(min>sum)
			min = sum;
		
	}
	else
	{
		for(i=0;i<k;i++)
		{
			if(used[i]==0)
			{
				used[i] = 1;
				p[n] = arr[i];
				npr(n+1, k);
				used[i] = 0;
			}
		}
		
	}
}
