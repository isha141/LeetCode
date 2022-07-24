class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(); 
        map<int,int>mp;  
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;++i){
            sum=(nums[i]+sum)%k; 
            // if(sum==0) return 1;
            if(mp.find(sum)!=mp.end()){
                if(abs(i-mp[sum])>1)
                    
                 return 1;
            } 
            else
            mp[sum]=i;
        }
        return 0;
    }
};