/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) {
            return;  
        }
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        temp.reserve(right - left + 1);

        int i = left;    
        int j = mid + 1; 

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = 0; k < (int)temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
