class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0, j = 0;
        int dir = 0;

        while (i >= 0 && i < n && j >= 0 && j < m) {
            if (matrix[i][j] == 1) {
             dir = (dir + 1) % 4;
             matrix[i][j] = 0;
                
            }

             i += directions[dir].first;
             j += directions[dir].second;
        }
        
        if (dir == 0) j--;
        else if (dir == 1) i--;
        else if (dir == 2) j++;
        else i++;

     return {i, j};
    }
};