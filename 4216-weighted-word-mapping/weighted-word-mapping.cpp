class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        
        vector<char> alphabets;
        for(int c = 'a'; c <= 'z' ; c++){
            alphabets.push_back(c);
        }
        
        string ans = "";
        for(int i = 0; i < n; i++){
            int wt = 0;

            for(int j = 0; j < words[i].size(); j++){
                wt += weights[abs('a' - words[i][j])];
            }
            
            int ind = wt % 26;
            
            ans += alphabets[25 - ind];
        }
        return ans;
    }
};