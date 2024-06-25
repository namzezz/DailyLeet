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
    int sum = 0; // Cumulative sum of nodes visited

    TreeNode* bstToGst(TreeNode* root) {
        convertBSTHelper(root);
        return root;
    }

private:
    void convertBSTHelper(TreeNode* root) {
        if (!root) return;

        // Traverse the right subtree first
        convertBSTHelper(root->right);

        // Update the value of the current node
        sum += root->val;
        root->val = sum;

        // Traverse the left subtree
        convertBSTHelper(root->left);
    }
};