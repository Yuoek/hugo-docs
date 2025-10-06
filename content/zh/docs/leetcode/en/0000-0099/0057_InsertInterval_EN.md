---
title: "0057_InsertInterval"
date: 2025-10-06T00:42:37+08:00
weight: 0057
tags: [Array]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [57. Insert Interval](https://leetcode.com/problems/insert-interval)

[中文文档](/solution/0000-0099/0057.Insert%20Interval/README.md)

## Description

<!-- description:start -->

<p>You are given an array of non-overlapping intervals <code>intervals</code> where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> represent the start and the end of the <code>i<sup>th</sup></code> interval and <code>intervals</code> is sorted in ascending order by <code>start<sub>i</sub></code>. You are also given an interval <code>newInterval = [start, end]</code> that represents the start and end of another interval.</p>

<p>Insert <code>newInterval</code> into <code>intervals</code> such that <code>intervals</code> is still sorted in ascending order by <code>start<sub>i</sub></code> and <code>intervals</code> still does not have any overlapping intervals (merge overlapping intervals if necessary).</p>

<p>Return <code>intervals</code><em> after the insertion</em>.</p>

<p><strong>Note</strong> that you don&#39;t need to modify <code>intervals</code> in-place. You can make a new array and return it.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,3],[6,9]], newInterval = [2,5]
<strong>Output:</strong> [[1,5],[6,9]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
<strong>Output:</strong> [[1,2],[3,10],[12,16]]
<strong>Explanation:</strong> Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= intervals.length &lt;= 10<sup>4</sup></code></li>
	<li><code>intervals[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt;= end<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>intervals</code> is sorted by <code>start<sub>i</sub></code> in <strong>ascending</strong> order.</li>
	<li><code>newInterval.length == 2</code></li>
	<li><code>0 &lt;= start &lt;= end &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1: Sorting + Interval Merging

We can first add the new interval `newInterval` to the interval list `intervals`, and then merge according to the regular method of interval merging.

The time complexity is $O(n \times \log n)$, and the space complexity is $O(n)$. Here, $n$ is the number of intervals.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2: One-pass Traversal

We can traverse the interval list `intervals`, let the current interval be `interval`, and there are three situations for each interval:

-   The current interval is on the right side of the new interval, that is, $newInterval[1] < interval[0]$. At this time, if the new interval has not been added, then add the new interval to the answer, and then add the current interval to the answer.
-   The current interval is on the left side of the new interval, that is, $interval[1] < newInterval[0]$. At this time, add the current interval to the answer.
-   Otherwise, it means that the current interval and the new interval intersect. We take the minimum of the left endpoint of the current interval and the left endpoint of the new interval, and the maximum of the right endpoint of the current interval and the right endpoint of the new interval, as the left and right endpoints of the new interval, and then continue to traverse the interval list.

After the traversal, if the new interval has not been added, then add the new interval to the answer.

The time complexity is $O(n)$, where $n$ is the number of intervals. Ignoring the space consumption of the answer array, the space complexity is $O(1)$.

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### Rust



#### C#



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        st, ed = newInterval
        ans = []
        insert = False
        for s, e in intervals:
            if ed < s:
                if not insert:
                    ans.append([st, ed])
                    insert = True
                ans.append([s, e])
            elif e < st:
                ans.append([s, e])
            else:
                st = min(st, s)
                ed = max(ed, e)
        if not insert:
            ans.append([st, ed])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int st = newInterval[0], ed = newInterval[1];
        boolean insert = false;
        for (int[] interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.add(new int[] {st, ed});
                    insert = true;
                }
                ans.add(interval);
            } else if (e < st) {
                ans.add(interval);
            } else {
                st = Math.min(st, s);
                ed = Math.max(ed, e);
            }
        }
        if (!insert) {
            ans.add(new int[] {st, ed});
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int st = newInterval[0], ed = newInterval[1];
        bool insert = false;
        for (auto& interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.push_back({st, ed});
                    insert = true;
                }
                ans.push_back(interval);
            } else if (e < st) {
                ans.push_back(interval);
            } else {
                st = min(st, s);
                ed = max(ed, e);
            }
        }
        if (!insert) {
            ans.push_back({st, ed});
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func insert(intervals [][]int, newInterval []int) (ans [][]int) {
	st, ed := newInterval[0], newInterval[1]
	insert := false
	for _, interval := range intervals {
		s, e := interval[0], interval[1]
		if ed < s {
			if !insert {
				ans = append(ans, []int{st, ed})
				insert = true
			}
			ans = append(ans, interval)
		} else if e < st {
			ans = append(ans, interval)
		} else {
			st = min(st, s)
			ed = max(ed, e)
		}
	}
	if !insert {
		ans = append(ans, []int{st, ed})
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function insert(intervals: number[][], newInterval: number[]): number[][] {
    let [st, ed] = newInterval;
    const ans: number[][] = [];
    let insert = false;
    for (const [s, e] of intervals) {
        if (ed < s) {
            if (!insert) {
                ans.push([st, ed]);
                insert = true;
            }
            ans.push([s, e]);
        } else if (e < st) {
            ans.push([s, e]);
        } else {
            st = Math.min(st, s);
            ed = Math.max(ed, e);
        }
    }
    if (!insert) {
        ans.push([st, ed]);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>> {
        let mut inserted = false;
        let mut result = vec![];

        let (mut start, mut end) = (new_interval[0], new_interval[1]);
        for iter in intervals.iter() {
            let (cur_st, cur_ed) = (iter[0], iter[1]);
            if cur_ed < start {
                result.push(vec![cur_st, cur_ed]);
            } else if cur_st > end {
                if !inserted {
                    inserted = true;
                    result.push(vec![start, end]);
                }
                result.push(vec![cur_st, cur_ed]);
            } else {
                start = std::cmp::min(start, cur_st);
                end = std::cmp::max(end, cur_ed);
            }
        }

        if !inserted {
            result.push(vec![start, end]);
        }
        result
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        var ans = new List<int[]>();
        int st = newInterval[0], ed = newInterval[1];
        bool insert = false;
        foreach (var interval in intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.Add(new int[]{st, ed});
                    insert = true;
                }
                ans.Add(interval);
            } else if (st > e) {
                ans.Add(interval);
            } else {
                st = Math.Min(st, s);
                ed = Math.Max(ed, e);
            }
        }
        if (!insert) {
            ans.Add(new int[]{st, ed});
        }
        return ans.ToArray();
    }
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        st, ed = newInterval
        ans = []
        insert = False
        for s, e in intervals:
            if ed < s:
                if not insert:
                    ans.append([st, ed])
                    insert = True
                ans.append([s, e])
            elif e < st:
                ans.append([s, e])
            else:
                st = min(st, s)
                ed = max(ed, e)
        if not insert:
            ans.append([st, ed])
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> ans = new ArrayList<>();
        int st = newInterval[0], ed = newInterval[1];
        boolean insert = false;
        for (int[] interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.add(new int[] {st, ed});
                    insert = true;
                }
                ans.add(interval);
            } else if (e < st) {
                ans.add(interval);
            } else {
                st = Math.min(st, s);
                ed = Math.max(ed, e);
            }
        }
        if (!insert) {
            ans.add(new int[] {st, ed});
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int st = newInterval[0], ed = newInterval[1];
        bool insert = false;
        for (auto& interval : intervals) {
            int s = interval[0], e = interval[1];
            if (ed < s) {
                if (!insert) {
                    ans.push_back({st, ed});
                    insert = true;
                }
                ans.push_back(interval);
            } else if (e < st) {
                ans.push_back(interval);
            } else {
                st = min(st, s);
                ed = max(ed, e);
            }
        }
        if (!insert) {
            ans.push_back({st, ed});
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}