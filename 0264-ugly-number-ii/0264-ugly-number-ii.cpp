class Solution {
public:
    int nthUglyNumber(int n) {
       set<long long>fixed,ans;
        ans.insert(1);
        while(fixed.size()!=n){
            auto itr=*(ans.begin());
            ans.erase(itr);
            fixed.insert(itr);
            ans.insert(2*itr);
            ans.insert(3*itr);
            ans.insert(5*itr);
        }
        return *(fixed.rbegin());
    }
};