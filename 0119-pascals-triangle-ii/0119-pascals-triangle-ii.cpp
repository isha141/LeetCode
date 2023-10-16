class Solution {
public:
    vector<int> getRow(int r) {
        vector<int>ans(r+1,0);
        ans[0]=1;
        int up=r;
        int low=1;
        long long  temp=1;
        for(int i=1;i<=r;++i,up--,low+=1){
            temp=(1ll*temp*up)/low;
            ans[i]=temp;
        }
         return ans;
    }
};