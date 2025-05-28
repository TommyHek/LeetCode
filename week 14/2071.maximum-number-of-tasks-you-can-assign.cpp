/*
 * @lc app=leetcode id=2071 lang=cpp
 *
 * [2071] Maximum Number of Tasks You Can Assign
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canFinish(int k,
                   const vector<int>& tasks,
                   const vector<int>& workers,
                   int pills, int strength)
    {
        multiset<int> pool; //worker strengths
        int n = workers.size();

        // strongest k workers
        for (int i = n - k; i < n; ++i)
            pool.insert(workers[i]);

        // go through k tasks, hardest first
        for (int i = k - 1; i >= 0; --i) {
            int need = tasks[i];

            // 1) try the strongest worker
            auto strongest = prev(pool.end());
            if (*strongest >= need) {
                pool.erase(strongest);
                continue;
            }

            // 2) need a pill
            if (pills == 0) return false;
            auto it = pool.lower_bound(need - strength); // weakest who works after pill
            if (it == pool.end()) return false;
            pool.erase(it);
            --pills;
        }
        return true;
    }

public:
    int maxTaskAssign(vector<int>& tasks,
                      vector<int>& workers,
                      int pills,
                      int strength)
    {
        sort(tasks.begin(),   tasks.end());   // easy → hard
        sort(workers.begin(), workers.end()); // weak → strong

        int lo = 0, hi = min(tasks.size(), workers.size());

        // binary search the answer
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (canFinish(mid, tasks, workers, pills, strength))
                lo = mid;      // mid works, try more
            else
                hi = mid - 1;  // mid fails, try less
        }
        return lo;
    }
};
// @lc code=end

