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
private:
    ListNode* findMiddle(ListNode* head){
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = temp -> next -> next;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* mergeLL(ListNode* left, ListNode* right){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(left != nullptr && right != nullptr){
            if(left -> val < right -> val){
                temp -> next = left;
                temp = left;
                left = left -> next;
            } else {
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }

        if(left) temp -> next = left;
        else temp -> next = right;

        return dummyNode -> next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* middle = findMiddle(head);
        ListNode* right = middle -> next;
        middle -> next = nullptr;
        
        ListNode* left = head;
        left = sortList(head);
        right = sortList(right);

        return mergeLL(left , right);
        
    }
};