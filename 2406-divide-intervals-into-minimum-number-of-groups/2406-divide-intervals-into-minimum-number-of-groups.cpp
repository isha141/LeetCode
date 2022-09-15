class Solution { 
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]>b[1];
    }
public:
    int minGroups(vector<vector<int>>& in) {
        sort(in.begin(),in.end()),cmp; 
        int c=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it: in){
            if(pq.size() && pq.top()<it[0]){
                pq.pop();
            }
               pq.push(it[1]);
        }
        return pq.size();
    }
};