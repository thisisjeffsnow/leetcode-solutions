<?php

class Solution
{
    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s)
    {
        // strings of 0 or 1 length are the longest possible already.
        $slen = strlen($s);
        if ($slen < 2) {
            return $slen;
        }

        // now string has at least 2 characters. sliding window.
        $maxstring = '';
        $maxlen = 0;
        $curstring = '';
        $curlen = 0;

        $a = 0;

        // Have two points, A, and B starting at the beginning of the string.
        // slide B forward, trying to add the next char to the current pile.
        // As long as that character doesn't exist in the pile, then the
        // extracted string is the longest so far.
        // If the char exists already, increment A so it's past the first instance
        // of that character and make a new pile from that unique string.

        for ($b = 0; $b < $slen; $b++) {
            $char = $s[$b];

            // add char and incremement length as long as it's unique to the current string.
            if (strpos($curstring, $char) === false) {
                $curstring .= $char;
                $curlen++;
            } else {
                // otherwise, check the pile against the best we've seen so far
                if ($curlen > $maxlen) {
                    $maxstring = $curstring;
                    $maxlen = $curlen;
                }

                // then add it anyway, but slide up A so that B is the only instance of that char.
                $curstring .= $char;
                $offset = 0;
                while ($s[$a] != $char) {
                    $a++;
                    $offset++;
                }
                $curstring = substr($curstring, $offset + 1);
                $curlen = strlen($curstring);
                $a++;
            }
        }
        return max($curlen, $maxlen);
    }
}
