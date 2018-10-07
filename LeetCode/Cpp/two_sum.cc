class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int, int> nums_map;
        for (int i = 0; i < nums.size(); ++i)
            nums_map.insert(make_pair(nums[i], i));

        vector<int> temp;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == (target - nums[i]))
                if (nums_map.count(target - nums[i]) != 1) {
                    auto range = nums_map.equal_range(nums[i]);
                    temp.emplace_back((range.first++)->second);
                    temp.emplace_back(range.first->second);
                    break;
                }

            auto iter = nums_map.find(target - nums[i]);
            if (iter != nums_map.end() && iter != nums_map.find(nums[i])) {
                temp.emplace_back(i);
                temp.emplace_back(iter->second);
                break;
            }
        }

        return temp;
    }
};
