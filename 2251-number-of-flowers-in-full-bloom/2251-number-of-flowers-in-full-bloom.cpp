class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
          int n=flowers.size();
          int m=people.size();
          vector<int>ans;
          vector<int>p=people;
          sort(flowers.begin(),flowers.end());
          sort(people.begin(),people.end());     
          map<int,int>mp;
          priority_queue<int,vector<int>,greater<int>>pq;
          int j=0;
          for(int i=0;i<m;i++){
               while(j<n && flowers[j][0]<=people[i]){
                   pq.push(flowers[j][1]);
                   j++;
               }
              while(!pq.empty() && pq.top()<people[i]){
                  pq.pop();
              }
              mp[people[i]]=pq.size();
          }
          for(auto i=0;i<m;++i){
              ans.push_back(mp[p[i]]);
          }
         return ans;
    }
};