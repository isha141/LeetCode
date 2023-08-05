class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;++i){
         mp[nums[i]].push_back(i);   
        }  
        if(mp.size()==1){
             return 0;
        }
        int ans=1e9;
        for(auto it: mp){
            vector<int>ds=it.second;
             int maxi=1;
            int m=ds.size();
            if(m==1){ 
                ans=min(ans,n-1);
                continue;
            }
            maxi=ds[0]+(n-ds[ds.size()-1]-1);
            for(int i=1;i<ds.size();++i){
                 // if(ds[i]-ds[i-1]!=1){
                     maxi=max(maxi,ds[i]-ds[i-1]-1);
                 // }
                // else{
                    // maxi=min(maxi,n-2);
                // }
            }
            ans=min(ans,maxi);
        }
        // cout<<ans<<";;"<<endl;
        return (ans+1)/2;
    }
};