class Solution { 
    long solve(string temp){
        long long ans=0;
        bool flag=0;
        int k=0;
        if(temp[0]=='-'){
            flag=1;
            k=1;
       }
        for(int i=k;i<temp.size();++i)
            ans=ans*10+temp[i]-'0';
        if(flag) ans=ans*-1;
        return ans;
    }
public:
    int evalRPN(vector<string>& t) {
        int n=t.size();
        long ans=0;
        stack<long long>s;
        for(auto itr: t){
            string temp=itr; 
            if(temp!="+" && temp!="-" && temp!="*" && temp!="/"){
             long long res=solve(temp); 
                // cout<<res<<",,";
                s.push(res);
            }
            else{
                long a=s.top();
                s.pop();
                // cout<<a<<",,";
                long b=s.top();
                s.pop();
                // cout<<b<<",,";
                if(temp=="+")
                    s.push(a+b);
                if(temp=="-")
                    s.push(b-a);
                if(temp=="*")
                    s.push(a*b);
                if(temp=="/")
                    s.push(b/a);
            }
        }
        return s.top();
    }
};