/*
    Time Complexity - O(N * M)
    Space Complexity - O(N * M)

    where N and M are the number of rows and columns of
    the grid respectively.
*/


#include <queue>


int isValid(vector<vector<bool>>& visited, int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m && visited[i][j] == false;
}

// BFS solution.
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int time = 0;

    // 2D array to mark visited cells.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    // Queue for BFS.
    queue<pair<int, int>> q;

    // Push all the rotten oranges into the queue as level 0.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }

    int i, j;

    // Array for exploring all 4 directions.
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while(q.size() > 0)
    {
        // Current level size.
        int levelSize = q.size();

        while(levelSize--)
        {
            pair<int,int> currCell = q.front();
            q.pop();

            i = currCell.first;
            j = currCell.second;
            
            // Check all adjacent cells and push them in queue, if fresh and valid.
            for(int k = 0; k < 4; k++)
            {
                int nextI = i + dx[k];
                int nextJ = j + dy[k];

                if(isValid(visited, nextI, nextJ, n, m) && grid[nextI][nextJ] == 1)
                {
                    q.push({nextI, nextJ});
                    visited[nextI][nextJ] = true;
                }
            }
        }

        // Increment time for next level.
        time++;
    }

    // If a fresh orange is still present, return -1.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 && visited[i][j] == false)
            {
                return -1;
            }
        }
    }

    // Return time elapsed.
    return max(0, time - 1);
}
