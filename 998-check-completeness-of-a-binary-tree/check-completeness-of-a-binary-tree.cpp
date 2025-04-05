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
    bool bfs(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int deepest = 0;
        bool noChild=false;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();

                    if (node->left) {
                if (noChild) return false;
                q.push(node->left);
            } else {
                noChild = true; 
            }

            if (node->right) {
                if (noChild) return false; 
                q.push(node->right);
            } else {
                noChild = true; 
            }
            }  
        }

        return true;
    }

    bool isCompleteTree(TreeNode* root) {
    
        return  bfs(root);
    }
};
