class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        vector<int>ds;
        while(x!=0){
            int temp=x%10;
            ds.push_back(temp);
            x/=10;
        }
        vector<int>a;
        a=ds;
        reverse(a.begin(),a.end());
        if(a==ds) return 1;
        return 0;
    }
};