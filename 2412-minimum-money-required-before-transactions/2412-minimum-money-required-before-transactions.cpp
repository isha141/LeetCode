// bool cmp(vector<int>&a,vector<int>&b)
//     {
//         // a-->b
//         long long t1=min(-a[0],-a[0]+a[1]-b[0]);
//         long long t2=min(-b[0],-b[0]+b[1]-a[0]); 
//         if(t1!=t2)
//            return t1<t2;
//         else
//         return a[0]<b[0];
//     };
class Solution { 
    private: 
    bool ispossible(vector<vector<int>>&t,long long mid)
    {
        for(auto &itr: t){
            if(itr[0]<=mid){
                mid-=itr[0];
                mid+=itr[1];
            }
            else
                return 0;
        }
        return 1;
    }
    
public:
    long long minimumMoney(vector<vector<int>>& trans) {
        int n=trans.size();
        sort(trans.begin(),trans.end(),[&](vector<int>&a,vector<int>&b){
            long long t1=min(-a[0],-a[0]+a[1]-b[0]);
            long long t2=min(-b[0],-b[0]+b[1]-a[0]);
            if(t1==t2)
                return a[0]<b[0];
            return t1<t2;
        });  
        long long low=0;
        long long high=LONG_MAX;   
        long long ans=0;
        while(low<=high){ 
            long long mid=low+(high-low)/2;
            if(ispossible(trans,mid))
            { 
                // cout<<mid<<" ";
                ans=mid; 
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};