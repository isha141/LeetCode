class Solution {
public:
    bool isSubsequence(string s, string t) {
          int n=s.size();
          int m=t.size();
          vector<int>freq(26,0);
          vector<int>freq2(26,0);
        int j=0;
        int i=0;
          for( i=0;i<n;++i){
              bool flag=0;
              while(j<m){
                  if(s[i]!=t[j])
                        j++;
                  else{
                      j++;
                      flag=1;
                      break;
                  }
              }
              if(!flag)
                   return 0;
          }
        if(i>=n) return 1;
        return 0;

    }
};