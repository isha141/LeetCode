class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        nth_element(p.begin(),p.begin()+k,p.end(),[](vector<int>&a,vector<int>&b)
                    { return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
                    });
        return vector<vector<int>>(p.begin(),p.begin()+k);
    }
};