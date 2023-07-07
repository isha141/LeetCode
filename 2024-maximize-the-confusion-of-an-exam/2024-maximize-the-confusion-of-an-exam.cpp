class Solution {
public:
    int maxConsecutiveAnswers(string ans, int k) {
           int n=ans.size();
           long long  res=1;
           int count=0; 
           int t=0;
           int f=0; 
           int j=0; 
        // long ans=0;
           for(int i=0;i<n;++i){
                 if(ans[i]=='T') t+=1;
                 else{
                     f+=1;
                 }  
                 bool flag=0;
                 if(t>=f && t!=0 && f!=0){
                     count=f;
                     flag=1;
                 }
               else if(f>=t && t!=0 && f!=0){
                   count=t;
               }
                 while(j<i && count>k){ 
                    if(ans[j]=='T')  
                        t-=1;
                    else  
                        f-=1;
                     j++; 
                     if(t>f && t!=0 && f!=0){
                     count=f;
                     flag=1;
                    }
                 else if(f>t && t!=0 && f!=0){
                   count=t;
                   } 
                     else count=0;
                 }
               res=max(res,1ll*(i-j+1)); 
               count=0;
           } 
            return res;
    }
};