// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int key[V], mst[V], parent[V];
        int MAX = 1001;
        for(int i = 0; i < V; i++){
            key[i] = MAX;
            mst[i] = 0;
            parent[i] = -1;
        }
        key[0] = 0;
        int isMST = 0;
        int minkey = 0;
        int minedgei = 0;
        int minedgej = 0;
        mst[0] = 1;
        
        while(isMST == 0){
            
            for(int i = 0; i < V; i++){
                if(mst[i] == 1){
                    for(int j = 0; j < adj[i].size(); j++){
                        if(adj[i][j][1] < key[j]){
                            key[j] = adj[i][j][1];
                            parent[j] = i;
                        }
                    }
                }
            }
            
            for(int i = 0; i < V; i++){
                if(mst[i] == 0){
                    for(int i = 0; i < V; i++){
                        if(key[minkey] > key[i]){
                            minkey = i;
                        }
                    }
                }
            }
            
            mst[minkey] = 1;
            
            isMST = 1;
            for(int i = 0; i < V; i++){
                if(mst[i] == 0){
                    isMST = 0;
                    break;
                }
            }
            for(int i = 0; i < V; i++){
                cout << mst[i] << " ";
            }
            cout << endl;
        }
        int sum = 0;
        for(int i = 0; i < V; i++){
            sum = sum + key[i];
        }
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends