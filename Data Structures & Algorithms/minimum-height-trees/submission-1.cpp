class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        int remaining=n;
        vector <vector<int>> adj (n);
        vector <int> rank (n,0);
        for( auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            rank[e[0]]++;
            rank[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(rank[i]==1)
            q.push(i);
             
        }

        while(remaining >2){
            int s= q.size();
            remaining-=s;
            while(s--){
                int node= q.front();
                q.pop();
                for( auto& x : adj[node]){
                    rank[x]--;
                    if(rank[x]==1)q.push(x);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
        }
return ans;

    }
};
 