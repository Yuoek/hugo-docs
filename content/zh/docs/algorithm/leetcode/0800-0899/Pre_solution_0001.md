---
title: "0800_相似 RGB 颜色 🔒"
date: 2025-10-08T18:36:34+08:00
weight: 1
tags: [位运算, 动态规划, 双指针, 哈希表, 图, 字符串, 并查集, 广度优先搜索, 拓扑排序, 数学, 数组, 枚举, 概率与统计, 深度优先搜索, 状态压缩, 矩阵, 贪心]
---

{{< markmap >}}
### [0800_相似 RGB 颜色 🔒](#800)
#### [数学](#800)
#### [字符串](#800)
#### [枚举](#800)
### [0801_使序列递增的最小交换次数](#801)
#### [数组](#801)
#### [动态规划](#801)
### [0802_找到最终的安全状态](#802)
#### [深度优先搜索](#802)
#### [广度优先搜索](#802)
#### [图](#802)
#### [拓扑排序](#802)
### [0803_打砖块](#803)
#### [并查集](#803)
#### [数组](#803)
#### [矩阵](#803)
### [0804_唯一摩尔斯密码词](#804)
#### [数组](#804)
#### [哈希表](#804)
#### [字符串](#804)
### [0805_数组的均值分割](#805)
#### [位运算](#805)
#### [数组](#805)
#### [数学](#805)
#### [动态规划](#805)
#### [状态压缩](#805)
### [0806_写字符串需要的行数](#806)
#### [数组](#806)
#### [字符串](#806)
### [0807_保持城市天际线](#807)
#### [贪心](#807)
#### [数组](#807)
#### [矩阵](#807)
### [0808_分汤](#808)
#### [数学](#808)
#### [动态规划](#808)
#### [概率与统计](#808)
### [0809_情感丰富的文字](#809)
#### [数组](#809)
#### [双指针](#809)
#### [字符串](#809)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0800_相似 RGB 颜色 🔒
___
#### 数学
___
#### 字符串
___
#### 枚举
---
### 0801_使序列递增的最小交换次数
___
#### 数组
___
#### 动态规划
---
### 0802_找到最终的安全状态
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 0803_打砖块
___
#### 并查集
___
#### 数组
___
#### 矩阵
---
### 0804_唯一摩尔斯密码词
___
#### 数组
___
#### 哈希表
___
#### 字符串
---
### 0805_数组的均值分割
___
#### 位运算
___
#### 数组
___
#### 数学
___
#### 动态规划
___
#### 状态压缩
---
### 0806_写字符串需要的行数
___
#### 数组
___
#### 字符串
---
### 0807_保持城市天际线
___
#### 贪心
___
#### 数组
___
#### 矩阵
---
### 0808_分汤
___
#### 数学
___
#### 动态规划
___
#### 概率与统计
---
### 0809_情感丰富的文字
___
#### 数组
___
#### 双指针
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 动态规划 | 双指针 |
| 哈希表 | 图 | 字符串 |
| 并查集 | 广度优先搜索 | 拓扑排序 |
| 数学 | 数组 | 枚举 |
| 概率与统计 | 深度优先搜索 | 状态压缩 |
| 矩阵 | 贪心 |  |

# [800. 相似 RGB 颜色 🔒](https://leetcode.cn/problems/similar-rgb-color){#800}

{{< tabs "800" >}}

{{% tab "python" %}}
```python
class Solution:
    def similarRGB(self, color: str) -> str:
        def f(x):
            y, z = divmod(int(x, 16), 17)
            if z > 8:
                y += 1
            return '{:02x}'.format(17 * y)

        a, b, c = color[1:3], color[3:5], color[5:7]
        return f'#{f(a)}{f(b)}{f(c)}'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String similarRGB(String color) {
        String a = color.substring(1, 3), b = color.substring(3, 5), c = color.substring(5, 7);
        return "#" + f(a) + f(b) + f(c);
    }

    private String f(String x) {
        int q = Integer.parseInt(x, 16);
        q = q / 17 + (q % 17 > 8 ? 1 : 0);
        return String.format("%02x", 17 * q);
    }
}
```
{{% /tab %}}
{{% tab "go" %}}
```go
func similarRGB(color string) string {
	f := func(x string) string {
		q, _ := strconv.ParseInt(x, 16, 64)
		if q%17 > 8 {
			q = q/17 + 1
		} else {
			q = q / 17
		}
		return fmt.Sprintf("%02x", 17*q)

	}
	a, b, c := color[1:3], color[3:5], color[5:7]
	return "#" + f(a) + f(b) + f(c)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>RGB 颜色 <code>"#AABBCC"</code>&nbsp;可以简写成&nbsp;<code>"#ABC"</code> 。</p>

<ul>
	<li>例如，<code>"#15c"</code>&nbsp;其实是&nbsp;<code>"#1155cc"</code> 的简写。</li>
</ul>

<p>现在，假如我们分别定义两个颜色 <code>"#ABCDEF"</code>&nbsp;和&nbsp;<code>"#UVWXYZ"</code>，则他们的相似度可以通过这个表达式&nbsp;<code>-(AB - UV)^2 -&nbsp;(CD - WX)^2 -&nbsp;(EF - YZ)^2</code>&nbsp;来计算。</p>

<p>那么给你一个按 <code>"#ABCDEF"</code> 形式定义的字符串 <code>color</code> 表示 RGB 颜色，请你以字符串形式，返回一个与它相似度最大且可以简写的颜色。（比如，可以表示成类似 <code>"#XYZ"</code> 的形式）</p>

<p><strong>任何</strong> 具有相同的（最大）相似度的答案都会被视为正确答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>color = "#09f166"
<strong>输出：</strong>"#11ee66"
<strong>解释：</strong> 
因为相似度计算得出 -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73
这已经是所有可以简写的颜色中最相似的了
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>color = "#4e3fe1"
<strong>输出：</strong>"#5544dd"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>color.length == 7</code></li>
	<li><code>color[0] == '#'</code></li>
	<li>对于任何 <code>i &gt; 0</code>，<code>color[i]</code> 都是一个在范围 <code>['0', 'f']</code> 内的 16 进制数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def similarRGB(self, color: str) -> str:
        def f(x):
            y, z = divmod(int(x, 16), 17)
            if z > 8:
                y += 1
            return '{:02x}'.format(17 * y)

        a, b, c = color[1:3], color[3:5], color[5:7]
        return f'#{f(a)}{f(b)}{f(c)}'
```

#### Java

```java
class Solution {
    public String similarRGB(String color) {
        String a = color.substring(1, 3), b = color.substring(3, 5), c = color.substring(5, 7);
        return "#" + f(a) + f(b) + f(c);
    }

    private String f(String x) {
        int q = Integer.parseInt(x, 16);
        q = q / 17 + (q % 17 > 8 ? 1 : 0);
        return String.format("%02x", 17 * q);
    }
}
```

#### Go

```go
func similarRGB(color string) string {
	f := func(x string) string {
		q, _ := strconv.ParseInt(x, 16, 64)
		if q%17 > 8 {
			q = q/17 + 1
		} else {
			q = q / 17
		}
		return fmt.Sprintf("%02x", 17*q)

	}
	a, b, c := color[1:3], color[3:5], color[5:7]
	return "#" + f(a) + f(b) + f(c)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [801. 使序列递增的最小交换次数](https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing){#801}

{{< tabs "801" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        a, b = 0, 1
        for i in range(1, len(nums1)):
            x, y = a, b
            if nums1[i - 1] >= nums1[i] or nums2[i - 1] >= nums2[i]:
                a, b = y, x + 1
            else:
                b = y + 1
                if nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i]:
                    a, b = min(a, y), min(b, x + 1)
        return min(a, b)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int a = 0, b = 1;
        for (int i = 1; i < nums1.length; ++i) {
            int x = a, y = b;
            if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
                a = y;
                b = x + 1;
            } else {
                b = y + 1;
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                    a = Math.min(a, y);
                    b = Math.min(b, x + 1);
                }
            }
        }
        return Math.min(a, b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b = 1, n = nums1.size();
        for (int i = 1; i < n; ++i) {
            int x = a, y = b;
            if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
                a = y, b = x + 1;
            } else {
                b = y + 1;
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                    a = min(a, y);
                    b = min(b, x + 1);
                }
            }
        }
        return min(a, b);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSwap(nums1 []int, nums2 []int) int {
	a, b, n := 0, 1, len(nums1)
	for i := 1; i < n; i++ {
		x, y := a, b
		if nums1[i-1] >= nums1[i] || nums2[i-1] >= nums2[i] {
			a, b = y, x+1
		} else {
			b = y + 1
			if nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i] {
				a = min(a, y)
				b = min(b, x+1)
			}
		}
	}
	return min(a, b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSwap(nums1: number[], nums2: number[]): number {
    let [a, b] = [0, 1];
    for (let i = 1; i < nums1.length; ++i) {
        let x = a,
            y = b;
        if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
            a = y;
            b = x + 1;
        } else {
            b = y + 1;
            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                a = Math.min(a, y);
                b = Math.min(b, x + 1);
            }
        }
    }
    return Math.min(a, b);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们有两个长度相等且不为空的整型数组&nbsp;<code>nums1</code>&nbsp;和&nbsp;<code>nums2</code>&nbsp;。在一次操作中，我们可以交换&nbsp;<code>nums1[i]</code>&nbsp;和&nbsp;<code>nums2[i]</code>的元素。</p>

<ul>
	<li>例如，如果 <code>nums1 = [1,2,3,<u>8</u>]</code> ， <code>nums2 =[5,6,7,<u>4</u>]</code> ，你可以交换 <code>i = 3</code> 处的元素，得到 <code>nums1 =[1,2,3,4]</code> 和 <code>nums2 =[5,6,7,8]</code> 。</li>
</ul>

<p>返回 <em>使 <code>nums1</code> 和 <code>nums2</code> <strong>严格递增&nbsp;</strong>所需操作的最小次数</em> 。</p>

<p>数组&nbsp;<code>arr</code>&nbsp;<strong>严格递增</strong> 且&nbsp;&nbsp;<code>arr[0] &lt; arr[1] &lt; arr[2] &lt; ... &lt; arr[arr.length - 1]</code>&nbsp;。</p>

<p><b>注意：</b></p>

<ul>
	<li>用例保证可以实现操作。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [1,3,5,4], nums2 = [1,2,3,7]
<strong>输出:</strong> 1
<strong>解释: </strong>
交换 A[3] 和 B[3] 后，两个数组如下:
A = [1, 3, 5, 7] ， B = [1, 2, 3, 4]
两个数组均为严格递增的。</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
<strong>输出:</strong> 1
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>2 &lt;= nums1.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums2.length == nums1.length</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 2 * 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

定义 $a$, $b$ 分别表示使得下标 $[0..i]$ 的元素序列严格递增，且第 $i$ 个元素不交换、交换的最小交换次数。下标从 $0$ 开始。

当 $i=0$ 时，有 $a = 0$, $b=1$。

当 $i\gt 0$ 时，我们先将此前 $a$, $b$ 的值保存在 $x$, $y$ 中，然后分情况讨论：

如果 $nums1[i - 1] \ge nums1[i]$ 或者 $nums2[i - 1] \ge nums2[i]$，为了使得两个序列均严格递增，下标 $i-1$ 和 $i$ 对应的元素的相对位置必须发生变化。也就是说，如果前一个位置交换了，那么当前位置不交换，因此有 $a = y$；如果前一个位置没有交换，那么当前位置必须交换，因此有 $b = x + 1$。

否则，下标 $i-1$ 和 $i$ 对应的元素的相对位置可以不发生变化，那么有 $b = y + 1$。另外，如果满足 $nums1[i - 1] \lt nums2[i]$ 并且 $nums2[i - 1] \lt nums1[i]$，那么下标 $i-1$ 和 $i$ 对应的元素的相对位置可以发生变化，此时 $a$ 和 $b$ 可以取较小值，因此有 $a = \min(a, y)$ 和 $b = \min(b, x + 1)$。

最后，返回 $a$ 和 $b$ 中较小值即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSwap(self, nums1: List[int], nums2: List[int]) -> int:
        a, b = 0, 1
        for i in range(1, len(nums1)):
            x, y = a, b
            if nums1[i - 1] >= nums1[i] or nums2[i - 1] >= nums2[i]:
                a, b = y, x + 1
            else:
                b = y + 1
                if nums1[i - 1] < nums2[i] and nums2[i - 1] < nums1[i]:
                    a, b = min(a, y), min(b, x + 1)
        return min(a, b)
```

