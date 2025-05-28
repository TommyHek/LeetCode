/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>   // std::sort
using namespace std;

class Solution {
public:
    // Return the k most-frequent elements (order can be arbitrary)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Count occurrences of each number
        unordered_map<int,int> freq;    // key = number, value = frequency
        for (int n : nums) freq[n]++;

        //Copy (number, frequency) pairs into a vector so we can sort
        vector<pair<int,int>> freqList; // {number, frequency}
        freqList.reserve(freq.size());
        for (auto& [num, cnt] : freq) freqList.push_back({num, cnt});

        //Sort the vector by frequency in descending order
        sort(freqList.begin(), freqList.end(),
             [](const auto& a, const auto& b){ return a.second > b.second; });

        //Extract the first k numbers
        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i) result.push_back(freqList[i].first);
        return result;
    }
};


// @lc code=end

