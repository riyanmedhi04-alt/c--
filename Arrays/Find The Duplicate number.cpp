class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];
        bool flag = true;
        // first phase -> we will find the meeting point because the fast pointer gets into a loop and eventually meet at a common entrance and that entrance is the entry point to the loop !! so when in second phase we move the slow pointr they will eventually meet at the repeating element!
        // first phase ->
        while(flag || slow != fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
            flag = false;
        }
        // found the entrance now moving for the second phase! but before taht set slow to nums[0] again
        slow = nums[0];
        // second phase ->
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast]; // now they will move at same pace.
        }
        return slow;
    }
};
