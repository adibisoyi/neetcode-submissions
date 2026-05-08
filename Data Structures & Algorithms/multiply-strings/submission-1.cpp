class Solution {
public:
    string multiply(string num1, string num2) {
        long long n1= stol(num1);
        long long n2= stol(num2);

        long long res = n1*n2;

        return to_string(res);
    }
};
