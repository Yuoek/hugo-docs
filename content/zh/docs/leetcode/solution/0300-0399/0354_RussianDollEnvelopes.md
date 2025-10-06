---
title: "0354_RussianDollEnvelopes"
date: 2025-10-06T00:42:37+08:00
weight: 0354
tags: [数组, 二分查找, 动态规划, 排序]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [354. 俄罗斯套娃信封问题](https://leetcode.cn/problems/russian-doll-envelopes)

[English Version](../en/0354-54/0354_RussianDollEnvelopes)

## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>envelopes</code> ，其中 <code>envelopes[i] = [w<sub>i</sub>, h<sub>i</sub>]</code> ，表示第 <code>i</code> 个信封的宽度和高度。</p>

<p>当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。</p>

<p>请计算 <strong>最多能有多少个</strong> 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。</p>

<p><strong>注意</strong>：不允许旋转信封。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>envelopes = [[5,4],[6,4],[6,7],[2,3]]
<strong>输出：</strong>3
<strong>解释：</strong>最多信封的个数为 <code>3, 组合为: </code>[2,3] =&gt; [5,4] =&gt; [6,7]。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>envelopes = [[1,1],[1,1],[1,1]]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= envelopes.length &lt;= 10<sup>5</sup></code></li>
	<li><code>envelopes[i].length == 2</code></li>
	<li><code>1 &lt;= w<sub>i</sub>, h<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：贪心 + 二分查找

时间复杂度 O(nlogn)。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        d = [envelopes[0][1]]
        for _, h in envelopes[1:]:
            if h > d[-1]:
                d.append(h)
            else:
                idx = bisect_left(d, h)
                d[idx] = h
        return len(d)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> { return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]; });
        int n = envelopes.length;
        int[] d = new int[n + 1];
        d[1] = envelopes[0][1];
        int size = 1;
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[size]) {
                d[++size] = x;
            } else {
                int left = 1, right = size;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (d[mid] >= x) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                int p = d[left] >= x ? left : 1;
                d[p] = x;
            }
        }
        return size;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        int n = envelopes.size();
        vector<int> d{envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[d.size() - 1])
                d.push_back(x);
            else {
                int idx = lower_bound(d.begin(), d.end(), x) - d.begin();
                if (idx == d.size()) idx = 0;
                d[idx] = x;
            }
        }
        return d.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxEnvelopes(envelopes [][]int) int {
	sort.Slice(envelopes, func(i, j int) bool {
		if envelopes[i][0] != envelopes[j][0] {
			return envelopes[i][0] < envelopes[j][0]
		}
		return envelopes[j][1] < envelopes[i][1]
	})
	n := len(envelopes)
	d := make([]int, n+1)
	d[1] = envelopes[0][1]
	size := 1
	for _, e := range envelopes[1:] {
		x := e[1]
		if x > d[size] {
			size++
			d[size] = x
		} else {
			left, right := 1, size
			for left < right {
				mid := (left + right) >> 1
				if d[mid] >= x {
					right = mid
				} else {
					left = mid + 1
				}
			}
			if d[left] < x {
				left = 1
			}
			d[left] = x
		}
	}
	return size
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        d = [envelopes[0][1]]
        for _, h in envelopes[1:]:
            if h > d[-1]:
                d.append(h)
            else:
                idx = bisect_left(d, h)
                d[idx] = h
        return len(d)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> { return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]; });
        int n = envelopes.length;
        int[] d = new int[n + 1];
        d[1] = envelopes[0][1];
        int size = 1;
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[size]) {
                d[++size] = x;
            } else {
                int left = 1, right = size;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (d[mid] >= x) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                int p = d[left] >= x ? left : 1;
                d[p] = x;
            }
        }
        return size;
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
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        int n = envelopes.size();
        vector<int> d{envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            int x = envelopes[i][1];
            if (x > d[d.size() - 1])
                d.push_back(x);
            else {
                int idx = lower_bound(d.begin(), d.end(), x) - d.begin();
                if (idx == d.size()) idx = 0;
                d[idx] = x;
            }
        }
        return d.size();
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}