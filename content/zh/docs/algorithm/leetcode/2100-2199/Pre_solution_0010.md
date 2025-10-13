---
title: "2190_数组中紧跟 key 之后出现最频繁的数字"
date: 2025-10-08T18:39:03+08:00
weight: 10
tags: [二叉树, 双指针, 哈希表, 图, 字符串, 广度优先搜索, 拓扑排序, 排序, 数学, 数据库, 数组, 数论, 栈, 树, 树状数组, 深度优先搜索, 计数, 贪心]
---

{{< markmap >}}
### [2190_数组中紧跟 key 之后出现最频繁的数字](#2190)
#### [数组](#2190)
#### [哈希表](#2190)
#### [计数](#2190)
### [2191_将杂乱无章的数字排序](#2191)
#### [数组](#2191)
#### [排序](#2191)
### [2192_有向无环图中一个节点的所有祖先](#2192)
#### [深度优先搜索](#2192)
#### [广度优先搜索](#2192)
#### [图](#2192)
#### [拓扑排序](#2192)
### [2193_得到回文串的最少操作次数](#2193)
#### [贪心](#2193)
#### [树状数组](#2193)
#### [双指针](#2193)
#### [字符串](#2193)
### [2194_Excel 表中某个范围内的单元格](#2194)
#### [字符串](#2194)
### [2195_向数组中追加 K 个整数](#2195)
#### [贪心](#2195)
#### [数组](#2195)
#### [数学](#2195)
#### [排序](#2195)
### [2196_根据描述创建二叉树](#2196)
#### [树](#2196)
#### [数组](#2196)
#### [哈希表](#2196)
#### [二叉树](#2196)
### [2197_替换数组中的非互质数](#2197)
#### [栈](#2197)
#### [数组](#2197)
#### [数学](#2197)
#### [数论](#2197)
### [2198_单因数三元组 🔒](#2198)
#### [数学](#2198)
### [2199_找到每篇文章的主题 🔒](#2199)
#### [数据库](#2199)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2190_数组中紧跟 key 之后出现最频繁的数字
___
#### 数组
___
#### 哈希表
___
#### 计数
---
### 2191_将杂乱无章的数字排序
___
#### 数组
___
#### 排序
---
### 2192_有向无环图中一个节点的所有祖先
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
---
### 2193_得到回文串的最少操作次数
___
#### 贪心
___
#### 树状数组
___
#### 双指针
___
#### 字符串
---
### 2194_Excel 表中某个范围内的单元格
___
#### 字符串
---
### 2195_向数组中追加 K 个整数
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 排序
---
### 2196_根据描述创建二叉树
___
#### 树
___
#### 数组
___
#### 哈希表
___
#### 二叉树
---
### 2197_替换数组中的非互质数
___
#### 栈
___
#### 数组
___
#### 数学
___
#### 数论
---
### 2198_单因数三元组 🔒
___
#### 数学
---
### 2199_找到每篇文章的主题 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 双指针 | 哈希表 |
| 图 | 字符串 | 广度优先搜索 |
| 拓扑排序 | 排序 | 数学 |
| 数据库 | 数组 | 数论 |
| 栈 | 树 | 树状数组 |
| 深度优先搜索 | 计数 | 贪心 |

# [2190. 数组中紧跟 key 之后出现最频繁的数字](https://leetcode.cn/problems/most-frequent-number-following-key-in-an-array){#2190}

