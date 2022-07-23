class NumberContainers { 
    map<int,int>mp;
    map<int,set<int>>mp1;
public:
    NumberContainers() {
        mp.clear();
        mp1.clear();
    }
    
    void change(int index, int number) {
        auto itr=mp.find(index);
        if(itr!=mp.end()){
            mp1[itr->second].erase(index); 
            if(mp1[itr->second].empty()) 
                mp1.erase(itr->second);
            mp1[number].insert(index);
            mp[index]=number;
        } 
        else{
            mp1[number].insert(index);
          mp[index]=number;
       }
    }
    int find(int number) {
        if(mp1.find(number)!=mp1.end())
            return *mp1[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */