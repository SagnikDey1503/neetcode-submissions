class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0 , r= nums.size()-1;
vector<int> ans;

        while(l<r){
            int sum = nums[l] + nums[r];
            if(sum < target) l++;
            else if(sum > target)r--;
            else 
            {
             ans.push_back(l+1);
               ans.push_back(r+1);
               break;
            }
        }
            return ans;

        
    }
};
