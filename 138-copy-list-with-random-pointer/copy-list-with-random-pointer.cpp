/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node* insertCopiesInBetween(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* copyNode = new Node(temp -> val);
            Node* nextNode = temp ->next;
            temp -> next = copyNode;
            copyNode -> next = nextNode;
            temp = nextNode;
        }

        return head;
    }
    Node* connectRandomPointers(Node* head){
        Node* temp = head;

        while(temp != nullptr){
            temp->next->random = (temp->random) ? temp->random->next : nullptr;
            temp = temp -> next -> next;
        }
        return head;
    }

    Node* connectNextPointers(Node* head){
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp != nullptr){
            res -> next = temp -> next;
            temp -> next = temp -> next -> next;
            res = res -> next;
            temp = temp -> next;

        }

        return dummyNode -> next;
    }
public:
    Node* copyRandomList(Node* head) {
        // Node* temp =head;
        // unordered_map<Node*, Node*> mpp;

        // while(temp != nullptr){
        //     Node* newNode = new Node(temp -> val);
        //     mpp[temp] = newNode;
        //     temp = temp -> next;
        // }

        // temp = head;

        // while(temp != nullptr){
        //     Node* copyNode = mpp[temp];
        //     copyNode -> next = mpp[temp -> next];
        //     copyNode -> random = mpp[temp -> random];

        //     temp = temp -> next;

        // }
        // return mpp[head];

        // 1. insert copies of node in between

        Node* temp = insertCopiesInBetween(head);
         
        // 2. connect random pointers

        temp = connectRandomPointers(temp);

        // 3. connect next Pointers

        temp = connectNextPointers(temp);
        return temp;
    }
};