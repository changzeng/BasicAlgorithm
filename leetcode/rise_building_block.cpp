class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if((int)grid.size()==0 || (int)grid[0].size()==0)
            return 0;
        vector<int> row_max(grid.size(), 0), col_max(grid[0].size(), 0);
        for(int i=0; i<(int)grid.size(); i++){
            for(int j=0; j<(int)grid[0].size(); j++){
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        int res=0;
        for(int i=0; i<(int)grid.size(); i++){
            for(int j=0; j<(int)grid[0].size(); j++){
                res += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return res;
    }
};