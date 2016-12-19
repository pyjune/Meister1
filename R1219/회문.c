#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char str[100][101]; // 최대 길이가 100인 문자열을 최대 100개 저장 
int main(int argc, char *argv[]) {
	
	int tc, T;
	int N, M;
	int i, j, k;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d %d", &N, &M);
		for(i=0;i<N;i++)
		{
			scanf("%s", str[i]); // 각 문자열을 저장할 주소 
			//printf("%s\n", str[i]); // 입력 확인 
		}
		printf("#%d ", tc);
		for(i=0;i<N;i++) // 가로 회문 
		{
			for(j=0;j<=N-M;j++) // 회문을 검사하는 첫 글자.. 
			{
				for(k=0;k<M/2;k++)
				{
					if(str[i][j+k]!=str[i][j+M-1-k])
						break;
				}
				if(k==M/2) // 회문 발견..
					break;
			}
			if(k==M/2) // 회문 발견..
					break;
		}
		if(k==M/2) // 회문 발견.. 
		{
			for(k=0;k<M;k++)
				printf("%c", str[i][j+k]);
			printf("\n");
		}
		for(i=0;i<N;i++) // 세로 회문 
		{
			for(j=0;j<=N-M;j++) // 회문을 검사하는 첫 글자.. 
			{
				for(k=0;k<M/2;k++)
				{
					if(str[j+k][i]!=str[j+M-1-k][i])
						break;
				}
				if(k==M/2) // 회문 발견..
					break;
			}
			if(k==M/2) // 회문 발견..
					break;
		}
		if(k==M/2) // 회문 발견.. 
		{
			for(k=0;k<M;k++)
				printf("%c", str[j+k][i]);
			printf("\n");
		}
	}
	return 0;
}
