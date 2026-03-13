#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;

void bfs(int graph[MAX][MAX], int n, int start) {
    queue<int> q;
    bool visited[MAX] = {false};
    
    visited[start] = true;
    q.push(start);
    
    while(!q.empty())
    {
		int v = q.front();
		q.pop();
		
		cout << v << " ";
		for(int i=0; i<n; i++)
		{
			if(graph[v][i] == 1 && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
    int n = 5;

    int graph[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,0,1,1},
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,1,0,0,0}
    };

    int start = 0;

    cout << "BFS Traversal: ";
    bfs(graph, n, start);

    return 0;
}
