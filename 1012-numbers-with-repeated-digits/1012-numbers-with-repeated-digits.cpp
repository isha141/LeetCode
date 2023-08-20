class Solution { 
    private: 
    int dp[10][2][2][1<<10];
    void digit(int n,vector<int>&ds){
          while(n){
              ds.push_back(n%10);
              n/=10;
          }
    }
     long long solve(int ind,vector<int>&ds,int tight,int zero,int vis,int mask,int num){
         if(ind>=ds.size()){
             if(vis){ 
                 // cout<<num<<" ;; ";
                   return 1;
             }
             return 0;
         }
          if(dp[ind][tight][vis][mask]!=-1)
                return dp[ind][tight][vis][mask];
         int limit=(tight)?ds[ind]:9;
         long long ans=0;
         for(int i=0;i<=limit;++i){
             int newtight=(ds[ind]==i)?tight:0;
             if(mask==0 && i==0){
                 ans+=solve(ind+1,ds,newtight,1,0,0,0);
             }
             else if((mask&(1<<i))){
                 ans+=solve(ind+1,ds,newtight,0,1,mask,num*10+i);
             }
             else{
                 ans+=solve(ind+1,ds,newtight,0,vis,(mask|(1<<i)),num*10+i);
             }
         }
         return dp[ind][tight][vis][mask]=ans;
     }
public:
    int numDupDigitsAtMostN(int n) {
        vector<int>ds;
         digit(n,ds);
         reverse(ds.begin(),ds.end());
         memset(dp,-1,sizeof(dp));
         return solve(0,ds,1,1,0,0,0);
    }
};

// class Solution {
// public:

// 	int dp[11][2][2][(1 << 10)];


// 	int solve(int pos, bool bound, bool hasRepeated, int mask, string &s,int num) {

// 		if (pos == s.length()) { 
//              if(hasRepeated){
//                  cout<<num<<" ;; ";
//                  return 1;
//              }
//             return 0;
// 		}

// 		// if (dp[pos][bound][hasRepeated][mask] != -1) return dp[pos][bound][hasRepeated][mask];

// 		int maxDigit = bound ? s[pos] - '0' : 9;
//         long long ans=0;

// 		for (int digit = 0; digit <= maxDigit; digit++) {

// 			/* if this is a leading zero, then hasRepeated for the the current guy (position) will obviously be false  */
// 			if (digit == 0 && mask == 0) ans += solve(pos + 1, bound && (digit == s[pos] - '0'), false, mask, s,num*10+digit);

// 			/*
// 				if this particular has already come earlier in this digit, and it is not a leading zero, then clearly, there is a repitition
// 				and we have to pass true in hasRepeated
// 			*/
// 			else if ((mask & (1 << digit))) ans += solve(pos + 1, bound && (digit == s[pos] - '0'), true, mask, s,num*10+digit);

// 			/*
// 				if this guy is coming for the first time, then hasRepeated will be whatever was for the previous guy
// 				and don't forget to switch on the bit corresponding to this digit in the mask
// 			*/
// 			else ans += solve(pos + 1, bound && (digit == s[pos] - '0'), hasRepeated, (mask | (1 << digit)), s,num*10+digit);

// 		}

// 		return  ans;

// 	}

// 	int numDupDigitsAtMostN(int n) {
// 		memset(dp, -1, sizeof(dp));
// 		string R = to_string(n);
// 		// return solve(0, true, false, false, 0, R);
// 		return solve(0, true, false, 0, R,0);
// 	}
// };

// 11 ;; 22 ;; 33 ;; 44 ;; 55 ;; 66 ;; 77 ;; 88 ;; 99 ;; 100 ;; 101 ;; 110 ;; 111 ;; 112 ;; 113 ;; 114 ;; 115 ;; 116 ;; 117 ;; 118 ;; 119 ;; 121 ;; 122 ;; 131 ;; 133 ;; 141 ;; 144 ;; 151 ;; 155 ;; 161 ;; 166 ;; 171 ;; 177 ;; 181 ;; 188 ;; 191 ;; 199 ;; 200 ;; 202 ;; 211 ;; 212 ;; 220 ;; 221 ;; 222 ;; 223 ;; 224 ;; 225 ;; 226 ;; 227 ;; 228 ;; 229 ;; 232 ;; 233 ;; 242 ;; 244 ;; 252 ;; 255 ;; 262 ;; 266 ;; 272 ;; 277 ;; 282 ;; 288 ;; 292 ;; 299 ;; 300 ;; 303 ;; 311 ;; 313 ;; 322 ;; 323 ;; 330 ;; 331 ;; 332 ;; 333 ;; 334 ;; 335 ;; 336 ;; 337 ;; 338 ;; 339 ;; 343 ;; 344 ;; 353 ;; 355 ;; 363 ;; 366 ;; 373 ;; 377 ;; 383 ;; 388 ;; 393 ;; 399 ;; 400 ;; 404 ;; 411 ;; 414 ;; 422 ;; 424 ;; 433 ;; 434 ;; 440 ;; 441 ;; 442 ;; 443 ;; 444 ;; 445 ;; 446 ;; 447 ;; 448 ;; 449 ;; 454 ;; 455 ;; 464 ;; 466 ;; 474 ;; 477 ;; 484 ;; 488 ;; 494 ;; 499 ;; 500 ;; 505 ;; 511 ;; 515 ;; 522 ;; 525 ;; 533 ;; 535 ;; 544 ;; 545 ;; 550 ;; 551 ;; 552 ;; 553 ;; 554 ;; 555 ;; 556 ;; 557 ;; 558 ;; 559 ;; 565 ;; 566 ;; 575 ;; 5...