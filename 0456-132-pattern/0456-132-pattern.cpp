class Solution {
public:
    bool find132pattern(vector<int>& nums) {
          int n=nums.size();
          vector<int>mini(n,INT_MAX);
          mini[0]=nums[0];
          for(int i=1;i<n;++i){
              mini[i]=min(mini[i-1],nums[i]);
          }
          stack<int>s;
         for(int i=n-1;i>=0;--i){
             while(!s.empty() && s.top()<=mini[i])
                 s.pop();
             if(!s.empty() && s.top()<nums[i])
                   return 1;
             s.push(nums[i]);
         }
         return 0;
    }
};