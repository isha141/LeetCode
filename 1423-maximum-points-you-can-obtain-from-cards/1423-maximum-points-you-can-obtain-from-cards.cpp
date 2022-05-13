class Solution {
public:
    int maxScore(vector<int>& points, int k) {
      int n=points.size();
        int sum=0;
        int ans=INT_MIN;
        for(auto itr: points)
            sum+=itr;
        int temp=n-k;
        int mini=0;
        for(int i=0;i<temp;i++)
            mini+=points[i];
        for(int i=temp;i<n;i++)
        {
            ans=max(ans,sum-mini);
            mini-=points[i-temp];
            mini+=points[i];
        }
        return max(ans,sum-mini);
    }
};