---
title: "2150_找出数组中的所有孤独数字"
date: 2025-10-08T18:39:03+08:00
weight: 6
tags: [位运算, 几何, 动态规划, 哈希函数, 哈希表, 回溯, 字符串, 并查集, 排序, 数学, 数据库, 数组, 有序集合, 枚举, 模拟, 滑动窗口, 滚动哈希, 状态压缩, 线段树, 计数]
---

{{< markmap >}}
### [2150_找出数组中的所有孤独数字](#2150)
#### [数组](#2150)
#### [哈希表](#2150)
#### [计数](#2150)
### [2151_基于陈述统计最多好人数](#2151)
#### [位运算](#2151)
#### [数组](#2151)
#### [回溯](#2151)
#### [枚举](#2151)
### [2152_穿过所有点的所需最少直线数量 🔒](#2152)
#### [位运算](#2152)
#### [几何](#2152)
#### [数组](#2152)
#### [哈希表](#2152)
#### [数学](#2152)
#### [动态规划](#2152)
#### [回溯](#2152)
#### [状态压缩](#2152)
### [2153_每辆车的乘客人数 II 🔒](#2153)
#### [数据库](#2153)
### [2154_将找到的值乘以 2](#2154)
#### [数组](#2154)
#### [哈希表](#2154)
#### [排序](#2154)
#### [模拟](#2154)
### [2155_分组得分最高的所有下标](#2155)
#### [数组](#2155)
### [2156_查找给定哈希值的子串](#2156)
#### [字符串](#2156)
#### [滑动窗口](#2156)
#### [哈希函数](#2156)
#### [滚动哈希](#2156)
### [2157_字符串分组](#2157)
#### [位运算](#2157)
#### [并查集](#2157)
#### [字符串](#2157)
### [2158_每天绘制新区域的数量 🔒](#2158)
#### [线段树](#2158)
#### [数组](#2158)
#### [有序集合](#2158)
### [2159_分别排序两列 🔒](#2159)
#### [数据库](#2159)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2150_找出数组中的所有孤独数字
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2151_基于陈述统计最多好人数
___
#### 位运算
___
#### 数组
___
#### 回溯
___
#### 枚举
---
### 2152_穿过所有点的所需最少直线数量 🔒
___
#### 位运算
___
#### 几何
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 动态规划
___
#### 回溯
___
#### 状态压缩
---
### 2153_每辆车的乘客人数 II 🔒
___
#### 数据库
---
### 2154_将找到的值乘以 2
___
#### 数组
___
#### 哈希表
___
#### 排序
___
#### 模拟
---
### 2155_分组得分最高的所有下标
___
#### 数组
---
### 2156_查找给定哈希值的子串
___
#### 字符串
___
#### 滑动窗口
___
#### 哈希函数
___
#### 滚动哈希
---
### 2157_字符串分组
___
#### 位运算
___
#### 并查集
___
#### 字符串
---
### 2158_每天绘制新区域的数量 🔒
___
#### 线段树
___
#### 数组
___
#### 有序集合
---
### 2159_分别排序两列 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 动态规划 |
| 哈希函数 | 哈希表 | 回溯 |
| 字符串 | 并查集 | 排序 |
| 数学 | 数据库 | 数组 |
| 有序集合 | 枚举 | 模拟 |
| 滑动窗口 | 滚动哈希 | 状态压缩 |
| 线段树 | 计数 |  |

# [2150. 找出数组中的所有孤独数字](https://leetcode.cn/problems/find-all-lonely-numbers-in-the-array){#2150}

{{< tabs "2150" >}}

{{% tab "python" %}}
```python
class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return [
            x for x, v in cnt.items() if v == 1 and cnt[x - 1] == 0 and cnt[x + 1] == 0
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> findLonely(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            if (v == 1 && !cnt.containsKey(x - 1) && !cnt.containsKey(x + 1)) {
                ans.add(x);
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
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        vector<int> ans;
        for (auto& [x, v] : cnt) {
            if (v == 1 && !cnt.contains(x - 1) && !cnt.contains(x + 1)) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findLonely(nums []int) (ans []int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x, v := range cnt {
		if v == 1 && cnt[x-1] == 0 && cnt[x+1] == 0 {
			ans = append(ans, x)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findLonely(nums: number[]): number[] {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    const ans: number[] = [];
    for (const [x, v] of cnt) {
        if (v === 1 && !cnt.has(x - 1) && !cnt.has(x + 1)) {
            ans.push(x);
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

<p>给你一个整数数组 <code>nums</code> 。如果数字 <code>x</code> 在数组中仅出现 <strong>一次</strong> ，且没有 <strong>相邻</strong> 数字（即，<code>x + 1</code> 和 <code>x - 1</code>）出现在数组中，则认为数字 <code>x</code> 是 <strong>孤独数字</strong> 。</p>

<p>返回<em> </em><code>nums</code> 中的 <strong>所有</strong> 孤独数字。你可以按 <strong>任何顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [10,6,5,8]
<strong>输出：</strong>[10,8]
<strong>解释：</strong>
- 10 是一个孤独数字，因为它只出现一次，并且 9 和 11 没有在 nums 中出现。
- 8 是一个孤独数字，因为它只出现一次，并且 7 和 9 没有在 nums 中出现。
- 5 不是一个孤独数字，因为 6 出现在 nums 中，反之亦然。
因此，nums 中的孤独数字是 [10, 8] 。
注意，也可以返回 [8, 10] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [1,3,5,3]
<strong>输出：</strong>[1,5]
<strong>解释：</strong>
- 1 是一个孤独数字，因为它只出现一次，并且 0 和 2 没有在 nums 中出现。
- 5 是一个孤独数字，因为它只出现一次，并且 4 和 6 没有在 nums 中出现。
- 3 不是一个孤独数字，因为它出现两次。
因此，nums 中的孤独数字是 [1, 5] 。
注意，也可以返回 [5, 1] 。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $\textit{cnt}$ 记录每个数字出现的次数，然后遍历哈希表，对于每个数字及其出现次数 $(x, v)$，如果 $v = 1$ 且 $\textit{cnt}[x - 1] = 0$ 且 $\textit{cnt}[x + 1] = 0$，则 $x$ 是一个孤独数字，将其加入答案数组中。

遍历结束后，返回答案数组即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        cnt = Counter(nums)
        return [
            x for x, v in cnt.items() if v == 1 and cnt[x - 1] == 0 and cnt[x + 1] == 0
        ]
```

#### Java

```java
class Solution {
    public List<Integer> findLonely(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) {
            cnt.merge(x, 1, Integer::sum);
        }
        List<Integer> ans = new ArrayList<>();
        for (var e : cnt.entrySet()) {
            int x = e.getKey(), v = e.getValue();
            if (v == 1 && !cnt.containsKey(x - 1) && !cnt.containsKey(x + 1)) {
                ans.add(x);
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
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }
        vector<int> ans;
        for (auto& [x, v] : cnt) {
            if (v == 1 && !cnt.contains(x - 1) && !cnt.contains(x + 1)) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findLonely(nums []int) (ans []int) {
	cnt := map[int]int{}
	for _, x := range nums {
		cnt[x]++
	}
	for x, v := range cnt {
		if v == 1 && cnt[x-1] == 0 && cnt[x+1] == 0 {
			ans = append(ans, x)
		}
	}
	return
}
```

#### TypeScript

