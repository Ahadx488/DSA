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
    int findLen(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
public:
   
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 0) return head;

        int len = findLen(head);
        k = k % len;

        ListNode* temp = head;
        ListNode* tail = head;
        ListNode* nextNode = head;
        while(tail -> next != nullptr){
            tail = tail -> next;
        }
        tail -> next = head;
        int cnt = 0;

        while(temp != nullptr){
            cnt++;
            if(cnt == len - k){
                nextNode = temp -> next;
                temp -> next = nullptr;
                break;
            }
            temp = temp -> next;
        }
        return nextNode;
    }
};