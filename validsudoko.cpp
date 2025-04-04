class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     unordered_map<int, unordered_map<char, int>> rows, cols, boxes;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                
                if (num == '.') continue;

                int boxIndex = (i / 3) * 3 + (j / 3); 

                if (rows[i][num]++ > 0 || cols[j][num]++ > 0 || boxes[boxIndex][num]++ > 0) {
                    return false;
                }
            }
        }
        return true; 
    }
};
