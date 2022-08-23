//code for gfg question

void dfsrec(vector<vector<char>>& grid, int n, int m, int x, int y){
        if(x >= n || x < 0){
            return;
        }
        if(y >= m || y < 0){
            return;
        }
        if(grid[x][y] == '0'){
            return;
        }
        grid[x][y] = '0';
        dfsrec(grid, n, m, x + 1, y);
        dfsrec(grid, n, m, x + 1, y + 1);
        dfsrec(grid, n, m, x + 1, y - 1);
        dfsrec(grid, n, m, x, y + 1);
        dfsrec(grid, n, m, x, y - 1);
        dfsrec(grid, n, m, x - 1, y - 1);
        dfsrec(grid, n, m, x - 1, y + 1);
        dfsrec(grid, n, m, x - 1, y);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    if(grid[i][j] == '1'){
                        count++;
                        dfsrec(grid, grid.size(), grid[0].size(), i, j);
                    }
                    
                }
            }
        }
        return count;
    }