class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int c1 = 0, c2 = 0;
        int count1 = 0, count2 = 0;

        for (int x : nums) {

            if (x == c1) {
                count1++;
            }
            else if (x == c2) {
                count2++;
            }
            else if (count1 == 0) {
                c1 = x;
                count1 = 1;
            }
            else if (count2 == 0) {
                c2 = x;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;

        for (int x : nums) {
            if (x == c1) count1++;
            else if (x == c2) count2++;
        }

        vector<int> ans;
        int n = nums.size();

        if (count1 > n / 3) ans.push_back(c1);
        if (count2 > n / 3) ans.push_back(c2);

        return ans;
    }
};