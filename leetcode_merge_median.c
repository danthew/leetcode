double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){

    if(nums1Size + nums2Size == 1){
        if(nums1Size == 1) return nums1[0];
        else return nums2[0];
    }

    //int* merged = mergeSort(int* nums1, int nums1Size, int* nums2, int nums2Size);
    //merge the arraye. typically would go in another function, but this IDE is weird
    int* merged;
    //allocate memory for a merged array (sizes are added)
    merged = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    //indices for nums1, nums2, and merged
    int a = 0, b = 0, c = 0;
    //the condition in this while is more or less irrelevant except for base case when a,b = 0
    while(a < nums1Size || b < nums2Size){
        //if a has gotten too big, add the rest of b in and break
        if(a >= nums1Size){
            while(b < nums2Size){
                merged[c] = nums2[b];
                b++, c++;
            }
            break;
        }
        //if b has gotten too big, add the rest of a in and break
        else if(b >= nums2Size){
            while(a < nums1Size){
                merged[c] = nums1[a];
                a++, c++;
            }
            break;
        }
        //if nums1's value is less than nums2's, it goes first; only increment when you use a number from an array
        if(nums1[a] <= nums2[b]){
            merged[c] = nums1[a];
            a++;
        }
        //if nums2's value is less than nums1's, it goes first
        else{
            merged[c] = nums2[b];
            b++;
        }
        //always iterate past where we just added in merged
        c++;
    }
    //DONE WITH MERGING

    //get the median index
    float mid_dex = (nums1Size + nums2Size)/2.0;
    //determine if median index is a whole number
    float remainder = mid_dex - (int)mid_dex;
    //return value
    double r_val = 0.0;
    //if we have a whole number, we have an even length, so we need the average of the two indices' values
    if(remainder == 0){
        r_val = (merged[(int)mid_dex] + merged[(int)mid_dex-1])/2.0;
    }
    //otherwise, odd length; just get the value at the index
    else{
        r_val = merged[(int)mid_dex];
    }
    //free our DAM and return
    free(merged);
    return r_val;
}