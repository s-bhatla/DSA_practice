//soln for permutation of strings in cpp

void swap(string& S, int i, int j){
	        char temp = S[j];
	        S[j] = S[i];
	        S[i] = temp;
	    }
	
	    void permutes(string S, vector<string>& ans, int l, int r){
	        if(l == r){
	            ans.push_back(S);
	            return;
	        }
	        
	        for(int i = l; i <=r; i++){
	            swap(S, i, l);
	            permutes(S, ans, l+1, r);
	            swap(S, i, l);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    permutes(S, ans, 0, S.length()-1);
		    sort(ans.begin(), ans.end());
		    string temp;
		    for(int i = 0; i < ans.size(); i++){ // checking for duplicates
		        temp = ans[i];
		        for(int j = i; j < ans.size(); j++){
		            if(ans[i] == ans[j] && j !=i){
		                ans.erase(ans.begin() + j);
		            }
		        }
		    }
		    return ans;
		}