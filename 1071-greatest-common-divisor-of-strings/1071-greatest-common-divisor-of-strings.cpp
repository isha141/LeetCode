class Solution { 
    bool solve(string s,string s1,string s2){
        string temp="";
        while(temp.size()<s1.size()){
            temp+=s;
        }
        string temp2="";
        while(temp2.size()<s2.size()){
            temp2+=s;
        }
        if(temp==s1 && temp2==s2)
            return 1;
        return 0;
    }
public:
    string gcdOfStrings(string str1, string str2) {
         string s="";
        int i=0;
        int j=0;
        int m=str1.size();
        int n=str2.size();
        string ans="";
        while(i<m && j<n){
            if(str1[i]!=str2[j])
                return "";
            s+=str1[i];
            if(solve(s,str1,str2)){
                ans=s;
            }
            i++;
            j++;
        }
        return ans;
    }
};