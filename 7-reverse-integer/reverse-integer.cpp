class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while(x!=0){
            int lastDig = x%10;
            rev = rev*10 + lastDig;
            x /= 10;

            // check for overflow condition
            if(rev<INT_MIN || rev> INT_MAX){
                return 0;
            }
        }
        return rev;
    }
};