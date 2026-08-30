class Solution {
private:
    int solve(string& s, int l, int r, int k) {

        if(r - l + 1 < k)
            return 0;

        vector<int> freq(26, 0);

        // Count frequencies in current substring
        for(int i = l; i <= r; i++) {
            freq[s[i] - 'a']++;
        }

        // Find a character whose frequency is < k
        for(int i = l; i <= r; i++) {

            if(freq[s[i] - 'a'] < k) {

                char bad = s[i];

                int left = solve(s, l, i - 1, k);
                int right = solve(s, i + 1, r, k);

                return max(left, right);
            }
        }

        // Every character appears >= k times
        return r - l + 1;
    }

public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
};