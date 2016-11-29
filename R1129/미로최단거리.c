#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int map[100][100];
int N;
void dfs(int r, int c, int e);
void dfs2(int r, int c);
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int min;
int cnt; 

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
		min=0x7fffffff;
		// 경로의 수 
		cnt = 0;
		dfs2(startR, startC);
		printf("#%d %d\n", tc, cnt);
		/* 최단거리 
		dfs(startR, startC, 0);
		if( min == 0x7fffffff)
			min = 1;
		printf("#%d %d\n", tc, min-1);*/
	}	
	
	
	return 0;
}

void dfs2(int r, int c)
{
	int nr, nc;
	int i;
	if(map[r][c]==3)
	{
		cnt++;
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
				dfs2(nr, nc);
					
			} 
		}
		map[r][c] = 0;
	}
}


void dfs(int r, int c, int e)
{
	int nr, nc;
	int i;
	if(map[r][c]==3)
	{
		if(min>e)
			min = e;
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
				dfs(nr, nc, e+1);
					
			} 
		}
		map[r][c] = 0;
	}
}
