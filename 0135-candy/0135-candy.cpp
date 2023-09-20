class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int>pre(n,0);
         vector<int>suff(n,0);
        pre[0]=1;
        for(int i=1;i<n;++i){
            if(rat[i]>rat[i-1]){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=1;
            }
        }
        suff[n-1]=1;
        for(int i=n-2;i>=0;--i){
            if(rat[i]>rat[i+1]){
                suff[i]=suff[i+1]+1;
            }
            else{
                suff[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i){
            ans+=max(pre[i],suff[i]);
        }
         return ans;
    }
};