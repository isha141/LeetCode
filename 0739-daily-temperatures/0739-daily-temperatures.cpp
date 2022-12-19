class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
         stack<int>s;
        vector<int>ans(n,0);
        for(int i=0;i<n;++i){
          while(!s.empty() && temp[s.top()]<temp[i]){
            int x=s.top();
            s.pop();
            ans[x]=i-x;
           }
            s.push(i);
         }
        return  ans;
    }
};