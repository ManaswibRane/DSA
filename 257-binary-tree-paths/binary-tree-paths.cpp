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
    vector<string> ans;
    void solve(string str,TreeNode* root){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            string s=to_string(root->val);
            str=str+s;
            ans.push_back(str);
            return;
        }
        str=str+to_string(root->val)+"->";
        if(root->left!=NULL){
            solve(str,root->left);
        }
         if(root->right!=NULL){
            solve(str,root->right);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve("",root);

        return ans;
    }
};