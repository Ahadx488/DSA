/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> list;
        ListNode * temp = head;
        
        while(temp != nullptr){
            list.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = list.size();
        int ans = 0;
        for(int i = 0; i < n/2; i++){
            ans  = max(ans , list[i] + list[n - i -1]);
        }

        return ans;
    }
};