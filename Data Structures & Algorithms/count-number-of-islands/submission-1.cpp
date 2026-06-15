class Solution {

    void df ( int i , int j ,vector<vector<char>>& grid ){
        int n= grid.size();
        int m =grid[0].size();
        if( i<0 || j<0 || i >=n || j >=m || grid[i][j]== '0') return;

        grid[i][j]='0';

        df( i +1 ,j,grid);
          df( i -1 ,j,grid); 
           df( i  ,j+1,grid); 
            df( i ,j-1,grid);

    }
public:

    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m =grid[0].size();
       int counter=0;
        for( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j] == '1'){
                counter++; 
                df(i,j,grid);
                }
            }
        }
        return counter;
    }
};
