class Solution {
private:
    int findNoOfBoquets(vector<int> &bloomDay, int day, int m, int k){
        int cnt = 0;
        int boquets = 0;

        for(int x: bloomDay){
            if(x <= day){
                cnt++;
                
                if(cnt == k){
                    boquets++;
                    cnt = 0;
                }
            }
            else cnt = 0;
            
        }
        return boquets;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < 1LL * m * k) return -1;
        
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int boquets = findNoOfBoquets(bloomDay, mid, m, k);
            if(boquets >= m){
                high = mid - 1;
                ans  = mid;
            } 
            else{
                low = mid + 1;
            }
        }
        return ans;

    }
};