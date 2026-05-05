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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* one = list1;
        ListNode* two = list2;
        ListNode* res = new ListNode();
        ListNode* head = res;
        while(one && two){
            if(one->val<=two->val){
                ListNode* node = new ListNode(one->val);
                res->next = node;
                res = res->next;
                one = one->next;
            }
            else{
                ListNode* node = new ListNode(two->val);
                res->next = node;
                res = res->next;
                two = two->next;
            }
        }
        while(one){
            ListNode* node = new ListNode(one->val);
            res->next = node;
            res = res->next;
            one = one->next;
        }
        while(two){
            ListNode* node = new ListNode(two->val);
            res->next = node;
            res = res->next;
            two = two->next;
        }
        return head->next;
    }
};
