class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {           vector<vector<int>>ans;
        
         int n=s.size();
         map<long long,pair<int,int>>mp;                                               
                                                                              
         for(int i=0;i<n;++i){
          long long num=0;
           if(s[i]=='0'){
               if(mp.find(0)==mp.end()){
                   mp[0]=make_pair(i,i);
               }
               continue;
           }
           for(int j=i;j<=min(i+32,n-1);++j){
                num=(num << 1)+(s[j]-'0'); 
                if(mp.find(num)==mp.end()){
                   mp[num]=make_pair(i,j);
               }
           }
          
        } 
         for(auto itr: q){
             long long temp=itr[0]^itr[1];
             if(mp.find(temp)==mp.end())
                 ans.push_back({-1,-1});
             else
                 ans.push_back({mp[temp].first,mp[temp].second});
         }                                                                      
                                                                               
            return ans;                                                  
        
    }
};