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
    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* front = head;
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || head -> next == nullptr) return nullptr;
        ListNode* newHead = reverseLL(head);

        // Delete first node after reversal
        if(n == 1){
            ListNode* del = newHead;
            newHead = newHead->next;
            delete del;
            return reverseLL(newHead);
        }

        int cnt = 1;
        ListNode* temp = newHead;

        while(cnt < n - 1 && temp != nullptr){
            temp = temp->next;
            cnt++;
        }
        
        if(temp != nullptr && temp->next != nullptr){
            ListNode* del = temp->next;
            temp->next = del->next;
            delete del;
        }

        return reverseLL(newHead);
    }
};