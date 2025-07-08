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
    void dfs(int depth , int& maxDepth,TreeNode* root){
        if(root==NULL) return;
        if(root!=NULL) depth++;
        if(root->left ==NULL && root->right==NULL){
            maxDepth=max(depth,maxDepth);
            return;
        }
        dfs(depth,maxDepth,root->left);
        dfs(depth,maxDepth,root->right);

    }
    int maxDepth(TreeNode* root) {
        int maxDepth=0,depth=0;
        dfs(depth,maxDepth,root);
        return maxDepth;
    }
};