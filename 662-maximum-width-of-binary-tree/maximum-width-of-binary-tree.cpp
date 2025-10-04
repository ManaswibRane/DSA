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
long long ans=INT_MIN;
void solve(TreeNode* root){
     if(root==NULL){
        return;
     }
      queue<pair<TreeNode*,long long>> q;
      q.push({root,0});
      while(!q.empty()){
        long long x=q.size();
        long long lmost=INT_MAX,rmost=INT_MIN;
        long long mmin=q.front().second;
        while(x--){
            auto it=q.front();
            q.pop();
            long long dist=it.second;
            if(dist<lmost){
                lmost=dist;
            }
            if(dist>rmost){
                rmost=dist;
            }
            TreeNode* node=it.first;
             if(node->left!=NULL){
                q.push({node->left,dist*2-mmin});
                
            }
            if(node->right!=NULL){
                q.push({node->right,dist*2+1-mmin});

            }
           
        }
        ans=max(ans,rmost-lmost+1);
      }
    
}
    int widthOfBinaryTree(TreeNode* root) {
        solve(root);
          return (int)ans;
    }
};