class Solution { 
    private:
    int solve(int mid,vector<int>&dist,double hour){
        double c=0;
        for(int i=0;i<dist.size();++i){ 
            c=ceil(c);
            // cout<<c<<" ";
            double temp=(double)dist[i]/mid;
            c+=temp; 
            if(c>hour)
                return 0;
        }
        return 1;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int low=1; 
        // if(hour<n-1)
        //     return -1;
        int ans=1e9+7;
        int high=1000000000;
        while(low<=high){ 
            int mid=(low+high)>>1;
            if(solve(mid,dist,hour)){
                ans=mid;
              high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans>=1e9+7?-1:ans;
    }
};
// 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 0 1 2 