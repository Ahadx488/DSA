class Solution {
public:
    bool isAnagram(string s, string t) {
        //if(s.length()!=t.length()) return false;
        // unordered_map<char,int>mpp;
        // for(int i=0;i<s.length();i++){
        //     mpp[s[i]]++;
        // }
        // for(int i=0;i<t.length();i++){
        //     if(mpp.find(t[i])!=mpp.end() ){
        //         mpp[t[i]]-=1;
        //     }
        //     else return false;
        // }
        // for(auto st:mpp){
        //     if(st.second!=0) return false;
        // }
        // return true;

        int n = s.length();
        int m = t.length();
        if(n != m) return false;

        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int j : freq){
            if(j != 0) return false;
        }
        return true;
    }
};