class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0; 
        long long ans=0;
        while(isspace(s[i]))
            i++;
        int sign=0;
        if(s[i]=='-'){
            sign=1;
        i++;
        } 
        else if(s[i]=='+') i++;
        for(int j=i;j<n;++j){ 
            if(ans>INT_MAX)
                break;
            if(isdigit(s[j])){ 
                ans=ans*10+s[j]-'0';
            }
            else
                break;
        } 
        // cout<<ans<<" ";
        if(ans>INT_MAX){
            if(sign)
                return INT_MIN;
            else
               return INT_MAX;
        }  
       // cout<<"hy"<<" ";
        if(sign)
            return -1*ans;
        else
            return ans;
    }
};