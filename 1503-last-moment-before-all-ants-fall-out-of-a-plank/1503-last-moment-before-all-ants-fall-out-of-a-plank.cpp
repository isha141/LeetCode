class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=0;
        int m=left.size();
        for(int i=0;i<m;++i){
            maxi=max(maxi,abs(left[i]));
        }
        for(int i=0;i<right.size();++i){
            maxi=max(maxi,abs(right[i]-n));
        }
        return maxi;
    }
};