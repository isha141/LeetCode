class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& can, int extra) { 
        int n=can.size();
         vector<bool>ans;
         priority_queue<int>pq;
         for(auto itr: can)
             pq.push(itr);
          for(auto itr: can){
              int temp=itr+extra;
              int t=pq.top();
              if(temp>=t){
                  ans.push_back(1);
              }
              else{
                  ans.push_back(0);
              }
          }
        return ans;
    }
};