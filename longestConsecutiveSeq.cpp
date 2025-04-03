class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> seq_map;
        int maxLength = 0;

        for (int num : nums) {
            if (seq_map.find(num) == seq_map.end()) {  
                int left = seq_map.count(num - 1) ? seq_map[num - 1] : 0;
                int right = seq_map.count(num + 1) ? seq_map[num + 1] : 0;

                int seqLength = left + 1 + right; 

                seq_map[num] = seqLength;
                seq_map[num - left] = seqLength;
                seq_map[num + right] = seqLength;

                maxLength = std::max(maxLength, seqLength);
            }
        }

        return maxLength;
    }
};
