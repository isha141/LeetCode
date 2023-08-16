class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int n=nums.size();
          vector<int>ans;
          vector<int>ds;  
          map<int,int>mp;
          priority_queue<int>pq;
          int maxi=0;
          for(int i=0;i<k;++i){
               pq.push(nums[i]);
              mp[nums[i]]++;
              maxi=max(maxi,nums[i]);
          }
          ans.push_back(maxi);
          for(int i=k;i<n;++i){
              pq.push(nums[i]);
              mp[nums[i-k]]--;
              mp[nums[i]]++;
              while(!pq.empty() && mp[pq.top()]==0)
                   pq.pop();
              ans.push_back(pq.top());
          }
        return ans;
    }
};