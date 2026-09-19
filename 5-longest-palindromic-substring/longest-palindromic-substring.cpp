#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++) {
            expand(i, i); // odd length: "bab"
            expand(i, i + 1); // even length: "bb"
        }

        return s.substr(start, maxLen);
    }
};

// Example usage
// int main() {
//     Solution sol;
//     cout << sol.longestPalindrome("babad") << endl; // bab or aba
//     cout << sol.longestPalindrome("cbbd") << endl; // bb
//     return 0;
// }