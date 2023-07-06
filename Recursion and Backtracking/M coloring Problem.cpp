/*
        Time Complexity - O(M ^ V)
        Space Complexity - O(V)

        where V is the number of vertices in the graph
        and M is the maximum number of colors allowed
*/

bool isCorrect(vector<vector<int>> &mat, int cur, vector<int> &color, int col)
{
	// Check if there any adjacent node with same color.
	for (int i = 0; i < mat.size(); ++i)
	{
		if (mat[cur][i] && color[i] == col)
		{
			return false;
		}
	}

	return true;
}

bool graphCol(vector<vector<int>> &mat, int m, int cur, vector<int> &color)
{
	if (cur == mat.size())
	{
		return true;
	}

	// Try to color from 1 to 'm'.
	for (int j = 1; j <= m; ++j)
	{
		if (isCorrect(mat, cur, color, j))
		{
			// Color current vertex with 'j' and try to color
			// rest of the graph.
			color[cur] = j;
			if (graphCol(mat, m, cur + 1, color))
			{
				return true;
			}

			// Return the color from the vertex.
			color[cur] = 0;
		}
	}

	return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
	int v = mat.size();

	// An array to maintain the color of any mode.
	vector<int> color(v, 0);

	// If graph can be colored using atmost 'm' color,
	// return true, else return false.
	if (graphCol(mat, m, 0, color))
	{
		return "YES";
	}
	else
	{
		return "NO";
	}
}
