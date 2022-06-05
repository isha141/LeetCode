class Solution {
    private:
    int ans=0;
    void count(int col,vector<string>&ds,int n,vector<int>&left,vector<int>&lower,vector<int>&upper)
    {
        if(col==n){
            ans++;
           return ;
         } 
        for(int i=0;i<n;i++)
        {
            if(ds[i][col]=='.' && !left[i] && lower[i+col] ==0 && upper[n-1+col-i]==0)
            {
                
                    ds[i][col]='Q';
                left[i]=1;
                lower[i+col] =1;
                upper[n-1+col-i]=1;
                count(col+1,ds,n,left,lower,upper);
                    ds[i][col]='.';
                left[i]=0;
                lower[i+col] =0;
                upper[n-1+col-i]=0;
            }
        }
        return ;
    }
public:
    int totalNQueens(int n) {
        string s(n,'.');
        vector<string>ds(n);
        vector<int>left(n,0);
        vector<int>lower(2*n-1,0);
        vector<int>upper(2*n-1,0);
        for(int i=0;i<n;i++)
        {
            ds[i]=s;
        }
       count(0,ds,n,left,lower,upper);
        return ans;
    }
};