class Solution { 
    private:
    int n;
    int ans=INT_MAX; 
    int k;
     void solve(int i,vector<int>&c,vector<int>&ds){
         if(i>=n){
             int res=INT_MIN;
             for(auto itr: ds){
                 res=max(res,itr);
             }
             ans=min(ans,res);
             return;
         }
          for(int j=0;j<k;++j){
               ds[j]+=c[i];
              solve(i+1,c,ds);
               ds[j]-=c[i];
          }
         return ;
     }
public:
    int distributeCookies(vector<int>& c, int k) { 
           n=c.size(); 
          this->k=k;
           vector<int>ds(k,0); 
          solve(0,c,ds);
          return ans;
    } 
};