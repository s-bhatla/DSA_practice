//soln for gfg ques of floyd warshall, note that argument given is a matrix

void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    int MAX = 1000000;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = MAX;
	            }
	        }
	    }
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            for(int k = 0; k < n; k++){
	                if(j == i || k == i){
	                    continue;
	                }
	                if(j==k){
	                    continue;
	                }
	                if(matrix[j][k] > matrix[j][i] + matrix[i][k]){
	                    matrix[j][k] = matrix[j][i] + matrix[i][k];
	                }
	            }
	        }
	    }
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(matrix[i][j] == MAX){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}