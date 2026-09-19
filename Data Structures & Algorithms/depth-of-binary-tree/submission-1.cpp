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
    int maxDepth(TreeNode* root, int depth = 0) {
        if (!root) {
            return depth;
        }
        const auto maxLeft = maxDepth(root->left, depth+1);
        const auto maxRight = maxDepth(root->right, depth+1);

        return maxLeft >= maxRight ? maxLeft : maxRight;
    }
};
