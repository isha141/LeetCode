class Solution {
public:
    int minimumLines(vector<vector<int>>& st) {
        int count=1; 
        if(st.size()==1)
            return 0;
        sort(st.begin(),st.end());
        for(int i=2;i<st.size();i++)
        {
            vector<int>temp1=st[i];
            vector<int>temp2=st[i-1];
            vector<int>temp3=st[i-2];
            int x0=temp1[0];
            int y0=temp1[1];
            int x1=temp2[0];
            int y1=temp2[1];
            int x2=temp3[0];
            int y2=temp3[1];
        if((1LL*(x1-x0)*(y2-y1))!= (1LL* (x2-x1)*(y1-y0)))
            count++;
        }
        return count;
    }
};