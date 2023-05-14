class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> response = {};
        unordered_map<int, int> stack{};
        
        int index = 0;
        for(auto it = nums.begin(); it != nums.end(); ++it) {
            int find = target - *it;
            
            auto found = stack.find(find);
            if(found != stack.end()) {
                response = {found->second, index};
                return response;
            }
            
            stack.insert({*it, index});
            
            index++;
            
        }
        
        
        return response;
    }
};