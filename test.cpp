#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <deque>
using namespace std;
map<int, int>* cache;
list<int>* order;

int maxCapacity;

void initCache(int capacity){
    cache = new map<int, int>;
    order = new list<int>;
    maxCapacity = capacity;
}

int get(int key){
    return cache->find(key) == cache->end() ? -1 : cache->find(key)->second;
}

void put(int key, int value){
    cache->insert(pair<int, int>(key, value));

}
//239. Sliding Window Maximum

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    vector<int> result;
    deque<int> dq;
    //if k is 1, return the array
    if(k==1)
        return nums;
    //k != 1
    for(int i = 0; i < nums.size(); i++){//iterate through the array
        //if the front of the deque is out of the window, pop it
        if(!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();
        //if the back of the deque is smaller than the current element, pop it
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        //push the current element
        dq.push_back(i);
        
        //if the window is full, push the front of the deque to the result
        if(i >= k - 1)
            result.push_back(nums[dq.front()]);
    }
    return result;
}
int main(){
    initCache(5);
    printf("Max Capacity:%d ,Current Capacity:%d \n",maxCapacity,cache->size());
    put(1,1);
    put(2,2);
    
    printf("Max Capacity:%d ,Current Capacity:%d \n",maxCapacity,cache->size());
    auto it = cache->find(1);

    if(it != cache->end()){
        printf("Key found!! Value = %d \n",it->second);
        (*cache)[1] = 100;
        printf("Update value to 100\n");
    }else{
        printf("Key not found!!\n");
    }

    for(const auto&kv : *cache){
        printf("Key:%d, Value:%d\n",kv.first,kv.second);
    }
    order->push_front(1);
    order->push_front(2);
    order->push_front(3);

    printf("End of List: %d\n",order->back());

    cache->erase(order->back());

    for(const auto&kv : *cache){
        printf("Key:%d, Value:%d\n",kv.first,kv.second);
    }
    //Test Vector

    vector<int> test = {1,-1,1};
    vector<int> result = maxSlidingWindow(test,1);
    for(int i = 0; i < result.size(); i++){
        printf("%d ",result[i]);
    }
}