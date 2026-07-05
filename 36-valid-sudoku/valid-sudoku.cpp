class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<unordered_set<char>> rows(9);
       vector<unordered_set<char>> cols(9);
       vector<vector<unordered_set<char>>> squares(3,
       vector<unordered_set<char>>(3));

       for(int i = 0; i < 9; i++){
        
        for(int j = 0; j < 9; j++){
            auto key = board[i][j];
            if(key == '.') continue;
            if(rows[i].find(key) != rows[i].end() || 
            cols[j].find(key) != cols[j].end() || 
            squares[i/3][j/3].find(key) != squares[i/3][j/3].end()) return false;
            
            rows[i].insert(key);
            cols[j].insert(key);
            squares[i/3][j/3].insert(key);
        
        }
       }
       return true;

    }
};