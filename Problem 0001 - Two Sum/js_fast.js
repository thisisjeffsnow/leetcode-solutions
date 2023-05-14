/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    
    let map = [];
    
    for(let i = 0; i < nums.length; i++) {
        let num = nums[i];
        if(map[target-num] != null) {
            return [i, map[target-num]];
        }
        map[num] = i;
    }
};