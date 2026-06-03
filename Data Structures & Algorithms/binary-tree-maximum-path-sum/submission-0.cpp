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
    int findMaxPath(TreeNode* root,int &ans){
        if(root==nullptr)
            return 0;
        int l = max(0,findMaxPath(root->left,ans));
        int r = max(0,findMaxPath(root->right,ans));

        int temp = max(max(l,r)+root->val,root->val);
        int res = max(temp,l+r+root->val);
        ans = max(res,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        ans = max(ans,findMaxPath(root,ans));
        return ans;
    }
};
