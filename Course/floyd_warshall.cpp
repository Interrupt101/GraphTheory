#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int n) {
    for(int k=0; k<n; k++)
    {
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(dist[i][k] < INF && dist[k][j] < INF)  
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}

int main() {
    int n = 4;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Example graph
    dist[0][1] = 5;
    dist[1][2] = 3;
    dist[2][3] = 1;
    dist[0][3] = 10;
    dist[3][0] = 2;

    floydWarshall(dist, n);

    cout << "Shortest distance matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
