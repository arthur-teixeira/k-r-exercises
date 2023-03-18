#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char []);

int main() {
    char s[100] = "2.9342723435e5";
    printf("%f\n", atof(s));
    return 0;
}

double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i=0; isspace(s[i]); i ++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0* val + (s[i] - '0');
        power *= 10;
    }
    double result = sign * val / power;

    double exp;
    int exp_sign;
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    exp_sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exp = 0.0; isdigit(s[i]); i++)
        exp = 10.0 * exp + (s[i] - '0');

    return result * pow(10, (exp * exp_sign));
}
