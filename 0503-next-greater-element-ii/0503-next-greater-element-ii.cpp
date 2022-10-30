class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            s.push(nums[i]);
        }
      vector<int>ans(n,-1); 
        for(int i=n-1;i>=0;--i){
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            if(!s.empty())
                ans[i]=s.top();
            s.push(nums[i]);
        }
        return ans;
    }
};