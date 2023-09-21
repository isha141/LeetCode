class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        double ans=0;
        int n=n1.size();
        int m=n2.size();
        int i=0;
        int j=0;
        int c1=-1;
        int c2=-1;
        int take=(m+n+1)/2;
        int count=0;
        while(i<n && j<m){
            if(n1[i]<=n2[j]){
                count+=1;
                if(count==take){
                    if(c1==-1)
                    c1=n1[i];
                }
                else if(count==take+1){
                    c2=n1[i];
                }
                i++;
            }
            else{
                count+=1;
                if(count==take){
                    if(c1==-1){
                        c1=n2[j];
                    }
                }
                else if(count==take+1){
                        c2=n2[j];
                    }
               j++;
            }
        }
        while(i<n){
            count+=1;
            if(count==take){
                    if(c1==-1){
                        c1=n1[i];
                    }
            }
            else if(count==take+1){
                        c2=n1[i];
                    }
            i++;
        }
        while(j<m){
            count+=1;
            if(count==take){
                        c1=n2[j];
           }
           else if(count==take+1){
                        c2=n2[j];
            }
            j++;
        }
        cout<<c1<<"-->"<<c2<<endl;
        if((m+n)%2){
            return (double)c1;
        }
        else
            return (double)(c1+c2)/2.0;
        
    }
};