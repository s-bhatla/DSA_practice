//soln for gfg question rat in a maze

class Solution{
    public:
    
    bool canmoveto(vector<vector<int>> &m, int n, int a, int b){
        if(a >= n || b >= n){
            return false;
        }
        if(a < 0 || b < 0){
            return false;
        }
        if(m[a][b] != 1){
            return false;
        }
        return true;
    }
    
    void recpath(vector<string>& ans, string temp, vector<vector<int>> &m, int n, int a, int b, char move){
        if(canmoveto(m, n, a, b) == false){
            return;
        }
        if(move != 'e'){
            temp += move;
        }
        if(a == n-1 && b == n-1){
            ans.push_back(temp);
            return;
        }
        m[a][b] = 0;
        recpath(ans, temp, m, n, a+1, b, 'D');
        recpath(ans, temp, m, n, a-1, b, 'U');
        recpath(ans, temp, m, n, a, b+1, 'R');
        recpath(ans, temp, m, n, a, b-1, 'L');
        m[a][b] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string temp = "";
        recpath(ans, temp, m, n, 0, 0, 'e');
        return ans;
    }
};
