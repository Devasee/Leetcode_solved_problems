class Solution {
public:
    vector<pair<int, int>> findXFreqElements(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int n : nums)
            freq[n]++;

        vector<pair<int, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
        if (a.second == b.second)
            return a.first > b.first;  // break ties by value
        return a.second > b.second;
        });

        return vec;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;

        if (k > nums.size()) return {};
        int times = nums.size() - k + 1;


        for(int i=0; i<times; i++)
        {
            vector<int> v(nums.begin() + i, nums.begin() + i + k);
            vector<pair<int, int>> r2 = findXFreqElements(v);
            int sum = 0;

            for (int j = 0; j < min(x, (int)r2.size()); j++)
            {
                sum += r2[j].first*r2[j].second;
            }

            result.push_back(sum);
        }

        return result;
    }
};