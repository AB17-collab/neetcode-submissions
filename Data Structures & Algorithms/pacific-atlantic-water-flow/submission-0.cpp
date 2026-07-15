class Solution {
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r,int c, vector<vector<bool>>& ocean,vector<vector<int>>& heights){
        ocean[r][c] = true;
        for(auto [dr,dc] : directions){
            int nr = r + dr,nc = c + dc;
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() &&
            !ocean[nr][nc] && heights[nr][nc]>=heights[r][c]){
                dfs(nr,nc,ocean,heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows,vector<bool>(cols,false));
        vector<vector<bool>> atl(rows,vector<bool>(cols,false));

        for(int col = 0;col<cols;col++){
            dfs(0,col,pac,heights);
            dfs(rows-1,col,atl,heights);
        }
        
        for(int row = 0;row<rows;row++){
            dfs(row,0,pac,heights);
            dfs(row,cols-1,atl,heights);
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pac[i][j] && atl[i][j])
                    res.push_back({i,j});
            }
        }
        return res;
    }
};
