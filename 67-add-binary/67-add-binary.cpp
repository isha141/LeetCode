class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int m=a.size();
        int n=b.size();
        int i=m-1;
        int j=n-1;  
        int carry=0;
        while(i>=0 || j>=0)
        { 
            int temp=0;
           if(i>=0)
           temp+=a[i]-'0';
            if(j>=0)
                temp+=b[j]-'0';
            temp+=carry;
            res+=to_string(temp%2);
            carry=temp/2;
            i--;
            j--;
        }  
        if(carry)
            res+=to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};