class Solution { 
    private:
    int solve(long long mid,vector<int>& time, int total){
          long long c=0; 
          for(auto itr: time){
              c+=mid/itr;
              if(c>=total)
                  return 1;
          }
        return c>=total;
    }
public:
    long long minimumTime(vector<int>& time, int total) {
        long long low=0;
        long long high=100000000008;
      long long ans=0; 
        if(time.size()==1)
            return (long long )time[0]*total;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(solve(mid,time,total)){
                  ans=mid;
                 high=mid-1; 
                // cout<<mid<<" ";
            }
            else{
                low=mid+1;
            } 
        }
        return ans;
    }
};