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
    void dfs(TreeNode* root,vector<int> &root1){
        root1.push_back(root->val);
        if(root->left)
            dfs(root->left,root1);
        else
            root1.push_back(0);
        if(root->right)
            dfs(root->right,root1);
        else
            root1.push_back(0);
        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p && q)
            return false;
        if(p && !q)
            return false;
        vector<int> p1,q1;
        dfs(p,p1);
        dfs(q,q1);
        int i=0,j=0;
        while(i<p1.size() && j<q1.size()){
            if(p1[i]==q1[j]){
                i++;
                j++;
            }
            else
                return false;
        }
        return true;
    }
};
