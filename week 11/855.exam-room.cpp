/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start
#include <set>
using namespace std;
class ExamRoom {
private:
    int n; // Total number of seats               
    set<int> taken;  // Set to store occupied seats
public:
    ExamRoom(int totalSeats) : n(totalSeats) {}

    // Function to find the best seat to occupy
    int seat() {
        // If no seats are taken, occupy the first seat
        if (taken.empty()) {
            taken.insert(0);
            return 0;
        }

        int bestSeat = 0; // Best seat to occupy          
        int maxDist  = *taken.begin(); // Distance from the first occupied seat

        int prevSeat = -1;// Previous occupied seat

        // Iterate through the occupied seats to find the best seat
        for (int currSeat : taken) {
            if (prevSeat != -1) {                    
                int mid = (prevSeat + currSeat) / 2; // Midpoint between two occupied seats
                int dist = (currSeat - prevSeat) / 2; // Distance to the midpoint
                if (dist > maxDist) { // if this distance is greater than the current max
                    maxDist = dist;
                    bestSeat = mid;
                }
            }
            prevSeat = currSeat;
        }

        
        int rightDist = (n - 1) - *taken.rbegin(); // Distance from the last occupied seat
        if (rightDist > maxDist) {
            bestSeat = n - 1;
        }

        taken.insert(bestSeat); // Occupy the best seat
        return bestSeat;
    }

    // Function to free up a seat
    void leave(int p) {
        taken.erase(p);
    }
};


/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

