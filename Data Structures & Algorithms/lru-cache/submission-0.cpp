#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int,int>> dll; // doubly linked list: {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> cache; // key -> iterator in dll

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // not found
        }
        // Move the accessed node to the front (most recently used)
        auto it = cache[key];
        int value = it->second;
        dll.erase(it);
        dll.push_front({key, value});
        cache[key] = dll.begin();
        return value;
    }
    
    void put(int key, int value) {
        // If key already exists, update and move to front
        if (cache.find(key) != cache.end()) {
            dll.erase(cache[key]);
        } else if ((int)dll.size() == capacity) {
            // Evict least recently used (back of list)
            auto lru = dll.back();
            cache.erase(lru.first);
            dll.pop_back();
        }
        // Insert new node at front
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};
