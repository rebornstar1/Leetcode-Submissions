class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>freq(27,vector<int>(10,0));

        for(int i = 0 ; i < 9 ; i++ ) 
        {
           for(int j = 0 ; j < 9 ; j++ )
           {
               if(board[i][j] == '.') continue;

               freq[i][board[i][j]-'0']++;
               if(freq[i][board[i][j]-'0'] > 1) return false;

               freq[9+j][board[i][j]-'0']++;
               if(freq[9+j][board[i][j]-'0'] > 1) return false;

               int indexVal = (3*(i/3) + (j/3));
               freq[18+indexVal][board[i][j]-'0']++;
               if(freq[18+indexVal][board[i][j]-'0'] > 1) return false;
           }
        }

        return true;
    }
};
