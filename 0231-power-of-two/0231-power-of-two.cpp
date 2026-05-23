class Solution {
public:
    bool f(int n, int i){

        if(pow(2, i) > n)
            return false;

        if(pow(2, i) == n)
            return true;

        return f(n, i + 1);
    }

    bool isPowerOfTwo(int n) {

        if(n <= 0)
            return false;

        return f(n, 0);
    }
};

