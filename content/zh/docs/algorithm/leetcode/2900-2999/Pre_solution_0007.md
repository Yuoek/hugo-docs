---
title: "2960_统计已测试设备"
date: 2025-10-08T18:39:48+08:00
weight: 7
tags: [二分查找, 前缀和, 动态规划, 单调队列, 哈希表, 堆（优先队列）, 排序, 数学, 数组, 模拟, 滑动窗口, 矩阵, 组合数学, 计数, 贪心, 队列]
---

{{< markmap >}}
### [2960_统计已测试设备](#2960)
#### [数组](#2960)
#### [计数](#2960)
#### [模拟](#2960)
### [2961_双模幂运算](#2961)
#### [数组](#2961)
#### [数学](#2961)
#### [模拟](#2961)
### [2962_统计最大元素出现至少 K 次的子数组](#2962)
#### [数组](#2962)
#### [滑动窗口](#2962)
### [2963_统计好分割方案的数目](#2963)
#### [数组](#2963)
#### [哈希表](#2963)
#### [数学](#2963)
#### [组合数学](#2963)
### [2964_可被整除的三元组数量 🔒](#2964)
#### [数组](#2964)
#### [哈希表](#2964)
### [2965_找出缺失和重复的数字](#2965)
#### [数组](#2965)
#### [哈希表](#2965)
#### [数学](#2965)
#### [矩阵](#2965)
### [2966_划分数组并满足最大差限制](#2966)
#### [贪心](#2966)
#### [数组](#2966)
#### [排序](#2966)
### [2967_使数组成为等数数组的最小代价](#2967)
#### [贪心](#2967)
#### [数组](#2967)
#### [数学](#2967)
#### [二分查找](#2967)
#### [排序](#2967)
### [2968_执行操作使频率分数最大](#2968)
#### [数组](#2968)
#### [二分查找](#2968)
#### [前缀和](#2968)
#### [排序](#2968)
#### [滑动窗口](#2968)
### [2969_购买水果需要的最少金币数 II 🔒](#2969)
#### [队列](#2969)
#### [数组](#2969)
#### [动态规划](#2969)
#### [单调队列](#2969)
#### [堆（优先队列）](#2969)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 2960_统计已测试设备
___
#### 数组
___
#### 计数
___
#### 模拟
---
### 2961_双模幂运算
___
#### 数组
___
#### 数学
___
#### 模拟
---
### 2962_统计最大元素出现至少 K 次的子数组
___
#### 数组
___
#### 滑动窗口
---
### 2963_统计好分割方案的数目
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 组合数学
---
### 2964_可被整除的三元组数量 🔒
___
#### 数组
___
#### 哈希表
---
### 2965_找出缺失和重复的数字
___
#### 数组
___
#### 哈希表
___
#### 数学
___
#### 矩阵
---
### 2966_划分数组并满足最大差限制
___
#### 贪心
___
#### 数组
___
#### 排序
---
### 2967_使数组成为等数数组的最小代价
___
#### 贪心
___
#### 数组
___
#### 数学
___
#### 二分查找
___
#### 排序
---
### 2968_执行操作使频率分数最大
___
#### 数组
___
#### 二分查找
___
#### 前缀和
___
#### 排序
___
#### 滑动窗口
---
### 2969_购买水果需要的最少金币数 II 🔒
___
#### 队列
___
#### 数组
___
#### 动态规划
___
#### 单调队列
___
#### 堆（优先队列）
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 前缀和 | 动态规划 |
| 单调队列 | 哈希表 | 堆（优先队列） |
| 排序 | 数学 | 数组 |
| 模拟 | 滑动窗口 | 矩阵 |
| 组合数学 | 计数 | 贪心 |
| 队列 |  |  |

# [2960. 统计已测试设备](https://leetcode.cn/problems/count-tested-devices-after-test-operations){#2960}

{{< tabs "2960" >}}

{{% tab "python" %}}
```python
class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        ans = 0
        for x in batteryPercentages:
            ans += x > ans
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countTestedDevices(int[] batteryPercentages) {
        int ans = 0;
        for (int x : batteryPercentages) {
            ans += x > ans ? 1 : 0;
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
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for (int x : batteryPercentages) {
            ans += x > ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countTestedDevices(batteryPercentages []int) (ans int) {
	for _, x := range batteryPercentages {
		if x > ans {
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countTestedDevices(batteryPercentages: number[]): number {
    let ans = 0;
    for (const x of batteryPercentages) {
        ans += x > ans ? 1 : 0;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn count_tested_devices(battery_percentages: Vec<i32>) -> i32 {
        let mut ans = 0;
        for x in battery_percentages {
            ans += if x > ans { 1 } else { 0 };
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

<p>给你一个长度为 <code>n</code> 、下标从<strong> 0 </strong>开始的整数数组 <code>batteryPercentages</code> ，表示 <code>n</code> 个设备的电池百分比。</p>

<p>你的任务是按照顺序测试每个设备 <code>i</code>，执行以下测试操作：</p>

<ul>
	<li>如果 <code>batteryPercentages[i]</code> <strong>大于</strong> <code>0</code>：

    <ul>
    	<li><strong>增加</strong> 已测试设备的计数。</li>
    	<li>将下标&nbsp;<code>j</code> 在 <code>[i + 1, n - 1]</code> 的所有设备的电池百分比减少 <code>1</code>，确保它们的电池百分比<strong> 不会低于</strong> <code>0</code> ，即 <code>batteryPercentages[j] = max(0, batteryPercentages[j] - 1)</code>。</li>
    	<li>移动到下一个设备。</li>
    </ul>
    </li>
    <li>否则，移动到下一个设备而不执行任何测试。</li>

</ul>

<p>返回一个整数，表示按顺序执行测试操作后 <strong>已测试设备</strong> 的数量。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>batteryPercentages = [1,1,2,1,3]
<strong>输出：</strong>3
<strong>解释：</strong>按顺序从设备 0 开始执行测试操作：
在设备 0 上，batteryPercentages[0] &gt; 0 ，现在有 1 个已测试设备，batteryPercentages 变为 [1,0,1,0,2] 。
在设备 1 上，batteryPercentages[1] == 0 ，移动到下一个设备而不进行测试。
在设备 2 上，batteryPercentages[2] &gt; 0 ，现在有 2 个已测试设备，batteryPercentages 变为 [1,0,1,0,1] 。
在设备 3 上，batteryPercentages[3] == 0 ，移动到下一个设备而不进行测试。
在设备 4 上，batteryPercentages[4] &gt; 0 ，现在有 3 个已测试设备，batteryPercentages 保持不变。
因此，答案是 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>batteryPercentages = [0,1,2]
<strong>输出：</strong>2
<strong>解释：</strong>按顺序从设备 0 开始执行测试操作：
在设备 0 上，batteryPercentages[0] == 0 ，移动到下一个设备而不进行测试。
在设备 1 上，batteryPercentages[1] &gt; 0 ，现在有 1 个已测试设备，batteryPercentages 变为 [0,1,1] 。
在设备 2 上，batteryPercentages[2] &gt; 0 ，现在有 2 个已测试设备，batteryPercentages 保持不变。
因此，答案是 2 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n == batteryPercentages.length &lt;= 100 </code></li>
	<li><code>0 &lt;= batteryPercentages[i] &lt;= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

假设我们当前已测试的设备数量为 $ans$，当测试新的一台设备 $i$ 时，它的剩余电量为 $\max(0, batteryPercentages[i] - ans)$，如果剩余电量大于 $0$，则说明这台设备可以进行测试，此时我们需要将 $ans$ 增加 $1$。

最后返回 $ans$ 即可。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        ans = 0
        for x in batteryPercentages:
            ans += x > ans
        return ans
```

#### Java

```java
class Solution {
    public int countTestedDevices(int[] batteryPercentages) {
        int ans = 0;
        for (int x : batteryPercentages) {
            ans += x > ans ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for (int x : batteryPercentages) {
            ans += x > ans;
        }
        return ans;
    }
};
```

#### Go

