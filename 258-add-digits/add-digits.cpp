class Solution {
public:

    int sumOfDig(int num){
        int sum = 0;
        while(num>0){
            int lastDig = num%10;
            sum+=lastDig;
            num /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>9){
            int sum = sumOfDig(num);
            num = sum;
        }
        return num;
    }
};