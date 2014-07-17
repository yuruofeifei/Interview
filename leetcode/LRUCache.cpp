class LRUCache{
public:
    list<pair<int, int>> queue;
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int capacity;
    int size;
    
    LRUCache(int capacity) : size(0), capacity(capacity) {
        
    }
    
    int get(int key) {
        if (hash.find(key) == hash.end()) return -1;
        auto it = hash[key];
        hash.erase(key);
        queue.erase(it);
        size --;
        set(key, it->second);
        return it->second;
    }
    
    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            auto it = hash[key];
            queue.erase(it);
            size --;
        }
        if (size >= capacity) {
            auto it = queue.begin();
            hash.erase(it->first);
            queue.pop_front();
            size --;
        }
        queue.push_back(make_pair(key, value));
        hash[key] = --end(queue);
        size ++;
    }
};