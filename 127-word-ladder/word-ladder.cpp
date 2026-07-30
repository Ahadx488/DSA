class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        set<string> st;
        for(auto it: wordList){
            st.insert(it);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            string str = it.first;
            int len = it.second;

            if(str == endWord) return len;

            for(int i = 0; i < str.size(); i++){
                char original = str[i];
                for(char c = 'a'; c <= 'z'; c++){
                    str[i] = c;
                    if(st.find(str) != st.end()){
                        q.push({str, len + 1});
                        st.erase(str);
                    }
                    str[i] = original;
                }
            }
        }
        return 0;
    }
};