#### Java

```java
class Solution {
    public int minSwap(int[] nums1, int[] nums2) {
        int a = 0, b = 1;
        for (int i = 1; i < nums1.length; ++i) {
            int x = a, y = b;
            if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
                a = y;
                b = x + 1;
            } else {
                b = y + 1;
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                    a = Math.min(a, y);
                    b = Math.min(b, x + 1);
                }
            }
        }
        return Math.min(a, b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int a = 0, b = 1, n = nums1.size();
        for (int i = 1; i < n; ++i) {
            int x = a, y = b;
            if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
                a = y, b = x + 1;
            } else {
                b = y + 1;
                if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                    a = min(a, y);
                    b = min(b, x + 1);
                }
            }
        }
        return min(a, b);
    }
};
```

#### Go

```go
func minSwap(nums1 []int, nums2 []int) int {
	a, b, n := 0, 1, len(nums1)
	for i := 1; i < n; i++ {
		x, y := a, b
		if nums1[i-1] >= nums1[i] || nums2[i-1] >= nums2[i] {
			a, b = y, x+1
		} else {
			b = y + 1
			if nums1[i-1] < nums2[i] && nums2[i-1] < nums1[i] {
				a = min(a, y)
				b = min(b, x+1)
			}
		}
	}
	return min(a, b)
}
```

#### TypeScript

