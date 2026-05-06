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
        if(!head)
            return nullptr;
        if(head && !head->next && n==1){
            head = nullptr;
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            if(!temp->next)
                break;
            temp = temp->next;
        }
        int j = count-n;
        ListNode* temp2 = head;
        if(j==0){
            head = head->next;;
            return head;
        }
        while(j>1){
            temp2 = temp2->next;
            j--;
        }
        temp2->next = temp2->next->next;
        return head;
    }
};
