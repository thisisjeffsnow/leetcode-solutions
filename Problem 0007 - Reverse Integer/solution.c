int reverse(int x){

    // Create a variable reserved to store the result.
    int reversed = 0;

    /* Pull the right most digit from x one-by-one and append it to the right of
       the current value in reversed */
    while(x) {

        /* Before appending, if reversed is below INT_MIN/10 or above
           INT_MAX/10, then return 0. Otherwise, appending will put the reversed
           outside of the 32-bit range. */
        if(INT_MAX/10 < reversed || reversed < INT_MIN/10) {
            return 0;
        }

        /* The operation to remove the right most digit is modular division by
           10. To 'attach' a digit, multiply the current value by 10 and then
           add the digit. */
        reversed = 10*reversed + (x % 10);
        x /= 10;
    }

    return reversed;
}