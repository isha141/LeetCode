class Solution {
public:
    int maxProfit(vector<int>& p) {
         int n=p.size();
        int ans=0;
        int buy=INT_MAX;
        for(int i=0;i<n;++i){
            if(buy>p[i]){
                buy=p[i];
            }
            else{
                ans=max(ans,p[i]-buy);
            }
        }
        return ans;
    }
};