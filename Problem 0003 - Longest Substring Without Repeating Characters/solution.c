int strpos(char* s, char n, int stop) {
    for(int i = 0; i < stop; i++) {
      if(n == s[i]) {return i;}
    }
    return -1;
}


int lengthOfLongestSubstring(char * s){
    
    // figure out how long s is.
    int slen = 0;
    while(s[slen] != '\0') {slen++;}
    
    // make a workspace equal to that length.
    int bestlen = 0, currlen = 0;
    char* workspace = (char*)calloc(slen, sizeof(char));
    
    for(int i = 0; i < slen; i++) {
        char c = s[i];
        // check the current char c in s for its existence in workspace
        
        // if it's already in the workspace before the max length then..
        int cpos = strpos(workspace, c, currlen);
        if(cpos != -1)  {
            // compare length of current workspace to best we have seen
            bestlen = (currlen > bestlen) ? currlen : bestlen;
            
            // update workspace to only have the substring past the first occurence of c
            for(int j = cpos + 1; j < currlen; j++) {
                workspace[j - cpos - 1] = workspace[j];
            }
            currlen -= cpos + 1;
        }
        workspace[currlen] = c;
        currlen++;
    }
    free(workspace);
    bestlen = (currlen > bestlen) ? currlen : bestlen;
    return bestlen;
}
