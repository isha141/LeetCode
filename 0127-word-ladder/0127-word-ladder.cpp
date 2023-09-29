class Solution {
    private:
    bool ok(string &a,string &b){
        int c=0;
        int n=a.size();
        for(int i=0;i<n;++i){
            if(a[i]!=b[i])
                  c+=1;
        }
        return (c==1);
    }
public:
    int ladderLength(string begin, string end, vector<string>& word) {
          set<string>s;
          for(auto it: word){
              s.insert(it);
          }
          if(s.find(end)==s.end())
                return 0;
          queue<string>q;
          q.push(begin);
          int ans=1;
          while(!q.empty()){
              int t=q.size();
              while(t--){
                  auto itr=q.front();
                  q.pop();
                  for(auto i=0;i<itr.size();++i){
                      string temp=itr;
                      for(char ch='a';ch<='z';++ch){
                          temp[i]=ch;
                          if(s.find(temp)==s.end())
                              continue;
                          if(temp==end){
                               return ans+1;
                          }
                          if(s.find(temp)!=s.end()){
                              s.erase(temp);
                              q.push(temp);
                          }
                      }
                  }
              }
              ans+=1;
          }
        return 0;
    }
};