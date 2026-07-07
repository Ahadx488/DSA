class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        int i = 0;
        while(i < numRows){
            vector<int> row(i + 1,1);

            for(int j = 1; j < i; j++){
                row[j] = pascalTriangle[i - 1][j-1] + pascalTriangle[i - 1][j];
            }

            pascalTriangle.push_back(row);
            i++;
        }

        return pascalTriangle;
    }
};