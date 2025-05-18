/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses,
                               vector<vector<int>>& prerequisites)
    {
        // Build the graph
        // nextCourses[pre] = {course1, course2, ...}
        vector<vector<int>> nextCourses(numCourses);  
        // indegree[course] = number of prerequisites for course
        vector<int> indegree(numCourses, 0);  

        // Fill the graph
        for (const auto& pair : prerequisites) {
            int course = pair[0];     
            int pre    = pair[1];     
            nextCourses[pre].push_back(course);
            ++indegree[course];       
        }
        // Find all courses with no prerequisites
        queue<int> ready;        
        for (int c = 0; c < numCourses; ++c)
            if (indegree[c] == 0) ready.push(c);

        // BFS to find the order of courses
        vector<int> order;       
        while (!ready.empty()) {
            int cur = ready.front();
            ready.pop();
            order.push_back(cur);     
            // For each course that depends on cur, reduce its indegree
            for (int next : nextCourses[cur]) {  
                if (--indegree[next] == 0)  // If indegree becomes 0, add it to the queue     
                    ready.push(next);            
            }
        }

        // If the order contains all courses, return it
        // else, return an empty vector (there's a cycle)
        return (order.size() == numCourses) ? order : vector<int>{}; 
    }
};
// @lc code=end