```go
func countTestedDevices(batteryPercentages []int) (ans int) {
	for _, x := range batteryPercentages {
		if x > ans {
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countTestedDevices(batteryPercentages: number[]): number {
    let ans = 0;
    for (const x of batteryPercentages) {
        ans += x > ans ? 1 : 0;
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn count_tested_devices(battery_percentages: Vec<i32>) -> i32 {
        let mut ans = 0;
        for x in battery_percentages {
            ans += if x > ans { 1 } else { 0 };
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

# [2961. 双模幂运算](https://leetcode.cn/problems/double-modular-exponentiation){#2961}

{{< tabs "2961" >}}

{{% tab "python" %}}
```python
class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        return [
            i
            for i, (a, b, c, m) in enumerate(variables)
            if pow(pow(a, b, 10), c, m) == target
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < variables.length; ++i) {
            var e = variables[i];
            int a = e[0], b = e[1], c = e[2], m = e[3];
            if (qpow(qpow(a, b, 10), c, m) == target) {
                ans.add(i);
            }
        }
        return ans;
    }

    private int qpow(long a, int n, int mod) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        auto qpow = [&](long long a, int n, int mod) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        for (int i = 0; i < variables.size(); ++i) {
            auto e = variables[i];
            int a = e[0], b = e[1], c = e[2], m = e[3];
            if (qpow(qpow(a, b, 10), c, m) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func getGoodIndices(variables [][]int, target int) (ans []int) {
	qpow := func(a, n, mod int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	for i, e := range variables {
		a, b, c, m := e[0], e[1], e[2], e[3]
		if qpow(qpow(a, b, 10), c, m) == target {
			ans = append(ans, i)
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function getGoodIndices(variables: number[][], target: number): number[] {
    const qpow = (a: number, n: number, mod: number) => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    const ans: number[] = [];
    for (let i = 0; i < variables.length; ++i) {
        const [a, b, c, m] = variables[i];
        if (qpow(qpow(a, b, 10), c, m) === target) {
            ans.push(i);
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

<p>给你一个下标从 <strong>0 </strong>开始的二维数组 <code>variables</code> ，其中 <code>variables[i] = [a<sub>i</sub>, b<sub>i</sub>, c<sub>i,</sub> m<sub>i</sub>]</code>，以及一个整数 <code>target</code> 。</p>

<p>如果满足以下公式，则下标 <code>i</code> 是 <strong>好下标</strong>：</p>

<ul>
	<li><code>0 &lt;= i &lt; variables.length</code></li>
	<li><code>((a<sub>i</sub><sup>b<sub>i</sub></sup> % 10)<sup>c<sub>i</sub></sup>) % m<sub>i</sub> == target</code></li>
</ul>

<p>返回一个由<strong> 好下标 </strong>组成的数组，<strong>顺序不限</strong> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>variables = [[2,3,3,10],[3,3,3,1],[6,1,1,4]], target = 2
<strong>输出：</strong>[0,2]
<strong>解释：</strong>对于 variables 数组中的每个下标 i ：
1) 对于下标 0 ，variables[0] = [2,3,3,10] ，(2<sup>3</sup> % 10)<sup>3</sup> % 10 = 2 。
2) 对于下标 1 ，variables[1] = [3,3,3,1] ，(3<sup>3</sup> % 10)<sup>3</sup> % 1 = 0 。
3) 对于下标 2 ，variables[2] = [6,1,1,4] ，(6<sup>1</sup> % 10)<sup>1</sup> % 4 = 2 。
因此，返回 [0,2] 作为答案。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>variables = [[39,3,1000,1000]], target = 17
<strong>输出：</strong>[]
<strong>解释：</strong>对于 variables 数组中的每个下标 i ：
1) 对于下标 0 ，variables[0] = [39,3,1000,1000] ，(39<sup>3</sup> % 10)<sup>1000</sup> % 1000 = 1 。
因此，返回 [] 作为答案。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= variables.length &lt;= 100</code></li>
	<li><code>variables[i] == [a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, m<sub>i</sub>]</code></li>
	<li><code>1 &lt;= a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, m<sub>i</sub> &lt;= 10<sup>3</sup></code></li>
	<li><code><font face="monospace">0 &lt;= target &lt;= 10<sup>3</sup></font></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟 + 快速幂

我们直接根据题目描述模拟即可。对于幂运算取模，我们可以使用快速幂来加速运算。

时间复杂度 $O(n \times \log M)$，其中 $n$ 为数组 $variables$ 的长度；而 $M$ 为 $b_i$ 和 $c_i$ 中的最大值，本题中 $M \le 10^3$。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        return [
            i
            for i, (a, b, c, m) in enumerate(variables)
            if pow(pow(a, b, 10), c, m) == target
        ]
```

#### Java

```java
class Solution {
    public List<Integer> getGoodIndices(int[][] variables, int target) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < variables.length; ++i) {
            var e = variables[i];
            int a = e[0], b = e[1], c = e[2], m = e[3];
            if (qpow(qpow(a, b, 10), c, m) == target) {
                ans.add(i);
            }
        }
        return ans;
    }

    private int qpow(long a, int n, int mod) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        auto qpow = [&](long long a, int n, int mod) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        for (int i = 0; i < variables.size(); ++i) {
            auto e = variables[i];
            int a = e[0], b = e[1], c = e[2], m = e[3];
            if (qpow(qpow(a, b, 10), c, m) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func getGoodIndices(variables [][]int, target int) (ans []int) {
	qpow := func(a, n, mod int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	for i, e := range variables {
		a, b, c, m := e[0], e[1], e[2], e[3]
		if qpow(qpow(a, b, 10), c, m) == target {
			ans = append(ans, i)
		}
	}
	return
}
```

#### TypeScript

```ts
function getGoodIndices(variables: number[][], target: number): number[] {
    const qpow = (a: number, n: number, mod: number) => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    const ans: number[] = [];
    for (let i = 0; i < variables.length; ++i) {
        const [a, b, c, m] = variables[i];
        if (qpow(qpow(a, b, 10), c, m) === target) {
            ans.push(i);
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

# [2962. 统计最大元素出现至少 K 次的子数组](https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times){#2962}

{{< tabs "2962" >}}

{{% tab "python" %}}
```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        n = len(nums)
        ans = cnt = j = 0
        for x in nums:
            while j < n and cnt < k:
                cnt += nums[j] == mx
                j += 1
            if cnt < k:
                break
            ans += n - j + 1
            cnt -= x == mx
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public long countSubarrays(int[] nums, int k) {
        int mx = Arrays.stream(nums).max().getAsInt();
        int n = nums.length;
        long ans = 0;
        int cnt = 0, j = 0;
        for (int x : nums) {
            while (j < n && cnt < k) {
                cnt += nums[j++] == mx ? 1 : 0;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            cnt -= x == mx ? 1 : 0;
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
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int cnt = 0, j = 0;
        for (int x : nums) {
            while (j < n && cnt < k) {
                cnt += nums[j++] == mx;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            cnt -= x == mx;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countSubarrays(nums []int, k int) (ans int64) {
	mx := slices.Max(nums)
	n := len(nums)
	cnt, j := 0, 0
	for _, x := range nums {
		for ; j < n && cnt < k; j++ {
			if nums[j] == mx {
				cnt++
			}
		}
		if cnt < k {
			break
		}
		ans += int64(n - j + 1)
		if x == mx {
			cnt--
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countSubarrays(nums: number[], k: number): number {
    const mx = Math.max(...nums);
    const n = nums.length;
    let [cnt, j] = [0, 0];
    let ans = 0;
    for (const x of nums) {
        for (; j < n && cnt < k; ++j) {
            cnt += nums[j] === mx ? 1 : 0;
        }
        if (cnt < k) {
            break;
        }
        ans += n - j + 1;
        cnt -= x === mx ? 1 : 0;
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

<p>给你一个整数数组 <code>nums</code> 和一个 <strong>正整数</strong> <code>k</code> 。</p>

<p>请你统计有多少满足 「&nbsp;<code>nums</code> 中的 <strong>最大</strong> 元素」至少出现 <code>k</code> 次的子数组，并返回满足这一条件的子数组的数目。</p>

<p>子数组是数组中的一个连续元素序列。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,3,3], k = 2
<strong>输出：</strong>6
<strong>解释：</strong>包含元素 3 至少 2 次的子数组为：[1,3,2,3]、[1,3,2,3,3]、[3,2,3]、[3,2,3,3]、[2,3,3] 和 [3,3] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,2,1], k = 3
<strong>输出：</strong>0
<strong>解释：</strong>没有子数组包含元素 4 至少 3 次。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

不妨记数组中的最大值为 $mx$。

我们用两个指针 $i$ 和 $j$ 维护一个滑动窗口，使得 $[i, j)$ 之间的子数组中，有 $k$ 个元素等于 $mx$。如果我们固定左端点 $i$，那么所有大于等于 $j-1$ 的右端点都满足条件，一共有 $n - (j - 1)$ 个。

因此，我们枚举左端点 $i$，用指针 $j$ 维护右端点，用一个变量 $cnt$ 记录当前窗口中等于 $mx$ 的元素个数，当 $cnt$ 大于等于 $k$ 时，我们就找到了满足条件的子数组，将答案增加 $n - (j - 1)$。然后我们更新 $cnt$，继续枚举下一个左端点。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx = max(nums)
        n = len(nums)
        ans = cnt = j = 0
        for x in nums:
            while j < n and cnt < k:
                cnt += nums[j] == mx
                j += 1
            if cnt < k:
                break
            ans += n - j + 1
            cnt -= x == mx
        return ans
```

#### Java

```java
class Solution {
    public long countSubarrays(int[] nums, int k) {
        int mx = Arrays.stream(nums).max().getAsInt();
        int n = nums.length;
        long ans = 0;
        int cnt = 0, j = 0;
        for (int x : nums) {
            while (j < n && cnt < k) {
                cnt += nums[j++] == mx ? 1 : 0;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            cnt -= x == mx ? 1 : 0;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        int cnt = 0, j = 0;
        for (int x : nums) {
            while (j < n && cnt < k) {
                cnt += nums[j++] == mx;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            cnt -= x == mx;
        }
        return ans;
    }
};
```

#### Go

```go
func countSubarrays(nums []int, k int) (ans int64) {
	mx := slices.Max(nums)
	n := len(nums)
	cnt, j := 0, 0
	for _, x := range nums {
		for ; j < n && cnt < k; j++ {
			if nums[j] == mx {
				cnt++
			}
		}
		if cnt < k {
			break
		}
		ans += int64(n - j + 1)
		if x == mx {
			cnt--
		}
	}
	return
}
```

#### TypeScript

```ts
function countSubarrays(nums: number[], k: number): number {
    const mx = Math.max(...nums);
    const n = nums.length;
    let [cnt, j] = [0, 0];
    let ans = 0;
    for (const x of nums) {
        for (; j < n && cnt < k; ++j) {
            cnt += nums[j] === mx ? 1 : 0;
        }
        if (cnt < k) {
            break;
        }
        ans += n - j + 1;
        cnt -= x === mx ? 1 : 0;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2963. 统计好分割方案的数目](https://leetcode.cn/problems/count-the-number-of-good-partitions){#2963}

{{< tabs "2963" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfGoodPartitions(self, nums: List[int]) -> int:
        last = {x: i for i, x in enumerate(nums)}
        mod = 10**9 + 7
        j, k = -1, 0
        for i, x in enumerate(nums):
            j = max(j, last[x])
            k += i == j
        return pow(2, k - 1, mod)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfGoodPartitions(int[] nums) {
        Map<Integer, Integer> last = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            last.put(nums[i], i);
        }
        final int mod = (int) 1e9 + 7;
        int j = -1;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            j = Math.max(j, last.get(nums[i]));
            k += i == j ? 1 : 0;
        }
        return qpow(2, k - 1, mod);
    }

    private int qpow(long a, int n, int mod) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> last;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            last[nums[i]] = i;
        }
        const int mod = 1e9 + 7;
        int j = -1, k = 0;
        for (int i = 0; i < n; ++i) {
            j = max(j, last[nums[i]]);
            k += i == j;
        }
        auto qpow = [&](long long a, int n, int mod) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        return qpow(2, k - 1, mod);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfGoodPartitions(nums []int) int {
	qpow := func(a, n, mod int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	last := map[int]int{}
	for i, x := range nums {
		last[x] = i
	}
	const mod int = 1e9 + 7
	j, k := -1, 0
	for i, x := range nums {
		j = max(j, last[x])
		if i == j {
			k++
		}
	}
	return qpow(2, k-1, mod)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfGoodPartitions(nums: number[]): number {
    const qpow = (a: number, n: number, mod: number) => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    const last: Map<number, number> = new Map();
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        last.set(nums[i], i);
    }
    const mod = 1e9 + 7;
    let [j, k] = [-1, 0];
    for (let i = 0; i < n; ++i) {
        j = Math.max(j, last.get(nums[i])!);
        if (i === j) {
            ++k;
        }
    }
    return qpow(2, k - 1, mod);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、由 <strong>正整数</strong> 组成的数组 <code>nums</code>。</p>

<p>将数组分割成一个或多个<strong> 连续</strong> 子数组，如果不存在包含了相同数字的两个子数组，则认为是一种 <strong>好分割方案</strong> 。</p>

<p>返回 <code>nums</code> 的 <strong>好分割方案</strong> 的 <strong>数目</strong>。</p>

<p>由于答案可能很大，请返回答案对 <code>10<sup>9</sup> + 7</code> <strong>取余</strong> 的结果。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>8
<strong>解释：</strong>有 8 种 <strong>好分割方案 </strong>：([1], [2], [3], [4]), ([1], [2], [3,4]), ([1], [2,3], [4]), ([1], [2,3,4]), ([1,2], [3], [4]), ([1,2], [3,4]), ([1,2,3], [4]) 和 ([1,2,3,4]) 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,1,1,1]
<strong>输出：</strong>1
<strong>解释：</strong>唯一的 <strong>好分割方案</strong> 是：([1,1,1,1]) 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,1,3]
<strong>输出：</strong>2
<strong>解释：</strong>有 2 种<strong> 好分割方案 </strong>：([1,2,1], [3]) 和 ([1,2,1,3]) 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 分组 + 快速幂

根据题目描述，我们可以知道，相同的数字必须在同一个子数组中。因此，我们用一个哈希表 $last$ 记录每个数字最后一次出现的下标。

接下来，我们用一个下标 $j$ 标识已经出现过的元素中最后一个元素的下标，用一个变量 $k$ 记录当前可以划分的子数组的个数。

然后，我们从左到右遍历数组 $nums$，对于当前遍历到的数字 $nums[i]$，我们获取其最后一次出现的下标，更新 $j = \max(j, last[nums[i]])$。如果 $i = j$，那么说明当前位置可以是一个子数组的结尾，我们将 $k$ 增加 $1$。继续遍历，直到遍历完整个数组。

最后，我们考虑 $k$ 个子数组的划分方案数。子数组数量为 $k$，有 $k-1$ 个位置可以划分（拼接），因此方案数为 $2^{k-1}$。由于答案可能很大，我们需要对 $10^9 + 7$ 取模。这里我们可以使用快速幂来加速运算。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfGoodPartitions(self, nums: List[int]) -> int:
        last = {x: i for i, x in enumerate(nums)}
        mod = 10**9 + 7
        j, k = -1, 0
        for i, x in enumerate(nums):
            j = max(j, last[x])
            k += i == j
        return pow(2, k - 1, mod)
```

#### Java

```java
class Solution {
    public int numberOfGoodPartitions(int[] nums) {
        Map<Integer, Integer> last = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            last.put(nums[i], i);
        }
        final int mod = (int) 1e9 + 7;
        int j = -1;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            j = Math.max(j, last.get(nums[i]));
            k += i == j ? 1 : 0;
        }
        return qpow(2, k - 1, mod);
    }

    private int qpow(long a, int n, int mod) {
        long ans = 1;
        for (; n > 0; n >>= 1) {
            if ((n & 1) == 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
        }
        return (int) ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> last;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            last[nums[i]] = i;
        }
        const int mod = 1e9 + 7;
        int j = -1, k = 0;
        for (int i = 0; i < n; ++i) {
            j = max(j, last[nums[i]]);
            k += i == j;
        }
        auto qpow = [&](long long a, int n, int mod) {
            long long ans = 1;
            for (; n; n >>= 1) {
                if (n & 1) {
                    ans = ans * a % mod;
                }
                a = a * a % mod;
            }
            return (int) ans;
        };
        return qpow(2, k - 1, mod);
    }
};
```

#### Go

```go
func numberOfGoodPartitions(nums []int) int {
	qpow := func(a, n, mod int) int {
		ans := 1
		for ; n > 0; n >>= 1 {
			if n&1 == 1 {
				ans = ans * a % mod
			}
			a = a * a % mod
		}
		return ans
	}
	last := map[int]int{}
	for i, x := range nums {
		last[x] = i
	}
	const mod int = 1e9 + 7
	j, k := -1, 0
	for i, x := range nums {
		j = max(j, last[x])
		if i == j {
			k++
		}
	}
	return qpow(2, k-1, mod)
}
```

#### TypeScript

```ts
function numberOfGoodPartitions(nums: number[]): number {
    const qpow = (a: number, n: number, mod: number) => {
        let ans = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                ans = Number((BigInt(ans) * BigInt(a)) % BigInt(mod));
            }
            a = Number((BigInt(a) * BigInt(a)) % BigInt(mod));
        }
        return ans;
    };
    const last: Map<number, number> = new Map();
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        last.set(nums[i], i);
    }
    const mod = 1e9 + 7;
    let [j, k] = [-1, 0];
    for (let i = 0; i < n; ++i) {
        j = Math.max(j, last.get(nums[i])!);
        if (i === j) {
            ++k;
        }
    }
    return qpow(2, k - 1, mod);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2964. 可被整除的三元组数量 🔒](https://leetcode.cn/problems/number-of-divisible-triplet-sums){#2964}

{{< tabs "2964" >}}

{{% tab "python" %}}
```python
class Solution:
    def divisibleTripletCount(self, nums: List[int], d: int) -> int:
        cnt = defaultdict(int)
        ans, n = 0, len(nums)
        for j in range(n):
            for k in range(j + 1, n):
                x = (d - (nums[j] + nums[k]) % d) % d
                ans += cnt[x]
            cnt[nums[j] % d] += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int divisibleTripletCount(int[] nums, int d) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0, n = nums.length;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x = (d - (nums[j] + nums[k]) % d) % d;
                ans += cnt.getOrDefault(x, 0);
            }
            cnt.merge(nums[j] % d, 1, Integer::sum);
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
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, int> cnt;
        int ans = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x = (d - (nums[j] + nums[k]) % d) % d;
                ans += cnt[x];
            }
            cnt[nums[j] % d]++;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func divisibleTripletCount(nums []int, d int) (ans int) {
	n := len(nums)
	cnt := map[int]int{}
	for j := 0; j < n; j++ {
		for k := j + 1; k < n; k++ {
			x := (d - (nums[j]+nums[k])%d) % d
			ans += cnt[x]
		}
		cnt[nums[j]%d]++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function divisibleTripletCount(nums: number[], d: number): number {
    const n = nums.length;
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let j = 0; j < n; ++j) {
        for (let k = j + 1; k < n; ++k) {
            const x = (d - ((nums[j] + nums[k]) % d)) % d;
            ans += cnt.get(x) || 0;
        }
        cnt.set(nums[j] % d, (cnt.get(nums[j] % d) || 0) + 1);
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

给定一个 <b>下标从 0 开始</b>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>d</code>，请返回满足 <code>i &lt; j &lt; k</code> 且 <code>(nums[i] + nums[j] + nums[k]) % d == 0</code> 的三元组 <code>(i, j, k)</code> 的数量。

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<strong>输入：</strong>nums = [3,3,4,7,8], d = 5
<strong>输出：</strong>3
<strong>解释：</strong>可以被5整除的三元组有：(0, 1, 2),(0, 2, 4),(1, 2, 4)。其他没有其他能被5整除的三元组。因此，答案是3。
</pre>

<p><b>示例 2：</b></p>

<pre>
<strong>输入：</strong>nums = [3,3,3,3], d = 3
<strong>输出：</strong>4
<strong>解释：</strong>这里选择的任何三元组的和都是9，可以被3整除。因此，答案是所有三元组的总数，即4。
</pre>

<p><b>示例 3:</b></p>

<pre>
<strong>输入：</strong>nums = [3,3,3,3], d = 6
<strong>输出：</strong>0
<strong>解释：</strong>这里选择的任何三元组的和都是9，不能被6整除。因此，答案是0。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= d &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 枚举

我们可以用哈希表 $cnt$ 记录 $nums[i] \bmod d$ 出现的次数，然后枚举 $j$ 和 $k$，计算使得等式 $(nums[i] + nums[j] + nums[k]) \bmod d = 0$ 成立的 $nums[i] \bmod d$ 的值，即 $(d - (nums[j] + nums[k]) \bmod d) \bmod d$，并将其出现次数累加到答案中。然后我们将 $nums[j] \bmod d$ 的出现次数加一。继续枚举 $j$ 和 $k$，直到 $j$ 到达数组末尾。

时间复杂度 $O(n^2)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divisibleTripletCount(self, nums: List[int], d: int) -> int:
        cnt = defaultdict(int)
        ans, n = 0, len(nums)
        for j in range(n):
            for k in range(j + 1, n):
                x = (d - (nums[j] + nums[k]) % d) % d
                ans += cnt[x]
            cnt[nums[j] % d] += 1
        return ans
```

#### Java

```java
class Solution {
    public int divisibleTripletCount(int[] nums, int d) {
        Map<Integer, Integer> cnt = new HashMap<>();
        int ans = 0, n = nums.length;
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x = (d - (nums[j] + nums[k]) % d) % d;
                ans += cnt.getOrDefault(x, 0);
            }
            cnt.merge(nums[j] % d, 1, Integer::sum);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, int> cnt;
        int ans = 0, n = nums.size();
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x = (d - (nums[j] + nums[k]) % d) % d;
                ans += cnt[x];
            }
            cnt[nums[j] % d]++;
        }
        return ans;
    }
};
```

#### Go

```go
func divisibleTripletCount(nums []int, d int) (ans int) {
	n := len(nums)
	cnt := map[int]int{}
	for j := 0; j < n; j++ {
		for k := j + 1; k < n; k++ {
			x := (d - (nums[j]+nums[k])%d) % d
			ans += cnt[x]
		}
		cnt[nums[j]%d]++
	}
	return
}
```

#### TypeScript

```ts
function divisibleTripletCount(nums: number[], d: number): number {
    const n = nums.length;
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let j = 0; j < n; ++j) {
        for (let k = j + 1; k < n; ++k) {
            const x = (d - ((nums[j] + nums[k]) % d)) % d;
            ans += cnt.get(x) || 0;
        }
        cnt.set(nums[j] % d, (cnt.get(nums[j] % d) || 0) + 1);
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2965. 找出缺失和重复的数字](https://leetcode.cn/problems/find-missing-and-repeated-values){#2965}

{{< tabs "2965" >}}

{{% tab "python" %}}
```python
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        cnt = [0] * (n * n + 1)
        for row in grid:
            for v in row:
                cnt[v] += 1
        ans = [0] * 2
        for i in range(1, n * n + 1):
            if cnt[i] == 2:
                ans[0] = i
            if cnt[i] == 0:
                ans[1] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int[] cnt = new int[n * n + 1];
        int[] ans = new int[2];
        for (int[] row : grid) {
            for (int x : row) {
                if (++cnt[x] == 2) {
                    ans[0] = x;
                }
            }
        }
        for (int x = 1;; ++x) {
            if (cnt[x] == 0) {
                ans[1] = x;
                return ans;
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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n * n + 1);
        vector<int> ans(2);
        for (auto& row : grid) {
            for (int x : row) {
                if (++cnt[x] == 2) {
                    ans[0] = x;
                }
            }
        }
        for (int x = 1;; ++x) {
            if (cnt[x] == 0) {
                ans[1] = x;
                return ans;
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findMissingAndRepeatedValues(grid [][]int) []int {
	n := len(grid)
	ans := make([]int, 2)
	cnt := make([]int, n*n+1)
	for _, row := range grid {
		for _, x := range row {
			cnt[x]++
			if cnt[x] == 2 {
				ans[0] = x
			}
		}
	}
	for x := 1; ; x++ {
		if cnt[x] == 0 {
			ans[1] = x
			return ans
		}
	}
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findMissingAndRepeatedValues(grid: number[][]): number[] {
    const n = grid.length;
    const cnt: number[] = Array(n * n + 1).fill(0);
    const ans: number[] = Array(2).fill(0);
    for (const row of grid) {
        for (const x of row) {
            if (++cnt[x] === 2) {
                ans[0] = x;
            }
        }
    }
    for (let x = 1; ; ++x) {
        if (cnt[x] === 0) {
            ans[1] = x;
            return ans;
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

<p>给你一个下标从<strong> 0 </strong>开始的二维整数矩阵 <code><font face="monospace">grid</font></code>，大小为 <code>n * n</code> ，其中的值在 <code>[1, n<sup>2</sup>]</code> 范围内。除了 <code>a</code> 出现 <strong>两次</strong>，<code>b</code> <strong>缺失</strong> 之外，每个整数都<strong> 恰好出现一次</strong> 。</p>

<p>任务是找出重复的数字<code>a</code> 和缺失的数字 <code>b</code> 。</p>

<p>返回一个下标从 0 开始、长度为 <code>2</code> 的整数数组 <code>ans</code> ，其中 <code>ans[0]</code> 等于 <code>a</code> ，<code>ans[1]</code> 等于 <code>b</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>grid = [[1,3],[2,2]]
<strong>输出：</strong>[2,4]
<strong>解释：</strong>数字 2 重复，数字 4 缺失，所以答案是 [2,4] 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>grid = [[9,1,7],[8,9,2],[3,4,6]]
<strong>输出：</strong>[9,5]
<strong>解释：</strong>数字 9 重复，数字 5 缺失，所以答案是 [9,5] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == grid.length == grid[i].length &lt;= 50</code></li>
	<li><code>1 &lt;= grid[i][j] &lt;= n * n</code></li>
	<li>对于所有满足<code>1 &lt;= x &lt;= n * n</code> 的 <code>x</code> ，恰好存在一个 <code>x</code> 与矩阵中的任何成员都不相等。</li>
	<li>对于所有满足<code>1 &lt;= x &lt;= n * n</code> 的 <code>x</code> ，恰好存在一个 <code>x</code> 与矩阵中的两个成员相等。</li>
	<li>除上述的两个之外，对于所有满足<code>1 &lt;= x &lt;= n * n</code> 的 <code>x</code> ，都恰好存在一对 <code>i, j</code> 满足 <code>0 &lt;= i, j &lt;= n - 1</code> 且 <code>grid[i][j] == x</code> 。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：计数

我们创建一个长度为 $n^2 + 1$ 的数组 $cnt$，统计矩阵中每个数字出现的次数。

接下来遍历 $i \in [1, n^2]$，如果 $cnt[i] = 2$，则 $i$ 是重复的数字，我们将答案的第一个元素设为 $i$；如果 $cnt[i] = 0$，则 $i$ 是缺失的数字，我们将答案的第二个元素设为 $i$。

时间复杂度 $O(n^2)$，空间复杂度 $O(n^2)$。其中 $n$ 是矩阵的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        cnt = [0] * (n * n + 1)
        for row in grid:
            for v in row:
                cnt[v] += 1
        ans = [0] * 2
        for i in range(1, n * n + 1):
            if cnt[i] == 2:
                ans[0] = i
            if cnt[i] == 0:
                ans[1] = i
        return ans
```

#### Java

```java
class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        int[] cnt = new int[n * n + 1];
        int[] ans = new int[2];
        for (int[] row : grid) {
            for (int x : row) {
                if (++cnt[x] == 2) {
                    ans[0] = x;
                }
            }
        }
        for (int x = 1;; ++x) {
            if (cnt[x] == 0) {
                ans[1] = x;
                return ans;
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> cnt(n * n + 1);
        vector<int> ans(2);
        for (auto& row : grid) {
            for (int x : row) {
                if (++cnt[x] == 2) {
                    ans[0] = x;
                }
            }
        }
        for (int x = 1;; ++x) {
            if (cnt[x] == 0) {
                ans[1] = x;
                return ans;
            }
        }
    }
};
```

#### Go

```go
func findMissingAndRepeatedValues(grid [][]int) []int {
	n := len(grid)
	ans := make([]int, 2)
	cnt := make([]int, n*n+1)
	for _, row := range grid {
		for _, x := range row {
			cnt[x]++
			if cnt[x] == 2 {
				ans[0] = x
			}
		}
	}
	for x := 1; ; x++ {
		if cnt[x] == 0 {
			ans[1] = x
			return ans
		}
	}
}
```

#### TypeScript

```ts
function findMissingAndRepeatedValues(grid: number[][]): number[] {
    const n = grid.length;
    const cnt: number[] = Array(n * n + 1).fill(0);
    const ans: number[] = Array(2).fill(0);
    for (const row of grid) {
        for (const x of row) {
            if (++cnt[x] === 2) {
                ans[0] = x;
            }
        }
    }
    for (let x = 1; ; ++x) {
        if (cnt[x] === 0) {
            ans[1] = x;
            return ans;
        }
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2966. 划分数组并满足最大差限制](https://leetcode.cn/problems/divide-array-into-arrays-with-max-difference){#2966}

{{< tabs "2966" >}}

{{% tab "python" %}}
```python
class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(0, n, 3):
            t = nums[i : i + 3]
            if t[2] - t[0] > k:
                return []
            ans.append(t)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int[][] ans = new int[n / 3][];
        for (int i = 0; i < n; i += 3) {
            int[] t = Arrays.copyOfRange(nums, i, i + 3);
            if (t[2] - t[0] > k) {
                return new int[][] {};
            }
            ans[i / 3] = t;
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
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            vector<int> t = {nums[i], nums[i + 1], nums[i + 2]};
            if (t[2] - t[0] > k) {
                return {};
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func divideArray(nums []int, k int) [][]int {
	sort.Ints(nums)
	ans := [][]int{}
	for i := 0; i < len(nums); i += 3 {
		t := slices.Clone(nums[i : i+3])
		if t[2]-t[0] > k {
			return [][]int{}
		}
		ans = append(ans, t)
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function divideArray(nums: number[], k: number): number[][] {
    nums.sort((a, b) => a - b);
    const ans: number[][] = [];
    for (let i = 0; i < nums.length; i += 3) {
        const t = nums.slice(i, i + 3);
        if (t[2] - t[0] > k) {
            return [];
        }
        ans.push(t);
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "swift" %}}
```swift
class Solution {
    func divideArray(_ nums: [Int], _ k: Int) -> [[Int]] {
        var sortedNums = nums.sorted()
        var ans: [[Int]] = []

        for i in stride(from: 0, to: sortedNums.count, by: 3) {
            if i + 2 >= sortedNums.count {
                return []
            }

            let t = Array(sortedNums[i..<i+3])
            if t[2] - t[0] > k {
                return []
            }

            ans.append(t)
        }

        return ans
    }
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        nums.sort();
        let mut ans = Vec::new();
        let n = nums.len();

        for i in (0..n).step_by(3) {
            if i + 2 >= n {
                return vec![];
            }

            let t = &nums[i..i+3];
            if t[2] - t[0] > k {
                return vec![];
            }

            ans.push(t.to_vec());
        }

        ans
    }
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        Array.Sort(nums);
        List<int[]> ans = new List<int[]>();

        for (int i = 0; i < nums.Length; i += 3) {
            if (i + 2 >= nums.Length) {
                return new int[0][];
            }

            int[] t = new int[] { nums[i], nums[i + 1], nums[i + 2] };
            if (t[2] - t[0] > k) {
                return new int[0][];
            }

            ans.Add(t);
        }

        return ans.ToArray();
    }
}
```
{{% /tab %}}
{{% tab "dart" %}}
```dart
class Solution {
  List<List<int>> divideArray(List<int> nums, int k) {
    nums.sort();
    List<List<int>> ans = [];

    for (int i = 0; i < nums.length; i += 3) {
      if (i + 2 >= nums.length) {
        return [];
      }

      List<int> t = nums.sublist(i, i + 3);
      if (t[2] - t[0] > k) {
        return [];
      }

      ans.add(t);
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

<p>给你一个长度为 <code>n</code> 的整数数组 <code>nums</code>，以及一个正整数 <code>k</code> 。</p>

<p>将这个数组划分为&nbsp;<code>n / 3</code>&nbsp;个长度为 <code>3</code> 的子数组，并满足以下条件：</p>

<ul>
	<li>子数组中<strong> 任意 </strong>两个元素的差必须 <strong>小于或等于</strong> <code>k</code> 。</li>
</ul>

<p>返回一个<em> </em><strong>二维数组 </strong>，包含所有的子数组。如果不可能满足条件，就返回一个空数组。如果有多个答案，返回 <strong>任意一个</strong> 即可。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b>nums = [1,3,4,8,7,9,3,5,1], k = 2</span></p>

<p><span class="example-io"><b>输出：</b>[[1,1,3],[3,4,5],[7,8,9]]</span></p>

<p><strong>解释：</strong></p>

<p>每个数组中任何两个元素之间的差小于或等于 2。</p>
</div>

<p><strong class="example">示例 2：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [2,4,2,2,5,2], k = 2</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">[]</span></p>

<p><strong>解释：</strong></p>

<p>将&nbsp;<code>nums</code>&nbsp;划分为 2 个长度为 3 的数组的不同方式有：</p>

<ul>
	<li>[[2,2,2],[2,4,5]] （及其排列）</li>
	<li>[[2,2,4],[2,2,5]] （及其排列）</li>
</ul>

<p>因为有四个 2，所以无论我们如何划分，都会有一个包含元素 2 和 5 的数组。因为&nbsp;<code>5 - 2 = 3 &gt; k</code>，条件无法被满足，所以没有合法的划分。</p>
</div>

<p><strong class="example">示例 3：</strong></p>

<div class="example-block">
<p><span class="example-io"><b>输入：</b></span><span class="example-io">nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14</span></p>

<p><span class="example-io"><b>输出：</b></span><span class="example-io">[[2,2,2],[4,5,5],[5,5,7],[7,8,8],[9,9,10],[11,12,12]]</span></p>

<p><strong>解释：</strong></p>

<p>每个数组中任何两个元素之间的差小于或等于 14。</p>
</div>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>n</code> 是 <code>3</code> 的倍数</li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

我们先对数组进行排序，然后每次取出三个元素，如果这三个元素的最大值和最小值的差大于 $k$，则无法满足条件，返回空数组。否则，我们将这三个元素组成的数组加入答案数组中。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(0, n, 3):
            t = nums[i : i + 3]
            if t[2] - t[0] > k:
                return []
            ans.append(t)
        return ans
```

#### Java

```java
class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int[][] ans = new int[n / 3][];
        for (int i = 0; i < n; i += 3) {
            int[] t = Arrays.copyOfRange(nums, i, i + 3);
            if (t[2] - t[0] > k) {
                return new int[][] {};
            }
            ans[i / 3] = t;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            vector<int> t = {nums[i], nums[i + 1], nums[i + 2]};
            if (t[2] - t[0] > k) {
                return {};
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
```

#### Go

```go
func divideArray(nums []int, k int) [][]int {
	sort.Ints(nums)
	ans := [][]int{}
	for i := 0; i < len(nums); i += 3 {
		t := slices.Clone(nums[i : i+3])
		if t[2]-t[0] > k {
			return [][]int{}
		}
		ans = append(ans, t)
	}
	return ans
}
```

#### TypeScript

```ts
function divideArray(nums: number[], k: number): number[][] {
    nums.sort((a, b) => a - b);
    const ans: number[][] = [];
    for (let i = 0; i < nums.length; i += 3) {
        const t = nums.slice(i, i + 3);
        if (t[2] - t[0] > k) {
            return [];
        }
        ans.push(t);
    }
    return ans;
}
```

#### Swift

```swift
class Solution {
    func divideArray(_ nums: [Int], _ k: Int) -> [[Int]] {
        var sortedNums = nums.sorted()
        var ans: [[Int]] = []

        for i in stride(from: 0, to: sortedNums.count, by: 3) {
            if i + 2 >= sortedNums.count {
                return []
            }

            let t = Array(sortedNums[i..<i+3])
            if t[2] - t[0] > k {
                return []
            }

            ans.append(t)
        }

        return ans
    }
}
```

#### Rust

```rust
impl Solution {
    pub fn divide_array(mut nums: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        nums.sort();
        let mut ans = Vec::new();
        let n = nums.len();

        for i in (0..n).step_by(3) {
            if i + 2 >= n {
                return vec![];
            }

            let t = &nums[i..i+3];
            if t[2] - t[0] > k {
                return vec![];
            }

            ans.push(t.to_vec());
        }

        ans
    }
}
```

#### C#

```cs
public class Solution {
    public int[][] DivideArray(int[] nums, int k) {
        Array.Sort(nums);
        List<int[]> ans = new List<int[]>();

        for (int i = 0; i < nums.Length; i += 3) {
            if (i + 2 >= nums.Length) {
                return new int[0][];
            }

            int[] t = new int[] { nums[i], nums[i + 1], nums[i + 2] };
            if (t[2] - t[0] > k) {
                return new int[0][];
            }

            ans.Add(t);
        }

        return ans.ToArray();
    }
}
```

#### Dart

```dart
class Solution {
  List<List<int>> divideArray(List<int> nums, int k) {
    nums.sort();
    List<List<int>> ans = [];

    for (int i = 0; i < nums.length; i += 3) {
      if (i + 2 >= nums.length) {
        return [];
      }

      List<int> t = nums.sublist(i, i + 3);
      if (t[2] - t[0] > k) {
        return [];
      }

      ans.add(t);
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

# [2967. 使数组成为等数数组的最小代价](https://leetcode.cn/problems/minimum-cost-to-make-array-equalindromic){#2967}

{{< tabs "2967" >}}

{{% tab "python" %}}
```python
ps = []
for i in range(1, 10**5 + 1):
    s = str(i)
    t1 = s[::-1]
    t2 = s[:-1][::-1]
    ps.append(int(s + t1))
    ps.append(int(s + t2))
ps.sort()


class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        def f(x: int) -> int:
            return sum(abs(v - x) for v in nums)

        nums.sort()
        i = bisect_left(ps, nums[len(nums) // 2])
        return min(f(ps[j]) for j in range(i - 1, i + 2) if 0 <= j < len(ps))
```
{{% /tab %}}
{{% tab "java" %}}
```java
public class Solution {
    private static long[] ps;
    private int[] nums;

    static {
        ps = new long[2 * (int) 1e5];
        for (int i = 1; i <= 1e5; i++) {
            String s = Integer.toString(i);
            String t1 = new StringBuilder(s).reverse().toString();
            String t2 = new StringBuilder(s.substring(0, s.length() - 1)).reverse().toString();
            ps[2 * i - 2] = Long.parseLong(s + t1);
            ps[2 * i - 1] = Long.parseLong(s + t2);
        }
        Arrays.sort(ps);
    }

    public long minimumCost(int[] nums) {
        this.nums = nums;
        Arrays.sort(nums);
        int i = Arrays.binarySearch(ps, nums[nums.length / 2]);
        i = i < 0 ? -i - 1 : i;
        long ans = 1L << 60;
        for (int j = i - 1; j <= i + 1; j++) {
            if (0 <= j && j < ps.length) {
                ans = Math.min(ans, f(ps[j]));
            }
        }
        return ans;
    }

    private long f(long x) {
        long ans = 0;
        for (int v : nums) {
            ans += Math.abs(v - x);
        }
        return ans;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
using ll = long long;

ll ps[2 * 100000];

int init = [] {
    for (int i = 1; i <= 100000; i++) {
        string s = to_string(i);
        string t1 = s;
        reverse(t1.begin(), t1.end());
        string t2 = s.substr(0, s.length() - 1);
        reverse(t2.begin(), t2.end());
        ps[2 * i - 2] = stoll(s + t1);
        ps[2 * i - 1] = stoll(s + t2);
    }
    sort(ps, ps + 2 * 100000);
    return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = lower_bound(ps, ps + 2 * 100000, nums[nums.size() / 2]) - ps;
        auto f = [&](ll x) {
            ll ans = 0;
            for (int& v : nums) {
                ans += abs(v - x);
            }
            return ans;
        };
        ll ans = LLONG_MAX;
        for (int j = i - 1; j <= i + 1; j++) {
            if (0 <= j && j < 2 * 100000) {
                ans = min(ans, f(ps[j]));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
var ps [2 * 100000]int64

func init() {
	for i := 1; i <= 100000; i++ {
		s := strconv.Itoa(i)
		t1 := reverseString(s)
		t2 := reverseString(s[:len(s)-1])
		ps[2*i-2], _ = strconv.ParseInt(s+t1, 10, 64)
		ps[2*i-1], _ = strconv.ParseInt(s+t2, 10, 64)
	}
	sort.Slice(ps[:], func(i, j int) bool {
		return ps[i] < ps[j]
	})
}

func reverseString(s string) string {
	cs := []rune(s)
	for i, j := 0, len(cs)-1; i < j; i, j = i+1, j-1 {
		cs[i], cs[j] = cs[j], cs[i]
	}
	return string(cs)
}

func minimumCost(nums []int) int64 {
	sort.Ints(nums)
	i := sort.Search(len(ps), func(i int) bool {
		return ps[i] >= int64(nums[len(nums)/2])
	})

	f := func(x int64) int64 {
		var ans int64
		for _, v := range nums {
			ans += int64(abs(int(x - int64(v))))
		}
		return ans
	}

	ans := int64(math.MaxInt64)
	for j := i - 1; j <= i+1; j++ {
		if 0 <= j && j < len(ps) {
			ans = min(ans, f(ps[j]))
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
const ps = Array(2e5).fill(0);

const init = (() => {
    for (let i = 1; i <= 1e5; ++i) {
        const s: string = i.toString();
        const t1: string = s.split('').reverse().join('');
        const t2: string = s.slice(0, -1).split('').reverse().join('');
        ps[2 * i - 2] = parseInt(s + t1, 10);
        ps[2 * i - 1] = parseInt(s + t2, 10);
    }
    ps.sort((a, b) => a - b);
})();

function minimumCost(nums: number[]): number {
    const search = (x: number): number => {
        let [l, r] = [0, ps.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (ps[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const f = (x: number): number => {
        return nums.reduce((acc, v) => acc + Math.abs(v - x), 0);
    };

    nums.sort((a, b) => a - b);
    const i: number = search(nums[nums.length >> 1]);
    let ans: number = Number.MAX_SAFE_INTEGER;
    for (let j = i - 1; j <= i + 1; j++) {
        if (j >= 0 && j < ps.length) {
            ans = Math.min(ans, f(ps[j]));
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i64 {
        use std::sync::Once;
        use std::cmp::min;

        static INIT: Once = Once::new();
        static mut PS: Vec<i64> = Vec::new();

        INIT.call_once(|| {
            let mut ps_local = Vec::with_capacity(2 * 100_000);
            for i in 1..=100_000 {
                let s = i.to_string();

                let mut t1 = s.clone();
                t1 = t1.chars().rev().collect();
                ps_local.push(format!("{}{}", s, t1).parse::<i64>().unwrap());

                let mut t2 = s[0..s.len() - 1].to_string();
                t2 = t2.chars().rev().collect();
                ps_local.push(format!("{}{}", s, t2).parse::<i64>().unwrap());
            }
            ps_local.sort();
            unsafe {
                PS = ps_local;
            }
        });

        let mut nums = nums;
        nums.sort();

        let mid = nums[nums.len() / 2] as i64;

        let i = unsafe {
            match PS.binary_search(&mid) {
                Ok(i) => i,
                Err(i) => i,
            }
        };

        let f = |x: i64| -> i64 {
            nums.iter().map(|&v| (v as i64 - x).abs()).sum()
        };

        let mut ans = i64::MAX;

        for j in i.saturating_sub(1)..=(i + 1).min(2 * 100_000 - 1) {
            let x = unsafe { PS[j] };
            ans = min(ans, f(x));
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

<p>给你一个长度为 <code>n</code>&nbsp;下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;。</p>

<p>你可以对 <code>nums</code>&nbsp;执行特殊操作 <strong>任意次</strong>&nbsp;（也可以 <strong>0</strong>&nbsp;次）。每一次特殊操作中，你需要 <strong>按顺序</strong>&nbsp;执行以下步骤：</p>

<ul>
	<li>从范围&nbsp;<code>[0, n - 1]</code>&nbsp;里选择一个下标 <code>i</code>&nbsp;和一个 <strong>正</strong>&nbsp;整数&nbsp;<code>x</code>&nbsp;。</li>
	<li>将&nbsp;<code>|nums[i] - x|</code>&nbsp;添加到总代价里。</li>
	<li>将 <code>nums[i]</code>&nbsp;变为&nbsp;<code>x</code>&nbsp;。</li>
</ul>

<p>如果一个正整数正着读和反着读都相同，那么我们称这个数是<strong>&nbsp;回文数</strong>&nbsp;。比方说，<code>121</code>&nbsp;，<code>2552</code> 和&nbsp;<code>65756</code>&nbsp;都是回文数，但是&nbsp;<code>24</code>&nbsp;，<code>46</code>&nbsp;，<code>235</code>&nbsp;都不是回文数。</p>

<p>如果一个数组中的所有元素都等于一个整数&nbsp;<code>y</code>&nbsp;，且&nbsp;<code>y</code>&nbsp;是一个小于&nbsp;<code>10<sup>9</sup></code>&nbsp;的&nbsp;<strong>回文数</strong>&nbsp;，那么我们称这个数组是一个 <strong>等数数组&nbsp;</strong>。</p>

<p>请你返回一个整数，表示执行任意次特殊操作后使 <code>nums</code>&nbsp;成为 <strong>等数数组</strong>&nbsp;的 <strong>最小</strong>&nbsp;总代价。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5]
<b>输出：</b>6
<b>解释：</b>我们可以将数组中所有元素变为回文数 3 得到等数数组，数组变成 [3,3,3,3,3] 需要执行 4 次特殊操作，代价为 |1 - 3| + |2 - 3| + |4 - 3| + |5 - 3| = 6 。
将所有元素变为其他回文数的总代价都大于 6 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [10,12,13,14,15]
<b>输出：</b>11
<b>解释：</b>我们可以将数组中所有元素变为回文数 11 得到等数数组，数组变成 [11,11,11,11,11] 需要执行 5 次特殊操作，代价为 |10 - 11| + |12 - 11| + |13 - 11| + |14 - 11| + |15 - 11| = 11 。
将所有元素变为其他回文数的总代价都大于 11 。
</pre>

<p><strong class="example">示例 3 ：</strong></p>

<pre>
<b>输入：</b>nums = [22,33,22,33,22]
<b>输出：</b>22
<b>解释：</b>我们可以将数组中所有元素变为回文数 22 得到等数数组，数组变为 [22,22,22,22,22] 需要执行 2 次特殊操作，代价为 |33 - 22| + |33 - 22| = 22 。
将所有元素变为其他回文数的总代价都大于 22 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：预处理 + 排序 + 二分查找

题目中回文数的范围是 $[1, 10^9]$，回文数由于对称性，我们可以在 $[1, 10^5]$ 的范围内枚举，然后将其翻转后拼接，得到所有的回文数，注意，如果是奇数长度的回文数，我们在翻转前要去掉最后一位。预处理得到的回文数数组记为 $ps$。我们对数组 $ps$ 进行排序。

接下来，我们对数组 $nums$ 进行排序，然后取 $nums$ 的中位数 $x$，我们只需要通过二分查找，在回文数组 $ps$ 中，找到一个与 $x$ 最接近的数，然后计算 $nums$ 变成这个数的代价，即可得到答案。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(M)$。其中 $n$ 是数组 $nums$ 的长度，而 $M$ 是回文数组 $ps$ 的长度。

相似题目：

-   [906. 超级回文数](https://github.com/doocs/leetcode/blob/main/solution/0900-0999/0906.Super%20Palindromes/README.md)

<!-- tabs:start -->

#### Python3

```python
ps = []
for i in range(1, 10**5 + 1):
    s = str(i)
    t1 = s[::-1]
    t2 = s[:-1][::-1]
    ps.append(int(s + t1))
    ps.append(int(s + t2))
ps.sort()


class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        def f(x: int) -> int:
            return sum(abs(v - x) for v in nums)

        nums.sort()
        i = bisect_left(ps, nums[len(nums) // 2])
        return min(f(ps[j]) for j in range(i - 1, i + 2) if 0 <= j < len(ps))
```

#### Java

```java
public class Solution {
    private static long[] ps;
    private int[] nums;

    static {
        ps = new long[2 * (int) 1e5];
        for (int i = 1; i <= 1e5; i++) {
            String s = Integer.toString(i);
            String t1 = new StringBuilder(s).reverse().toString();
            String t2 = new StringBuilder(s.substring(0, s.length() - 1)).reverse().toString();
            ps[2 * i - 2] = Long.parseLong(s + t1);
            ps[2 * i - 1] = Long.parseLong(s + t2);
        }
        Arrays.sort(ps);
    }

    public long minimumCost(int[] nums) {
        this.nums = nums;
        Arrays.sort(nums);
        int i = Arrays.binarySearch(ps, nums[nums.length / 2]);
        i = i < 0 ? -i - 1 : i;
        long ans = 1L << 60;
        for (int j = i - 1; j <= i + 1; j++) {
            if (0 <= j && j < ps.length) {
                ans = Math.min(ans, f(ps[j]));
            }
        }
        return ans;
    }

    private long f(long x) {
        long ans = 0;
        for (int v : nums) {
            ans += Math.abs(v - x);
        }
        return ans;
    }
}
```

#### C++

```cpp
using ll = long long;

ll ps[2 * 100000];

int init = [] {
    for (int i = 1; i <= 100000; i++) {
        string s = to_string(i);
        string t1 = s;
        reverse(t1.begin(), t1.end());
        string t2 = s.substr(0, s.length() - 1);
        reverse(t2.begin(), t2.end());
        ps[2 * i - 2] = stoll(s + t1);
        ps[2 * i - 1] = stoll(s + t2);
    }
    sort(ps, ps + 2 * 100000);
    return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = lower_bound(ps, ps + 2 * 100000, nums[nums.size() / 2]) - ps;
        auto f = [&](ll x) {
            ll ans = 0;
            for (int& v : nums) {
                ans += abs(v - x);
            }
            return ans;
        };
        ll ans = LLONG_MAX;
        for (int j = i - 1; j <= i + 1; j++) {
            if (0 <= j && j < 2 * 100000) {
                ans = min(ans, f(ps[j]));
            }
        }
        return ans;
    }
};
```

#### Go

```go
var ps [2 * 100000]int64

func init() {
	for i := 1; i <= 100000; i++ {
		s := strconv.Itoa(i)
		t1 := reverseString(s)
		t2 := reverseString(s[:len(s)-1])
		ps[2*i-2], _ = strconv.ParseInt(s+t1, 10, 64)
		ps[2*i-1], _ = strconv.ParseInt(s+t2, 10, 64)
	}
	sort.Slice(ps[:], func(i, j int) bool {
		return ps[i] < ps[j]
	})
}

func reverseString(s string) string {
	cs := []rune(s)
	for i, j := 0, len(cs)-1; i < j; i, j = i+1, j-1 {
		cs[i], cs[j] = cs[j], cs[i]
	}
	return string(cs)
}

func minimumCost(nums []int) int64 {
	sort.Ints(nums)
	i := sort.Search(len(ps), func(i int) bool {
		return ps[i] >= int64(nums[len(nums)/2])
	})

	f := func(x int64) int64 {
		var ans int64
		for _, v := range nums {
			ans += int64(abs(int(x - int64(v))))
		}
		return ans
	}

	ans := int64(math.MaxInt64)
	for j := i - 1; j <= i+1; j++ {
		if 0 <= j && j < len(ps) {
			ans = min(ans, f(ps[j]))
		}
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

#### TypeScript

```ts
const ps = Array(2e5).fill(0);

const init = (() => {
    for (let i = 1; i <= 1e5; ++i) {
        const s: string = i.toString();
        const t1: string = s.split('').reverse().join('');
        const t2: string = s.slice(0, -1).split('').reverse().join('');
        ps[2 * i - 2] = parseInt(s + t1, 10);
        ps[2 * i - 1] = parseInt(s + t2, 10);
    }
    ps.sort((a, b) => a - b);
})();

function minimumCost(nums: number[]): number {
    const search = (x: number): number => {
        let [l, r] = [0, ps.length];
        while (l < r) {
            const mid = (l + r) >> 1;
            if (ps[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    };
    const f = (x: number): number => {
        return nums.reduce((acc, v) => acc + Math.abs(v - x), 0);
    };

    nums.sort((a, b) => a - b);
    const i: number = search(nums[nums.length >> 1]);
    let ans: number = Number.MAX_SAFE_INTEGER;
    for (let j = i - 1; j <= i + 1; j++) {
        if (j >= 0 && j < ps.length) {
            ans = Math.min(ans, f(ps[j]));
        }
    }
    return ans;
}
```

#### Rust

```rust
impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i64 {
        use std::sync::Once;
        use std::cmp::min;

        static INIT: Once = Once::new();
        static mut PS: Vec<i64> = Vec::new();

        INIT.call_once(|| {
            let mut ps_local = Vec::with_capacity(2 * 100_000);
            for i in 1..=100_000 {
                let s = i.to_string();

                let mut t1 = s.clone();
                t1 = t1.chars().rev().collect();
                ps_local.push(format!("{}{}", s, t1).parse::<i64>().unwrap());

                let mut t2 = s[0..s.len() - 1].to_string();
                t2 = t2.chars().rev().collect();
                ps_local.push(format!("{}{}", s, t2).parse::<i64>().unwrap());
            }
            ps_local.sort();
            unsafe {
                PS = ps_local;
            }
        });

        let mut nums = nums;
        nums.sort();

        let mid = nums[nums.len() / 2] as i64;

        let i = unsafe {
            match PS.binary_search(&mid) {
                Ok(i) => i,
                Err(i) => i,
            }
        };

        let f = |x: i64| -> i64 {
            nums.iter().map(|&v| (v as i64 - x).abs()).sum()
        };

        let mut ans = i64::MAX;

        for j in i.saturating_sub(1)..=(i + 1).min(2 * 100_000 - 1) {
            let x = unsafe { PS[j] };
            ans = min(ans, f(x));
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

# [2968. 执行操作使频率分数最大](https://leetcode.cn/problems/apply-operations-to-maximize-frequency-score){#2968}

{{< tabs "2968" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        nums.sort()
        s = list(accumulate(nums, initial=0))
        n = len(nums)
        l, r = 0, n
        while l < r:
            mid = (l + r + 1) >> 1
            ok = False
            for i in range(n - mid + 1):
                j = i + mid
                x = nums[(i + j) // 2]
                left = ((i + j) // 2 - i) * x - (s[(i + j) // 2] - s[i])
                right = (s[j] - s[(i + j) // 2]) - ((j - (i + j) // 2) * x)
                if left + right <= k:
                    ok = True
                    break
            if ok:
                l = mid
            else:
                r = mid - 1
        return l
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxFrequencyScore(int[] nums, long k) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            boolean ok = false;

            for (int i = 0; i <= n - mid; i++) {
                int j = i + mid;
                int x = nums[(i + j) / 2];
                long left = ((i + j) / 2 - i) * (long) x - (s[(i + j) / 2] - s[i]);
                long right = (s[j] - s[(i + j) / 2]) - ((j - (i + j) / 2) * (long) x);
                if (left + right <= k) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> s(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            bool ok = false;

            for (int i = 0; i <= n - mid; i++) {
                int j = i + mid;
                int x = nums[(i + j) / 2];
                long long left = ((i + j) / 2 - i) * (long long) x - (s[(i + j) / 2] - s[i]);
                long long right = (s[j] - s[(i + j) / 2]) - ((j - (i + j) / 2) * (long long) x);

                if (left + right <= k) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxFrequencyScore(nums []int, k int64) int {
	sort.Ints(nums)
	n := len(nums)
	s := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		s[i] = s[i-1] + int64(nums[i-1])
	}

	l, r := 0, n
	for l < r {
		mid := (l + r + 1) >> 1
		ok := false

		for i := 0; i <= n-mid; i++ {
			j := i + mid
			x := int64(nums[(i+j)/2])
			left := (int64((i+j)/2-i) * x) - (s[(i+j)/2] - s[i])
			right := (s[j] - s[(i+j)/2]) - (int64(j-(i+j)/2) * x)

			if left+right <= k {
				ok = true
				break
			}
		}

		if ok {
			l = mid
		} else {
			r = mid - 1
		}
	}

	return l
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxFrequencyScore(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + nums[i - 1];
    }

    let l: number = 0;
    let r: number = n;
    while (l < r) {
        const mid: number = (l + r + 1) >> 1;
        let ok: boolean = false;
        for (let i = 0; i <= n - mid; i++) {
            const j = i + mid;
            const x = nums[Math.floor((i + j) / 2)];
            const left = (Math.floor((i + j) / 2) - i) * x - (s[Math.floor((i + j) / 2)] - s[i]);
            const right = s[j] - s[Math.floor((i + j) / 2)] - (j - Math.floor((i + j) / 2)) * x;
            if (left + right <= k) {
                ok = true;
                break;
            }
        }
        if (ok) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始的整数数组&nbsp;<code>nums</code>&nbsp;和一个整数&nbsp;<code>k</code>&nbsp;。</p>

<p>你可以对数组执行 <strong>至多</strong>&nbsp;<code>k</code>&nbsp;次操作：</p>

<ul>
	<li>从数组中选择一个下标 <code>i</code>&nbsp;，将&nbsp;<code>nums[i]</code> <strong>增加</strong>&nbsp;或者&nbsp;<strong>减少</strong>&nbsp;<code>1</code>&nbsp;。</li>
</ul>

<p>最终数组的频率分数定义为数组中众数的 <strong>频率</strong>&nbsp;。</p>

<p>请你返回你可以得到的 <strong>最大</strong>&nbsp;频率分数。</p>

<p>众数指的是数组中出现次数最多的数。一个元素的频率指的是数组中这个元素的出现次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,6,4], k = 3
<b>输出：</b>3
<b>解释：</b>我们可以对数组执行以下操作：
- 选择 i = 0 ，将 nums[0] 增加 1 。得到数组 [2,2,6,4] 。
- 选择 i = 3 ，将 nums[3] 减少 1 ，得到数组 [2,2,6,3] 。
- 选择 i = 3 ，将 nums[3] 减少 1 ，得到数组 [2,2,6,2] 。
元素 2 是最终数组中的众数，出现了 3 次，所以频率分数为 3 。
3 是所有可行方案里的最大频率分数。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,4,2,4], k = 0
<b>输出：</b>3
<b>解释：</b>我们无法执行任何操作，所以得到的频率分数是原数组中众数的频率 3 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>14</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序 + 前缀和 + 二分查找

题目求的是在最多进行 $k$ 次操作的情况下，我们能得到的众数的最大频率。如果我们将数组 $nums$ 按照从小到大的顺序排列，那么最好就是将一段连续的数字都变成同一个数，这样可以使得操作次数较少，并且众数的频率较高。

因此，我们不妨先对数组 $nums$ 进行排序。

接下来，我们再分析，如果一个频率 $x$ 是可行的，那么对于任意 $y \le x$，频率 $y$ 也是可行的，这存在着单调性。因此，我们可以通过二分查找，找到最大的满足条件的频率。

我们二分枚举频率，定义二分查找的左边界 $l = 0$，右边界 $r = n$，其中 $n$ 是数组的长度。每次二分查找的过程中，我们取中间值 $mid = \lfloor \frac{l + r + 1}{2} \rfloor$，然后判断 $nums$ 中是否存在一个长度为 $mid$ 的连续子数组，使得这个子数组中的所有元素都变成这个子数组的中位数，且操作次数不超过 $k$。如果存在，那么我们就将左边界 $l$ 更新为 $mid$，否则我们就将右边界 $r$ 更新为 $mid - 1$。

为了判断是否存在这样的子数组，我们可以使用前缀和。我们首先定义两个指针 $i$ 和 $j$，初始时 $i = 0$, $j = i + mid$。那么 $nums[i]$ 到 $nums[j - 1]$ 这一段的元素都变成 $nums[(i + j) / 2]$，所需要的操作次数为 $left + right$，其中：

$$
\begin{aligned}
\textit{left} &= \sum_{k = i}^{(i + j) / 2 - 1} (nums[(i + j) / 2] - nums[k]) \\
&= ((i + j) / 2 - i) \times nums[(i + j) / 2] - \sum_{k = i}^{(i + j) / 2 - 1} nums[k]
\end{aligned}
$$

$$
\begin{aligned}
\textit{right} &= \sum_{k = (i + j) / 2 + 1}^{j} (nums[k] - nums[(i + j) / 2]) \\
&= \sum_{k = (i + j) / 2 + 1}^{j} nums[k] - (j - (i + j) / 2) \times nums[(i + j) / 2]
\end{aligned}
$$

我们可以通过前缀和数组 $s$ 来计算 $\sum_{k = i}^{j} nums[k]$，从而在 $O(1)$ 的时间内计算出 $left$ 和 $right$。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 是数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:
        nums.sort()
        s = list(accumulate(nums, initial=0))
        n = len(nums)
        l, r = 0, n
        while l < r:
            mid = (l + r + 1) >> 1
            ok = False
            for i in range(n - mid + 1):
                j = i + mid
                x = nums[(i + j) // 2]
                left = ((i + j) // 2 - i) * x - (s[(i + j) // 2] - s[i])
                right = (s[j] - s[(i + j) // 2]) - ((j - (i + j) // 2) * x)
                if left + right <= k:
                    ok = True
                    break
            if ok:
                l = mid
            else:
                r = mid - 1
        return l
```

#### Java

```java
class Solution {
    public int maxFrequencyScore(int[] nums, long k) {
        Arrays.sort(nums);
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            boolean ok = false;

            for (int i = 0; i <= n - mid; i++) {
                int j = i + mid;
                int x = nums[(i + j) / 2];
                long left = ((i + j) / 2 - i) * (long) x - (s[(i + j) / 2] - s[i]);
                long right = (s[j] - s[(i + j) / 2]) - ((j - (i + j) / 2) * (long) x);
                if (left + right <= k) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> s(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            bool ok = false;

            for (int i = 0; i <= n - mid; i++) {
                int j = i + mid;
                int x = nums[(i + j) / 2];
                long long left = ((i + j) / 2 - i) * (long long) x - (s[(i + j) / 2] - s[i]);
                long long right = (s[j] - s[(i + j) / 2]) - ((j - (i + j) / 2) * (long long) x);

                if (left + right <= k) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }
};
```

#### Go

```go
func maxFrequencyScore(nums []int, k int64) int {
	sort.Ints(nums)
	n := len(nums)
	s := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		s[i] = s[i-1] + int64(nums[i-1])
	}

	l, r := 0, n
	for l < r {
		mid := (l + r + 1) >> 1
		ok := false

		for i := 0; i <= n-mid; i++ {
			j := i + mid
			x := int64(nums[(i+j)/2])
			left := (int64((i+j)/2-i) * x) - (s[(i+j)/2] - s[i])
			right := (s[j] - s[(i+j)/2]) - (int64(j-(i+j)/2) * x)

			if left+right <= k {
				ok = true
				break
			}
		}

		if ok {
			l = mid
		} else {
			r = mid - 1
		}
	}

	return l
}
```

#### TypeScript

```ts
function maxFrequencyScore(nums: number[], k: number): number {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const s: number[] = Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + nums[i - 1];
    }

    let l: number = 0;
    let r: number = n;
    while (l < r) {
        const mid: number = (l + r + 1) >> 1;
        let ok: boolean = false;
        for (let i = 0; i <= n - mid; i++) {
            const j = i + mid;
            const x = nums[Math.floor((i + j) / 2)];
            const left = (Math.floor((i + j) / 2) - i) * x - (s[Math.floor((i + j) / 2)] - s[i]);
            const right = s[j] - s[Math.floor((i + j) / 2)] - (j - Math.floor((i + j) / 2)) * x;
            if (left + right <= k) {
                ok = true;
                break;
            }
        }
        if (ok) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    return l;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [2969. 购买水果需要的最少金币数 II 🔒](https://leetcode.cn/problems/minimum-number-of-coins-for-fruits-ii){#2969}

{{< tabs "2969" >}}

{{% tab "python" %}}
```python
class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        q = deque()
        for i in range(n, 0, -1):
            while q and q[0] > i * 2 + 1:
                q.popleft()
            if i <= (n - 1) // 2:
                prices[i - 1] += prices[q[0] - 1]
            while q and prices[q[-1] - 1] >= prices[i - 1]:
                q.pop()
            q.append(i)
        return prices[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minimumCoins(int[] prices) {
        int n = prices.length;
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = n; i > 0; --i) {
            while (!q.isEmpty() && q.peek() > i * 2 + 1) {
                q.poll();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.peek() - 1];
            }
            while (!q.isEmpty() && prices[q.peekLast() - 1] >= prices[i - 1]) {
                q.pollLast();
            }
            q.offer(i);
        }
        return prices[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<int> q;
        for (int i = n; i; --i) {
            while (q.size() && q.front() > i * 2 + 1) {
                q.pop_front();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.front() - 1];
            }
            while (q.size() && prices[q.back() - 1] >= prices[i - 1]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return prices[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minimumCoins(prices []int) int {
	n := len(prices)
	q := Deque{}
	for i := n; i > 0; i-- {
		for q.Size() > 0 && q.Front() > i*2+1 {
			q.PopFront()
		}
		if i <= (n-1)/2 {
			prices[i-1] += prices[q.Front()-1]
		}
		for q.Size() > 0 && prices[q.Back()-1] >= prices[i-1] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return prices[0]
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minimumCoins(prices: number[]): number {
    const n = prices.length;
    const q = new Deque<number>();
    for (let i = n; i; --i) {
        while (q.getSize() && q.frontValue()! > i * 2 + 1) {
            q.popFront();
        }
        if (i <= (n - 1) >> 1) {
            prices[i - 1] += prices[q.frontValue()! - 1];
        }
        while (q.getSize() && prices[q.backValue()! - 1] >= prices[i - 1]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return prices[0];
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你在一个水果超市里，货架上摆满了玲琅满目的奇珍异果。</p>

<p>给你一个 <b>下标从 1 开始</b>&nbsp;的数组&nbsp;<code>prices</code>，其中&nbsp;<code>prices[i]</code>&nbsp;表示你购买第&nbsp;<code>i</code>&nbsp;个水果所需的硬币数量。</p>

<p>水果市场有以下优惠活动：</p>

<ul>
	<li>如果你用&nbsp;<code>prices[i]</code>&nbsp;个硬币购买第 <code>i</code> 个水果， 那么接下来的 i 个水果你都可以免费获得。</li>
</ul>

<p><strong>请注意</strong>&nbsp;即使你 <strong>可以</strong> 免费获得第&nbsp;<code>j</code>&nbsp;个水果，你仍然可以用&nbsp;<code>prices[j]</code>&nbsp;个硬币来购买它，以获取新的优惠。</p>

<p>返回 <em>获得所有水果所需的 <strong>最小</strong> 硬币数量。</em></p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>prices = [3,1,2]
<strong>输出：</strong>4
<strong>解释：</strong>你可以按以下方式获取水果：
- 用3个硬币购买第1个水果，并且可以免费获得第2个水果。
- 用1个硬币购买第2个水果，并且可以免费获得第3个水果。
- 免费获得第三个水果。
请注意，即使你可以免费获得第2个水果，你还是购买了它，因为这是更优的选择。
可以证明4是获取所有水果所需的最小硬币数量。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
输入：prices = [1,10,1,1]
输出：2
解释：你可以按以下方式获取水果：
- 用1个硬币购买第1个水果，并且可以免费获得第2个水果。
- 免费获得第2个水果。
- 用1个硬币购买第3个水果，并且可以免费获得第4个水果。
- 免费获得第4个水果。
可以证明2是获取所有水果所需的最小硬币数量。
</pre>

<p>&nbsp;</p>

<p><b>提示：</b></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i]$ 表示从第 $i$ 个水果开始购买所有水果所需要的最少金币数。那么答案就是 $f[1]$。

状态转移方程为 $f[i] = \min_{i + 1 \le j \le 2i + 1} f[j] + prices[i - 1]$。

在实现上，我们从后往前计算，并且可以直接在数组 $prices$ 上进行状态转移，这样可以节省空间。

以上做法的时间复杂度为 $O(n^2)$，由于本题 $n$ 的规模达到 $10^5$，因此会超时。

我们观察状态转移方程，可以发现，对于每个 $i$，我们需要求出 $f[i + 1], f[i + 2], \cdots, f[2i + 1]$ 的最小值，并且随着 $i$ 的减小，这些值的范围也在减小。这实际上是求一个单调收窄的滑动窗口的最小值，我们可以使用单调队列来优化。

我们从后往前计算，维护一个单调递增的队列 $q$，队列中存储的是下标。如果 $q$ 的队首元素大于 $i \times 2 + 1$，说明 $i$ 之后的元素都不会被用到，所以我们将队首元素出队。如果 $i$ 不大于 $(n - 1) / 2$，那么我们可以将 $prices[q[0] - 1]$ 加到 $prices[i - 1]$ 上，然后将 $i$ 加入队尾。如果 $q$ 的队尾元素对应的水果价格大于等于 $prices[i - 1]$，那么我们将队尾元素出队，直到队尾元素对应的水果价格小于 $prices[i - 1]$ 或者队列为空，然后将 $i$ 加入队尾。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为数组 $prices$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        q = deque()
        for i in range(n, 0, -1):
            while q and q[0] > i * 2 + 1:
                q.popleft()
            if i <= (n - 1) // 2:
                prices[i - 1] += prices[q[0] - 1]
            while q and prices[q[-1] - 1] >= prices[i - 1]:
                q.pop()
            q.append(i)
        return prices[0]
```

#### Java

```java
class Solution {
    public int minimumCoins(int[] prices) {
        int n = prices.length;
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = n; i > 0; --i) {
            while (!q.isEmpty() && q.peek() > i * 2 + 1) {
                q.poll();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.peek() - 1];
            }
            while (!q.isEmpty() && prices[q.peekLast() - 1] >= prices[i - 1]) {
                q.pollLast();
            }
            q.offer(i);
        }
        return prices[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<int> q;
        for (int i = n; i; --i) {
            while (q.size() && q.front() > i * 2 + 1) {
                q.pop_front();
            }
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.front() - 1];
            }
            while (q.size() && prices[q.back() - 1] >= prices[i - 1]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return prices[0];
    }
};
```

#### Go

```go
func minimumCoins(prices []int) int {
	n := len(prices)
	q := Deque{}
	for i := n; i > 0; i-- {
		for q.Size() > 0 && q.Front() > i*2+1 {
			q.PopFront()
		}
		if i <= (n-1)/2 {
			prices[i-1] += prices[q.Front()-1]
		}
		for q.Size() > 0 && prices[q.Back()-1] >= prices[i-1] {
			q.PopBack()
		}
		q.PushBack(i)
	}
	return prices[0]
}

// template
type Deque struct{ l, r []int }

func (q Deque) Empty() bool {
	return len(q.l) == 0 && len(q.r) == 0
}

func (q Deque) Size() int {
	return len(q.l) + len(q.r)
}

func (q *Deque) PushFront(v int) {
	q.l = append(q.l, v)
}

func (q *Deque) PushBack(v int) {
	q.r = append(q.r, v)
}

func (q *Deque) PopFront() (v int) {
	if len(q.l) > 0 {
		q.l, v = q.l[:len(q.l)-1], q.l[len(q.l)-1]
	} else {
		v, q.r = q.r[0], q.r[1:]
	}
	return
}

func (q *Deque) PopBack() (v int) {
	if len(q.r) > 0 {
		q.r, v = q.r[:len(q.r)-1], q.r[len(q.r)-1]
	} else {
		v, q.l = q.l[0], q.l[1:]
	}
	return
}

func (q Deque) Front() int {
	if len(q.l) > 0 {
		return q.l[len(q.l)-1]
	}
	return q.r[0]
}

func (q Deque) Back() int {
	if len(q.r) > 0 {
		return q.r[len(q.r)-1]
	}
	return q.l[0]
}

func (q Deque) Get(i int) int {
	if i < len(q.l) {
		return q.l[len(q.l)-1-i]
	}
	return q.r[i-len(q.l)]
}
```

#### TypeScript

```ts
function minimumCoins(prices: number[]): number {
    const n = prices.length;
    const q = new Deque<number>();
    for (let i = n; i; --i) {
        while (q.getSize() && q.frontValue()! > i * 2 + 1) {
            q.popFront();
        }
        if (i <= (n - 1) >> 1) {
            prices[i - 1] += prices[q.frontValue()! - 1];
        }
        while (q.getSize() && prices[q.backValue()! - 1] >= prices[i - 1]) {
            q.popBack();
        }
        q.pushBack(i);
    }
    return prices[0];
}

class Node<T> {
    value: T;
    next: Node<T> | null;
    prev: Node<T> | null;

    constructor(value: T) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class Deque<T> {
    private front: Node<T> | null;
    private back: Node<T> | null;
    private size: number;

    constructor() {
        this.front = null;
        this.back = null;
        this.size = 0;
    }

    pushFront(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.next = this.front;
            this.front!.prev = newNode;
            this.front = newNode;
        }
        this.size++;
    }

    pushBack(val: T): void {
        const newNode = new Node(val);
        if (this.isEmpty()) {
            this.front = newNode;
            this.back = newNode;
        } else {
            newNode.prev = this.back;
            this.back!.next = newNode;
            this.back = newNode;
        }
        this.size++;
    }

    popFront(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.front!.value;
        this.front = this.front!.next;
        if (this.front !== null) {
            this.front.prev = null;
        } else {
            this.back = null;
        }
        this.size--;
        return value;
    }

    popBack(): T | undefined {
        if (this.isEmpty()) {
            return undefined;
        }
        const value = this.back!.value;
        this.back = this.back!.prev;
        if (this.back !== null) {
            this.back.next = null;
        } else {
            this.front = null;
        }
        this.size--;
        return value;
    }

    frontValue(): T | undefined {
        return this.front?.value;
    }

    backValue(): T | undefined {
        return this.back?.value;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size === 0;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
