class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      int n=nums.size();
        stack<int>s;
        s.push(0);
        int i=1;
        int ind1=n;
        int ind2=0;
        while(i<n){
            if(nums[s.top()]>nums[i]){
                while(!s.empty() && nums[s.top()]>nums[i]){
                    ind1=min(ind1,s.top());
                    s.pop();
                }
                ind2=max(ind2,i);
            }
            s.push(i);
            i++;
        }
        if(ind1==n) 
            return 0; 
       while(!s.empty()) s.pop();
         i=n-1;
        while(i>=0){
            while(!s.empty() && nums[s.top()]<nums[i]){
                ind2=max(ind2,s.top());
                s.pop();
            }
            s.push(i);
            i--;
        }
        return ind2-ind1+1;
    }
};