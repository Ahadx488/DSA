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
    ListNode* findKthNode(ListNode* head, int k){
        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* temp = head;

        int cnt = 1;

        while(temp != nullptr){
            if(cnt == k) return temp;
            cnt++;
            temp = temp -> next;
        }
        return nullptr;
    }
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k <= 1) return head;
        ListNode* temp = head;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;

        while(temp != nullptr){
            ListNode* kthNode = findKthNode(temp, k);
            if(kthNode == nullptr){
                if(prevNode) prevNode -> next = temp;
                break;
            }
            nextNode = kthNode -> next;
            kthNode -> next = nullptr;
            
            kthNode = reverseLL(temp);

            if(temp == head){
                head = kthNode;
            }
            else{
                if(prevNode) prevNode -> next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};