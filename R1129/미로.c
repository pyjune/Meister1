#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int map[100][100];
int N;
int dfs(int r, int c);
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

int main(int argc, char *argv[]) {
	
	int tc, T;
	int i, j;
	int startR, startC;
	int r;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d", &N);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%1d", &map[i][j]);
				if(map[i][j]==2)
				{
					startR = i;
					startC = j;
				}
			}
		}
		r = dfs(startR, startC);
		printf("#%d %d\n", tc, r);
	}	
	
	
	return 0;
}

int dfs(int r, int c)
{
	int nr, nc;
	int i;
	if(map[r][c]==3)
	{
		return 1;
	}
	else
	{
		map[r][c] = 1; // 방문한 곳은 벽으로 처리.. 
		for(i=0; i<4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if(map[nr][nc] != 1) // 벽으로 둘러쌓인 미로라 유효좌표 검사 안함. 
			{
				if(dfs(nr, nc) == 1)
					return 1;
			} 
			
		}
		return 0;
	}
}
