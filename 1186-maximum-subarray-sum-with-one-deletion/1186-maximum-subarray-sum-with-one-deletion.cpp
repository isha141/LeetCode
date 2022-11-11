class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>f(n,0),b(n,0);
        f[0]=arr[0]; 
        int ans=arr[0];
        for(int i=1;i<n;++i){
            f[i]=max(arr[i],f[i-1]+arr[i]);
            ans=max(ans,f[i]);
        }  
        // for(int i=0;i<n;++i)
        //     cout<<f[i]<<" ";
        b[n-1]=arr[n-1];
        for(int i=n-2;i>=0;--i){
            b[i]=max(arr[i],arr[i]+b[i+1]); 
            ans=max(ans,b[i]);
        } 
        // cout<<"****"<<endl;
        // for(int i=0;i<n;++i){
        //     cout<<b[i]<<" ";
        // }
        // int ans=arr[0];
        for(int i=0;i<n-2;++i){
            ans=max(ans,f[i]+b[i+2]);
            ans=max(ans,f[i]);
        } 
        ans=max(ans,f[n-1]);
        // ans=max(ans,f[n-2]);
        return ans;
    }
};