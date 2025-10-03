---
title: "day_0057 "
date: 2025-09-14T09:49:17+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0057 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        def merge(intervals: List[List[int]]) -> List[List[int]]:
            intervals.sort()
            ans = [intervals[0]]
            for s, e in intervals[1:]:
                if ans[-1][1] < s:
                    ans.append([s, e])
                else:
                    ans[-1][1] = max(ans[-1][1], e)
            return ans

        intervals.append(newInterval)
        return merge(intervals) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int[][] newIntervals = new int[intervals.length + 1][2];
        for (int i = 0; i < intervals.length; ++i) {
            newIntervals[i] = intervals[i];
        }
        newIntervals[intervals.length] = newInterval;
        return merge(newIntervals);
    }

    private int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> ans = new ArrayList<>();
        ans.add(intervals[0]);
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ans.get(ans.size() - 1)[1] < s) {
                ans.add(intervals[i]);
            } else {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], e);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0057  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        def merge(intervals: List[List[int]]) -> List[List[int]]:  # 定义合并区间的辅助函数
            intervals.sort()  # 首先对区间按起始点进行排序
            ans = [intervals[0]]  # 初始化结果列表，放入第一个区间
            for s, e in intervals[1:]:  # 遍历剩余的区间
                if ans[-1][1] < s:  # 如果当前区间与前一个区间不重叠
                    ans.append([s, e])  # 直接添加到结果中
                else:  # 如果存在重叠
                    ans[-1][1] = max(ans[-1][1], e)  # 合并区间，取最大的结束点
            return ans  # 返回合并后的区间列表

        intervals.append(newInterval)  # 将新区间添加到原区间列表中
        return merge(intervals)  # 调用合并函数处理所有区间
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (ans.back()[1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int[][] newIntervals = new int[intervals.length + 1][2];
        for (int i = 0; i < intervals.length; ++i) {
            newIntervals[i] = intervals[i];
        }
        newIntervals[intervals.length] = newInterval;
        return merge(newIntervals);
    }

    private int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        List<int[]> ans = new ArrayList<>();
        ans.add(intervals[0]);
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ans.get(ans.size() - 1)[1] < s) {
                ans.add(intervals[i]);
            } else {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], e);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0057  数学解释

```python 
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        def merge(intervals: List[List[int]]) -> List[List[int]]:
            intervals.sort()
            ans = [intervals[0]]
            for s, e in intervals[1:]:
                if ans[-1][1] < s:
                    ans.append([s, e])
                else:
                    ans[-1][1] = max(ans[-1][1], e)
            return ans

        intervals.append(newInterval)
        return merge(intervals) 
```


这段代码使用了**贪心算法**和**排序**的数学思想来解决区间插入问题：

## 核心数学思想

### 1. 贪心算法思想
- **局部最优选择**：每次处理当前区间时，只考虑与最后一个合并区间的重叠关系
- **全局最优解**：通过局部最优的合并操作，最终得到所有不重叠的区间

### 2. 排序预处理
- 首先对所有区间按**起始点升序排序**，这是贪心算法能够正确工作的前提
- 排序后，区间按起始位置有序排列，便于后续的合并操作

### 3. 区间合并的数学逻辑
对于排序后的区间序列：
- 如果当前区间 `[s, e]` 与结果列表中最后一个区间 `ans[-1]` **不重叠**（即 `ans[-1][1] < s`）
  - 直接将当前区间加入结果
- 如果**重叠**（即 `ans[-1][1] >= s`）
  - 合并区间：取两个区间结束点的最大值 `max(ans[-1][1], e)`

### 4. 时间复杂度分析
- 排序：O(n log n)
- 线性扫描合并：O(n)
- 总体时间复杂度：O(n log n)

这种解法体现了**通过排序将问题结构化，然后使用贪心策略进行线性处理**的经典算法设计模式。

