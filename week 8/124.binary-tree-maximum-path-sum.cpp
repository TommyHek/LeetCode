/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
using namespace std;
#include <limits.h> // INT_MIN
#include <algorithm> 
class Solution {
    private:
        int globalMax = INT_MIN;  // Initialize to the smallest possible integer value  
    
        int maxGain(TreeNode* node) {
            if (!node) return 0; // Base case: if the node is null, return 0
    
            // Recursively calculate the maximum gain from left and right subtrees
            // We only consider positive gains, so we use max(0, ...) to ignore negative paths
            int leftGain  = max(0, maxGain(node->left));
            int rightGain = max(0, maxGain(node->right));
    
            // Calculate the maximum path sum with the current node as the highest node
            int wholePathSum = leftGain + node->val + rightGain;
            // Update the global maximum path sum if the current path sum is greater
            globalMax = max(globalMax, wholePathSum);
            
            return node->val + max(leftGain, rightGain);
        }
    
    public:
        int maxPathSum(TreeNode* root) {
            maxGain(root);
            return globalMax;
        }
};
// @lc code=end

