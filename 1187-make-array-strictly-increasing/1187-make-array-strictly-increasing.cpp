int dp[2003][2003];
class Solution {
    private:
    int n;
    int m;
    int solve(int i,int j,int maxi,vector<int>&arr1,vector<int>&arr2){
        if(i>=n)
              return 0;  
        // if(j>=m) return n+1;
        int take=n+1;
        int not_take=n+1;
         j=upper_bound(arr2.begin()+j,arr2.end(),maxi)-arr2.begin();
        if(dp[i][j]!=-1)
             return dp[i][j];
        if(j!=m){
            take=1+solve(i+1,j+1,arr2[j],arr1,arr2);
        }
        if(maxi<arr1[i]){
            not_take=solve(i+1,j,arr1[i],arr1,arr2);
        }
        return dp[i][j]=min(take,not_take);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
         sort(arr2.begin(),arr2.end()); 
         n=arr1.size();
         m=arr2.size(); 
         memset(dp,-1,sizeof(dp));
        int ans= solve(0,0,-1,arr1,arr2); 
        if(ans>n)
             return -1;
        return ans;
    } 
};