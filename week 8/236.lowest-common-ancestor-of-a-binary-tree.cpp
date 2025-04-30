/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution {
public:
    // Main function to find the lowest common ancestor
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is null or equal to p or q, return it
        if (root == nullptr || root == p || root == q) return root;

        // Search left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If both left and right are not null, current node is the LCA
        if (leftLCA != nullptr && rightLCA != nullptr) return root;

        // Otherwise, return the non-null one
        return leftLCA != nullptr ? leftLCA : rightLCA;
    }
};

// @lc code=end

