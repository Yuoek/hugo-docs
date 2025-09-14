---
title: "day_0056 "
date: 2025-09-14T09:51:14+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0056 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = []
        st, ed = intervals[0]
        for s, e in intervals[1:]:
            if ed < s:
                ans.append([st, ed])
                st, ed = s, e
            else:
                ed = max(ed, e)
        ans.append([st, ed])
        return ans 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], ed = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); ++i) {
            if (ed < intervals[i][0]) {
                ans.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            } else {
                ed = max(ed, intervals[i][1]);
            }
        }
        ans.push_back({st, ed});
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int st = intervals[0][0], ed = intervals[0][1];
        List<int[]> ans = new ArrayList<>();
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ed < s) {
                ans.add(new int[] {st, ed});
                st = s;
                ed = e;
            } else {
                ed = Math.max(ed, e);
            }
        }
        ans.add(new int[] {st, ed});
        return ans.toArray(new int[ans.size()][]);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0056  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()  # 首先对区间按起始点进行排序
        ans = []  # 初始化结果列表
        st, ed = intervals[0]  # 取第一个区间作为初始合并区间
        for s, e in intervals[1:]:  # 遍历剩余的所有区间
            if ed < s:  # 如果当前区间与合并区间无重叠
                ans.append([st, ed])  # 将合并区间加入结果
                st, ed = s, e  # 重置合并区间为当前区间
            else:  # 如果存在重叠
                ed = max(ed, e)  # 扩展合并区间的结束点为较大值
        ans.append([st, ed])  # 将最后一个合并区间加入结果
        return ans  # 返回合并后的区间列表
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int st = intervals[0][0], ed = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < intervals.size(); ++i) {
            if (ed < intervals[i][0]) {
                ans.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            } else {
                ed = max(ed, intervals[i][1]);
            }
        }
        ans.push_back({st, ed});
        return ans;
    }
}; 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int st = intervals[0][0], ed = intervals[0][1];
        List<int[]> ans = new ArrayList<>();
        for (int i = 1; i < intervals.length; ++i) {
            int s = intervals[i][0], e = intervals[i][1];
            if (ed < s) {
                ans.add(new int[] {st, ed});
                st = s;
                ed = e;
            } else {
                ed = Math.max(ed, e);
            }
        }
        ans.add(new int[] {st, ed});
        return ans.toArray(new int[ans.size()][]);
    }
} 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0056  数学解释

```python 
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = []
        st, ed = intervals[0]
        for s, e in intervals[1:]:
            if ed < s:
                ans.append([st, ed])
                st, ed = s, e
            else:
                ed = max(ed, e)
        ans.append([st, ed])
        return ans 
```


这段代码使用了**贪心算法**和**排序**的数学思想来解决区间合并问题：

## 核心数学思想

### 1. 排序预处理
- 首先对所有区间按起始点排序，确保区间按起始时间有序排列
- 这是贪心算法的基础，使得我们可以按顺序处理区间

### 2. 贪心选择
- 维护当前合并区间 `[st, ed]`
- 遍历每个区间时，如果当前区间的结束时间 `ed` 小于下一个区间的开始时间 `s`：
  - 说明两个区间不重叠，将当前合并区间加入结果
  - 重置当前合并区间为下一个区间
- 否则（有重叠）：
  - 扩展当前合并区间的结束时间为 `max(ed, e)`（取最大值确保覆盖所有重叠区间）

### 3. 数学证明
- **最优子结构**：每个最优解都包含子问题的最优解
- **贪心选择性质**：每次选择局部最优（合并重叠区间）能得到全局最优解
- **无后效性**：当前决策不影响后续决策的正确性

## 算法正确性
通过排序确保区间有序，然后通过一次遍历合并所有重叠区间，时间复杂度为 O(nlogn)（主要来自排序），空间复杂度为 O(1)（不考虑输出空间）。

