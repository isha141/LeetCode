class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int mod=1e9+7;
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        stack<pair<int,int>>s;
        for(int i=0;i<n;++i){
            int count=0;
            while(!s.empty() && s.top().first>arr[i]){
                count+=s.top().second;
                s.pop();
            }
            pre[i]=count+1;
            s.push({arr[i],count+1});
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;--i){
             int count=0;
            while(!s.empty() && s.top().first>=arr[i]){
                count+=s.top().second;
                s.pop();
            }
            suff[i]=count+1;
            s.push({arr[i],count+1});
        }
        // for(int i=0;i<n;++i){
            // cout<<pre[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;++i){
            // cout<<suff[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;++i){
            int temp=(1ll*pre[i]*suff[i])%mod;
            temp=(1ll*temp*arr[i])%mod;
            ans=(ans%mod+ temp%mod)%mod;
        }
        return ans;
    }
};