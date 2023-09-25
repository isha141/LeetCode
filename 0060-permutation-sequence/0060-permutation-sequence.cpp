class Solution {
public:
    string getPermutation(int n, int k) {
            string ans="";
            vector<int>ds;
            int fact=1;
            for(int i=1;i<n;++i){
                ds.push_back(i);
                fact=fact*i;
            }
           ds.push_back(n);
           k-=1;
          while(1){
              ans+=to_string(ds[k/fact]);
              ds.erase(ds.begin()+k/fact);
              if(ds.size()==0)
                    return ans;
              k%=fact;
              fact=fact/ds.size();
          }
         return "";
           
    }
};