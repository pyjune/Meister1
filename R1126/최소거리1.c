#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
		for(i= 1; i<=N;i++)
		{
			//arr[i-1] = i+1; 
			used[i] = 0;
			min = 0x7fffffff;
			for(j = 1; j<=N;j++)
			{
				scanf("%d", &A[i][j]);
			}	
		}
		p[0] = 1;
		npr(1, N);
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
		// p[0]->p[1] :  첫번째 방문 순서 
		// p[1]->p[2] 
		for(i=1;i<k;i++)
		{
			sum += A[p[i-1]][p[i]];
		}
		sum +=A[p[i-1]][p[0]];
		if(min>sum)
			min = sum;
		
		/* // 일단 순열 생성 확인.. 
		for(i=0;i<k;i++)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
		*/
	}
	else
	{
		for(i=0;i<k-1;i++)
		{
			if(used[i]==0)
			{
				used[i] = 1;
				p[n] = i+2; // {1, 2, 3,...}
				// p[n] = arr[i];
				npr(n+1, k);
				used[i] = 0;
			}
		}
		
	}
}




