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
    bool solve(TreeNode* lt,TreeNode* rt){
           if((lt==NULL && rt!=NULL) || (lt!=NULL && rt==NULL)) return false;
           if(lt==NULL && rt==NULL) return true;
           if(lt->val != rt->val) return false;
           else{
            return (solve(lt->left,rt->right) && solve(rt->left,lt->right));
           }
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return solve(root->left , root->right);
    }
};