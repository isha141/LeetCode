class Solution { 
    private:
    vector<vector<string>>ans;  
     set<string>s;
     map<string, int>mp; 
    string begin; 
    int n;
    void solve(string end,vector<string>&ds){
        if(end==begin){ 
            reverse(ds.begin(),ds.end());
            ans.push_back(ds); 
            reverse(ds.begin(),ds.end());
            return ;
        } 
         for(auto it: mp){
                   string w=it.first;
                   int c=0;
                 for(int i=0;i<n;++i){
                     if(w[i]!=end[i]) c++;
                 }
                 if(c==1 && mp[w]==mp[end]-1){
                      ds.push_back(w);
                      solve(w,ds);
                     ds.pop_back();
              }
      }
    }
public:
    vector<vector<string>> findLadders(string begin, string end, vector<string>& word) { 
          this->begin=begin;
          queue<string>q;
          q.push(begin);
          mp[begin]=0;
        int level=0;  
        n=begin.size(); 
        for(auto itr: word)
              s.insert(itr);  
         while(!q.empty()){ 
             auto itr=q.front();
             q.pop(); 
             s.erase(itr);
             for(auto it: word){
                   string w=it;
                   int c=0;
                 for(int i=0;i<n;++i){
                     if(w[i]!=itr[i]) c++;
                 }
                 if(c==1 && s.find(w)!=s.end()){
                     q.push(w); 
                     mp[w]=mp[itr]+1;
                     s.erase(w);
                 }
             } 
         }  
        // for(auto itr: mp)
            // cout<<itr.first<<" "<<itr.second<<endl;
        level=mp[end];
        vector<string>ds;
        ds.push_back(end);
         solve(end,ds);
        return ans;
        
    }
};