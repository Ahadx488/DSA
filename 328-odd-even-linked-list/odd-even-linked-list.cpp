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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        // ListNode* odd = head;
        // ListNode* even = head -> next;
        // ListNode* evenHead = even;

        // while( even != nullptr && even -> next != nullptr){
        //     odd -> next = odd -> next -> next;
        //     even -> next = even -> next -> next;

        //     even = even -> next;
        //     odd = odd -> next;
        // }
        // odd -> next = evenHead;
        // return head;

        ListNode* even = head -> next;
        ListNode* odd = head;

        vector<int> list;

        while(odd != nullptr && odd -> next != nullptr){
            list.push_back(odd -> val);
            odd = odd -> next -> next;
        }
        if(odd){
            list.push_back(odd -> val);
        }
        while(even != nullptr && even -> next != nullptr){
            list.push_back(even -> val);
            even = even -> next -> next;
        }
        if(even ){
            list.push_back(even -> val);
        }

        ListNode * temp = head;
        int i = 0;
        while(temp != nullptr){
            temp -> val = list[i];
            i++;
            temp = temp -> next;
        }
        return head;
    }
};