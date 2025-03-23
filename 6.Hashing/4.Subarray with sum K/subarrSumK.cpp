#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countSubarraysWithSumK(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumFreq;
    int prefixSum = 0, count = 0;

    // Initialize with prefix sum 0 to handle cases where subarray starts from index 0
    prefixSumFreq[0] = 1;

    for (int num : nums) {
        prefixSum += num;

        // Check if (prefixSum - k) exists in the map
        if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end()) {
            count += prefixSumFreq[prefixSum - k]; // Add the count of such prefix sums
        }

        // Store the current prefix sum in the map
        prefixSumFreq[prefixSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1}; // Example array
    int k = 2;                    // Target sum
    cout << "Number of subarrays with sum " << k << ": " << countSubarraysWithSumK(nums, k) << endl;
    return 0;
}
