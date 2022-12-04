class LockingTree { 
    private:
    vector<int>par;
    int count=0;
    map<int,int>mp;
    map<int,vector<int>>checkpar;
    int n; 
    map<int,int>fpar;
    void findparent() {
      for(int i=0;i<n;++i){
          fpar[i]=par[i]; 
          checkpar[par[i]].push_back(i);
       }
      return ;
   }
    
   bool isvalid(int num,int user){
       if(num==-1)
           return 1;
       if(mp.find(num)!=mp.end())
           return 0;
       return isvalid(fpar[num],user);
       // return 1;
   }
    bool solve(int num,int user,bool &flag){
        if(num>=n)
            return 1;
        if(mp.find(num)!=mp.end()){
            mp.erase(num); 
            flag=1;
        }
       for(auto itr: checkpar[num]){
           if(!solve(itr,user,flag))
               return 0;
       }
        return 1;
    }
public:
    LockingTree(vector<int>& parent) {
        par=parent;
        n=par.size();
        findparent(); 
        // for(auto itr: fpar)
            // cout<<itr.first<<" "<<itr.second<<endl;
        return ;
    }
    
    bool lock(int num, int user) {
        count++;
         if(mp.find(num)!=mp.end())
             return 0;
          mp[num]=user;
        return 1;
    }
    
    bool unlock(int num, int user) {
        count++;
        if(mp.find(num)==mp.end())
            return 0;
        auto itr=mp[num];
        if(itr!=user)
            return 0;
        mp.erase(num);
        return 1;
    }
    
    bool upgrade(int num, int user) {
        
        if(mp.find(num)!=mp.end())
            return 0; 
        bool flag=0;
         // cout<<" ith"<<count<<"isahhha"<<num<<" "<<user<<endl;
        // count++;
        if(!isvalid(num,user)){
            // cout<<flag<<" ith"<<count<<"**"<<num<<" "<<user<<endl;
            return 0;
        }
           
         solve(num,user,flag);
       cout<<flag<<" ith"<<count<<"*&*"<<num<<" "<<user<<endl;
        if(!flag)
            return 0;
      // cout<<flag<<" ith"<<count<<"isahhha"<<num<<" "<<user<<endl;
        mp[num]=user;
        return 1;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */