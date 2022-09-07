class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       int n=nums.size();
        set<int>s;
        for(auto itr: nums){
            s.insert(itr);
        } 
        long long ans=0;
        long long start=1;
        for(auto itr: s){
            long long l=start;
            long long r=itr;
            if((r-l)>=k){
                break;
            } 
            k-=(r-l);
           long long temp=(r*(r-1))/2-(l*(l-1)/2);
            ans+=temp;
            start=r+1;
        }
        long long l=start;
        long long r=start+k;
        ans+=(r*(r-1))/2 -(l*(l-1))/2;
        return ans;
    }
};