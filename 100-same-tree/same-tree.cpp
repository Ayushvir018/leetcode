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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: both nodes are null, meaning they are identical empty trees.
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // If only one node is null, the structures do not match.
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // If values differ, the trees are not the same.
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check if left and right subtrees match.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
