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
    int dfs(TreeNode* root,int prevSum){
        if(root==NULL) return 0;
         prevSum=prevSum*10+root->val;
        if(root->left==NULL && root->right==NULL) return prevSum;
       
        return dfs(root->left,prevSum)+dfs(root->right,prevSum);
    }
    int sumNumbers(TreeNode* root) {
      
        return dfs(root,0);
    }
};