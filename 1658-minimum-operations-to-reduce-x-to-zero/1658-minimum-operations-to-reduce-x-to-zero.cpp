class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0; 
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mp[sum]=i;
        }  
        if(sum<x) return -1;
        int size=0;
        int val=0; 
        sum-=x; 
        //map[0]=0;
        for(int i=0;i<n;i++){
            val+=nums[i]; 
            if(val-sum==0)
                size=max(size,i+1);
            if(mp.count(val-sum)){
            size=max(size,abs(mp[val-sum]-i));
           }
        } 
        if(sum==0) return n;
        else if(size==0) return -1;
        return n-size;
    }
};