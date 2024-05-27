// WE CAN USE SORTING AND THEN CHECK IF THERE IS ANY REPEATABLE NUMBER AND SECOND METHOD IS RUN TWO LOOPS AND CHECK IF THERE IS 
// ANY CHECK THAT MATCHES ANY NUMBER . BUT BOTH TLE





class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen; // DECLARATION OF MAP
        for (int num : nums) {        // TRAVERSING AN UNORDERED MAP
            if (seen[num] >= 1)
                return true;
            seen[num]++;
        }
        return false;
    }
};
