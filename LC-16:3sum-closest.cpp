#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    // Function to find the sum of three integers closest to the target
    // Time Complexity: O(n^2) where n is the size of the array
    // Space Complexity: O(1) excluding the space used for sorting
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to enable two-pointer approach
        // This allows us to efficiently search for triplets
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize gap to maximum value to track minimum difference
        // gap stores the absolute difference between current sum and target
        int gap = INT_MAX;
        // res stores the sum closest to target found so far
        int res = 0;
        
        // Iterate through array, fixing one element at a time
        // We stop at n-2 because we need at least 3 elements
        for(int i = 0; i < n-2; i++){
            // Initialize two pointers for the remaining subarray
            int left = i + 1;      // Start from element after current
            int right = n - 1;     // Start from last element
            
            // Use two-pointer technique to find best pair for current element
            while(left < right){
                // Calculate sum of current triplet
                int sum = nums[i] + nums[left] + nums[right];
                
                // If sum is less than target, we need larger values
                if(sum < target){
                    // Check if this sum is closer to target than previous best
                    if(target - sum < gap){
                        gap = target - sum;  // Update minimum gap
                        res = sum;           // Update result
                    }
                    left++;  // Move left pointer right to increase sum
                }
                // If sum is greater than target, we need smaller values
                else if(sum > target){
                    // Check if this sum is closer to target than previous best
                    if(sum - target < gap){
                        gap = sum - target;  // Update minimum gap
                        res = sum;           // Update result
                    }
                    right--;  // Move right pointer left to decrease sum
                }
                // If sum equals target, we found the exact match
                else{
                    return target;  // Can't get closer than exact match
                }
            }
        }
        // Return the closest sum found
        return res;
    }
};

int main() {
    // Create Solution object
    Solution solution;
    
    // Get size of array from user
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    // Validate input size (need at least 3 elements)
    if(n < 3) {
        cout << "Array must have at least 3 elements!" << endl;
        return 1;
    }
    
    // Read array elements from user
    vector<int> nums(n);
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Get target value from user
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    
    // Call the function and get result
    int result = solution.threeSumClosest(nums, target);
    
    // Display the result
    cout << "The sum of three integers closest to " << target << " is: " << result << endl;
    
    return 0;
}
