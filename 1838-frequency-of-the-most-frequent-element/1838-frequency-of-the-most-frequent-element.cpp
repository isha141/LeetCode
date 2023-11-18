class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        map<int,int>mp;
        for(auto itr: nums){
            mp[itr]++;
        }
        vector<pair<int,int>>ds;
        for(auto itr: mp){
            ds.push_back({itr.first,itr.second});
        }
        // cout<<ds[55].first<<" --&&&"<<ds[56].first<<" ";
        long long ans=0;
        for(int i=0;i<ds.size();++i){
            // cout<<i<<"-->"<<endl;
            long  long count=ds[i].second;
            long long  temp=k;
            int j=i-1;
            bool flag=0;
            // cout<<i<<"-->"<<endl;
            while(j>=0){
                int diff=ds[i].first-ds[j].first;
                long long tot=1ll*diff*ds[j].second;
                // cout<<j<<"-->"<<diff<<"--"<<tot<<endl;
                if(temp>=tot){
                    temp-=tot;
                    count+=ds[j].second;
                }
                else{
                    long c=temp/diff;
                    count+=c;
                    flag=1;
                    // break;
                }
                if(flag)
                    break;
                j--;
            }
            // cout<<"*********"<<endl;
            // cout<<ans<<"-->"<<count<<endl;
            ans=max(ans,count);
        }
        return ans;
    }
};