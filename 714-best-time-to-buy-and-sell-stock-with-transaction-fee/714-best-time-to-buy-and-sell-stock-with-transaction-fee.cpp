class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int>prev(2,0);
        vector<int>curr(2,0); 
        int n=prices.size();
        for(int i=n-1;i>=0;--i){
            for(int buy=0;buy<=1;++buy){
                if(buy)
                curr[buy]=max(-(prices[i]+fee)+prev[0],curr[1]);
                else
                curr[buy]=max(prices[i]+prev[1],curr[0]);
            }
            prev=curr;
        }
        return prev[1];
    }
};