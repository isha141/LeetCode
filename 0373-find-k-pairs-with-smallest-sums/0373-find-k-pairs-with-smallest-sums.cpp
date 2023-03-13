class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& n1, vector<int>& n2, int k) {
         vector<vector<int>> ans; 
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n2.size();++i){
            pq.push({n1[0]+n2[i],{0,i}});
        }
        while(!pq.empty() && ans.size()!=k){
             auto itr=pq.top();
              pq.pop();
             int i=itr.second.first;
            int j=itr.second.second;
           vector<int>ds={n1[i],n2[j]}; 
             if(i+1<n1.size()){
                pq.push({n2[j]+n1[i+1],{i+1,j}});
            }
            ans.push_back(ds);  
        } 
        return ans;
    }
};