{{< tabs "2190" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        cnt = Counter()
        ans = mx = 0
        for a, b in pairwise(nums):
            if a == key:
                cnt[b] += 1
                if mx < cnt[b]:
                    mx = cnt[b]
                    ans = b
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int mostFrequent(int[] nums, int key) {
        int[] cnt = new int[1001];
        int ans = 0, mx = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] == key) {
                if (mx < ++cnt[nums[i + 1]]) {
                    mx = cnt[nums[i + 1]];
                    ans = nums[i + 1];
                }
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
    int mostFrequent(vector<int>& nums, int key) {
        int cnt[1001]{};
        int ans = 0, mx = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == key) {
                if (mx < ++cnt[nums[i + 1]]) {
                    mx = cnt[nums[i + 1]];
                    ans = nums[i + 1];
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostFrequent(nums []int, key int) (ans int) {
	cnt := [1001]int{}
	mx := 0
	for i, x := range nums[1:] {
		if nums[i] == key {
			cnt[x]++
			if mx < cnt[x] {
				mx = cnt[x]
				ans = x
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function mostFrequent(nums: number[], key: number): number {
    const cnt: number[] = Array(Math.max(...nums) + 1).fill(0);
    let [ans, mx] = [0, 0];
    for (let i = 0; i < nums.length - 1; ++i) {
        if (nums[i] === key) {
            if (mx < ++cnt[nums[i + 1]]) {
                mx = cnt[nums[i + 1]];
                ans = nums[i + 1];
            }
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} key
 * @return {number}
 */
var mostFrequent = function (nums, key) {
    const cnt = Array(Math.max(...nums) + 1).fill(0);
    let [ans, mx] = [0, 0];
    for (let i = 0; i < nums.length - 1; ++i) {
        if (nums[i] === key) {
            if (mx < ++cnt[nums[i + 1]]) {
                mx = cnt[nums[i + 1]];
                ans = nums[i + 1];
            }
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    function mostFrequent($nums, $key) {
        $cnt = array_fill(0, max($nums) + 1, 0);
        $ans = 0;
        $mx = 0;
        for ($i = 0; $i < count($nums) - 1; ++$i) {
            if ($nums[$i] === $key) {
                $cnt[$nums[$i + 1]]++;
                if ($mx < $cnt[$nums[$i + 1]]) {
                    $mx = $cnt[$nums[$i + 1]];
                    $ans = $nums[$i + 1];
                }
            }
        }
        return $ans;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;，同时给你一个整数&nbsp;<code>key</code>&nbsp;，它在&nbsp;<code>nums</code>&nbsp;出现过。</p>

<p><strong>统计&nbsp;</strong>在 <code>nums</code>&nbsp;数组中紧跟着 <code>key</code>&nbsp;后面出现的不同整数&nbsp;<code>target</code>&nbsp;的出现次数。换言之，<code>target</code>&nbsp;的出现次数为满足以下条件的 <code>i</code>&nbsp;的数目：</p>

<ul>
	<li><code>0 &lt;= i &lt;= n - 2</code></li>
	<li><code>nums[i] == key</code>&nbsp;且</li>
	<li><code>nums[i + 1] == target</code>&nbsp;。</li>
</ul>

<p>请你返回出现 <strong>最多</strong>&nbsp;次数的<em>&nbsp;</em><code>target</code>&nbsp;。测试数据保证出现次数最多的 <code>target</code>&nbsp;是唯一的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>nums = [1,100,200,1,100], key = 1
<b>输出：</b>100
<b>解释：</b>对于 target = 100 ，在下标 1 和 4 处出现过 2 次，且都紧跟着 key 。
没有其他整数在 key 后面紧跟着出现，所以我们返回 100 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>nums = [2,2,2,2,3], key = 2
<b>输出：</b>2
<b>解释：</b>对于 target = 2 ，在下标 1 ，2 和 3 处出现过 3 次，且都紧跟着 key 。
对于 target = 3 ，在下标 4 出出现过 1 次，且紧跟着 key 。
target = 2 是紧跟着 key 之后出现次数最多的数字，所以我们返回 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
	<li>测试数据保证答案是唯一的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们用一个哈希表或数组 $\textit{cnt}$ 记录每个 $\textit{target}$ 出现的次数，用一个变量 $\textit{mx}$ 维护 $\textit{target}$ 出现的最大次数，初始时 $\textit{mx} = 0$。

遍历数组 $\textit{nums}$，如果 $\textit{nums}[i] = \textit{key}$，则 $\textit{nums}[i + 1]$ 出现的次数 $\textit{cnt}[\textit{nums}[i + 1]]$ 加一，如果此时 $\textit{mx} \lt \textit{cnt}[\textit{nums}[i + 1]]$，则更新 $\textit{mx} = \textit{cnt}[\textit{nums}[i + 1]]$，并更新答案 $\textit{ans} = \textit{nums}[i + 1]$。

遍历结束后，返回答案 $\textit{ans}$。

时间复杂度 $O(n)$，空间复杂度 $O(M)$。其中 $n$ 和 $M$ 分别为数组 $\textit{nums}$ 的长度和数组 $\textit{nums}$ 中元素的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        cnt = Counter()
        ans = mx = 0
        for a, b in pairwise(nums):
            if a == key:
                cnt[b] += 1
                if mx < cnt[b]:
                    mx = cnt[b]
                    ans = b
        return ans
```

#### Java

```java
class Solution {
    public int mostFrequent(int[] nums, int key) {
        int[] cnt = new int[1001];
        int ans = 0, mx = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] == key) {
                if (mx < ++cnt[nums[i + 1]]) {
                    mx = cnt[nums[i + 1]];
                    ans = nums[i + 1];
                }
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
    int mostFrequent(vector<int>& nums, int key) {
        int cnt[1001]{};
        int ans = 0, mx = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == key) {
                if (mx < ++cnt[nums[i + 1]]) {
                    mx = cnt[nums[i + 1]];
                    ans = nums[i + 1];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func mostFrequent(nums []int, key int) (ans int) {
	cnt := [1001]int{}
	mx := 0
	for i, x := range nums[1:] {
		if nums[i] == key {
			cnt[x]++
			if mx < cnt[x] {
				mx = cnt[x]
				ans = x
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function mostFrequent(nums: number[], key: number): number {
    const cnt: number[] = Array(Math.max(...nums) + 1).fill(0);
    let [ans, mx] = [0, 0];
    for (let i = 0; i < nums.length - 1; ++i) {
        if (nums[i] === key) {
            if (mx < ++cnt[nums[i + 1]]) {
                mx = cnt[nums[i + 1]];
                ans = nums[i + 1];
            }
        }
    }
    return ans;
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} key
 * @return {number}
 */
var mostFrequent = function (nums, key) {
    const cnt = Array(Math.max(...nums) + 1).fill(0);
    let [ans, mx] = [0, 0];
    for (let i = 0; i < nums.length - 1; ++i) {
        if (nums[i] === key) {
            if (mx < ++cnt[nums[i + 1]]) {
                mx = cnt[nums[i + 1]];
                ans = nums[i + 1];
            }
        }
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    function mostFrequent($nums, $key) {
        $cnt = array_fill(0, max($nums) + 1, 0);
        $ans = 0;
        $mx = 0;
        for ($i = 0; $i < count($nums) - 1; ++$i) {
            if ($nums[$i] === $key) {
                $cnt[$nums[$i + 1]]++;
                if ($mx < $cnt[$nums[$i + 1]]) {
                    $mx = $cnt[$nums[$i + 1]];
                    $ans = $nums[$i + 1];
                }
            }
        }
        return $ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2191. 将杂乱无章的数字排序](https://leetcode.cn/problems/sort-the-jumbled-numbers){#2191}

{{< tabs "2191" >}}

{{% tab "python" %}}
```python
class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def f(x: int) -> int:
            if x == 0:
                return mapping[0]
            y, k = 0, 1
            while x:
                x, v = divmod(x, 10)
                v = mapping[v]
                y = k * v + y
                k *= 10
            return y

        arr = sorted((f(x), i) for i, x in enumerate(nums))
        return [nums[i] for _, i in arr]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[] mapping;

    public int[] sortJumbled(int[] mapping, int[] nums) {
        this.mapping = mapping;
        int n = nums.length;
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {f(nums[i]), i};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[arr[i][1]];
        }
        return ans;
    }

    private int f(int x) {
        if (x == 0) {
            return mapping[0];
        }
        int y = 0;
        for (int k = 1; x > 0; x /= 10) {
            int v = mapping[x % 10];
            y = k * v + y;
            k *= 10;
        }
        return y;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto f = [&](int x) {
            if (x == 0) {
                return mapping[0];
            }
            int y = 0;
            for (int k = 1; x; x /= 10) {
                int v = mapping[x % 10];
                y = k * v + y;
                k *= 10;
            }
            return y;
        };
        const int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(f(nums[i]), i);
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (const auto& [_, i] : arr) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sortJumbled(mapping []int, nums []int) (ans []int) {
	n := len(nums)
	f := func(x int) (y int) {
		if x == 0 {
			return mapping[0]
		}
		for k := 1; x > 0; x /= 10 {
			v := mapping[x%10]
			y = k*v + y
			k *= 10
		}
		return
	}
	arr := make([][2]int, n)
	for i, x := range nums {
		arr[i] = [2]int{f(x), i}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] < arr[j][0] || arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1] })
	for _, p := range arr {
		ans = append(ans, nums[p[1]])
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sortJumbled(mapping: number[], nums: number[]): number[] {
    const n = nums.length;
    const f = (x: number): number => {
        if (x === 0) {
            return mapping[0];
        }
        let y = 0;
        for (let k = 1; x; x = (x / 10) | 0) {
            const v = mapping[x % 10];
            y += v * k;
            k *= 10;
        }
        return y;
    };
    const arr: number[][] = nums.map((x, i) => [f(x), i]);
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    return arr.map(x => nums[x[1]]);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function (mapping, nums) {
    const n = nums.length;
    const f = x => {
        if (x === 0) {
            return mapping[0];
        }
        let y = 0;
        for (let k = 1; x; x = (x / 10) | 0) {
            const v = mapping[x % 10];
            y += v * k;
            k *= 10;
        }
        return y;
    };
    const arr = nums.map((x, i) => [f(x), i]);
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    return arr.map(x => nums[x[1]]);
};
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn sort_jumbled(mapping: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        let f = |x: i32| -> i32 {
            if x == 0 {
                return mapping[0];
            }
            let mut y = 0;
            let mut k = 1;
            let mut num = x;
            while num != 0 {
                let v = mapping[(num % 10) as usize];
                y = k * v + y;
                k *= 10;
                num /= 10;
            }
            y
        };

        let n = nums.len();
        let mut arr: Vec<(i32, usize)> = Vec::with_capacity(n);
        for i in 0..n {
            arr.push((f(nums[i]), i));
        }
        arr.sort();

        let mut ans: Vec<i32> = Vec::with_capacity(n);
        for (_, i) in arr {
            ans.push(nums[i]);
        }
        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[] SortJumbled(int[] mapping, int[] nums) {
        Func<int, int> f = (int x) => {
            if (x == 0) {
                return mapping[0];
            }
            int y = 0;
            int k = 1;
            int num = x;
            while (num != 0) {
                int v = mapping[num % 10];
                y = k * v + y;
                k *= 10;
                num /= 10;
            }
            return y;
        };

        int n = nums.Length;
        List<(int, int)> arr = new List<(int, int)>();
        for (int i = 0; i < n; ++i) {
            arr.Add((f(nums[i]), i));
        }
        arr.Sort();

        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[arr[i].Item2];
        }
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

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>mapping</code>&nbsp;，它表示一个十进制数的映射规则，<code>mapping[i] = j</code>&nbsp;表示这个规则下将数位&nbsp;<code>i</code>&nbsp;映射为数位 <code>j</code>&nbsp;。</p>

<p>一个整数 <strong>映射后的值</strong>&nbsp;为将原数字每一个数位 <code>i</code>&nbsp;（<code>0 &lt;= i &lt;= 9</code>）映射为&nbsp;<code>mapping[i]</code>&nbsp;。</p>

<p>另外给你一个整数数组&nbsp;<code>nums</code>&nbsp;，请你将数组<em>&nbsp;</em><code>nums</code>&nbsp;中每个数按照它们映射后对应数字非递减顺序排序后返回。</p>

<p><strong>注意：</strong></p>

<ul>
	<li>如果两个数字映射后对应的数字大小相同，则将它们按照输入中的 <strong>相对顺序</strong>&nbsp;排序。</li>
	<li><code>nums</code>&nbsp;中的元素只有在排序的时候需要按照映射后的值进行比较，返回的值应该是输入的元素本身。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<b>输入：</b>mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
<b>输出：</b>[338,38,991]
<b>解释：</b>
将数字 991 按照如下规则映射：
1. mapping[9] = 6 ，所有数位 9 都会变成 6 。
2. mapping[1] = 9 ，所有数位 1 都会变成 9 。
所以，991 映射的值为 669 。
338 映射为 007 ，去掉前导 0 后得到 7 。
38 映射为 07 ，去掉前导 0 后得到 7 。
由于 338 和 38 映射后的值相同，所以它们的前后顺序保留原数组中的相对位置关系，338 在 38 的前面。
所以，排序后的数组为 [338,38,991] 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<b>输入：</b>mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
<b>输出：</b>[123,456,789]
<b>解释：</b>789 映射为 789 ，456 映射为 456 ，123 映射为 123 。所以排序后数组为 [123,456,789] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>mapping.length == 10</code></li>
	<li><code>0 &lt;= mapping[i] &lt;= 9</code></li>
	<li><code>mapping[i]</code>&nbsp;的值 <strong>互不相同</strong>&nbsp;。</li>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：自定义排序

我们遍历数组 $nums$ 中的每个元素 $nums[i]$，将其映射后的值 $y$ 与下标 $i$ 一起存入数组 $arr$ 中，然后对数组 $arr$ 进行排序，最后将排序后的数组 $arr$ 中的下标 $i$ 取出，转换为原数组 $nums$ 中的元素 $nums[i]$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        def f(x: int) -> int:
            if x == 0:
                return mapping[0]
            y, k = 0, 1
            while x:
                x, v = divmod(x, 10)
                v = mapping[v]
                y = k * v + y
                k *= 10
            return y

        arr = sorted((f(x), i) for i, x in enumerate(nums))
        return [nums[i] for _, i in arr]
```

#### Java

```java
class Solution {
    private int[] mapping;

    public int[] sortJumbled(int[] mapping, int[] nums) {
        this.mapping = mapping;
        int n = nums.length;
        int[][] arr = new int[n][0];
        for (int i = 0; i < n; ++i) {
            arr[i] = new int[] {f(nums[i]), i};
        }
        Arrays.sort(arr, (a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[arr[i][1]];
        }
        return ans;
    }

    private int f(int x) {
        if (x == 0) {
            return mapping[0];
        }
        int y = 0;
        for (int k = 1; x > 0; x /= 10) {
            int v = mapping[x % 10];
            y = k * v + y;
            k *= 10;
        }
        return y;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto f = [&](int x) {
            if (x == 0) {
                return mapping[0];
            }
            int y = 0;
            for (int k = 1; x; x /= 10) {
                int v = mapping[x % 10];
                y = k * v + y;
                k *= 10;
            }
            return y;
        };
        const int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.emplace_back(f(nums[i]), i);
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (const auto& [_, i] : arr) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
```

#### Go

```go
func sortJumbled(mapping []int, nums []int) (ans []int) {
	n := len(nums)
	f := func(x int) (y int) {
		if x == 0 {
			return mapping[0]
		}
		for k := 1; x > 0; x /= 10 {
			v := mapping[x%10]
			y = k*v + y
			k *= 10
		}
		return
	}
	arr := make([][2]int, n)
	for i, x := range nums {
		arr[i] = [2]int{f(x), i}
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i][0] < arr[j][0] || arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1] })
	for _, p := range arr {
		ans = append(ans, nums[p[1]])
	}
	return
}
```

#### TypeScript

```ts
function sortJumbled(mapping: number[], nums: number[]): number[] {
    const n = nums.length;
    const f = (x: number): number => {
        if (x === 0) {
            return mapping[0];
        }
        let y = 0;
        for (let k = 1; x; x = (x / 10) | 0) {
            const v = mapping[x % 10];
            y += v * k;
            k *= 10;
        }
        return y;
    };
    const arr: number[][] = nums.map((x, i) => [f(x), i]);
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    return arr.map(x => nums[x[1]]);
}
```

#### JavaScript

```js
/**
 * @param {number[]} mapping
 * @param {number[]} nums
 * @return {number[]}
 */
var sortJumbled = function (mapping, nums) {
    const n = nums.length;
    const f = x => {
        if (x === 0) {
            return mapping[0];
        }
        let y = 0;
        for (let k = 1; x; x = (x / 10) | 0) {
            const v = mapping[x % 10];
            y += v * k;
            k *= 10;
        }
        return y;
    };
    const arr = nums.map((x, i) => [f(x), i]);
    arr.sort((a, b) => (a[0] === b[0] ? a[1] - b[1] : a[0] - b[0]));
    return arr.map(x => nums[x[1]]);
};
```

#### Rust

```rust
impl Solution {
    pub fn sort_jumbled(mapping: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        let f = |x: i32| -> i32 {
            if x == 0 {
                return mapping[0];
            }
            let mut y = 0;
            let mut k = 1;
            let mut num = x;
            while num != 0 {
                let v = mapping[(num % 10) as usize];
                y = k * v + y;
                k *= 10;
                num /= 10;
            }
            y
        };

        let n = nums.len();
        let mut arr: Vec<(i32, usize)> = Vec::with_capacity(n);
        for i in 0..n {
            arr.push((f(nums[i]), i));
        }
        arr.sort();

        let mut ans: Vec<i32> = Vec::with_capacity(n);
        for (_, i) in arr {
            ans.push(nums[i]);
        }
        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int[] SortJumbled(int[] mapping, int[] nums) {
        Func<int, int> f = (int x) => {
            if (x == 0) {
                return mapping[0];
            }
            int y = 0;
            int k = 1;
            int num = x;
            while (num != 0) {
                int v = mapping[num % 10];
                y = k * v + y;
                k *= 10;
                num /= 10;
            }
            return y;
        };

        int n = nums.Length;
        List<(int, int)> arr = new List<(int, int)>();
        for (int i = 0; i < n; ++i) {
            arr.Add((f(nums[i]), i));
        }
        arr.Sort();

        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[arr[i].Item2];
        }
        return ans;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2192. 有向无环图中一个节点的所有祖先](https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph){#2192}

{{< tabs "2192" >}}

{{% tab "python" %}}
```python
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        def bfs(s: int):
            q = deque([s])
            vis = {s}
            while q:
                i = q.popleft()
                for j in g[i]:
                    if j not in vis:
                        vis.add(j)
                        q.append(j)
                        ans[j].append(s)

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
        ans = [[] for _ in range(n)]
        for i in range(n):
            bfs(i)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private List<Integer>[] g;
    private List<List<Integer>> ans;

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        g = new List[n];
        this.n = n;
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            g[e[0]].add(e[1]);
        }
        ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            ans.add(new ArrayList<>());
        }
        for (int i = 0; i < n; ++i) {
            bfs(i);
        }
        return ans;
    }

    private void bfs(int s) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(s);
        boolean[] vis = new boolean[n];
        vis[s] = true;
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j : g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.offer(j);
                    ans.get(j).add(s);
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
        }
        vector<vector<int>> ans(n);
        auto bfs = [&](int s) {
            queue<int> q;
            q.push(s);
            bool vis[n];
            memset(vis, 0, sizeof(vis));
            vis[s] = true;
            while (q.size()) {
                int i = q.front();
                q.pop();
                for (int j : g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        ans[j].push_back(s);
                        q.push(j);
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            bfs(i);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getAncestors(n int, edges [][]int) [][]int {
	g := make([][]int, n)
	for _, e := range edges {
		g[e[0]] = append(g[e[0]], e[1])
	}
	ans := make([][]int, n)
	bfs := func(s int) {
		q := []int{s}
		vis := make([]bool, n)
		vis[s] = true
		for len(q) > 0 {
			i := q[0]
			q = q[1:]
			for _, j := range g[i] {
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
					ans[j] = append(ans[j], s)
				}
			}
		}
	}
	for i := 0; i < n; i++ {
		bfs(i)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getAncestors(n: number, edges: number[][]): number[][] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
    }
    const ans: number[][] = Array.from({ length: n }, () => []);
    const bfs = (s: number) => {
        const q: number[] = [s];
        const vis: boolean[] = Array.from({ length: n }, () => false);
        vis[s] = true;
        while (q.length) {
            const i = q.pop()!;
            for (const j of g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    ans[j].push(s);
                    q.push(j);
                }
            }
        }
    };
    for (let i = 0; i < n; ++i) {
        bfs(i);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    private int n;
    private List<int>[] g;
    private IList<IList<int>> ans;

    public IList<IList<int>> GetAncestors(int n, int[][] edges) {
        g = new List<int>[n];
        this.n = n;
        for (int i = 0; i < n; i++) {
            g[i] = new List<int>();
        }
        foreach (var e in edges) {
            g[e[0]].Add(e[1]);
        }
        ans = new List<IList<int>>();
        for (int i = 0; i < n; ++i) {
            ans.Add(new List<int>());
        }
        for (int i = 0; i < n; ++i) {
            BFS(i);
        }
        return ans;
    }

    private void BFS(int s) {
        Queue<int> q = new Queue<int>();
        q.Enqueue(s);
        bool[] vis = new bool[n];
        vis[s] = true;
        while (q.Count > 0) {
            int i = q.Dequeue();
            foreach (int j in g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.Enqueue(j);
                    ans[j].Add(s);
                }
            }
        }
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数&nbsp;<code>n</code>&nbsp;，它表示一个 <strong>有向无环图</strong>&nbsp;中节点的数目，节点编号为&nbsp;<code>0</code>&nbsp;到&nbsp;<code>n - 1</code>&nbsp;（包括两者）。</p>

<p>给你一个二维整数数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [from<sub>i</sub>, to<sub>i</sub>]</code>&nbsp;表示图中一条从&nbsp;<code>from<sub>i</sub></code>&nbsp;到&nbsp;<code>to<sub>i</sub></code>&nbsp;的单向边。</p>

<p>请你返回一个数组&nbsp;<code>answer</code>，其中<em>&nbsp;</em><code>answer[i]</code>是第&nbsp;<code>i</code>&nbsp;个节点的所有&nbsp;<strong>祖先</strong>&nbsp;，这些祖先节点&nbsp;<strong>升序</strong>&nbsp;排序。</p>

<p>如果 <code>u</code>&nbsp;通过一系列边，能够到达 <code>v</code>&nbsp;，那么我们称节点 <code>u</code>&nbsp;是节点 <code>v</code>&nbsp;的 <strong>祖先</strong>&nbsp;节点。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2192.All%20Ancestors%20of%20a%20Node%20in%20a%20Directed%20Acyclic%20Graph/images/e1.png" style="width: 322px; height: 265px;"></p>

<pre><b>输入：</b>n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
<b>输出：</b>[[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
<strong>解释：</strong>
上图为输入所对应的图。
- 节点 0 ，1 和 2 没有任何祖先。
- 节点 3 有 2 个祖先 0 和 1 。
- 节点 4 有 2 个祖先 0 和 2 。
- 节点 5 有 3 个祖先 0 ，1 和 3 。
- 节点 6 有 5 个祖先 0 ，1 ，2 ，3 和 4 。
- 节点 7 有 4 个祖先 0 ，1 ，2 和 3 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2192.All%20Ancestors%20of%20a%20Node%20in%20a%20Directed%20Acyclic%20Graph/images/e2.png" style="width: 343px; height: 299px;"></p>

<pre><b>输入：</b>n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
<b>输出：</b>[[],[0],[0,1],[0,1,2],[0,1,2,3]]
<strong>解释：</strong>
上图为输入所对应的图。
- 节点 0 没有任何祖先。
- 节点 1 有 1 个祖先 0 。
- 节点 2 有 2 个祖先 0 和 1 。
- 节点 3 有 3 个祖先 0 ，1 和 2 。
- 节点 4 有 4 个祖先 0 ，1 ，2 和 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= edges.length &lt;= min(2000, n * (n - 1) / 2)</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= from<sub>i</sub>, to<sub>i</sub> &lt;= n - 1</code></li>
	<li><code>from<sub>i</sub> != to<sub>i</sub></code></li>
	<li>图中不会有重边。</li>
	<li>图是 <strong>有向</strong> 且 <strong>无环</strong> 的。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：BFS

我们先根据二维数组 $edges$ 构建邻接表 $g$，其中 $g[i]$ 表示节点 $i$ 的所有后继节点。

然后我们从小到大枚举节点 $i$ 作为祖先节点，使用 BFS 搜索节点 $i$ 的所有后继节点，把节点 $i$ 加入这些后继节点的祖先列表中。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是节点数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        def bfs(s: int):
            q = deque([s])
            vis = {s}
            while q:
                i = q.popleft()
                for j in g[i]:
                    if j not in vis:
                        vis.add(j)
                        q.append(j)
                        ans[j].append(s)

        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
        ans = [[] for _ in range(n)]
        for i in range(n):
            bfs(i)
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private List<Integer>[] g;
    private List<List<Integer>> ans;

    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        g = new List[n];
        this.n = n;
        Arrays.setAll(g, i -> new ArrayList<>());
        for (var e : edges) {
            g[e[0]].add(e[1]);
        }
        ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            ans.add(new ArrayList<>());
        }
        for (int i = 0; i < n; ++i) {
            bfs(i);
        }
        return ans;
    }

    private void bfs(int s) {
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(s);
        boolean[] vis = new boolean[n];
        vis[s] = true;
        while (!q.isEmpty()) {
            int i = q.poll();
            for (int j : g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.offer(j);
                    ans.get(j).add(s);
                }
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
        }
        vector<vector<int>> ans(n);
        auto bfs = [&](int s) {
            queue<int> q;
            q.push(s);
            bool vis[n];
            memset(vis, 0, sizeof(vis));
            vis[s] = true;
            while (q.size()) {
                int i = q.front();
                q.pop();
                for (int j : g[i]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        ans[j].push_back(s);
                        q.push(j);
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            bfs(i);
        }
        return ans;
    }
};
```

#### Go

```go
func getAncestors(n int, edges [][]int) [][]int {
	g := make([][]int, n)
	for _, e := range edges {
		g[e[0]] = append(g[e[0]], e[1])
	}
	ans := make([][]int, n)
	bfs := func(s int) {
		q := []int{s}
		vis := make([]bool, n)
		vis[s] = true
		for len(q) > 0 {
			i := q[0]
			q = q[1:]
			for _, j := range g[i] {
				if !vis[j] {
					vis[j] = true
					q = append(q, j)
					ans[j] = append(ans[j], s)
				}
			}
		}
	}
	for i := 0; i < n; i++ {
		bfs(i)
	}
	return ans
}
```

#### TypeScript

```ts
function getAncestors(n: number, edges: number[][]): number[][] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        g[u].push(v);
    }
    const ans: number[][] = Array.from({ length: n }, () => []);
    const bfs = (s: number) => {
        const q: number[] = [s];
        const vis: boolean[] = Array.from({ length: n }, () => false);
        vis[s] = true;
        while (q.length) {
            const i = q.pop()!;
            for (const j of g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    ans[j].push(s);
                    q.push(j);
                }
            }
        }
    };
    for (let i = 0; i < n; ++i) {
        bfs(i);
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    private int n;
    private List<int>[] g;
    private IList<IList<int>> ans;

    public IList<IList<int>> GetAncestors(int n, int[][] edges) {
        g = new List<int>[n];
        this.n = n;
        for (int i = 0; i < n; i++) {
            g[i] = new List<int>();
        }
        foreach (var e in edges) {
            g[e[0]].Add(e[1]);
        }
        ans = new List<IList<int>>();
        for (int i = 0; i < n; ++i) {
            ans.Add(new List<int>());
        }
        for (int i = 0; i < n; ++i) {
            BFS(i);
        }
        return ans;
    }

    private void BFS(int s) {
        Queue<int> q = new Queue<int>();
        q.Enqueue(s);
        bool[] vis = new bool[n];
        vis[s] = true;
        while (q.Count > 0) {
            int i = q.Dequeue();
            foreach (int j in g[i]) {
                if (!vis[j]) {
                    vis[j] = true;
                    q.Enqueue(j);
                    ans[j].Add(s);
                }
            }
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2193. 得到回文串的最少操作次数](https://leetcode.cn/problems/minimum-number-of-moves-to-make-palindrome){#2193}

{{< tabs "2193" >}}

{{% tab "python" %}}
```python
class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        cs = list(s)
        ans, n = 0, len(s)
        i, j = 0, n - 1
        while i < j:
            even = False
            for k in range(j, i, -1):
                if cs[i] == cs[k]:
                    even = True
                    while k < j:
                        cs[k], cs[k + 1] = cs[k + 1], cs[k]
                        k += 1
                        ans += 1
                    j -= 1
                    break
            if not even:
                ans += n // 2 - i
            i += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minMovesToMakePalindrome(String s) {
        int n = s.length();
        int ans = 0;
        char[] cs = s.toCharArray();
        for (int i = 0, j = n - 1; i < j; ++i) {
            boolean even = false;
            for (int k = j; k != i; --k) {
                if (cs[i] == cs[k]) {
                    even = true;
                    for (; k < j; ++k) {
                        char t = cs[k];
                        cs[k] = cs[k + 1];
                        cs[k + 1] = t;
                        ++ans;
                    }
                    --j;
                    break;
                }
            }
            if (!even) {
                ans += n / 2 - i;
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
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i) {
            bool even = false;
            for (int k = j; k != i; --k) {
                if (s[i] == s[k]) {
                    even = true;
                    for (; k < j; ++k) {
                        swap(s[k], s[k + 1]);
                        ++ans;
                    }
                    --j;
                    break;
                }
            }
            if (!even) ans += n / 2 - i;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minMovesToMakePalindrome(s string) int {
	cs := []byte(s)
	ans, n := 0, len(s)
	for i, j := 0, n-1; i < j; i++ {
		even := false
		for k := j; k != i; k-- {
			if cs[i] == cs[k] {
				even = true
				for ; k < j; k++ {
					cs[k], cs[k+1] = cs[k+1], cs[k]
					ans++
				}
				j--
				break
			}
		}
		if !even {
			ans += n/2 - i
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

<p>给你一个只包含小写英文字母的字符串&nbsp;<code>s</code>&nbsp;。</p>

<p>每一次 <strong>操作</strong>&nbsp;，你可以选择 <code>s</code>&nbsp;中两个 <strong>相邻</strong>&nbsp;的字符，并将它们交换。</p>

<p>请你返回将 <code>s</code>&nbsp;变成回文串的 <strong>最少操作次数</strong>&nbsp;。</p>

<p><strong>注意</strong>&nbsp;，输入数据会确保&nbsp;<code>s</code>&nbsp;一定能变成一个回文串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><b>输入：</b>s = "aabb"
<b>输出：</b>2
<strong>解释：</strong>
我们可以将 s 变成 2 个回文串，"abba" 和 "baab" 。
- 我们可以通过 2 次操作得到 "abba" ："a<em><strong>ab</strong></em>b" -&gt; "ab<em><strong>ab</strong></em>" -&gt; "abba" 。
- 我们可以通过 2 次操作得到 "baab" ："a<em><strong>ab</strong></em>b" -&gt; "<em><strong>ab</strong></em>ab" -&gt; "baab" 。
因此，得到回文串的最少总操作次数为 2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><b>输入：</b>s = "letelt"
<b>输出：</b>2
<strong>解释：</strong>
通过 2 次操作从 s 能得到回文串 "lettel" 。
其中一种方法是："lete<em><strong>lt</strong></em>" -&gt; "let<em><strong>et</strong></em>l" -&gt; "lettel" 。
其他回文串比方说 "tleelt" 也可以通过 2 次操作得到。
可以证明少于 2 次操作，无法得到回文串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
	<li><code>s</code>&nbsp;可以通过有限次操作得到一个回文串。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

由于题目保证原串一定可以变成回文串，那么原串中最多只有一种字母出现奇数次。如果有一种字母出现奇数次，那么将该字母中排在最中间的字符移动到字符串中间，剩下的字符可以转化为所有字母均出现偶数次的情况。

贪心算法是：每次固定字符串最左边的字母 $a$ 不变，找出距离字符串右侧最近的 $a$，把它交换到字符串最右边。这样字符串的头尾字母就相等了。把字符串的头尾去掉，就变成了子问题。把所有子问题的答案加起来就是最少交换次数。

由于数据范围较小，通过 ${O}(n^2)$ 的模拟即可通过本题。

证明：

构造回文串的过程，实际上是每次选择一对字母并把它们交换到字符串头尾的过程。考虑字母 $x$ 和字母 $y$ 哪个先选，分以下情况讨论：

-   字母 $x$ 和 $y$ 的位置满足 $\underbrace{\cdots}_{a\textit{ 个}}x\underbrace{\cdots}_{b\textit{ 个}}y\underbrace{\cdots}_{c\textit{ 个}}y\underbrace{\cdots}_{d\textit{ 个}}x\underbrace{\cdots}_{e\textit{ 个}}$。如果先把 $x$ 换到头尾，再把 $y$ 换到头尾，那么需要 $(a + e) + (b + d)$ 次交换；如果先换 $y$ 再换 $x$，那么需要 $(a + b + 1 + d + e + 1) + (a + e)$ 次交换。显然先换 $x$ 更优。
-   字母 $x$ 和 $y$ 的位置满足 $\underbrace{\cdots}_{a\textit{ 个}}x\underbrace{\cdots}_{b\textit{ 个}}y\underbrace{\cdots}_{c\textit{ 个}}x\underbrace{\cdots}_{d\textit{ 个}}y\underbrace{\cdots}_{e\textit{ 个}}$。如果先换 $x$ 再换 $y$，那么需要 $(a + d + e + 1) + (a + b + e)$ 次交换；如果先换 $y$ 再换 $x$，那么需要 $(a + b + 1 + e) + (a + d + e)$ 次交换。先换哪个都一样。
-   字母 $x$ 和 $y$ 的位置满足 $\underbrace{\cdots}_{a\textit{ 个}}x\underbrace{\cdots}_{b\textit{ 个}}x\underbrace{\cdots}_{c\textit{ 个}}y\underbrace{\cdots}_{d\textit{ 个}}y\underbrace{\cdots}_{e\textit{ 个}}$。如果先换 $x$ 再换 $y$，那么需要 $(a + c + d + e + 2) + (a + b + c + e)$ 次交换；如果先换 $y$ 再换 $x$，那么需要 $(a + b + c + 2 + e) + (a + c + d + e)$ 次交换。先换哪个都一样。

上述讨论可以得到结论：每次交换最外边出现的字母不劣。因此贪心解法成立。

> 出处：https://leetcode.cn/problems/minimum-number-of-moves-to-make-palindrome/solution/tan-xin-zheng-ming-geng-da-shu-ju-fan-we-h57i/

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        cs = list(s)
        ans, n = 0, len(s)
        i, j = 0, n - 1
        while i < j:
            even = False
            for k in range(j, i, -1):
                if cs[i] == cs[k]:
                    even = True
                    while k < j:
                        cs[k], cs[k + 1] = cs[k + 1], cs[k]
                        k += 1
                        ans += 1
                    j -= 1
                    break
            if not even:
                ans += n // 2 - i
            i += 1
        return ans
```

#### Java

```java
class Solution {
    public int minMovesToMakePalindrome(String s) {
        int n = s.length();
        int ans = 0;
        char[] cs = s.toCharArray();
        for (int i = 0, j = n - 1; i < j; ++i) {
            boolean even = false;
            for (int k = j; k != i; --k) {
                if (cs[i] == cs[k]) {
                    even = true;
                    for (; k < j; ++k) {
                        char t = cs[k];
                        cs[k] = cs[k + 1];
                        cs[k + 1] = t;
                        ++ans;
                    }
                    --j;
                    break;
                }
            }
            if (!even) {
                ans += n / 2 - i;
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
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0, j = n - 1; i < j; ++i) {
            bool even = false;
            for (int k = j; k != i; --k) {
                if (s[i] == s[k]) {
                    even = true;
                    for (; k < j; ++k) {
                        swap(s[k], s[k + 1]);
                        ++ans;
                    }
                    --j;
                    break;
                }
            }
            if (!even) ans += n / 2 - i;
        }
        return ans;
    }
};
```

#### Go

```go
func minMovesToMakePalindrome(s string) int {
	cs := []byte(s)
	ans, n := 0, len(s)
	for i, j := 0, n-1; i < j; i++ {
		even := false
		for k := j; k != i; k-- {
			if cs[i] == cs[k] {
				even = true
				for ; k < j; k++ {
					cs[k], cs[k+1] = cs[k+1], cs[k]
					ans++
				}
				j--
				break
			}
		}
		if !even {
			ans += n/2 - i
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

# [2194. Excel 表中某个范围内的单元格](https://leetcode.cn/problems/cells-in-a-range-on-an-excel-sheet){#2194}

{{< tabs "2194" >}}

{{% tab "python" %}}
```python
class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        return [
            chr(i) + str(j)
            for i in range(ord(s[0]), ord(s[-2]) + 1)
            for j in range(int(s[1]), int(s[-1]) + 1)
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> cellsInRange(String s) {
        List<String> ans = new ArrayList<>();
        for (char i = s.charAt(0); i <= s.charAt(3); ++i) {
            for (char j = s.charAt(1); j <= s.charAt(4); ++j) {
                ans.add(i + "" + j);
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
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (char i = s[0]; i <= s[3]; ++i) {
            for (char j = s[1]; j <= s[4]; ++j) {
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func cellsInRange(s string) (ans []string) {
	for i := s[0]; i <= s[3]; i++ {
		for j := s[1]; j <= s[4]; j++ {
			ans = append(ans, string(i)+string(j))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function cellsInRange(s: string): string[] {
    const ans: string[] = [];
    for (let i = s.charCodeAt(0); i <= s.charCodeAt(3); ++i) {
        for (let j = s.charCodeAt(1); j <= s.charCodeAt(4); ++j) {
            ans.push(String.fromCharCode(i) + String.fromCharCode(j));
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

<p>Excel 表中的一个单元格 <code>(r, c)</code> 会以字符串 <code>"&lt;col&gt;&lt;row&gt;"</code> 的形式进行表示，其中：</p>

<ul>
	<li><code>&lt;col&gt;</code> 即单元格的列号 <code>c</code> 。用英文字母表中的 <strong>字母</strong> 标识。

    <ul>
    	<li>例如，第 <code>1</code> 列用 <code>'A'</code> 表示，第 <code>2</code> 列用 <code>'B'</code> 表示，第 <code>3</code> 列用 <code>'C'</code> 表示，以此类推。</li>
    </ul>
    </li>
    <li><code>&lt;row&gt;</code> 即单元格的行号 <code>r</code> 。第 <code>r</code> 行就用 <strong>整数</strong> <code>r</code> 标识。</li>

</ul>

<p>给你一个格式为 <code>"&lt;col1&gt;&lt;row1&gt;:&lt;col2&gt;&lt;row2&gt;"</code> 的字符串 <code>s</code> ，其中 <code>&lt;col1&gt;</code> 表示 <code>c1</code> 列，<code>&lt;row1&gt;</code> 表示 <code>r1</code> 行，<code>&lt;col2&gt;</code> 表示 <code>c2</code> 列，<code>&lt;row2&gt;</code> 表示 <code>r2</code> 行，并满足 <code>r1 &lt;= r2</code> 且 <code>c1 &lt;= c2</code> 。</p>

<p>找出所有满足&nbsp;<code>r1 &lt;= x &lt;= r2</code> 且 <code>c1 &lt;= y &lt;= c2</code> 的单元格，并以列表形式返回。单元格应该按前面描述的格式用 <strong>字符串</strong> 表示，并以 <strong>非递减</strong> 顺序排列（先按列排，再按行排）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2194.Cells%20in%20a%20Range%20on%20an%20Excel%20Sheet/images/ex1drawio.png" style="width: 250px; height: 160px;" /></p>

<pre>
<strong>输入：</strong>s = "K1:L2"
<strong>输出：</strong>["K1","K2","L1","L2"]
<strong>解释：</strong>
上图显示了列表中应该出现的单元格。
红色箭头指示单元格的出现顺序。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2194.Cells%20in%20a%20Range%20on%20an%20Excel%20Sheet/images/exam2drawio.png" style="width: 500px; height: 50px;" /></p>

<pre>
<strong>输入：</strong>s = "A1:F1"
<strong>输出：</strong>["A1","B1","C1","D1","E1","F1"]
<strong>解释：</strong>
上图显示了列表中应该出现的单元格。 
红色箭头指示单元格的出现顺序。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == 5</code></li>
	<li><code>'A' &lt;= s[0] &lt;= s[3] &lt;= 'Z'</code></li>
	<li><code>'1' &lt;= s[1] &lt;= s[4] &lt;= '9'</code></li>
	<li><code>s</code> 由大写英文字母、数字、和 <code>':'</code> 组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接遍历范围内的所有单元格，将其添加到答案数组中。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别为行数和列数的取值范围。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        return [
            chr(i) + str(j)
            for i in range(ord(s[0]), ord(s[-2]) + 1)
            for j in range(int(s[1]), int(s[-1]) + 1)
        ]
```

#### Java

```java
class Solution {
    public List<String> cellsInRange(String s) {
        List<String> ans = new ArrayList<>();
        for (char i = s.charAt(0); i <= s.charAt(3); ++i) {
            for (char j = s.charAt(1); j <= s.charAt(4); ++j) {
                ans.add(i + "" + j);
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
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for (char i = s[0]; i <= s[3]; ++i) {
            for (char j = s[1]; j <= s[4]; ++j) {
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};
```

#### Go

```go
func cellsInRange(s string) (ans []string) {
	for i := s[0]; i <= s[3]; i++ {
		for j := s[1]; j <= s[4]; j++ {
			ans = append(ans, string(i)+string(j))
		}
	}
	return
}
```

#### TypeScript

```ts
function cellsInRange(s: string): string[] {
    const ans: string[] = [];
    for (let i = s.charCodeAt(0); i <= s.charCodeAt(3); ++i) {
        for (let j = s.charCodeAt(1); j <= s.charCodeAt(4); ++j) {
            ans.push(String.fromCharCode(i) + String.fromCharCode(j));
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

# [2195. 向数组中追加 K 个整数](https://leetcode.cn/problems/append-k-integers-with-minimal-sum){#2195}

{{< tabs "2195" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        nums.extend([0, 2 * 10**9])
        nums.sort()
        ans = 0
        for a, b in pairwise(nums):
            m = max(0, min(k, b - a - 1))
            ans += (a + 1 + a + m) * m // 2
            k -= m
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long minimalKSum(int[] nums, int k) {
        int n = nums.length;
        int[] arr = new int[n + 2];
        arr[1] = 2 * 1000000000;
        System.arraycopy(nums, 0, arr, 2, n);
        Arrays.sort(arr);
        long ans = 0;
        for (int i = 0; i < n + 1 && k > 0; ++i) {
            int m = Math.max(0, Math.min(k, arr[i + 1] - arr[i] - 1));
            ans += (arr[i] + 1L + arr[i] + m) * m / 2;
            k -= m;
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
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0);
        nums.push_back(2e9);
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size() - 1 && k > 0; ++i) {
            int m = max(0, min(k, nums[i + 1] - nums[i] - 1));
            ans += 1LL * (nums[i] + 1 + nums[i] + m) * m / 2;
            k -= m;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimalKSum(nums []int, k int) (ans int64) {
	nums = append(nums, []int{0, 2e9}...)
	sort.Ints(nums)
	for i, b := range nums[1:] {
		a := nums[i]
		m := max(0, min(k, b-a-1))
		ans += int64(a+1+a+m) * int64(m) / 2
		k -= m
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimalKSum(nums: number[], k: number): number {
    nums.push(...[0, 2 * 10 ** 9]);
    nums.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < nums.length - 1; ++i) {
        const m = Math.max(0, Math.min(k, nums[i + 1] - nums[i] - 1));
        ans += Number((BigInt(nums[i] + 1 + nums[i] + m) * BigInt(m)) / BigInt(2));
        k -= m;
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

<p>给你一个整数数组 <code>nums</code> 和一个整数 <code>k</code> 。请你向 <code>nums</code> 中追加 <code>k</code> 个 <strong>未</strong> 出现在 <code>nums</code> 中的、<strong>互不相同</strong> 的 <strong>正</strong> 整数，并使结果数组的元素和 <strong>最小</strong> 。</p>

<p>返回追加到 <code>nums</code> 中的 <code>k</code> 个整数之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [1,4,25,10,25], k = 2
<strong>输出：</strong>5
<strong>解释：</strong>在该解法中，向数组中追加的两个互不相同且未出现的正整数是 2 和 3 。
nums 最终元素和为 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70 ，这是所有情况中的最小值。
所以追加到数组中的两个整数之和是 2 + 3 = 5 ，所以返回 5 。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [5,6], k = 6
<strong>输出：</strong>25
<strong>解释：</strong>在该解法中，向数组中追加的两个互不相同且未出现的正整数是 1 、2 、3 、4 、7 和 8 。
nums 最终元素和为 5 + 6 + 1 + 2 + 3 + 4 + 7 + 8 = 36 ，这是所有情况中的最小值。
所以追加到数组中的两个整数之和是 1 + 2 + 3 + 4 + 7 + 8 = 25 ，所以返回 25 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 贪心 + 数学

我们不妨向数组中加入两个哨兵节点，分别为 $0$ 和 $2 \times 10^9$。

然后我们对数组进行排序，那么对于数组中的任意两个相邻的元素 $a$ 和 $b$，区间 $[a+1, b-1]$ 中的整数都是未出现在数组中的，我们可以将这些整数加入到数组中。

因此，我们从小到大遍历数组中的相邻元素对 $(a, b)$，对于每个相邻元素对，我们计算区间 $[a+1, b-1]$ 中的整数个数 $m$，那么这 $m$ 个整数的和为 $\frac{m \times (a+1 + a+m)}{2}$，我们将这个和累加到答案中，并将 $k$ 减去 $m$。如果 $k$ 减到 $0$，我们就可以停止遍历了，返回答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(\log n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        nums.extend([0, 2 * 10**9])
        nums.sort()
        ans = 0
        for a, b in pairwise(nums):
            m = max(0, min(k, b - a - 1))
            ans += (a + 1 + a + m) * m // 2
            k -= m
        return ans
```

#### Java

```java
class Solution {
    public long minimalKSum(int[] nums, int k) {
        int n = nums.length;
        int[] arr = new int[n + 2];
        arr[1] = 2 * 1000000000;
        System.arraycopy(nums, 0, arr, 2, n);
        Arrays.sort(arr);
        long ans = 0;
        for (int i = 0; i < n + 1 && k > 0; ++i) {
            int m = Math.max(0, Math.min(k, arr[i + 1] - arr[i] - 1));
            ans += (arr[i] + 1L + arr[i] + m) * m / 2;
            k -= m;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        nums.push_back(0);
        nums.push_back(2e9);
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size() - 1 && k > 0; ++i) {
            int m = max(0, min(k, nums[i + 1] - nums[i] - 1));
            ans += 1LL * (nums[i] + 1 + nums[i] + m) * m / 2;
            k -= m;
        }
        return ans;
    }
};
```

#### Go

```go
func minimalKSum(nums []int, k int) (ans int64) {
	nums = append(nums, []int{0, 2e9}...)
	sort.Ints(nums)
	for i, b := range nums[1:] {
		a := nums[i]
		m := max(0, min(k, b-a-1))
		ans += int64(a+1+a+m) * int64(m) / 2
		k -= m
	}
	return ans
}
```

#### TypeScript

```ts
function minimalKSum(nums: number[], k: number): number {
    nums.push(...[0, 2 * 10 ** 9]);
    nums.sort((a, b) => a - b);
    let ans = 0;
    for (let i = 0; i < nums.length - 1; ++i) {
        const m = Math.max(0, Math.min(k, nums[i + 1] - nums[i] - 1));
        ans += Number((BigInt(nums[i] + 1 + nums[i] + m) * BigInt(m)) / BigInt(2));
        k -= m;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2196. 根据描述创建二叉树](https://leetcode.cn/problems/create-binary-tree-from-descriptions){#2196}

{{< tabs "2196" >}}

{{% tab "python" %}}
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = defaultdict(TreeNode)
        children = set()
        for parent, child, isLeft in descriptions:
            if parent not in nodes:
                nodes[parent] = TreeNode(parent)
            if child not in nodes:
                nodes[child] = TreeNode(child)
            children.add(child)
            if isLeft:
                nodes[parent].left = nodes[child]
            else:
                nodes[parent].right = nodes[child]
        root = (set(nodes.keys()) - children).pop()
        return nodes[root]
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> nodes = new HashMap<>();
        Set<Integer> children = new HashSet<>();
        for (var d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (!nodes.containsKey(parent)) {
                nodes.put(parent, new TreeNode(parent));
            }
            if (!nodes.containsKey(child)) {
                nodes.put(child, new TreeNode(child));
            }
            if (isLeft == 1) {
                nodes.get(parent).left = nodes.get(child);
            } else {
                nodes.get(parent).right = nodes.get(child);
            }
            children.add(child);
        }
        for (var e : nodes.entrySet()) {
            if (!children.contains(e.getKey())) {
                return e.getValue();
            }
        }
        return null;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (const auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (!nodes.contains(parent)) {
                nodes[parent] = new TreeNode(parent);
            }
            if (!nodes.contains(child)) {
                nodes[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            children.insert(child);
        }
        for (const auto& [k, v] : nodes) {
            if (!children.contains(k)) {
                return v;
            }
        }
        return nullptr;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func createBinaryTree(descriptions [][]int) *TreeNode {
	nodes := map[int]*TreeNode{}
	children := map[int]bool{}
	for _, d := range descriptions {
		parent, child, isLeft := d[0], d[1], d[2]
		if _, ok := nodes[parent]; !ok {
			nodes[parent] = &TreeNode{Val: parent}
		}
		if _, ok := nodes[child]; !ok {
			nodes[child] = &TreeNode{Val: child}
		}
		if isLeft == 1 {
			nodes[parent].Left = nodes[child]
		} else {
			nodes[parent].Right = nodes[child]
		}
		children[child] = true
	}
	for k, v := range nodes {
		if _, ok := children[k]; !ok {
			return v
		}
	}
	return nil
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function createBinaryTree(descriptions: number[][]): TreeNode | null {
    const nodes: Record<number, TreeNode> = {};
    const children = new Set<number>();
    for (const [parent, child, isLeft] of descriptions) {
        if (!nodes[parent]) {
            nodes[parent] = new TreeNode(parent);
        }
        if (!nodes[child]) {
            nodes[child] = new TreeNode(child);
        }
        if (isLeft) {
            nodes[parent].left = nodes[child];
        } else {
            nodes[parent].right = nodes[child];
        }
        children.add(child);
    }
    for (const [k, v] of Object.entries(nodes)) {
        if (!children.has(+k)) {
            return v;
        }
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::{HashMap, HashSet};
use std::rc::Rc;
impl Solution {
    pub fn create_binary_tree(descriptions: Vec<Vec<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut nodes = HashMap::new();
        let mut children = HashSet::new();

        for d in descriptions {
            let parent = d[0];
            let child = d[1];
            let is_left = d[2];

            nodes
                .entry(parent)
                .or_insert_with(|| Rc::new(RefCell::new(TreeNode::new(parent))));
            nodes
                .entry(child)
                .or_insert_with(|| Rc::new(RefCell::new(TreeNode::new(child))));

            if is_left == 1 {
                nodes.get(&parent).unwrap().borrow_mut().left =
                    Some(Rc::clone(nodes.get(&child).unwrap()));
            } else {
                nodes.get(&parent).unwrap().borrow_mut().right =
                    Some(Rc::clone(nodes.get(&child).unwrap()));
            }

            children.insert(child);
        }

        for (key, node) in &nodes {
            if !children.contains(key) {
                return Some(Rc::clone(node));
            }
        }

        None
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function (descriptions) {
    const nodes = {};
    const children = new Set();
    for (const [parent, child, isLeft] of descriptions) {
        if (!nodes[parent]) {
            nodes[parent] = new TreeNode(parent);
        }
        if (!nodes[child]) {
            nodes[child] = new TreeNode(child);
        }
        if (isLeft) {
            nodes[parent].left = nodes[child];
        } else {
            nodes[parent].right = nodes[child];
        }
        children.add(child);
    }
    for (const [k, v] of Object.entries(nodes)) {
        if (!children.has(+k)) {
            return v;
        }
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个二维整数数组 <code>descriptions</code> ，其中 <code>descriptions[i] = [parent<sub>i</sub>, child<sub>i</sub>, isLeft<sub>i</sub>]</code> 表示 <code>parent<sub>i</sub></code> 是 <code>child<sub>i</sub></code> 在 <strong>二叉树</strong> 中的 <strong>父节点</strong>，二叉树中各节点的值 <strong>互不相同</strong> 。此外：</p>

<ul>
	<li>如果 <code>isLeft<sub>i</sub> == 1</code> ，那么 <code>child<sub>i</sub></code> 就是 <code>parent<sub>i</sub></code> 的左子节点。</li>
	<li>如果 <code>isLeft<sub>i</sub> == 0</code> ，那么 <code>child<sub>i</sub></code> 就是 <code>parent<sub>i</sub></code> 的右子节点。</li>
</ul>

<p>请你根据 <code>descriptions</code> 的描述来构造二叉树并返回其 <strong>根节点</strong> 。</p>

<p>测试用例会保证可以构造出 <strong>有效</strong> 的二叉树。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2196.Create%20Binary%20Tree%20From%20Descriptions/images/example1drawio.png" style="width: 300px; height: 236px;" /></p>

<pre>
<strong>输入：</strong>descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
<strong>输出：</strong>[50,20,80,15,17,19]
<strong>解释：</strong>根节点是值为 50 的节点，因为它没有父节点。
结果二叉树如上图所示。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/2100-2199/2196.Create%20Binary%20Tree%20From%20Descriptions/images/example2drawio.png" style="width: 131px; height: 300px;" /></p>

<pre>
<strong>输入：</strong>descriptions = [[1,2,1],[2,3,0],[3,4,1]]
<strong>输出：</strong>[1,2,null,null,3,4]
<strong>解释：</strong>根节点是值为 1 的节点，因为它没有父节点。 
结果二叉树如上图所示。 </pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= descriptions.length &lt;= 10<sup>4</sup></code></li>
	<li><code>descriptions[i].length == 3</code></li>
	<li><code>1 &lt;= parent<sub>i</sub>, child<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= isLeft<sub>i</sub> &lt;= 1</code></li>
	<li><code>descriptions</code> 所描述的二叉树是一棵有效二叉树</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以用一个哈希表 $\textit{nodes}$ 来存储所有节点，其中键为节点的值，值为节点本身，用一个集合 $\textit{children}$ 来存储所有的子节点。

遍历 $\textit{descriptions}$，对于每个描述 $[\textit{parent}, \textit{child}, \textit{isLeft}]$，如果 $\textit{parent}$ 不在 $\textit{nodes}$ 中，我们就将 $\textit{parent}$ 加入 $\textit{nodes}$，并初始化一个值为 $\textit{parent}$ 的节点。如果 $\textit{child}$ 不在 $\textit{nodes}$ 中，我们就将 $\textit{child}$ 加入 $\textit{nodes}$，并初始化一个值为 $\textit{child}$ 的节点。然后我们将 $\textit{child}$ 加入 $\textit{children}$。

如果 $\textit{isLeft}$ 为真，我们就将 $\textit{child}$ 作为 $\textit{parent}$ 的左子节点，否则我们就将 $\textit{child}$ 作为 $\textit{parent}$ 的右子节点。

最后，我们遍历 $\textit{nodes}$，如果某个节点的值不在 $\textit{children}$ 中，那么这个节点就是根节点，我们返回这个节点。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是 $\textit{descriptions}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes = defaultdict(TreeNode)
        children = set()
        for parent, child, isLeft in descriptions:
            if parent not in nodes:
                nodes[parent] = TreeNode(parent)
            if child not in nodes:
                nodes[child] = TreeNode(child)
            children.add(child)
            if isLeft:
                nodes[parent].left = nodes[child]
            else:
                nodes[parent].right = nodes[child]
        root = (set(nodes.keys()) - children).pop()
        return nodes[root]
```

#### Java

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> nodes = new HashMap<>();
        Set<Integer> children = new HashSet<>();
        for (var d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (!nodes.containsKey(parent)) {
                nodes.put(parent, new TreeNode(parent));
            }
            if (!nodes.containsKey(child)) {
                nodes.put(child, new TreeNode(child));
            }
            if (isLeft == 1) {
                nodes.get(parent).left = nodes.get(child);
            } else {
                nodes.get(parent).right = nodes.get(child);
            }
            children.add(child);
        }
        for (var e : nodes.entrySet()) {
            if (!children.contains(e.getKey())) {
                return e.getValue();
            }
        }
        return null;
    }
}
```

#### C++

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (const auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (!nodes.contains(parent)) {
                nodes[parent] = new TreeNode(parent);
            }
            if (!nodes.contains(child)) {
                nodes[child] = new TreeNode(child);
            }
            if (isLeft) {
                nodes[parent]->left = nodes[child];
            } else {
                nodes[parent]->right = nodes[child];
            }
            children.insert(child);
        }
        for (const auto& [k, v] : nodes) {
            if (!children.contains(k)) {
                return v;
            }
        }
        return nullptr;
    }
};
```

#### Go

```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func createBinaryTree(descriptions [][]int) *TreeNode {
	nodes := map[int]*TreeNode{}
	children := map[int]bool{}
	for _, d := range descriptions {
		parent, child, isLeft := d[0], d[1], d[2]
		if _, ok := nodes[parent]; !ok {
			nodes[parent] = &TreeNode{Val: parent}
		}
		if _, ok := nodes[child]; !ok {
			nodes[child] = &TreeNode{Val: child}
		}
		if isLeft == 1 {
			nodes[parent].Left = nodes[child]
		} else {
			nodes[parent].Right = nodes[child]
		}
		children[child] = true
	}
	for k, v := range nodes {
		if _, ok := children[k]; !ok {
			return v
		}
	}
	return nil
}
```

#### TypeScript

```ts
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function createBinaryTree(descriptions: number[][]): TreeNode | null {
    const nodes: Record<number, TreeNode> = {};
    const children = new Set<number>();
    for (const [parent, child, isLeft] of descriptions) {
        if (!nodes[parent]) {
            nodes[parent] = new TreeNode(parent);
        }
        if (!nodes[child]) {
            nodes[child] = new TreeNode(child);
        }
        if (isLeft) {
            nodes[parent].left = nodes[child];
        } else {
            nodes[parent].right = nodes[child];
        }
        children.add(child);
    }
    for (const [k, v] of Object.entries(nodes)) {
        if (!children.has(+k)) {
            return v;
        }
    }
}
```

#### Rust

```rust
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::{HashMap, HashSet};
use std::rc::Rc;
impl Solution {
    pub fn create_binary_tree(descriptions: Vec<Vec<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut nodes = HashMap::new();
        let mut children = HashSet::new();

        for d in descriptions {
            let parent = d[0];
            let child = d[1];
            let is_left = d[2];

            nodes
                .entry(parent)
                .or_insert_with(|| Rc::new(RefCell::new(TreeNode::new(parent))));
            nodes
                .entry(child)
                .or_insert_with(|| Rc::new(RefCell::new(TreeNode::new(child))));

            if is_left == 1 {
                nodes.get(&parent).unwrap().borrow_mut().left =
                    Some(Rc::clone(nodes.get(&child).unwrap()));
            } else {
                nodes.get(&parent).unwrap().borrow_mut().right =
                    Some(Rc::clone(nodes.get(&child).unwrap()));
            }

            children.insert(child);
        }

        for (key, node) in &nodes {
            if !children.contains(key) {
                return Some(Rc::clone(node));
            }
        }

        None
    }
}
```

#### JavaScript

```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function (descriptions) {
    const nodes = {};
    const children = new Set();
    for (const [parent, child, isLeft] of descriptions) {
        if (!nodes[parent]) {
            nodes[parent] = new TreeNode(parent);
        }
        if (!nodes[child]) {
            nodes[child] = new TreeNode(child);
        }
        if (isLeft) {
            nodes[parent].left = nodes[child];
        } else {
            nodes[parent].right = nodes[child];
        }
        children.add(child);
    }
    for (const [k, v] of Object.entries(nodes)) {
        if (!children.has(+k)) {
            return v;
        }
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2197. 替换数组中的非互质数](https://leetcode.cn/problems/replace-non-coprime-numbers-in-array){#2197}

{{< tabs "2197" >}}

{{% tab "python" %}}
```python
class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stk = []
        for x in nums:
            stk.append(x)
            while len(stk) > 1:
                x, y = stk[-2:]
                g = gcd(x, y)
                if g == 1:
                    break
                stk.pop()
                stk[-1] = x * y // g
        return stk
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> stk = new ArrayList<>();
        for (int x : nums) {
            stk.add(x);
            while (stk.size() > 1) {
                x = stk.get(stk.size() - 1);
                int y = stk.get(stk.size() - 2);
                int g = gcd(x, y);
                if (g == 1) {
                    break;
                }
                stk.remove(stk.size() - 1);
                stk.set(stk.size() - 1, (int) ((long) x * y / g));
            }
        }
        return stk;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;
        for (int x : nums) {
            stk.push_back(x);
            while (stk.size() > 1) {
                x = stk.back();
                int y = stk[stk.size() - 2];
                int g = __gcd(x, y);
                if (g == 1) {
                    break;
                }
                stk.pop_back();
                stk.back() = 1LL * x * y / g;
            }
        }
        return stk;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func replaceNonCoprimes(nums []int) []int {
	stk := []int{}
	for _, x := range nums {
		stk = append(stk, x)
		for len(stk) > 1 {
			x = stk[len(stk)-1]
			y := stk[len(stk)-2]
			g := gcd(x, y)
			if g == 1 {
				break
			}
			stk = stk[:len(stk)-1]
			stk[len(stk)-1] = x * y / g
		}
	}
	return stk
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function replaceNonCoprimes(nums: number[]): number[] {
    const gcd = (a: number, b: number): number => {
        if (b === 0) {
            return a;
        }
        return gcd(b, a % b);
    };
    const stk: number[] = [];
    for (let x of nums) {
        stk.push(x);
        while (stk.length > 1) {
            x = stk.at(-1)!;
            const y = stk.at(-2)!;
            const g = gcd(x, y);
            if (g === 1) {
                break;
            }
            stk.pop();
            stk.pop();
            stk.push(((x * y) / g) | 0);
        }
    }
    return stk;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 。请你对数组执行下述操作：</p>

<ol>
	<li>从 <code>nums</code> 中找出 <strong>任意</strong> 两个 <strong>相邻</strong> 的 <strong>非互质</strong> 数。</li>
	<li>如果不存在这样的数，<strong>终止</strong> 这一过程。</li>
	<li>否则，删除这两个数，并 <strong>替换</strong> 为它们的 <strong>最小公倍数</strong>（Least Common Multiple，LCM）。</li>
	<li>只要还能找出两个相邻的非互质数就继续 <strong>重复</strong> 这一过程。</li>
</ol>

<p>返回修改后得到的 <strong>最终</strong> 数组。可以证明的是，以 <strong>任意</strong> 顺序替换相邻的非互质数都可以得到相同的结果。</p>

<p>生成的测试用例可以保证最终数组中的值 <strong>小于或者等于</strong> <code>10<sup>8</sup></code> 。</p>

<p>两个数字 <code>x</code> 和 <code>y</code> 满足 <strong>非互质数</strong> 的条件是：<code>GCD(x, y) &gt; 1</code> ，其中 <code>GCD(x, y)</code> 是 <code>x</code> 和 <code>y</code> 的 <strong>最大公约数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1 ：</strong></p>

<pre>
<strong>输入：</strong>nums = [6,4,3,2,7,6,2]
<strong>输出：</strong>[12,7,6]
<strong>解释：</strong>
- (6, 4) 是一组非互质数，且 LCM(6, 4) = 12 。得到 nums = [<em><strong>12</strong></em>,3,2,7,6,2] 。
- (12, 3) 是一组非互质数，且 LCM(12, 3) = 12 。得到 nums = [<em><strong>12</strong></em>,2,7,6,2] 。
- (12, 2) 是一组非互质数，且 LCM(12, 2) = 12 。得到 nums = [<em><strong>12</strong></em>,7,6,2] 。
- (6, 2) 是一组非互质数，且 LCM(6, 2) = 6 。得到 nums = [12,7,<em><strong>6</strong></em>] 。
现在，nums 中不存在相邻的非互质数。
因此，修改后得到的最终数组是 [12,7,6] 。
注意，存在其他方法可以获得相同的最终数组。
</pre>

<p><strong>示例 2 ：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,2,1,1,3,3,3]
<strong>输出：</strong>[2,1,1,3]
<strong>解释：</strong>
- (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,<em><strong>3</strong></em>,3] 。
- (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,<em><strong>3</strong></em>] 。
- (2, 2) 是一组非互质数，且 LCM(2, 2) = 2 。得到 nums = [<em><strong>2</strong></em>,1,1,3] 。
现在，nums 中不存在相邻的非互质数。 
因此，修改后得到的最终数组是 [2,1,1,3] 。 
注意，存在其他方法可以获得相同的最终数组。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li>生成的测试用例可以保证最终数组中的值 <strong>小于或者等于</strong> <code>10<sup>8</sup></code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：栈

如果存在三个相邻的数 $x$, $y$, $z$ 可以进行合并，那么我们先合并 $x$ 和 $y$，再合并 $z$ 的结果，与先合并 $y$ 和 $z$，再合并 $x$ 的结果是一样的，结果均为 $\textit{LCM}(x, y, z)$。

因此，我们可以总是优先合并左侧相邻的数，再将合并后的结果与右侧相邻的数进行合并。

我们使用一个栈来模拟这个过程，遍历数组，对于每个数，我们将其入栈，然后不断检查栈顶的两个数是否互质，如果不互质，我们将这两个数出栈，然后将它们的最小公倍数入栈，直到栈顶的两个数互质，或者栈中元素小于两个。

最后栈中的元素即为最终结果。

时间复杂度 $O(n \times \log M)$，空间复杂度 $O(n)$。其中 $M$ 为数组中的最大值。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stk = []
        for x in nums:
            stk.append(x)
            while len(stk) > 1:
                x, y = stk[-2:]
                g = gcd(x, y)
                if g == 1:
                    break
                stk.pop()
                stk[-1] = x * y // g
        return stk
```

#### Java

```java
class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> stk = new ArrayList<>();
        for (int x : nums) {
            stk.add(x);
            while (stk.size() > 1) {
                x = stk.get(stk.size() - 1);
                int y = stk.get(stk.size() - 2);
                int g = gcd(x, y);
                if (g == 1) {
                    break;
                }
                stk.remove(stk.size() - 1);
                stk.set(stk.size() - 1, (int) ((long) x * y / g));
            }
        }
        return stk;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;
        for (int x : nums) {
            stk.push_back(x);
            while (stk.size() > 1) {
                x = stk.back();
                int y = stk[stk.size() - 2];
                int g = __gcd(x, y);
                if (g == 1) {
                    break;
                }
                stk.pop_back();
                stk.back() = 1LL * x * y / g;
            }
        }
        return stk;
    }
};
```

#### Go

```go
func replaceNonCoprimes(nums []int) []int {
	stk := []int{}
	for _, x := range nums {
		stk = append(stk, x)
		for len(stk) > 1 {
			x = stk[len(stk)-1]
			y := stk[len(stk)-2]
			g := gcd(x, y)
			if g == 1 {
				break
			}
			stk = stk[:len(stk)-1]
			stk[len(stk)-1] = x * y / g
		}
	}
	return stk
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
```

#### TypeScript

```ts
function replaceNonCoprimes(nums: number[]): number[] {
    const gcd = (a: number, b: number): number => {
        if (b === 0) {
            return a;
        }
        return gcd(b, a % b);
    };
    const stk: number[] = [];
    for (let x of nums) {
        stk.push(x);
        while (stk.length > 1) {
            x = stk.at(-1)!;
            const y = stk.at(-2)!;
            const g = gcd(x, y);
            if (g === 1) {
                break;
            }
            stk.pop();
            stk.pop();
            stk.push(((x * y) / g) | 0);
        }
    }
    return stk;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2198. 单因数三元组 🔒](https://leetcode.cn/problems/number-of-single-divisor-triplets){#2198}

{{< tabs "2198" >}}

{{% tab "python" %}}
```python
class Solution:
    def singleDivisorTriplet(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        ans = 0
        for a, x in cnt.items():
            for b, y in cnt.items():
                for c, z in cnt.items():
                    s = a + b + c
                    if sum(s % v == 0 for v in (a, b, c)) == 1:
                        if a == b:
                            ans += x * (x - 1) * z
                        elif a == c:
                            ans += x * (x - 1) * y
                        elif b == c:
                            ans += x * y * (y - 1)
                        else:
                            ans += x * y * z
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long singleDivisorTriplet(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            ++cnt[x];
        }
        long ans = 0;
        for (int a = 1; a <= 100; ++a) {
            for (int b = 1; b <= 100; ++b) {
                for (int c = 1; c <= 100; ++c) {
                    int s = a + b + c;
                    int x = cnt[a], y = cnt[b], z = cnt[c];
                    int t = 0;
                    t += s % a == 0 ? 1 : 0;
                    t += s % b == 0 ? 1 : 0;
                    t += s % c == 0 ? 1 : 0;
                    if (t == 1) {
                        if (a == b) {
                            ans += 1L * x * (x - 1) * z;
                        } else if (a == c) {
                            ans += 1L * x * (x - 1) * y;
                        } else if (b == c) {
                            ans += 1L * x * y * (y - 1);
                        } else {
                            ans += 1L * x * y * z;
                        }
                    }
                }
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
    long long singleDivisorTriplet(vector<int>& nums) {
        int cnt[101]{};
        for (int x : nums) {
            ++cnt[x];
        }
        long long ans = 0;
        for (int a = 1; a <= 100; ++a) {
            for (int b = 1; b <= 100; ++b) {
                for (int c = 1; c <= 100; ++c) {
                    int s = a + b + c;
                    int x = cnt[a], y = cnt[b], z = cnt[c];
                    int t = (s % a == 0) + (s % b == 0) + (s % c == 0);
                    if (t == 1) {
                        if (a == b) {
                            ans += 1LL * x * (x - 1) * z;
                        } else if (a == c) {
                            ans += 1LL * x * (x - 1) * y;
                        } else if (b == c) {
                            ans += 1LL * x * y * (y - 1);
                        } else {
                            ans += 1LL * x * y * z;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func singleDivisorTriplet(nums []int) (ans int64) {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
	}
	f := func(a, b int) int {
		if a%b == 0 {
			return 1
		}
		return 0
	}
	for a := 1; a <= 100; a++ {
		for b := 1; b <= 100; b++ {
			for c := 1; c <= 100; c++ {
				s := a + b + c
				t := f(s, a) + f(s, b) + f(s, c)
				if t == 1 {
					if a == b {
						ans += int64(cnt[a] * (cnt[a] - 1) * cnt[c])
					} else if a == c {
						ans += int64(cnt[a] * (cnt[a] - 1) * cnt[b])
					} else if b == c {
						ans += int64(cnt[b] * (cnt[b] - 1) * cnt[a])
					} else {
						ans += int64(cnt[a] * cnt[b] * cnt[c])
					}
				}
			}
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function singleDivisorTriplet(nums: number[]): number {
    const cnt: number[] = Array(101).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    let ans = 0;
    const f = (a: number, b: number) => (a % b === 0 ? 1 : 0);
    for (let a = 1; a <= 100; ++a) {
        for (let b = 1; b <= 100; ++b) {
            for (let c = 1; c <= 100; ++c) {
                const s = a + b + c;
                const t = f(s, a) + f(s, b) + f(s, c);
                if (t === 1) {
                    if (a === b) {
                        ans += cnt[a] * (cnt[a] - 1) * cnt[c];
                    } else if (a === c) {
                        ans += cnt[a] * (cnt[a] - 1) * cnt[b];
                    } else if (b === c) {
                        ans += cnt[b] * (cnt[b] - 1) * cnt[a];
                    } else {
                        ans += cnt[a] * cnt[b] * cnt[c];
                    }
                }
            }
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

<p>给定一个下标从 <strong>0</strong> 开始的正整数数组 <code>nums</code>。由三个&nbsp;<strong>不同&nbsp;</strong>索引&nbsp;<code>(i, j, k)</code> 组成的三元组，如果 <code>nums[i] + nums[j] + nums[k]</code> 能被 <code>nums[i]</code>、<code>nums[j]</code>&nbsp;或 <code>nums[k]</code> 中的&nbsp;<strong>一个&nbsp;</strong>整除，则称为 <code>nums</code> 的&nbsp;<strong>单因数三元组</strong>。</p>

<p>返回 <em><code>nums</code> 的单因数三元组</em>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> nums = [4,6,7,3,2]
<strong>输出:</strong> 12
<strong>解释:
</strong>三元组索引 (0, 3, 4), (0, 4, 3), (3, 0, 4), (3, 4, 0), (4, 0, 3), 和 (4, 3, 0) 的值为 [4, 3, 2] (或者说排列为 [4, 3, 2]).
4 + 3 + 2 = 9 只能被 3 整除，所以所有的三元组都是单因数三元组。
三元组索引 (0, 2, 3), (0, 3, 2), (2, 0, 3), (2, 3, 0), (3, 0, 2), 和 (3, 2, 0) 的值为 [4, 7, 3]  (或者说排列为 [4, 7, 3]).
4 + 7 + 3 = 14 只能被 7 整除，所以所有的三元组都是单因数三元组。
一共有 12 个单因数三元组。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,2,2]
<strong>输出:</strong> 6
<strong>提示:</strong>
三元组索引 (0, 1, 2), (0, 2, 1), (1, 0, 2), (1, 2, 0), (2, 0, 1), 和 (2, 1, 0) 的值为 [1, 2, 2] (或者说排列为 [1, 2, 2]).
1 + 2 + 2 = 5 只能被 1 整除，所以所有的三元组都是单因数三元组。
一共有6个单因数三元组。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> nums = [1,1,1]
<strong>输出:</strong> 0
<strong>提示:</strong>
没有单因数三元组。
注意 (0, 1, 2) 不是单因数三元组。 因为 nums[0] + nums[1] + nums[2] = 3，3 可以被 nums[0], nums[1], nums[2] 整除。
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数 + 枚举

我们注意到，数组 $\textit{nums}$ 的元素的范围是 $[1, 100]$，因此我们可以枚举三个数 $a, b, c$，其中 $a, b, c \in [1, 100]$，然后判断 $a + b + c$ 是否只能被 $a, b, c$ 中的一个数整除。如果是，则我们可以计算出以 $a, b, c$ 为元素的单因数三元组的个数。具体计算方法如下：

-   如果 $a = b$，那么以 $a, b, c$ 为元素的单因数三元组的个数为 $x \times (x - 1) \times z$，其中 $x$, $y$, $z$ 分别表示 $a$, $b$, $c$ 在数组 $\textit{nums}$ 中出现的次数。
-   如果 $a = c$，那么以 $a, b, c$ 为元素的单因数三元组的个数为 $x \times (x - 1) \times y$。
-   如果 $b = c$，那么以 $a, b, c$ 为元素的单因数三元组的个数为 $x \times y \times (y - 1)$。
-   如果 $a, b, c$ 互不相等，那么以 $a, b, c$ 为元素的单因数三元组的个数为 $x \times y \times z$。

最后，我们将所有的单因数三元组的个数相加即可。

时间复杂度 $O(M^3)$，空间复杂度 $O(M)$。其中 $M$ 为数组 $\textit{nums}$ 中元素的取值范围。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def singleDivisorTriplet(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        ans = 0
        for a, x in cnt.items():
            for b, y in cnt.items():
                for c, z in cnt.items():
                    s = a + b + c
                    if sum(s % v == 0 for v in (a, b, c)) == 1:
                        if a == b:
                            ans += x * (x - 1) * z
                        elif a == c:
                            ans += x * (x - 1) * y
                        elif b == c:
                            ans += x * y * (y - 1)
                        else:
                            ans += x * y * z
        return ans
```

#### Java

```java
class Solution {
    public long singleDivisorTriplet(int[] nums) {
        int[] cnt = new int[101];
        for (int x : nums) {
            ++cnt[x];
        }
        long ans = 0;
        for (int a = 1; a <= 100; ++a) {
            for (int b = 1; b <= 100; ++b) {
                for (int c = 1; c <= 100; ++c) {
                    int s = a + b + c;
                    int x = cnt[a], y = cnt[b], z = cnt[c];
                    int t = 0;
                    t += s % a == 0 ? 1 : 0;
                    t += s % b == 0 ? 1 : 0;
                    t += s % c == 0 ? 1 : 0;
                    if (t == 1) {
                        if (a == b) {
                            ans += 1L * x * (x - 1) * z;
                        } else if (a == c) {
                            ans += 1L * x * (x - 1) * y;
                        } else if (b == c) {
                            ans += 1L * x * y * (y - 1);
                        } else {
                            ans += 1L * x * y * z;
                        }
                    }
                }
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
    long long singleDivisorTriplet(vector<int>& nums) {
        int cnt[101]{};
        for (int x : nums) {
            ++cnt[x];
        }
        long long ans = 0;
        for (int a = 1; a <= 100; ++a) {
            for (int b = 1; b <= 100; ++b) {
                for (int c = 1; c <= 100; ++c) {
                    int s = a + b + c;
                    int x = cnt[a], y = cnt[b], z = cnt[c];
                    int t = (s % a == 0) + (s % b == 0) + (s % c == 0);
                    if (t == 1) {
                        if (a == b) {
                            ans += 1LL * x * (x - 1) * z;
                        } else if (a == c) {
                            ans += 1LL * x * (x - 1) * y;
                        } else if (b == c) {
                            ans += 1LL * x * y * (y - 1);
                        } else {
                            ans += 1LL * x * y * z;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func singleDivisorTriplet(nums []int) (ans int64) {
	cnt := [101]int{}
	for _, x := range nums {
		cnt[x]++
	}
	f := func(a, b int) int {
		if a%b == 0 {
			return 1
		}
		return 0
	}
	for a := 1; a <= 100; a++ {
		for b := 1; b <= 100; b++ {
			for c := 1; c <= 100; c++ {
				s := a + b + c
				t := f(s, a) + f(s, b) + f(s, c)
				if t == 1 {
					if a == b {
						ans += int64(cnt[a] * (cnt[a] - 1) * cnt[c])
					} else if a == c {
						ans += int64(cnt[a] * (cnt[a] - 1) * cnt[b])
					} else if b == c {
						ans += int64(cnt[b] * (cnt[b] - 1) * cnt[a])
					} else {
						ans += int64(cnt[a] * cnt[b] * cnt[c])
					}
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function singleDivisorTriplet(nums: number[]): number {
    const cnt: number[] = Array(101).fill(0);
    for (const x of nums) {
        ++cnt[x];
    }
    let ans = 0;
    const f = (a: number, b: number) => (a % b === 0 ? 1 : 0);
    for (let a = 1; a <= 100; ++a) {
        for (let b = 1; b <= 100; ++b) {
            for (let c = 1; c <= 100; ++c) {
                const s = a + b + c;
                const t = f(s, a) + f(s, b) + f(s, c);
                if (t === 1) {
                    if (a === b) {
                        ans += cnt[a] * (cnt[a] - 1) * cnt[c];
                    } else if (a === c) {
                        ans += cnt[a] * (cnt[a] - 1) * cnt[b];
                    } else if (b === c) {
                        ans += cnt[b] * (cnt[b] - 1) * cnt[a];
                    } else {
                        ans += cnt[a] * cnt[b] * cnt[c];
                    }
                }
            }
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

# [2199. 找到每篇文章的主题 🔒](https://leetcode.cn/problems/finding-the-topic-of-each-post){#2199}

{{< tabs "2199" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    post_id,
    IFNULL(GROUP_CONCAT(DISTINCT topic_id), 'Ambiguous!') AS topic
FROM
    Posts
    LEFT JOIN Keywords ON INSTR(CONCAT(' ', content, ' '), CONCAT(' ', word, ' ')) > 0
GROUP BY post_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Keywords</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| topic_id    | int     |
| word        | varchar |
+-------------+---------+
(topic_id, word) 是该表的主键（具有唯一值的列的组合）。
该表的每一行都包含一个主题的 id 和一个用于表达该主题的词。
可以用多个词来表达同一个主题，也可以用一个词来表达多个主题。
</pre>

<p>&nbsp;</p>

<p>表: <code>Posts</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| post_id     | int     |
| content     | varchar |
+-------------+---------+
post_id 是该表的主键（具有唯一值的列）。
该表的每一行都包含一个帖子的 ID 及其内容。
内容仅由英文字母和空格组成。
</pre>

<p>&nbsp;</p>

<p>Leetcode 从其社交媒体网站上收集了一些帖子，并对每个帖子的主题感兴趣。每个主题可以由一个或多个关键字表示。如果某个主题的关键字存在于一个帖子的内容中 (不区分大小写)，那么这个帖子就有这个主题。</p>

<p>编写解决方案，根据以下规则查找每篇文章的主题:</p>

<ul>
	<li>如果帖子没有来自任何主题的关键词，那么它的主题应该是&nbsp;<code>"Ambiguous!"</code>。</li>
	<li>如果该帖子至少有一个主题的关键字，其主题应该是其主题的 id 按升序排列并以逗号 '，' 分隔的字符串。字符串不应该包含重复的 id。</li>
</ul>

<p>以&nbsp;<strong>任意顺序&nbsp;</strong>返回结果表。</p>

<p>结果格式如下所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> 
Keywords 表:
+----------+----------+
| topic_id | word     |
+----------+----------+
| 1        | handball |
| 1        | football |
| 3        | WAR      |
| 2        | Vaccine  |
+----------+----------+
Posts 表:
+---------+------------------------------------------------------------------------+
| post_id | content                                                                |
+---------+------------------------------------------------------------------------+
| 1       | We call it soccer They call it football hahaha                         |
| 2       | Americans prefer basketball while Europeans love handball and football |
| 3       | stop the war and play handball                                         |
| 4       | warning I planted some flowers this morning and then got vaccinated    |
+---------+------------------------------------------------------------------------+
<strong>输出:</strong> 
+---------+------------+
| post_id | topic      |
+---------+------------+
| 1       | 1          |
| 2       | 1          |
| 3       | 1,3        |
| 4       | Ambiguous! |
+---------+------------+
<strong>解释:</strong> 
1: "We call it soccer They call it football hahaha"
"football" 表示主题 1。没有其他词能表示任何其他主题。

2: "Americans prefer basketball while Europeans love handball and football"
"handball" 表示主题 1。"football" 表示主题 1。
没有其他词能表示任何其他主题。

3: "stop the war and play handball"
"war" 表示主题 3。 "handball" 表示主题 1。
没有其他词能表示任何其他主题。

4: "warning I planted some flowers this morning and then got vaccinated"
这个句子里没有一个词能表示任何主题。注意 “warning” 和 “war” 不同，尽管它们有一个共同的前缀。
所以这篇文章 “Ambiguous!”
请注意，可以使用一个词来表达多个主题。</pre>

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
SELECT
    post_id,
    IFNULL(GROUP_CONCAT(DISTINCT topic_id), 'Ambiguous!') AS topic
FROM
    Posts
    LEFT JOIN Keywords ON INSTR(CONCAT(' ', content, ' '), CONCAT(' ', word, ' ')) > 0
GROUP BY post_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
