class Solution { 
    private:
    bool check(long long mid,vector<int>&b,int n)
    {
        long long total=mid*n;
        long long  count=0;
        for(auto &itr: b)
        {
           count+=min((long long)itr,mid); 
        }
        return total<=count;
    }
public:
    long long maxRunTime(int n, vector<int>& b) { 
       long long sum=0;
        for(auto itr : b)
            sum+=itr;
       long long low=0;
    long long  high=sum; 
 long long count=0;
        //cout<<high<<" ";
        while(low<=high)
        {
            long long  mid=(low+high)/2;
            if(check(mid,b,n))
            {
              count=mid;
                low=mid+1;
            } 
            else
            {
                high=mid-1;
            }
        }
        return count;
    }
};