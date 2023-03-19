/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    
    const len = s.length;
    if(len < 2) {return len;}
    
    var maxstring = "";
    var maxlen = 1;
    var curstring = "";
    var curlen = 0;
    
    var a = 0;
    for(var b = 0; b < len; b++) {
        var char = s[b];
        
        if(!curstring.includes(char)) {
            curstring = curstring.concat(char);
            curlen++;
        } else {
            if(curlen > maxlen) {
                maxstring = curstring;
                maxlen = curlen;
            }
            curstring = curstring.concat(char);
            a = s.indexOf(char, a) + 1;
            curstring = curstring.substring(curstring.indexOf(char) + 1);            
            curlen = curstring.length;
        }
    }
    return Math.max(curlen, maxlen);
    
};