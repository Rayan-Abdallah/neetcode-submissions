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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* start = res;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val + carry;
            res->val = sum%10;
            sum/=10;
            carry = sum;
            l1 = l1->next;
            l2 = l2->next;
            if(carry != 0 || l1 != nullptr || l2 != nullptr){
                res->next = new ListNode();
                res = res->next;
            }
        }
        ListNode* left = nullptr;
        if(l1 != nullptr){
            left = l1;
        }
        else if(l2 != nullptr){
            left = l2;
        }
        while(left != nullptr){
            int sum = left->val + carry;
            res->val = sum%10;
            sum/=10;
            carry = sum;
            left = left->next;
            if(carry != 0 || left != nullptr){
                res->next = new ListNode();
                res = res->next;
            }
        }
        while(carry != 0){
            res->val = carry%10;
            carry/=10;
            if(carry != 0){
                res->next = new ListNode();
                res = res->next;
            }
        }
        return start;
    }
};
