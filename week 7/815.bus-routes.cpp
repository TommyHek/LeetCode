/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes,
                              int source, int target) {
        if (source == target) return 0;
        
        //To map each stop to the routes that pass through it
        //Key: stop, Value: list of routes that pass through the stop
        unordered_map<int, vector<int>> stopToRoutes;
        for (int routeId = 0; routeId < routes.size(); routeId++) {
            for (int stop : routes[routeId]) {
                stopToRoutes[stop].push_back(routeId); //To map stop to routeId ex: stopToRoutes[1] = [0, 1]
            }
        }

        queue<int> stopsQ;   //Current stops to visit               
        stopsQ.push(source);
        unordered_set<int> stopVisited;  //To track visited stops  
        stopVisited.insert(source);
        vector<bool> routeVisited(routes.size(), false);  //To track visited routes

        int busCount = 0;

        
        while (!stopsQ.empty()) {
            ++busCount;                          
            int levelSize = stopsQ.size(); //To track the number of stops at the current level

            for (int i = 0; i < levelSize; ++i) {
                int curStop = stopsQ.front();
                stopsQ.pop();

                //For each route that passes through the current stop
                for (int routeId : stopToRoutes[curStop]) {
                    if (routeVisited[routeId]) continue;     

                    routeVisited[routeId] = true;            
                    //For each stop in the current route
                    for (int nextStop : routes[routeId]) {
                        if (nextStop == target) return busCount;
                        if (stopVisited.insert(nextStop).second) {
                            stopsQ.push(nextStop); //If the stop is not visited, add it to the queue
                        }
                    }
                }
            }
        }
        return -1; 
    }
};

// @lc code=end

