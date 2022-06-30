class Solution {
public:
    int evalRPN(vector<string>& t) {
        int ans=stoi(t[0]);
        stack<int>s;
        for(auto itr: t){
              int m=itr.size();
            if(itr[0]>='0' && itr[0]<='9'){
                s.push(stoi(itr));
            } 
            else if(itr[m-1]>='0' && itr[m-1]<='9')
            {
                s.push(stoi(itr));
            }
            else{
                int temp=s.top();
                s.pop(); 
                int temp2=s.top();
                s.pop();  
                // cout<<temp<<" "<<temp2<<endl;
                int a=0;
                if(itr=="+")
                a=temp +temp2;
                else if(itr=="-")
                    a=temp2-temp;
                else if(itr=="*")
                    a=temp2*temp;
                else if(itr=="/")
                        a=temp2/temp; 
                ans=a; 
                // cout<<ans<<" ";
                s.push(a);
            }
        }
        return ans;
    }
};