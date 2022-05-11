class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0; 
        int sum=0;
        int rem=0;  
        map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i]; 
           int temp=sum%k;
            if(temp<0){
            if(mp.count(temp+k))
                count+=mp[temp+k];
                mp[temp+k]++;
            }
            else  
            {
                if(mp.count(temp)){
                count+=mp[temp]; 
                }
                mp[temp]++;
            }
        }
        return count;
    }
};