class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector < unordered_map<char,int>> row (9);
        vector < unordered_map<char,int>> column (9);
        vector < unordered_map<char,int>> box (9);

          for(int i=0;i< 9;i++){
            for(int j=0;j<9;j++){
                int box_no = (i/3)*3 + (j/3);
                if(board[i][j] == '.') continue;
                int e = board[i][j];
                if( row[i].count(e) || column[j].count(e)|| box[box_no].count(e))
                return false;
               row[i][e] ++;
                column[j][e] ++;
                box[box_no][e] ++;
               

            }
           
          }
           return true;
    }
};
