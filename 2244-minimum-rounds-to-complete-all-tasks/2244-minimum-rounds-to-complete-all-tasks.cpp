class Solution {
public:
    int minimumRounds(vector<int>& t) {
        int n=t.size();
        map<int,int>mp;
        for(auto itr: t)
            mp[itr]++;
        int c=0;
        for(auto itr: mp){
            int val=itr.second;
                if(val==1) return -1;
                val+=2;
               c+=val/3;
        }
        return c;
    }
};