class Solution { 
public:
    int minimumTotal(vector<vector<int>>& t) {
       int n =t.size();
       vector<int>prev(n);
        for(int j=0;j<n;j++){
            prev[j]=t[n-1][j];
        }
        for(int i=n-2;i>=0;i--){ 
            vector<int>temp(n);
            for(int j=i;j>=0;j--){
                long left=INT_MAX;
                 long  right=INT_MAX;
            left=t[i][j]+ prev[j]; 
            // if(j>0 && i>0)
           right=t[i][j]+prev[j+1];
                temp[j]=min(left,right);
            }
            prev=temp;
        }
        return prev[0];
    }
};