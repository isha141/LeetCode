class Solution { 
private:
    string stringjustifier(string temp,int maxwidth,int islast)
    {
        int stringspace=0;
        if(temp.length()==maxwidth)
            return temp;
        for(auto itr: temp)
        {
            if(itr==' ') stringspace++;
        } 
        int spacetoinsert=maxwidth-temp.length();
        if(stringspace==0 || islast==1){
            temp.insert(temp.end(),spacetoinsert,' ');
            return temp;
        }
        int eachslot=spacetoinsert/stringspace;
        int leftoverspace=spacetoinsert%stringspace; 
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i]==' ' && (eachslot>0 || leftoverspace>0))
            {
                int totalspace=eachslot+(leftoverspace-->0?1:0);
                temp.insert(i,totalspace,' ');
                i+=totalspace;
            }
        }
        return temp;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string temp=words[0];
        for(int i=1;i<words.size();i++)
        {
            if((temp.length()+ words[i].length()+1)<=maxWidth)
                temp+=" "+words[i];
            else
            {
                temp=stringjustifier(temp,maxWidth,0);
                ans.push_back(temp);
                temp=words[i];
            }
        }
        temp=stringjustifier(temp,maxWidth,1);
        ans.push_back(temp);
        return ans;
    }
};