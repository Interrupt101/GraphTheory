#include <iostream>
using namespace std;

const int MAX = 100;

void dfs(int graph[MAX][MAX], int n, int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	
	for(int i=0; i < n; i++)
	{
		if(graph[v][i] == 1 && !visited[i])
		{
			dfs(graph, n, i, visited);
		}
	}
}

int main()
{
    int n = 5; // Number of vertices

    int graph[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,1,0,0,0}
    };

    int start = 0;
    bool visited[MAX] = {false};

    cout << "DFS Traversal: ";
    dfs(graph, n, start, visited);

    return 0;
}
