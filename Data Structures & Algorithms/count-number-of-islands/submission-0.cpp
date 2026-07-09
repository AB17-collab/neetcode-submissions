class Solution {
public:
    int rows[4] = {-1,0,1,0};
    int cols[4] = {0,1,0,-1};
    void dfs(int r,int c,vector<vector<char>> &grid){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]!='1')
            return;
        
        grid[r][c] = '2';
        for(int k=0;k<4;k++){
            int ii = r + rows[k];
            int jj = c + cols[k];
            dfs(ii,jj,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
