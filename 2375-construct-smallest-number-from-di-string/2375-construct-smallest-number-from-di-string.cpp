class Solution {
public:
    string smallestNumber(string pat) {
        int n=pat.size();
        int k=1;
        string ans="";
          for(int i=0;i<n;++i){
              ans+=to_string(k);
              k++;
          }
        ans+=to_string(k);
        int i=0;
        while(i<n){
             int pos=i;
            if(pat[i]=='D'){
                while(i<pat.size() && pat[i]=='D') 
                    i++;
            reverse(ans.begin()+pos,ans.begin()+i+1);
            }
            // cout<<i<<" ";
            i++;
        }
        return ans;
        
    }
};