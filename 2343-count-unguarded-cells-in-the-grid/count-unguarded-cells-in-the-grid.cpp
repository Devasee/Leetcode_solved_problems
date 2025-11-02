class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        int size1 = guards.size();
        int size2 = walls.size();

        int count = 0;

        for (auto& guard : guards)
            v[guard[0]][guard[1]] = 1;

        // Mark walls
        for (auto& wall : walls)
            v[wall[0]][wall[1]] = 2;

        for(auto& guard : guards)
        {
            int row = guard[0];
            int col = guard[1];

            for(int r= row-1; r >= 0; r--)
            {
                if(v[r][col] == 1 || v[r][col] == 2)break;
                if(v[r][col] == 0) v[r][col] = 3;
            }

            for(int r= row+1; r < m; r++)
            {
                if(v[r][col] == 1 || v[r][col] == 2)break;
                if(v[r][col] == 0) v[r][col] = 3;
            }

            for(int c= col-1; c >= 0; c--)
            {
                if(v[row][c] == 1 || v[row][c] == 2)break;
                if(v[row][c] == 0) v[row][c] = 3;
            }

            for(int c= col+1; c < n; c++)
            {
                if(v[row][c] == 1 || v[row][c] == 2)break;
                if(v[row][c] == 0) v[row][c] = 3;
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(v[i][j] == 0)
                count ++;
            }
        }

        return count;
    }
};