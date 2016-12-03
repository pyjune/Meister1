#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int map[100][100];
int V[100][100];
int N;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};
int min;
int cnt; 
int bfs(int r, int c);
// 큐
typedef struct{
	int row;
	int col;
}PosType;
PosType Q[10000];
int front;
int rear;
void enQ(int r, int c);
PosType deQ(void);
 
int main(int argc, char *argv[]) {
	
	int tc, T;
	int i, j;
	int startR, startC;
	int r;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		front = -1;
		rear = -1;
		scanf("%d", &N);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				V[i][j] = 0;
				scanf("%1d", &map[i][j]);
				if(map[i][j]==2)
				{
					startR = i;
					startC = j;
				}
			}
		}
			
		min = bfs(startR, startC);
		printf("#%d %d\n", tc, min);
				
	}	
	
	
	return 0;
}

void enQ(int r, int c)
{
	++rear;
	Q[rear].row = r;
	Q[rear].col = c;
}
PosType deQ(void)
{
	return Q[++front];
}

int bfs(int r, int c)
{
	PosType n;
	int nr, nc;
	int i; 
	// 초기화..
	enQ(r, c);
	V[r][c] = 1;
	while(front!=rear)
	{
		n = deQ();
		// 인접 조사..
		for(i=0;i<4;i++)
		{
			nr = n.row + dr[i];
			nc = n.col + dc[i];
			if(map[nr][nc]!=1 && V[nr][nc]==0)
			{
				enQ(nr, nc);
				V[nr][nc] = V[n.row][n.col]+1;
				if(map[nr][nc]==3)
					return V[nr][nc]-2;
			}
		}
	}
	return 0; 
}
