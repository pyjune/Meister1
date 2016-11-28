#include <stdio.h>
#include <stdlib.h>
/*
1   T
5 6 V E 정점개수, 간선수 
1 2 1 3 3 2 3 4 2 5 5 4  출발node->도착node * E 
*/

int adj[10][10];
int visited[10];
void dfs(int n, int k); // n 노드번호..k 노드 개수

int main(int argc, char *argv[]) {
	
	int tc, T;
	int V, E;
	int i, j;
	int n1, n2; 
	freopen("Text.txt","r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d %d", &V, &E);
		for(i=1;i<=V;i++)
		{
			visited[i] = 0;
			for(j=1;j<=V;j++)
			{
				adj[i][j] = 0; // 인접행렬 초기화 
			}
		}
		for(i=0;i<E;i++)
		{
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1; // 인접행렬 생성 
		}
		
		dfs(1, V); 
		
	}
	
	return 0;
}
// 방문 노드 번호 n, 마지막노드번호 k
void dfs(int n, int k)
{
	int i;
	visited[n] = 1;
	printf("%d ", n); // visit()
	for(i=1; i<=k; i++)
	{
		if(adj[n][i]==1 && visited[i]==0)
		{
			dfs(i, k);
		}
	}
}
