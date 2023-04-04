class Solution {
public:
    vector<string> commonChars(vector<string>& w) {
         int n=w.size();
         vector<string>ans;
         string s=w[0];
          for(auto itr: s){
            char ch=itr;
            int count=1;
            for(int i=1;i<n;++i){
                string st=w[i]; 
                bool flag=0; 
                int j=0;
                for(j=0;j<st.size();j++){
                    if(st[j]==ch){ 
                        flag=1;
                        count++; 
                        break;
                    } 
                    if(flag)
                        break;
                }
                if(!flag)
                    break;
                w[i][j]='.';
            }
            if(count==n){ 
                 string s="";
                 s+=ch;
                ans.push_back(s);
            }
        }
        return ans;
    }
};