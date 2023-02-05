class Solution {
public:
    long long minCost(vector<int>& bas1, vector<int>& bas2) {
        map<int,int>mp;
        for(auto itr: bas1){
            mp[itr]++;
        }
        for(auto itr: bas2)
            mp[itr]++; 
        int  mini=INT_MAX;
        for(auto itr: mp){
            mini=min(mini,itr.first);
            if(itr.second%2)
                 return -1;
        }
        map<int,int>mp1,mp2;
        vector<int>ds1,ds2;
        for(auto itr: bas1) mp1[itr]++;
        for(auto itr: bas2) mp2[itr]++;
        for(auto itr: mp1){ 
            int val=itr.first;
                 if(mp2.find(val)!=mp.end()){ 
                    int temp=min(mp1[val],mp2[val]);
                    mp1[val]-=temp;
                    mp2[val]-=temp; 
            }
        }
        for(auto itr: mp1){
            int val=itr.first; 
            int temp=(itr.second)/2;
            for(int i=0;i<temp;++i)
                ds1.push_back(val);
        }
        for(auto itr: mp2){
            int val=itr.first; 
            int temp=(itr.second)/2;
            for(int i=0;i<temp;++i)
                ds2.push_back(val);
        }  
        sort(ds1.begin(),ds1.end());
        sort(ds2.rbegin(),ds2.rend());
        long long ans=0;
        for(int i=0;i<ds1.size();++i){
            if(ds1[i]>mini && ds2[i]>mini){
                ans+=min(2*mini,min(ds1[i],ds2[i]));
            }
            else{
                ans+=mini;
            }
        }
        return ans;
        
    }
};