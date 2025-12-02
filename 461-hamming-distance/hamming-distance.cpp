class Solution {
public:

    int hammingDistance(int x, int y) {
            int count = 0;
        while(x!= 0 || y!=0){
            int bin1 = x%2;
            int bin2 = y%2;

            if(bin1 != bin2){
                count++;
            }
            x /= 2;
            y /= 2;
        }
        return count; 
    }
};