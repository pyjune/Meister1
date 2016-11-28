#include <stdio.h>
#include <stdlib.h>
/*
1   T
5 6 V E 정점개수, 간선수 
1 2 1 3 3 2 3 4 2 5 5 4  출발node->도착node * E 
*/

int adj[11][11];
int visited[11];
void dfs(int n, int k); // n 노드번호..k 노드 개수
// 경로의 수
int cnt; 
void dfs2(int n, int k);
// 최소 거리
int min;
void dfs3(int n, int k, int e);

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
		for(i=0;i<=V;i++)
		{
			visited[i] = 0;
			for(j=0;j<=V;j++)
			{
				adj[i][j] = 0; // 인접행렬 초기화 
			}
		}
		for(i=0;i<E;i++)
		{
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1; // 인접행렬 생성 
		}
		/*printf("#%d", tc);
		dfs(0, V);
		printf("\n");*/
		/*cnt=0;
		dfs2(0, V);
		printf("#%d %d\n", tc, cnt);*/
		cnt =0;
		min = 0x7fffffff;
		dfs3(0, V, 0);
		printf("#%d %d %d\n", tc, min, cnt);
	}
	return 0;
}
// 방문 노드 번호 n, 마지막노드번호 k
void dfs(int n, int k)
{
	int i;
	visited[n] = 1;
	printf(" %d", n); // visit()
	for(i=0; i<=k; i++)
	{
		if(adj[n][i]==1 && visited[i]==0)
		{
			dfs(i, k);
		}
	}
}
// 0에서 N번에 도착하는 경로의 개수 찾기 
void dfs2(int n, int k)
{
	int i;
	if(n==k)
	{
		cnt++;
	}
	else
	{
		visited[n] = 1;
		for(i=0; i<=k; i++)
		{
			if(adj[n][i]==1 && visited[i]==0)
			{
				dfs2(i, k);
			}
		}
		visited[n]=0;
	}
}
// 최소 거리.. 
void dfs3(int n, int k, int e)
{
	int i;
	if(n==k)
	{
		cnt++; // els if(min<=e) 부분의 효과를 확인하기 위해.. 
		if(min>e)
			min=e;
	}
	else if(min<=e)
		return;
	else
	{
		visited[n] = 1;
		for(i=0; i<=k; i++)
		{
			if(adj[n][i]==1 && visited[i]==0)
			{
				dfs3(i, k, e+1);
			}
		}
		visited[n]=0;
	}
}
