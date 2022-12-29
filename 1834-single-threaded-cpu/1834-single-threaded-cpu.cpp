class cmp{
    public:
    bool operator()(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b){
        if(a.second.first==b.second.first){ // comapring arrival time 
           if(a.first!=b.first) // busrt time
                return a.first>b.first;
             return a.second.second>b.second.second;
         }
        if(a.second.first!=b.second.first){   
            if(a.first!=b.first)
                return a.first>b.first;
             else
            return a.second.second>b.second.second;
        }
           
        // }
        else
            return a.second.second<b.second.second;
        // if(a.first==b.first)
                // return a.second.second>b.second.second;
    }  
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& task) {
         vector<int>ans;
        int n=task.size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp>pq;
        int time=task[0][0]; 
        int  i=0;
        vector<vector<int>>ds;
        for(int i=0;i<n;++i)
            ds.push_back({task[i][0],task[i][1],i});
            sort(ds.begin(),ds.end());
             time=ds[0][0];
            while(i<n){  
               while(i<n && time>=ds[i][0]){ 
                pq.push({ds[i][1],{ds[i][0],ds[i][2]}});
                i++;
               } 
                if(pq.size()){ 
                    time+=pq.top().first;
                    ans.push_back(pq.top().second.second);
                     pq.pop();
                }
                else{
                    if(i<n){
                        time=ds[i][0];
                    }
                }
                
            }
        while(!pq.empty()){ 
            ans.push_back(pq.top().second.second);
            pq.pop();
        }
        return ans;
    }
};