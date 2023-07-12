class Solution {
public:
    int calculate(string str) {
        int n=str.size();
        stack<int>s; 
        char op='+'; 
        long long  num=0;
        for(auto i=0;i<n;++i){
            if(isdigit(str[i])){
                num=num*10+str[i]-'0';
            }
             if(!isdigit(str[i]) && !iswspace(str[i]) || i==n-1){
                    if(op=='+'){
                        s.push(num);
                    }
                    else if(op=='-'){
                        s.push(-num);
                    }
                    else if(op=='*'){
                        auto iitr=s.top();
                        s.pop();
                        s.push(iitr*num);
                    }
                    else{
                        auto iitr=s.top(); 
                        s.pop();
                        s.push(iitr/num);
                    }
                    num=0;
                    op=str[i];
            }
        } 
        int ans=0;
        while(!s.empty()){
            auto itt=s.top(); 
            s.pop();
            ans+=itt;
        }
         return ans;   
    }
};