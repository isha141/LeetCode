class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(auto itr: arr)
            mp[itr]++;
        priority_queue<int>pq;
        for(auto [x,y]: mp)
            pq.push(y);
        int c=0;
        int count=0;
        while(!pq.empty())
        {
            int temp=pq.top();
            c+=temp;
            count++;
            pq.pop();
            if(c>=n/2)
                return count;
        }
        return count;
    }
};