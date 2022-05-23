class Solution {
public:
    bool isHappy(int n) {
        int ans=n; 
        set<int>s;
        while(ans>1)
        {
            int temp=ans;
            int k=0;
            while(temp!=0)
            {
                int rem=temp%10;
                k+=rem*rem;
                temp=temp/10;
            }
            ans=k; 
            if(s.find(ans)==s.end())
                s.insert(ans);
            else
                return false;
        }
       
            return true;
    }
};