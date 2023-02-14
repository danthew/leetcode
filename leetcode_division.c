int divide(int dividend, int divisor){
    int quotient = 0;
    int factor;
    if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) factor = 1;
    else factor = -1;

    if(divisor == pow(-2,31)){
        if(dividend == pow(-2,31)) return 1;
        else return 0;
    }
    divisor = abs(divisor);

    if(dividend == pow(-2,31)){
        dividend += divisor;
        quotient++;
    }
    dividend = abs(dividend);

    int MAX = pow(2,31) - 1;

    while(dividend >= divisor && quotient < MAX){
        dividend -= divisor;
        quotient++;
    }
    if(quotient == MAX){
        if(factor == -1){
            if(dividend <= divisor){
                quotient *= -1;
                quotient--;
                return quotient;
            }
            else return quotient *= -1;
        }
        else return quotient;
    }
    return quotient * factor;
}