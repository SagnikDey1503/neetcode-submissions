class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zp =0 , tp=nums.size()-1;
 int i =0;
        while ( i <= tp){
            if( nums[i]==0){
                swap( nums[i++],nums[zp++]);
            }
             else if( nums[i]==2){
                swap( nums[i],nums[tp--]);
            }
           else
           i++;
        }
    }
}; 



