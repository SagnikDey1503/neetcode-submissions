class Solution {
private:
    vector<int> parents;
    vector<int> rank;

    int find(int e) {
        if (parents[e] == e)
            return e;

        return parents[e] = find(parents[e]);
    }

    bool unnion(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return false;

        if (rank[pa] > rank[pb])
            parents[pb] = pa;
        else if (rank[pa] < rank[pb])
            parents[pa] = pb;
        else {
            parents[pa] = pb;
            rank[pb]++;
        }

        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;

        parents.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parents[i] = i;

        for (auto &edge : edges) {
            if (!unnion(edge[0], edge[1]))
                return false;
        }

        return true;
    }
};