```ts
function findLonely(nums: number[]): number[] {
    const cnt: Map<number, number> = new Map();
    for (const x of nums) {
        cnt.set(x, (cnt.get(x) || 0) + 1);
    }
    const ans: number[] = [];
    for (const [x, v] of cnt) {
        if (v === 1 && !cnt.has(x - 1) && !cnt.has(x + 1)) {
            ans.push(x);
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

# [2151. 基于陈述统计最多好人数](https://leetcode.cn/problems/maximum-good-people-based-on-statements){#2151}

{{< tabs "2151" >}}

{{% tab "python" %}}
```python
class Solution:
    def maximumGood(self, statements: List[List[int]]) -> int:
        def check(mask: int) -> int:
            cnt = 0
            for i, row in enumerate(statements):
                if mask >> i & 1:
                    for j, x in enumerate(row):
                        if x < 2 and (mask >> j & 1) != x:
                            return 0
                    cnt += 1
            return cnt

        return max(check(i) for i in range(1, 1 << len(statements)))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maximumGood(int[][] statements) {
        int ans = 0;
        for (int mask = 1; mask < 1 << statements.length; ++mask) {
            ans = Math.max(ans, check(mask, statements));
        }
        return ans;
    }

    private int check(int mask, int[][] statements) {
        int cnt = 0;
        int n = statements.length;
        for (int i = 0; i < n; ++i) {
            if (((mask >> i) & 1) == 1) {
                for (int j = 0; j < n; ++j) {
                    int v = statements[i][j];
                    if (v < 2 && ((mask >> j) & 1) != v) {
                        return 0;
                    }
                }
                ++cnt;
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0;
        for (int mask = 1; mask < 1 << statements.size(); ++mask) ans = max(ans, check(mask, statements));
        return ans;
    }

    int check(int mask, vector<vector<int>>& statements) {
        int cnt = 0;
        int n = statements.size();
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                for (int j = 0; j < n; ++j) {
                    int v = statements[i][j];
                    if (v < 2 && ((mask >> j) & 1) != v) return 0;
                }
                ++cnt;
            }
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maximumGood(statements [][]int) int {
	n := len(statements)
	check := func(mask int) int {
		cnt := 0
		for i, s := range statements {
			if ((mask >> i) & 1) == 1 {
				for j, v := range s {
					if v < 2 && ((mask>>j)&1) != v {
						return 0
					}
				}
				cnt++
			}
		}
		return cnt
	}
	ans := 0
	for mask := 1; mask < 1<<n; mask++ {
		ans = max(ans, check(mask))
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maximumGood(statements: number[][]): number {
    const n = statements.length;
    function check(mask) {
        let cnt = 0;
        for (let i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                for (let j = 0; j < n; ++j) {
                    const v = statements[i][j];
                    if (v < 2 && ((mask >> j) & 1) != v) {
                        return 0;
                    }
                }
                ++cnt;
            }
        }
        return cnt;
    }
    let ans = 0;
    for (let mask = 1; mask < 1 << n; ++mask) {
        ans = Math.max(ans, check(mask));
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

<p>游戏中存在两种角色：</p>

<ul>
	<li><strong>好人</strong>：该角色只说真话。</li>
	<li><strong>坏人</strong>：该角色可能说真话，也可能说假话。</li>
</ul>

<p>给你一个下标从 <strong>0</strong> 开始的二维整数数组 <code>statements</code> ，大小为 <code>n x n</code> ，表示 <code>n</code> 个玩家对彼此角色的陈述。具体来说，<code>statements[i][j]</code> 可以是下述值之一：</p>

<ul>
	<li><code>0</code> 表示 <code>i</code> 的陈述认为 <code>j</code> 是 <strong>坏人</strong> 。</li>
	<li><code>1</code> 表示 <code>i</code> 的陈述认为 <code>j</code> 是 <strong>好人</strong> 。</li>
	<li><code>2</code> 表示 <code>i</code> 没有对 <code>j</code> 作出陈述。</li>
</ul>

<p>另外，玩家不会对自己进行陈述。形式上，对所有&nbsp;<code>0 &lt;= i &lt; n</code> ，都有 <code>statements[i][i] = 2</code> 。</p>

<p>根据这 <code>n</code> 个玩家的陈述，返回可以认为是 <strong>好人</strong> 的 <strong>最大</strong> 数目。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2151.Maximum%20Good%20People%20Based%20on%20Statements/images/logic1.jpg" style="width: 600px; height: 262px;">
<pre><strong>输入：</strong>statements = [[2,1,2],[1,2,2],[2,0,2]]
<strong>输出：</strong>2
<strong>解释：</strong>每个人都做一条陈述。
- 0 认为 1 是好人。
- 1 认为 0 是好人。
- 2 认为 1 是坏人。
以 2 为突破点。
- 假设 2 是一个好人：
    - 基于 2 的陈述，1 是坏人。
    - 那么可以确认 1 是坏人，2 是好人。
    - 基于 1 的陈述，由于 1 是坏人，那么他在陈述时可能：
        - 说真话。在这种情况下会出现矛盾，所以假设无效。
        - 说假话。在这种情况下，0 也是坏人并且在陈述时说假话。
    - <strong>在认为 2 是好人的情况下，这组玩家中只有一个好人。</strong>
- 假设 2 是一个坏人：
    - 基于 2 的陈述，由于 2 是坏人，那么他在陈述时可能：
        - 说真话。在这种情况下，0 和 1 都是坏人。
            - <strong>在认为 2 是坏人但说真话的情况下，这组玩家中没有一个好人。</strong>
        - 说假话。在这种情况下，1 是好人。
            - 由于 1 是好人，0 也是好人。
            - <strong>在认为 2 是坏人且说假话的情况下，这组玩家中有两个好人。</strong>
在最佳情况下，至多有两个好人，所以返回 2 。
注意，能得到此结论的方法不止一种。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2151.Maximum%20Good%20People%20Based%20on%20Statements/images/logic2.jpg" style="width: 600px; height: 262px;">
<pre><strong>输入：</strong>statements = [[2,0],[0,2]]
<strong>输出：</strong>1
<strong>解释：</strong>每个人都做一条陈述。
- 0 认为 1 是坏人。
- 1 认为 0 是坏人。
以 0 为突破点。
- 假设 0 是一个好人：
    - 基于与 0 的陈述，1 是坏人并说假话。
    - <strong>在认为 0 是好人的情况下，这组玩家中只有一个好人。</strong>
- 假设 0 是一个坏人：
    - 基于 0 的陈述，由于 0 是坏人，那么他在陈述时可能：
        - 说真话。在这种情况下，0 和 1 都是坏人。
            - <strong>在认为 0 是坏人但说真话的情况下，这组玩家中没有一个好人。</strong>
        - 说假话。在这种情况下，1 是好人。
            - <strong>在认为 0 是坏人且说假话的情况下，这组玩家中只有一个好人。</strong>
在最佳情况下，至多有一个好人，所以返回 1 。 
注意，能得到此结论的方法不止一种。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == statements.length == statements[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 15</code></li>
	<li><code>statements[i][j]</code> 的值为 <code>0</code>、<code>1</code> 或 <code>2</code></li>
	<li><code>statements[i][i] == 2</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二进制枚举

二进制枚举好人的状态 $mask$，由于“好人只说真话”，我们借此判断 $statements$ 与 $mask$ 是否存在矛盾，不存在则获取 $mask$ 中好人的数量 $cnt$。迭代获取最大的合法 $cnt$。

时间复杂度 $O(2^n*n^2)$，其中 $n$ 表示 $statements$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maximumGood(self, statements: List[List[int]]) -> int:
        def check(mask: int) -> int:
            cnt = 0
            for i, row in enumerate(statements):
                if mask >> i & 1:
                    for j, x in enumerate(row):
                        if x < 2 and (mask >> j & 1) != x:
                            return 0
                    cnt += 1
            return cnt

        return max(check(i) for i in range(1, 1 << len(statements)))
```

#### Java

```java
class Solution {
    public int maximumGood(int[][] statements) {
        int ans = 0;
        for (int mask = 1; mask < 1 << statements.length; ++mask) {
            ans = Math.max(ans, check(mask, statements));
        }
        return ans;
    }

    private int check(int mask, int[][] statements) {
        int cnt = 0;
        int n = statements.length;
        for (int i = 0; i < n; ++i) {
            if (((mask >> i) & 1) == 1) {
                for (int j = 0; j < n; ++j) {
                    int v = statements[i][j];
                    if (v < 2 && ((mask >> j) & 1) != v) {
                        return 0;
                    }
                }
                ++cnt;
            }
        }
        return cnt;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int ans = 0;
        for (int mask = 1; mask < 1 << statements.size(); ++mask) ans = max(ans, check(mask, statements));
        return ans;
    }

    int check(int mask, vector<vector<int>>& statements) {
        int cnt = 0;
        int n = statements.size();
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                for (int j = 0; j < n; ++j) {
                    int v = statements[i][j];
                    if (v < 2 && ((mask >> j) & 1) != v) return 0;
                }
                ++cnt;
            }
        }
        return cnt;
    }
};
```

#### Go

```go
func maximumGood(statements [][]int) int {
	n := len(statements)
	check := func(mask int) int {
		cnt := 0
		for i, s := range statements {
			if ((mask >> i) & 1) == 1 {
				for j, v := range s {
					if v < 2 && ((mask>>j)&1) != v {
						return 0
					}
				}
				cnt++
			}
		}
		return cnt
	}
	ans := 0
	for mask := 1; mask < 1<<n; mask++ {
		ans = max(ans, check(mask))
	}
	return ans
}
```

#### TypeScript

```ts
function maximumGood(statements: number[][]): number {
    const n = statements.length;
    function check(mask) {
        let cnt = 0;
        for (let i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                for (let j = 0; j < n; ++j) {
                    const v = statements[i][j];
                    if (v < 2 && ((mask >> j) & 1) != v) {
                        return 0;
                    }
                }
                ++cnt;
            }
        }
        return cnt;
    }
    let ans = 0;
    for (let mask = 1; mask < 1 << n; ++mask) {
        ans = Math.max(ans, check(mask));
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2152. 穿过所有点的所需最少直线数量 🔒](https://leetcode.cn/problems/minimum-number-of-lines-to-cover-points){#2152}

{{< tabs "2152" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumLines(self, points: List[List[int]]) -> int:
        def check(i, j, k):
            x1, y1 = points[i]
            x2, y2 = points[j]
            x3, y3 = points[k]
            return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1)

        @cache
        def dfs(state):
            if state == (1 << n) - 1:
                return 0
            ans = inf
            for i in range(n):
                if not (state >> i & 1):
                    for j in range(i + 1, n):
                        nxt = state | 1 << i | 1 << j
                        for k in range(j + 1, n):
                            if not (nxt >> k & 1) and check(i, j, k):
                                nxt |= 1 << k
                        ans = min(ans, dfs(nxt) + 1)
                    if i == n - 1:
                        ans = min(ans, dfs(state | 1 << i) + 1)
            return ans

        n = len(points)
        return dfs(0)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] f;
    private int[][] points;
    private int n;

    public int minimumLines(int[][] points) {
        n = points.length;
        this.points = points;
        f = new int[1 << n];
        return dfs(0);
    }

    private int dfs(int state) {
        if (state == (1 << n) - 1) {
            return 0;
        }
        if (f[state] != 0) {
            return f[state];
        }
        int ans = 1 << 30;
        for (int i = 0; i < n; ++i) {
            if (((state >> i) & 1) == 0) {
                for (int j = i + 1; j < n; ++j) {
                    int nxt = state | 1 << i | 1 << j;
                    for (int k = j + 1; k < n; ++k) {
                        if (((state >> k) & 1) == 0 && check(i, j, k)) {
                            nxt |= 1 << k;
                        }
                    }
                    ans = Math.min(ans, dfs(nxt) + 1);
                }
                if (i == n - 1) {
                    ans = Math.min(ans, dfs(state | 1 << i) + 1);
                }
            }
        }
        return f[state] = ans;
    }

    private boolean check(int i, int j, int k) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        int x3 = points[k][0], y3 = points[k][1];
        return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumLines(vector<vector<int>>& points) {
        auto check = [&](int i, int j, int k) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];
            int x3 = points[k][0], y3 = points[k][1];
            return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1);
        };
        int n = points.size();
        int f[1 << n];
        memset(f, 0, sizeof f);
        function<int(int)> dfs = [&](int state) -> int {
            if (state == (1 << n) - 1) return 0;
            if (f[state]) return f[state];
            int ans = 1 << 30;
            for (int i = 0; i < n; ++i) {
                if (!(state >> i & 1)) {
                    for (int j = i + 1; j < n; ++j) {
                        int nxt = state | 1 << i | 1 << j;
                        for (int k = j + 1; k < n; ++k) {
                            if (!(nxt >> k & 1) && check(i, j, k)) {
                                nxt |= 1 << k;
                            }
                        }
                        ans = min(ans, dfs(nxt) + 1);
                    }
                    if (i == n - 1) {
                        ans = min(ans, dfs(state | 1 << i) + 1);
                    }
                }
            }
            return f[state] = ans;
        };
        return dfs(0);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumLines(points [][]int) int {
	check := func(i, j, k int) bool {
		x1, y1 := points[i][0], points[i][1]
		x2, y2 := points[j][0], points[j][1]
		x3, y3 := points[k][0], points[k][1]
		return (x2-x1)*(y3-y1) == (x3-x1)*(y2-y1)
	}
	n := len(points)
	f := make([]int, 1<<n)
	var dfs func(int) int
	dfs = func(state int) int {
		if state == (1<<n)-1 {
			return 0
		}
		if f[state] > 0 {
			return f[state]
		}
		ans := 1 << 30
		for i := 0; i < n; i++ {
			if (state >> i & 1) == 0 {
				for j := i + 1; j < n; j++ {
					nxt := state | 1<<i | 1<<j
					for k := j + 1; k < n; k++ {
						if (nxt>>k&1) == 0 && check(i, j, k) {
							nxt |= 1 << k
						}
					}
					ans = min(ans, dfs(nxt)+1)
				}
				if i == n-1 {
					ans = min(ans, dfs(state|1<<i)+1)
				}
			}
		}
		f[state] = ans
		return ans
	}
	return dfs(0)
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个 <code>points</code>&nbsp;数组，<code>points[i] = [xi, yi]</code>&nbsp;表示直角坐标系 <strong>X-Y</strong> 的一个点。</p>

<p>现在考虑向 X-Y 坐标系中添加 <strong>直线</strong>，使得每个点 <strong>至少</strong> 在一条直线上。</p>

<p>返回能够穿过所有点的所需&nbsp;<strong>最少直线&nbsp;</strong>数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2152.Minimum%20Number%20of%20Lines%20to%20Cover%20Points/images/image-20220123200023-1.png" style="width: 350px; height: 402px;" />
<pre>
<strong>输入:</strong> points = [[0,1],[2,3],[4,5],[4,3]]
<strong>输出:</strong> 2
<strong>解释:</strong> 所需最少直线数量为 2 ，一种可能的答案是添加:
- 一条穿过点 (0, 1) 和 点(4, 5) 的直线
- 另一条穿过点 (2, 3) 和点 (4, 3) 的直线
</pre>

<p><strong>示例 2:</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2152.Minimum%20Number%20of%20Lines%20to%20Cover%20Points/images/image-20220123200057-3.png" style="width: 350px; height: 480px;" />
<pre>
<strong>输入:</strong> points = [[0,2],[-2,-2],[1,4]]
<strong>输出:</strong> 1
<strong>解释:</strong> 所需最少直线数量为 1 ，唯一的答案是:
- 一条穿过点 (-2, -2) 和点 (1, 4) 的直线
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= points.length &lt;= 10</code></li>
	<li><code>points[i].length == 2</code></li>
	<li><code>-100 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 100</code></li>
	<li><code>points</code>&nbsp;中元素都是唯一的</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 记忆化搜索

我们可以用一个整数 `state` 来表示当前已经添加的直线，其中 `state` 的第 $i$ 位表示第 $i$ 条直线是否已经添加。如果 `state` 的第 $i$ 位为 $1$，则表示第 $i$ 条直线已经添加，否则表示第 $i$ 条直线还未添加。

接下来，我们设计一个函数 $dfs(state)$，表示当前已经添加的直线为 `state` 时，至少需要添加多少条直线才能使得每个点至少在一条直线上。那么答案就是 $dfs(0)$。

函数 $dfs(state)$ 的计算过程如下：

-   如果 `state` 的所有位都为 $1$，则说明所有直线都已经添加，返回 $0$。
-   否则，我们枚举当前还未添加的点 $i$，接下来枚举 $j$，我们将 $i$ 和 $j$ 的点连成一条直线，此时的状态为 $nxt = state | 1 << i | 1 << j$，其中 $1 << i$ 表示将第 $i$ 位设置为 $1$，$1 << j$ 表示将第 $j$ 位设置为 $1$。接下来，我们枚举所有 $k$，如果 $i$、$j$ 和 $k$ 三个点共线，则将 $k$ 的状态设置为 $1$，即 $nxt = nxt | 1 << k$。此时，我们可以将 $i$ 和 $j$ 以及 $k$ 这三个点连成一条直线，此时的状态为 $nxt$，此时至少需要添加 $dfs(nxt)$ 条直线，我们取所有情况的最小值，即为 $dfs(state)$ 的值。

为了避免重复计算，我们可以使用记忆化搜索。

时间复杂度 $O(2^n \times n^3)$，空间复杂度 $O(2^n)$。其中 $n$ 为点的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumLines(self, points: List[List[int]]) -> int:
        def check(i, j, k):
            x1, y1 = points[i]
            x2, y2 = points[j]
            x3, y3 = points[k]
            return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1)

        @cache
        def dfs(state):
            if state == (1 << n) - 1:
                return 0
            ans = inf
            for i in range(n):
                if not (state >> i & 1):
                    for j in range(i + 1, n):
                        nxt = state | 1 << i | 1 << j
                        for k in range(j + 1, n):
                            if not (nxt >> k & 1) and check(i, j, k):
                                nxt |= 1 << k
                        ans = min(ans, dfs(nxt) + 1)
                    if i == n - 1:
                        ans = min(ans, dfs(state | 1 << i) + 1)
            return ans

        n = len(points)
        return dfs(0)
```

#### Java

```java
class Solution {
    private int[] f;
    private int[][] points;
    private int n;

    public int minimumLines(int[][] points) {
        n = points.length;
        this.points = points;
        f = new int[1 << n];
        return dfs(0);
    }

    private int dfs(int state) {
        if (state == (1 << n) - 1) {
            return 0;
        }
        if (f[state] != 0) {
            return f[state];
        }
        int ans = 1 << 30;
        for (int i = 0; i < n; ++i) {
            if (((state >> i) & 1) == 0) {
                for (int j = i + 1; j < n; ++j) {
                    int nxt = state | 1 << i | 1 << j;
                    for (int k = j + 1; k < n; ++k) {
                        if (((state >> k) & 1) == 0 && check(i, j, k)) {
                            nxt |= 1 << k;
                        }
                    }
                    ans = Math.min(ans, dfs(nxt) + 1);
                }
                if (i == n - 1) {
                    ans = Math.min(ans, dfs(state | 1 << i) + 1);
                }
            }
        }
        return f[state] = ans;
    }

    private boolean check(int i, int j, int k) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        int x3 = points[k][0], y3 = points[k][1];
        return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumLines(vector<vector<int>>& points) {
        auto check = [&](int i, int j, int k) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];
            int x3 = points[k][0], y3 = points[k][1];
            return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1);
        };
        int n = points.size();
        int f[1 << n];
        memset(f, 0, sizeof f);
        function<int(int)> dfs = [&](int state) -> int {
            if (state == (1 << n) - 1) return 0;
            if (f[state]) return f[state];
            int ans = 1 << 30;
            for (int i = 0; i < n; ++i) {
                if (!(state >> i & 1)) {
                    for (int j = i + 1; j < n; ++j) {
                        int nxt = state | 1 << i | 1 << j;
                        for (int k = j + 1; k < n; ++k) {
                            if (!(nxt >> k & 1) && check(i, j, k)) {
                                nxt |= 1 << k;
                            }
                        }
                        ans = min(ans, dfs(nxt) + 1);
                    }
                    if (i == n - 1) {
                        ans = min(ans, dfs(state | 1 << i) + 1);
                    }
                }
            }
            return f[state] = ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func minimumLines(points [][]int) int {
	check := func(i, j, k int) bool {
		x1, y1 := points[i][0], points[i][1]
		x2, y2 := points[j][0], points[j][1]
		x3, y3 := points[k][0], points[k][1]
		return (x2-x1)*(y3-y1) == (x3-x1)*(y2-y1)
	}
	n := len(points)
	f := make([]int, 1<<n)
	var dfs func(int) int
	dfs = func(state int) int {
		if state == (1<<n)-1 {
			return 0
		}
		if f[state] > 0 {
			return f[state]
		}
		ans := 1 << 30
		for i := 0; i < n; i++ {
			if (state >> i & 1) == 0 {
				for j := i + 1; j < n; j++ {
					nxt := state | 1<<i | 1<<j
					for k := j + 1; k < n; k++ {
						if (nxt>>k&1) == 0 && check(i, j, k) {
							nxt |= 1 << k
						}
					}
					ans = min(ans, dfs(nxt)+1)
				}
				if i == n-1 {
					ans = min(ans, dfs(state|1<<i)+1)
				}
			}
		}
		f[state] = ans
		return ans
	}
	return dfs(0)
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2153. 每辆车的乘客人数 II 🔒](https://leetcode.cn/problems/the-number-of-passengers-in-each-bus-ii){#2153}

{{< tabs "2153" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            SUM(cnt) OVER (ORDER BY dt, bus_id) AS cur,
            IF(@t > 0, @t := cnt, @t := @t + cnt) AS cur_sum
        FROM
            (
                SELECT bus_id, arrival_time AS dt, capacity AS cnt FROM Buses
                UNION ALL
                SELECT -1, arrival_time AS dt, -1 FROM Passengers
            ) AS a JOIN (SELECT @t := 0 x) AS b
    )
SELECT
    bus_id,
    IF(cur_sum > 0, cnt - cur_sum, cnt) AS passengers_cnt
FROM T
WHERE bus_id > 0
ORDER BY bus_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Buses</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| bus_id       | int  |
| arrival_time | int  |
| capacity     | int  |
+--------------+------+
bus_id 包含唯一的值。
该表的每一行都包含关于公交车到达 LeetCode 站点的时间和它的容量 (空座位的数量) 的信息。
不会出现两辆公交车同时到达，所有公交车的容量都是正整数。
</pre>

<p>&nbsp;</p>

<p>表: <code>Passengers</code></p>

<pre>
+--------------+------+
| Column Name  | Type |
+--------------+------+
| passenger_id | int  |
| arrival_time | int  |
+--------------+------+
passenger_id 包含唯一的值。
该表的每一行都包含乘客到达 LeetCode 站的时间信息。
</pre>

<p>&nbsp;</p>

<p>公交车和乘客到达 LeetCode 站。如果一辆公交车在 <code>t<sub>bus</sub></code> 时间点到达车站，乘客在 <code>t<sub>passenger</sub></code> 到达车站，其中&nbsp;<code>t<sub>passenger</sub> &lt;= t<sub>bus</sub></code>，而该乘客没有赶上任何公交车，则该乘客将搭乘该公交车。此外，每辆公交车都有一个容量。如果在公交车到站的那一刻，等待的乘客超过了它的载客量 <code>capacity</code>，只有&nbsp;<code>capacity</code> 个乘客才会搭乘该公交车。</p>

<p>编写解决方案，报告使用每条总线的用户数量。</p>

<p>返回按 <code>bus_id</code> <strong>升序排序&nbsp;</strong>的结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Buses 表:
+--------+--------------+----------+
| bus_id | arrival_time | capacity |
+--------+--------------+----------+
| 1      | 2            | 1        |
| 2      | 4            | 10       |
| 3      | 7            | 2        |
+--------+--------------+----------+
Passengers 表:
+--------------+--------------+
| passenger_id | arrival_time |
+--------------+--------------+
| 11           | 1            |
| 12           | 1            |
| 13           | 5            |
| 14           | 6            |
| 15           | 7            |
+--------------+--------------+
<strong>输出:</strong> 
+--------+----------------+
| bus_id | passengers_cnt |
+--------+----------------+
| 1      | 1              |
| 2      | 1              |
| 3      | 2              |
+--------+----------------+
<strong>解释:</strong> 
- 11 号乘客在时间 1 到达。
- 12 号乘客在时间 1 到达。
- 1 号公交车到达时间为 2，因为有一个空座位，所以搭载了 11 号乘客。

- 2 号公交车在时间 4 到达，搭载了12 号乘客，因为它有 10 个空座位。

- 13 号乘客在时间 5 到达。
- 14 号乘客在时间 6 到达。
- 15 号乘客在时间 7 到达。
- 3 号公交车在时间 7 到达，车上有两个空座位，搭载了 12 号和 13 号乘客。</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            *,
            SUM(cnt) OVER (ORDER BY dt, bus_id) AS cur,
            IF(@t > 0, @t := cnt, @t := @t + cnt) AS cur_sum
        FROM
            (
                SELECT bus_id, arrival_time AS dt, capacity AS cnt FROM Buses
                UNION ALL
                SELECT -1, arrival_time AS dt, -1 FROM Passengers
            ) AS a JOIN (SELECT @t := 0 x) AS b
    )
SELECT
    bus_id,
    IF(cur_sum > 0, cnt - cur_sum, cnt) AS passengers_cnt
FROM T
WHERE bus_id > 0
ORDER BY bus_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2154. 将找到的值乘以 2](https://leetcode.cn/problems/keep-multiplying-found-values-by-two){#2154}

{{< tabs "2154" >}}

{{% tab "python" %}}
```python
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        s = set(nums)
        while original in s:
            original <<= 1
        return original
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {

    public int findFinalValue(int[] nums, int original) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) {
            s.add(num);
        }
        while (s.contains(original)) {
            original <<= 1;
        }
        return original;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.contains(original)) {
            original <<= 1;
        }
        return original;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findFinalValue(nums []int, original int) int {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for s[original] {
		original <<= 1
	}
	return original
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findFinalValue(nums: number[], original: number): number {
    const s: Set<number> = new Set([...nums]);
    while (s.has(original)) {
        original <<= 1;
    }
    return original;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> ，另给你一个整数 <code>original</code> ，这是需要在 <code>nums</code> 中搜索的第一个数字。</p>

<p>接下来，你需要按下述步骤操作：</p>

<ol>
	<li>如果在 <code>nums</code> 中找到 <code>original</code> ，将 <code>original</code>&nbsp;<strong>乘以</strong> 2 ，得到新 <code>original</code>（即，令 <code>original = 2 * original</code>）。</li>
	<li>否则，停止这一过程。</li>
	<li>只要能在数组中找到新 <code>original</code> ，就对新 <code>original</code> 继续 <strong>重复</strong> 这一过程<strong>。</strong></li>
</ol>

<p>返回<em> </em><code>original</code> 的 <strong>最终</strong> 值。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [5,3,6,1,12], original = 3
<strong>输出：</strong>24
<strong>解释：</strong> 
- 3 能在 nums 中找到。3 * 2 = 6 。
- 6 能在 nums 中找到。6 * 2 = 12 。
- 12 能在 nums 中找到。12 * 2 = 24 。
- 24 不能在 nums 中找到。因此，返回 24 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,7,9], original = 4
<strong>输出：</strong>4
<strong>解释：</strong>
- 4 不能在 nums 中找到。因此，返回 4 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], original &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们用一个哈希表 $\textit{s}$ 记录数组 $\textit{nums}$ 中的所有数字。

接下来，我们从 $\textit{original}$ 开始，如果 $\textit{original}$ 在 $\textit{s}$ 中，我们将 $\textit{original}$ 乘以 $2$，直到 $\textit{original}$ 不在 $\textit{s}$ 中，返回 $\textit{original}$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        s = set(nums)
        while original in s:
            original <<= 1
        return original
```

#### Java

```java
class Solution {

    public int findFinalValue(int[] nums, int original) {
        Set<Integer> s = new HashSet<>();
        for (int num : nums) {
            s.add(num);
        }
        while (s.contains(original)) {
            original <<= 1;
        }
        return original;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.contains(original)) {
            original <<= 1;
        }
        return original;
    }
};
```

#### Go

```go
func findFinalValue(nums []int, original int) int {
	s := map[int]bool{}
	for _, x := range nums {
		s[x] = true
	}
	for s[original] {
		original <<= 1
	}
	return original
}
```

#### TypeScript

```ts
function findFinalValue(nums: number[], original: number): number {
    const s: Set<number> = new Set([...nums]);
    while (s.has(original)) {
        original <<= 1;
    }
    return original;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2155. 分组得分最高的所有下标](https://leetcode.cn/problems/all-divisions-with-the-highest-score-of-a-binary-array){#2155}

{{< tabs "2155" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        l0, r1 = 0, sum(nums)
        mx = r1
        ans = [0]
        for i, x in enumerate(nums, 1):
            l0 += x ^ 1
            r1 -= x
            t = l0 + r1
            if mx == t:
                ans.append(i)
            elif mx < t:
                mx = t
                ans = [i]
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> maxScoreIndices(int[] nums) {
        int l0 = 0, r1 = Arrays.stream(nums).sum();
        int mx = r1;
        List<Integer> ans = new ArrayList<>();
        ans.add(0);
        for (int i = 1; i <= nums.length; ++i) {
            int x = nums[i - 1];
            l0 += x ^ 1;
            r1 -= x;
            int t = l0 + r1;
            if (mx == t) {
                ans.add(i);
            } else if (mx < t) {
                mx = t;
                ans.clear();
                ans.add(i);
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
    vector<int> maxScoreIndices(vector<int>& nums) {
        int l0 = 0, r1 = accumulate(nums.begin(), nums.end(), 0);
        int mx = r1;
        vector<int> ans = {0};
        for (int i = 1; i <= nums.size(); ++i) {
            int x = nums[i - 1];
            l0 += x ^ 1;
            r1 -= x;
            int t = l0 + r1;
            if (mx == t) {
                ans.push_back(i);
            } else if (mx < t) {
                mx = t;
                ans = {i};
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxScoreIndices(nums []int) []int {
	l0, r1 := 0, 0
	for _, x := range nums {
		r1 += x
	}
	mx := r1
	ans := []int{0}
	for i, x := range nums {
		l0 += x ^ 1
		r1 -= x
		t := l0 + r1
		if mx == t {
			ans = append(ans, i+1)
		} else if mx < t {
			mx = t
			ans = []int{i + 1}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxScoreIndices(nums: number[]): number[] {
    const n = nums.length;
    let [l0, r1] = [0, nums.reduce((a, b) => a + b, 0)];
    let mx = r1;
    const ans: number[] = [0];
    for (let i = 1; i <= n; ++i) {
        const x = nums[i - 1];
        l0 += x ^ 1;
        r1 -= x;
        const t = l0 + r1;
        if (mx === t) {
            ans.push(i);
        } else if (mx < t) {
            mx = t;
            ans.length = 0;
            ans.push(i);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn max_score_indices(nums: Vec<i32>) -> Vec<i32> {
        let mut l0 = 0;
        let mut r1: i32 = nums.iter().sum();
        let mut mx = r1;
        let mut ans = vec![0];

        for i in 1..=nums.len() {
            let x = nums[i - 1];
            l0 += x ^ 1;
            r1 -= x;
            let t = l0 + r1;
            if mx == t {
                ans.push(i as i32);
            } else if mx < t {
                mx = t;
                ans = vec![i as i32];
            }
        }

        ans
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的二进制数组 <code>nums</code> ，数组长度为 <code>n</code> 。<code>nums</code> 可以按下标 <code>i</code>（ <code>0 &lt;= i &lt;= n</code> ）拆分成两个数组（可能为空）：<code>nums<sub>left</sub></code> 和 <code>nums<sub>right</sub></code> 。</p>

<ul>
	<li><code>nums<sub>left</sub></code> 包含 <code>nums</code> 中从下标 <code>0</code> 到 <code>i - 1</code> 的所有元素<strong>（包括 </strong><code>0</code><strong> 和 </strong><code>i - 1</code><strong> ）</strong>，而 <code>nums<sub>right</sub></code> 包含 <code>nums</code> 中从下标 <code>i</code> 到 <code>n - 1</code> 的所有元素<strong>（包括 </strong><code>i</code><strong> 和 </strong><code>n - 1</code><strong> ）。</strong></li>
	<li>如果 <code>i == 0</code> ，<code>nums<sub>left</sub></code> 为 <strong>空</strong> ，而 <code>nums<sub>right</sub></code> 将包含 <code>nums</code> 中的所有元素。</li>
	<li>如果 <code>i == n</code> ，<code>nums<sub>left</sub></code> 将包含 <code>nums</code> 中的所有元素，而 <code>nums<sub>right</sub></code> 为 <strong>空</strong> 。</li>
</ul>

<p>下标 <code>i</code><strong> </strong>的<strong> 分组得分</strong> 为 <code>nums<sub>left</sub></code> 中 <code>0</code> 的个数和 <code>nums<sub>right</sub></code> 中 <code>1</code> 的个数之<strong> 和</strong> 。</p>

<p>返回 <strong>分组得分 最高</strong> 的 <strong>所有不同下标</strong> 。你可以按 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [0,0,1,0]
<strong>输出：</strong>[2,4]
<strong>解释：</strong>按下标分组
- 0 ：nums<sub>left</sub> 为 [] 。nums<sub>right</sub> 为 [0,0,<em><strong>1</strong></em>,0] 。得分为 0 + 1 = 1 。
- 1 ：nums<sub>left</sub> 为 [<em><strong>0</strong></em>] 。nums<sub>right</sub> 为 [0,<em><strong>1</strong></em>,0] 。得分为 1 + 1 = 2 。
- 2 ：nums<sub>left</sub> 为 [<em><strong>0</strong></em>,<em><strong>0</strong></em>] 。nums<sub>right</sub> 为 [<em><strong>1</strong></em>,0] 。得分为 2 + 1 = 3 。
- 3 ：nums<sub>left</sub> 为 [<em><strong>0</strong></em>,<em><strong>0</strong></em>,1] 。nums<sub>right</sub> 为 [0] 。得分为 2 + 0 = 2 。
- 4 ：nums<sub>left</sub> 为 [<em><strong>0</strong></em>,<em><strong>0</strong></em>,1,<em><strong>0</strong></em>] 。nums<sub>right</sub> 为 [] 。得分为 3 + 0 = 3 。
下标 2 和 4 都可以得到最高的分组得分 3 。
注意，答案 [4,2] 也被视为正确答案。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [0,0,0]
<strong>输出：</strong>[3]
<strong>解释：</strong>按下标分组
- 0 ：nums<sub>left</sub> 为 [] 。nums<sub>right</sub> 为 [0,0,0] 。得分为 0 + 0 = 0 。
- 1 ：nums<sub>left</sub> 为 [<em><strong>0</strong></em>] 。nums<sub>right</sub> 为 [0,0] 。得分为 1 + 0 = 1 。
- 2 ：nums<sub>left</sub> 为 [<em><strong>0</strong></em>,<em><strong>0</strong></em>] 。nums<sub>right</sub> 为 [0] 。得分为 2 + 0 = 2 。
- 3 ：nums<sub>left</sub> 为 [<em><strong>0</strong></em>,<em><strong>0</strong></em>,<em><strong>0</strong></em>] 。nums<sub>right</sub> 为 [] 。得分为 3 + 0 = 3 。
只有下标 3 可以得到最高的分组得分 3 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>nums = [1,1]
<strong>输出：</strong>[0]
<strong>解释：</strong>按下标分组
- 0 ：nums<sub>left</sub> 为 [] 。nums<sub>right</sub> 为 [<em><strong>1</strong></em>,<em><strong>1</strong></em>] 。得分为 0 + 2 = 2 。
- 1 ：nums<sub>left</sub> 为 [1] 。nums<sub>right</sub> 为 [<em><strong>1</strong></em>] 。得分为 0 + 1 = 1 。
- 2 ：nums<sub>left</sub> 为 [1,1] 。nums<sub>right</sub> 为 [] 。得分为 0 + 0 = 0 。
只有下标 0 可以得到最高的分组得分 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> 为 <code>0</code> 或 <code>1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和

我们从 $i = 0$ 开始，用两个变量 $\textit{l0}$ 和 $\textit{r1}$ 分别记录 $i$ 左侧和右侧的 $1$ 的个数，初始时 $\textit{l0} = 0$，而 $\textit{r1} = \sum \textit{nums}$。

我们遍历数组 $\textit{nums}$，对于每个 $i$，更新 $\textit{l0}$ 和 $\textit{r1}$，计算当前分组得分 $t = \textit{l0} + \textit{r1}$，如果 $t$ 等于当前最大分组得分 $\textit{mx}$，则将 $i$ 加入答案数组，如果 $t$ 大于 $\textit{mx}$，则更新 $\textit{mx}$ 为 $t$，并将答案数组清空，然后将 $i$ 加入答案数组。

遍历结束后，返回答案数组。

时间复杂度 $O(n)$，其中 $n$ 为数组 $\textit{nums}$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        l0, r1 = 0, sum(nums)
        mx = r1
        ans = [0]
        for i, x in enumerate(nums, 1):
            l0 += x ^ 1
            r1 -= x
            t = l0 + r1
            if mx == t:
                ans.append(i)
            elif mx < t:
                mx = t
                ans = [i]
        return ans
```

#### Java

```java
class Solution {
    public List<Integer> maxScoreIndices(int[] nums) {
        int l0 = 0, r1 = Arrays.stream(nums).sum();
        int mx = r1;
        List<Integer> ans = new ArrayList<>();
        ans.add(0);
        for (int i = 1; i <= nums.length; ++i) {
            int x = nums[i - 1];
            l0 += x ^ 1;
            r1 -= x;
            int t = l0 + r1;
            if (mx == t) {
                ans.add(i);
            } else if (mx < t) {
                mx = t;
                ans.clear();
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
    vector<int> maxScoreIndices(vector<int>& nums) {
        int l0 = 0, r1 = accumulate(nums.begin(), nums.end(), 0);
        int mx = r1;
        vector<int> ans = {0};
        for (int i = 1; i <= nums.size(); ++i) {
            int x = nums[i - 1];
            l0 += x ^ 1;
            r1 -= x;
            int t = l0 + r1;
            if (mx == t) {
                ans.push_back(i);
            } else if (mx < t) {
                mx = t;
                ans = {i};
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxScoreIndices(nums []int) []int {
	l0, r1 := 0, 0
	for _, x := range nums {
		r1 += x
	}
	mx := r1
	ans := []int{0}
	for i, x := range nums {
		l0 += x ^ 1
		r1 -= x
		t := l0 + r1
		if mx == t {
			ans = append(ans, i+1)
		} else if mx < t {
			mx = t
			ans = []int{i + 1}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxScoreIndices(nums: number[]): number[] {
    const n = nums.length;
    let [l0, r1] = [0, nums.reduce((a, b) => a + b, 0)];
    let mx = r1;
    const ans: number[] = [0];
    for (let i = 1; i <= n; ++i) {
        const x = nums[i - 1];
        l0 += x ^ 1;
        r1 -= x;
        const t = l0 + r1;
        if (mx === t) {
            ans.push(i);
        } else if (mx < t) {
            mx = t;
            ans.length = 0;
            ans.push(i);
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn max_score_indices(nums: Vec<i32>) -> Vec<i32> {
        let mut l0 = 0;
        let mut r1: i32 = nums.iter().sum();
        let mut mx = r1;
        let mut ans = vec![0];

        for i in 1..=nums.len() {
            let x = nums[i - 1];
            l0 += x ^ 1;
            r1 -= x;
            let t = l0 + r1;
            if mx == t {
                ans.push(i as i32);
            } else if mx < t {
                mx = t;
                ans = vec![i as i32];
            }
        }

        ans
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2156. 查找给定哈希值的子串](https://leetcode.cn/problems/find-substring-with-given-hash-value){#2156}

{{< tabs "2156" >}}

{{% tab "python" %}}
```python
class Solution:
    def subStrHash(
        self, s: str, power: int, modulo: int, k: int, hashValue: int
    ) -> str:
        h, n = 0, len(s)
        p = 1
        for i in range(n - 1, n - 1 - k, -1):
            val = ord(s[i]) - ord("a") + 1
            h = ((h * power) + val) % modulo
            if i != n - k:
                p = p * power % modulo
        j = n - k
        for i in range(n - 1 - k, -1, -1):
            pre = ord(s[i + k]) - ord("a") + 1
            cur = ord(s[i]) - ord("a") + 1
            h = ((h - pre * p) * power + cur) % modulo
            if h == hashValue:
                j = i
        return s[j : j + k]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String subStrHash(String s, int power, int modulo, int k, int hashValue) {
        long h = 0, p = 1;
        int n = s.length();
        for (int i = n - 1; i >= n - k; --i) {
            int val = s.charAt(i) - 'a' + 1;
            h = ((h * power % modulo) + val) % modulo;
            if (i != n - k) {
                p = p * power % modulo;
            }
        }
        int j = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            int pre = s.charAt(i + k) - 'a' + 1;
            int cur = s.charAt(i) - 'a' + 1;
            h = ((h - pre * p % modulo + modulo) * power % modulo + cur) % modulo;
            if (h == hashValue) {
                j = i;
            }
        }
        return s.substring(j, j + k);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long h = 0, p = 1;
        int n = s.size();
        for (int i = n - 1; i >= n - k; --i) {
            int val = s[i] - 'a' + 1;
            h = ((h * power % modulo) + val) % modulo;
            if (i != n - k) {
                p = p * power % modulo;
            }
        }
        int j = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            int pre = s[i + k] - 'a' + 1;
            int cur = s[i] - 'a' + 1;
            h = ((h - pre * p % modulo + modulo) * power % modulo + cur) % modulo;
            if (h == hashValue) {
                j = i;
            }
        }
        return s.substr(j, k);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func subStrHash(s string, power int, modulo int, k int, hashValue int) string {
	h, p := 0, 1
	n := len(s)
	for i := n - 1; i >= n-k; i-- {
		val := int(s[i] - 'a' + 1)
		h = (h*power%modulo + val) % modulo
		if i != n-k {
			p = p * power % modulo
		}
	}
	j := n - k
	for i := n - k - 1; i >= 0; i-- {
		pre := int(s[i+k] - 'a' + 1)
		cur := int(s[i] - 'a' + 1)
		h = ((h-pre*p%modulo+modulo)*power%modulo + cur) % modulo
		if h == hashValue {
			j = i
		}
	}
	return s[j : j+k]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function subStrHash(
    s: string,
    power: number,
    modulo: number,
    k: number,
    hashValue: number,
): string {
    let h: bigint = BigInt(0),
        p: bigint = BigInt(1);
    const n: number = s.length;
    const mod = BigInt(modulo);
    for (let i: number = n - 1; i >= n - k; --i) {
        const val: bigint = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = (((h * BigInt(power)) % mod) + val) % mod;
        if (i !== n - k) {
            p = (p * BigInt(power)) % mod;
        }
    }
    let j: number = n - k;
    for (let i: number = n - k - 1; i >= 0; --i) {
        const pre: bigint = BigInt(s.charCodeAt(i + k) - 'a'.charCodeAt(0) + 1);
        const cur: bigint = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = ((((h - ((pre * p) % mod) + mod) * BigInt(power)) % mod) + cur) % mod;
        if (Number(h) === hashValue) {
            j = i;
        }
    }
    return s.substring(j, j + k);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number} power
 * @param {number} modulo
 * @param {number} k
 * @param {number} hashValue
 * @return {string}
 */
var subStrHash = function (s, power, modulo, k, hashValue) {
    let h = BigInt(0),
        p = BigInt(1);
    const n = s.length;
    const mod = BigInt(modulo);
    for (let i = n - 1; i >= n - k; --i) {
        const val = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = (((h * BigInt(power)) % mod) + val) % mod;
        if (i !== n - k) {
            p = (p * BigInt(power)) % mod;
        }
    }
    let j = n - k;
    for (let i = n - k - 1; i >= 0; --i) {
        const pre = BigInt(s.charCodeAt(i + k) - 'a'.charCodeAt(0) + 1);
        const cur = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = ((((h - ((pre * p) % mod) + mod) * BigInt(power)) % mod) + cur) % mod;
        if (Number(h) === hashValue) {
            j = i;
        }
    }
    return s.substring(j, j + k);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定整数 <code>p</code>&nbsp;和 <code>m</code>&nbsp;，一个长度为 <code>k</code>&nbsp;且下标从 <strong>0</strong>&nbsp;开始的字符串&nbsp;<code>s</code>&nbsp;的哈希值按照如下函数计算：</p>

<ul>
	<li><code>hash(s, p, m) = (val(s[0]) * p<sup>0</sup> + val(s[1]) * p<sup>1</sup> + ... + val(s[k-1]) * p<sup>k-1</sup>) mod m</code>.</li>
</ul>

<p>其中&nbsp;<code>val(s[i])</code>&nbsp;表示&nbsp;<code>s[i]</code>&nbsp;在字母表中的下标，从&nbsp;<code>val('a') = 1</code> 到&nbsp;<code>val('z') = 26</code>&nbsp;。</p>

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;和整数&nbsp;<code>power</code>，<code>modulo</code>，<code>k</code>&nbsp;和&nbsp;<code>hashValue</code>&nbsp;。请你返回 <code>s</code>&nbsp;中 <strong>第一个</strong> 长度为 <code>k</code>&nbsp;的 <strong>子串</strong>&nbsp;<code>sub</code>&nbsp;，满足<em>&nbsp;</em><code>hash(sub, power, modulo) == hashValue</code>&nbsp;。</p>

<p>测试数据保证一定 <strong>存在</strong>&nbsp;至少一个这样的子串。</p>

<p><strong>子串</strong> 定义为一个字符串中连续非空字符组成的序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "leetcode", power = 7, modulo = 20, k = 2, hashValue = 0
<strong>输出：</strong>"ee"
<strong>解释：</strong>"ee" 的哈希值为 hash("ee", 7, 20) = (5 * 1 + 5 * 7) mod 20 = 40 mod 20 = 0 。
"ee" 是长度为 2 的第一个哈希值为 0 的子串，所以我们返回 "ee" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "fbxzaad", power = 31, modulo = 100, k = 3, hashValue = 32
<b>输出：</b>"fbx"
<b>解释：</b>"fbx" 的哈希值为 hash("fbx", 31, 100) = (6 * 1 + 2 * 31 + 24 * 31<sup>2</sup>) mod 100 = 23132 mod 100 = 32 。
"bxz" 的哈希值为 hash("bxz", 31, 100) = (2 * 1 + 24 * 31 + 26 * 31<sup>2</sup>) mod 100 = 25732 mod 100 = 32 。
"fbx" 是长度为 3 的第一个哈希值为 32 的子串，所以我们返回 "fbx" 。
注意，"bxz" 的哈希值也为 32 ，但是它在字符串中比 "fbx" 更晚出现。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= power, modulo &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= hashValue &lt; modulo</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
	<li>测试数据保证一定 <strong>存在</strong>&nbsp;满足条件的子串。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口 + 倒序遍历

我们可以维护一个长度为 $k$ 的滑动窗口，用来计算子串的哈希值。考虑到如果正序遍历字符串，在哈希值的计算中，涉及到除法取模的操作，处理起来比较麻烦。因此我们可以倒序遍历字符串，这样在计算哈希值的时候，只需要乘法和取模操作。

我们首先计算字符串末尾的 $k$ 个字符的哈希值，然后从字符串末尾开始倒序遍历，每次计算当前窗口的哈希值，如果等于给定的哈希值，我们就找到了一个满足条件的子串，更新答案字符串的起始位置。

最后返回答案字符串即可。

时间复杂度 $O(n)$，其中 $n$ 是字符串的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def subStrHash(
        self, s: str, power: int, modulo: int, k: int, hashValue: int
    ) -> str:
        h, n = 0, len(s)
        p = 1
        for i in range(n - 1, n - 1 - k, -1):
            val = ord(s[i]) - ord("a") + 1
            h = ((h * power) + val) % modulo
            if i != n - k:
                p = p * power % modulo
        j = n - k
        for i in range(n - 1 - k, -1, -1):
            pre = ord(s[i + k]) - ord("a") + 1
            cur = ord(s[i]) - ord("a") + 1
            h = ((h - pre * p) * power + cur) % modulo
            if h == hashValue:
                j = i
        return s[j : j + k]
```

#### Java

```java
class Solution {
    public String subStrHash(String s, int power, int modulo, int k, int hashValue) {
        long h = 0, p = 1;
        int n = s.length();
        for (int i = n - 1; i >= n - k; --i) {
            int val = s.charAt(i) - 'a' + 1;
            h = ((h * power % modulo) + val) % modulo;
            if (i != n - k) {
                p = p * power % modulo;
            }
        }
        int j = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            int pre = s.charAt(i + k) - 'a' + 1;
            int cur = s.charAt(i) - 'a' + 1;
            h = ((h - pre * p % modulo + modulo) * power % modulo + cur) % modulo;
            if (h == hashValue) {
                j = i;
            }
        }
        return s.substring(j, j + k);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long h = 0, p = 1;
        int n = s.size();
        for (int i = n - 1; i >= n - k; --i) {
            int val = s[i] - 'a' + 1;
            h = ((h * power % modulo) + val) % modulo;
            if (i != n - k) {
                p = p * power % modulo;
            }
        }
        int j = n - k;
        for (int i = n - k - 1; i >= 0; --i) {
            int pre = s[i + k] - 'a' + 1;
            int cur = s[i] - 'a' + 1;
            h = ((h - pre * p % modulo + modulo) * power % modulo + cur) % modulo;
            if (h == hashValue) {
                j = i;
            }
        }
        return s.substr(j, k);
    }
};
```

#### Go

```go
func subStrHash(s string, power int, modulo int, k int, hashValue int) string {
	h, p := 0, 1
	n := len(s)
	for i := n - 1; i >= n-k; i-- {
		val := int(s[i] - 'a' + 1)
		h = (h*power%modulo + val) % modulo
		if i != n-k {
			p = p * power % modulo
		}
	}
	j := n - k
	for i := n - k - 1; i >= 0; i-- {
		pre := int(s[i+k] - 'a' + 1)
		cur := int(s[i] - 'a' + 1)
		h = ((h-pre*p%modulo+modulo)*power%modulo + cur) % modulo
		if h == hashValue {
			j = i
		}
	}
	return s[j : j+k]
}
```

#### TypeScript

```ts
function subStrHash(
    s: string,
    power: number,
    modulo: number,
    k: number,
    hashValue: number,
): string {
    let h: bigint = BigInt(0),
        p: bigint = BigInt(1);
    const n: number = s.length;
    const mod = BigInt(modulo);
    for (let i: number = n - 1; i >= n - k; --i) {
        const val: bigint = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = (((h * BigInt(power)) % mod) + val) % mod;
        if (i !== n - k) {
            p = (p * BigInt(power)) % mod;
        }
    }
    let j: number = n - k;
    for (let i: number = n - k - 1; i >= 0; --i) {
        const pre: bigint = BigInt(s.charCodeAt(i + k) - 'a'.charCodeAt(0) + 1);
        const cur: bigint = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = ((((h - ((pre * p) % mod) + mod) * BigInt(power)) % mod) + cur) % mod;
        if (Number(h) === hashValue) {
            j = i;
        }
    }
    return s.substring(j, j + k);
}
```

#### JavaScript

```js
/**
 * @param {string} s
 * @param {number} power
 * @param {number} modulo
 * @param {number} k
 * @param {number} hashValue
 * @return {string}
 */
var subStrHash = function (s, power, modulo, k, hashValue) {
    let h = BigInt(0),
        p = BigInt(1);
    const n = s.length;
    const mod = BigInt(modulo);
    for (let i = n - 1; i >= n - k; --i) {
        const val = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = (((h * BigInt(power)) % mod) + val) % mod;
        if (i !== n - k) {
            p = (p * BigInt(power)) % mod;
        }
    }
    let j = n - k;
    for (let i = n - k - 1; i >= 0; --i) {
        const pre = BigInt(s.charCodeAt(i + k) - 'a'.charCodeAt(0) + 1);
        const cur = BigInt(s.charCodeAt(i) - 'a'.charCodeAt(0) + 1);
        h = ((((h - ((pre * p) % mod) + mod) * BigInt(power)) % mod) + cur) % mod;
        if (Number(h) === hashValue) {
            j = i;
        }
    }
    return s.substring(j, j + k);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2157. 字符串分组](https://leetcode.cn/problems/groups-of-strings){#2157}

{{< tabs "2157" >}}

{{% tab "python" %}}
```python
class Solution:
    def groupStrings(self, words: List[str]) -> List[int]:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(a, b):
            nonlocal mx, n
            if b not in p:
                return
            pa, pb = find(a), find(b)
            if pa == pb:
                return
            p[pa] = pb
            size[pb] += size[pa]
            mx = max(mx, size[pb])
            n -= 1

        p = {}
        size = Counter()
        n = len(words)
        mx = 0
        for word in words:
            x = 0
            for c in word:
                x |= 1 << (ord(c) - ord('a'))
            p[x] = x
            size[x] += 1
            mx = max(mx, size[x])
            if size[x] > 1:
                n -= 1
        for x in p.keys():
            for i in range(26):
                union(x, x ^ (1 << i))
                if (x >> i) & 1:
                    for j in range(26):
                        if ((x >> j) & 1) == 0:
                            union(x, x ^ (1 << i) | (1 << j))
        return [n, mx]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Map<Integer, Integer> p;
    private Map<Integer, Integer> size;
    private int mx;
    private int n;

    public int[] groupStrings(String[] words) {
        p = new HashMap<>();
        size = new HashMap<>();
        n = words.length;
        mx = 0;
        for (String word : words) {
            int x = 0;
            for (char c : word.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            p.put(x, x);
            size.put(x, size.getOrDefault(x, 0) + 1);
            mx = Math.max(mx, size.get(x));
            if (size.get(x) > 1) {
                --n;
            }
        }
        for (int x : p.keySet()) {
            for (int i = 0; i < 26; ++i) {
                union(x, x ^ (1 << i));
                if (((x >> i) & 1) != 0) {
                    for (int j = 0; j < 26; ++j) {
                        if (((x >> j) & 1) == 0) {
                            union(x, x ^ (1 << i) | (1 << j));
                        }
                    }
                }
            }
        }
        return new int[] {n, mx};
    }

    private int find(int x) {
        if (p.get(x) != x) {
            p.put(x, find(p.get(x)));
        }
        return p.get(x);
    }

    private void union(int a, int b) {
        if (!p.containsKey(b)) {
            return;
        }
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return;
        }
        p.put(pa, pb);
        size.put(pb, size.get(pb) + size.get(pa));
        mx = Math.max(mx, size.get(pb));
        --n;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int mx, n;

    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int, int> p;
        unordered_map<int, int> size;
        mx = 0;
        n = words.size();
        for (auto& word : words) {
            int x = 0;
            for (auto& c : word) x |= 1 << (c - 'a');
            p[x] = x;
            ++size[x];
            mx = max(mx, size[x]);
            if (size[x] > 1) --n;
        }
        for (auto& [x, _] : p) {
            for (int i = 0; i < 26; ++i) {
                unite(x, x ^ (1 << i), p, size);
                if ((x >> i) & 1) {
                    for (int j = 0; j < 26; ++j) {
                        if (((x >> j) & 1) == 0) unite(x, x ^ (1 << i) | (1 << j), p, size);
                    }
                }
            }
        }
        return {n, mx};
    }

    int find(int x, unordered_map<int, int>& p) {
        if (p[x] != x) p[x] = find(p[x], p);
        return p[x];
    }

    void unite(int a, int b, unordered_map<int, int>& p, unordered_map<int, int>& size) {
        if (!p.count(b)) return;
        int pa = find(a, p), pb = find(b, p);
        if (pa == pb) return;
        p[pa] = pb;
        size[pb] += size[pa];
        mx = max(mx, size[pb]);
        --n;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func groupStrings(words []string) []int {
	p := map[int]int{}
	size := map[int]int{}
	mx, n := 0, len(words)
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		if _, ok := p[b]; !ok {
			return
		}
		pa, pb := find(a), find(b)
		if pa == pb {
			return
		}
		p[pa] = pb
		size[pb] += size[pa]
		mx = max(mx, size[pb])
		n--
	}

	for _, word := range words {
		x := 0
		for _, c := range word {
			x |= 1 << (c - 'a')
		}
		p[x] = x
		size[x]++
		mx = max(mx, size[x])
		if size[x] > 1 {
			n--
		}
	}
	for x := range p {
		for i := 0; i < 26; i++ {
			union(x, x^(1<<i))
			if ((x >> i) & 1) != 0 {
				for j := 0; j < 26; j++ {
					if ((x >> j) & 1) == 0 {
						union(x, x^(1<<i)|(1<<j))
					}
				}
			}
		}
	}
	return []int{n, mx}
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从&nbsp;<strong>0&nbsp;</strong>开始的字符串数组&nbsp;<code>words</code>&nbsp;。每个字符串都只包含 <strong>小写英文字母</strong>&nbsp;。<code>words</code>&nbsp;中任意一个子串中，每个字母都至多只出现一次。</p>

<p>如果通过以下操作之一，我们可以从 <code>s1</code>&nbsp;的字母集合得到 <code>s2</code>&nbsp;的字母集合，那么我们称这两个字符串为 <strong>关联的</strong>&nbsp;：</p>

<ul>
	<li>往&nbsp;<code>s1</code>&nbsp;的字母集合中添加一个字母。</li>
	<li>从&nbsp;<code>s1</code>&nbsp;的字母集合中删去一个字母。</li>
	<li>将 <code>s1</code>&nbsp;中的一个字母替换成另外任意一个字母（也可以替换为这个字母本身）。</li>
</ul>

<p>数组&nbsp;<code>words</code>&nbsp;可以分为一个或者多个无交集的 <strong>组</strong>&nbsp;。如果一个字符串与另一个字符串关联，那么它们应当属于同一个组。</p>

<p>注意，你需要确保分好组后，一个组内的任一字符串与其他组的字符串都不关联。可以证明在这个条件下，分组方案是唯一的。</p>

<p>请你返回一个长度为 <code>2</code>&nbsp;的数组&nbsp;<code>ans</code>&nbsp;：</p>

<ul>
	<li><code>ans[0]</code>&nbsp;是&nbsp;<code>words</code>&nbsp;分组后的&nbsp;<strong>总组数</strong>&nbsp;。</li>
	<li><code>ans[1]</code>&nbsp;是字符串数目最多的组所包含的字符串数目。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>words = ["a","b","ab","cde"]
<b>输出：</b>[2,3]
<b>解释：</b>
- words[0] 可以得到 words[1] （将 'a' 替换为 'b'）和 words[2] （添加 'b'）。所以 words[0] 与 words[1] 和 words[2] 关联。
- words[1] 可以得到 words[0] （将 'b' 替换为 'a'）和 words[2] （添加 'a'）。所以 words[1] 与 words[0] 和 words[2] 关联。
- words[2] 可以得到 words[0] （删去 'b'）和 words[1] （删去 'a'）。所以 words[2] 与 words[0] 和 words[1] 关联。
- words[3] 与 words 中其他字符串都不关联。
所以，words 可以分成 2 个组 ["a","b","ab"] 和 ["cde"] 。最大的组大小为 3 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>words = ["a","ab","abc"]
<b>输出：</b>[1,3]
<strong>解释：</strong>
- words[0] 与 words[1] 关联。
- words[1] 与 words[0] 和 words[2] 关联。
- words[2] 与 words[1] 关联。
由于所有字符串与其他字符串都关联，所以它们全部在同一个组内。
所以最大的组大小为 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= words[i].length &lt;= 26</code></li>
	<li><code>words[i]</code>&nbsp;只包含小写英文字母。</li>
	<li><code>words[i]</code> 中每个字母最多只出现一次。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩（位运算） + 并查集

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def groupStrings(self, words: List[str]) -> List[int]:
        def find(x):
            if p[x] != x:
                p[x] = find(p[x])
            return p[x]

        def union(a, b):
            nonlocal mx, n
            if b not in p:
                return
            pa, pb = find(a), find(b)
            if pa == pb:
                return
            p[pa] = pb
            size[pb] += size[pa]
            mx = max(mx, size[pb])
            n -= 1

        p = {}
        size = Counter()
        n = len(words)
        mx = 0
        for word in words:
            x = 0
            for c in word:
                x |= 1 << (ord(c) - ord('a'))
            p[x] = x
            size[x] += 1
            mx = max(mx, size[x])
            if size[x] > 1:
                n -= 1
        for x in p.keys():
            for i in range(26):
                union(x, x ^ (1 << i))
                if (x >> i) & 1:
                    for j in range(26):
                        if ((x >> j) & 1) == 0:
                            union(x, x ^ (1 << i) | (1 << j))
        return [n, mx]
```

#### Java

```java
class Solution {
    private Map<Integer, Integer> p;
    private Map<Integer, Integer> size;
    private int mx;
    private int n;

    public int[] groupStrings(String[] words) {
        p = new HashMap<>();
        size = new HashMap<>();
        n = words.length;
        mx = 0;
        for (String word : words) {
            int x = 0;
            for (char c : word.toCharArray()) {
                x |= 1 << (c - 'a');
            }
            p.put(x, x);
            size.put(x, size.getOrDefault(x, 0) + 1);
            mx = Math.max(mx, size.get(x));
            if (size.get(x) > 1) {
                --n;
            }
        }
        for (int x : p.keySet()) {
            for (int i = 0; i < 26; ++i) {
                union(x, x ^ (1 << i));
                if (((x >> i) & 1) != 0) {
                    for (int j = 0; j < 26; ++j) {
                        if (((x >> j) & 1) == 0) {
                            union(x, x ^ (1 << i) | (1 << j));
                        }
                    }
                }
            }
        }
        return new int[] {n, mx};
    }

    private int find(int x) {
        if (p.get(x) != x) {
            p.put(x, find(p.get(x)));
        }
        return p.get(x);
    }

    private void union(int a, int b) {
        if (!p.containsKey(b)) {
            return;
        }
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return;
        }
        p.put(pa, pb);
        size.put(pb, size.get(pb) + size.get(pa));
        mx = Math.max(mx, size.get(pb));
        --n;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int mx, n;

    vector<int> groupStrings(vector<string>& words) {
        unordered_map<int, int> p;
        unordered_map<int, int> size;
        mx = 0;
        n = words.size();
        for (auto& word : words) {
            int x = 0;
            for (auto& c : word) x |= 1 << (c - 'a');
            p[x] = x;
            ++size[x];
            mx = max(mx, size[x]);
            if (size[x] > 1) --n;
        }
        for (auto& [x, _] : p) {
            for (int i = 0; i < 26; ++i) {
                unite(x, x ^ (1 << i), p, size);
                if ((x >> i) & 1) {
                    for (int j = 0; j < 26; ++j) {
                        if (((x >> j) & 1) == 0) unite(x, x ^ (1 << i) | (1 << j), p, size);
                    }
                }
            }
        }
        return {n, mx};
    }

    int find(int x, unordered_map<int, int>& p) {
        if (p[x] != x) p[x] = find(p[x], p);
        return p[x];
    }

    void unite(int a, int b, unordered_map<int, int>& p, unordered_map<int, int>& size) {
        if (!p.count(b)) return;
        int pa = find(a, p), pb = find(b, p);
        if (pa == pb) return;
        p[pa] = pb;
        size[pb] += size[pa];
        mx = max(mx, size[pb]);
        --n;
    }
};
```

#### Go

```go
func groupStrings(words []string) []int {
	p := map[int]int{}
	size := map[int]int{}
	mx, n := 0, len(words)
	var find func(int) int
	find = func(x int) int {
		if p[x] != x {
			p[x] = find(p[x])
		}
		return p[x]
	}
	union := func(a, b int) {
		if _, ok := p[b]; !ok {
			return
		}
		pa, pb := find(a), find(b)
		if pa == pb {
			return
		}
		p[pa] = pb
		size[pb] += size[pa]
		mx = max(mx, size[pb])
		n--
	}

	for _, word := range words {
		x := 0
		for _, c := range word {
			x |= 1 << (c - 'a')
		}
		p[x] = x
		size[x]++
		mx = max(mx, size[x])
		if size[x] > 1 {
			n--
		}
	}
	for x := range p {
		for i := 0; i < 26; i++ {
			union(x, x^(1<<i))
			if ((x >> i) & 1) != 0 {
				for j := 0; j < 26; j++ {
					if ((x >> j) & 1) == 0 {
						union(x, x^(1<<i)|(1<<j))
					}
				}
			}
		}
	}
	return []int{n, mx}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2158. 每天绘制新区域的数量 🔒](https://leetcode.cn/problems/amount-of-new-area-painted-each-day){#2158}

{{< tabs "2158" >}}

{{% tab "python" %}}
```python
class Node:
    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) >> 1
        self.v = 0
        self.add = 0


class SegmentTree:
    def __init__(self):
        self.root = Node(1, 10**5 + 10)

    def modify(self, l, r, v, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = node.r - node.l + 1
            node.add = v
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modify(l, r, v, node.left)
        if r > node.mid:
            self.modify(l, r, v, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if l > r:
            return 0
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v += self.query(l, r, node.left)
        if r > node.mid:
            v += self.query(l, r, node.right)
        return v

    def pushup(self, node):
        node.v = node.left.v + node.right.v

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        if node.add:
            left, right = node.left, node.right
            left.v = left.r - left.l + 1
            right.v = right.r - right.l + 1
            left.add = node.add
            right.add = node.add
            node.add = 0


class Solution:
    def amountPainted(self, paint: List[List[int]]) -> List[int]:
        tree = SegmentTree()
        ans = []
        for i, (start, end) in enumerate(paint):
            l, r = start + 1, end
            v = tree.query(l, r)
            ans.append(r - l + 1 - v)
            tree.modify(l, r, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    Node left;
    Node right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private Node root = new Node(1, 100010);

    public SegmentTree() {
    }

    public void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    public void modify(int l, int r, int v, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = node.r - node.l + 1;
            node.add = v;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modify(l, r, v, node.left);
        }
        if (r > node.mid) {
            modify(l, r, v, node.right);
        }
        pushup(node);
    }

    public int query(int l, int r) {
        return query(l, r, root);
    }

    public int query(int l, int r, Node node) {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return node.v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node.mid) {
            v += query(l, r, node.left);
        }
        if (r > node.mid) {
            v += query(l, r, node.right);
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = node.left.v + node.right.v;
    }

    public void pushdown(Node node) {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0) {
            Node left = node.left, right = node.right;
            left.add = node.add;
            right.add = node.add;
            left.v = left.r - left.l + 1;
            right.v = right.r - right.l + 1;
            node.add = 0;
        }
    }
}

class Solution {
    public int[] amountPainted(int[][] paint) {
        SegmentTree tree = new SegmentTree();
        int n = paint.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int l = paint[i][0] + 1;
            int r = paint[i][1];
            int v = tree.query(l, r);
            ans[i] = r - l + 1 - v;
            tree.modify(l, r, 1);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 100010);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    void modify(int l, int r, int v, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = node->r - node->l + 1;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modify(l, r, v, node->left);
        if (r > node->mid) modify(l, r, v, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v += query(l, r, node->left);
        if (r > node->mid) v += query(l, r, node->right);
        return v;
    }

    void pushup(Node* node) {
        node->v = node->left->v + node->right->v;
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add) {
            Node* left = node->left;
            Node* right = node->right;
            left->v = left->r - left->l + 1;
            right->v = right->r - right->l + 1;
            left->add = node->add;
            right->add = node->add;
            node->add = 0;
        }
    }
};

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();
        vector<int> ans(n);
        SegmentTree* tree = new SegmentTree();
        for (int i = 0; i < n; ++i) {
            int l = paint[i][0] + 1;
            int r = paint[i][1];
            int v = tree->query(l, r);
            ans[i] = r - l + 1 - v;
            tree->modify(l, r, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一幅细长的画，可以用数轴来表示。 给你一个长度为 <code>n</code> 、下标从 <strong>0</strong> 开始的二维整数数组 <code>paint</code> ，其中 <code>paint[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> 表示在第 <code>i</code> 天你需要绘制 <code>start<sub>i</sub></code>&nbsp;和 <code>end<sub>i</sub></code>&nbsp;之间的区域。</p>

<p>多次绘制同一区域会导致不均匀，因此每个区域最多只能绘制 <strong>一次 </strong>。</p>

<p>返回一个长度为 <code>n</code> 的整数数组 <code>worklog</code>，其中 <code>worklog[i]</code> 是你在第 <code>i</code> 天绘制的<strong> 新 </strong>区域的数量。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2158.Amount%20of%20New%20Area%20Painted%20Each%20Day/images/screenshot-2022-02-01-at-17-16-16-diagram-drawio-diagrams-net.png" style="height: 300px; width: 620px;" />
<pre>
<strong>输入：</strong>paint = [[1,4],[4,7],[5,8]]
<strong>输出：</strong>[3,3,1]
<strong>解释：
</strong>在第 0 天，绘制 1 到 4 之间的所有内容。
第 0 天绘制的新区域数量为 4 - 1 = 3 。
在第 1 天，绘制 4 到 7 之间的所有内容。
第 1 天绘制的新区域数量为 7 - 4 = 3 。
在第 2 天，绘制 7 到 8 之间的所有内容。
5 到 7 之间的所有内容都已在第 1 天绘制完毕。
第 2 天绘制的新区域数量为 8 - 7 = 1 。
</pre>

<p><strong>示例&nbsp;2：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2158.Amount%20of%20New%20Area%20Painted%20Each%20Day/images/screenshot-2022-02-01-at-17-17-45-diagram-drawio-diagrams-net.png" style="width: 604px; height: 300px;" />
<pre>
<strong>输入：</strong>paint = [[1,4],[5,8],[4,7]]
<strong>输出：</strong>[3,3,1]
<strong>解释：</strong>
在第 0 天，绘制 1 到 4 之间的所有内容。
第 0 天绘制的新区域数量为 4 - 1 = 3 。
第 1 天，绘制 5 到 8 之间的所有内容。
第 1 天绘制的新区域数量为 8 - 5 = 3 。
在第 2 天，绘制 4 到 5 之间的所有内容。
5 到 7 之间的所有内容都已在第 1 天绘制完毕。
第 2 天绘制的新区域数量为 5 - 4 = 1 。
</pre>

<p><strong>示例&nbsp;3：</strong></p>
<img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2158.Amount%20of%20New%20Area%20Painted%20Each%20Day/images/screenshot-2022-02-01-at-17-19-49-diagram-drawio-diagrams-net.png" style="width: 423px; height: 275px;" />
<pre>
<strong>输入：</strong>paint = [[1,5],[2,4]]
<strong>输出：</strong>[4,0]
<strong>解释：</strong>
在第 0 天，绘制 1 到 5 之间的所有内容。
第 0 天绘制的新区域数量为 5 - 1 = 4 。
在第 1 天，什么都不画，因为第 0 天已经画了 2 到 4 之间的所有内容。
第 1 天绘制的新区域数量为 0 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= paint.length &lt;= 10<sup>5</sup></code></li>
	<li><code>paint[i].length == 2</code></li>
	<li><code>0 &lt;= start<sub>i</sub> &lt; end<sub>i</sub> &lt;= 5 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树

线段树将整个区间分割为多个不连续的子区间，子区间的数量不超过 `log(width)`。更新某个元素的值，只需要更新 `log(width)` 个区间，并且这些区间都包含在一个包含该元素的大区间内。区间修改时，需要使用**懒标记**保证效率。

-   线段树的每个节点代表一个区间；
-   线段树具有唯一的根节点，代表的区间是整个统计范围，如 `[1, N]`；
-   线段树的每个叶子节点代表一个长度为 1 的元区间 `[x, x]`；
-   对于每个内部节点 `[l, r]`，它的左儿子是 `[l, mid]`，右儿子是 `[mid + 1, r]`, 其中 `mid = ⌊(l + r) / 2⌋` (即向下取整)。

对于本题，线段树节点维护的信息有：

1. 区间中元素大于 0 的个数 v
1. 懒标记 add

<!-- tabs:start -->

#### Python3

```python
class Node:
    def __init__(self, l, r):
        self.left = None
        self.right = None
        self.l = l
        self.r = r
        self.mid = (l + r) >> 1
        self.v = 0
        self.add = 0


class SegmentTree:
    def __init__(self):
        self.root = Node(1, 10**5 + 10)

    def modify(self, l, r, v, node=None):
        if l > r:
            return
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            node.v = node.r - node.l + 1
            node.add = v
            return
        self.pushdown(node)
        if l <= node.mid:
            self.modify(l, r, v, node.left)
        if r > node.mid:
            self.modify(l, r, v, node.right)
        self.pushup(node)

    def query(self, l, r, node=None):
        if l > r:
            return 0
        if node is None:
            node = self.root
        if node.l >= l and node.r <= r:
            return node.v
        self.pushdown(node)
        v = 0
        if l <= node.mid:
            v += self.query(l, r, node.left)
        if r > node.mid:
            v += self.query(l, r, node.right)
        return v

    def pushup(self, node):
        node.v = node.left.v + node.right.v

    def pushdown(self, node):
        if node.left is None:
            node.left = Node(node.l, node.mid)
        if node.right is None:
            node.right = Node(node.mid + 1, node.r)
        if node.add:
            left, right = node.left, node.right
            left.v = left.r - left.l + 1
            right.v = right.r - right.l + 1
            left.add = node.add
            right.add = node.add
            node.add = 0


class Solution:
    def amountPainted(self, paint: List[List[int]]) -> List[int]:
        tree = SegmentTree()
        ans = []
        for i, (start, end) in enumerate(paint):
            l, r = start + 1, end
            v = tree.query(l, r)
            ans.append(r - l + 1 - v)
            tree.modify(l, r, 1)
        return ans
```

#### Java

```java
class Node {
    Node left;
    Node right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    public Node(int l, int r) {
        this.l = l;
        this.r = r;
        this.mid = (l + r) >> 1;
    }
}

class SegmentTree {
    private Node root = new Node(1, 100010);

    public SegmentTree() {
    }

    public void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    public void modify(int l, int r, int v, Node node) {
        if (l > r) {
            return;
        }
        if (node.l >= l && node.r <= r) {
            node.v = node.r - node.l + 1;
            node.add = v;
            return;
        }
        pushdown(node);
        if (l <= node.mid) {
            modify(l, r, v, node.left);
        }
        if (r > node.mid) {
            modify(l, r, v, node.right);
        }
        pushup(node);
    }

    public int query(int l, int r) {
        return query(l, r, root);
    }

    public int query(int l, int r, Node node) {
        if (l > r) {
            return 0;
        }
        if (node.l >= l && node.r <= r) {
            return node.v;
        }
        pushdown(node);
        int v = 0;
        if (l <= node.mid) {
            v += query(l, r, node.left);
        }
        if (r > node.mid) {
            v += query(l, r, node.right);
        }
        return v;
    }

    public void pushup(Node node) {
        node.v = node.left.v + node.right.v;
    }

    public void pushdown(Node node) {
        if (node.left == null) {
            node.left = new Node(node.l, node.mid);
        }
        if (node.right == null) {
            node.right = new Node(node.mid + 1, node.r);
        }
        if (node.add != 0) {
            Node left = node.left, right = node.right;
            left.add = node.add;
            right.add = node.add;
            left.v = left.r - left.l + 1;
            right.v = right.r - right.l + 1;
            node.add = 0;
        }
    }
}

class Solution {
    public int[] amountPainted(int[][] paint) {
        SegmentTree tree = new SegmentTree();
        int n = paint.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int l = paint[i][0] + 1;
            int r = paint[i][1];
            int v = tree.query(l, r);
            ans[i] = r - l + 1 - v;
            tree.modify(l, r, 1);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Node {
public:
    Node* left;
    Node* right;
    int l;
    int r;
    int mid;
    int v;
    int add;

    Node(int l, int r) {
        this->l = l;
        this->r = r;
        this->mid = (l + r) >> 1;
        this->left = this->right = nullptr;
        v = add = 0;
    }
};

class SegmentTree {
private:
    Node* root;

public:
    SegmentTree() {
        root = new Node(1, 100010);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, root);
    }

    void modify(int l, int r, int v, Node* node) {
        if (l > r) return;
        if (node->l >= l && node->r <= r) {
            node->v = node->r - node->l + 1;
            node->add = v;
            return;
        }
        pushdown(node);
        if (l <= node->mid) modify(l, r, v, node->left);
        if (r > node->mid) modify(l, r, v, node->right);
        pushup(node);
    }

    int query(int l, int r) {
        return query(l, r, root);
    }

    int query(int l, int r, Node* node) {
        if (l > r) return 0;
        if (node->l >= l && node->r <= r) return node->v;
        pushdown(node);
        int v = 0;
        if (l <= node->mid) v += query(l, r, node->left);
        if (r > node->mid) v += query(l, r, node->right);
        return v;
    }

    void pushup(Node* node) {
        node->v = node->left->v + node->right->v;
    }

    void pushdown(Node* node) {
        if (!node->left) node->left = new Node(node->l, node->mid);
        if (!node->right) node->right = new Node(node->mid + 1, node->r);
        if (node->add) {
            Node* left = node->left;
            Node* right = node->right;
            left->v = left->r - left->l + 1;
            right->v = right->r - right->l + 1;
            left->add = node->add;
            right->add = node->add;
            node->add = 0;
        }
    }
};

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();
        vector<int> ans(n);
        SegmentTree* tree = new SegmentTree();
        for (int i = 0; i < n; ++i) {
            int l = paint[i][0] + 1;
            int r = paint[i][1];
            int v = tree->query(l, r);
            ans[i] = r - l + 1 - v;
            tree->modify(l, r, 1);
        }
        return ans;
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2159. 分别排序两列 🔒](https://leetcode.cn/problems/order-two-columns-independently){#2159}

{{< tabs "2159" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT
            first_col,
            ROW_NUMBER() OVER (ORDER BY first_col) AS rk
        FROM Data
    ),
    T AS (
        SELECT
            second_col,
            ROW_NUMBER() OVER (ORDER BY second_col DESC) AS rk
        FROM Data
    )
SELECT first_col, second_col
FROM
    S
    JOIN T USING (rk);
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Data</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| first_col   | int  |
| second_col  | int  |
+-------------+------+
该表可能包含重复数据。
</pre>

<p>&nbsp;</p>

<p>编写解决方案，使：</p>

<ul>
	<li><code>first_col</code> 按照<strong> 升序 </strong>排列。</li>
	<li><code>second_col</code> 按照 <strong>降序 </strong>排列。</li>
</ul>

<p>返回的结果格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Data 表：
+-----------+------------+
| first_col | second_col |
+-----------+------------+
| 4         | 2          |
| 2         | 3          |
| 3         | 1          |
| 1         | 4          |
+-----------+------------+
<strong>输出：</strong>
+-----------+------------+
| first_col | second_col |
+-----------+------------+
| 1         | 4          |
| 2         | 3          |
| 3         | 2          |
| 4         | 1          |
+-----------+------------+
</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    S AS (
        SELECT
            first_col,
            ROW_NUMBER() OVER (ORDER BY first_col) AS rk
        FROM Data
    ),
    T AS (
        SELECT
            second_col,
            ROW_NUMBER() OVER (ORDER BY second_col DESC) AS rk
        FROM Data
    )
SELECT first_col, second_col
FROM
    S
    JOIN T USING (rk);
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
