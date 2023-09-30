int dp[102][102][102];
class Solution {
    private:
    int solve(int l,int r,vector<int>&boxes,int k){
        int ans=0;
        if(l>r) return 0;
        if(dp[l][r][k]!=-1)
              return dp[l][r][k];
        int i=l;
        int j=k;
        while(l+1<=r && boxes[l]==boxes[l+1]){
            l+=1;
            k+=1;
        }
        ans=((k+1)*(k+1))+solve(l+1,r,boxes,0);
        int temp=0;
        for(int i=l+1;i<=r;++i){
            if(boxes[i]==boxes[l]){
                temp=max(temp,solve(l+1,i-1,boxes,0)+solve(i,r,boxes,k+1));
            }
        }
        return dp[i][r][j]=max(temp,ans);
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,boxes,0);
    }
};