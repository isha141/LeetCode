class Solution {  
    private: 
    int f(string s)
    {
        int ans=0;
        for(int i=0;i<s.size();++i){
            ans=ans*10+s[i]-'0';
        }
        return ans;
    }
    private:
    void solve(int i,int n,string &ds,int k,vector<int>&ans)
    { 
        if(n<0)
            return ;
        if(n==0){
           for(int i=0;i<ds.size()-1;++i){
               int a=ds[i]-'0';
               int b=ds[i+1]-'0'; 
               if(abs(a-b)!=k)
                   return ;
           } 
            int temp=f(ds);
            ans.push_back(temp);
        }
        for(int l=0;l<=9;++l){ 
            int temp=ds[ds.size()-1]-'0';
            int cur=l;
            if(abs(temp-cur)==k){
            ds+=to_string(l);
            solve(l,n-1,ds,k,ans);
            ds.pop_back();
            }
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
         vector<int>ans;
        string ds="";
        for(int i=1;i<=9;++i){ 
            ds=to_string(i);
            solve(i,n-1,ds,k,ans); 
            ds.pop_back();
        }
        return ans;
    }
};