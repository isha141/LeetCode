class Solution {
public:
    string convert(string s, int num) {
         vector<string>ds(num);
          int j=0; 
        bool flag=0;
        for(int i=0;i<s.size();++i){
              ds[j]+=s[i];
            if((j==0 || flag==0) && j!=num-1){
                j++; 
                flag=0;
            } 
            else if((j==num-1 || flag) && j!=0){
                  j--;
                flag=1;
            }
        }
        string ans="";
        for(auto itr: ds) ans+=itr;
        return ans;
        
    }
};