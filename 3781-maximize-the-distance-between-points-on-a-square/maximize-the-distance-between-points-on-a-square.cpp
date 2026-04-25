#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to map 2D boundary coordinates to a 1D perimeter line
    long long getPos(long long x, long long y, long long side) {
        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 3LL * side - x;
        if (x == 0) return 4LL * side - y;
        return 0; 
    }

    // Helper function to greedily check if we can pick k points with min distance D
    bool check(long long D, int N, int k, long long L, const vector<long long>& A, vector<int>& nxt) {
        int j = 0;
        
        // Two pointers to find the next valid point that sits at least 'D' distance away
        for (int i = 0; i < 2 * N; ++i) {
            while (j < 2 * N && A[j] - A[i] < D) {
                j++;
            }
            nxt[i] = j;
        }

        // Test every starting point in the first loop
        for (int i = 0; i < N; ++i) {
            int curr = i;
            
            // Greedily take 'k' jumps
            for (int step = 0; step < k; ++step) {
                curr = nxt[curr];
                if (curr == 2 * N) break; // Reached dead end
            }
            
            // If we successfully made k jumps and didn't exceed one full loop length
            if (curr < 2 * N && A[curr] - A[i] <= L) {
                return true;
            }
        }
        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> A(n);
        
        // Step 1: Map and Sort
        for (int i = 0; i < n; ++i) {
            A[i] = getPos(points[i][0], points[i][1], side);
        }
        sort(A.begin(), A.end());

        // Step 2: Double the array to handle cyclic wrap-arounds cleanly
        long long L = 4LL * side;
        vector<long long> doubledA(2 * n);
        for (int i = 0; i < n; ++i) {
            doubledA[i] = A[i];
            doubledA[i + n] = A[i] + L;
        }

        long long low = 1, high = side;
        long long ans = 0;
        vector<int> nxt(2 * n + 1, 2 * n); // Allocated once for efficiency

        // Step 3: Binary Search the maximum possible minimum gap
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (check(mid, n, k, L, doubledA, nxt)) {
                ans = mid;         // Mid works, save it
                low = mid + 1;     // Try for an even larger minimum distance
            } else {
                high = mid - 1;    // Mid is too large, reduce the distance
            }
        }

        return static_cast<int>(ans);
    }
};