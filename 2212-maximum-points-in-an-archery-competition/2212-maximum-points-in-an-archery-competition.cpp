class Solution {  
    private: 
    int maxi=0; 
    vector<int>ds;
    void solve(int i,vector<int>&alice,int arr,int sum,vector<int>&ans){
        if(i>=12){  
            // if(arr>0)
                // ans[0]+=arr;
          if(maxi<=sum){
              ds=ans; 
              if(arr>0)
                  ds[0]+=arr;
              maxi=sum;
          }
            return ;
        } 
        if(arr>alice[i]){
            ans[i]=alice[i]+1;
            sum+=i;
            arr-=alice[i]+1;
            solve(i+1,alice,arr,sum,ans);
            arr+=alice[i]+1;
            sum-=i;
            ans[i]=0;
        }
        solve(i+1,alice,arr,sum,ans);
        return ;
    }
public:
    vector<int> maximumBobPoints(int arr, vector<int>& alice) {
          vector<int>ans(12,0);
        ds.resize(12,0);
          int sum=0;
           solve(0,alice,arr,sum,ans);
        return ds;
    }
};