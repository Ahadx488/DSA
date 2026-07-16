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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 0;
        ListNode* temp = head;
        ListNode* start = nullptr;
        ListNode* end = nullptr;

        while(temp != nullptr) {
            cnt++;
            if(cnt == left){
                start = temp;
            }
            if(cnt == right){
                end = temp;
                break;
            }
            temp = temp -> next;
        }
        if(start == end) return head;
        ListNode * temp1 = start;
        stack<int> st;
        while(temp1 != end -> next){
            st.push(temp1 -> val);
            temp1 = temp1 -> next;
        }
        temp1 = start;
        while(temp1 != end -> next){
            temp1 -> val = st.top();
            st.pop();
            temp1 = temp1 -> next;
        }
        return head;
    }
};