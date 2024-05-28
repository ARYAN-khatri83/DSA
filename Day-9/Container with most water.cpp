class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left_pointer = 0;
        int right_pointer = n - 1;
        int max_area = 0;

        while (left_pointer < right_pointer) {
            int height_of_left_pointer = height[left_pointer];
            int height_of_right_pointer = height[right_pointer];

            int min_height = min(height_of_left_pointer, height_of_right_pointer);
            int length = right_pointer - left_pointer;

            int curr_area = min_height * length;

            max_area = max(max_area, curr_area);

            if (height_of_left_pointer < height_of_right_pointer)
                left_pointer++;
            else
                right_pointer--;
        }

        return max_area;
    }
};
