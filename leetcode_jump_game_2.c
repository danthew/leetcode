int jump(int* nums, int numsSize){
    //if we are at the end of our array, we don't jump
    if(numsSize == 1) return 0;

    //ints for the number of jumps we made in our current recursion and for the fewest jumps we make in any path
    //initialize min_jumps as the max number of jumps we can make, AKA the size of the array
    int jumps = 0, min_jumps = numsSize-1;

    //int for the length of the jump from our space
    int len = nums[0];
    if(len == 0) return -1;

    //if you KNOW you can get to the end within one jump just return one
    if(len >= numsSize-1) return 1;

    int max_jump = 0;
    int a = 0;
    for(int i = len; i > 0; i--){
        //don't jump to a 0 in the first place
        if(nums[i] == 0 && i != numsSize-1) continue;

        if(nums[i] + i >= numsSize - 1) return 2;

        if(nums[i] + i > max_jump){
            max_jump = nums[i] + i;
            a = i;
        }
    }

    int* rNums;
    rNums = (int*)malloc(sizeof(int)*(numsSize-a));
    for(int j = 0; j < numsSize-a; j++){
        rNums[j] = nums[j+a];
    }

    //recursive jump plus the smallest of the next series of jumps
    //if jump len is -1, then we landed on a 0, so we dont consider it
    int jump_len = jump(rNums, numsSize-a);
    if(jump_len != -1){
        jumps = 1 + jump_len;
    }

    //if these jumps are smaller than the previous smallest, update
    //OR if the jumps are equivalent (check both paths, as either could be shorter)
    if(jumps <= min_jumps){
        min_jumps = jumps;
    }

    //free the array we made
    free(rNums);

    //return the fewest number of jumps
    return min_jumps;
}