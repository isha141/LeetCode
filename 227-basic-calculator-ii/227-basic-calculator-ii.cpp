class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int ans=0;
        stack<int>st;
        long long  num=0; 
        char operation ='+';
      for(int i=0;i<n;++i){
          if(isdigit(s[i])){
              num=num*10+s[i]-'0';
          }
           if(!isdigit(s[i]) && !iswspace(s[i]) || i==n-1){
               if(operation=='+'){
                   st.push(num);
               }
               else if(operation=='-'){
                   st.push(-num);
               }
               else if(operation=='*'){
                   int temp=st.top();
                   st.pop();
                   st.push(temp*num);
               }
               else if(operation=='/'){
                   int temp=st.top();
                   st.pop();
                   st.push(temp/num);
               }
               num=0;
               operation =s[i];
           }
      } 
        // cout<<"hy";
        while(!st.empty()){
            int temp=st.top(); 
            // cout<<temp<< " ";
            st.pop();
            ans+=temp;
        }
        return ans;
    }
};