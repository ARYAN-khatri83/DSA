// BASIC APPROACH WOULD BE USE ANY SORTING TECHNIQUE

// MEDIUM 
// WE CAN COUNT THE NUMBERS AND THEN USE THEM TO PLACE AGIAN IN THE ARRAY ACC TO THEIR COUNT VALUES TC-O(N) * O(N) SC - O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_0 = 0 ;
        int cnt_1 = 0 ;
        int cnt_2 = 0 ;


        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0) cnt_0++;
            else if(nums[i]== 1) cnt_1++;
            else cnt_2 ++;
        }

        for(int i = 0; i<cnt_0;i++){
            nums[i]=0;
        }
        for(int i = cnt_0 ; i<cnt_0+cnt_1;i++){
            nums[i]=1;
        }
        for(int i = cnt_0+cnt_1 ; i<cnt_0+cnt_1+cnt_2;i++){
            nums[i]=2;
        }
    }
};


// optimal
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low =0, mid =0, high = n-1;

        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid ++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high --;
            }
        }

    }
};
