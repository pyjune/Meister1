#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int N;
char str[100][101];
char pattern[101];
int visited[100][100];
int find(int n, int row, int col);
 
int main(int argc, char *argv[]) {
	int T, tc;
	int i, j;
	int r;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N); // 글자판 크기 일기 
		scanf("%s", pattern); // 찾을 문자열 패턴읽기 
		// printf("%s\n", pattern); // 패턴 확인 
		for(i=0;i<N;i++)
		{
			scanf("%s", str[i]); // 글자판 읽기 
		}
		r = 0;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				visited[i][j] = 0; // 사용한 글자를 표시.. 
			}
		}
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(str[i][j]==pattern[0])
				{
					r=find(0, i, j); // 첫번째 글자를 찾으면 주변 탐색 
					if(r==1)
						break;
				}
			}
			if(r==1)
				break;
		}
		printf("#%d %d\n", tc, r);
	} 
	
	return 0;
}

int find(int n, int row, int col)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int nr, nc;
	int i;
	
	if(pattern[n]=='\0') // 패턴 전체와  일치 
	{
		return 1;
	}
	else if(str[row][col]!=pattern[n]) // 패턴과 다름 
	{
		return 0;
	}
	else
	{
		visited[row][col] = 1;
		for(i=0;i<4;i++)
		{
			nr = row+dr[i];
      nc = col+dc[i];
			if(nr>=0 && nr<N && nc>=0 && nc<N)
			{
				if(find(n+1, nr, nc))
					return 1;
			}
		}
		visited[row][col] = 0;
		return 0;
	}
} 
