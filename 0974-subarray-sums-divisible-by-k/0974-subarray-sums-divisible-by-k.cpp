class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        mp[0]++;
        int sum=0; 
        int ans=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            sum%=k;
            if(sum<0){
                if(mp.find((sum+k)%k)!=mp.end()){
                    ans+=mp[(sum+k)%k];
               }
                sum+=k;
                sum%=k;
                mp[sum]++;
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    ans+=mp[sum];
                }
                mp[sum]++;
            }
        }
        return ans;
    }
};