#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;

int countIslands(char grid[MAX][MAX], int rows, int cols) {
    bool visited[MAX][MAX] = {false};
    int islands = 0;
    
    int dr[4] = {-1, 1, 0, 0}; //up, down
    int dc[4] = {0, 0, -1, 1}; //left, right
    
    for(int r=0; r < rows; r++)
    {
		for(int c=0; c < cols; c++)
		{
			if(grid[r][c] == '1' && !visited[r][c])
			{
				islands++;
				queue<pair<int, int>> q;
				q.push({r, c});
				visited[r][c] = true;
				
				while(!q.empty())
				{
					auto cell = q.front();
					q.pop();
					
					int x = cell.first;
					int y = cell.second;
					
					for(int i=0; i<4; i++)
					{
						int nx = x + dr[i];
						int ny = y + dc[i];
						
						if(nx >=0 && nx < rows && ny >=0 && ny < cols && grid[nx][ny] == '1' && !visited[nx][ny])
						{
							visited[nx][ny] = true;
							q.push({nx, ny});
						}
					}
					
				}
				
			}
		}
	}
	return islands;
}

int main() {
    int rows = 5, cols = 5;

    char grid[MAX][MAX] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
        {'1','0','0','1','1'}
    };

    cout << "Number of islands: " << countIslands(grid, rows, cols) << endl;

    return 0;
}

