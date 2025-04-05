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
  
    int bfs(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int deepest = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            deepest++;
        }

        return deepest;
    }


    void findAllDeeps(TreeNode* root, vector<TreeNode*>& allDeeps, int level) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                if (depth == level) {
                    allDeeps.push_back(node);
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& allDeep) {
        if (!root) return nullptr;
        for (TreeNode* x : allDeep) {
            if (root == x) return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, allDeep);
        TreeNode* right = lowestCommonAncestor(root->right, allDeep);

        if (left && right) return root;
        return left ? left : right;
    }

   
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int level = bfs(root);
        vector<TreeNode*> allDeeps;
        findAllDeeps(root, allDeeps, level);
        return lowestCommonAncestor(root, allDeeps);
    }
};
