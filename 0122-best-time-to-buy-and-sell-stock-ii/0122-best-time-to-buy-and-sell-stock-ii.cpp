class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0;
        int n=p.size();
        for(int i=1;i<n;++i){
            if(p[i-1]<p[i]){
                ans+=p[i]-p[i-1];
                // i++;
            }
        }
        return ans;
    }
};