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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::function<bool(ListNode*, ListNode*)> recurseToRemove;
        recurseToRemove = [&] (ListNode* prev, ListNode* cur){
            if(cur == nullptr){
                return true;
            }
            bool status = recurseToRemove(cur, cur->next);
            if(status){
                n--;
            }
            else{
                return false;
            }
            if(n == 0){
                if(cur == head){
                    head = head->next;
                    return false;
                }
                prev->next = cur->next;
                return false;
            }
            else{
                return true;
            }
        };
        recurseToRemove(nullptr, head);
        return head;
    }
};
