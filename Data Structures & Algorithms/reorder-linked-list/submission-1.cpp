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
    void reorderList(ListNode* head) {
        ListNode* l = head;
        if(head->next == nullptr){
            return;
        }
        ListNode* r;
        bool done = false;
        while(!done){
            r = l;
            ListNode* prevR = nullptr;
            while(r->next != nullptr){
                prevR = r;
                r = r->next;
            }
            if(l == prevR){
                done = true;
                continue;
            }
            ListNode* nextL = l->next;
            l->next = r;
            l = l->next;
            l->next = nextL;
            l = l->next;
            prevR->next = nullptr;
            if(l == prevR){
                done = true;
                continue;
            }
        }
    }
};
