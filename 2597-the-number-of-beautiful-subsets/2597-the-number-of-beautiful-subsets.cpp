class Solution { 
    private:
    int n;  
    unordered_map<int,int>mp;
    int solve(int i,vector<int>&nums,int &k){ 
          int l=0; 
        int r=0;
        if(i>=n) return 1; 
        else{
        if(mp[nums[i]-k]==0){ 
            mp[nums[i]]++;
         l=solve(i+1,nums,k);
         mp[nums[i]]--;
        }
         r=solve(i+1,nums,k);  
        }
        return l+r;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        n=nums.size();  
        vector<int>ds; 
        sort(nums.begin(),nums.end());
        return solve(0,nums,k)-1;
    }
};