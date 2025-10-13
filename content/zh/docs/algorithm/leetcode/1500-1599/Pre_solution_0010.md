---
title: "1590_使数组和能被 P 整除"
date: 2025-10-08T18:37:33+08:00
weight: 10
tags: [二叉树, 位运算, 前缀和, 动态规划, 哈希表, 回溯, 图, 字符串, 拓扑排序, 数据库, 数组, 栈, 树, 模拟, 状态压缩, 矩阵]
---

{{< markmap >}}
### [1590_使数组和能被 P 整除](#1590)
#### [数组](#1590)
#### [哈希表](#1590)
#### [前缀和](#1590)
### [1591_奇怪的打印机 II](#1591)
#### [图](#1591)
#### [拓扑排序](#1591)
#### [数组](#1591)
#### [矩阵](#1591)
### [1592_重新排列单词间的空格](#1592)
#### [字符串](#1592)
### [1593_拆分字符串使唯一子字符串的数目最大](#1593)
#### [哈希表](#1593)
#### [字符串](#1593)
#### [回溯](#1593)
### [1594_矩阵的最大非负积](#1594)
#### [数组](#1594)
#### [动态规划](#1594)
#### [矩阵](#1594)
### [1595_连通两组点的最小成本](#1595)
#### [位运算](#1595)
#### [数组](#1595)
#### [动态规划](#1595)
#### [状态压缩](#1595)
#### [矩阵](#1595)
### [1596_每位顾客最经常订购的商品 🔒](#1596)
#### [数据库](#1596)
### [1597_根据中缀表达式构造二叉表达式树 🔒](#1597)
#### [栈](#1597)
#### [树](#1597)
#### [字符串](#1597)
#### [二叉树](#1597)
### [1598_文件夹操作日志搜集器](#1598)
#### [栈](#1598)
#### [数组](#1598)
#### [字符串](#1598)
### [1599_经营摩天轮的最大利润](#1599)
#### [数组](#1599)
#### [模拟](#1599)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1590_使数组和能被 P 整除
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 1591_奇怪的打印机 II
___
#### 图
___
#### 拓扑排序
___
#### 数组
___
#### 矩阵
---
### 1592_重新排列单词间的空格
___
#### 字符串
---
### 1593_拆分字符串使唯一子字符串的数目最大
___
#### 哈希表
___
#### 字符串
___
#### 回溯
---
### 1594_矩阵的最大非负积
___
#### 数组
___
#### 动态规划
___
#### 矩阵
---
### 1595_连通两组点的最小成本
___
#### 位运算
___
#### 数组
___
#### 动态规划
___
#### 状态压缩
___
#### 矩阵
---
### 1596_每位顾客最经常订购的商品 🔒
___
#### 数据库
---
### 1597_根据中缀表达式构造二叉表达式树 🔒
___
#### 栈
___
#### 树
___
#### 字符串
___
#### 二叉树
---
### 1598_文件夹操作日志搜集器
___
#### 栈
___
#### 数组
___
#### 字符串
---
### 1599_经营摩天轮的最大利润
___
#### 数组
___
#### 模拟
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二叉树 | 位运算 | 前缀和 |
| 动态规划 | 哈希表 | 回溯 |
| 图 | 字符串 | 拓扑排序 |
| 数据库 | 数组 | 栈 |
| 树 | 模拟 | 状态压缩 |
| 矩阵 |  |  |

# [1590. 使数组和能被 P 整除](https://leetcode.cn/problems/make-sum-divisible-by-p){#1590}

