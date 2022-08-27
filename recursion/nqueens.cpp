//soln for leetcode nqueens question, here we have done backtracking in a void fxn

bool issafe(vector<string> board, int a, int b){
        int n = board.size();
        for(int i = 0; i < n; i++){
            if(board[i][b] == 'Q'){
                return false;
            }
        }
        for(int i = 0; i < n; i++){
            if(board[a][i] == 'Q'){
                return false;
            }
        }
        int i = a;
        int j = b;
        while(i < n && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j++;
        }
        i = a;
        j = b;
        while(i < n && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }
        i = a;
        j = b;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        i = a;
        j = b;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }
    
    void boardclear(vector<string>& board){
        string temp = "";
        int n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp = temp + ".";
            }
            board.push_back(temp);
        }  
    }
    
    void nqueen(vector<vector<string>>& ans, vector<string> board, int row){
        if(row == board.size()){
            ans.push_back(board);
        }
        for(int col=0; col < board.size(); col++){
            if(issafe(board, row, col)){
                board[row][col] = 'Q';
                nqueen(ans, board, row+1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for( int i=0; i<n; i++){
            board[i] = s;
        }
        nqueen(ans, board, 0);
        return ans;
    }