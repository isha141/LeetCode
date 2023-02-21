class Solution {
public:
    string multiply(string num1, string num2) {
        string ans="";
        int m=num1.size();
        int n=num2.size();
        vector<int>ds(m+n,0);
        // long long a=stoll(num1);
        // long long b=stoll(num2);
        // if(a==0 || b==0) return "0";
        
        int k=0;
        int i=m-1;
        int j=n-1;
        while(i>=0){
            int temp=num1[i]-'0';
            int l=k;
            for(int j=n-1;j>=0;--j){
                int a=num2[j]-'0';
                int res=temp*a+ds[l];
                ds[l]=res%10;
                int carry=res/10;
                l++;
                ds[l]+=carry;
            }
            i--;
            k++;
        }
        for(auto itr: ds){
            ans+=to_string(itr);
        } 
        reverse(ans.begin(),ans.end());
        bool flag=0;
        int ind=-1;
        for(int i=0;i<ans.size();++i){
            if(ans[i]=='0' && !flag){
                ind=i;
            } 
            else if(ans[i]!='0'){
                flag=1;
            }
        }
        string res="";
        cout<<ind<<":"<<endl;
        if(ind!=-1 && (ind+1)!=(n+m)){
            res=ans.substr(ind+1);
        } 
        else if(ind+1!=(n+m)){
            res=ans;
        }
        else if(ind+1==(n+m))
            return "0";
        return res;
    }
};