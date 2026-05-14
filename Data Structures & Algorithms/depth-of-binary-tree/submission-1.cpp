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
    void goDeep(TreeNode* root,int &maxComp,int &count){
        if(root){
            count++;
            maxComp = max(maxComp,count);
        }
        if(root->left){
            goDeep(root->left,maxComp,count);
            count--;
        }
        if(root->right){
            goDeep(root->right,maxComp,count);
            count--;
        }
        return;
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int ans = INT_MIN;
        int count = 0;
        goDeep(root,ans,count);
        return ans;
    }
};
