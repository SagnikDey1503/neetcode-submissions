class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> check(n + 1, vector<int>(2, 0));
     
        for (auto& x : trust) {
            check[x[0]][0]++; // trusts someone
            check[x[1]][1]++; // trusted by someone
        }

        for (int i = 1; i <= n; i++) {
            if (check[i][0] == 0 && check[i][1] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};