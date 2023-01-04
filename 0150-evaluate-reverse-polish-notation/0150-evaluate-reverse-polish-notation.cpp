class Solution {
public:
    int evalRPN(vector<string>& tok) {
        int n=tok.size();
        int ans=0; 
        stack<int>s; 
        for(auto itr: tok){
            if(itr[itr.size()-1]>='0' && itr[itr.size()-1]<='9'){ 
                bool flag=0; 
                int i=0;
                if(itr[0]=='-'){
                    flag=1;
                    i=1;
                }
                int val=0;
                for(int j=i;j<itr.size();++j){
                    val=val*10+itr[j]-'0';
                } 
                if(flag) val=val*-1;
                s.push(val);
            }
            else if(itr=="+"){
                  int val=s.top(); s.pop();
                int val2=s.top();
                s.pop();
                s.push(val+val2);
            }
            else if(itr=="-"){
             int val=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(-val+val2);
            }
            else if(itr=="*"){
                int val=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(val*val2);
            }
            else if(itr=="/"){
                int val=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                s.push(val2/val);
            }  
            // if(s.size())
            //     cout<<s.top()<<",, ";
            // cout<<itr<<" ";
        }
        return s.top();
    }
};