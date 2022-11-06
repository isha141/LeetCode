class Solution { 
    private:
    int solve(long long mid,vector<int>&can, long long k){
        long long c=0;
        for(auto itr: can){
            c+=itr/mid;
        if(c>=k)
            return 1;
        }
        return 0;
    }
public:
    int maximumCandies(vector<int>& can, long long k) {
        int n=can.size();
        long long low=1; 
        long long ans=0; 
        sort(can.begin(),can.end());
          long long high=can[n-1];  
        while(low<=high){
            long long mid=(low+high)>>1;
            if(solve(mid,can,k)){
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};