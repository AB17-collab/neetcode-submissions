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
        ListNode* res = new ListNode(-1);
        ListNode* temp = res;
        int k = lists.size();
        priority_queue<pair<int,ListNode*>,
            vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;

        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }

            temp->next = it.second;
            temp = temp->next;
        }
        return res->next;
    }
};
