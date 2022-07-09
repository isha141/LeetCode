// class Solution {
// public:
//     int myAtoi(string s) {
//         int n=s.size(); 
//         bool sign=0;  
//         int c=0;
//         long ans=0;
//         for(int i=0;i<n;++i){
//             if(s[i]=='+' || s[i]=='-' )
//                 c++;
//             if(s[i]==' ')
//                 continue;
//             else if(s[i]=='-' && !sign)
//                 sign=1;
//             else if(s[i]>='0' && s[i]<='9')
//                 ans=ans*10+(long )(s[i]-'0'); 
//            else if(s[i]>='a' && s[i]<='z' || s[i]=='.')
//                return 0;
//         }  
//         if(c>1) return 0;  
//         cout<<endl;
//          cout<<ans<<" ";
//         if(ans>=INT_MAX){
//             if(sign) 
//                 return INT_MIN; 
//             return INT_MAX;
//         }
//         return ans=sign?(-1*ans):ans ;
            
                
//     }
// };
class Solution {
public:
    int myAtoi(string s) {
    int i=0;
        int n=s.size();
        int res=INT_MAX;
        long long num=0;
        int flag=0;
        while(isspace(s[i]))
        {
            i++;
        }
        if(s[i]=='-')
        {
             flag=1;
            i++;
        } 
        else if(s[i]=='+')
            i++;
        if(!isdigit(s[i]))
            return 0;
        for(int j=i;j<n;j++)
        {
           if(isdigit(s[j]))
           { 
               if(num>INT_MAX)
                   break;
               else
                num=num*10+s[j]-48 ; 
           } 
            else
                break;
        }
        if(flag==1)
        { 
            if(num>INT_MAX)
                return INT_MIN;
            else
            {
            num=num*-1;
            return num;
            }   
        }
        if(num>INT_MAX)
                return INT_MAX;
        else
            return num;
        
            
    }
};