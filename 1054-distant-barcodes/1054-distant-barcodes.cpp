class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        int n=b.size();
        vector<int> ans(n,0);
        map<int,int>mp;
        for(auto itr: b)
            mp[itr]++;
        priority_queue<pair<int,int>>pq;
        for(auto itr: mp){
            pq.push({itr.second,itr.first});
        }
        int val=pq.top().first;
        int a=pq.top().second;
        pq.pop(); 
        int i=0;
        while(!pq.empty() || val){  
              if(ans[i]==0){ 
                  while(val>0 && ans[i]==0){
                  ans[i]=a;
                  i=(i+2)%n;
                  val--;
                  }
              if(val==0){ 
                  if(pq.size()){
                  a=pq.top().second;
                  val=pq.top().first;  
                      pq.pop();
                  } 
                  else
                      break;
              } 
              }
              else{
                  i=(i+1)%n;
              }
        }
        return ans;
        
    }
};