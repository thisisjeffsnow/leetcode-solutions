<?php

/* Fast Method O(n) in PHP */

class Solution
{
    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target)
    {
        $known_nums = [];

        for ($i = 0; $i < count($nums); $i++) {
            $num = $nums[$i];
            if (isset($known_nums[$target - $num])) {
                return [$i, $known_nums[$target - $num]];
            } else {
                $known_nums[$num] = $i;
            }
        }
    }
}
