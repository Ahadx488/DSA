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
    int length(ListNode*head){
        int cnt=0;
        ListNode*temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode*temp=head;
        int n=1;
        ListNode*tail=head;
        while(tail->next!=nullptr){
            n++;
            tail=tail->next;
        }
        k=k%n;
        if(k==0) return head;
        ListNode*prev=head;
        int cnt=0;
        while(temp->next!=nullptr){
            cnt++;
            prev=temp;
            temp=temp->next;
            if(cnt==n-k){
                prev->next=nullptr;
                break;
            }
        }
       tail->next=head;
       head=temp;
       return head;
    }
};