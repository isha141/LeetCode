class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
           vector<int>ans;
            int n=as.size();
           stack<pair<int ,char>>s;
             for(int i=0;i<n;++i){
                 int temp=as[i];
                 char ch='R';
                 if(temp<0){
                     ch='L';
                 }
                 bool flag=0;
           while(!s.empty() && s.top().second!=ch && ch=='L'){
               auto itr=s.top();
                s.pop();
               int val=itr.first;
               if(abs(val)==abs(temp)){
                   flag=1;
                   break;
               }
               if(abs(val)>abs(temp)){ 
                   s.push({val,itr.second});
                   flag=1;
                   break;
               }
           } 
          if(!flag){
              s.push({temp,ch});
          }
        } 
        while(!s.empty()){
            ans.push_back(s.top().first);
             s.pop();
        } 
        reverse(ans.begin(),ans.end());
         return ans;
    }
};