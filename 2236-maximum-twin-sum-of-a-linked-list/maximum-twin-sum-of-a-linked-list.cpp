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

        ListNode* temp = head;
        ListNode* front = head;
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newHead = reverseLL(slow -> next);

        ListNode* first = head;
        ListNode* second = newHead;
        int sum = INT_MIN;
        while(second != nullptr){
            sum = max(sum, first -> val + second -> val);
            first = first -> next;
            second = second -> next;
        }
        reverseLL(newHead);

        return sum;
    }
};