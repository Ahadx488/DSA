class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mpp;
        for(auto s : strs){
            string key = s;
            sort(key.begin() , key.end());
            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};