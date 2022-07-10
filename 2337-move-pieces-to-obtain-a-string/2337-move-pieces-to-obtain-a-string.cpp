class Solution {
public:
    bool canChange(string start, string target) {
        int i=0;
        int j=0;
        int n=start.size();
        while(i<n || j<n)
        {
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++; 
            // cout<<i<<" "<<j<<endl; 
            if(i==n || j==n)
                return ( i==n && j==n);
            if(start[i]!=target[j])
                return false;
            if(start[i]=='L'){
                if(i<j)
                    return false;
            }
            else{
                if(i>j)
                    return false;
            }
            i++;
            j++;
        }
        return i==n && j==n;
    }
};