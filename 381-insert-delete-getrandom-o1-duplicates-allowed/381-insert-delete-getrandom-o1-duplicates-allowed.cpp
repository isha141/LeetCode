class RandomizedCollection { 
    vector<int>v;
    map<int,unordered_set<int>>mp;
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) { 
        bool temp=true;
    if(mp.count(val))
        temp=false;
        v.push_back(val);
            mp[val].insert(v.size()-1); 
        return temp;
    }
    
    bool remove(int val) { 
         auto itr=mp.find(val);
        if(itr!=end(mp))
        {
            auto itt=*itr->second.begin();
            itr->second.erase(itr->second.begin());
            v[itt]=v.back();
            mp[v.back()].insert(itt);
            mp[v.back()].erase(v.size()-1);
            v.pop_back(); 
            if(itr->second.size()==0)
                mp.erase(itr);
            return true;
        }
        return false;
    }
    int getRandom() {
     int n=rand()%v.size();
        return v[n];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */