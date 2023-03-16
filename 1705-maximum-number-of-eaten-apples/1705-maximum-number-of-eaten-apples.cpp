class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& days) {
        int n=a.size();
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  
        int i=0;
        int day=1;
         while(1){ 
             if(i<n){
            pq.push({days[i]+i,a[i]});  
                 i++;
             }
             while(!pq.empty() && pq.top().first<day)
                 pq.pop();
            if(pq.size()){
                ans+=1;
                auto itr=pq.top();
                pq.pop();
                int app=itr.second;
                int valid=itr.first;
                if(app>1){
                    pq.push({valid,app-1});
                }
            }
             if(i>=n && pq.size()==0) return ans;
            day++;
        } 
        // while(!pq.empty()){
        //     while(!pq.empty() && pq.top().first<day)
        //         pq.pop();
        //     if(pq.size()){
        //         ans+=1;
        //         auto itr=pq.top();
        //         pq.pop();
        //         int app=itr.second;
        //         int valid=itr.first;
        //         if(app>1){
        //             pq.push({valid,app-1});
        //         }
        //     }
        //     day++;
        // }
        return ans;
    }
};