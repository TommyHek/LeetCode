/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
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
#include <unordered_map>

class Solution {
private:
    TreeNode* buildSubtree(const vector<int>& preorder, int &preIndex,
        const vector<int>& inorder, int inLeft, int inRight,
        unordered_map<int, int> &inMap) {
    
    if (inLeft > inRight) {
    return nullptr;
    }

    int rootVal = preorder[preIndex];
    preIndex++; 

    TreeNode* root = new TreeNode(rootVal);

    int inIdx = inMap[rootVal];
    // Build the left subtree using the updated preIndex
    root->left = buildSubtree(preorder, preIndex, inorder, inLeft, inIdx - 1, inMap);
    // Build the right subtree using the updated preIndex
    root->right = buildSubtree(preorder, preIndex, inorder, inIdx + 1, inRight, inMap);

    return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < (int)inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int preIndex = 0;
        
        return buildSubtree(preorder, preIndex, inorder, 0, inorder.size() - 1, inMap);
    }
};
// @lc code=end

