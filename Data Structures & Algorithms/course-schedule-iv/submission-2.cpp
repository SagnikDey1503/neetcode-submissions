class Solution {
public:
       
       bool check ( int l , int r ,vector<vector<int>>& adj , vector<int> & path , vector<int> & visited ){
              if ( l == r ) return true;
              path[l] = 1;
              for(auto & neighbour : adj [l]){
                 if(  !visited[neighbour]){
                    if(path[neighbour])
                    continue;
                 if (check(neighbour,r, adj , path , visited ))
                 return true;
                 }

              }
               visited[l]=1;
               path[l]=0;

              return false;
       }

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& preReq, vector<vector<int>>& q) {
        // pre req is basically an adj 
             vector<vector<int>> adj (n);
             for(auto & x: preReq){
                 adj[x[0]].push_back(x[1]);
             }
        // build adjancey list
        vector<bool> ans;
        for( auto& x : q){
            vector<int> path (n,0);
             vector<int> visited (n,0);
            int l =x[0],r=x[1];
             ans.push_back(check(l,r, adj , path , visited ));
        }
        return ans;
    }
};

