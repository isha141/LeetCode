class Solution {
public:
    int minimumLines(vector<vector<int>>& st) {
        sort(st.begin(),st.end()); 
        int n=st.size();
        int count=1; 
        if(n==1)
            return 0;
        for(int i=1;i<n-1;i++)
        {
            if(1LL*(st[i][1]-st[i-1][1])*(st[i+1][0]-st[i][0])!= 1LL *(st[i+1][1]-st[i][1])*(st[i][0]-st[i-1][0]))
               count++;
        }
         return count;         
    }
};