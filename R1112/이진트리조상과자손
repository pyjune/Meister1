#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int ch1[1001];
int ch2[1001];
int p[1001];
int E;
int N;
int find(int n);
void DLR(int n);
void LDR(int n);
void LRD(int n);
int cnt; 
int main(int argc, char *argv[]) {
	int tc, T;
	int i;
	int n1, n2;
	int root;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for( tc = 1; tc <= T; tc++)
	{
		for(i=1;i<=E+1;i++)
		{
			ch1[i] = 0;
			ch2[i] = 0;
			p[i] = 0;
		}
		scanf("%d %d", &E, &N);
		cnt = 0;
		for(i=0;i<E;i++)
		{
			scanf("%d %d", &n1, &n2);
			// 부모를 인덱스로 자식 번호 저장 
			if(ch1[n1]==0)
				ch1[n1]=n2;
			else
				ch2[n1]=n2;
			// 자식을 인덱스로 부모 번호 저장 
			p[n2] = n1;
		}
		/* // 순회 연습을 위한 root 찾기.. 
		for(i = 1; i<=E+1;i++)
		{
			if(p[i]==0)
			{
				root = i;
				break;
			}
		}*/
		DLR(N);
		printf("#%d %d %d\n", tc, find(N), cnt-1);
		/* // 순회 연습.. 
		printf("#%d\n", tc);
		DLR(root);
		printf("\n");
		LDR(root);
		printf("\n");
		LRD(root);
		printf("\n");
		*/
		
	}
	
	return 0;
}
// 조상 찾기 
int find(int n)
{
	int c = n;
	int cnt = 0;
	while(p[c]!=0)
	{
		cnt++;
		c=p[c];
	}
	return cnt;
}
void DLR(int n)
{
	//printf("%d ", n);
	cnt++;
	if(ch1[n]!=0)
		DLR(ch1[n]);
	if(ch2[n]!=0)
		DLR(ch2[n]);
}
void LDR(int n)
{
	if(ch1[n]!=0)
		LDR(ch1[n]);
	printf("%d ", n);
	if(ch2[n]!=0)
		LDR(ch2[n]);
}
void LRD(int n)
{
	if(ch1[n]!=0)
		LRD(ch1[n]);
	if(ch2[n]!=0)
		LRD(ch2[n]);
	printf("%d ", n);
}
