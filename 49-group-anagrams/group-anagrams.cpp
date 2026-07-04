class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // int n = strs.size();
        // unordered_map<string, vector<string>> mpp;
        // for(auto s : strs){
        //     string key = s;
        //     sort(key.begin() , key.end());
        //     mpp[key].push_back(s);
        // }
        // vector<vector<string>> ans;
        // for(auto it : mpp){
        //     ans.push_back(it.second);
        // }
        // return ans;

        // O(n*klog(k));
        // klog(k) for sorting
        // we can do it in O(n*k)

        unordered_map<string, vector<string>> mpp;

        for(auto &s : strs){
            vector<int> freq(26,0);
            
            for(char c : s){
                freq[c - 'a']++;
            }

            string key = "";

            for(int x: freq){
                key += to_string(x) + "#";
            }

            mpp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;

    }
};