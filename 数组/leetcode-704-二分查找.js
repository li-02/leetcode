/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
let search = function(nums, target) {
    let left=0,right=nums.length-1;
    let mid;
    while(left<=right){
        // 加法优先级高于>> ,防止溢出
        mid=left+((right-left)>>1);
        if(nums[mid]>target){
            right=mid-1;
        }else if(nums[mid]<target){
            left=mid+1;
        }else{
            return mid;
        }
    }
    return -1;
};
