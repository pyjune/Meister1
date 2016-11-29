#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int map[10][10];
int min;
int N, M;
int dr[] = {0, 1};
int dc[] = {1, 0};
void find(int r, int c, int s);
int cnt;
int main(int argc, char *argv[]) {
	
	int tc, T;
	int i, j;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d %d", &N, &M);
		for(i = 0; i<N; i++)
		{
			for(j=0;j<M;j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		cnt = 0;
		min = 0x7fffffff;
		find(0, 0, 0);
		printf("#%d %d %d\n", tc, min, cnt);
	}
	
	
	return 0;
}

void find(int r, int c, int s)
{
	int nr, nc;
	int i;
	if(r==N-1&&c==M-1)
	{
		cnt++;
		if(min>(s+map[r][c]))
			min = s+map[r][c];
	}
	else if(s>=min)
	{
		return;
	}
	else
	{
		for(i=0;i<2;i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if(nr<N&&nc<M)
			{
				find( nr, nc, s+map[r][c]);
			}
		}
	}
}
