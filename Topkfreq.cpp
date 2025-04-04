class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        priority_queue<pair<int, int>> maxHeap;

        for (auto& it : freqMap) {
            maxHeap.push({it.second, it.first}); 
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top().second); 
            maxHeap.pop();
        }

        return result;
    }
};
