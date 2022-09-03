//this is the gfg soln for the word search problem
//Uses backtracking

bool checkpick(vector<vector<char>>& board, int a, int b){
        if(a < 0 || b < 0){
            return false;
        }
        if(a > board.size()-1 || b > board[0].size()-1){
            return false;
        }
        if(board[a][b] == '.'){
            return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int a, int b, int c, string word){
        if(word.length() == 1){
            for(int i = 0; i<board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    if(board[i][j] == word[0]){
                        return true;
                    }
                }
            }
        }
        if(checkpick(board, a, b)== false){
            return false;
        }
        // cout << "we at " << board[a][b]<<c << endl;
        char temp;
        if(c == 0){
            for(int i = 0; i<board.size(); i++){
                for(int j = 0; j < board[0].size(); j++){
                    if(board[i][j] == word[0]){
                        temp = board[i][j];
                        // cout << "calling " << board[i][j] << endl;
                        board[i][j] = '.';
                        if(solve(board, i+1, j, c+1, word)){
                            return true;
                        }if(solve(board, i-1, j, c+1, word)){
                            return true;
                        }if(solve(board, i, j+1, c+1, word)){
                            return true;
                        }if(solve(board, i, j-1, c+1, word)){
                            return true;
                        }
                        board[i][j] = temp;
                    }
                }
            }
        }
        else if(c == word.length()-1){
            // cout << "wlen-1 board" << board[a][b];
            if(board[a][b] == word[c]){
                // cout << "we retrue?";
                return true;
            }
            else{
                // cout << "we refalse?";
                return false;
            }
        }
        else{
            if(board[a][b] == word[c]){
                temp = board[a][b];
                // cout << "calling mid " << board[a][b] << endl;

                board[a][b] = '.';
                if(solve(board, a+1, b, c+1, word)){
                    return true;
                }if(solve(board, a-1, b, c+1, word)){
                    return true;
                }if(solve(board, a, b+1, c+1, word)){
                    // cout << "did we not ?";
                    return true;
                }if(solve(board, a, b-1, c+1, word)){
                    return true;
                }
                board[a][b] = temp;
            }
        }
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        return solve(board, 0, 0, 0, word);
    }
