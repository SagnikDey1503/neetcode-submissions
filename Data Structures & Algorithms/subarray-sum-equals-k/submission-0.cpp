class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        vector<int> prefix ;
        prefix.push_back(0);

        for( int i =0;i<nums.size();i++){
          prefix.push_back(prefix[i]+nums[i]);
        }
        
int counter=0;
       for( int k =1 ;k<=nums.size();k++){
        for(int i =0; i<= nums.size()-k;i++){
            int r = i+k;
            int sum = prefix[r]-prefix[i];
            if(sum==target) counter++;
        } 
       }
return counter;
    }
};