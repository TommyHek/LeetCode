/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
#include <unordered_map>
#include <stack>
using namespace std;
class FreqStack {
private:
    unordered_map<int, int> freq;    // Maps value to its frequency          
    unordered_map<int, stack<int>> buckets; // Maps frequency to a stack of values with that frequency
    int maxFreq = 0;                                

public:
    FreqStack() = default;

    // Pushes an integer onto the stack.
    void push(int val) {
        int f = ++freq[val];        
        // If this frequency is greater than the current max frequency, update maxFreq
        if (f > maxFreq) maxFreq = f;         
        buckets[f].push(val);                 
    }

    // Pops the most frequent element from the stack.
    int pop() {
        int val = buckets[maxFreq].top();     
        buckets[maxFreq].pop(); // Remove the value from the current max frequency stack              
        if (--freq[val] == 0) freq.erase(val); // Remove value from freq map if its frequency is zero

        // If the current max frequency stack is empty, decrease maxFreq
        if (buckets[maxFreq].empty())         
            --maxFreq;
        return val;                           
    }
};


/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

