class Solution {
public:
    int reverse(int x) { 
        if(x<=INT_MIN || x>=INT_MAX) return 0;
        int sign=0;
        if(x<0)
            sign=1;
        string s=to_string(x);
        std::reverse(s.begin(),s.end());
        long long  temp =stoll(s); 
        if(temp>=INT_MAX)
            return 0;
        if(sign)
            temp=temp*-1;
        return temp;
            
    }
};