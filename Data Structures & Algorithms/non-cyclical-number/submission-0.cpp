class Solution {
public:
    bool isHappy(int n) {
        int slow=n;
        int fast=helper(n);

        while(slow != fast)
        {
            fast = helper(fast);
            fast = helper(fast);
            slow = helper(slow);
        }

        return fast==1;
    }
private:
    int helper(int n){
       int num=0;
       while(n)
       {
            num += (n%10)*(n%10);
            n=n/10;
       } 
       return num;
    }
};