{{< tabs "1590" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        k = sum(nums) % p
        if k == 0:
            return 0
        last = {0: -1}
        cur = 0
        ans = len(nums)
        for i, x in enumerate(nums):
            cur = (cur + x) % p
            target = (cur - k + p) % p
            if target in last:
                ans = min(ans, i - last[target])
            last[cur] = i
        return -1 if ans == len(nums) else ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSubarray(int[] nums, int p) {
        int k = 0;
        for (int x : nums) {
            k = (k + x) % p;
        }
        if (k == 0) {
            return 0;
        }
        Map<Integer, Integer> last = new HashMap<>();
        last.put(0, -1);
        int n = nums.length;
        int ans = n;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            int target = (cur - k + p) % p;
            if (last.containsKey(target)) {
                ans = Math.min(ans, i - last.get(target));
            }
            last.put(cur, i);
        }
        return ans == n ? -1 : ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int k = 0;
        for (int& x : nums) {
            k = (k + x) % p;
        }
        if (k == 0) {
            return 0;
        }
        unordered_map<int, int> last;
        last[0] = -1;
        int n = nums.size();
        int ans = n;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            int target = (cur - k + p) % p;
            if (last.count(target)) {
                ans = min(ans, i - last[target]);
            }
            last[cur] = i;
        }
        return ans == n ? -1 : ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSubarray(nums []int, p int) int {
	k := 0
	for _, x := range nums {
		k = (k + x) % p
	}
	if k == 0 {
		return 0
	}
	last := map[int]int{0: -1}
	n := len(nums)
	ans := n
	cur := 0
	for i, x := range nums {
		cur = (cur + x) % p
		target := (cur - k + p) % p
		if j, ok := last[target]; ok {
			ans = min(ans, i-j)
		}
		last[cur] = i
	}
	if ans == n {
		return -1
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSubarray(nums: number[], p: number): number {
    let k = 0;
    for (const x of nums) {
        k = (k + x) % p;
    }
    if (k === 0) {
        return 0;
    }
    const last = new Map<number, number>();
    last.set(0, -1);
    const n = nums.length;
    let ans = n;
    let cur = 0;
    for (let i = 0; i < n; ++i) {
        cur = (cur + nums[i]) % p;
        const target = (cur - k + p) % p;
        if (last.has(target)) {
            const j = last.get(target)!;
            ans = Math.min(ans, i - j);
        }
        last.set(cur, i);
    }
    return ans === n ? -1 : ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let mut k = 0;
        for &x in &nums {
            k = (k + x) % p;
        }
        if k == 0 {
            return 0;
        }

        let mut last = HashMap::new();
        last.insert(0, -1);
        let n = nums.len();
        let mut ans = n as i32;
        let mut cur = 0;

        for i in 0..n {
            cur = (cur + nums[i]) % p;
            let target = (cur - k + p) % p;
            if let Some(&prev_idx) = last.get(&target) {
                ans = ans.min(i as i32 - prev_idx);
            }
            last.insert(cur, i as i32);
        }

        if ans == n as i32 {
            -1
        } else {
            ans
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
var minSubarray = function (nums, p) {
    let k = 0;
    for (const x of nums) {
        k = (k + x) % p;
    }
    if (k === 0) {
        return 0;
    }
    const last = new Map();
    last.set(0, -1);
    const n = nums.length;
    let ans = n;
    let cur = 0;
    for (let i = 0; i < n; ++i) {
        cur = (cur + nums[i]) % p;
        const target = (cur - k + p) % p;
        if (last.has(target)) {
            const j = last.get(target);
            ans = Math.min(ans, i - j);
        }
        last.set(cur, i);
    }
    return ans === n ? -1 : ans;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个正整数数组&nbsp;<code>nums</code>，请你移除 <strong>最短</strong>&nbsp;子数组（可以为 <strong>空</strong>），使得剩余元素的 <strong>和</strong>&nbsp;能被 <code>p</code>&nbsp;整除。 <strong>不允许</strong>&nbsp;将整个数组都移除。</p>

<p>请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 <code>-1</code>&nbsp;。</p>

<p><strong>子数组</strong>&nbsp;定义为原数组中连续的一组元素。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>nums = [3,1,4,2], p = 6
<strong>输出：</strong>1
<strong>解释：</strong>nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>nums = [6,3,5,2], p = 9
<strong>输出：</strong>2
<strong>解释：</strong>我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
</pre>

<p><strong>示例&nbsp;3：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3], p = 3
<strong>输出：</strong>0
<strong>解释：</strong>和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
</pre>

<p><strong>示例&nbsp; 4：</strong></p>

<pre><strong>输入：</strong>nums = [1,2,3], p = 7
<strong>输出：</strong>-1
<strong>解释：</strong>没有任何方案使得移除子数组后剩余元素的和被 7 整除。
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>nums = [1000000000,1000000000,1000000000], p = 3
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= p &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 哈希表

我们可以先求出数组 $\textit{nums}$ 所有元素之和模 $p$ 的值，记为 $k$。如果 $k$ 为 $0$，说明数组 $\textit{nums}$ 所有元素之和就是 $p$ 的倍数，直接返回 $0$ 即可。

如果 $k$ 不为 $0$，我们需要找到一个最短的子数组，使得删除该子数组后，剩余元素之和模 $p$ 的值为 $0$。

我们可以遍历数组 $\textit{nums}$，维护当前的前缀和模 $p$ 的值，记为 $cur$。用哈希表 $last$ 记录每个前缀和模 $p$ 的值最后一次出现的位置。

如果当前存在一个以 $\textit{nums}[i]$ 结尾的子数组，使得删除该子数组后，剩余元素之和模 $p$ 的值为 $0$。也就是说，我们需要找到此前的一个前缀和模 $p$ 的值为 $target$ 的位置 $j$，使得 $(target + k - cur) \bmod p = 0$。如果找到，我们就可以将 $j + 1$ 到 $i$ 这一段闭区间子数组 $\textit{nums}[j+1,..i]$ 删除，使得剩余元素之和模 $p$ 的值为 $0$。

因此，如果存在一个 $target = (cur - k + p) \bmod p$，那么我们可以更新答案为 $\min(ans, i - j)$。接下来，我们更新 $last[cur]$ 的值为 $i$。继续遍历数组 $\textit{nums}$，直到遍历结束，即可得到答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        k = sum(nums) % p
        if k == 0:
            return 0
        last = {0: -1}
        cur = 0
        ans = len(nums)
        for i, x in enumerate(nums):
            cur = (cur + x) % p
            target = (cur - k + p) % p
            if target in last:
                ans = min(ans, i - last[target])
            last[cur] = i
        return -1 if ans == len(nums) else ans
```

#### Java

```java
class Solution {
    public int minSubarray(int[] nums, int p) {
        int k = 0;
        for (int x : nums) {
            k = (k + x) % p;
        }
        if (k == 0) {
            return 0;
        }
        Map<Integer, Integer> last = new HashMap<>();
        last.put(0, -1);
        int n = nums.length;
        int ans = n;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            int target = (cur - k + p) % p;
            if (last.containsKey(target)) {
                ans = Math.min(ans, i - last.get(target));
            }
            last.put(cur, i);
        }
        return ans == n ? -1 : ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int k = 0;
        for (int& x : nums) {
            k = (k + x) % p;
        }
        if (k == 0) {
            return 0;
        }
        unordered_map<int, int> last;
        last[0] = -1;
        int n = nums.size();
        int ans = n;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            int target = (cur - k + p) % p;
            if (last.count(target)) {
                ans = min(ans, i - last[target]);
            }
            last[cur] = i;
        }
        return ans == n ? -1 : ans;
    }
};
```

#### Go

```go
func minSubarray(nums []int, p int) int {
	k := 0
	for _, x := range nums {
		k = (k + x) % p
	}
	if k == 0 {
		return 0
	}
	last := map[int]int{0: -1}
	n := len(nums)
	ans := n
	cur := 0
	for i, x := range nums {
		cur = (cur + x) % p
		target := (cur - k + p) % p
		if j, ok := last[target]; ok {
			ans = min(ans, i-j)
		}
		last[cur] = i
	}
	if ans == n {
		return -1
	}
	return ans
}
```

#### TypeScript

```ts
function minSubarray(nums: number[], p: number): number {
    let k = 0;
    for (const x of nums) {
        k = (k + x) % p;
    }
    if (k === 0) {
        return 0;
    }
    const last = new Map<number, number>();
    last.set(0, -1);
    const n = nums.length;
    let ans = n;
    let cur = 0;
    for (let i = 0; i < n; ++i) {
        cur = (cur + nums[i]) % p;
        const target = (cur - k + p) % p;
        if (last.has(target)) {
            const j = last.get(target)!;
            ans = Math.min(ans, i - j);
        }
        last.set(cur, i);
    }
    return ans === n ? -1 : ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
        let mut k = 0;
        for &x in &nums {
            k = (k + x) % p;
        }
        if k == 0 {
            return 0;
        }

        let mut last = HashMap::new();
        last.insert(0, -1);
        let n = nums.len();
        let mut ans = n as i32;
        let mut cur = 0;

        for i in 0..n {
            cur = (cur + nums[i]) % p;
            let target = (cur - k + p) % p;
            if let Some(&prev_idx) = last.get(&target) {
                ans = ans.min(i as i32 - prev_idx);
            }
            last.insert(cur, i as i32);
        }

        if ans == n as i32 {
            -1
        } else {
            ans
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
var minSubarray = function (nums, p) {
    let k = 0;
    for (const x of nums) {
        k = (k + x) % p;
    }
    if (k === 0) {
        return 0;
    }
    const last = new Map();
    last.set(0, -1);
    const n = nums.length;
    let ans = n;
    let cur = 0;
    for (let i = 0; i < n; ++i) {
        cur = (cur + nums[i]) % p;
        const target = (cur - k + p) % p;
        if (last.has(target)) {
            const j = last.get(target);
            ans = Math.min(ans, i - j);
        }
        last.set(cur, i);
    }
    return ans === n ? -1 : ans;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1591. 奇怪的打印机 II](https://leetcode.cn/problems/strange-printer-ii){#1591}

{{< tabs "1591" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个奇怪的打印机，它有如下两个特殊的打印规则：</p>

<ul>
	<li>每一次操作时，打印机会用同一种颜色打印一个矩形的形状，每次打印会覆盖矩形对应格子里原本的颜色。</li>
	<li>一旦矩形根据上面的规则使用了一种颜色，那么 <strong>相同的颜色不能再被使用&nbsp;</strong>。</li>
</ul>

<p>给你一个初始没有颜色的&nbsp;<code>m x n</code>&nbsp;的矩形&nbsp;<code>targetGrid</code>&nbsp;，其中&nbsp;<code>targetGrid[row][col]</code>&nbsp;是位置&nbsp;<code>(row, col)</code>&nbsp;的颜色。</p>

<p>如果你能按照上述规则打印出矩形<em>&nbsp;</em><code>targetGrid</code>&nbsp;，请你返回&nbsp;<code>true</code>&nbsp;，否则返回&nbsp;<code>false</code>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1591.Strange%20Printer%20II/images/sample_1_1929.png" style="height: 138px; width: 483px;"></p>

<pre><strong>输入：</strong>targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1591.Strange%20Printer%20II/images/sample_2_1929.png" style="height: 290px; width: 483px;"></p>

<pre><strong>输入：</strong>targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
<strong>输出：</strong>false
<strong>解释：</strong>没有办法得到 targetGrid ，因为每一轮操作使用的颜色互不相同。</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>targetGrid = [[1,1,1],[3,1,3]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == targetGrid.length</code></li>
	<li><code>n == targetGrid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 60</code></li>
	<li><code>1 &lt;= targetGrid[row][col] &lt;= 60</code></li>
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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1592. 重新排列单词间的空格](https://leetcode.cn/problems/rearrange-spaces-between-words){#1592}

{{< tabs "1592" >}}

{{% tab "python" %}}
```python
class Solution:
    def reorderSpaces(self, text: str) -> str:
        spaces = text.count(" ")
        words = text.split()
        if len(words) == 1:
            return words[0] + " " * spaces
        cnt, mod = divmod(spaces, len(words) - 1)
        return (" " * cnt).join(words) + " " * mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String reorderSpaces(String text) {
        int spaces = 0;
        for (char c : text.toCharArray()) {
            if (c == ' ') {
                ++spaces;
            }
        }
        String[] words = text.trim().split("\\s+");
        if (words.length == 1) {
            return words[0] + " ".repeat(spaces);
        }
        int cnt = spaces / (words.length - 1);
        int mod = spaces % (words.length - 1);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; ++i) {
            sb.append(words[i]);
            if (i < words.length - 1) {
                sb.append(" ".repeat(cnt));
            }
        }
        sb.append(" ".repeat(mod));
        return sb.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = ranges::count(text, ' ');
        auto words = split(text);

        if (words.size() == 1) {
            return words[0] + string(spaces, ' ');
        }

        int cnt = spaces / (words.size() - 1);
        int mod = spaces % (words.size() - 1);

        string result = join(words, string(cnt, ' '));
        result += string(mod, ' ');

        return result;
    }

private:
    vector<string> split(const string& text) {
        vector<string> words;
        istringstream stream(text);
        string word;
        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }

    string join(const vector<string>& words, const string& separator) {
        ostringstream result;
        for (size_t i = 0; i < words.size(); ++i) {
            result << words[i];
            if (i < words.size() - 1) {
                result << separator;
            }
        }
        return result.str();
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func reorderSpaces(text string) string {
	cnt := strings.Count(text, " ")
	words := strings.Fields(text)
	m := len(words) - 1
	if m == 0 {
		return words[0] + strings.Repeat(" ", cnt)
	}
	return strings.Join(words, strings.Repeat(" ", cnt/m)) + strings.Repeat(" ", cnt%m)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function reorderSpaces(text: string): string {
    const spaces = (text.match(/ /g) || []).length;
    const words = text.split(/\s+/).filter(Boolean);
    if (words.length === 1) {
        return words[0] + ' '.repeat(spaces);
    }
    const cnt = Math.floor(spaces / (words.length - 1));
    const mod = spaces % (words.length - 1);
    const result = words.join(' '.repeat(cnt));
    return result + ' '.repeat(mod);
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn reorder_spaces(text: String) -> String {
        let spaces = text.chars().filter(|&c| c == ' ').count();
        let words: Vec<&str> = text.split_whitespace().collect();
        if words.len() == 1 {
            return format!("{}{}", words[0], " ".repeat(spaces));
        }
        let cnt = spaces / (words.len() - 1);
        let mod_spaces = spaces % (words.len() - 1);
        let result = words.join(&" ".repeat(cnt));
        result + &" ".repeat(mod_spaces)
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>text</code> ，该字符串由若干被空格包围的单词组成。每个单词由一个或者多个小写英文字母组成，并且两个单词之间至少存在一个空格。题目测试用例保证 <code>text</code> <strong>至少包含一个单词</strong> 。</p>

<p>请你重新排列空格，使每对相邻单词之间的空格数目都 <strong>相等</strong> ，并尽可能 <strong>最大化</strong> 该数目。如果不能重新平均分配所有空格，请 <strong>将多余的空格放置在字符串末尾</strong> ，这也意味着返回的字符串应当与原 <code>text</code> 字符串的长度相等。</p>

<p>返回 <strong>重新排列空格后的字符串</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = &quot;  this   is  a sentence &quot;
<strong>输出：</strong>&quot;this   is   a   sentence&quot;
<strong>解释：</strong>总共有 9 个空格和 4 个单词。可以将 9 个空格平均分配到相邻单词之间，相邻单词间空格数为：9 / (4-1) = 3 个。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = &quot; practice   makes   perfect&quot;
<strong>输出：</strong>&quot;practice   makes   perfect &quot;
<strong>解释：</strong>总共有 7 个空格和 3 个单词。7 / (3-1) = 3 个空格加上 1 个多余的空格。多余的空格需要放在字符串的末尾。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = &quot;hello   world&quot;
<strong>输出：</strong>&quot;hello   world&quot;
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>text = &quot;  walks  udp package   into  bar a&quot;
<strong>输出：</strong>&quot;walks  udp  package  into  bar  a &quot;
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>text = &quot;a&quot;
<strong>输出：</strong>&quot;a&quot;
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 100</code></li>
	<li><code>text</code> 由小写英文字母和 <code>&#39; &#39;</code> 组成</li>
	<li><code>text</code> 中至少包含一个单词</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：字符串模拟

我们先统计字符串 $\textit{text}$ 中的空格数，记为 $\textit{spaces}$。将 $\textit{text}$ 按空格分割成字符串数组 $\textit{words}$。然后计算相邻字符串之间需要拼接的空格数，进行拼接。最后将剩余的空格拼接在末尾。

时间复杂度 $O(n)$，空间复杂度 $O(n)$，其中 $n$ 表示字符串 $\textit{text}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def reorderSpaces(self, text: str) -> str:
        spaces = text.count(" ")
        words = text.split()
        if len(words) == 1:
            return words[0] + " " * spaces
        cnt, mod = divmod(spaces, len(words) - 1)
        return (" " * cnt).join(words) + " " * mod
```

#### Java

```java
class Solution {
    public String reorderSpaces(String text) {
        int spaces = 0;
        for (char c : text.toCharArray()) {
            if (c == ' ') {
                ++spaces;
            }
        }
        String[] words = text.trim().split("\\s+");
        if (words.length == 1) {
            return words[0] + " ".repeat(spaces);
        }
        int cnt = spaces / (words.length - 1);
        int mod = spaces % (words.length - 1);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; ++i) {
            sb.append(words[i]);
            if (i < words.length - 1) {
                sb.append(" ".repeat(cnt));
            }
        }
        sb.append(" ".repeat(mod));
        return sb.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = ranges::count(text, ' ');
        auto words = split(text);

        if (words.size() == 1) {
            return words[0] + string(spaces, ' ');
        }

        int cnt = spaces / (words.size() - 1);
        int mod = spaces % (words.size() - 1);

        string result = join(words, string(cnt, ' '));
        result += string(mod, ' ');

        return result;
    }

private:
    vector<string> split(const string& text) {
        vector<string> words;
        istringstream stream(text);
        string word;
        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }

    string join(const vector<string>& words, const string& separator) {
        ostringstream result;
        for (size_t i = 0; i < words.size(); ++i) {
            result << words[i];
            if (i < words.size() - 1) {
                result << separator;
            }
        }
        return result.str();
    }
};
```

#### Go

```go
func reorderSpaces(text string) string {
	cnt := strings.Count(text, " ")
	words := strings.Fields(text)
	m := len(words) - 1
	if m == 0 {
		return words[0] + strings.Repeat(" ", cnt)
	}
	return strings.Join(words, strings.Repeat(" ", cnt/m)) + strings.Repeat(" ", cnt%m)
}
```

#### TypeScript

```ts
function reorderSpaces(text: string): string {
    const spaces = (text.match(/ /g) || []).length;
    const words = text.split(/\s+/).filter(Boolean);
    if (words.length === 1) {
        return words[0] + ' '.repeat(spaces);
    }
    const cnt = Math.floor(spaces / (words.length - 1));
    const mod = spaces % (words.length - 1);
    const result = words.join(' '.repeat(cnt));
    return result + ' '.repeat(mod);
}
```

#### Rust

```rust
impl Solution {
    pub fn reorder_spaces(text: String) -> String {
        let spaces = text.chars().filter(|&c| c == ' ').count();
        let words: Vec<&str> = text.split_whitespace().collect();
        if words.len() == 1 {
            return format!("{}{}", words[0], " ".repeat(spaces));
        }
        let cnt = spaces / (words.len() - 1);
        let mod_spaces = spaces % (words.len() - 1);
        let result = words.join(&" ".repeat(cnt));
        result + &" ".repeat(mod_spaces)
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1593. 拆分字符串使唯一子字符串的数目最大](https://leetcode.cn/problems/split-a-string-into-the-max-number-of-unique-substrings){#1593}

{{< tabs "1593" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def dfs(i: int):
            nonlocal ans
            if len(st) + len(s) - i <= ans:
                return
            if i >= len(s):
                ans = max(ans, len(st))
                return
            for j in range(i + 1, len(s) + 1):
                if s[i:j] not in st:
                    st.add(s[i:j])
                    dfs(j)
                    st.remove(s[i:j])

        ans = 0
        st = set()
        dfs(0)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private Set<String> st = new HashSet<>();
    private int ans;
    private String s;

    public int maxUniqueSplit(String s) {
        this.s = s;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (st.size() + s.length() - i <= ans) {
            return;
        }
        if (i >= s.length()) {
            ans = Math.max(ans, st.size());
            return;
        }
        for (int j = i + 1; j <= s.length(); ++j) {
            String t = s.substring(i, j);
            if (st.add(t)) {
                dfs(j);
                st.remove(t);
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
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int n = s.size();
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (st.size() + n - i <= ans) {
                return;
            }
            if (i >= n) {
                ans = max(ans, (int) st.size());
                return;
            }
            for (int j = i + 1; j <= n; ++j) {
                string t = s.substr(i, j - i);
                if (!st.contains(t)) {
                    st.insert(t);
                    dfs(j);
                    st.erase(t);
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxUniqueSplit(s string) (ans int) {
	st := map[string]bool{}
	n := len(s)
	var dfs func(int)
	dfs = func(i int) {
		if len(st)+n-i <= ans {
			return
		}
		if i >= n {
			ans = max(ans, len(st))
			return
		}
		for j := i + 1; j <= n; j++ {
			if t := s[i:j]; !st[t] {
				st[t] = true
				dfs(j)
				delete(st, t)
			}
		}
	}
	dfs(0)
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxUniqueSplit(s: string): number {
    const n = s.length;
    const st = new Set<string>();
    let ans = 0;
    const dfs = (i: number): void => {
        if (st.size + n - i <= ans) {
            return;
        }
        if (i >= n) {
            ans = Math.max(ans, st.size);
            return;
        }
        for (let j = i + 1; j <= n; ++j) {
            const t = s.slice(i, j);
            if (!st.has(t)) {
                st.add(t);
                dfs(j);
                st.delete(t);
            }
        }
    };
    dfs(0);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。</p>

<p>字符串 <code>s</code> 拆分后可以得到若干 <strong>非空子字符串</strong> ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 <strong>唯一的</strong> 。</p>

<p>注意：<strong>子字符串</strong> 是字符串中的一个连续字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = &quot;ababccc&quot;
<strong>输出：</strong>5
<strong>解释：</strong>一种最大拆分方法为 [&#39;a&#39;, &#39;b&#39;, &#39;ab&#39;, &#39;c&#39;, &#39;cc&#39;] 。像 [&#39;a&#39;, &#39;b&#39;, &#39;a&#39;, &#39;b&#39;, &#39;c&#39;, &#39;cc&#39;] 这样拆分不满足题目要求，因为其中的 &#39;a&#39; 和 &#39;b&#39; 都出现了不止一次。
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = &quot;aba&quot;
<strong>输出：</strong>2
<strong>解释：</strong>一种最大拆分方法为 [&#39;a&#39;, &#39;ba&#39;] 。
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = &quot;aa&quot;
<strong>输出：</strong>1
<strong>解释：</strong>无法进一步拆分字符串。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li>
	<p><code>1 &lt;= s.length&nbsp;&lt;= 16</code></p>
	</li>
	<li>
	<p><code>s</code> 仅包含小写英文字母</p>
	</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：回溯 + 剪枝

我们定义一个哈希表 $\textit{st}$，用于存储当前已经拆分出的子字符串。然后我们使用深度优先搜索的方式，尝试将字符串 $\textit{s}$ 拆分成若干个唯一的子字符串。

具体地，我们设计一个函数 $\text{dfs}(i)$，表示我们正在考虑将 $\textit{s}[i:]$ 进行拆分。

在函数 $\text{dfs}(i)$ 中，我们首先判断如果当前已经拆分出的子字符串的数量加上剩余的字符数小于等于当前的答案，那么我们就没有必要继续拆分，直接返回。如果 $i \geq n$，那么说明我们已经完成了对整个字符串的拆分，我们更新答案为当前的子字符串数量和答案的较大值。否则，我们枚举当前子字符串的结束位置 $j$（不包括 $j$），并判断 $\textit{s}[i..j)$ 是否已经被拆分出来。如果没有被拆分出来，我们将其加入到哈希表 $\textit{st}$ 中，并继续递归地考虑拆分剩余的部分。在递归调用结束后，我们需要将 $\textit{s}[i..j)$ 从哈希表 $\textit{st}$ 中移除。

最后，我们返回答案。

时间复杂度 $O(n^2 \times 2^n)$，空间复杂度 $O(n)$。其中 $n$ 为字符串 $\textit{s}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def dfs(i: int):
            nonlocal ans
            if len(st) + len(s) - i <= ans:
                return
            if i >= len(s):
                ans = max(ans, len(st))
                return
            for j in range(i + 1, len(s) + 1):
                if s[i:j] not in st:
                    st.add(s[i:j])
                    dfs(j)
                    st.remove(s[i:j])

        ans = 0
        st = set()
        dfs(0)
        return ans
```

#### Java

```java
class Solution {
    private Set<String> st = new HashSet<>();
    private int ans;
    private String s;

    public int maxUniqueSplit(String s) {
        this.s = s;
        dfs(0);
        return ans;
    }

    private void dfs(int i) {
        if (st.size() + s.length() - i <= ans) {
            return;
        }
        if (i >= s.length()) {
            ans = Math.max(ans, st.size());
            return;
        }
        for (int j = i + 1; j <= s.length(); ++j) {
            String t = s.substring(i, j);
            if (st.add(t)) {
                dfs(j);
                st.remove(t);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int n = s.size();
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (st.size() + n - i <= ans) {
                return;
            }
            if (i >= n) {
                ans = max(ans, (int) st.size());
                return;
            }
            for (int j = i + 1; j <= n; ++j) {
                string t = s.substr(i, j - i);
                if (!st.contains(t)) {
                    st.insert(t);
                    dfs(j);
                    st.erase(t);
                }
            }
        };
        dfs(0);
        return ans;
    }
};
```

#### Go

```go
func maxUniqueSplit(s string) (ans int) {
	st := map[string]bool{}
	n := len(s)
	var dfs func(int)
	dfs = func(i int) {
		if len(st)+n-i <= ans {
			return
		}
		if i >= n {
			ans = max(ans, len(st))
			return
		}
		for j := i + 1; j <= n; j++ {
			if t := s[i:j]; !st[t] {
				st[t] = true
				dfs(j)
				delete(st, t)
			}
		}
	}
	dfs(0)
	return
}
```

#### TypeScript

```ts
function maxUniqueSplit(s: string): number {
    const n = s.length;
    const st = new Set<string>();
    let ans = 0;
    const dfs = (i: number): void => {
        if (st.size + n - i <= ans) {
            return;
        }
        if (i >= n) {
            ans = Math.max(ans, st.size);
            return;
        }
        for (let j = i + 1; j <= n; ++j) {
            const t = s.slice(i, j);
            if (!st.has(t)) {
                st.add(t);
                dfs(j);
                st.delete(t);
            }
        }
    };
    dfs(0);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1594. 矩阵的最大非负积](https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix){#1594}

{{< tabs "1594" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        mod = 10**9 + 7
        dp = [[[grid[0][0]] * 2 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            dp[i][0] = [dp[i - 1][0][0] * grid[i][0]] * 2
        for j in range(1, n):
            dp[0][j] = [dp[0][j - 1][0] * grid[0][j]] * 2
        for i in range(1, m):
            for j in range(1, n):
                v = grid[i][j]
                if v >= 0:
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v
                else:
                    dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v
                    dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v
        ans = dp[-1][-1][1]
        return -1 if ans < 0 else ans % mod
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int maxProductPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        long[][][] dp = new long[m][n][2];
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j][0] = dp[0][j - 1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j - 1][1] * grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int v = grid[i][j];
                if (v >= 0) {
                    dp[i][j][0] = Math.min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                    dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                } else {
                    dp[i][j][0] = Math.max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                    dp[i][j][1] = Math.min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                }
            }
        }
        long ans = dp[m - 1][n - 1][1];
        return ans < 0 ? -1 : (int) (ans % MOD);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;
const int mod = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(2, grid[0][0])));
        for (int i = 1; i < m; ++i) {
            dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j][0] = dp[0][j - 1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j - 1][1] * grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int v = grid[i][j];
                if (v >= 0) {
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                } else {
                    dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                    dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                }
            }
        }
        ll ans = dp[m - 1][n - 1][1];
        return ans < 0 ? -1 : (int) (ans % mod);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxProductPath(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dp := make([][][]int, m)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, 2)
		}
	}
	dp[0][0] = []int{grid[0][0], grid[0][0]}
	for i := 1; i < m; i++ {
		dp[i][0][0] = dp[i-1][0][0] * grid[i][0]
		dp[i][0][1] = dp[i-1][0][1] * grid[i][0]
	}
	for j := 1; j < n; j++ {
		dp[0][j][0] = dp[0][j-1][0] * grid[0][j]
		dp[0][j][1] = dp[0][j-1][1] * grid[0][j]
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			v := grid[i][j]
			if v >= 0 {
				dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) * v
				dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) * v
			} else {
				dp[i][j][0] = max(dp[i-1][j][1], dp[i][j-1][1]) * v
				dp[i][j][1] = min(dp[i-1][j][0], dp[i][j-1][0]) * v
			}
		}
	}
	ans := dp[m-1][n-1][1]
	if ans < 0 {
		return -1
	}
	var mod int = 1e9 + 7
	return ans % mod
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个大小为 <code>m x n</code> 的矩阵 <code>grid</code> 。最初，你位于左上角 <code>(0, 0)</code> ，每一步，你可以在矩阵中 <strong>向右</strong> 或 <strong>向下</strong> 移动。</p>

<p>在从左上角 <code>(0, 0)</code> 开始到右下角 <code>(m - 1, n - 1)</code> 结束的所有路径中，找出具有 <strong>最大非负积</strong> 的路径。路径的积是沿路径访问的单元格中所有整数的乘积。</p>

<p>返回 <strong>最大非负积 </strong>对<strong><em> </em><code>10<sup>9</sup>&nbsp;+ 7</code></strong> <strong>取余</strong> 的结果。如果最大积为 <strong>负数</strong> ，则返回<em> </em><code>-1</code> 。</p>

<p><strong>注意，</strong>取余是在得到最大积之后执行的。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1594.Maximum%20Non%20Negative%20Product%20in%20a%20Matrix/images/product1.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
<strong>输出：</strong>-1
<strong>解释：</strong>从 (0, 0) 到 (2, 2) 的路径中无法得到非负积，所以返回 -1 。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1594.Maximum%20Non%20Negative%20Product%20in%20a%20Matrix/images/product2.jpg" style="width: 244px; height: 245px;" />
<pre>
<strong>输入：</strong>grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
<strong>输出：</strong>8
<strong>解释：</strong>最大非负积对应的路径如图所示 (1 * 1 * -2 * -4 * 1 = 8)
</pre>

<p><strong>示例 3：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1594.Maximum%20Non%20Negative%20Product%20in%20a%20Matrix/images/product3.jpg" style="width: 164px; height: 165px;" />
<pre>
<strong>输入：</strong>grid = [[1,3],[0,-4]]
<strong>输出：</strong>0
<strong>解释：</strong>最大非负积对应的路径如图所示 (1 * 0 * -4 = 0)
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 15</code></li>
	<li><code>-4 &lt;= grid[i][j] &lt;= 4</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

时间复杂度 $O(m\times n)$。其中 $m$ 和 $n$ 分别为矩阵的行数和列数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        mod = 10**9 + 7
        dp = [[[grid[0][0]] * 2 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            dp[i][0] = [dp[i - 1][0][0] * grid[i][0]] * 2
        for j in range(1, n):
            dp[0][j] = [dp[0][j - 1][0] * grid[0][j]] * 2
        for i in range(1, m):
            for j in range(1, n):
                v = grid[i][j]
                if v >= 0:
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v
                else:
                    dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v
                    dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v
        ans = dp[-1][-1][1]
        return -1 if ans < 0 else ans % mod
```

#### Java

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int maxProductPath(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        long[][][] dp = new long[m][n][2];
        dp[0][0][0] = grid[0][0];
        dp[0][0][1] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j][0] = dp[0][j - 1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j - 1][1] * grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int v = grid[i][j];
                if (v >= 0) {
                    dp[i][j][0] = Math.min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                    dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                } else {
                    dp[i][j][0] = Math.max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                    dp[i][j][1] = Math.min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                }
            }
        }
        long ans = dp[m - 1][n - 1][1];
        return ans < 0 ? -1 : (int) (ans % MOD);
    }
}
```

#### C++

```cpp
using ll = long long;
const int mod = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(2, grid[0][0])));
        for (int i = 1; i < m; ++i) {
            dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j][0] = dp[0][j - 1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j - 1][1] * grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int v = grid[i][j];
                if (v >= 0) {
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                } else {
                    dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * v;
                    dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * v;
                }
            }
        }
        ll ans = dp[m - 1][n - 1][1];
        return ans < 0 ? -1 : (int) (ans % mod);
    }
};
```

#### Go

```go
func maxProductPath(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	dp := make([][][]int, m)
	for i := range dp {
		dp[i] = make([][]int, n)
		for j := range dp[i] {
			dp[i][j] = make([]int, 2)
		}
	}
	dp[0][0] = []int{grid[0][0], grid[0][0]}
	for i := 1; i < m; i++ {
		dp[i][0][0] = dp[i-1][0][0] * grid[i][0]
		dp[i][0][1] = dp[i-1][0][1] * grid[i][0]
	}
	for j := 1; j < n; j++ {
		dp[0][j][0] = dp[0][j-1][0] * grid[0][j]
		dp[0][j][1] = dp[0][j-1][1] * grid[0][j]
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			v := grid[i][j]
			if v >= 0 {
				dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) * v
				dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]) * v
			} else {
				dp[i][j][0] = max(dp[i-1][j][1], dp[i][j-1][1]) * v
				dp[i][j][1] = min(dp[i-1][j][0], dp[i][j-1][0]) * v
			}
		}
	}
	ans := dp[m-1][n-1][1]
	if ans < 0 {
		return -1
	}
	var mod int = 1e9 + 7
	return ans % mod
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1595. 连通两组点的最小成本](https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points){#1595}

{{< tabs "1595" >}}

{{% tab "python" %}}
```python
class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        m, n = len(cost), len(cost[0])
        f = [inf] * (1 << n)
        f[0] = 0
        g = f[:]
        for i in range(1, m + 1):
            for j in range(1 << n):
                g[j] = inf
                for k in range(n):
                    if (j >> k & 1) == 0:
                        continue
                    c = cost[i - 1][k]
                    x = min(g[j ^ (1 << k)], f[j], f[j ^ (1 << k)]) + c
                    g[j] = min(g[j], x)
            f = g[:]
        return f[-1]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int connectTwoGroups(List<List<Integer>> cost) {
        int m = cost.size(), n = cost.get(0).size();
        final int inf = 1 << 30;
        int[] f = new int[1 << n];
        Arrays.fill(f, inf);
        f[0] = 0;
        int[] g = f.clone();
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                g[j] = inf;
                for (int k = 0; k < n; ++k) {
                    if ((j >> k & 1) == 1) {
                        int c = cost.get(i - 1).get(k);
                        g[j] = Math.min(g[j], g[j ^ (1 << k)] + c);
                        g[j] = Math.min(g[j], f[j] + c);
                        g[j] = Math.min(g[j], f[j ^ (1 << k)] + c);
                    }
                }
            }
            System.arraycopy(g, 0, f, 0, 1 << n);
        }
        return f[(1 << n) - 1];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(), n = cost[0].size();
        const int inf = 1 << 30;
        vector<int> f(1 << n, inf);
        f[0] = 0;
        vector<int> g = f;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                g[j] = inf;
                for (int k = 0; k < n; ++k) {
                    if (j >> k & 1) {
                        int c = cost[i - 1][k];
                        int x = min({g[j ^ (1 << k)], f[j], f[j ^ (1 << k)]}) + c;
                        g[j] = min(g[j], x);
                    }
                }
            }
            f.swap(g);
        }
        return f[(1 << n) - 1];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func connectTwoGroups(cost [][]int) int {
	m, n := len(cost), len(cost[0])
	const inf = 1 << 30
	f := make([]int, 1<<n)
	for i := range f {
		f[i] = inf
	}
	f[0] = 0
	g := make([]int, 1<<n)
	for i := 1; i <= m; i++ {
		for j := 0; j < 1<<n; j++ {
			g[j] = inf
			for k := 0; k < n; k++ {
				c := cost[i-1][k]
				if j>>k&1 == 1 {
					g[j] = min(g[j], g[j^1<<k]+c)
					g[j] = min(g[j], f[j]+c)
					g[j] = min(g[j], f[j^1<<k]+c)
				}
			}
		}
		copy(f, g)
	}
	return f[1<<n-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function connectTwoGroups(cost: number[][]): number {
    const m = cost.length;
    const n = cost[0].length;
    const inf = 1 << 30;
    const f: number[] = new Array(1 << n).fill(inf);
    f[0] = 0;
    const g = new Array(1 << n).fill(0);
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j < 1 << n; ++j) {
            g[j] = inf;
            for (let k = 0; k < n; ++k) {
                if (((j >> k) & 1) === 1) {
                    const c = cost[i - 1][k];
                    g[j] = Math.min(g[j], g[j ^ (1 << k)] + c);
                    g[j] = Math.min(g[j], f[j] + c);
                    g[j] = Math.min(g[j], f[j ^ (1 << k)] + c);
                }
            }
        }
        f.splice(0, f.length, ...g);
    }
    return f[(1 << n) - 1];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你两组点，其中第一组中有 <code>size<sub>1</sub></code> 个点，第二组中有 <code>size<sub>2</sub></code> 个点，且 <code>size<sub>1</sub> &gt;= size<sub>2</sub></code> 。</p>

<p>任意两点间的连接成本 <code>cost</code> 由大小为 <code>size<sub>1</sub> x size<sub>2</sub></code> 矩阵给出，其中 <code>cost[i][j]</code> 是第一组中的点 <code>i</code> 和第二组中的点 <code>j</code> 的连接成本。<strong>如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。</strong>换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。</p>

<p>返回连通两组点所需的最小成本。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1595.Minimum%20Cost%20to%20Connect%20Two%20Groups%20of%20Points/images/ex1.jpg" style="height: 243px; width: 322px;"></p>

<pre><strong>输入：</strong>cost = [[15, 96], [36, 2]]
<strong>输出：</strong>17
<strong>解释：</strong>连通两组点的最佳方法是：
1--A
2--B
总成本为 17 。
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1595.Minimum%20Cost%20to%20Connect%20Two%20Groups%20of%20Points/images/ex2.jpg" style="height: 403px; width: 322px;"></p>

<pre><strong>输入：</strong>cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
<strong>输出：</strong>4
<strong>解释：</strong>连通两组点的最佳方法是：
1--A
2--B
2--C
3--A
最小成本为 4 。
请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A ，但由于题目并不限制连接点的数目，所以只需要关心最低总成本。</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
<strong>输出：</strong>10
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>size<sub>1</sub> == cost.length</code></li>
	<li><code>size<sub>2</sub> == cost[i].length</code></li>
	<li><code>1 &lt;= size<sub>1</sub>, size<sub>2</sub> &lt;= 12</code></li>
	<li><code>size<sub>1</sub> &gt;=&nbsp;size<sub>2</sub></code></li>
	<li><code>0 &lt;= cost[i][j] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 动态规划

我们记第一组的点数为 $m$，第二组的点数为 $n$。

由于 $1 \leq n \leq m \leq 12$，因此，我们可以用一个整数来表示第二组中点的状态，即二进制表示的一个长度为 $n$ 的整数，其中第 $k$ 位为 $1$ 表示第二组中的第 $k$ 个点与第一组中的点连通，为 $0$ 表示不连通。

接下来，我们定义 $f[i][j]$ 表示第一组中的前 $i$ 个点已经全部连通，且第二组中的点的状态为 $j$ 时的最小成本。初始时 $f[0][0] = 0$，其余值均为正无穷大。答案即为 $f[m][2^n - 1]$。

考虑 $f[i][j]$，其中 $i \geq 1$。我们可以枚举第二组中的每个点 $k$，如果点 $k$ 与第一组中的第 $i$ 个点连通，那么我们可以分以下两种情况讨论：

-   如果点 $k$ 只与第一组中的第 $i$ 个点连通，那么 $f[i][j]$ 可以从 $f[i][j \oplus 2^k]$ 或者 $f[i - 1][j \oplus 2^k]$ 转移而来，其中 $\oplus$ 表示异或运算；
-   如果点 $k$ 与第一组中的第 $i$ 个点以及其他点都连通，那么 $f[i][j]$ 可以从 $f[i - 1][j]$ 转移而来。

在上述两种情况中，我们需要选择转移值最小的那个，即有：

$$
f[i][j] = \min_{k \in \{0, 1, \cdots, n - 1\}} \{f[i][j \oplus 2^k], f[i - 1][j \oplus 2^k], f[i - 1][j]\} + cost[i - 1][k]
$$

最后，我们返回 $f[m][2^n - 1]$ 即可。

时间复杂度 $O(m \times n \times 2^n)$，空间复杂度 $O(m \times 2^n)$。其中 $m$ 和 $n$ 分别是第一组和第二组中的点数。

我们注意到 $f[i][j]$ 的转移只与 $f[i - 1][\cdot]$ 以及 $f[i][\cdot]$ 有关，因此我们可以使用滚动数组优化空间复杂度，将空间复杂度优化到 $O(2^n)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        m, n = len(cost), len(cost[0])
        f = [[inf] * (1 << n) for _ in range(m + 1)]
        f[0][0] = 0
        for i in range(1, m + 1):
            for j in range(1 << n):
                for k in range(n):
                    if (j >> k & 1) == 0:
                        continue
                    c = cost[i - 1][k]
                    x = min(f[i][j ^ (1 << k)], f[i - 1][j], f[i - 1][j ^ (1 << k)]) + c
                    f[i][j] = min(f[i][j], x)
        return f[m][-1]
```

#### Java

```java
class Solution {
    public int connectTwoGroups(List<List<Integer>> cost) {
        int m = cost.size(), n = cost.get(0).size();
        final int inf = 1 << 30;
        int[][] f = new int[m + 1][1 << n];
        for (int[] g : f) {
            Arrays.fill(g, inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if ((j >> k & 1) == 1) {
                        int c = cost.get(i - 1).get(k);
                        f[i][j] = Math.min(f[i][j], f[i][j ^ (1 << k)] + c);
                        f[i][j] = Math.min(f[i][j], f[i - 1][j] + c);
                        f[i][j] = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + c);
                    }
                }
            }
        }
        return f[m][(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(), n = cost[0].size();
        int f[m + 1][1 << n];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (j >> k & 1) {
                        int c = cost[i - 1][k];
                        int x = min({f[i][j ^ (1 << k)], f[i - 1][j], f[i - 1][j ^ (1 << k)]}) + c;
                        f[i][j] = min(f[i][j], x);
                    }
                }
            }
        }
        return f[m][(1 << n) - 1];
    }
};
```

#### Go

```go
func connectTwoGroups(cost [][]int) int {
	m, n := len(cost), len(cost[0])
	const inf = 1 << 30
	f := make([][]int, m+1)
	for i := range f {
		f[i] = make([]int, 1<<n)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= m; i++ {
		for j := 0; j < 1<<n; j++ {
			for k := 0; k < n; k++ {
				c := cost[i-1][k]
				if j>>k&1 == 1 {
					f[i][j] = min(f[i][j], f[i][j^(1<<k)]+c)
					f[i][j] = min(f[i][j], f[i-1][j]+c)
					f[i][j] = min(f[i][j], f[i-1][j^(1<<k)]+c)
				}
			}
		}
	}
	return f[m][(1<<n)-1]
}
```

#### TypeScript

```ts
function connectTwoGroups(cost: number[][]): number {
    const m = cost.length;
    const n = cost[0].length;
    const inf = 1 << 30;
    const f: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(1 << n).fill(inf));
    f[0][0] = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j < 1 << n; ++j) {
            for (let k = 0; k < n; ++k) {
                if (((j >> k) & 1) === 1) {
                    const c = cost[i - 1][k];
                    f[i][j] = Math.min(f[i][j], f[i][j ^ (1 << k)] + c);
                    f[i][j] = Math.min(f[i][j], f[i - 1][j] + c);
                    f[i][j] = Math.min(f[i][j], f[i - 1][j ^ (1 << k)] + c);
                }
            }
        }
    }
    return f[m][(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        m, n = len(cost), len(cost[0])
        f = [inf] * (1 << n)
        f[0] = 0
        g = f[:]
        for i in range(1, m + 1):
            for j in range(1 << n):
                g[j] = inf
                for k in range(n):
                    if (j >> k & 1) == 0:
                        continue
                    c = cost[i - 1][k]
                    x = min(g[j ^ (1 << k)], f[j], f[j ^ (1 << k)]) + c
                    g[j] = min(g[j], x)
            f = g[:]
        return f[-1]
```

#### Java

```java
class Solution {
    public int connectTwoGroups(List<List<Integer>> cost) {
        int m = cost.size(), n = cost.get(0).size();
        final int inf = 1 << 30;
        int[] f = new int[1 << n];
        Arrays.fill(f, inf);
        f[0] = 0;
        int[] g = f.clone();
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                g[j] = inf;
                for (int k = 0; k < n; ++k) {
                    if ((j >> k & 1) == 1) {
                        int c = cost.get(i - 1).get(k);
                        g[j] = Math.min(g[j], g[j ^ (1 << k)] + c);
                        g[j] = Math.min(g[j], f[j] + c);
                        g[j] = Math.min(g[j], f[j ^ (1 << k)] + c);
                    }
                }
            }
            System.arraycopy(g, 0, f, 0, 1 << n);
        }
        return f[(1 << n) - 1];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int m = cost.size(), n = cost[0].size();
        const int inf = 1 << 30;
        vector<int> f(1 << n, inf);
        f[0] = 0;
        vector<int> g = f;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < 1 << n; ++j) {
                g[j] = inf;
                for (int k = 0; k < n; ++k) {
                    if (j >> k & 1) {
                        int c = cost[i - 1][k];
                        int x = min({g[j ^ (1 << k)], f[j], f[j ^ (1 << k)]}) + c;
                        g[j] = min(g[j], x);
                    }
                }
            }
            f.swap(g);
        }
        return f[(1 << n) - 1];
    }
};
```

#### Go

```go
func connectTwoGroups(cost [][]int) int {
	m, n := len(cost), len(cost[0])
	const inf = 1 << 30
	f := make([]int, 1<<n)
	for i := range f {
		f[i] = inf
	}
	f[0] = 0
	g := make([]int, 1<<n)
	for i := 1; i <= m; i++ {
		for j := 0; j < 1<<n; j++ {
			g[j] = inf
			for k := 0; k < n; k++ {
				c := cost[i-1][k]
				if j>>k&1 == 1 {
					g[j] = min(g[j], g[j^1<<k]+c)
					g[j] = min(g[j], f[j]+c)
					g[j] = min(g[j], f[j^1<<k]+c)
				}
			}
		}
		copy(f, g)
	}
	return f[1<<n-1]
}
```

#### TypeScript

```ts
function connectTwoGroups(cost: number[][]): number {
    const m = cost.length;
    const n = cost[0].length;
    const inf = 1 << 30;
    const f: number[] = new Array(1 << n).fill(inf);
    f[0] = 0;
    const g = new Array(1 << n).fill(0);
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j < 1 << n; ++j) {
            g[j] = inf;
            for (let k = 0; k < n; ++k) {
                if (((j >> k) & 1) === 1) {
                    const c = cost[i - 1][k];
                    g[j] = Math.min(g[j], g[j ^ (1 << k)] + c);
                    g[j] = Math.min(g[j], f[j] + c);
                    g[j] = Math.min(g[j], f[j ^ (1 << k)] + c);
                }
            }
        }
        f.splice(0, f.length, ...g);
    }
    return f[(1 << n) - 1];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1596. 每位顾客最经常订购的商品 🔒](https://leetcode.cn/problems/the-most-frequently-ordered-products-for-each-customer){#1596}

{{< tabs "1596" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            customer_id,
            product_id,
            RANK() OVER (
                PARTITION BY customer_id
                ORDER BY COUNT(1) DESC
            ) AS rk
        FROM Orders
        GROUP BY 1, 2
    )
SELECT customer_id, product_id, product_name
FROM
    T
    JOIN Products USING (product_id)
WHERE rk = 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：<code>Customers</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| customer_id   | int     |
| name          | varchar |
+---------------+---------+
customer_id 是该表具有唯一值的列
该表包含所有顾客的信息
</pre>

<p>&nbsp;</p>

<p>表：<code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| customer_id   | int     |
| product_id    | int     |
+---------------+---------+
order_id 是该表具有唯一值的列
该表包含顾客 customer_id 的订单信息
没有顾客会在一天内订购相同的商品<strong> 多于一次</strong></pre>

<p>&nbsp;</p>

<p>表：<code>Products</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| product_id    | int     |
| product_name  | varchar |
| price         | int     |
+---------------+---------+
product_id 是该表具有唯一值的列
该表包含了所有商品的信息
</pre>

<p>&nbsp;</p>

<p>写一个解决方案，找到每一个顾客最经常订购的商品。</p>

<p>结果表单应该有每一位至少下过一次单的顾客 <code>customer_id</code>&nbsp;,&nbsp;他最经常订购的商品的&nbsp;<code>product_id</code>&nbsp;和&nbsp;<code>product_name</code>。</p>

<p>返回结果<strong> 没有顺序要求</strong>。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<code><strong>输入：</strong>
Customers表：</code>
+-------------+-------+
| customer_id | name  |
+-------------+-------+
| 1           | Alice |
| 2           | Bob   |
| 3           | Tom   |
| 4           | Jerry |
| 5           | John  |
+-------------+-------+
<code>Orders表：</code>
+----------+------------+-------------+------------+
| order_id | order_date | customer_id | product_id |
+----------+------------+-------------+------------+
| 1        | 2020-07-31 | 1           | 1          |
| 2        | 2020-07-30 | 2           | 2          |
| 3        | 2020-08-29 | 3           | 3          |
| 4        | 2020-07-29 | 4           | 1          |
| 5        | 2020-06-10 | 1           | 2          |
| 6        | 2020-08-01 | 2           | 1          |
| 7        | 2020-08-01 | 3           | 3          |
| 8        | 2020-08-03 | 1           | 2          |
| 9        | 2020-08-07 | 2           | 3          |
| 10       | 2020-07-15 | 1           | 2          |
+----------+------------+-------------+------------+
<code>Products表：</code>
+------------+--------------+-------+
| product_id | product_name | price |
+------------+--------------+-------+
| 1          | keyboard     | 120   |
| 2          | mouse        | 80    |
| 3          | screen       | 600   |
| 4          | hard disk    | 450   |
+------------+--------------+-------+
<strong>输出：</strong>
+-------------+------------+--------------+
| customer_id | product_id | product_name |
+-------------+------------+--------------+
| 1           | 2          | mouse        |
| 2           | 1          | keyboard     |
| 2           | 2          | mouse        |
| 2           | 3          | screen       |
| 3           | 3          | screen       |
| 4           | 1          | keyboard     |
+-------------+------------+--------------+
<strong>解释：</strong>
Alice (customer 1) 三次订购鼠标, 一次订购键盘, 所以鼠标是 Alice 最经常订购的商品.
Bob (customer 2) 一次订购键盘, 一次订购鼠标, 一次订购显示器, 所以这些都是 Bob 最经常订购的商品.
Tom (customer 3) 只两次订购显示器, 所以显示器是 Tom 最经常订购的商品.
Jerry (customer 4) 只一次订购键盘, 所以键盘是 Jerry 最经常订购的商品.
John (customer 5) 没有订购过商品, 所以我们并没有把 John 包含在结果表中.</pre>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：分组 + 窗口函数

我们将 `Orders` 表按照 `customer_id` 和 `product_id` 进行分组，然后利用窗口函数 `rank()`，按照 `customer_id` 分区，并且按照 `count(1)` 降序排列，得到每个 `customer_id` 下对应的 `product_id` 的排名，排名为 $1$ 的就是该 `customer_id` 下最经常订购的商品。

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
WITH
    T AS (
        SELECT
            customer_id,
            product_id,
            RANK() OVER (
                PARTITION BY customer_id
                ORDER BY COUNT(1) DESC
            ) AS rk
        FROM Orders
        GROUP BY 1, 2
    )
SELECT customer_id, product_id, product_name
FROM
    T
    JOIN Products USING (product_id)
WHERE rk = 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1597. 根据中缀表达式构造二叉表达式树 🔒](https://leetcode.cn/problems/build-binary-expression-tree-from-infix-expression){#1597}

{{< tabs "1597" >}}

{{% tab "python" %}}
```python

```
{{% /tab %}}
{{% tab "java" %}}
```java

```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp

```
{{% /tab %}}
{{% tab "go" %}}
```go

```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><strong>二叉表达式树</strong> 是一种表达算术表达式的二叉树。二叉表达式树中的每一个节点都有零个或两个子节点。&nbsp;叶节点（有 0 个子节点的节点）表示操作数，非叶节点（有 2 个子节点的节点）表示运算符：&nbsp;<code>'+'</code>&nbsp;（加）、&nbsp;<code>'-'</code> （减）、&nbsp;<code>'*'</code> （乘）和&nbsp;<code>'/'</code> （除）。</p>

<p>对于每一个运算符为 <code>o</code> 的非叶节点，对应的<strong> <a href="http://baike.baidu.com/item/中缀表达式/2725244?fr=aladdin" target="_blank">中缀表达式</a></strong> 为&nbsp;<code>(A o B)</code>，其中&nbsp;<code>A</code>&nbsp;是左子树所表达的表达式，&nbsp;<code>B</code>&nbsp;是右子树所表达的表达式。</p>

<p>给定一个<strong> 中缀表达式 </strong>字符串&nbsp;<code>s</code>，其中包含操作数、上面提到的运算符，以及括号&nbsp;<code>'('</code>&nbsp;与&nbsp;<code>')'</code>&nbsp;。</p>

<p>返回一个有效的<strong> 二叉表达式树</strong>，其 <a href="http://baike.baidu.com/item/中序遍历/757281?fr=aladdin" target="_blank"><strong>中序遍历</strong></a><sup> </sup>序列对应表达式 <code>s</code> 消除括号后的序列（详情参见下面的示例）<em>。</em></p>

<p><strong>注意，表达式的一般解析顺序适用于&nbsp;</strong><code>s</code>，即优先解析括号内的表达式，然后解析乘除法，最后解析加减法。</p>

<p>同时，操作数在 <code>s</code> 和树的中序遍历中 <strong>出现顺序相同</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1597.Build%20Binary%20Expression%20Tree%20From%20Infix%20Expression/images/ex1-4.png" style="width: 250px; height: 161px;" />
<pre>
<strong>输入：</strong>s = "3*4-2*5"
<strong>输出：</strong>[-,*,*,3,4,2,5]
<strong>解释：</strong>上面是唯一一种有效的二叉表达式树，其中序遍历生成 s 。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1597.Build%20Binary%20Expression%20Tree%20From%20Infix%20Expression/images/ex1-2.png" style="width: 150px; height: 210px;" />
<pre>
<strong>输入：</strong>s = "2-3/(5*2)+1"
<strong>输出：</strong>[+,-,1,2,/,null,null,null,null,3,*,null,null,5,2]
<strong>解释：</strong>上面的树的中序遍历为 2-3/5*2+1 ，与 s 消除括号后相同。该树还会生成正确的结果，其操作数的顺序与 s 中出现的顺序相同。
下面的树也是一个有效的二叉表达式树，具有与 s 相同的中序遍历，但它不是一个有效的答案，因为它的求值结果不同。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1597.Build%20Binary%20Expression%20Tree%20From%20Infix%20Expression/images/ex1-1.png" style="width: 201px; height: 281px;" />
下面的树也是无效的。尽管它的计算结果相等并与上述树等效，但其中序遍历不会产生 s ，并且其操作数与 s 中的顺序也不相同。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1597.Build%20Binary%20Expression%20Tree%20From%20Infix%20Expression/images/ex1-3.png" style="width: 281px; height: 281px;" />
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "1+2+3+4+5"
<strong>输出：</strong>[+,+,5,+,4,null,null,+,3,null,null,1,2]
<strong>解释：</strong>二叉树 [+,+,5,+,+,null,null,1,2,3,4] 也是诸多有效的二叉表达式树之一。</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code>&nbsp;中包含数字和字符&nbsp;<code>'('</code>、&nbsp;<code>')'</code>、<code>'+'</code>、&nbsp;<code>'-'</code>、&nbsp;<code>'*'</code>、&nbsp;<code>'/'</code> 。</li>
	<li><code>s</code>&nbsp;中的操作数 <strong>恰好</strong> 是一位数字。</li>
	<li>题目数据保证 <code>s</code> 是一个有效的表达式。</li>
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

```

#### Java

```java

```

#### C++

```cpp

```

#### Go

```go

```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1598. 文件夹操作日志搜集器](https://leetcode.cn/problems/crawler-log-folder){#1598}

{{< tabs "1598" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperations(self, logs: List[str]) -> int:
        ans = 0
        for v in logs:
            if v == "../":
                ans = max(0, ans - 1)
            elif v[0] != ".":
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperations(String[] logs) {
        int ans = 0;
        for (var v : logs) {
            if ("../".equals(v)) {
                ans = Math.max(0, ans - 1);
            } else if (v.charAt(0) != '.') {
                ++ans;
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
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto& v : logs) {
            if (v == "../") {
                ans = max(0, ans - 1);
            } else if (v[0] != '.') {
                ++ans;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperations(logs []string) int {
	ans := 0
	for _, v := range logs {
		if v == "../" {
			if ans > 0 {
				ans--
			}
		} else if v[0] != '.' {
			ans++
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperations(logs) {
    let ans = 0;
    for (const x of logs) {
        if (x === '../') {
            ans && ans--;
        } else if (x !== './') {
            ans++;
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut depth = 0;
        for log in logs.iter() {
            if log == "../" {
                depth = (0).max(depth - 1);
            } else if log != "./" {
                depth += 1;
            }
        }
        depth
    }
}
```
{{% /tab %}}
{{% tab "c" %}}
```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minOperations(char** logs, int logsSize) {
    int depth = 0;
    for (int i = 0; i < logsSize; i++) {
        char* log = logs[i];
        if (!strcmp(log, "../")) {
            depth = max(0, depth - 1);
        } else if (strcmp(log, "./")) {
            depth++;
        }
    }
    return depth;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>每当用户执行变更文件夹操作时，LeetCode 文件系统都会保存一条日志记录。</p>

<p>下面给出对变更操作的说明：</p>

<ul>
	<li><code>&quot;../&quot;</code> ：移动到当前文件夹的父文件夹。如果已经在主文件夹下，则 <strong>继续停留在当前文件夹</strong> 。</li>
	<li><code>&quot;./&quot;</code> ：继续停留在当前文件夹<strong>。</strong></li>
	<li><code>&quot;x/&quot;</code> ：移动到名为 <code>x</code> 的子文件夹中。题目数据 <strong>保证总是存在文件夹 <code>x</code></strong> 。</li>
</ul>

<p>给你一个字符串列表 <code>logs</code> ，其中 <code>logs[i]</code> 是用户在 <code>i<sup>th</sup></code> 步执行的操作。</p>

<p>文件系统启动时位于主文件夹，然后执行 <code>logs</code> 中的操作。</p>

<p>执行完所有变更文件夹操作后，请你找出 <strong>返回主文件夹所需的最小步数</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1598.Crawler%20Log%20Folder/images/sample_11_1957.png" style="height: 151px; width: 775px;"></p>

<pre><strong>输入：</strong>logs = [&quot;d1/&quot;,&quot;d2/&quot;,&quot;../&quot;,&quot;d21/&quot;,&quot;./&quot;]
<strong>输出：</strong>2
<strong>解释：</strong>执行 &quot;../&quot; 操作变更文件夹 2 次，即可回到主文件夹
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1598.Crawler%20Log%20Folder/images/sample_22_1957.png" style="height: 270px; width: 600px;"></p>

<pre><strong>输入：</strong>logs = [&quot;d1/&quot;,&quot;d2/&quot;,&quot;./&quot;,&quot;d3/&quot;,&quot;../&quot;,&quot;d31/&quot;]
<strong>输出：</strong>3
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>logs = [&quot;d1/&quot;,&quot;../&quot;,&quot;../&quot;,&quot;../&quot;]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 10<sup>3</sup></code></li>
	<li><code>2 &lt;= logs[i].length &lt;= 10</code></li>
	<li><code>logs[i]</code> 包含小写英文字母，数字，<code>&#39;.&#39;</code> 和 <code>&#39;/&#39;</code></li>
	<li><code>logs[i]</code> 符合语句中描述的格式</li>
	<li>文件夹名称由小写英文字母和数字组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

直接模拟，记录深度的变化即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 为 `logs` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperations(self, logs: List[str]) -> int:
        ans = 0
        for v in logs:
            if v == "../":
                ans = max(0, ans - 1)
            elif v[0] != ".":
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int minOperations(String[] logs) {
        int ans = 0;
        for (var v : logs) {
            if ("../".equals(v)) {
                ans = Math.max(0, ans - 1);
            } else if (v.charAt(0) != '.') {
                ++ans;
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
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto& v : logs) {
            if (v == "../") {
                ans = max(0, ans - 1);
            } else if (v[0] != '.') {
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minOperations(logs []string) int {
	ans := 0
	for _, v := range logs {
		if v == "../" {
			if ans > 0 {
				ans--
			}
		} else if v[0] != '.' {
			ans++
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minOperations(logs: string[]): number {
    let ans = 0;
    for (const x of logs) {
        if (x === '../') {
            ans && ans--;
        } else if (x !== './') {
            ans++;
        }
    }
    return ans;
}
```

#### JavaScript

```ts
function minOperations(logs) {
    let ans = 0;
    for (const x of logs) {
        if (x === '../') {
            ans && ans--;
        } else if (x !== './') {
            ans++;
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut depth = 0;
        for log in logs.iter() {
            if log == "../" {
                depth = (0).max(depth - 1);
            } else if log != "./" {
                depth += 1;
            }
        }
        depth
    }
}
```

#### C

```c
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minOperations(char** logs, int logsSize) {
    int depth = 0;
    for (int i = 0; i < logsSize; i++) {
        char* log = logs[i];
        if (!strcmp(log, "../")) {
            depth = max(0, depth - 1);
        } else if (strcmp(log, "./")) {
            depth++;
        }
    }
    return depth;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1599. 经营摩天轮的最大利润](https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel){#1599}

{{< tabs "1599" >}}

{{% tab "python" %}}
```python
class Solution:
    def minOperationsMaxProfit(
        self, customers: List[int], boardingCost: int, runningCost: int
    ) -> int:
        ans = -1
        mx = t = 0
        wait = 0
        i = 0
        while wait or i < len(customers):
            wait += customers[i] if i < len(customers) else 0
            up = wait if wait < 4 else 4
            wait -= up
            t += up * boardingCost - runningCost
            i += 1
            if t > mx:
                mx = t
                ans = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        int ans = -1;
        int mx = 0, t = 0;
        int wait = 0, i = 0;
        while (wait > 0 || i < customers.length) {
            wait += i < customers.length ? customers[i] : 0;
            int up = Math.min(4, wait);
            wait -= up;
            ++i;
            t += up * boardingCost - runningCost;
            if (t > mx) {
                mx = t;
                ans = i;
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
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1;
        int mx = 0, t = 0;
        int wait = 0, i = 0;
        while (wait || i < customers.size()) {
            wait += i < customers.size() ? customers[i] : 0;
            int up = min(4, wait);
            wait -= up;
            ++i;
            t += up * boardingCost - runningCost;
            if (t > mx) {
                mx = t;
                ans = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minOperationsMaxProfit(customers []int, boardingCost int, runningCost int) int {
	ans := -1
	t, mx := 0, 0
	wait, i := 0, 0
	for wait > 0 || i < len(customers) {
		if i < len(customers) {
			wait += customers[i]
		}
		up := min(4, wait)
		wait -= up
		t += up*boardingCost - runningCost
		i++
		if t > mx {
			mx = t
			ans = i
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minOperationsMaxProfit(
    customers: number[],
    boardingCost: number,
    runningCost: number,
): number {
    let ans: number = -1;
    let [mx, t, wait, i] = [0, 0, 0, 0];
    while (wait > 0 || i < customers.length) {
        wait += i < customers.length ? customers[i] : 0;
        let up: number = Math.min(4, wait);
        wait -= up;
        ++i;
        t += up * boardingCost - runningCost;

        if (t > mx) {
            mx = t;
            ans = i;
        }
    }

    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn min_operations_max_profit(
        customers: Vec<i32>,
        boarding_cost: i32,
        running_cost: i32,
    ) -> i32 {
        let mut ans = -1;
        let mut mx = 0;
        let mut t = 0;
        let mut wait = 0;
        let mut i = 0;

        while wait > 0 || i < customers.len() {
            wait += if i < customers.len() { customers[i] } else { 0 };
            let up = std::cmp::min(4, wait);
            wait -= up;
            i += 1;
            t += up * boarding_cost - running_cost;

            if t > mx {
                mx = t;
                ans = i as i32;
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

<p>你正在经营一座摩天轮，该摩天轮共有 <strong>4 个座舱</strong> ，每个座舱<strong> 最多可以容纳 4 位游客</strong> 。你可以 <strong>逆时针</strong>&nbsp;轮转座舱，但每次轮转都需要支付一定的运行成本 <code>runningCost</code> 。</p>

<p>给你一个长度为 <code>n</code> 的数组 <code>customers</code> ， <code>customers[i]</code> 是在第 <code>i</code> 次轮转（下标从 0 开始）之前到达的新游客的数量。这也意味着你必须在新游客到来前轮转 <code>i</code> 次。<strong>如果有座舱空闲就不能让游客等待。</strong>每位游客在登上离地面最近的座舱前都会支付登舱成本 <code>boardingCost</code> ，一旦该座舱再次抵达地面，他们就会离开座舱结束游玩。</p>

<p>你可以随时停下摩天轮，即便是 <strong>在服务所有游客之前</strong> 。如果你决定停止运营摩天轮，为了保证所有游客安全着陆，<strong>将免费进行</strong><strong>所有后续轮转</strong>&nbsp;。注意，如果有超过 4 位游客在等摩天轮，那么只有 4 位游客可以登上摩天轮，其余的需要等待 <strong>下一次轮转</strong> 。</p>

<p>返回最大化利润所需执行的 <strong>最小轮转次数</strong> 。 如果不存在利润为正的方案，则返回 <code>-1</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1599.Maximum%20Profit%20of%20Operating%20a%20Centennial%20Wheel/images/wheeldiagram12.png" /></p>

<pre>
<strong>输入：</strong>customers = [8,3], boardingCost = 5, runningCost = 6
<strong>输出：</strong>3
<strong>解释：</strong>座舱上标注的数字是该座舱的当前游客数。
1. 8 位游客抵达，4 位登舱，4 位等待下一舱，摩天轮轮转。当前利润为 4 * $5 - 1 * $6 = $14 。
2. 3 位游客抵达，4 位在等待的游客登舱，其他 3 位等待，摩天轮轮转。当前利润为 8 * $5 - 2 * $6 = $28 。
3. 最后 3 位游客登舱，摩天轮轮转。当前利润为 11 * $5 - 3 * $6 = $37 。
轮转 3 次得到最大利润，最大利润为 $37 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>customers = [10,9,6], boardingCost = 6, runningCost = 4
<strong>输出：</strong>7
<strong>解释：</strong>
1. 10 位游客抵达，4 位登舱，6 位等待下一舱，摩天轮轮转。当前利润为 4 * $6 - 1 * $4 = $20 。
2. 9 位游客抵达，4 位登舱，11 位等待（2 位是先前就在等待的，9 位新加入等待的），摩天轮轮转。当前利润为 8 * $6 - 2 * $4 = $40 。
3. 最后 6 位游客抵达，4 位登舱，13 位等待，摩天轮轮转。当前利润为 12 * $6 - 3 * $4 = $60 。
4. 4 位登舱，9 位等待，摩天轮轮转。当前利润为 * $6 - 4 * $4 = $80 。
5. 4 位登舱，5 位等待，摩天轮轮转。当前利润为 20 * $6 - 5 * $4 = $100 。
6. 4 位登舱，1 位等待，摩天轮轮转。当前利润为 24 * $6 - 6 * $4 = $120 。
7. 1 位登舱，摩天轮轮转。当前利润为 25 * $6 - 7 * $4 = $122 。
轮转 7 次得到最大利润，最大利润为$122 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>customers = [3,4,0,5,1], boardingCost = 1, runningCost = 92
<strong>输出：</strong>-1
<strong>解释：</strong>
1. 3 位游客抵达，3 位登舱，0 位等待，摩天轮轮转。当前利润为 3 * $1 - 1 * $92 = -$89 。
2. 4 位游客抵达，4 位登舱，0 位等待，摩天轮轮转。当前利润为 7 * $1 - 2 * $92 = -$177 。
3. 0 位游客抵达，0 位登舱，0 位等待，摩天轮轮转。当前利润为 7 * $1 - 3 * $92 = -$269 。
4. 5 位游客抵达，4 位登舱，1 位等待，摩天轮轮转。当前利润为 11 * $1 - 4 * $92 = -$357 。
5. 1 位游客抵达，2 位登舱，0 位等待，摩天轮轮转。当前利润为 13 * $1 - 5 * $92 = -$447 。
利润永不为正，所以返回 -1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == customers.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= customers[i] &lt;= 50</code></li>
	<li><code>1 &lt;= boardingCost, runningCost &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们直接模拟摩天轮的轮转过程，每次轮转时，累加等待的游客以及新到达的游客，然后最多 $4$ 个人上船，更新等待的游客数和利润，记录最大利润与其对应的轮转次数。

时间复杂度 $O(n)$，其中 $n$ 为数组 `customers` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minOperationsMaxProfit(
        self, customers: List[int], boardingCost: int, runningCost: int
    ) -> int:
        ans = -1
        mx = t = 0
        wait = 0
        i = 0
        while wait or i < len(customers):
            wait += customers[i] if i < len(customers) else 0
            up = wait if wait < 4 else 4
            wait -= up
            t += up * boardingCost - runningCost
            i += 1
            if t > mx:
                mx = t
                ans = i
        return ans
```

#### Java

```java
class Solution {
    public int minOperationsMaxProfit(int[] customers, int boardingCost, int runningCost) {
        int ans = -1;
        int mx = 0, t = 0;
        int wait = 0, i = 0;
        while (wait > 0 || i < customers.length) {
            wait += i < customers.length ? customers[i] : 0;
            int up = Math.min(4, wait);
            wait -= up;
            ++i;
            t += up * boardingCost - runningCost;
            if (t > mx) {
                mx = t;
                ans = i;
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
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1;
        int mx = 0, t = 0;
        int wait = 0, i = 0;
        while (wait || i < customers.size()) {
            wait += i < customers.size() ? customers[i] : 0;
            int up = min(4, wait);
            wait -= up;
            ++i;
            t += up * boardingCost - runningCost;
            if (t > mx) {
                mx = t;
                ans = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func minOperationsMaxProfit(customers []int, boardingCost int, runningCost int) int {
	ans := -1
	t, mx := 0, 0
	wait, i := 0, 0
	for wait > 0 || i < len(customers) {
		if i < len(customers) {
			wait += customers[i]
		}
		up := min(4, wait)
		wait -= up
		t += up*boardingCost - runningCost
		i++
		if t > mx {
			mx = t
			ans = i
		}
	}
	return ans
}
```

#### TypeScript

```ts
function minOperationsMaxProfit(
    customers: number[],
    boardingCost: number,
    runningCost: number,
): number {
    let ans: number = -1;
    let [mx, t, wait, i] = [0, 0, 0, 0];
    while (wait > 0 || i < customers.length) {
        wait += i < customers.length ? customers[i] : 0;
        let up: number = Math.min(4, wait);
        wait -= up;
        ++i;
        t += up * boardingCost - runningCost;

        if (t > mx) {
            mx = t;
            ans = i;
        }
    }

    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn min_operations_max_profit(
        customers: Vec<i32>,
        boarding_cost: i32,
        running_cost: i32,
    ) -> i32 {
        let mut ans = -1;
        let mut mx = 0;
        let mut t = 0;
        let mut wait = 0;
        let mut i = 0;

        while wait > 0 || i < customers.len() {
            wait += if i < customers.len() { customers[i] } else { 0 };
            let up = std::cmp::min(4, wait);
            wait -= up;
            i += 1;
            t += up * boarding_cost - running_cost;

            if t > mx {
                mx = t;
                ans = i as i32;
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
