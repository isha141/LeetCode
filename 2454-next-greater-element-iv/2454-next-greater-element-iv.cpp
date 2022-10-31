class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>s,s2; 
        vector<int>nextgreater(n,n);
        for(int i=0;i<n;++i){
            while(!s.empty() && nums[s.top()]<nums[i]){
               nextgreater[s.top()]=i;
                s.pop();
            }
            s.push(i);
        } 
        for(int i=0;i<n;++i){
            int l=nextgreater[i]+1; 
            // cout<<l<<" "<<i<<endl;
            while(l<n && nums[i]>=nums[l])
                l=nextgreater[l];
            if(l<n)
                ans[i]=nums[l];
        }
        return ans;
        
    }
};