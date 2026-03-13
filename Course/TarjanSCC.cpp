#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TarjanSCC {
private:
    int n;
    vector<vector<int>> graph;
    vector<int> disc, low;
    vector<bool> inStack;
    stack<int> st;
    int timer;
    vector<vector<int>> sccs;

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for (int v : graph[u]) {
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // If u is the root of an SCC
        if (low[u] == disc[u]) {
            vector<int> scc;
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                scc.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(scc);
        }
    }

public:
    TarjanSCC(int vertices) : n(vertices) {
        graph.resize(n);
        disc.assign(n, -1);
        low.assign(n, -1);
        inStack.assign(n, false);
        timer = 0;
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i);
            }
        }
        return sccs;
    }
};

int main() {
    int n = 8; // number of vertices
    TarjanSCC tarjan(n);

    tarjan.addEdge(0, 1);
    tarjan.addEdge(1, 2);
    tarjan.addEdge(2, 0);
    tarjan.addEdge(2, 3);
    tarjan.addEdge(3, 4);
    tarjan.addEdge(4, 5);
    tarjan.addEdge(5, 3);
    tarjan.addEdge(6, 5);
    tarjan.addEdge(6, 7);
    tarjan.addEdge(7, 6);

    vector<vector<int>> sccs = tarjan.findSCCs();

    cout << "Strongly Connected Components:\n";
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
