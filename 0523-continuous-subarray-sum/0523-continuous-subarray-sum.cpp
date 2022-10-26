class Solution { 
    private: 
    int n;
    bool flag=0;
    int solve(int i,vector<int>&nums,int k,int sum){
         map<int,int>mp;
        sum=0; 
        mp[0]=-1;
        for(int i=0;i<n;++i){
            sum+=nums[i]; 
            sum%=k;
            if(mp.find(sum)!=mp.end()){
                if(abs(i-mp[sum])>1)
                return 1;
            }
            else
                mp[sum]=i;
        }
        return 0;
    }
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        n=nums.size();
        int sum=0; 
        return solve(0,nums,k,sum);
    }
};