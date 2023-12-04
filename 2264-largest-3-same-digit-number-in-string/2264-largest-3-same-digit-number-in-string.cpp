class Solution {
public:
    string largestGoodInteger(string num) { 
        string ans="";
        string temp="";
        temp+=num[0];
        int n=num.size();
        for(int i=1;i<n;i++)
        { 
            if(temp.size()==3){
                ans=max(ans,temp);
                temp=num[i];
            }
           else if(temp.size() && temp[temp.size()-1]==num[i])
                temp+=num[i];
            else{
                temp=num[i];
            }
        } 
        if(temp.size()==3)
            ans=max(ans,temp);
       if(ans.size()==3 && temp.size()==3)
           return max(ans,temp);
        return ans;
        
    }
};