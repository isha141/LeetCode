class Solution {
public:
    string convert(string s, int num) { 
        int n=s.size(); 
        if(num==1)
            return s;
      vector<vector<char>>ds(num,vector<char>(n+1,'*'));
      bool flag=0;
      int i=0;
        int j=0;
        int k=0; 
        int l=0;
        while(k<s.size()){
            if(!flag){  
                while(i<num && k<s.size()){
                    ds[i][j]=s[k];
                    // cout<<i<<".."<<j<<"..."<<s[k]<<endl;
                    i++;  
                    // cout<<s[k]<<"..";
                    k++;
                }
                flag=!flag;
                // cout<<endl;
            }
            else{   
                i--;
                while(i>0  && k<s.size()){ 
                    i--;
                    j++;
                    ds[i][j]=s[k];
                    // cout<<i<<"***"<<j<<"**"<<s[k]<<endl;
                    if(i>0  )
                    k++; 
                    l=1;
                }
                flag=!flag;
                // cout<<endl;
            }
        }
        string ans="";
        for(int i=0;i<num;++i){
            for(int j=0;j<n;++j) {
                if(ds[i][j]!='*')
                    ans+=ds[i][j];
                // cout<<ds[i][j];
            }
            // cout<<endl;
        }
        return ans;
    }
};