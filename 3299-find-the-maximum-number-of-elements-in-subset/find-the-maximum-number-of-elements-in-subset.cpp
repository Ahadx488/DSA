#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int max_len = 1;

        // Handle the special case for 1
        if (freq.count(1)) {
            int count1 = freq[1];
            // The length must be an odd number
            if (count1 % 2 == 0) {
                count1--;
            }
            max_len = max(max_len, count1);
            freq.erase(1); // Remove 1 so it isn't processed in the main loop
        }

        for (auto const& [key, count] : freq) {
            long long x = key;

            // Optimization: Only start building the sequence if 'x' is the base.
            // If the square root of x exists and has a count >= 2, x is part of a larger sequence.
            long long root = round(sqrt(x));
            if (root * root == x && freq.count(root) && freq[root] >= 2) {
                continue; 
            }

            int current_len = 0;
            long long curr = x;

            // Keep squaring as long as we have at least 2 copies of the current number
            while (freq.count(curr) && freq[curr] >= 2) {
                current_len += 2;
                curr = curr * curr;

                // Prevent unnecessary large calculations since max value in nums is 10^9
                if (curr > 1000000000LL) {
                    break; 
                }
            }

            // If the next number exists (at least 1 copy), it can be our peak
            if (freq.count(curr) && freq[curr] >= 1) {
                current_len += 1;
            } else {
                // Otherwise, the previous number has to act as the peak.
                // We added 2 for it in the loop, but we only need 1, so subtract 1.
                current_len -= 1;
            }

            if (current_len > 0) {
                max_len = max(max_len, current_len);
            }
        }

        return max_len;
    }
};
   