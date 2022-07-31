class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        // sort(grades.begin(),grades.end());
        int k=0;
        int n=grades.size();
        int total=0;
        while(total+k+1<=n)
            total+=++k;
        return k;
    }
};