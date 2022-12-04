class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long >pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;++i){
           pre[i]=pre[i-1]+nums[i]; 
        }
        int ans=(int)1e9;
        int mini=n-1;
        for(int i=0;i<n-1;++i){
            int diff=abs(pre[i]/(i+1)-abs(pre[n-1]-pre[i])/(n-i-1));
            if(diff<ans){
                ans=diff;
                mini=i;
            }
        }
        if(ans>(pre[n-1])/(n)){
          ans=pre[n-1];
          mini=n-1;
         }
        return mini;
    }
};