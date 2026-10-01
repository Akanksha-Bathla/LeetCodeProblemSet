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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        if(root->left == NULL && root->right == NULL) return {root->val};
        stack<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.top();
            q.pop();

            if(node->right != NULL) q.push(node->right);
            if(node->left != NULL) q.push(node->left);

            ans.push_back(node->val);
        }

        return ans;
    }
};