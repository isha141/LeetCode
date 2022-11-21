class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size(); 
        int k=0;
        int l=0;
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans[j][i]=box[i][j];
            }
        } 
        int i=0;
       for(int i=0;i<m;++i){
          int j=0;
           while(j<n/2){
               swap(ans[i][j],ans[i][n-j-1]);
               j++;
           }
       }
        for(int i=m-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                if(ans[i][j]=='*')
                    continue;
                else if(ans[i][j]=='#'){
                    int k=i+1;
                    while(k<m && ans[k][j]=='.'){
                        k++;
                    }
                    if(k<=m && ans[k-1][j]=='.'){
                        ans[k-1][j]='#';
                        ans[i][j]='.';
                    }
                  }
                }
            }
        return ans;   
    }
};