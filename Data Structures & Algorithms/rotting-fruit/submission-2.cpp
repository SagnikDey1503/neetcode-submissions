class Solution {
public:
    void check ( int i , int j , vector<vector<int>>& grid, queue <pair<int,int>>& q ){
       int n = grid.size();
        int m = grid[0].size();
           if( i<0 || i>=n || j<0 ||j>=m || grid[i][j]==2 || grid[i][j]==0)return;
          grid[i][j]=2;
           q.push({i,j});

    }


    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
     
     queue <pair<int,int>> q;
     for(int i =0;i<n;i++){
        for(int j=0;j<m;j++)
              if(grid[i][j]==2) q.push({i,j});
     }
     int counter=-1;
    while(!q.empty()){
         int s = q.size();
         while (s--){
        auto x = q.front();
        int i = x.first,j=x.second;
        q.pop();
        check(i+1,j,grid,q);
        check(i-1,j,grid,q);
        check(i,j+1,grid,q);
        check(i,j-1,grid,q);
         }
         counter++;
    }
           for(int i =0;i<n;i++){
        for(int j=0;j<m;j++)
              if(grid[i][j]==1) return -1;
     }
     return max(counter,0);
    }
};
