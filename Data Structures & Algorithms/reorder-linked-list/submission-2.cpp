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
        ListNode* temp = head;
        vector<ListNode*> rec;
        int count = 0;
        while(temp){
            rec.push_back(temp);
            count++;
            if(!temp->next)
                break;
            temp = temp->next;
        }
        int left = 0,right = count-1;
        while(left<right){
            rec[left]->next = rec[right];
            left++;
            if(left==right)
                break;
            rec[right]->next = rec[left];
            right--;
        }
        rec[left]->next = nullptr;
    }
};
