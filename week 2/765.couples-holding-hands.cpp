/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(); // 2n
        // create a map to store the position of each person
        vector<int> pos(n);
        for(int i = 0; i < n; i++){
            pos[row[i]] = i;
        }

        int swaps = 0;
        // check every pair
        for(int i = 0; i < n; i += 2){
            int first = row[i];
            // find partner
            int partner = (first % 2 == 0) ? first + 1 : first - 1; 
            
            // check if partner is sitting next to first
            if(row[i+1] != partner){
                swaps++;
                
                // find partner's position
                int partnerPos = pos[partner]; 
                
                // exchange i+1 and partner
                int second = row[i+1];
                row[partnerPos] = second;
                row[i+1] = partner;

                // update pos
                pos[second] = partnerPos;
                pos[partner] = i+1;
            }
        }
        return swaps;
    }
};
// @lc code=end

