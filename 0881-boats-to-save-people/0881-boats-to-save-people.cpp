class Solution { 
    private: 
    int n;
    bool ok(int mid,vector<int>&p,int limit){
        int c=0;
        int w=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            if(p[i]+p[j]<=limit){
                i++;
                j--;
                c++;
                continue;
            }
            else{
                c+=1;
                j--;
            }
        }
        return c<=mid;
    }
public:
    int numRescueBoats(vector<int>& p, int limit) { 
        n=p.size();
        sort(p.begin(),p.end());
        int low=1;
        int high=n;
        int ans=0;
        // for(auto itr: p) high+=itr;
        while(low<=high){
            int mid=(low+high)>>1;
            if(ok(mid,p,limit)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};