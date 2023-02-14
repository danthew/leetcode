int removeDuplicates(int* nums, int numsSize){
    int k = 1, cur = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(cur == nums[i]){
            while(cur == nums[i] && i < numsSize-1) i++;
            if(i < numsSize && cur != nums[i]){
                nums[k] = nums[i];
                k++;
            }
        }
        else{
            nums[k] = nums[i];
            k++;
        }
        cur = nums[i];
    }
    return k;
}