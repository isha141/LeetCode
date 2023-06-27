class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
         vector<vector<int>>ans;
          int n=n1.size();
          int m=n2.size(); 
          // cout<<n<<"....."<<m<<endl;       
         priority_queue<pair<long long ,pair<int,int>>,vector<pair<long long ,pair<int,int>>>,greater<pair<long long ,pair<int,int>>>>pq;
          for(int i=0;i<n;++i){
              pq.push({n2[0]+n1[i],{i,0}});
          } 
           while(k-- && pq.size()){
               auto itr=pq.top();
               pq.pop();
               int first=itr.second.first;
               int second=itr.second.second;
               ans.push_back({n1[first],n2[second]}); 
               // cout<<first<<";;;"<<second<<endl;
               if((second+1)<m){ 
                   // cout<<first<<";**;"<<second<<endl;
               pq.push({n1[first]+n2[second+1],{first,second+1}}); 
               } 
           }
        return ans;
    }
};