```ts
function minSwap(nums1: number[], nums2: number[]): number {
    let [a, b] = [0, 1];
    for (let i = 1; i < nums1.length; ++i) {
        let x = a,
            y = b;
        if (nums1[i - 1] >= nums1[i] || nums2[i - 1] >= nums2[i]) {
            a = y;
            b = x + 1;
        } else {
            b = y + 1;
            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                a = Math.min(a, y);
                b = Math.min(b, x + 1);
            }
        }
    }
    return Math.min(a, b);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [802. 找到最终的安全状态](https://leetcode.cn/problems/find-eventual-safe-states){#802}

{{< tabs "802" >}}

{{% tab "python" %}}
```python
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        def dfs(i):
            if color[i]:
                return color[i] == 2
            color[i] = 1
            for j in graph[i]:
                if not dfs(j):
                    return False
            color[i] = 2
            return True

        n = len(graph)
        color = [0] * n
        return [i for i in range(n) if dfs(i)]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] color;
    private int[][] g;

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        color = new int[n];
        g = graph;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (dfs(i)) {
                ans.add(i);
            }
        }
        return ans;
    }

    private boolean dfs(int i) {
        if (color[i] > 0) {
            return color[i] == 2;
        }
        color[i] = 1;
        for (int j : g[i]) {
            if (!dfs(j)) {
                return false;
            }
        }
        color[i] = 2;
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> color;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (dfs(i, graph)) ans.push_back(i);
        return ans;
    }

    bool dfs(int i, vector<vector<int>>& g) {
        if (color[i]) return color[i] == 2;
        color[i] = 1;
        for (int j : g[i])
            if (!dfs(j, g)) return false;
        color[i] = 2;
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func eventualSafeNodes(graph [][]int) []int {
	n := len(graph)
	color := make([]int, n)
	var dfs func(int) bool
	dfs = func(i int) bool {
		if color[i] > 0 {
			return color[i] == 2
		}
		color[i] = 1
		for _, j := range graph[i] {
			if !dfs(j) {
				return false
			}
		}
		color[i] = 2
		return true
	}
	ans := []int{}
	for i := range graph {
		if dfs(i) {
			ans = append(ans, i)
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function (graph) {
    const n = graph.length;
    const color = new Array(n).fill(0);
    function dfs(i) {
        if (color[i]) {
            return color[i] == 2;
        }
        color[i] = 1;
        for (const j of graph[i]) {
            if (!dfs(j)) {
                return false;
            }
        }
        color[i] = 2;
        return true;
    }
    let ans = [];
    for (let i = 0; i < n; ++i) {
        if (dfs(i)) {
            ans.push(i);
        }
    }
    return ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个有 <code>n</code> 个节点的有向图，节点按 <code>0</code> 到 <code>n - 1</code> 编号。图由一个 <strong>索引从 0 开始</strong> 的 2D 整数数组&nbsp;<code>graph</code>表示，&nbsp;<code>graph[i]</code>是与节点 <code>i</code> 相邻的节点的整数数组，这意味着从节点 <code>i</code> 到&nbsp;<code>graph[i]</code>中的每个节点都有一条边。</p>

<p>如果一个节点没有连出的有向边，则该节点是 <strong>终端节点</strong> 。如果从该节点开始的所有可能路径都通向 <strong>终端节点</strong>（或另一个安全节点），则该节点为 <strong>安全节点</strong>。</p>

<p>返回一个由图中所有 <strong>安全节点</strong> 组成的数组作为答案。答案数组中的元素应当按 <strong>升序</strong> 排列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="Illustration of graph" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0802.Find%20Eventual%20Safe%20States/images/picture1.png" /></p>

<pre>
<strong>输入：</strong>graph = [[1,2],[2,3],[5],[0],[5],[],[]]
<strong>输出：</strong>[2,4,5,6]
<strong>解释：</strong>示意图如上。
节点 5 和节点 6 是终端节点，因为它们都没有出边。
从节点 2、4、5 和 6 开始的所有路径都指向节点 5 或 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
<strong>输出：</strong>[4]
<strong>解释:</strong>
只有节点 4 是终端节点，从节点 4 开始的所有路径都通向节点 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= graph[i].length &lt;= n</code></li>
	<li><code>0 &lt;= graph[i][j] &lt;= n - 1</code></li>
	<li><code>graph[i]</code> 按严格递增顺序排列。</li>
	<li>图中可能包含自环。</li>
	<li>图中边的数目在范围 <code>[1, 4 * 10<sup>4</sup>]</code> 内。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：拓扑排序

出度为零的点是安全的，如果一个点**只能**到达安全的点，那么它同样是安全的，所以问题转换成了拓扑排序。

我们可以将图中所有边反向，得到一个反图，然后在反图上运行拓扑排序。

时间复杂度 $O(n+m)$，其中 $n$ 表示图中的点数，$m$ 表示图中的边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        rg = defaultdict(list)
        indeg = [0] * len(graph)
        for i, vs in enumerate(graph):
            for j in vs:
                rg[j].append(i)
            indeg[i] = len(vs)
        q = deque([i for i, v in enumerate(indeg) if v == 0])
        while q:
            i = q.popleft()
            for j in rg[i]:
                indeg[j] -= 1
                if indeg[j] == 0:
                    q.append(j)
        return [i for i, v in enumerate(indeg) if v == 0]
```

#### Java

```java
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        int[] indeg = new int[n];
        List<Integer>[] rg = new List[n];
        Arrays.setAll(rg, k -> new ArrayList<>());
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                rg[j].add(i);
            }
            indeg[i] = graph[i].length;
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            for (int j : rg[i]) {
                if (--indeg[j] == 0) {
                    q.offer(j);
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                ans.add(i);
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indeg(n);
        vector<vector<int>> rg(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) rg[j].push_back(i);
            indeg[i] = graph[i].size();
            if (indeg[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j : rg[i])
                if (--indeg[j] == 0) q.push(j);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) ans.push_back(i);
        return ans;
    }
};
```

#### Go

```go
func eventualSafeNodes(graph [][]int) []int {
	n := len(graph)
	indeg := make([]int, n)
	rg := make([][]int, n)
	q := []int{}
	for i, vs := range graph {
		for _, j := range vs {
			rg[j] = append(rg[j], i)
		}
		indeg[i] = len(vs)
		if indeg[i] == 0 {
			q = append(q, i)
		}
	}
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		for _, j := range rg[i] {
			indeg[j]--
			if indeg[j] == 0 {
				q = append(q, j)
			}
		}
	}
	ans := []int{}
	for i, v := range indeg {
		if v == 0 {
			ans = append(ans, i)
		}
	}
	return ans
}
```

#### JavaScript

```js
/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function (graph) {
    const n = graph.length;
    const rg = new Array(n).fill(0).map(() => new Array());
    const indeg = new Array(n).fill(0);
    const q = [];
    for (let i = 0; i < n; ++i) {
        for (let j of graph[i]) {
            rg[j].push(i);
        }
        indeg[i] = graph[i].length;
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (q.length) {
        const i = q.shift();
        for (let j of rg[i]) {
            if (--indeg[j] == 0) {
                q.push(j);
            }
        }
    }
    let ans = [];
    for (let i = 0; i < n; ++i) {
        if (indeg[i] == 0) {
            ans.push(i);
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：DFS + 三色标记法

若起始节点位于一个环内，或者能到达一个环，则该节点不是安全的。否则，该节点是安全的。

-   白色（用 0 表示）：该节点尚未被访问；
-   灰色（用 1 表示）：该节点位于递归栈中，或者在某个环上；
-   黑色（用 2 表示）：该节点搜索完毕，是一个安全节点。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        def dfs(i):
            if color[i]:
                return color[i] == 2
            color[i] = 1
            for j in graph[i]:
                if not dfs(j):
                    return False
            color[i] = 2
            return True

        n = len(graph)
        color = [0] * n
        return [i for i in range(n) if dfs(i)]
```

#### Java

```java
class Solution {
    private int[] color;
    private int[][] g;

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        color = new int[n];
        g = graph;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (dfs(i)) {
                ans.add(i);
            }
        }
        return ans;
    }

    private boolean dfs(int i) {
        if (color[i] > 0) {
            return color[i] == 2;
        }
        color[i] = 1;
        for (int j : g[i]) {
            if (!dfs(j)) {
                return false;
            }
        }
        color[i] = 2;
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> color;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        color.assign(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (dfs(i, graph)) ans.push_back(i);
        return ans;
    }

    bool dfs(int i, vector<vector<int>>& g) {
        if (color[i]) return color[i] == 2;
        color[i] = 1;
        for (int j : g[i])
            if (!dfs(j, g)) return false;
        color[i] = 2;
        return true;
    }
};
```

#### Go

```go
func eventualSafeNodes(graph [][]int) []int {
	n := len(graph)
	color := make([]int, n)
	var dfs func(int) bool
	dfs = func(i int) bool {
		if color[i] > 0 {
			return color[i] == 2
		}
		color[i] = 1
		for _, j := range graph[i] {
			if !dfs(j) {
				return false
			}
		}
		color[i] = 2
		return true
	}
	ans := []int{}
	for i := range graph {
		if dfs(i) {
			ans = append(ans, i)
		}
	}
	return ans
}
```

#### JavaScript

```js
/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function (graph) {
    const n = graph.length;
    const color = new Array(n).fill(0);
    function dfs(i) {
        if (color[i]) {
            return color[i] == 2;
        }
        color[i] = 1;
        for (const j of graph[i]) {
            if (!dfs(j)) {
                return false;
            }
        }
        color[i] = 2;
        return true;
    }
    let ans = [];
    for (let i = 0; i < n; ++i) {
        if (dfs(i)) {
            ans.push(i);
        }
    }
    return ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [803. 打砖块](https://leetcode.cn/problems/bricks-falling-when-hit){#803}

{{< tabs "803" >}}

{{% tab "python" %}}
```python
class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                size[pb] += size[pa]
                p[pa] = pb

        m, n = len(grid), len(grid[0])
        p = list(range(m * n + 1))
        size = [1] * len(p)
        g = deepcopy(grid)
        for i, j in hits:
            g[i][j] = 0
        for j in range(n):
            if g[0][j] == 1:
                union(j, m * n)
        for i in range(1, m):
            for j in range(n):
                if g[i][j] == 0:
                    continue
                if g[i - 1][j] == 1:
                    union(i * n + j, (i - 1) * n + j)
                if j > 0 and g[i][j - 1] == 1:
                    union(i * n + j, i * n + j - 1)
        ans = []
        for i, j in hits[::-1]:
            if grid[i][j] == 0:
                ans.append(0)
                continue
            g[i][j] = 1
            prev = size[find(m * n)]
            if i == 0:
                union(j, m * n)
            for a, b in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and g[x][y] == 1:
                    union(i * n + j, x * n + y)
            curr = size[find(m * n)]
            ans.append(max(0, curr - prev - 1))
        return ans[::-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] p;
    private int[] size;

    public int[] hitBricks(int[][] grid, int[][] hits) {
        int m = grid.length;
        int n = grid[0].length;
        p = new int[m * n + 1];
        size = new int[m * n + 1];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
            size[i] = 1;
        }
        int[][] g = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = grid[i][j];
            }
        }
        for (int[] h : hits) {
            g[h[0]][h[1]] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (g[0][j] == 1) {
                union(j, m * n);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 0) {
                    continue;
                }
                if (g[i - 1][j] == 1) {
                    union(i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && g[i][j - 1] == 1) {
                    union(i * n + j, i * n + j - 1);
                }
            }
        }
        int[] ans = new int[hits.length];
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = hits.length - 1; k >= 0; --k) {
            int i = hits[k][0];
            int j = hits[k][1];
            if (grid[i][j] == 0) {
                continue;
            }
            g[i][j] = 1;
            int prev = size[find(m * n)];
            if (i == 0) {
                union(j, m * n);
            }
            for (int l = 0; l < 4; ++l) {
                int x = i + dirs[l];
                int y = j + dirs[l + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1) {
                    union(i * n + j, x * n + y);
                }
            }
            int curr = size[find(m * n)];
            ans[k] = Math.max(0, curr - prev - 1);
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            size[pb] += size[pa];
            p[pa] = pb;
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> p;
    vector<int> size;

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        p.resize(m * n + 1);
        size.resize(m * n + 1);
        for (int i = 0; i < p.size(); ++i) {
            p[i] = i;
            size[i] = 1;
        }
        vector<vector<int>> g(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = grid[i][j];
        for (auto& h : hits) g[h[0]][h[1]] = 0;
        for (int j = 0; j < n; ++j)
            if (g[0][j] == 1)
                merge(j, m * n);
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 0) continue;
                if (g[i - 1][j] == 1) merge(i * n + j, (i - 1) * n + j);
                if (j > 0 && g[i][j - 1] == 1) merge(i * n + j, i * n + j - 1);
            }
        }
        vector<int> ans(hits.size());
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int k = hits.size() - 1; k >= 0; --k) {
            int i = hits[k][0], j = hits[k][1];
            if (grid[i][j] == 0) continue;
            g[i][j] = 1;
            int prev = size[find(m * n)];
            if (i == 0) merge(j, m * n);
            for (int l = 0; l < 4; ++l) {
                int x = i + dirs[l], y = j + dirs[l + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1)
                    merge(i * n + j, x * n + y);
            }
            int curr = size[find(m * n)];
            ans[k] = max(0, curr - prev - 1);
        }
        return ans;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            size[pb] += size[pa];
            p[pa] = pb;
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func hitBricks(grid [][]int, hits [][]int) []int {
	m, n := len(grid), len(grid[0])
	p := make([]int, m*n+1)
	size := make([]int, len(p))
	for i := range p {
		p[i] = i
		size[i] = 1
	}

	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa != pb {
			size[pb] += size[pa]
			p[pa] = pb
		}
	}

	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = grid[i][j]
		}
	}
	for _, h := range hits {
		g[h[0]][h[1]] = 0
	}
	for j, v := range g[0] {
		if v == 1 {
			union(j, m*n)
		}
	}
	for i := 1; i < m; i++ {
		for j := 0; j < n; j++ {
			if g[i][j] == 0 {
				continue
			}
			if g[i-1][j] == 1 {
				union(i*n+j, (i-1)*n+j)
			}
			if j > 0 && g[i][j-1] == 1 {
				union(i*n+j, i*n+j-1)
			}
		}
	}
	ans := make([]int, len(hits))
	dirs := []int{-1, 0, 1, 0, -1}
	for k := len(hits) - 1; k >= 0; k-- {
		i, j := hits[k][0], hits[k][1]
		if grid[i][j] == 0 {
			continue
		}
		g[i][j] = 1
		prev := size[find(m*n)]
		if i == 0 {
			union(j, m*n)
		}
		for l := 0; l < 4; l++ {
			x, y := i+dirs[l], j+dirs[l+1]
			if x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1 {
				union(i*n+j, x*n+y)
			}
		}
		curr := size[find(m*n)]
		ans[k] = max(0, curr-prev-1)
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个 <code>m x n</code> 的二元网格<meta charset="UTF-8" />&nbsp;<code>grid</code>&nbsp;，其中 <code>1</code> 表示砖块，<code>0</code> 表示空白。砖块 <strong>稳定</strong>（不会掉落）的前提是：</p>

<ul>
	<li>一块砖直接连接到网格的顶部，或者</li>
	<li>至少有一块相邻（4&nbsp;个方向之一）砖块<strong> 稳定 </strong>不会掉落时</li>
</ul>

<p>给你一个数组 <code>hits</code> ，这是需要依次消除砖块的位置。每当消除&nbsp;<code>hits[i] = (rowi, coli)</code> 位置上的砖块时，对应位置的砖块（若存在）会消失，然后其他的砖块可能因为这一消除操作而 <strong>掉落</strong> 。一旦砖块掉落，它会 <strong>立即</strong> 从网格&nbsp;<code>grid</code>&nbsp;中消失（即，它不会落在其他稳定的砖块上）。</p>

<p>返回一个数组 <code>result</code> ，其中 <code>result[i]</code> 表示第 <code>i</code> 次消除操作对应掉落的砖块数目。</p>

<p><strong>注意</strong>，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
<strong>输出：</strong>[2]
<strong>解释：</strong>网格开始为：
[[1,0,0,0]，
 [<strong>1</strong>,1,1,0]]
消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0]
 [0,<strong>1</strong>,<strong>1</strong>,0]]
两个加粗的砖不再稳定，因为它们不再与顶部相连，也不再与另一个稳定的砖相邻，因此它们将掉落。得到网格：
[[1,0,0,0],
 [0,0,0,0]]
因此，结果为 [2] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
<strong>输出：</strong>[0,0]
<strong>解释：</strong>网格开始为：
[[1,0,0,0],
 [1,<strong>1</strong>,0,0]]
消除 (1,1) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [1,0,0,0]]
剩下的砖都很稳定，所以不会掉落。网格保持不变：
[[1,0,0,0], 
 [<strong>1</strong>,0,0,0]]
接下来消除 (1,0) 处加粗的砖块，得到网格：
[[1,0,0,0],
 [0,0,0,0]]
剩下的砖块仍然是稳定的，所以不会有砖块掉落。
因此，结果为 [0,0] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>grid[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>1 &lt;= hits.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>hits[i].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i&nbsp;</sub>&lt;= m - 1</code></li>
	<li><code>0 &lt;=&nbsp;y<sub>i</sub> &lt;= n - 1</code></li>
	<li>所有 <code>(x<sub>i</sub>, y<sub>i</sub>)</code> 互不相同</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(a, b):
            pa, pb = find(a), find(b)
            if pa != pb:
                size[pb] += size[pa]
                p[pa] = pb

        m, n = len(grid), len(grid[0])
        p = list(range(m * n + 1))
        size = [1] * len(p)
        g = deepcopy(grid)
        for i, j in hits:
            g[i][j] = 0
        for j in range(n):
            if g[0][j] == 1:
                union(j, m * n)
        for i in range(1, m):
            for j in range(n):
                if g[i][j] == 0:
                    continue
                if g[i - 1][j] == 1:
                    union(i * n + j, (i - 1) * n + j)
                if j > 0 and g[i][j - 1] == 1:
                    union(i * n + j, i * n + j - 1)
        ans = []
        for i, j in hits[::-1]:
            if grid[i][j] == 0:
                ans.append(0)
                continue
            g[i][j] = 1
            prev = size[find(m * n)]
            if i == 0:
                union(j, m * n)
            for a, b in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and g[x][y] == 1:
                    union(i * n + j, x * n + y)
            curr = size[find(m * n)]
            ans.append(max(0, curr - prev - 1))
        return ans[::-1]
```

#### Java

```java
class Solution {
    private int[] p;
    private int[] size;

    public int[] hitBricks(int[][] grid, int[][] hits) {
        int m = grid.length;
        int n = grid[0].length;
        p = new int[m * n + 1];
        size = new int[m * n + 1];
        for (int i = 0; i < p.length; ++i) {
            p[i] = i;
            size[i] = 1;
        }
        int[][] g = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = grid[i][j];
            }
        }
        for (int[] h : hits) {
            g[h[0]][h[1]] = 0;
        }
        for (int j = 0; j < n; ++j) {
            if (g[0][j] == 1) {
                union(j, m * n);
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 0) {
                    continue;
                }
                if (g[i - 1][j] == 1) {
                    union(i * n + j, (i - 1) * n + j);
                }
                if (j > 0 && g[i][j - 1] == 1) {
                    union(i * n + j, i * n + j - 1);
                }
            }
        }
        int[] ans = new int[hits.length];
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = hits.length - 1; k >= 0; --k) {
            int i = hits[k][0];
            int j = hits[k][1];
            if (grid[i][j] == 0) {
                continue;
            }
            g[i][j] = 1;
            int prev = size[find(m * n)];
            if (i == 0) {
                union(j, m * n);
            }
            for (int l = 0; l < 4; ++l) {
                int x = i + dirs[l];
                int y = j + dirs[l + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1) {
                    union(i * n + j, x * n + y);
                }
            }
            int curr = size[find(m * n)];
            ans[k] = Math.max(0, curr - prev - 1);
        }
        return ans;
    }

    private int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    private void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            size[pb] += size[pa];
            p[pa] = pb;
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> p;
    vector<int> size;

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        p.resize(m * n + 1);
        size.resize(m * n + 1);
        for (int i = 0; i < p.size(); ++i) {
            p[i] = i;
            size[i] = 1;
        }
        vector<vector<int>> g(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = grid[i][j];
        for (auto& h : hits) g[h[0]][h[1]] = 0;
        for (int j = 0; j < n; ++j)
            if (g[0][j] == 1)
                merge(j, m * n);
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 0) continue;
                if (g[i - 1][j] == 1) merge(i * n + j, (i - 1) * n + j);
                if (j > 0 && g[i][j - 1] == 1) merge(i * n + j, i * n + j - 1);
            }
        }
        vector<int> ans(hits.size());
        vector<int> dirs = {-1, 0, 1, 0, -1};
        for (int k = hits.size() - 1; k >= 0; --k) {
            int i = hits[k][0], j = hits[k][1];
            if (grid[i][j] == 0) continue;
            g[i][j] = 1;
            int prev = size[find(m * n)];
            if (i == 0) merge(j, m * n);
            for (int l = 0; l < 4; ++l) {
                int x = i + dirs[l], y = j + dirs[l + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1)
                    merge(i * n + j, x * n + y);
            }
            int curr = size[find(m * n)];
            ans[k] = max(0, curr - prev - 1);
        }
        return ans;
    }

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void merge(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            size[pb] += size[pa];
            p[pa] = pb;
        }
    }
};
```

#### Go

```go
func hitBricks(grid [][]int, hits [][]int) []int {
	m, n := len(grid), len(grid[0])
	p := make([]int, m*n+1)
	size := make([]int, len(p))
	for i := range p {
		p[i] = i
		size[i] = 1
	}

	var find func(x int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		pa, pb := find(a), find(b)
		if pa != pb {
			size[pb] += size[pa]
			p[pa] = pb
		}
	}

	g := make([][]int, m)
	for i := range g {
		g[i] = make([]int, n)
		for j := range g[i] {
			g[i][j] = grid[i][j]
		}
	}
	for _, h := range hits {
		g[h[0]][h[1]] = 0
	}
	for j, v := range g[0] {
		if v == 1 {
			union(j, m*n)
		}
	}
	for i := 1; i < m; i++ {
		for j := 0; j < n; j++ {
			if g[i][j] == 0 {
				continue
			}
			if g[i-1][j] == 1 {
				union(i*n+j, (i-1)*n+j)
			}
			if j > 0 && g[i][j-1] == 1 {
				union(i*n+j, i*n+j-1)
			}
		}
	}
	ans := make([]int, len(hits))
	dirs := []int{-1, 0, 1, 0, -1}
	for k := len(hits) - 1; k >= 0; k-- {
		i, j := hits[k][0], hits[k][1]
		if grid[i][j] == 0 {
			continue
		}
		g[i][j] = 1
		prev := size[find(m*n)]
		if i == 0 {
			union(j, m*n)
		}
		for l := 0; l < 4; l++ {
			x, y := i+dirs[l], j+dirs[l+1]
			if x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1 {
				union(i*n+j, x*n+y)
			}
		}
		curr := size[find(m*n)]
		ans[k] = max(0, curr-prev-1)
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [804. 唯一摩尔斯密码词](https://leetcode.cn/problems/unique-morse-code-words){#804}

{{< tabs "804" >}}

{{% tab "python" %}}
```python
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        codes = [
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--..",
        ]
        s = {''.join([codes[ord(c) - ord('a')] for c in word]) for word in words}
        return len(s)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] codes = new String[] {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
            "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."};
        Set<String> s = new HashSet<>();
        for (String word : words) {
            StringBuilder t = new StringBuilder();
            for (char c : word.toCharArray()) {
                t.append(codes[c - 'a']);
            }
            s.add(t.toString());
        }
        return s.size();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (auto& word : words) {
            string t;
            for (char& c : word) t += codes[c - 'a'];
            s.insert(t);
        }
        return s.size();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func uniqueMorseRepresentations(words []string) int {
	codes := []string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
		"---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}
	s := make(map[string]bool)
	for _, word := range words {
		t := &strings.Builder{}
		for _, c := range word {
			t.WriteString(codes[c-'a'])
		}
		s[t.String()] = true
	}
	return len(s)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const codes = [
    '.-',
    '-...',
    '-.-.',
    '-..',
    '.',
    '..-.',
    '--.',
    '....',
    '..',
    '.---',
    '-.-',
    '.-..',
    '--',
    '-.',
    '---',
    '.--.',
    '--.-',
    '.-.',
    '...',
    '-',
    '..-',
    '...-',
    '.--',
    '-..-',
    '-.--',
    '--..',
];

function uniqueMorseRepresentations(words: string[]): number {
    return new Set(
        words.map(word => {
            return word
                .split('')
                .map(c => codes[c.charCodeAt(0) - 'a'.charCodeAt(0)])
                .join('');
        }),
    ).size;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashSet;
impl Solution {
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        const codes: [&str; 26] = [
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--..",
        ];
        words
            .iter()
            .map(|word| {
                word.as_bytes()
                    .iter()
                    .map(|v| codes[(v - b'a') as usize])
                    .collect::<String>()
            })
            .collect::<HashSet<String>>()
            .len() as i32
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串，&nbsp;比如:</p>

<ul>
	<li><code>'a'</code> 对应 <code>".-"</code> ，</li>
	<li><code>'b'</code> 对应 <code>"-..."</code> ，</li>
	<li><code>'c'</code> 对应 <code>"-.-."</code> ，以此类推。</li>
</ul>

<p>为了方便，所有 <code>26</code> 个英文字母的摩尔斯密码表如下：</p>

<pre>
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]</pre>

<p>给你一个字符串数组 <code>words</code> ，每个单词可以写成每个字母对应摩尔斯密码的组合。</p>

<ul>
	<li>例如，<code>"cab"</code> 可以写成 <code>"-.-..--..."</code> ，(即 <code>"-.-."</code> + <code>".-"</code> + <code>"-..."</code> 字符串的结合)。我们将这样一个连接过程称作 <strong>单词翻译</strong> 。</li>
</ul>

<p>对<strong> </strong><code>words</code> 中所有单词进行单词翻译，返回不同 <strong>单词翻译</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> words = ["gin", "zen", "gig", "msg"]
<strong>输出:</strong> 2
<strong>解释: </strong>
各单词翻译如下:
"gin" -&gt; "--...-."
"zen" -&gt; "--...-."
"gig" -&gt; "--...--."
"msg" -&gt; "--...--."

共有 2 种不同翻译, "--...-." 和 "--...--.".
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["a"]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 12</code></li>
	<li><code>words[i]</code> 由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

将 words 所有单词翻译成对应的摩尔斯密码，加入到哈希表中，最后返回哈希表的 size。

时间复杂度 $O(n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        codes = [
            ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--..",
        ]
        s = {''.join([codes[ord(c) - ord('a')] for c in word]) for word in words}
        return len(s)
```

#### Java

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] codes = new String[] {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
            "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."};
        Set<String> s = new HashSet<>();
        for (String word : words) {
            StringBuilder t = new StringBuilder();
            for (char c : word.toCharArray()) {
                t.append(codes[c - 'a']);
            }
            s.add(t.toString());
        }
        return s.size();
    }
}
```

#### C++

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
            "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (auto& word : words) {
            string t;
            for (char& c : word) t += codes[c - 'a'];
            s.insert(t);
        }
        return s.size();
    }
};
```

#### Go

```go
func uniqueMorseRepresentations(words []string) int {
	codes := []string{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
		"---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}
	s := make(map[string]bool)
	for _, word := range words {
		t := &strings.Builder{}
		for _, c := range word {
			t.WriteString(codes[c-'a'])
		}
		s[t.String()] = true
	}
	return len(s)
}
```

#### TypeScript

```ts
const codes = [
    '.-',
    '-...',
    '-.-.',
    '-..',
    '.',
    '..-.',
    '--.',
    '....',
    '..',
    '.---',
    '-.-',
    '.-..',
    '--',
    '-.',
    '---',
    '.--.',
    '--.-',
    '.-.',
    '...',
    '-',
    '..-',
    '...-',
    '.--',
    '-..-',
    '-.--',
    '--..',
];

function uniqueMorseRepresentations(words: string[]): number {
    return new Set(
        words.map(word => {
            return word
                .split('')
                .map(c => codes[c.charCodeAt(0) - 'a'.charCodeAt(0)])
                .join('');
        }),
    ).size;
}
```

#### Rust

```rust
use std::collections::HashSet;
impl Solution {
    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        const codes: [&str; 26] = [
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--..",
        ];
        words
            .iter()
            .map(|word| {
                word.as_bytes()
                    .iter()
                    .map(|v| codes[(v - b'a') as usize])
                    .collect::<String>()
            })
            .collect::<HashSet<String>>()
            .len() as i32
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [805. 数组的均值分割](https://leetcode.cn/problems/split-array-with-same-average){#805}

{{< tabs "805" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return False
        s = sum(nums)
        for i, v in enumerate(nums):
            nums[i] = v * n - s
        m = n >> 1
        vis = set()
        for i in range(1, 1 << m):
            t = sum(v for j, v in enumerate(nums[:m]) if i >> j & 1)
            if t == 0:
                return True
            vis.add(t)
        for i in range(1, 1 << (n - m)):
            t = sum(v for j, v in enumerate(nums[m:]) if i >> j & 1)
            if t == 0 or (i != (1 << (n - m)) - 1 and -t in vis):
                return True
        return False
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean splitArraySameAverage(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return false;
        }
        int s = Arrays.stream(nums).sum();
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] * n - s;
        }
        int m = n >> 1;
        Set<Integer> vis = new HashSet<>();
        for (int i = 1; i < 1 << m; ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j) {
                if (((i >> j) & 1) == 1) {
                    t += nums[j];
                }
            }
            if (t == 0) {
                return true;
            }
            vis.add(t);
        }
        for (int i = 1; i < 1 << (n - m); ++i) {
            int t = 0;
            for (int j = 0; j < (n - m); ++j) {
                if (((i >> j) & 1) == 1) {
                    t += nums[m + j];
                }
            }
            if (t == 0 || (i != (1 << (n - m)) - 1) && vis.contains(-t)) {
                return true;
            }
        }
        return false;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;
        int s = accumulate(nums.begin(), nums.end(), 0);
        for (int& v : nums) v = v * n - s;
        int m = n >> 1;
        unordered_set<int> vis;
        for (int i = 1; i < 1 << m; ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j)
                if (i >> j & 1) t += nums[j];
            if (t == 0) return true;
            vis.insert(t);
        }
        for (int i = 1; i < 1 << (n - m); ++i) {
            int t = 0;
            for (int j = 0; j < (n - m); ++j)
                if (i >> j & 1) t += nums[m + j];
            if (t == 0 || (i != (1 << (n - m)) - 1 && vis.count(-t))) return true;
        }
        return false;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitArraySameAverage(nums []int) bool {
	n := len(nums)
	if n == 1 {
		return false
	}
	s := 0
	for _, v := range nums {
		s += v
	}
	for i, v := range nums {
		nums[i] = v*n - s
	}
	m := n >> 1
	vis := map[int]bool{}
	for i := 1; i < 1<<m; i++ {
		t := 0
		for j, v := range nums[:m] {
			if (i >> j & 1) == 1 {
				t += v
			}
		}
		if t == 0 {
			return true
		}
		vis[t] = true
	}
	for i := 1; i < 1<<(n-m); i++ {
		t := 0
		for j, v := range nums[m:] {
			if (i >> j & 1) == 1 {
				t += v
			}
		}
		if t == 0 || (i != (1<<(n-m))-1 && vis[-t]) {
			return true
		}
	}
	return false
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定你一个整数数组<meta charset="UTF-8" />&nbsp;<code>nums</code></p>

<p>我们要将<meta charset="UTF-8" />&nbsp;<code>nums</code>&nbsp;数组中的每个元素移动到&nbsp;<code>A</code>&nbsp;数组 或者&nbsp;<code>B</code>&nbsp;数组中，使得&nbsp;<code>A</code>&nbsp;数组和<meta charset="UTF-8" />&nbsp;<code>B</code>&nbsp;数组不为空，并且<meta charset="UTF-8" />&nbsp;<code>average(A) == average(B)</code>&nbsp;。</p>

<p>如果可以完成则返回<code>true</code>&nbsp;， 否则返回 <code>false</code>&nbsp;&nbsp;。</p>

<p><strong>注意：</strong>对于数组<meta charset="UTF-8" />&nbsp;<code>arr</code>&nbsp;, <meta charset="UTF-8" />&nbsp;<code>average(arr)</code>&nbsp;是<meta charset="UTF-8" />&nbsp;<code>arr</code>&nbsp;的所有元素的和除以<meta charset="UTF-8" />&nbsp;<code>arr</code>&nbsp;长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,3,4,5,6,7,8]
<strong>输出:</strong> true
<strong>解释: </strong>我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [3,1]
<strong>输出:</strong> false
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 30</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：折半查找 + 二进制枚举

根据题目要求，要判断是否可以将数组 $\textit{nums}$ 划分为两个子数组 $A$ 和 $B$，使得两个子数组的平均值相等。

我们记数组 $\textit{nums}$ 的和为 $s$，元素个数为 $n$。子数组 $A$ 的和以及个数分别为 $s_1$ 和 $k$，那么子数组 $B$ 的和为 $s_2 = s - s_1$，个数为 $n - k$，即：

$$
\frac{s_1}{k} = \frac{s_2}{n - k} = \frac{s-s_1}{n-k}
$$

整理可得：

$$
s_1 \times (n-k) = (s-s_1) \times k
$$

化简可得：

$$
\frac{s_1}{k} = \frac{s}{n}
$$

也就是说，要我们找出一个子数组 $A$，使得其平均值等于数组 $\textit{nums}$ 的平均值。我们考虑将数组 $\textit{nums}$ 每个元素都减去数组 $\textit{nums}$ 的平均值，这样问题就转化为了在数组 $\textit{nums}$ 中找出一个子数组，使得其和为 $0$。

但是，数组 $\textit{nums}$ 的平均值可能不是整数，浮点数计算可能存在精度问题，我们不妨将数组 $\textit{nums}$ 中的每个元素都乘以 $n$，即 $nums[i] \leftarrow nums[i] \times n$，上述式子就变成：

$$
\frac{s_1\times n}{k} = s
$$

此时我们将数组 $\textit{nums}$ 中每个元素都减去整数 $s$，题目就转化为：在数组 $nums$ 中找出一个子数组 $A$，使得其和为 $0$。

数组 $\textit{nums}$ 的长度范围为 $[1, 30]$，如果我们使用暴力枚举子数组的方法，时间复杂度为 $O(2^n)$，会超时。我们可以使用折半查找的方法，将时间复杂度降低到 $O(2^{n/2})$。

我们将数组 $\textit{nums}$ 分成左右两部分，那么子数组 $A$ 可能存在三种情况：

1. 子数组 $A$ 完全在数组 $\textit{nums}$ 的左半部分；
2. 子数组 $A$ 完全在数组 $\textit{nums}$ 的右半部分；
3. 子数组 $A$ 一部分在数组 $\textit{nums}$ 的左半部分，一部分在数组 $\textit{nums}$ 的右半部分。

我们可以使用二进制枚举的方法，先枚举左半部分所有子数组的和，如果存在一个子数组和为 $0$，直接返回 `true`，否则我们将其存入哈希表 $\textit{vis}$ 中；然后枚举右半部分所有子数组的和，如果存在一个子数组和为 $0$，直接返回 `true`，否则我们判断此时哈希表 $\textit{vis}$ 中是否存在该和的相反数，如果存在，直接返回 `true`。

需要注意的是，我们不能同时全选左半部分和右半部分，因为这样会导致子数组 $B$ 为空，这是不符合题意的。在实现上，我们只需要考虑数组的 $n-1$ 个数。

时间复杂度 $O(n\times 2^{\frac{n}{2}})$，空间复杂度 $O(2^{\frac{n}{2}})$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitArraySameAverage(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return False
        s = sum(nums)
        for i, v in enumerate(nums):
            nums[i] = v * n - s
        m = n >> 1
        vis = set()
        for i in range(1, 1 << m):
            t = sum(v for j, v in enumerate(nums[:m]) if i >> j & 1)
            if t == 0:
                return True
            vis.add(t)
        for i in range(1, 1 << (n - m)):
            t = sum(v for j, v in enumerate(nums[m:]) if i >> j & 1)
            if t == 0 or (i != (1 << (n - m)) - 1 and -t in vis):
                return True
        return False
```

#### Java

```java
class Solution {
    public boolean splitArraySameAverage(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return false;
        }
        int s = Arrays.stream(nums).sum();
        for (int i = 0; i < n; ++i) {
            nums[i] = nums[i] * n - s;
        }
        int m = n >> 1;
        Set<Integer> vis = new HashSet<>();
        for (int i = 1; i < 1 << m; ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j) {
                if (((i >> j) & 1) == 1) {
                    t += nums[j];
                }
            }
            if (t == 0) {
                return true;
            }
            vis.add(t);
        }
        for (int i = 1; i < 1 << (n - m); ++i) {
            int t = 0;
            for (int j = 0; j < (n - m); ++j) {
                if (((i >> j) & 1) == 1) {
                    t += nums[m + j];
                }
            }
            if (t == 0 || (i != (1 << (n - m)) - 1) && vis.contains(-t)) {
                return true;
            }
        }
        return false;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;
        int s = accumulate(nums.begin(), nums.end(), 0);
        for (int& v : nums) v = v * n - s;
        int m = n >> 1;
        unordered_set<int> vis;
        for (int i = 1; i < 1 << m; ++i) {
            int t = 0;
            for (int j = 0; j < m; ++j)
                if (i >> j & 1) t += nums[j];
            if (t == 0) return true;
            vis.insert(t);
        }
        for (int i = 1; i < 1 << (n - m); ++i) {
            int t = 0;
            for (int j = 0; j < (n - m); ++j)
                if (i >> j & 1) t += nums[m + j];
            if (t == 0 || (i != (1 << (n - m)) - 1 && vis.count(-t))) return true;
        }
        return false;
    }
};
```

#### Go

```go
func splitArraySameAverage(nums []int) bool {
	n := len(nums)
	if n == 1 {
		return false
	}
	s := 0
	for _, v := range nums {
		s += v
	}
	for i, v := range nums {
		nums[i] = v*n - s
	}
	m := n >> 1
	vis := map[int]bool{}
	for i := 1; i < 1<<m; i++ {
		t := 0
		for j, v := range nums[:m] {
			if (i >> j & 1) == 1 {
				t += v
			}
		}
		if t == 0 {
			return true
		}
		vis[t] = true
	}
	for i := 1; i < 1<<(n-m); i++ {
		t := 0
		for j, v := range nums[m:] {
			if (i >> j & 1) == 1 {
				t += v
			}
		}
		if t == 0 || (i != (1<<(n-m))-1 && vis[-t]) {
			return true
		}
	}
	return false
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [806. 写字符串需要的行数](https://leetcode.cn/problems/number-of-lines-to-write-string){#806}

{{< tabs "806" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        lines, last = 1, 0
        for w in map(lambda c: widths[ord(c) - ord("a")], s):
            if last + w <= 100:
                last += w
            else:
                lines += 1
                last = w
        return [lines, last]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] numberOfLines(int[] widths, String s) {
        int lines = 1, last = 0;
        for (int i = 0; i < s.length(); ++i) {
            int w = widths[s.charAt(i) - 'a'];
            if (last + w <= 100) {
                last += w;
            } else {
                ++lines;
                last = w;
            }
        }
        return new int[] {lines, last};
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, last = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (last + w <= 100) {
                last += w;
            } else {
                ++lines;
                last = w;
            }
        }
        return {lines, last};
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfLines(widths []int, s string) []int {
	lines, last := 1, 0
	for _, c := range s {
		w := widths[c-'a']
		if last+w <= 100 {
			last += w
		} else {
			lines++
			last = w
		}
	}
	return []int{lines, last}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfLines(widths: number[], s: string): number[] {
    let [lines, last] = [1, 0];
    for (const c of s) {
        const w = widths[c.charCodeAt(0) - 'a'.charCodeAt(0)];
        if (last + w <= 100) {
            last += w;
        } else {
            ++lines;
            last = w;
        }
    }
    return [lines, last];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let mut lines = 1;
        let mut last = 0;

        for c in s.chars() {
            let idx = ((c as u8) - b'a') as usize;
            let w = widths[idx];
            if last + w <= 100 {
                last += w;
            } else {
                lines += 1;
                last = w;
            }
        }

        vec![lines, last]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>我们要把给定的字符串 <code>S</code>&nbsp;从左到右写到每一行上，每一行的最大宽度为100个单位，如果我们在写某个字母的时候会使这行超过了100 个单位，那么我们应该把这个字母写到下一行。我们给定了一个数组&nbsp;<code>widths</code>&nbsp;，这个数组&nbsp;widths[0] 代表 &#39;a&#39; 需要的单位，&nbsp;widths[1] 代表 &#39;b&#39; 需要的单位，...，&nbsp;widths[25] 代表 &#39;z&#39; 需要的单位。</p>

<p>现在回答两个问题：至少多少行能放下<code>S</code>，以及最后一行使用的宽度是多少个单位？将你的答案作为长度为2的整数列表返回。</p>

<pre>
<strong>示例 1:</strong>
<strong>输入:</strong> 
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = &quot;abcdefghijklmnopqrstuvwxyz&quot;
<strong>输出:</strong> [3, 60]
<strong>解释: 
</strong>所有的字符拥有相同的占用单位10。所以书写所有的26个字母，
我们需要2个整行和占用60个单位的一行。
</pre>

<pre>
<strong>示例 2:</strong>
<strong>输入:</strong> 
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = &quot;bbbcccdddaaa&quot;
<strong>输出:</strong> [2, 4]
<strong>解释: 
</strong>除去字母&#39;a&#39;所有的字符都是相同的单位10，并且字符串 &quot;bbbcccdddaa&quot; 将会覆盖 9 * 10 + 2 * 4 = 98 个单位.
最后一个字母 &#39;a&#39; 将会被写到第二行，因为第一行只剩下2个单位了。
所以，这个答案是2行，第二行有4个单位宽度。
</pre>

<p>&nbsp;</p>

<p><strong>注:</strong></p>

<ul>
	<li>字符串&nbsp;<code>S</code> 的长度在&nbsp;[1, 1000] 的范围。</li>
	<li><code>S</code> 只包含小写字母。</li>
	<li><code>widths</code> 是长度为&nbsp;<code>26</code>的数组。</li>
	<li><code>widths[i]</code>&nbsp;值的范围在&nbsp;<code>[2, 10]</code>。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们定义两个变量 `lines` 和 `last`，分别表示行数和最后一行的宽度，初始时 `lines = 1`，`last = 0`。

遍历字符串 $s$，对于每个字符 $c$，计算其宽度 $w$，如果 $last + w \leq 100$，则将 $w$ 加到 `last` 上，否则行数 `lines` 加一，并且 `last` 重置为 $w$。

最后返回 `lines` 和 `last` 构成的数组。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        lines, last = 1, 0
        for w in map(lambda c: widths[ord(c) - ord("a")], s):
            if last + w <= 100:
                last += w
            else:
                lines += 1
                last = w
        return [lines, last]
```

#### Java

```java
class Solution {
    public int[] numberOfLines(int[] widths, String s) {
        int lines = 1, last = 0;
        for (int i = 0; i < s.length(); ++i) {
            int w = widths[s.charAt(i) - 'a'];
            if (last + w <= 100) {
                last += w;
            } else {
                ++lines;
                last = w;
            }
        }
        return new int[] {lines, last};
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, last = 0;
        for (char c : s) {
            int w = widths[c - 'a'];
            if (last + w <= 100) {
                last += w;
            } else {
                ++lines;
                last = w;
            }
        }
        return {lines, last};
    }
};
```

#### Go

```go
func numberOfLines(widths []int, s string) []int {
	lines, last := 1, 0
	for _, c := range s {
		w := widths[c-'a']
		if last+w <= 100 {
			last += w
		} else {
			lines++
			last = w
		}
	}
	return []int{lines, last}
}
```

#### TypeScript

```ts
function numberOfLines(widths: number[], s: string): number[] {
    let [lines, last] = [1, 0];
    for (const c of s) {
        const w = widths[c.charCodeAt(0) - 'a'.charCodeAt(0)];
        if (last + w <= 100) {
            last += w;
        } else {
            ++lines;
            last = w;
        }
    }
    return [lines, last];
}
```

#### Rust

```rust
impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let mut lines = 1;
        let mut last = 0;

        for c in s.chars() {
            let idx = ((c as u8) - b'a') as usize;
            let w = widths[idx];
            if last + w <= 100 {
                last += w;
            } else {
                lines += 1;
                last = w;
            }
        }

        vec![lines, last]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [807. 保持城市天际线](https://leetcode.cn/problems/max-increase-to-keep-city-skyline){#807}

{{< tabs "807" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        row_max = [max(row) for row in grid]
        col_max = [max(col) for col in zip(*grid)]
        return sum(
            min(row_max[i], col_max[j]) - x
            for i, row in enumerate(grid)
            for j, x in enumerate(row)
        )
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = Math.max(rowMax[i], grid[i][j]);
                colMax[j] = Math.max(colMax[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += Math.min(rowMax[i], colMax[j]) - grid[i][j];
            }
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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowMax(m);
        vector<int> colMax(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxIncreaseKeepingSkyline(grid [][]int) (ans int) {
	rowMax := make([]int, len(grid))
	colMax := make([]int, len(grid[0]))
	for i, row := range grid {
		for j, x := range row {
			rowMax[i] = max(rowMax[i], x)
			colMax[j] = max(colMax[j], x)
		}
	}
	for i, row := range grid {
		for j, x := range row {
			ans += min(rowMax[i], colMax[j]) - x
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxIncreaseKeepingSkyline(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const rowMax = Array(m).fill(0);
    const colMax = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            rowMax[i] = Math.max(rowMax[i], grid[i][j]);
            colMax[j] = Math.max(colMax[j], grid[i][j]);
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans += Math.min(rowMax[i], colMax[j]) - grid[i][j];
        }
    }
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一座由 <code>n x n</code> 个街区组成的城市，每个街区都包含一座立方体建筑。给你一个下标从 <strong>0</strong> 开始的 <code>n x n</code> 整数矩阵 <code>grid</code> ，其中 <code>grid[r][c]</code> 表示坐落于 <code>r</code> 行 <code>c</code> 列的建筑物的 <strong>高度</strong> 。</p>

<p>城市的 <strong>天际线</strong> 是从远处观察城市时，所有建筑物形成的外部轮廓。从东、南、西、北四个主要方向观测到的 <strong>天际线</strong> 可能不同。</p>

<p>我们被允许为 <strong>任意数量的建筑物 </strong>的高度增加<strong> 任意增量（不同建筑物的增量可能不同）</strong> 。 高度为 <code>0</code> 的建筑物的高度也可以增加。然而，增加的建筑物高度 <strong>不能影响</strong> 从任何主要方向观察城市得到的 <strong>天际线</strong> 。</p>

<p>在 <strong>不改变</strong> 从任何主要方向观测到的城市 <strong>天际线</strong> 的前提下，返回建筑物可以增加的 <strong>最大高度增量总和</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0807.Max%20Increase%20to%20Keep%20City%20Skyline/images/807-ex1.png" style="width: 700px; height: 603px;" />
<pre>
<strong>输入：</strong>grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
<strong>输出：</strong>35
<strong>解释：</strong>建筑物的高度如上图中心所示。
用红色绘制从不同方向观看得到的天际线。
在不影响天际线的情况下，增加建筑物的高度：
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[0,0,0],[0,0,0],[0,0,0]]
<strong>输出：</strong>0
<strong>解释：</strong>增加任何建筑物的高度都会导致天际线的变化。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == grid.length</code></li>
	<li><code>n == grid[r].length</code></li>
	<li><code>2 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[r][c] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

根据题目描述，我们可以将每个单元格 $(i, j)$ 的值增加至第 $i$ 行的最大值和第 $j$ 列的最大值中的较小值，这样可以保证不影响天际线，即每个单元格增加的高度为 $\min(\textit{rowMax}[i], \textit{colMax}[j]) - \textit{grid}[i][j]$。

因此，我们可以先遍历一次矩阵，分别计算出每行和每列的最大值，记录在数组 $\textit{rowMax}$ 和 $\textit{colMax}$ 中，然后再遍历一次矩阵，计算出答案即可。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 为矩阵 $\textit{grid}$ 的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        row_max = [max(row) for row in grid]
        col_max = [max(col) for col in zip(*grid)]
        return sum(
            min(row_max[i], col_max[j]) - x
            for i, row in enumerate(grid)
            for j, x in enumerate(row)
        )
```

#### Java

```java
class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] rowMax = new int[m];
        int[] colMax = new int[n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = Math.max(rowMax[i], grid[i][j]);
                colMax[j] = Math.max(colMax[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += Math.min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rowMax(m);
        vector<int> colMax(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxIncreaseKeepingSkyline(grid [][]int) (ans int) {
	rowMax := make([]int, len(grid))
	colMax := make([]int, len(grid[0]))
	for i, row := range grid {
		for j, x := range row {
			rowMax[i] = max(rowMax[i], x)
			colMax[j] = max(colMax[j], x)
		}
	}
	for i, row := range grid {
		for j, x := range row {
			ans += min(rowMax[i], colMax[j]) - x
		}
	}
	return
}
```

#### TypeScript

```ts
function maxIncreaseKeepingSkyline(grid: number[][]): number {
    const m = grid.length;
    const n = grid[0].length;
    const rowMax = Array(m).fill(0);
    const colMax = Array(n).fill(0);
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            rowMax[i] = Math.max(rowMax[i], grid[i][j]);
            colMax[j] = Math.max(colMax[j], grid[i][j]);
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans += Math.min(rowMax[i], colMax[j]) - grid[i][j];
        }
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [808. 分汤](https://leetcode.cn/problems/soup-servings){#808}

{{< tabs "808" >}}

{{% tab "python" %}}
```python
class Solution:
    def soupServings(self, n: int) -> float:
        @cache
        def dfs(i: int, j: int) -> float:
            if i <= 0 and j <= 0:
                return 0.5
            if i <= 0:
                return 1
            if j <= 0:
                return 0
            return 0.25 * (
                dfs(i - 4, j)
                + dfs(i - 3, j - 1)
                + dfs(i - 2, j - 2)
                + dfs(i - 1, j - 3)
            )

        return 1 if n > 4800 else dfs((n + 24) // 25, (n + 24) // 25)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private double[][] f = new double[200][200];

    public double soupServings(int n) {
        return n > 4800 ? 1 : dfs((n + 24) / 25, (n + 24) / 25);
    }

    private double dfs(int i, int j) {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1.0;
        }
        if (j <= 0) {
            return 0;
        }
        if (f[i][j] > 0) {
            return f[i][j];
        }
        double ans
            = 0.25 * (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3));
        f[i][j] = ans;
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double soupServings(int n) {
        double f[200][200] = {0.0};
        auto dfs = [&](this auto&& dfs, int i, int j) -> double {
            if (i <= 0 && j <= 0) return 0.5;
            if (i <= 0) return 1;
            if (j <= 0) return 0;
            if (f[i][j] > 0) return f[i][j];
            double ans = 0.25 * (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3));
            f[i][j] = ans;
            return ans;
        };
        return n > 4800 ? 1 : dfs((n + 24) / 25, (n + 24) / 25);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func soupServings(n int) float64 {
	if n > 4800 {
		return 1
	}
	f := [200][200]float64{}
	var dfs func(i, j int) float64
	dfs = func(i, j int) float64 {
		if i <= 0 && j <= 0 {
			return 0.5
		}
		if i <= 0 {
			return 1.0
		}
		if j <= 0 {
			return 0
		}
		if f[i][j] > 0 {
			return f[i][j]
		}
		ans := 0.25 * (dfs(i-4, j) + dfs(i-3, j-1) + dfs(i-2, j-2) + dfs(i-1, j-3))
		f[i][j] = ans
		return ans
	}
	return dfs((n+24)/25, (n+24)/25)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function soupServings(n: number): number {
    const f = Array.from({ length: 200 }, () => Array(200).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1;
        }
        if (j <= 0) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        f[i][j] =
            0.25 * (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3));
        return f[i][j];
    };
    return n >= 4800 ? 1 : dfs(Math.ceil(n / 25), Math.ceil(n / 25));
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn soup_servings(n: i32) -> f64 {
        if n > 4800 {
            return 1.0;
        }
        Self::dfs((n + 24) / 25, (n + 24) / 25)
    }

    fn dfs(i: i32, j: i32) -> f64 {
        static mut F: [[f64; 200]; 200] = [[0.0; 200]; 200];

        unsafe {
            if i <= 0 && j <= 0 {
                return 0.5;
            }
            if i <= 0 {
                return 1.0;
            }
            if j <= 0 {
                return 0.0;
            }
            if F[i as usize][j as usize] > 0.0 {
                return F[i as usize][j as usize];
            }

            let ans = 0.25 * (Self::dfs(i - 4, j) + Self::dfs(i - 3, j - 1) + Self::dfs(i - 2, j - 2) + Self::dfs(i - 1, j - 3));
            F[i as usize][j as usize] = ans;
            ans
        }
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private double[,] f = new double[200, 200];

    public double SoupServings(int n) {
        if (n > 4800) {
            return 1.0;
        }

        return Dfs((n + 24) / 25, (n + 24) / 25);
    }

    private double Dfs(int i, int j) {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1.0;
        }
        if (j <= 0) {
            return 0.0;
        }
        if (f[i, j] > 0) {
            return f[i, j];
        }

        double ans = 0.25 * (Dfs(i - 4, j) + Dfs(i - 3, j - 1) + Dfs(i - 2, j - 2) + Dfs(i - 1, j - 3));
        f[i, j] = ans;
        return ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有两种汤，<strong>A</strong> 和 <strong>B</strong>，每种初始为 <code>n</code>&nbsp;毫升。在每一轮中，会随机选择以下四种操作中的一种，每种操作的概率为 <code>0.25</code>，且与之前的所有轮次 <strong>无关</strong>：</p>

<ol>
	<li>从汤 A 取 100 毫升，从汤 B 取 0 毫升</li>
	<li>从汤 A 取 75 毫升，从汤 B 取 25 毫升</li>
	<li>从汤 A 取 50 毫升，从汤 B 取 50 毫升</li>
	<li>从汤 A 取 25 毫升，从汤 B 取 75 毫升</li>
</ol>

<p><strong>注意：</strong></p>

<ul>
	<li>不存在从汤 A 取&nbsp;<code>0</code>&nbsp;ml 和从汤 B 取&nbsp;<code>100</code> ml 的操作。</li>
	<li>汤 A 和 B 在每次操作中同时被取出。</li>
	<li>如果一次操作要求你取出比剩余的汤更多的量，请取出该汤剩余的所有部分。</li>
</ul>

<p>操作过程在任何回合中任一汤被取完后立即停止。</p>

<p>返回汤 A 在 B 前取完的概率，加上两种汤在 <strong>同一回合&nbsp;</strong>取完概率的一半。返回值在正确答案&nbsp;<code>10<sup>-5</sup></code>&nbsp;的范围内将被认为是正确的。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>n = 50
<strong>输出：</strong>0.62500
<strong>解释：
</strong>如果我们选择前两个操作<strong>，</strong>A 首先将变为空。
对于第三个操作，A 和 B 会同时变为空。
对于第四个操作，B 首先将变为空。<strong>
</strong>所以 A 变为空的总概率加上 A 和 B 同时变为空的概率的一半是 0.25 *(1 + 1 + 0.5 + 0)= 0.625。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入：</strong>n = 100
<strong>输出：</strong>0.71875
<strong>解释：</strong>
如果我们选择第一个操作，A 首先将变为空。
如果我们选择第二个操作，A 将在执行操作 [1, 2, 3] 时变为空，然后 A 和 B 在执行操作 4 时同时变空。
如果我们选择第三个操作，A 将在执行操作 [1, 2] 时变为空，然后 A 和 B 在执行操作 3 时同时变空。
如果我们选择第四个操作，A 将在执行操作 1 时变为空，然后 A 和 B 在执行操作 2 时同时变空。
所以 A 变为空的总概率加上 A 和 B 同时变为空的概率的一半是 0.71875。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

在这道题中，由于每次操作都是 $25$ 的倍数，因此，我们可以将每 $25ml$ 的汤视为一份。这样就能将数据规模缩小到 $\left \lceil \frac{n}{25} \right \rceil$。

我们设计一个函数 $dfs(i, j)$，表示当前剩余 $i$ 份汤 $A$ 和 $j$ 份汤 $B$ 的结果概率。

当 $i \leq 0$ 并且 $j \leq 0$ 时，表示两种汤都分配完了，此时应该返回 $0.5$；当 $i \leq 0$ 时，表示汤 $A$ 先分配完了，此时应该返回 $1$；当 $j \leq 0$ 时，表示汤 $B$ 先分配完了，此时应该返回 $0$。

接下来，对于每一次操作，我们都有四种选择，即：

-   从 $i$ 份汤 $A$ 中取出 $4$ 份，从 $j$ 份汤 $B$ 中取出 $0$ 份；
-   从 $i$ 份汤 $A$ 中取出 $3$ 份，从 $j$ 份汤 $B$ 中取出 $1$ 份；
-   从 $i$ 份汤 $A$ 中取出 $2$ 份，从 $j$ 份汤 $B$ 中取出 $2$ 份；
-   从 $i$ 份汤 $A$ 中取出 $1$ 份，从 $j$ 份汤 $B$ 中取出 $3$ 份；

每一种选择的概率都是 $0.25$，因此，我们可以得到：

$$
dfs(i, j) = 0.25 \times (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3))
$$

记忆化搜索即可。

另外，我们发现在 $n=4800$ 时，结果为 $0.999994994426$，而题目要求的精度为 $10^{-5}$，并且随着 $n$ 的增大，结果越来越接近 $1$，因此，当 $n \gt 4800$ 时，直接返回 $1$ 即可。

时间复杂度 $O(C^2)$，空间复杂度 $O(C^2)$。本题中 $C=200$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def soupServings(self, n: int) -> float:
        @cache
        def dfs(i: int, j: int) -> float:
            if i <= 0 and j <= 0:
                return 0.5
            if i <= 0:
                return 1
            if j <= 0:
                return 0
            return 0.25 * (
                dfs(i - 4, j)
                + dfs(i - 3, j - 1)
                + dfs(i - 2, j - 2)
                + dfs(i - 1, j - 3)
            )

        return 1 if n > 4800 else dfs((n + 24) // 25, (n + 24) // 25)
```

#### Java

```java
class Solution {
    private double[][] f = new double[200][200];

    public double soupServings(int n) {
        return n > 4800 ? 1 : dfs((n + 24) / 25, (n + 24) / 25);
    }

    private double dfs(int i, int j) {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1.0;
        }
        if (j <= 0) {
            return 0;
        }
        if (f[i][j] > 0) {
            return f[i][j];
        }
        double ans
            = 0.25 * (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3));
        f[i][j] = ans;
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double soupServings(int n) {
        double f[200][200] = {0.0};
        auto dfs = [&](this auto&& dfs, int i, int j) -> double {
            if (i <= 0 && j <= 0) return 0.5;
            if (i <= 0) return 1;
            if (j <= 0) return 0;
            if (f[i][j] > 0) return f[i][j];
            double ans = 0.25 * (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3));
            f[i][j] = ans;
            return ans;
        };
        return n > 4800 ? 1 : dfs((n + 24) / 25, (n + 24) / 25);
    }
};
```

#### Go

```go
func soupServings(n int) float64 {
	if n > 4800 {
		return 1
	}
	f := [200][200]float64{}
	var dfs func(i, j int) float64
	dfs = func(i, j int) float64 {
		if i <= 0 && j <= 0 {
			return 0.5
		}
		if i <= 0 {
			return 1.0
		}
		if j <= 0 {
			return 0
		}
		if f[i][j] > 0 {
			return f[i][j]
		}
		ans := 0.25 * (dfs(i-4, j) + dfs(i-3, j-1) + dfs(i-2, j-2) + dfs(i-1, j-3))
		f[i][j] = ans
		return ans
	}
	return dfs((n+24)/25, (n+24)/25)
}
```

#### TypeScript

```ts
function soupServings(n: number): number {
    const f = Array.from({ length: 200 }, () => Array(200).fill(-1));
    const dfs = (i: number, j: number): number => {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1;
        }
        if (j <= 0) {
            return 0;
        }
        if (f[i][j] !== -1) {
            return f[i][j];
        }
        f[i][j] =
            0.25 * (dfs(i - 4, j) + dfs(i - 3, j - 1) + dfs(i - 2, j - 2) + dfs(i - 1, j - 3));
        return f[i][j];
    };
    return n >= 4800 ? 1 : dfs(Math.ceil(n / 25), Math.ceil(n / 25));
}
```

#### Rust

```rust
impl Solution {
    pub fn soup_servings(n: i32) -> f64 {
        if n > 4800 {
            return 1.0;
        }
        Self::dfs((n + 24) / 25, (n + 24) / 25)
    }

    fn dfs(i: i32, j: i32) -> f64 {
        static mut F: [[f64; 200]; 200] = [[0.0; 200]; 200];

        unsafe {
            if i <= 0 && j <= 0 {
                return 0.5;
            }
            if i <= 0 {
                return 1.0;
            }
            if j <= 0 {
                return 0.0;
            }
            if F[i as usize][j as usize] > 0.0 {
                return F[i as usize][j as usize];
            }

            let ans = 0.25 * (Self::dfs(i - 4, j) + Self::dfs(i - 3, j - 1) + Self::dfs(i - 2, j - 2) + Self::dfs(i - 1, j - 3));
            F[i as usize][j as usize] = ans;
            ans
        }
    }
}
```

#### C#

```cs
public class Solution {
    private double[,] f = new double[200, 200];

    public double SoupServings(int n) {
        if (n > 4800) {
            return 1.0;
        }

        return Dfs((n + 24) / 25, (n + 24) / 25);
    }

    private double Dfs(int i, int j) {
        if (i <= 0 && j <= 0) {
            return 0.5;
        }
        if (i <= 0) {
            return 1.0;
        }
        if (j <= 0) {
            return 0.0;
        }
        if (f[i, j] > 0) {
            return f[i, j];
        }

        double ans = 0.25 * (Dfs(i - 4, j) + Dfs(i - 3, j - 1) + Dfs(i - 2, j - 2) + Dfs(i - 1, j - 3));
        f[i, j] = ans;
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [809. 情感丰富的文字](https://leetcode.cn/problems/expressive-words){#809}

{{< tabs "809" >}}

{{% tab "python" %}}
```python
class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        def check(s, t):
            m, n = len(s), len(t)
            if n > m:
                return False
            i = j = 0
            while i < m and j < n:
                if s[i] != t[j]:
                    return False
                k = i
                while k < m and s[k] == s[i]:
                    k += 1
                c1 = k - i
                i, k = k, j
                while k < n and t[k] == t[j]:
                    k += 1
                c2 = k - j
                j = k
                if c1 < c2 or (c1 < 3 and c1 != c2):
                    return False
            return i == m and j == n

        return sum(check(s, t) for t in words)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int expressiveWords(String s, String[] words) {
        int ans = 0;
        for (String t : words) {
            if (check(s, t)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        if (n > m) {
            return false;
        }
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s.charAt(i) != t.charAt(j)) {
                return false;
            }
            int k = i;
            while (k < m && s.charAt(k) == s.charAt(i)) {
                ++k;
            }
            int c1 = k - i;
            i = k;
            k = j;
            while (k < n && t.charAt(k) == t.charAt(j)) {
                ++k;
            }
            int c2 = k - j;
            j = k;
            if (c1 < c2 || (c1 < 3 && c1 != c2)) {
                return false;
            }
        }
        return i == m && j == n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        auto check = [](string& s, string& t) -> int {
            int m = s.size(), n = t.size();
            if (n > m) return 0;
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (s[i] != t[j]) return 0;
                int k = i;
                while (k < m && s[k] == s[i]) ++k;
                int c1 = k - i;
                i = k, k = j;
                while (k < n && t[k] == t[j]) ++k;
                int c2 = k - j;
                j = k;
                if (c1 < c2 || (c1 < 3 && c1 != c2)) return 0;
            }
            return i == m && j == n;
        };

        int ans = 0;
        for (string& t : words) ans += check(s, t);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func expressiveWords(s string, words []string) (ans int) {
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		if n > m {
			return false
		}
		i, j := 0, 0
		for i < m && j < n {
			if s[i] != t[j] {
				return false
			}
			k := i
			for k < m && s[k] == s[i] {
				k++
			}
			c1 := k - i
			i, k = k, j
			for k < n && t[k] == t[j] {
				k++
			}
			c2 := k - j
			j = k
			if c1 < c2 || (c1 != c2 && c1 < 3) {
				return false
			}
		}
		return i == m && j == n
	}
	for _, t := range words {
		if check(s, t) {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有时候人们会用重复写一些字母来表示额外的感受，比如 <code>"hello" -&gt; "heeellooo"</code>, <code>"hi" -&gt; "hiii"</code>。我们将相邻字母都相同的一串字符定义为相同字母组，例如："h", "eee", "ll", "ooo"。</p>

<p>对于一个给定的字符串 S ，如果另一个单词能够通过将一些字母组扩张从而使其和 S 相同，我们将这个单词定义为可扩张的（stretchy）。扩张操作定义如下：选择一个字母组（包含字母&nbsp;<code>c</code>&nbsp;），然后往其中添加相同的字母&nbsp;<code>c</code>&nbsp;使其长度达到 3 或以上。</p>

<p>例如，以&nbsp;"hello" 为例，我们可以对字母组&nbsp;"o" 扩张得到 "hellooo"，但是无法以同样的方法得到 "helloo" 因为字母组 "oo" 长度小于&nbsp;3。此外，我们可以进行另一种扩张 "ll" -&gt; "lllll" 以获得&nbsp;"helllllooo"。如果&nbsp;<code>s = "helllllooo"</code>，那么查询词&nbsp;"hello" 是可扩张的，因为可以对它执行这两种扩张操作使得&nbsp;<code>query = "hello" -&gt; "hellooo" -&gt;&nbsp;"helllllooo" = s</code>。</p>

<p>输入一组查询单词，输出其中可扩张的单词数量。</p>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong> 
s = "heeellooo"
words = ["hello", "hi", "helo"]
<strong>输出：</strong>1
<strong>解释</strong>：
我们能通过扩张 "hello" 的 "e" 和 "o" 来得到 "heeellooo"。
我们不能通过扩张 "helo" 来得到 "heeellooo" 因为 "ll" 的长度小于 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><font color="#c7254e" face="Menlo, Monaco, Consolas, Courier New, monospace"><span style="font-size: 12.6px; background-color: rgb(249, 242, 244);">s</span></font> 和所有在&nbsp;<code>words</code>&nbsp;中的单词都只由小写字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数 + 双指针

我们可以遍历数组 $\textit{words}$，对于数组中的每个单词 $t$，判断 $t$ 是否可以通过扩张得到 $s$，如果可以，那么答案加一。

因此，问题的关键在于判断单词 $t$ 是否可以通过扩张得到 $s$。这里我们通过一个 $\textit{check}(s, t)$ 函数来判断。函数的具体实现逻辑如下：

首先判断 $s$ 和 $t$ 的长度关系，如果 $t$ 的长度大于 $s$，直接返回 $\textit{false}$；否则，我们用双指针 $i$ 和 $j$ 分别指向 $s$ 和 $t$，初始时 $i$ 和 $j$ 的值均为 $0$。

如果 $i$ 和 $j$ 指向的字符不同，那么 $t$ 无法通过扩张得到 $s$，直接返回 $\textit{false}$；否则，我们需要判断 $i$ 指向的字符的连续出现次数 $c_1$ 和 $j$ 指向的字符的连续出现次数 $c_2$ 的关系。如果 $c_1 \lt c_2$ 或者 $c_1 \lt 3$ 并且 $c_1 \neq c_2$，那么 $t$ 无法通过扩张得到 $s$，直接返回 $\textit{false}$；否则，将 $i$ 和 $j$ 分别右移 $c_1$ 和 $c_2$ 次。继续判断。

如果 $i$ 和 $j$ 都到达了字符串的末尾，那么 $t$ 可以通过扩张得到 $s$，返回 $\textit{true}$，否则返回 $\textit{false}$。

时间复杂度 $O(n \times m + \sum_{i=0}^{m-1} w_i)$，其中 $n$ 和 $m$ 分别为字符串 $s$ 和数组 $\textit{words}$ 的长度，而 $w_i$ 为数组 $\textit{words}$ 中第 $i$ 个单词的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        def check(s, t):
            m, n = len(s), len(t)
            if n > m:
                return False
            i = j = 0
            while i < m and j < n:
                if s[i] != t[j]:
                    return False
                k = i
                while k < m and s[k] == s[i]:
                    k += 1
                c1 = k - i
                i, k = k, j
                while k < n and t[k] == t[j]:
                    k += 1
                c2 = k - j
                j = k
                if c1 < c2 or (c1 < 3 and c1 != c2):
                    return False
            return i == m and j == n

        return sum(check(s, t) for t in words)
```

#### Java

```java
class Solution {
    public int expressiveWords(String s, String[] words) {
        int ans = 0;
        for (String t : words) {
            if (check(s, t)) {
                ++ans;
            }
        }
        return ans;
    }

    private boolean check(String s, String t) {
        int m = s.length(), n = t.length();
        if (n > m) {
            return false;
        }
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s.charAt(i) != t.charAt(j)) {
                return false;
            }
            int k = i;
            while (k < m && s.charAt(k) == s.charAt(i)) {
                ++k;
            }
            int c1 = k - i;
            i = k;
            k = j;
            while (k < n && t.charAt(k) == t.charAt(j)) {
                ++k;
            }
            int c2 = k - j;
            j = k;
            if (c1 < c2 || (c1 < 3 && c1 != c2)) {
                return false;
            }
        }
        return i == m && j == n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        auto check = [](string& s, string& t) -> int {
            int m = s.size(), n = t.size();
            if (n > m) return 0;
            int i = 0, j = 0;
            while (i < m && j < n) {
                if (s[i] != t[j]) return 0;
                int k = i;
                while (k < m && s[k] == s[i]) ++k;
                int c1 = k - i;
                i = k, k = j;
                while (k < n && t[k] == t[j]) ++k;
                int c2 = k - j;
                j = k;
                if (c1 < c2 || (c1 < 3 && c1 != c2)) return 0;
            }
            return i == m && j == n;
        };

        int ans = 0;
        for (string& t : words) ans += check(s, t);
        return ans;
    }
};
```

#### Go

```go
func expressiveWords(s string, words []string) (ans int) {
	check := func(s, t string) bool {
		m, n := len(s), len(t)
		if n > m {
			return false
		}
		i, j := 0, 0
		for i < m && j < n {
			if s[i] != t[j] {
				return false
			}
			k := i
			for k < m && s[k] == s[i] {
				k++
			}
			c1 := k - i
			i, k = k, j
			for k < n && t[k] == t[j] {
				k++
			}
			c2 := k - j
			j = k
			if c1 < c2 || (c1 != c2 && c1 < 3) {
				return false
			}
		}
		return i == m && j == n
	}
	for _, t := range words {
		if check(s, t) {
			ans++
		}
	}
	return ans
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
