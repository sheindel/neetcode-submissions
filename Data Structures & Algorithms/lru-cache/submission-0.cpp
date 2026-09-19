#include <map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) ,_cache(capacity), _cacheOrder(capacity) {
        
    }
    
    int get(int key) {
        // check if in the cache, if not, return -1
        if (!_cache.contains(key)) {
            return -1;
        }

        // if the cache is at capacity, and since it already existed 
        // in the cache, we need to delete the item mid-cache first
        if (_cacheOrder.size() >= _capacity) {
            _cacheOrder.remove(key);
        }

        // then we can add the item at the back
        _cacheOrder.push_back(key);

        return _cache[key];
    }
    
    void put(int key, int value) {
        // do cache cleanup first...
        if (_cacheOrder.size() >= _capacity) {
            if (!_cache.contains(key)) {
                auto front = _cacheOrder.front();
                _cacheOrder.pop_front();
                _cache.erase(front);
            } else { // if it already existed...
                _cacheOrder.remove(key);
            }
        }
        
        // then we can add the item at the back
        _cacheOrder.push_back(key);
        
        _cache[key] = value;
    }

private:
    std::unordered_map<int, int> _cache;
    std::list<int> _cacheOrder;
    int _capacity;
};
