class cmp{
bool operator()(pair<int,int>&a,pair<int,int>&b)
{
    if(a.first!=b.first)
        return a.first>b.first;
    else
        return a.second<b.second;
};
};
class Solution {
public:
    int minRefuelStops(int target, int start, vector<vector<int>>& st) {
        priority_queue<int>pq;
        int maxi=start;
        int c=0; 
        int i=0;
        while(maxi<target)
        { 
           while(i<st.size() && st[i][0]<=maxi) {
               pq.push(st[i][1]);
               i++;
           }
            if(pq.empty())
                return -1;
            maxi+=pq.top();
            pq.pop();
           c++;
        }
        return c;
    }
};