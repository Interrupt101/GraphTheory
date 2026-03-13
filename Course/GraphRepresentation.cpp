#include <iostream>
#include <vector>
using namespace std;

void print_matrix(const vector<vector<int>>& matrix);
void print_adj_list(const vector<vector<int>>& adj_list);

int main() {
    int n = 4; // number of vertices: 0,1,2,3
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    // add directed edges
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[1][2] = 1;
    matrix[2][3] = 1;
    matrix[3][1] = 1;
    
	print_matrix(matrix);
    
    
    vector<vector<int>> adj(n);
    // add directed edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    print_adj_list(adj);
    
    return 0;
}

void print_matrix(const vector<vector<int>>& matrix)
{
    cout << "Adjacency Matrix:\n";
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
void print_adj_list(const vector<vector<int>>& adj_list)
{
	cout << "Adjacency List:\n";
    for (size_t i = 0; i < adj_list.size(); i++) {
        cout << i << ": ";
        for (size_t v : adj_list[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
}
