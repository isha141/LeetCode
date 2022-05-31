class Solution { 
    bool isvalid(string word)
    { 
        if(word.length()==1)
            return 0;
        int d=1;
        int c=0; 
        if(word[0]!='$')
            return false;
        for(auto itr: word)
        {
            if(isalpha(itr))
                return false;
            if(itr=='.')
                d++;
            else if(itr=='$')
                c++;
        }
        if(c>1 || d>2)
            return 0;
        return  1;
    }
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string ans="";
        string word; 
        int c=0;
        for(auto itr: sentence)
            c+= itr==' ';
        int t=0;
        while(ss>>word)
        {
            if(isvalid(word)){
                double val=stol(word.substr(1,word.length()));
                double ans1=((0.01 *discount)*val); 
                ans1=(val-ans1);  
               stringstream temp;
                temp<<fixed<<setprecision(2)<<ans1;
               ans+='$'+temp.str()+' ';
            } 
               else
                ans+=word+' ';
        }
        //ans.erase(remove(ans.begin(), ans.end(), ' '), ans.end());
        //reverse(ans.begin(),ans.end()); 
        ans.pop_back();
        return ans;
    }
};