int dp[505][505];
class Solution {
    private:
    int solve(int i,int j,vector<int>&ds,int x){
         if(i>=j)
              return 0;
         int take=INT_MAX;
         int not_take=INT_MAX;
         int res=INT_MAX;
         if(dp[i][j]!=-1)
              return dp[i][j];
         if(i+1<j)
         take=min(x,abs(ds[i+1]-ds[i]))+solve(i+2,j,ds,x);
         not_take=min(x,abs(ds[i]-ds[j]))+solve(i+1,j-1,ds,x);
         res=min(x,abs(ds[j]-ds[j-1]))+solve(i,j-2,ds,x);
         return dp[i][j]=min(take,min(res,not_take));
    }
public:
    int minOperations(string a, string b, int x) {
         int n=a.size();
         if(b.size()!=n) return -1;
         vector<int>ds; 
         for(int i=0;i<n;++i){
             if(a[i]!=b[i]){
                 ds.push_back(i);
             }
         } 
         memset(dp,-1,sizeof(dp));
         if(ds.size()%2) return -1;
         return solve(0,ds.size()-1,ds,x);
    }
};