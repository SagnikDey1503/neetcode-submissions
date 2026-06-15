class Solution {
public:

    bool dfs(int num,
             vector<vector<int>>& adj,
             vector<bool>& path,
             vector<bool>& visited) {

        if(visited[num]) return false;  
        if(path[num]) return true;  

        path[num] = true;

        for(auto x : adj[num]) {
            if(dfs(x, adj, path, visited))
                return true;
        }

        path[num] = false;
        visited[num] = true;

        return false;
    }

    bool canFinish(int num, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(num);

        for(auto &x : prerequisites) {
            adj[x[1]].push_back(x[0]);
        }

        vector<bool> visited(num, false);
        vector<bool> path(num, false);

        for(int i = 0; i < num; i++) {
            if(dfs(i, adj, path, visited))
                return false;
        }

        return true;
    }
};