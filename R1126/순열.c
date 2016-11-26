#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int A[] = {1, 2, 3, 4, 5};
int P[5];
int used[5];
int cnt;
// 주어진 숫자를 모두 이용하는 경우 
void perm(int n, int k);
// 5개 중에 3개를 고르는 경우처럼 일부만 사용하는 경우 
void perm2(int n, int k, int l);

int main(int argc, char *argv[]) {
	
	
	//perm(0, 5);
	perm2(0, 3, 5); 
	//printf("%d\n", cnt);
	return 0;
}

void perm2(int n, int k, int l)
{
	int i;
	if(n==k)
	{
		cnt++;
		for(i=0;i<k;i++)
			printf("%d ", P[i]);
		printf("\n");
	}	
	else
	{
		for(i=0;i<l;i++)
		{
			if(used[i]==0)
			{
				used[i]=1;
				P[n] = A[i];
				perm2(n+1, k, l);
				used[i]=0;
			}
		}
	}
	
}


void perm(int n, int k)
{
	int i;
	if(n==k)
	{
		for(i=0;i<k;i++)
			printf("%d ", P[i]);
		printf("\n");
	}	
	else
	{
		for(i=0;i<k;i++)
		{
			if(used[i]==0)
			{
				used[i]=1;
				P[n] = A[i];
				perm(n+1, k);
				used[i]=0;
			}
		}
	}
	
}
