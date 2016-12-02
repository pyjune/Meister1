#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 10
int Q[Q_SIZE];
void enQ(int n);
int deQ(void);
int front = -1;
int rear = -1;
int adj[10][10];
int visited[10];
void bfs(int s, int k);
/*

*/
int main(int argc, char *argv[]) {
	int V, E;
	int i;
	int n1, n2;
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for(i=0;i<E;i++)
	{
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
	}
	bfs(1, V);
		
/*	enQ(1);
	enQ(2);
	enQ(3);
	printf("%d\n", deQ());
	printf("%d\n", deQ());
	printf("%d\n", deQ());
*/	return 0;
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
		for(i=1;i<=k;i++)
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















