class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        if(n==0)
            return 1;

        double num =1;
        for(int i=0;i<abs(n);i++)
        {
            num *= x;
        }

        return n>=0 ? num : 1/num;
    }
};
