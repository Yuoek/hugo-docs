---
title: "day_0074 "
date: 2025-09-14T08:50:22+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0074 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        while left < right:
            mid = (left + right) >> 1
            x, y = divmod(mid, n)
            if matrix[x][y] >= target:
                right = mid
            else:
                left = mid + 1
        return matrix[left // n][left % n] == target 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left < right) {
            int mid = left + right >> 1;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return matrix[left / n][left % n] == target;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return matrix[left / n][left % n] == target;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0074  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])  # 获取矩阵的行数m和列数n
        left, right = 0, m * n - 1  # 将二维矩阵视为一维数组，设置二分查找的左右边界
        while left < right:  # 当左边界小于右边界时循环
            mid = (left + right) >> 1  # 计算中间位置，使用位运算右移1位相当于除以2
            x, y = divmod(mid, n)  # 将一维索引mid转换为二维坐标(x,y)
            if matrix[x][y] >= target:  # 如果中间值大于等于目标值
                right = mid  # 将右边界移动到中间位置
            else:
                left = mid + 1  # 否则将左边界移动到中间位置+1
        return matrix[left // n][left % n] == target  # 最终检查找到的位置是否等于目标值
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left < right) {
            int mid = left + right >> 1;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return matrix[left / n][left % n] == target;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;
        int left = 0, right = m * n - 1;
        while (left < right) {
            int mid = (left + right) >> 1;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return matrix[left / n][left % n] == target;
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0074  数学解释

```python 
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        while left < right:
            mid = (left + right) >> 1
            x, y = divmod(mid, n)
            if matrix[x][y] >= target:
                right = mid
            else:
                left = mid + 1
        return matrix[left // n][left % n] == target 
```


这段代码使用了**二分查找**的数学思想，具体体现在：

## 核心数学思想：**降维映射**

### 1. 二维到一维的线性映射
将二维矩阵视为一个有序的一维数组：
- 总元素数量：`m × n`
- 索引映射：`index = row × n + column`
- 逆映射：`row = index // n`, `column = index % n`

### 2. 二分查找的数学原理
- **单调性保证**：矩阵按行升序排列，且每行的第一个整数大于前一行的最后一个整数
- **搜索空间**：`[0, m×n-1]` 的整数区间
- **终止条件**：`left == right` 时找到唯一候选位置

### 3. 数学运算细节
- `>> 1`：等价于 `// 2`，使用位运算优化除法
- `divmod(mid, n)`：同时计算行号和列号的数学运算
- 最终验证：`matrix[left//n][left%n] == target` 确认是否找到目标

### 4. 时间复杂度分析
- **O(log(m×n))**：标准的二分查找对数时间复杂度
- 空间复杂度：**O(1)**：仅使用常数个变量

这种解法巧妙地将二维搜索问题转化为经典的一维二分查找问题，体现了**数学映射思想**在算法设计中的重要作用。


