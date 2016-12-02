#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 11
int Q[Q_SIZE];
void enQ(int n);
int deQ(void);
int front = -1;
int rear = -1;
int adj[11][11];
int visited[11];
void bfs(int s, int k);
/*

*/
int main(int argc, char *argv[]) {
	int V, E;
	int i, j;
	int n1, n2;
	int tc, T; 
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d %d", &V, &E);
		for(i=0;i<=V;i++)
		{
			visited[i] = 0;
			for(j=0;j<=V;j++)
			{
				adj[i][j] = 0;
			}
		}
		front = -1;
		rear = -1;
		for(i=0;i<E;i++)
		{
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1;
		}
		bfs(0, V);
		printf("#%d %d\n", tc, visited[V]-1);
	}
	return 0;
}

void bfs(int s, int k)
{
	int n;
	int i;
	// 초기화
	enQ(s);
	visited[s] = 1;
	// 반복
	while(front!=rear) // while(is_not_emptyQ())
	{
		n = deQ();
		printf("%d ", n);
		for(i=0;i<=k;i++)
		{
			if(adj[n][i]==1&&visited[i]==0)
			{
				//n에 인접이면서 방문하지 않았으면
				enQ(i);
				visited[i] = visited[n]+1; 
			}
		}
	} 
}

void enQ(int n)
{
	if( rear == Q_SIZE-1 )
		printf("Overflow!\n");
	Q[++rear] = n;
}

int deQ(void)
{
	if( front == rear )
	{
		printf("Empty!\n");
		return -1;	
	}
	return Q[++front];
}
