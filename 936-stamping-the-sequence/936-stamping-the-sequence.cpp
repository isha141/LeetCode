class Solution { 
    private:
    bool solve(int i,string &stamp,string &target)
    { 
        int k=0; 
        int count=0;
        for(int j=i;j<i+stamp.size();++j){
            if(stamp[k++]!=target[j] &&  target[j]!='?')
                return 0;
        }
        return 1;
        
    }
    int replaceable(int i,string &target,int m)
    { 
        int count=0;
        for(int j=i;j<i+m;++j){
           if(target[j]!='?'){
               target[j]='?';
            count++;
           }
        }
        return count;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>ans;
        int m=stamp.size(); 
        int n=target.size(); 
        int count=0;   
        vector<int>vis(n+1,0);
        while(count!=n){
        bool flag=0; 
        for(int i=0;i<=n-stamp.size();++i){
          if(!vis[i] && solve(i,stamp,target)){
             count+=replaceable(i,target,m);
              flag=1;
             vis[i]=1; 
              ans.push_back(i);
                if(count==n)
                break;
          }
        } 
        if(!flag){
         return {};
        }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};