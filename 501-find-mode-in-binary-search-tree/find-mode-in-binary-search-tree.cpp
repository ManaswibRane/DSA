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
    void inorder(TreeNode* root, unordered_map<int,int> &mp){
         if(root==NULL) return;
         inorder(root->left,mp);
         mp[root->val]++;
        inorder(root->right,mp);
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        inorder(root,mp);
        int maxEle,maxOcc=INT_MIN;
        for(auto it: mp){
               int ele=it.first;
               int occ=it.second;
               if(occ>maxOcc){
                   maxOcc=occ;
               }
        }
        vector<int> ans;
         for(auto it: mp){
               int ele=it.first;
               int occ=it.second;
               if(occ==maxOcc){
                   ans.push_back(ele);
               }
        }
        return ans;
    }
};