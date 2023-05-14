<?php

class Solution
{
    /**
     * @param String $s
     * @return String
     */
    function longestPalindrome($s)
    {
        $slen = strlen($s);
        $max = $s[0];
        $maxlen = 1;

        for ($i = 0; $i < $slen; $i++) {
            $maxspread = floor(($maxlen + 1) / 2);
            while ($i - $maxspread >= 0 && $i + $maxspread < $slen) {
                $current = substr($s, $i - $maxspread, 2 * $maxspread + 1);
                if ($this->isPalindrome($current)) {
                    $max = $current;
                    $maxlen = 2 * $maxspread + 1;
                    $maxspread++;
                } else {
                    break;
                }
            }
            $maxspread = floor($maxlen / 2);
            while ($i - $maxspread >= 0 && $i + 1 + $maxspread < $slen) {
                $current = substr($s, $i - $maxspread, 2 * $maxspread + 2);
                if ($this->isPalindrome($current)) {
                    $max = $current;
                    $maxlen = 2 * $maxspread + 2;
                    $maxspread++;
                } else {
                    break;
                }
            }
        }

        return $max;
    }

    function isPalindrome($s)
    {
        return $s == strrev($s);
    }
}
