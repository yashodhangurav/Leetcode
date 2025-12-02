class Solution {
public:
    int fib(int n) {

        if(n == 0) return 0;
        if(n == 1) return 1;
        
         int answer = 0, p1 = 0, p2 = 1;
          for(int i =2; i<=n; i++){       
            answer = p1+p2;
            p1 = p2;
            p2 = answer;
        }
        
        return answer;
    }
};