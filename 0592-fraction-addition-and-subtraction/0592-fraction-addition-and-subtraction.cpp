class Solution {
public:
    string fractionAddition(string expr) {
        int nume = 0;
        int deno = 1;

        int i = 0;
        int n = expr.length();
        while(i < n) {
            int currNume = 0;
            int currDeno = 0;

            bool isNeg = (expr[i] == '-');      //flag --> that i is negative or not.
            
            //agr initially + and - ho to skip krdo.
            if(expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            //Build the currNume
            while(i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currNume = (currNume*10) + val;
                i++;
            }

            i++; //numerator / denominator //skipiing the divisrio character '/'

            if(isNeg == true) {
                currNume *= -1;
            }

            //Build the currDeno
            while(i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

       
        int GCD = abs(__gcd(nume, deno)); 

        nume /= GCD;
        deno /= GCD;

        return to_string(nume) + "/" + to_string(deno); 
    }
};