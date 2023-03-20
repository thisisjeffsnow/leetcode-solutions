<?php

class Solution {

    /**
     * @param String $s
     * @param Integer $numRows
     * @return String
     */
    function convert($s, $numRows) {
        
        if($numRows == 1) {return $s;}
        
        $rows = array();
        for($i = 0; $i < $numRows; $i++) {
            $rows[$i] = "";
        }
        
        for($i = 0; $i < strlen($s); $i++) {
            $j = $i % (2*$numRows - 2);
            if($j < $numRows) {$rows[$j] .= $s[$i];}
            else {$rows[2*$numRows - 2 - $j] .= $s[$i];}
        }
        return implode("", $rows);
    }
}