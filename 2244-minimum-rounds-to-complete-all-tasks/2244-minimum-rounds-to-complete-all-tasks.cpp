class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        int ans=0;
        map<int,int>mp;
        for(auto itr: tasks)
            mp[itr]++;
        for(auto itr: mp){ 
            if(itr.second==1) return -1;
            ans+=(itr.second+2)/3;
        }
        return ans;
    }
};
