class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& heal, string dir) {
           int n=pos.size();
         vector<int>ans;
          stack<pair<int,char>>st;  
           vector<pair<int,int>>ds;
          for(int i=0;i<n;++i){
              ds.push_back({pos[i],i});
          }
          sort(ds.begin(),ds.end());
          for(int i=0;i<n;++i){
              int ind1=ds[i].second;
              char ch=dir[ind1];
                while(ch=='L' && !st.empty() && (st.top().second!=ch)){
                    if(heal[ind1]<heal[st.top().first]){
                        heal[ind1]=0; 
                        int ind=st.top().first;
                        heal[ind]-=1; 
                        if(heal[ind]==0){
                            st.pop();
                        }  
                        // cout<<ind1<<";;"<<endl;
                        break;
                    }
                    else if(heal[ind1]<=heal[st.top().first]){
                         st.pop();
                          heal[ind1]=0; 
                        break;
                    }
                    else{
                         st.pop(); 
                         heal[ind1]-=1;  
                        // cout<<ind1<<"***"<<endl;
                        // break;
                    }
                }
              if(heal[ind1]!=0){
                  st.push({ind1,dir[ind1]});
              }
          } 
           stack<int>s; 
          vector<pair<int,int>>check;
         while(!st.empty()){
             auto itr=st.top();
              st.pop(); 
             check.push_back({itr.first,heal[itr.first]});
         }
         sort(check.begin(),check.end());
         for(auto itr: check)
               ans.push_back(itr.second);
        return ans;
    }
};