class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int x: nums){
            st.insert(x);
        }
        

        int maxlen = 0;
        
        for(int it: st){

            if(st.find(it - 1) == st.end()){
                int curr = it;
                int len = 1;

                while(st.find(curr + 1) != st.end()){
                    curr++;
                    len++;
                }
                maxlen = max(len , maxlen);
            }
        }
        return maxlen;
    }
};