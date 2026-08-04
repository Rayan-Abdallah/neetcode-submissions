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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> ptrs = lists;
        ListNode* ans = new ListNode;
        ListNode* start = ans;
        bool done = false;
        while(!done){
            int minVal = 1001;
            vector<ListNode*> newPtrs;
            for(int i = 0; i < ptrs.size();i++){
                if(ptrs[i] != nullptr){
                    minVal = min(minVal, ptrs[i]->val);
                    newPtrs.push_back(ptrs[i]);
                }
            }
            std::cout<<minVal<<" "<<newPtrs.size()<<endl;
            if(newPtrs.empty()){
                done = true;
                continue;
            }
            for(int i = 0; i < newPtrs.size(); i++){
                while(newPtrs[i] != nullptr && newPtrs[i]->val == minVal){
                    ans->next = new ListNode(minVal);
                    ans = ans->next;
                    newPtrs[i] = newPtrs[i]->next;
                }
            }
            ptrs = newPtrs;
        }
        start = start->next;
        return start;
    }
};
