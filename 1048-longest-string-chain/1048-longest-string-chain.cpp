bool cmp(string &a,string &b){
    if(a.size()==b.size())
          return a<b;
    return a.size()<b.size();
}
class Solution { 
    private:
    int n; 
    bool ok(string &a,string &b){
        int i=0;
        int j=0;
        int m=a.size();
        int t=b.size();
        if((t-m)!=1)
              return 0;
        while(i<m){
               bool flag=0;
              while(j<t && b[j]!=a[i]){
                  j++;
              }
            if(j<t && b[j]==a[i]){
                i++; 
                j++;
            }
            else
                return 0;
        }
        if(i>=m)return 1;
         return 0;
    }
    int solve(int i,vector<string>&words,string temp,map<string,int>&mp){
        if(i>=n)
              return 0;
        if(mp.find(temp)!=mp.end())
              return mp[temp];
       int ans=0; 
        for(int j=i;j<n;++j){
            if((temp.size()==0) || ok(temp,words[j])){
                 // cout<<j<<"->"<<temp<<"-->"<<words[j]<<endl;
                ans=max(ans,1+solve(j+1,words,words[j],mp));
            }
        }
        // cout<<i<<"-->"<<ans<<"-->"<<temp<<endl;
        return mp[temp]=ans;
    }
public:
    int longestStrChain(vector<string>& words) {
           n=words.size(); 
           map<string,int>mp;
          sort(words.begin(),words.end(),cmp); 
          return solve(0,words,"",mp);
    }
};