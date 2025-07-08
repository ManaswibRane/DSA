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
    void dfs(int & count,TreeNode* root){
        if(root== NULL) return;
        count++;
         dfs(count,root->left);
          dfs(count,root->right);
    }
    int countNodes(TreeNode* root) {
        int count=0;
        dfs(count,root);
        return count;
        
    }
};