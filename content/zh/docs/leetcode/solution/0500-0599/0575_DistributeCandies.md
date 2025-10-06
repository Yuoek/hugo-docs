---
title: "0575_DistributeCandies"
date: 2025-10-06T00:42:37+08:00
weight: 0575
tags: [数组, 哈希表]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [575. 分糖果](https://leetcode.cn/problems/distribute-candies)

[English Version](../en/0575-75/0575_DistributeCandies)

## 题目描述

<!-- description:start -->

<p>Alice 有 <code>n</code> 枚糖，其中第 <code>i</code> 枚糖的类型为 <code>candyType[i]</code> 。Alice 注意到她的体重正在增长，所以前去拜访了一位医生。</p>

<p>医生建议 Alice 要少摄入糖分，只吃掉她所有糖的 <code>n / 2</code> 即可（<code>n</code> 是一个偶数）。Alice 非常喜欢这些糖，她想要在遵循医生建议的情况下，尽可能吃到最多不同种类的糖。</p>

<p>给你一个长度为 <code>n</code> 的整数数组 <code>candyType</code> ，返回： Alice <em>在仅吃掉 <code>n / 2</code> 枚糖的情况下，可以吃到糖的 <strong>最多</strong> 种类数</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>candyType = [1,1,2,2,3,3]
<strong>输出：</strong>3
<strong>解释：</strong>Alice 只能吃 6 / 2 = 3 枚糖，由于只有 3 种糖，她可以每种吃一枚。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>candyType = [1,1,2,3]
<strong>输出：</strong>2
<strong>解释：</strong>Alice 只能吃 4 / 2 = 2 枚糖，不管她选择吃的种类是 [1,2]、[1,3] 还是 [2,3]，她只能吃到两种不同类的糖。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>candyType = [6,6,6,6]
<strong>输出：</strong>1
<strong>解释：</strong>Alice 只能吃 4 / 2 = 2 枚糖，尽管她能吃 2 枚，但只能吃到 1 种糖。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == candyType.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>n</code> 是一个偶数</li>
	<li><code>-10<sup>5</sup> &lt;= candyType[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表来存储糖果的种类，如果糖果的种类数小于 $n / 2$，那么 Alice 最多可以吃到的糖果种类数就是糖果的种类数；否则，Alice 最多可以吃到的糖果种类数就是 $n / 2$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为糖果的数量。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(candyType) >> 1, len(set(candyType)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> s = new HashSet<>();
        for (int c : candyType) {
            s.add(c);
        }
        return Math.min(candyType.length >> 1, s.size());
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(candyType.size() >> 1, s.size());
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func distributeCandies(candyType []int) int {
	s := hashset.New()
	for _, c := range candyType {
		s.Add(c)
	}
	return min(len(candyType)>>1, s.Size())
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function distributeCandies(candyType: number[]): number {
    const s = new Set(candyType);
    return Math.min(s.size, candyType.length >> 1);
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(candyType) >> 1, len(set(candyType)))
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public int distributeCandies(int[] candyType) {
        Set<Integer> s = new HashSet<>();
        for (int c : candyType) {
            s.add(c);
        }
        return Math.min(candyType.length >> 1, s.size());
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
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        return min(candyType.size() >> 1, s.size());
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}