/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    // Function to remove adjacent duplicates in a string
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;   
        // Using a stack to keep track of characters and their counts
        for (char ch : s) {
            if (!st.empty() && st.back().first == ch) {
                ++st.back().second;            
            } else {
                st.push_back({ch, 1});         
            }
            // If the count of the last character reaches k, pop it from the stack
            if (st.back().second == k) {
                st.pop_back();
            }
        }

        // Construct the result string from the stack
        string result;
        // Iterate through the stack and append characters to the result
        for (auto &[letter, cnt] : st) {
            result.append(cnt, letter);        
        }
        return result;
    }
};
// @lc code=end

