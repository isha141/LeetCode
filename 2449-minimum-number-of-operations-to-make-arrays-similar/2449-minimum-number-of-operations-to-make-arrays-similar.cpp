class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
       vector<int>e1,e2,o1,o2;
        for(auto it: nums){
            if(it%2)
                o1.push_back(it);
            else
                e1.push_back(it);
        }
        for(auto it: target){
            if(it%2)
                o2.push_back(it);
            else
                e2.push_back(it);
        }
        sort(e1.begin(),e1.end());
        sort(e2.begin(),e2.end());
        sort(o1.begin(),o1.end());
        sort(o2.begin(),o2.end());
        long long ans=0;
        for(int i=0;i<e1.size();++i){
            ans+=abs(e1[i]-e2[i]);
        }
        for(int j=0;j<o1.size();++j){
            ans+=abs(o1[j]-o2[j]);
        }
        return ans/4;
    }
};