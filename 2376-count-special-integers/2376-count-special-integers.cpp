class Solution {  
    private:
    void digits(int n,vector<int>&ds){ 
        while(n){
            ds.push_back(n%10);
            n/=10;
        }
    }
    int solve(int ind,bool tight,bool zero,vector<int>&ds,bool vis,int mask,int num){
        if(ind>=ds.size()){
             if(vis ){ 
                   if(mask!=0)
                   return 1; 
                 
             }
            return 0;
        }
         int limit=(tight)?ds[ind]:9;
         long long ans=0;
         for(int d=0;d<=limit;++d){
             int newtight=(ds[ind]==d)?(tight):0;
              if(mask==0 && d==0){
                  ans+=solve(ind+1,newtight,1,ds,vis,0,0);
              }
              else if(mask&(1<<d)){
                  continue;
              }
             else{
                 ans+=solve(ind+1,newtight,0,ds,1,(mask|(1<<d)),num*10+d);
             }
         }
        return ans;
    }
public:
    int countSpecialNumbers(int n) { 
          vector<int>ds;
          digits(n,ds);  
          reverse(ds.begin(),ds.end());
         return  solve(0,1,1,ds,0,0,0);
    }
};