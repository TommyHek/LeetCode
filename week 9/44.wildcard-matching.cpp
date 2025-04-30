/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class WildcardMatcher {
public:
    // Return true if pattern p matches the whole string s
    bool isMatch(const string& s, const string& p) {
        int m = s.size(), n = p.size();
        // dp[i][j] : first i chars of s match first j chars of p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;                      // both empty
        // empty string vs. pattern with leading '*'
        for (int j = 1; j <= n && p[j - 1] == '*'; ++j)
            dp[0][j] = true;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char pc = p[j - 1], sc = s[i - 1];
                if (pc == '*') {
                    // 1) * matches empty   2) * consumes one char of s
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (pc == '?' || pc == sc) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

