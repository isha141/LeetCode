class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& days) {
        int n=a.size();
        int ans=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        int day=1;
        for(int i=0;i<n;++i){ 
            pq.push({days[i]+i,a[i]}); 
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
            day++;
        } 
        while(!pq.empty()){
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
            day++;
        }
        return ans;
        // for(int i=1;i<=100000;++i){
        //     while(!pq.empty() && pq.top().first<i){
        //         pq.pop();
        //     }
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
        //     else
        //         return ans;
        // }
        // return ans;
    }
};