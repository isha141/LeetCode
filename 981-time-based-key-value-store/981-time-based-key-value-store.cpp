class TimeMap { 
    unordered_map<string,map<int,string>>mp;
    
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int t) {
        mp[key].insert({t,value});
        }
    string get(string key, int time) { 
        if(mp.find(key)==mp.end())
            return ""; 
        auto it=mp[key].upper_bound(time);
        if(it==mp[key].begin())
            return ""; 
        // cout<<it->first<<" hy"<<it->second<<endl;
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */