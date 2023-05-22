class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans=0;
        for(int i=n/2-1;i>=0;--i){
            int temp=cost[2*i+1];
            int temp2=cost[2*i+2];
            ans+=abs(temp-temp2);
            cost[i]+=max(temp,temp2);
        }
        return ans;
    }
};