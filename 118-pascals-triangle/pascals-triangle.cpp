class Solution {
private:
    vector<int> generateRow(int row){
        vector<int> temp;
        long long ans = 1;
        temp.push_back(1);
        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans/col;
            temp.push_back(ans);
        }
        return temp;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        // int i = 0;
        // while(i < numRows){
        //     vector<int> row(i + 1,1);

        //     for(int j = 1; j < i; j++){
        //         row[j] = pascalTriangle[i - 1][j-1] + pascalTriangle[i - 1][j];
        //     }

        //     pascalTriangle.push_back(row);
        //     i++;
        // }

        // return pascalTriangle;
        //pascalTriangle.push_back({1});
        
        
        for(int i = 1; i <= numRows; i++){
            pascalTriangle.push_back(generateRow(i));
        }
        return pascalTriangle;
    }
};