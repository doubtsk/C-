#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。*/
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    for (int i = 0; i < n; ++i)
    {
        nums1[m + i] = nums2[i];
    }
    std::sort(nums1.begin(), nums1.end());
}
/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。*/
class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int i = 0;
        for (int n : nums)
            if (n != val)
            {
                nums[i] = n;
                i++;
            }
        return i;
    }
};

/*给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。*/
class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[j] != nums[i])
            {
                nums[++j] = nums[i];
            }
        }
        return ++j;
    }
};

/*给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。*/
class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        std::vector<int>::iterator itor = nums.begin();
        while (itor != nums.end())
        {
            if ((itor + 2) < nums.end() && *itor == *(itor + 2))
            {
                itor = nums.erase(itor);
            }
            else
            {
                itor++;
            }
        }
        return nums.size();
    }
};

/*给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。*/

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        std::unordered_map<int, int> freqMap;
        int n = nums.size();
        for (int num : nums)
        {
            freqMap[num]++;
            if (freqMap[num] > n / 2)
            {
                return num;
            }
        }
        return -1;
    }
};

/*给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。*/

void reverse(vector<int> &nums, int begin, int end)
{
    while (begin < end)
    {
        swap(nums[begin++], nums[end--]);
    }
}
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size(); // 防止循环多轮
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};

/*给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minprice = INT_MAX;
        int maxprofit = 0;
        for (int num : prices)
        {
            minprice = min(minprice, num);
            maxprofit = max(maxprofit, num - minprice);
        }
        return maxprofit;
    }
};
