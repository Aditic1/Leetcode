class Solution {
public:
    long long modulo = 1e9 + 7;

    
    int concatenatedBinary(int n) {
        /*
            Let's take n = 2;
            already, value/answer = 1 (due to n = 1), number of digits in i = 2

            start from 2 -> i
                for a particular i, say 2, no of digits = 2
                So when 2 is concatenated in binary string format, 2 bits are added to the right => our current value/answer left shifts by 2, where 2 is no of digits. - 110 => value >> k + i => 6

                Similarly, for 3, no of digits = 2, 
                6 >> 2 + 3 => 11000 + 3 -> 27

                For 4, "11011" + "100" => when i is a power of 2, increase the digits count
        */

        long long answer = 0;
        int digits = 0;

        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                digits++;
            }
            answer = ((answer << digits) % modulo + i) % modulo;
        }
        return answer;
    }
};