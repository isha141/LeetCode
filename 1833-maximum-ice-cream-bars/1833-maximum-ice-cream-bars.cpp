class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int ans=0;
        sort(costs.begin(),costs.end());
        int k=0;
        while(coins && k<n){
             if(costs[k]<=coins){
                 ans++;
                 coins-=costs[k++];
             }
            else break;
        }
        return ans;
    }
};