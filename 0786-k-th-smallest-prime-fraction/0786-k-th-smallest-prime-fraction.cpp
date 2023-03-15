class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>ans;
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i!=j){
                    pq.push({(double)arr[i]/(arr[j]*1.0),{arr[i],arr[j]}});
                }
            }
        }
        while(--k){ 
            // cout<<pq.top().first<<"::"<<pq.top().second.first<<"***"<<pq.top().second.second<<endl;
            pq.pop();
        }
        ans.push_back(pq.top().second.first); 
        ans.push_back(pq.top().second.second);
        return ans;
    }
};