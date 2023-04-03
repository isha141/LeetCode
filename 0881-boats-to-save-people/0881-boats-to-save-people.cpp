class Solution { 
    private:
    bool ok(int mid,vector<int>&p,int limit){
        int c=0;
        int sum=0; 
        int n=p.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            if(low!=high && p[low]+p[high]<=limit){
                low++;
                high--;
               c++; 
            } 
            else {
                high--;
                c+=1;
            }
        }
        return c<=mid;
    }
public:
    int numRescueBoats(vector<int>& p, int limit) {
        int n=p.size();
        int low=1;
        int high=n; 
        int ans=n; 
        sort(p.begin(),p.end());
        while(low<=high){
            int mid=(low+high)>>1;
            if(ok(mid,p,limit)){
                ans=mid;
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        return ans;
    }
};