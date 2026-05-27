/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> one,two;
        TreeNode* ansRoot;
        TreeNode* t1 = root;
        TreeNode* t2 = root;
        while(t1){
            if(t1->val==p->val){
                one.push_back(t1->val);
                break;
            }
            else if(t1->val<p->val){
                one.push_back(t1->val);
                t1 = t1->right;
            }
            else{
                one.push_back(t1->val);
                t1 = t1->left;
            }
        }
        while(t2){
            if(t2->val==q->val){
                two.push_back(t2->val);
                break;
            }
            else if(t2->val<q->val){
                two.push_back(t2->val);
                t2 = t2->right;
            }
            else{
                two.push_back(t2->val);
                t2 = t2->left;
            }
        }
        for(int k=0;k<one.size();k++)
            cout<<one[k]<<" ";
        for(int l=0;l<two.size();l++)
            cout<<two[l]<<" ";
        int l1 = one.size();
        int l2 = two.size();
        int i=0,j=0;
        int lastIndex = 0;
        int ele;
        while(i<l1 && j<l2){
            if(one[i] == two[j]){
                lastIndex = j;
                ele = one[i];
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        ansRoot = root;
        while(ansRoot){
            if(ansRoot->val == ele){
                break;
            }
            else if(ansRoot->val>ele){
                ansRoot = ansRoot->left;
            }
            else
                ansRoot = ansRoot->right;
        }
        return ansRoot;
    }
};
