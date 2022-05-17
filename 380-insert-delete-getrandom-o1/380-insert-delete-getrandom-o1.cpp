class RandomizedSet { 
    map<int,int>mp;
    vector<int>v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {  
        bool temp=true;
        if(mp.count(val))
           return false;
        v.push_back(val);
        mp[val]=v.size()-1;
        return temp;
        
    }
    
    bool remove(int val) {
        if(mp.count(val))
        {
            int temp=mp[val];
            mp.erase(val);
            if(temp<v.size()-1)
            { 
               v[temp]=v[v.size()-1] ;  
               v.pop_back();
               mp[v[temp]]=temp;
            }  
            else
                 v.pop_back();
            // for(auto itr: mp)
            //     cout<<itr.first<<" "<<itr.second<<endl;
            return true;
        }
        return false;
    }  
    int getRandom() {
      return v[rand()%v.size()];  
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */