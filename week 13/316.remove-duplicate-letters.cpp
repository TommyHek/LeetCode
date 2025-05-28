/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(const string& s) {
        const int N = s.size();
        // Create a vector to store the last position of each character
        vector<int> lastPos(26, -1);
        for (int i = 0; i < N; ++i)
            lastPos[s[i] - 'a'] = i;

        // Use a string to build the result and a vector to track characters in the stack
        string res;
        vector<bool> inStack(26, false);

        // Iterate through each character in the string
        for (int i = 0; i < N; ++i) {
            char c = s[i];
            int id = c - 'a';

            if (inStack[id]) continue;                     

            // If the current character is smaller than the last character in the result
            while (!res.empty() &&
                   res.back() > c &&
                   lastPos[res.back() - 'a'] > i) {
                inStack[res.back() - 'a'] = false;         
                res.pop_back();
            }

            
            res.push_back(c);
            inStack[id] = true;                            
        }
        return res;
    }
};

// @lc code=end

