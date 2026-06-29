class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        stack<pair<int,int>> s;
        s.push({temp[0],0});

        vector<int> ans(temp.size(),0);

        int i = 1;

        while (i < temp.size()) {

            int ele = temp[i];

            while (!s.empty() && ele > s.top().first) {
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }

            s.push({ele,i});
            i++;
        }

        return ans;
    }
};