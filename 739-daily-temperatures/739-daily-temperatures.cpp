class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) { 
        int n=t.size();
        vector<int>ans(n,0);
        int count=0;
        stack<int>s;
        for(int i=0;i<n;++i){
            while(!s.empty() && t[s.top()]<t[i]){
                int x=s.top();
                s.pop();
                ans[x]=i-x;
            }
            s.push(i);
        }
        return ans;
    }
};