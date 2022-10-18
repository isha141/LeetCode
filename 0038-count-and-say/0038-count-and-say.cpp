class Solution {
    private:
    string ans=""; 
   void koko(int j,string temp, string  &a){ 
        if(j>=temp.size())
            return ;
       // if(j==temp.size()-1){
       //     a+=to_string(1);
       //     a+=temp[j-1];
       // }
        int c=1;
        while(j<temp.size()){
            if(j+1<temp.size()&& temp[j]==temp[j+1])
                c++;
            else
                break;
            j++;
        } 
        a+=to_string(c);
        a+=temp[j];
        koko(j+1,temp,a);
    }
    private:
    void solve(int i,int n,string temp){
        for(int j=i+1;j<=n;++j){
            string a="";
            koko(0,temp,a);
            // cout<<a<<" ";
            temp=a;
            ans=temp;
        }
    }
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        } 
        if(n==2)
            return "11";
        string temp="11";
        solve(2,n,temp);
         return ans;
    }
};