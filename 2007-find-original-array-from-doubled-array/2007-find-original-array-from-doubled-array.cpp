class Solution {
public:
    vector<int> findOriginalArray(vector<int>& ch) {
        map<int,int>mp;
        vector<int>ans;  
        if(ch.size()==1) return {};
        sort(ch.begin(),ch.end());
        for(auto it: ch){
           mp[it]++;
        }
        for(auto it: ch){ 
            if(mp[it]==0) continue;
            if(mp[it*2]==0) return {};
            if(it!=0 && mp.find(it*2)!=mp.end()){
                ans.push_back(it);
                mp[it*2]--;
            } 
            if(it==0){ 
                if(mp[0]>=2){
                 mp[0]--;
                ans.push_back(it);
                }else
                    return {};
            } 
           mp[it]--;
        }
       return ans;
    }
};