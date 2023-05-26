class Solution { 
    
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
            int m=q.size();
           vector<int>ans(m,1); // lowest ancestor will be the smallest of the bigger value of the child node 
           for(int i=0;i<m;++i){
               int x=q[i][0] , y=q[i][1];
                while(x!=y){
                    if(x>y){
                     x/=2;
                    }
                    else{
                        y/=2;
                    }
                    ans[i]++;  // here incrementing the depth at each level 
                }
           }
        return ans;
    }
};