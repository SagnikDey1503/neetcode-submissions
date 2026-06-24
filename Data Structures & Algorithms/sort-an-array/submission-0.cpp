class Solution {
public:
       void merge (vector<int>& arr , int l , int mid ,int r ){
            vector <int> temp;
            int i= l , j = mid+1;
            while( i <=mid && j <=r){
                if(arr[i]< arr[j]){
                    temp.push_back(arr[i++]);
                }
                else
                temp.push_back(arr[j++]);
            }

            while( i <=mid)
             temp.push_back(arr[i++]);

             while( j<=r)
              temp.push_back(arr[j++]);

              for(int i =0;i<temp.size();i++){
                arr[l+i] = temp[i];
              }

       }
      void mergeSort ( vector<int>& nums , int l , int r){
        if (l>=r) return;

        int mid = l + (r-l)/2 ;

        mergeSort ( nums , l , mid);
        mergeSort( nums, mid+1,r);
        merge(nums , l , mid , r);
      }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort( nums , 0, nums.size()-1);
        return nums;
    }
};