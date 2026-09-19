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
 *   1
 * 2   3
 * 
 *   1
 * 3   2
 * 
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both are null, we can say that is equivalent
        if (!p && !q) {
            return true;
        }

        // if one is null, then they are NOT equivalent
        if (!p || !q) {
            return false;
        }

        // if the node values don't match, return false
        if (p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};
