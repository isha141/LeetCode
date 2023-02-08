#define ll long long
// class Solution {
// private:
//     int gcd(int a, int b) {
//         if (!b) return a;
//         return gcd(b, a % b); //188821161...

//     }
//     int lcm(ll a, ll b) {
//         ll temp = (a / gcd(a, b)) * b;
//         return temp > INT_MAX ? INT_MAX : temp;
//     }
// public:
//     int minimizeSet(int divisor1, int divisor2, int uc1, int uc2) {
//         int l = 1, r = INT_MAX, LCM = lcm(divisor1, divisor2);
//         cout<<LCM<<":"<<endl;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             int a = mid / divisor1, b = mid / divisor2;
//             if (uc1 <= mid - a && uc2 <= mid - b && uc1 + uc2 <= (mid - (mid / LCM))) {
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return l;
//     }
// };






































#define ll long long
class Solution {  
    private:
ll gcd(ll a, ll b) 
{  
if (b > a) {return gcd(b, a);} 
 if (b == 0) {return a;}
 return gcd(b, a % b);
}
ll lcm(int a, int b) {
    ll temp= (1ll* a * b) / gcd(a, b);
         return temp>INT_MAX?INT_MAX: temp;
}
public:
    int minimizeSet(int div1, int div2, int uc1, int uc2) {
        int low=0;
        int high=INT_MAX; 
        int com=lcm(div1,div2);
        // cout<<com<<"..."<<endl;
        int ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2; 
            ll a=mid/div1;
            ll b=mid/div2;
            ll ra=mid-a;
            ll rb=mid-b;
            // cout<<ra<<"::"<<rb<<"::"<<mid<<endl;
            if(ra>=uc1 && rb>=uc2 && (uc1+uc2)<=(mid-(mid/com))){
               ans=mid;
              high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};