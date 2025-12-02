class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long long temp = x;
        long long rev = 0;

        while (x > 0) {
            int lastDig = x % 10;
            rev = rev * 10 + lastDig;
            x /= 10;
        }
        return temp == rev;
    }
};
