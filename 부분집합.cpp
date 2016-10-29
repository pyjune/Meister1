#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int A[] = {1, 2, 3};
/*  부분집합
{}      000
{1}     100
{2}     010
{3}
{1, 2}  110
{2,3}
{1, 3}
{1, 2, 3}
*/

int A[100];
int L[100];
int cnt;
int cnt2;
void subset(int n, int k);
void subsetSum(int n, int k, int s);
void subsetSum2(int n, int k, int s, int ssum);
void subsetSum3(int n, int k, int s, int ssum, int tsum);

int main(int argc, char *argv[]) {
	int tc, T;
	int N, S;
	int i;
	int tsum;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);

	for (i = 0; i<100; i++)
	{
		A[i] = i + 1;
	}
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &S);
		cnt = 0;
		cnt2 = 0;
		tsum = (1 + N)*N / 2;
		//subsetSum(0, N, S);
		//subsetSum2(0, N, S, 0);
		subsetSum3(0, N, S, 0, tsum);
		printf("#%d %d %d\n", tc, cnt, cnt2);
	}
	//subset(0, 3); A[3] 인 경우... 
	return 0;
}
// 고려한 구간의 합이 s보다 크거나, 남은 구간의 합을 더해도 s보다 작으면 리턴
void subsetSum3(int n, int k, int s, int ssum, int tsum)
{
	int i;
	int sum = 0;
	if (n == k)
	{
		cnt2++;
		if (ssum == s)
		{
			cnt++;
		}
		//printf("\n");
	}
	else if ((ssum + tsum)<s)
	{
		return;
	}
	else if (ssum > s)
	{
		return;
	}
	else
	{
		L[n] = 0;
		subsetSum3(n + 1, k, s, ssum, tsum - A[n]);
		L[n] = 1;
		subsetSum3(n + 1, k, s, ssum + A[n], tsum - A[n]);
	}
}
// 고려한 구간의 합이 s보다 크면 리턴
void subsetSum2(int n, int k, int s, int ssum)
{
	int i;
	int sum = 0;
	if (n == k)
	{
		cnt2++;
		if (ssum == s)
		{
			cnt++;
		}
		//printf("\n");
	}
	else if (ssum > s)
	{
		return;
	}
	else
	{
		L[n] = 0;
		subsetSum2(n + 1, k, s, ssum);
		L[n] = 1;
		subsetSum2(n + 1, k, s, ssum + A[n]);
	}
}
// 모든 부분 집합의 합을 s와 비교
void subsetSum(int n, int k, int s)
{
	int i;
	int sum = 0;
	if (n == k)
	{
		cnt2++;
		for (i = 0; i<k; i++)
		{
			if (L[i] == 1)
			{
				sum += A[i];
				//printf("%d ", A[i]);
			}
		}
		if (sum == s)
		{
			cnt++;
		}
		//printf("\n");
	}
	else
	{
		L[n] = 0;
		subsetSum(n + 1, k, s);
		L[n] = 1;
		subsetSum(n + 1, k, s);
	}
}
// 모든 부분 집합을 만드는 경우
void subset(int n, int k)
{
	int i;
	if (n == k)
	{
		for (i = 0; i<k; i++)
		{
			if (L[i] == 1)
				printf("%d ", A[i]);
		}
		printf("\n");
	}
	else
	{
		L[n] = 0;
		subset(n + 1, k);
		L[n] = 1;
		subset(n + 1, k);
	}
}