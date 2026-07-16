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
// private:
//     ListNode* reverseLL(ListNode* head){
//         if(head == nullptr || head -> next == nullptr) return head;
//         ListNode* newHead = reverseLL(head -> next);

//         ListNode* front = head -> next;
//         front -> next = head;
//         head -> next = nullptr;

//         return newHead;
//     }

// Find middle → O(n)
// Reverse → O(n/2)
// Compare → O(n/2)
// Restore → O(n/2)

// Overall:

// Time: O(n)
// Space: O(n) because your reverseLL() is recursive (recursion stack).

// Note: The optimal solution uses an iterative reverse, reducing the extra space to O(1)
private:
    ListNode* reverseLL(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front = head;

        while(temp != nullptr)
        {
            front = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast -> next != nullptr && fast -> next -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* newHead = reverseLL(slow -> next);
        ListNode* first = head;
        ListNode* second = newHead;

        while(second != nullptr){
            if(first -> val != second -> val ) {
                reverseLL(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverseLL(newHead);
        return true;

    }
};