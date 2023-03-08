class Solution { 
    private:
    long long solve(long long mid,vector<int>&piles,int h){
        int n=piles.size();
        int c=0; 
        int rem=0;
        for(auto itr: piles){
            if(itr<=mid){
                c+=1;
            }
            else{
                c+=(itr/mid);
                if(itr%mid)
                c+=1;
            }
        }
        // c+=rem/mid;
        // rem%=mid;
        // if(rem)
        // c+=1;
        return c;
    }
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n=p.size();
        long long low=1;
        long long high=0;
        for(auto itr: p){
            high+=itr;
        } 
        long long ans=1e9;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(solve(mid,p,h)<=h){
                // cout<<mid<<"::"<<endl;
                ans=mid;
                high =mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};