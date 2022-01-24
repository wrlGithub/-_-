# -_-
C++实现
from https://leetcode-cn.com/

题目一：（704）https://leetcode-cn.com/problems/binary-search/
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9     
输出: 4       
解释: 9 出现在 nums 中并且下标为 4     
示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2     
输出: -1        
解释: 2 不存在 nums 中因此返回 -1        
提示：
	• 你可以假设 nums 中的所有元素是不重复的。
	• n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。![image](https://user-images.githubusercontent.com/85392473/150714515-82948118-9fa2-4a2f-a9db-0833e9bee9dd.png)

题解：
这里考虑闭区间的做法：
因为定义target在[left, right]区间，所以有如下两点：
·while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=
·if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1
int binarySeach(vector<int>& num,int target){
    int left = 0;
    int right = num.size() - 1;
    while (left <= right)
    {   
        // int middle = (left+right)/2;
        int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
        if( num[middle] >target){
            right = middle-1;
        }else if(num[middle]<target){
            left = middle+1;
        }else{
            return middle;
        }
    }
    return -1;
}




