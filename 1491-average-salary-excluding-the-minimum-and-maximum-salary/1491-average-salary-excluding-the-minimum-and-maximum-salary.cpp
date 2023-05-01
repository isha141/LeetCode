class Solution {
public:
    double average(vector<int>& sal) {
         sort(sal.begin(),sal.end());
         int n=sal.size();
         double sum=0;
         for(int i=1;i<n-1;++i){
             sum+=sal[i];
         }
          return (double)sum/(n-2); 
    }
};