class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int can) {
         long long ans=0;
         int n=cost.size(); 
         int left=0;
        int right=n-1; 
        set<int>s;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>l,r;
         while(left<n && left<can){
             l.push({cost[left],left});
              left++;
         }  
         long long sum=0;
          int c=0;
          while(right>=0 && c<can){
              r.push({cost[right],right});
               right-=1; 
              c+=1;
          }
          while(k--){
              auto left1=l.top();
               auto right1=r.top();
              int ind1=left1.second;
              int ind2=right1.second; 
              if(s.find(ind1)!=s.end()){
                  l.pop();
              }
               while(left<n && l.size()!=can){
                       if(s.find(left)==s.end()){
                           l.push({cost[left],left});
                       }
                        left++;
                }
              if(s.find(ind2)!=s.end()){
                  r.pop();
              }
              while(right>=0 && r.size()!=can){ 
                   if(s.find(right)==s.end()){
                       r.push({cost[right],right});
                   }
                      right--;
              }
              int val1=INT_MAX;
              int val2=INT_MAX;
              while(l.size() && s.find(l.top().second)!=s.end()){
                    l.pop();
              }
               if(l.size()){
                   val1=l.top().first;
               }
               while(r.size() && s.find(r.top().second)!=s.end()){
                    r.pop();
              } 
              if(r.size()){
                  val2=r.top().first;
              }
               if(val1<=val2){
                    if(val1!=INT_MAX){
                        sum+=val1;
                        s.insert(l.top().second);
                    }
               }
               else if(val2<=val1){
                   if(val2!=INT_MAX){
                       sum+=val2;
                        s.insert(r.top().second);
                   }
               }
          }    
        return sum;
    }
};