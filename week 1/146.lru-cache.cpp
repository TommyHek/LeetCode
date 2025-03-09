/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
class LRUCache {
private:
    //key, value, iterator
    unordered_map<int, pair<int,list<int>::iterator>> cache;
    //order of keys
    list<int>* order;
    int maxCapacity;
public:
    LRUCache(int capacity) {
        order = new list<int>;
        maxCapacity = capacity;
    }
    
    int get(int key) {
        //find key in cache, if not found the interator will return cache->end()
        auto result = cache.find(key);
        if( result != cache.end()){
            order->erase(result->second.second);//erase the key from the list
            order->push_front(key);
            result->second.second = order->begin();//update the iterator in the cache
            return result->second.first;//return the value
        }
        //if key is not found, return -1
        return -1;
    }
    
    void put(int key, int value) {
        auto result = cache.find(key);

        //if key exists, update the value
        if(result != cache.end()){
            //if key is found, move the key to the front of the list
            order->erase(result->second.second);//erase the key from the list
            order->push_front(key);
            result->second.second = order->begin();//update the iterator in the cache
            //update the key value pair
            result->second.first = value;
        }else{
            //if key does not exist, insert the key value pair
            if(cache.size() == maxCapacity){
                //if cache is full, remove the least recently used key
                cache.erase(order->back());
                //remove the least recently used key from the list
                order->pop_back();
            }
            //Add new key to the front of the list
            order->push_front(key);
            //insert the key value iterator pair to the cache
            cache[key] = {value, order->begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

