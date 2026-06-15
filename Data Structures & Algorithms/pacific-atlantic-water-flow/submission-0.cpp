class Solution {
     void dfs ( int i , int j, vector<vector<int>>& p,vector<vector<int>>& heights, int val){
         int n= heights.size();
          int m = heights[0].size();
          if( i<0 || j<0 || i>=n || j>=m || p[i][j]) return;

          if(!(heights[i][j]>=val))return;

          val=heights[i][j];
          p[i][j]=1;

          dfs( i+1 , j , p , heights , val);
                dfs( i-1 , j , p , heights , val);
                      dfs( i , j+1, p , heights , val);
                            dfs( i , j-1 , p , heights , val);

     }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
          int n= heights.size();
          int m = heights[0].size();
         
         vector<vector<int>> p (n , vector<int> (m,0));
         for( int i=0,j=0;i<n;i++){
           dfs(i,j,p,heights,heights[i][j]);
         }
          for( int i=0,j=0;j<m;j++){
           dfs(i,j,p,heights,heights[i][j]);
         }

  vector<vector<int>> a (n , vector<int> (m,0));
         for( int i=0,j=m-1;i<n;i++){
           dfs(i,j,a,heights,heights[i][j]);
         }
          for( int i=n-1,j=0;j<m;j++){
           dfs(i,j,a,heights,heights[i][j]);
         }
         vector<vector<int>> ans;
         for( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j] && p[i][j]) ans.push_back({i,j});
            }
         }

return ans;

    }
};
