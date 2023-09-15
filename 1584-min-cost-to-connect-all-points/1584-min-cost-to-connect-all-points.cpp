class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res=0;
        int n=points.size(); 
         vector<bool>v(n,0);  
        int i=0; 
        int connected=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        while(++connected<n)
        {
           v[i]=true;
            for(int j=0;j<n;j++)
            {
                if(!v[j])
                pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),j});
            }
            while(v[pq.top().second]){
                 pq.pop();
            } 
            cout<<"!"<<pq.top().first<<endl;
            res+=pq.top().first;
            i=pq.top().second;
            pq.pop();
        }
        return res;
    }
};