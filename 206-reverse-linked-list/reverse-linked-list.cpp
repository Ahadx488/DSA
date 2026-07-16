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
    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* newHead = reverseLL(head -> next);

        ListNode* front = head -> next;
        head -> next = nullptr;
        front -> next = head;
        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // recursive approach 
        return reverseLL(head);;
    }
};