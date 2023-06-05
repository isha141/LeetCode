class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
          int n=c.size();
        if(n==1) return 1; 
         sort(c.begin(),c.end());
           double slope=(abs(c[1][0]-c[0][0])*1.0)/(abs(c[1][1]-c[0][1])); 
        for(int i=0;i<n;++i){
             for(int j=i+1;j<n;++j){
                 double s1=(abs(c[j][0]-c[i][0])*1.0)/(abs(c[j][1]-c[i][1]));
                 if(s1!=slope)
                      return 0;
             }
        }
        return 1;
    }
};