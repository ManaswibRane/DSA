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
    vector<double> averageOfLevels(TreeNode* root) {
          if(root==NULL) return {};
          queue<TreeNode* > q;
          q.push(root);
          vector<double> ans;
          while(!q.empty()){
             int n=q.size();
             int sz=n;
             double sum=0;
             while(sz--){

                TreeNode* node=q.front();
                sum+=node->val;
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                q.pop();

             }
             double v=sum/n;
             ans.push_back(v);
          }
          return ans;
    }
};