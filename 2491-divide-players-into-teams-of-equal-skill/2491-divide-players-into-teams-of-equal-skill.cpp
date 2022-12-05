class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
      int n=skill.size();
        long long sum=0;
        for(auto itr: skill)
            sum+=itr;
        int teams=n/2; 
        if(sum%teams)
            return -1;
        int total=sum/teams;
        long long ans=0;
        map<int,int>mp;
        for(auto itr: skill)
            mp[itr]++;
        sort(skill.begin(),skill.end());
        int c=0;
        for(auto itr: skill){
            if(c>=teams)
                return ans;
            if(mp.find(total-itr)!=mp.end()){
                mp[itr]--;
                mp[total-itr]--;
                ans+=(total-itr)*itr;
               if(mp[itr]<=0)
                   mp.erase(itr);
                if(mp[total-itr]<=0)
                    mp.erase(total-itr);
                c++;
            }
            else
                return -1;
        }
        return ans;
    }
};