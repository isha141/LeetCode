class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans=INT_MIN;
        int n=points.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && points[i][0]-pq.top().second>k)
                pq.pop();
            if(!pq.empty())
            ans=max(ans,points[i][0]+points[i][1]+pq.top().first);
            pq.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;
    }
};