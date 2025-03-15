/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
class LFUCache {
private:
    unordered_map<int, pair<int, pair<int, list<int>::iterator>>> cache;//key, value, freq, iterator
    unordered_map<int, list<int>> freqList;//freq, list of keys
    int minFreq;
    int maxCapacity;

    void updateFreq(int key) {
        int freq = cache[key].second.first;//get the current freq
        freqList[freq].erase(cache[key].second.second);//erase the key from the list
        if (freq == minFreq && freqList[freq].empty()) minFreq++;//if the list is empty, update minFreq
        cache[key].second.first++;
        freqList[cache[key].second.first].push_front(key);//push the key to the new freq list
        cache[key].second.second = freqList[cache[key].second.first].begin();//update the iterator
    }
public:
    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        updateFreq(key);
        return cache[key].first;
    }

    void put(int key, int value) {
        if (maxCapacity <= 0) return;

        if (cache.count(key)) {
            cache[key].first = value;
            updateFreq(key);
        } else {
            if (cache.size() == maxCapacity) {
                int removeKey = freqList[minFreq].back();
                freqList[minFreq].pop_back();
                cache.erase(removeKey);
            }

            minFreq = 1;
            freqList[minFreq].push_front(key);
            cache[key] = {value, {minFreq, freqList[minFreq].begin()}};//value, freq, iterator
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

