#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Kahn's algorithm
vector<int> topologicalSort(int V, const vector<vector<int>>& adj) {
	vector<int> indegree(V, 0);
	for(int u=0; u <V; u++)
	{
		for(int v : adj[u])
		{
			indegree[v]++;
		}
	}
	queue<int> q;
	for(int i=0; i <V; i++)
	{
		if(indegree[i] == 0)
			q.push(i);
	}
	vector<int> topo;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		topo.push_back(node);
		for(int neighbor : adj[node])
		{
			indegree[neighbor]--;
			if(indegree[neighbor] == 0)
				q.push(neighbor);
		}
	}
	
	if((int)topo.size() != V)
	{
		return {}; // topological sort not possible
	}
	
	return topo;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSort(V, adj);

    if (result.empty()) {
        cout << "Graph has a cycle. Topological sort not possible.\n";
    } else {
        cout << "Topological Order: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
