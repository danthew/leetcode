int reverse(int x){
    //find out whether we have to multiply by -1 at the end, make x absolute
    int factor = 1;
    if(x < 0) factor = -1;

    //negative max can't be converted to a positive
    if(x == -pow(2, 31)) return 0;
    x = abs(x);

    //find the length of x, ignoring any trailing 0's
    //len = -1 because we treat powers like lengths 0,1,2,..., as 10^0 = 1, aka the ones place in digits
    int len = -1;
    int x2 = x;
    int mod = 0;
    while(x2 > 0){
        mod = x2 % 10;
        //if either we have a remainder OR the next division is not 0 (we have another digit), we count the digit,
        //even if it IS a zero
        if(mod != 0 || (x2 / 10) != 0) len++;
        x2 /= 10;
    }

    //if our number runs the risk of exceeding the max upon reversal
    if(len >= 9){
        //check each digit against each digit of the max
        //if ANY of the number's corresponding digits is greater, the reverse will be too big. return 0
        //if ANY of the number's corresponding digits is lesser, then the number fits. break from loop
        int MAX[10] = {2,1,4,7,4,8,3,6,4,8};
        int x3 = x;
        for(int i = 0; i < 10; i++){
            if(x3 % 10 > MAX[i]) return 0;
            else if(x3 % 10 < MAX[i]) break;
            x3 /= 10;
        }
    }

    //return int
    int reverse = 0;
    while(x > 0){
        int place = x % 10;
        //if we have a remainder, add it into our return int with its corresponding power of 10
        if(place!=0){
            place *= pow(10, len);
            reverse += place;
        }
        //decrease the power of 10 from our int length
        len--;
        x /= 10;
    }

    //multiply reverse by our original +/- factor
    reverse *= factor;

    //if our number was so big that it wrapped around and changed factors, return 0
    if((factor == 1 && reverse < 0) || (factor == -1 && reverse > 0)) return 0;

    //return as either positive or negative
    return reverse;
}