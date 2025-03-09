#include <iostream>
#include <map>
#include <list>

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

}