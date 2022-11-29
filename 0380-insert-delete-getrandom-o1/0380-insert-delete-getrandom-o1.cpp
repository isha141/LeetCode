class RandomizedSet { 
    unordered_map<int,int>mp;
    vector<int>ds;
    int count=0;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) { 
        if(mp.size() && mp.find(val)!=mp.end()) return 0;
         mp[val]=count;
        ds.push_back(val);
        count++;
        return 1;
    }
    
    bool remove(int val) { 
        if(mp.size() && mp.find(val)!=mp.end()){
            int temp=mp[val];
            mp.erase(val); 
            if(temp<count-1){
              ds[temp]=ds[count-1];
               ds.pop_back();
              mp[ds[temp]]=temp;
            // return 1;
            }
            else
            ds.pop_back();
            count-=1;
            return 1;
         }
        return 0;
    }
    
    int getRandom() { 
        int t=(rand() % (count)); 
        return  ds[t];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */