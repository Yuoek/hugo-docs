---
title: "1982_FindArrayGivenSubsetSums"
date: 2025-10-06T00:42:37+08:00
weight: 1982
tags: [数组, 分治]
---


{{< katex />}}

{{< badge title="Difficulty" value="困难" >}}

<!-- problem:start -->

# [1982. 从子集的和还原数组](https://leetcode.cn/problems/find-array-given-subset-sums)

[English Version](../en/1982-82/1982_FindArrayGivenSubsetSums)

## 题目描述

<!-- description:start -->

<p>存在一个未知数组需要你进行还原，给你一个整数 <code>n</code> 表示该数组的长度。另给你一个数组 <code>sums</code> ，由未知数组中全部 <code>2<sup>n</sup></code> 个 <strong>子集的和</strong> 组成（子集中的元素没有特定的顺序）。</p>

<p>返回一个长度为 <code>n</code> 的数组<em> </em><code>ans</code><em> </em>表示还原得到的未知数组。如果存在 <strong>多种</strong> 答案，只需返回其中 <strong>任意一个</strong> 。</p>

<p>如果可以由数组 <code>arr</code> 删除部分元素（也可能不删除或全删除）得到数组 <code>sub</code> ，那么数组 <code>sub</code> 就是数组 <code>arr</code> 的一个<strong> 子集</strong> 。<code>sub</code> 的元素之和就是 <code>arr</code> 的一个 <strong>子集的和</strong> 。一个空数组的元素之和为 <code>0</code> 。</p>

<p><strong>注意：</strong>生成的测试用例将保证至少存在一个正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3, sums = [-3,-2,-1,0,0,1,2,3]
<strong>输出：</strong>[1,2,-3]
<strong>解释：</strong>[1,2,-3] 能够满足给出的子集的和：
- []：和是 0
- [1]：和是 1
- [2]：和是 2
- [1,2]：和是 3
- [-3]：和是 -3
- [1,-3]：和是 -2
- [2,-3]：和是 -1
- [1,2,-3]：和是 0
注意，[1,2,-3] 的任何排列和 [-1,-2,3] 的任何排列都会被视作正确答案。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, sums = [0,0,0,0]
<strong>输出：</strong>[0,0]
<strong>解释：</strong>唯一的正确答案是 [0,0] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
<strong>输出：</strong>[0,-1,4,5]
<strong>解释：</strong>[0,-1,4,5] 能够满足给出的子集的和。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
	<li><code>sums.length == 2<sup>n</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= sums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

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
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        sums.sort()
        ans = []
        for i in range(n, 0, -1):
            k = 1 << i
            d = sums[k - 1] - sums[k - 2]
            cnt = Counter(sums[:k])
            sums1, sums2 = [], []
            sign = 1
            for s in sums[:k]:
                if not cnt[s]:
                    continue
                cnt[s] -= 1
                cnt[s + d] -= 1
                sums1.append(s)
                sums2.append(s + d)
                if s + d == 0:
                    sign = -1
            ans.append(sign * d)
            sums = sums1 if sign == 1 else sums2
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] recoverArray(int n, int[] sums) {
        Arrays.sort(sums);
        int[] sums1 = new int[1 << n];
        int[] sums2 = new int[1 << n];
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[n];
        for (int i = n; i > 0; --i) {
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            cnt.clear();
            for (int j = 0; j < k; ++j) {
                cnt.merge(sums[j], 1, Integer::sum);
            }
            int sign = 1;
            for (int j = 0, p = 0; j < k; ++j) {
                if (cnt.getOrDefault(sums[j], 0) == 0) {
                    continue;
                }
                cnt.merge(sums[j], -1, Integer::sum);
                cnt.merge(sums[j] + d, -1, Integer::sum);
                sums1[p] = sums[j];
                sums2[p++] = sums[j] + d;
                if (sums[j] + d == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            System.arraycopy(sign == 1 ? sums1 : sums2, 0, sums, 0, k / 2);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans(n);
        unordered_map<int, int> cnt;
        for (int i = n; i; --i) {
            cnt.clear();
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            for (int j = 0; j < k; ++j) {
                cnt[sums[j]]++;
            }
            vector<int> sums1, sums2;
            int sign = 1;
            for (int j = 0; j < k; ++j) {
                if (cnt[sums[j]] == 0) {
                    continue;
                }
                --cnt[sums[j]];
                --cnt[sums[j] + d];
                sums1.push_back(sums[j]);
                sums2.push_back(sums[j] + d);
                if (sums2.back() == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            for (int j = 0; j < k / 2; ++j) {
                sums[j] = sign == 1 ? sums1[j] : sums2[j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func recoverArray(n int, sums []int) (ans []int) {
	sort.Ints(sums)
	for i := n; i > 0; i-- {
		k := 1 << i
		d := sums[k-1] - sums[k-2]
		cnt := map[int]int{}
		for _, s := range sums[:k] {
			cnt[s]++
		}
		sums1, sums2 := []int{}, []int{}
		sign := 1
		for _, s := range sums[:k] {
			if cnt[s] == 0 {
				continue
			}
			cnt[s]--
			cnt[s+d]--
			sums1 = append(sums1, s)
			sums2 = append(sums2, s+d)
			if s+d == 0 {
				sign = -1
			}
		}
		ans = append(ans, sign*d)
		if sign == -1 {
			sums1 = sums2
		}
		sums = sums1
	}
	return
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def recoverArray(self, n: int, sums: List[int]) -> List[int]:
        sums.sort()
        ans = []
        for i in range(n, 0, -1):
            k = 1 << i
            d = sums[k - 1] - sums[k - 2]
            cnt = Counter(sums[:k])
            sums1, sums2 = [], []
            sign = 1
            for s in sums[:k]:
                if not cnt[s]:
                    continue
                cnt[s] -= 1
                cnt[s + d] -= 1
                sums1.append(s)
                sums2.append(s + d)
                if s + d == 0:
                    sign = -1
            ans.append(sign * d)
            sums = sums1 if sign == 1 else sums2
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int[] recoverArray(int n, int[] sums) {
        Arrays.sort(sums);
        int[] sums1 = new int[1 << n];
        int[] sums2 = new int[1 << n];
        Map<Integer, Integer> cnt = new HashMap<>();
        int[] ans = new int[n];
        for (int i = n; i > 0; --i) {
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            cnt.clear();
            for (int j = 0; j < k; ++j) {
                cnt.merge(sums[j], 1, Integer::sum);
            }
            int sign = 1;
            for (int j = 0, p = 0; j < k; ++j) {
                if (cnt.getOrDefault(sums[j], 0) == 0) {
                    continue;
                }
                cnt.merge(sums[j], -1, Integer::sum);
                cnt.merge(sums[j] + d, -1, Integer::sum);
                sums1[p] = sums[j];
                sums2[p++] = sums[j] + d;
                if (sums[j] + d == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            System.arraycopy(sign == 1 ? sums1 : sums2, 0, sums, 0, k / 2);
        }
        return ans;
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
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int> ans(n);
        unordered_map<int, int> cnt;
        for (int i = n; i; --i) {
            cnt.clear();
            int k = 1 << i;
            int d = sums[k - 1] - sums[k - 2];
            for (int j = 0; j < k; ++j) {
                cnt[sums[j]]++;
            }
            vector<int> sums1, sums2;
            int sign = 1;
            for (int j = 0; j < k; ++j) {
                if (cnt[sums[j]] == 0) {
                    continue;
                }
                --cnt[sums[j]];
                --cnt[sums[j] + d];
                sums1.push_back(sums[j]);
                sums2.push_back(sums[j] + d);
                if (sums2.back() == 0) {
                    sign = -1;
                }
            }
            ans[i - 1] = sign * d;
            for (int j = 0; j < k / 2; ++j) {
                sums[j] = sign == 1 ? sums1[j] : sums2[j];
            }
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}