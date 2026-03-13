#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstraNaive(int n, const vector<vector<pair<int, int>>>& graph, int source) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    
    dist[source] = 0;
    
    for(int step=0; step < n; step++)
    {
		int u = -1;
		for(int i=0; i < n; i++)
		{
			if(!visited[i] && (u == -1 || dist[i] < dist[u]))
				u = i;
		}
		
		if(u == -1 || dist[u] == INF)
			break;
		
		visited[u] = true;
		
		// Relaxation
		for(auto edge : graph[u])
		{
			int v = edge.first;
			int w = edge.second;
			
			if(!visited[v] && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w ;
			}
		}	
	}
	
	// Print results :
	cout << "Shortest distances from vertex " << source << ":\n";
	for(int i=0; i < n; i++)
	{
		if(dist[i] == INF)
			cout << "Vertex " << i << ": INF\n";
		else
			cout << "Vertex " << i << ": " << dist[i] << "\n";
	}
}

int main() {
    int n = 4; // number of nodes: 0, 1, 2, 3
    vector<vector<pair<int, int>>> graph(n);

    // Add directed edges: graph[u].push_back({v, weight});
    graph[0].push_back({1, 4});
    graph[0].push_back({2, 1});
    graph[2].push_back({1, 2});
    graph[1].push_back({3, 1});
    graph[2].push_back({3, 5});

    int source = 0;
    dijkstraNaive(n, graph, source);

    return 0;
}
