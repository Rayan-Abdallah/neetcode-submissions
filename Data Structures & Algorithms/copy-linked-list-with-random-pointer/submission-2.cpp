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
    unordered_map<Node*, Node*> mp;
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* start = new Node(head->val);
        Node* nodeLeft = start;
        Node* nodeRight = head;
        mp[nodeRight] = nodeLeft;
        while(nodeRight->next != NULL){
            nodeLeft->next = new Node(nodeRight->next->val);
            nodeLeft = nodeLeft->next;
            nodeRight = nodeRight->next;
            mp[nodeRight] = nodeLeft;
        }
        nodeLeft = start;
        nodeRight = head;
        while(nodeLeft != NULL){
            nodeLeft->random = mp[nodeRight->random];
            nodeLeft = nodeLeft->next;
            nodeRight = nodeRight->next;
        }
        return start;
    }
};
