    bool cmp(char a,char b){
    int val1=0;
    int val2=0;
    if(a>='a' && a<='z'){
        val1=a-'a';
    }
    else{
          val1=a-'A';
    }
    if(b>='a' && b<='z'){
         val2=b-'a';
    }
    else
          val2=b-'A'; 
        return val1<val2;
}
class Solution { 
    bool ok(char ch){
        return (ch=='a' || ch=='A'|| ch=='e' || ch=='E'|| ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U');
    }
public:
    string sortVowels(string s) {
        int n=s.size();
         string small="";
        string large="";
         for(int i=0;i<n;++i){
             if(ok(s[i])){
                  if(s[i]>='a' && s[i]<='z')
                       small+=s[i];
                 else 
                     large+=s[i];
             }
         }
        string ans="";
        sort(small.begin(),small.end(),cmp);
        sort(large.begin(),large.end(),cmp);
        large+=small;
        int k=0;
        for(int i=0;i<n;++i){
             if(ok(s[i])){
                 ans+=large[k++];
             }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};