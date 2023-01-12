class Solution { 
    private:
    long long mod=1e9+7;
    long reverse1(long temp){
        string s=to_string(temp); 
        // cout<<s<<",,";
        reverse(s.begin(),s.end());
        return stol(s);
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        map<int,int>mp;
        for(int i=0;i<n;++i){
        long temp=nums[i]-reverse1(nums[i]);
            if(mp.find(temp)!=mp.end())
                ans+=mp[temp];
            ans%=mod;
            mp[temp]++;
        }
        return ans;
    }
};