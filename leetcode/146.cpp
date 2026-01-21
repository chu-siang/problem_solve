class LRUCache {
private:
    int capacity;
    list<int>usageOrder; //linked_list for order <key> iterator
    unordered_map<int,pair<int,list<int>::iterator>>cache; // <key,<val,list_node>>
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())return -1;
        usageOrder.erase(cache[key].second);
        usageOrder.push_front(key);
        cache[key].second = usageOrder.begin();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            usageOrder.erase(cache[key].second);
            usageOrder.push_front(key);
            cache[key] = {value,usageOrder.begin()};
            return;
        }
        if(cache.size() >= this->capacity){
            int lrukey = usageOrder.back();
            cache.erase(lrukey);
            usageOrder.pop_back();
            
        }
        usageOrder.push_front(key);
        cache[key] = {value,usageOrder.begin()}; 
    }
};