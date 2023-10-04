class MyHashMap { 
    private:
    vector<int>v;
public:
    MyHashMap() {
        v.resize(1e6+3,-1);
    }
    
    void put(int key, int value) {
        v[key]=value;
    }
    
    int get(int key) {
        if(v[key]!=-1)
              return v[key];
        return -1;
    }
    
    void remove(int key) {
        v[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */