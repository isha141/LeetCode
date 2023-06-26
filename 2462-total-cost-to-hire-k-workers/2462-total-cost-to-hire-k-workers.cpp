class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int can) {
        long long ans=0; 
         int n=cost.size();
         int i=0;
        int j=n-1;
        priority_queue<int,vector<int>,greater<int>>l,r;
         while(k--){ 
              int t=can;
             while(i<=j &&  l.size()!=can){
                 l.push(cost[i]);
                  i++;
                 t--;
             }
              t=can;
             while(j>=i && r.size()!=can){
                 r.push(cost[j]);
                  j--;
                 t--;
             }
             int a=l.size()>0?l.top():INT_MAX; 
             int b=r.size()>0?r.top(): INT_MAX;
             if(a<=b){
                  ans+=a;
                  l.pop();
             }
             else if(b<=a){
                     ans+=b;
                     r.pop();
             }
         }
        return ans;
    }
};