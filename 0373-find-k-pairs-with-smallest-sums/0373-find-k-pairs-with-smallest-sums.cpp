class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) { 
         vector<vector<int>>ans;
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<n;++i){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        j=1;
        while(!pq.empty() && ans.size()!=k){
            auto itr=pq.top();
            pq.pop();
            int x=itr.second.first;
            int y=itr.second.second;
            ans.push_back({nums1[x],nums2[y]});
            if(y!=m-1){
                pq.push({nums1[x]+nums2[y+1],{x,y+1}});
                // j++;
            }
        }
        return ans;
    }
};