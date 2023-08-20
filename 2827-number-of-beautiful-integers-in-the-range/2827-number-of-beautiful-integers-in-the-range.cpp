int dp[20][2][2][20][20][50];
class Solution { 
    private: 
    int k;
    void getdigits(int low,vector<int>&ds){
          while(low){
              ds.push_back(low%10);
               low/=10;
          }
         return ;
    }
    long long solve(int ind,bool tight,bool zero,int even,int odd,int num,vector<int>&ds){
        if(ind>=ds.size()){
              if(even==odd && num==0){ 
                    return 1;
              }
            return 0;
        }
         if(dp[ind][tight][zero][even][odd][num]!=-1)
               return dp[ind][tight][zero][even][odd][num];
        int last=(tight)?ds[ind]:9;
        long long ans=0;
        for(int d=0;d<=last;++d){
             int neweven=even;
            int newodd=odd; 
            int newtight=(d==ds[ind])?tight:0;
            if(d==0 && zero){
                ans+=solve(ind+1,0,zero,0,0,0,ds);
            }
            else{
              if(d%2)
                    newodd+=1;
                else
                     neweven+=1;
                ans+=solve(ind+1,newtight,0,neweven,newodd,(num*10+d)%k,ds);
            }
        }
        return  dp[ind][tight][zero][even][odd][num]=ans;
    }
public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        vector<int>ds;  
        low--; 
        this->k=k; 
        memset(dp,-1,sizeof(dp));
         getdigits(low,ds);
           reverse(ds.begin(),ds.end());
         long long ans1=solve(0,1,1,0,0,0,ds);
         ds.clear();
          getdigits(high,ds);
        memset(dp,-1,sizeof(dp));
          reverse(ds.begin(),ds.end());
         long long ans2=solve(0,1,1,0,0,0,ds);
        // cout<<ans1<<";;"<<ans2<<endl;
          return ans2-ans1;
    }
};