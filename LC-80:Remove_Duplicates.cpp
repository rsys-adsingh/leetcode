#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to remove duplicates from sorted array
    // Allows at most 2 occurrences of each element
    // Returns the new length of the array after removing excess duplicates
    int removeDuplicates(vector<int>& nums) {
        // i keeps track of the position where we place valid elements
        int i = 0;
        
        // Iterate through each element in the array
        for(auto element : nums)
        {
            // Place element if:
            // 1. It's one of the first two positions (i==0 or i==1), OR
            // 2. Current element is different from the element two positions back (nums[i-2])
            //    This ensures we keep at most 2 duplicates
            if(i == 0 || i == 1 || nums[i-2] != element)
            {
                nums[i] = element;  // Place the element at position i
                i++;                 // Move to next position
            }
            // If element appears more than twice consecutively, skip it
        }
        
        // Return the length of array with at most 2 duplicates
        return i;
    }
};

int main() {
    Solution solution;
    
    // Get the size of the array from user
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    // Input validation
    if(n <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }
    
    // Create vector and get input from user
    vector<int> nums(n);
    cout << "Enter " << n << " sorted elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Call the removeDuplicates function
    int newLength = solution.removeDuplicates(nums);
    
    // Display the result
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for(int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}

