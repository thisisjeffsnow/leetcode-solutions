bool isPalindrome(char* s, int start, int end) {
    for(int i = 0; i + start <= (start + end)/2; i++) {
        if(s[i + start] != s[end - i]) {return 0;}
    }
    return 1;
}


char * longestPalindrome(char * s){
    int slen = 0;

    while(s[slen] != '\0') {slen++;}
    if(slen < 2 || isPalindrome(s, 0, slen - 1)) {return s;}
    
    int maxstart = 0;
    int maxlen = 1;
    int maxspread;
    int i;
    
    
    for(i = 0; i < slen; i++) {
        maxspread = (maxlen + 1)/2;
        while(i - maxspread >= 0 && i + maxspread < slen) {
            if(isPalindrome(s, i - maxspread, i + maxspread)) {
                maxstart = i - maxspread;
                maxlen = 2*maxspread + 1;
                maxspread++;
            } else {break;}
        }
        maxspread = maxlen/2;
        while(i - maxspread >= 0 && i + 1 + maxspread < slen) {
            if(isPalindrome(s, i - maxspread, i + maxspread + 1)) {
                maxstart = i - maxspread;
                maxlen = 2*maxspread + 2;
                maxspread++;
            } else {break;}
        }        
    }
    
    char* answer = (char*) calloc(slen, sizeof(char));

    for(i = maxstart; i < maxstart + maxlen; i++) {
        answer[i - maxstart] = s[i];
    }
    
    
    return answer;
}