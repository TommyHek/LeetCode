/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
private:
    double myPowWithLong(double x, long long n){
        if(n == 0 || x == 1) return 1;
        if(n < 0) return 1 / myPowWithLong(x, -n);//
        if(n % 2 == 0) return myPowWithLong(x * x, n / 2); //prevent overflow
        //if n is odd, we can reduce it to even by multiplying x once
        return x * myPowWithLong(x, n - 1); 
    }
public:
    double myPow(double x, int n) {
        return myPowWithLong(x,n); //call the private function
    }
};
// @lc code=end

