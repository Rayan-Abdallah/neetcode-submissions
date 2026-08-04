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
#include <map>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> ptrs = lists;
        ListNode* ans = new ListNode;
        ListNode* start = ans;
        map<int, vector<ListNode*> > mp;
        bool done = false;
        for(int i = 0; i < ptrs.size(); i++){
            if(ptrs[i] != nullptr){
                mp[ptrs[i]->val].push_back(ptrs[i]);
            }
        }
        for(auto it: mp){
            int val = it.first;
            for(auto p: it.second){
                while(p != nullptr && p->val == val){
                    ans->next = p;
                    ans = ans->next;
                    p = p->next;
                }
                if(p != nullptr){
                    mp[p->val].push_back(p);
                }
            }
        }
        start = start->next;
        return start;
    }
};
