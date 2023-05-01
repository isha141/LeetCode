class Solution {
public:
    double average(vector<int>& sal) {
      return (accumulate(begin(sal),end(sal),0.)- 
          *min_element(begin(sal),end(sal)) - *max_element(begin(sal),end(sal))) /(sal.size()-2);
    }
};