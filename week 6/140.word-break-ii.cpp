/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
    private:
    vector<string> dfs(const string &s, 
                       int start, 
                       const unordered_set<string>& wordSet,
                       unordered_map<int, vector<string>>& memo) 
    {
        
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        if (start == (int)s.size()) {
            return {""};
        }
        
        vector<string> results;
        
        for (int end = start + 1; end <= (int)s.size(); end++) {
            string word = s.substr(start, end - start);
            
            if (wordSet.find(word) != wordSet.end()) {
                vector<string> subList = dfs(s, end, wordSet, memo);
                
                for (auto &sub : subList) {
                    if (sub.empty()) {
                        results.push_back(word);
                    } else {
                        results.push_back(word + " " + sub);
                    }
                }
            }
        }
        
        memo[start] = results;
        return results;
    }
public:
    vector<string> wordBreak(const string &s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        
        return dfs(s, 0, wordSet, memo);
    }
    
};

// @lc code=end

