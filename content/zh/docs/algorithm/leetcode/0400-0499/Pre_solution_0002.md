---
title: "0410_分割数组的最大值"
date: 2025-10-08T18:36:10+08:00
weight: 2
tags: [二分查找, 位运算, 前缀和, 动态规划, 回溯, 字符串, 广度优先搜索, 排序, 数学, 数组, 模拟, 深度优先搜索, 滑动窗口, 矩阵, 贪心]
---

{{< markmap >}}
### [0410_分割数组的最大值](#410)
#### [贪心](#410)
#### [数组](#410)
#### [二分查找](#410)
#### [动态规划](#410)
#### [前缀和](#410)
### [0411_最短独占单词缩写 🔒](#411)
#### [位运算](#411)
#### [数组](#411)
#### [字符串](#411)
#### [回溯](#411)
### [0412_Fizz Buzz](#412)
#### [数学](#412)
#### [字符串](#412)
#### [模拟](#412)
### [0413_等差数列划分](#413)
#### [数组](#413)
#### [动态规划](#413)
#### [滑动窗口](#413)
### [0414_第三大的数](#414)
#### [数组](#414)
#### [排序](#414)
### [0415_字符串相加](#415)
#### [数学](#415)
#### [字符串](#415)
#### [模拟](#415)
### [0416_分割等和子集](#416)
#### [数组](#416)
#### [动态规划](#416)
### [0417_太平洋大西洋水流问题](#417)
#### [深度优先搜索](#417)
#### [广度优先搜索](#417)
#### [数组](#417)
#### [矩阵](#417)
### [0418_屏幕可显示句子的数量 🔒](#418)
#### [数组](#418)
#### [字符串](#418)
#### [动态规划](#418)
### [0419_棋盘上的战舰](#419)
#### [深度优先搜索](#419)
#### [数组](#419)
#### [矩阵](#419)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0410_分割数组的最大值
___
#### 贪心
___
#### 数组
___
#### 二分查找
___
#### 动态规划
___
#### 前缀和
---
### 0411_最短独占单词缩写 🔒
___
#### 位运算
___
#### 数组
___
#### 字符串
___
#### 回溯
---
### 0412_Fizz Buzz
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 0413_等差数列划分
___
#### 数组
___
#### 动态规划
___
#### 滑动窗口
---
### 0414_第三大的数
___
#### 数组
___
#### 排序
---
### 0415_字符串相加
___
#### 数学
___
#### 字符串
___
#### 模拟
---
### 0416_分割等和子集
___
#### 数组
___
#### 动态规划
---
### 0417_太平洋大西洋水流问题
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 数组
___
#### 矩阵
---
### 0418_屏幕可显示句子的数量 🔒
___
#### 数组
___
#### 字符串
___
#### 动态规划
---
### 0419_棋盘上的战舰
___
#### 深度优先搜索
___
#### 数组
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 前缀和 |
| 动态规划 | 回溯 | 字符串 |
| 广度优先搜索 | 排序 | 数学 |
| 数组 | 模拟 | 深度优先搜索 |
| 滑动窗口 | 矩阵 | 贪心 |

# [410. 分割数组的最大值](https://leetcode.cn/problems/split-array-largest-sum){#410}

{{< tabs "410" >}}

{{% tab "python" %}}
```python
class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def check(mx):
            s, cnt = inf, 0
            for x in nums:
                s += x
                if s > mx:
                    s = x
                    cnt += 1
            return cnt <= k

        left, right = max(nums), sum(nums)
        return left + bisect_left(range(left, right + 1), True, key=check)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int splitArray(int[] nums, int k) {
        int left = 0, right = 0;
        for (int x : nums) {
            left = Math.max(left, x);
            right += x;
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int[] nums, int mx, int k) {
        int s = 1 << 30, cnt = 0;
        for (int x : nums) {
            s += x;
            if (s > mx) {
                ++cnt;
                s = x;
            }
        }
        return cnt <= k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for (int& x : nums) {
            left = max(left, x);
            right += x;
        }
        auto check = [&](int mx) {
            int s = 1 << 30, cnt = 0;
            for (int& x : nums) {
                s += x;
                if (s > mx) {
                    s = x;
                    ++cnt;
                }
            }
            return cnt <= k;
        };
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func splitArray(nums []int, k int) int {
	left, right := 0, 0
	for _, x := range nums {
		left = max(left, x)
		right += x
	}
	return left + sort.Search(right-left, func(mx int) bool {
		mx += left
		s, cnt := 1<<30, 0
		for _, x := range nums {
			s += x
			if s > mx {
				s = x
				cnt++
			}
		}
		return cnt <= k
	})
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var splitArray = function (nums, k) {
    let l = Math.max(...nums);
    let r = nums.reduce((a, b) => a + b);

    const check = mx => {
        let [s, cnt] = [0, 0];
        for (const x of nums) {
            s += x;
            if (s > mx) {
                s = x;
                if (++cnt === k) return false;
            }
        }
        return true;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function splitArray(nums: number[], k: number): number {
    let l = Math.max(...nums);
    let r = nums.reduce((a, b) => a + b);

    const check = (mx: number) => {
        let [s, cnt] = [0, 0];
        for (const x of nums) {
            s += x;
            if (s > mx) {
                s = x;
                if (++cnt === k) return false;
            }
        }
        return true;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
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

<p>给定一个非负整数数组 <code>nums</code> 和一个整数&nbsp;<code>k</code> ，你需要将这个数组分成&nbsp;<code>k</code><em>&nbsp;</em>个非空的连续子数组，使得这&nbsp;<code>k</code><em>&nbsp;</em>个子数组各自和的最大值 <strong>最小</strong>。</p>

<p>返回分割后最小的和的最大值。</p>

<p><strong>子数组</strong> 是数组中连续的部份。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [7,2,5,10,8], k = 2
<strong>输出：</strong>18
<strong>解释：</strong>
一共有四种方法将 nums 分割为 2 个子数组。 
其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4,5], k = 2
<strong>输出：</strong>9
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,4,4], k = 3
<strong>输出：</strong>4
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= min(50, nums.length)</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，当子数组的和的最大值越大，子数组的个数越少，当存在一个满足条件的子数组和的最大值时，那么比这个最大值更大的子数组和的最大值一定也满足条件。也就是说，我们可以对子数组和的最大值进行二分查找，找到满足条件的最小值。

我们定义二分查找的左边界 $left = \max(nums)$，右边界 $right = sum(nums)$，然后对于二分查找的每一步，我们取中间值 $mid = \lfloor \frac{left + right}{2} \rfloor$，然后判断是否存在一个分割方式，使得子数组的和的最大值不超过 $mid$，如果存在，则说明 $mid$ 可能是满足条件的最小值，因此我们将右边界调整为 $mid$，否则我们将左边界调整为 $mid + 1$。

我们如何判断是否存在一个分割方式，使得子数组的和的最大值不超过 $mid$ 呢？我们可以使用贪心的方法，从左到右遍历数组，将数组中的元素依次加入到子数组中，如果当前子数组的和大于 $mid$，则我们将当前元素加入到下一个子数组中。如果我们能够将数组分割成不超过 $k$ 个子数组，且每个子数组的和的最大值不超过 $mid$，则说明 $mid$ 是满足条件的最小值，否则 $mid$ 不是满足条件的最小值。

时间复杂度 $O(n \times \log m)$，空间复杂度 $O(1)$。其中 $n$ 和 $m$ 分别是数组的长度和数组所有元素的和。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def check(mx):
            s, cnt = inf, 0
            for x in nums:
                s += x
                if s > mx:
                    s = x
                    cnt += 1
            return cnt <= k

        left, right = max(nums), sum(nums)
        return left + bisect_left(range(left, right + 1), True, key=check)
```

#### Java

```java
class Solution {
    public int splitArray(int[] nums, int k) {
        int left = 0, right = 0;
        for (int x : nums) {
            left = Math.max(left, x);
            right += x;
        }
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(nums, mid, k)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private boolean check(int[] nums, int mx, int k) {
        int s = 1 << 30, cnt = 0;
        for (int x : nums) {
            s += x;
            if (s > mx) {
                ++cnt;
                s = x;
            }
        }
        return cnt <= k;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for (int& x : nums) {
            left = max(left, x);
            right += x;
        }
        auto check = [&](int mx) {
            int s = 1 << 30, cnt = 0;
            for (int& x : nums) {
                s += x;
                if (s > mx) {
                    s = x;
                    ++cnt;
                }
            }
            return cnt <= k;
        };
        while (left < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

#### Go

```go
func splitArray(nums []int, k int) int {
	left, right := 0, 0
	for _, x := range nums {
		left = max(left, x)
		right += x
	}
	return left + sort.Search(right-left, func(mx int) bool {
		mx += left
		s, cnt := 1<<30, 0
		for _, x := range nums {
			s += x
			if s > mx {
				s = x
				cnt++
			}
		}
		return cnt <= k
	})
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var splitArray = function (nums, k) {
    let l = Math.max(...nums);
    let r = nums.reduce((a, b) => a + b);

    const check = mx => {
        let [s, cnt] = [0, 0];
        for (const x of nums) {
            s += x;
            if (s > mx) {
                s = x;
                if (++cnt === k) return false;
            }
        }
        return true;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
};
```

#### TypeScript

```ts
function splitArray(nums: number[], k: number): number {
    let l = Math.max(...nums);
    let r = nums.reduce((a, b) => a + b);

    const check = (mx: number) => {
        let [s, cnt] = [0, 0];
        for (const x of nums) {
            s += x;
            if (s > mx) {
                s = x;
                if (++cnt === k) return false;
            }
        }
        return true;
    };

    while (l < r) {
        const mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
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

# [411. 最短独占单词缩写 🔒](https://leetcode.cn/problems/minimum-unique-word-abbreviation){#411}

{{< tabs "411" >}}

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

<p>通过将任意数量的 <strong>不相邻</strong> 子字符串替换为它们的长度，可以完成对字符串的 <strong>缩写</strong> 。 例如，像 <code>"substitution"</code> 这样的字符串可以缩写为（但不限于）：</p>

<ul>
	<li><code>"s10n"</code> (<code>"s <strong>ubstitutio</strong> n"</code>)</li>
	<li><code>"sub4u4"</code> (<code>"sub <strong>stit</strong> u <strong>tion</strong>"</code>)</li>
	<li><code>"12"</code> (<code>"<strong>substitution</strong>"</code>)</li>
	<li><code>"su3i1u2on"</code> (<code>"su <strong>bst</strong> i <strong>t</strong> u <strong>ti</strong> on"</code>)</li>
	<li><code>"substitution"</code> (不替换子字符串)</li>
</ul>

<p>注意：<code>"s55n"</code> (<code>"s <strong>ubsti</strong> <strong>tutio</strong> n"</code>) 不是&nbsp;<code>"substitution"</code> 的有效缩写形式，因为它试图替换两个相邻的子字符串。</p>

<p>缩写的 <strong>长度</strong> 是未被替换的字母数加上被替换的字符串数。例如，缩写 <code>"s10n"</code> 的长度为 <code>3</code>（<code>2</code> 个字母 + <code>1</code> 个子字符串），而 <code>"su3i1u2on"</code> 的长度为 <code>9</code>（<code>6</code> 个字母 + <code>3</code> 子字符串）。</p>

<p>给你一个目标字符串 <code>target</code> 和一个字符串数组 <code>dictionary</code> 作为字典，为<em> </em><code>target</code> 找出并返回一个&nbsp;<strong>最短 </strong>长度的缩写字符串，同时这个缩写字符串 <strong>不是</strong> 字典&nbsp;<code>dictionary</code> 中其他字符串的缩写形式。如果有多个有效答案，可以返回其中任意一个。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>target = "apple", dictionary = ["blade"]
<strong>输出：</strong>"a4"
<strong>解释：</strong>"apple" 的最短缩写形式为 "5" ，但这也是 "blade" 的缩写形式之一。
下一组最短缩写是 "a4" 和 "4e" ，其中 "4e" 也是 "blade" 的缩写形式之一，而 "a4" 不是。
因此，返回 "a4" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>target = "apple", dictionary = ["blade","plain","amber"]
<strong>输出：</strong>"1p3"
<strong>解释：</strong>"5" 同时是 "apple" 和字典中所有单词的缩写形式。
"a4" 同时是 "apple" 和 "amber" 的缩写形式。
"4e" 同时是 "apple" 和 "blade" 的缩写形式。
"1p3"、"2p2" 和 "3l1" 是 "apple" 的下一组最短缩写形式。
因为它们不是字典中其他单词的缩写形式，返回其中任意一个都是正确的。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>target.length == m</code></li>
	<li><code>dictionary.length == n</code></li>
	<li><code>1 &lt;= m &lt;= 21</code></li>
	<li><code>0 &lt;= n &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary[i].length&nbsp;&lt;= 100</code></li>
	<li>如果 <code>n &gt; 0</code> ，那么 <code>log<sub>2</sub>(n) + m &lt;= 21</code></li>
	<li><code>target</code>&nbsp;和&nbsp;<code>dictionary[i]</code>&nbsp;仅包含小写字符</li>
	<li><code>dictionary</code>&nbsp;不包含 <code>target</code>。</li>
</ul>

<p>&nbsp;</p>

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

# [412. Fizz Buzz](https://leetcode.cn/problems/fizz-buzz){#412}

{{< tabs "412" >}}

{{% tab "python" %}}
```python
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []
        for i in range(1, n + 1):
            if i % 15 == 0:
                ans.append('FizzBuzz')
            elif i % 3 == 0:
                ans.append('Fizz')
            elif i % 5 == 0:
                ans.append('Buzz')
            else:
                ans.append(str(i))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ans = new ArrayList<>();
        for (int i = 1; i <= n; ++i) {
            String s = "";
            if (i % 3 == 0) {
                s += "Fizz";
            }
            if (i % 5 == 0) {
                s += "Buzz";
            }
            if (s.length() == 0) {
                s += i;
            }
            ans.add(s);
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
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            string s = "";
            if (i % 3 == 0) {
                s += "Fizz";
            }
            if (i % 5 == 0) {
                s += "Buzz";
            }
            if (s.empty()) {
                s = to_string(i);
            }
            ans.push_back(s);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func fizzBuzz(n int) []string {
	ans := make([]string, 0, n)
	for i := 1; i < n+1; i++ {
		switch {
		case i%15 == 0:
			ans = append(ans, "FizzBuzz")
		case i%3 == 0:
			ans = append(ans, "Fizz")
		case i%5 == 0:
			ans = append(ans, "Buzz")
		default:
			ans = append(ans, strconv.Itoa(i))
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function (n) {
    const ans = [];
    for (let i = 1; i <= n; ++i) {
        if (i % 15 === 0) {
            ans.push('FizzBuzz');
        } else if (i % 3 === 0) {
            ans.push('Fizz');
        } else if (i % 5 === 0) {
            ans.push('Buzz');
        } else {
            ans.push(`${i}`);
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "php" %}}
```php
class Solution {
    /**
     * @param Integer $n
     * @return String[]
     */
    function fizzBuzz($n) {
        $ans = [];
        for ($i = 1; $i <= $n; ++$i) {
            $s = '';
            if ($i % 3 == 0) {
                $s .= 'Fizz';
            }
            if ($i % 5 == 0) {
                $s .= 'Buzz';
            }
            if (strlen($s) == 0) {
                $s .= $i;
            }
            $ans[] = $s;
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

<p>给你一个整数 <code>n</code> ，返回一个字符串数组 <code>answer</code>（<strong>下标从 1 开始</strong>），其中：</p>

<ul>
	<li><code>answer[i] == "FizzBuzz"</code> 如果 <code>i</code> 同时是 <code>3</code> 和 <code>5</code> 的倍数。</li>
	<li><code>answer[i] == "Fizz"</code> 如果 <code>i</code> 是 <code>3</code> 的倍数。</li>
	<li><code>answer[i] == "Buzz"</code> 如果 <code>i</code> 是 <code>5</code> 的倍数。</li>
	<li><code>answer[i] == i</code> （以字符串形式）如果上述条件全不满足。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 3
<strong>输出：</strong>["1","2","Fizz"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 5
<strong>输出：</strong>["1","2","Fizz","4","Buzz"]
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 15
<strong>输出：</strong>["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历从 1 到 n 的每个整数，对于每个整数，我们检查它是否是 3 和 5 的倍数，或者只是 3 的倍数，或者只是 5 的倍数。根据检查的结果，我们将相应的字符串添加到答案数组中。

时间复杂度 $O(n)$，其中 $n$ 是题目给定的整数。忽略答案数组的空间消耗，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = []
        for i in range(1, n + 1):
            if i % 15 == 0:
                ans.append('FizzBuzz')
            elif i % 3 == 0:
                ans.append('Fizz')
            elif i % 5 == 0:
                ans.append('Buzz')
            else:
                ans.append(str(i))
        return ans
```

#### Java

```java
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> ans = new ArrayList<>();
        for (int i = 1; i <= n; ++i) {
            String s = "";
            if (i % 3 == 0) {
                s += "Fizz";
            }
            if (i % 5 == 0) {
                s += "Buzz";
            }
            if (s.length() == 0) {
                s += i;
            }
            ans.add(s);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; ++i) {
            string s = "";
            if (i % 3 == 0) {
                s += "Fizz";
            }
            if (i % 5 == 0) {
                s += "Buzz";
            }
            if (s.empty()) {
                s = to_string(i);
            }
            ans.push_back(s);
        }
        return ans;
    }
};
```

#### Go

```go
func fizzBuzz(n int) []string {
	ans := make([]string, 0, n)
	for i := 1; i < n+1; i++ {
		switch {
		case i%15 == 0:
			ans = append(ans, "FizzBuzz")
		case i%3 == 0:
			ans = append(ans, "Fizz")
		case i%5 == 0:
			ans = append(ans, "Buzz")
		default:
			ans = append(ans, strconv.Itoa(i))
		}
	}
	return ans
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function (n) {
    const ans = [];
    for (let i = 1; i <= n; ++i) {
        if (i % 15 === 0) {
            ans.push('FizzBuzz');
        } else if (i % 3 === 0) {
            ans.push('Fizz');
        } else if (i % 5 === 0) {
            ans.push('Buzz');
        } else {
            ans.push(`${i}`);
        }
    }
    return ans;
};
```

#### PHP

```php
class Solution {
    /**
     * @param Integer $n
     * @return String[]
     */
    function fizzBuzz($n) {
        $ans = [];
        for ($i = 1; $i <= $n; ++$i) {
            $s = '';
            if ($i % 3 == 0) {
                $s .= 'Fizz';
            }
            if ($i % 5 == 0) {
                $s .= 'Buzz';
            }
            if (strlen($s) == 0) {
                $s .= $i;
            }
            $ans[] = $s;
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

# [413. 等差数列划分](https://leetcode.cn/problems/arithmetic-slices){#413}

{{< tabs "413" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = cnt = 0
        d = 3000
        for a, b in pairwise(nums):
            if b - a == d:
                cnt += 1
            else:
                d = b - a
                cnt = 0
            ans += cnt
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int ans = 0, cnt = 0;
        int d = 3000;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i + 1] - nums[i] == d) {
                ++cnt;
            } else {
                d = nums[i + 1] - nums[i];
                cnt = 0;
            }
            ans += cnt;
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
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, cnt = 0;
        int d = 3000;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] == d) {
                ++cnt;
            } else {
                d = nums[i + 1] - nums[i];
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberOfArithmeticSlices(nums []int) (ans int) {
	cnt, d := 0, 3000
	for i, b := range nums[1:] {
		a := nums[i]
		if b-a == d {
			cnt++
		} else {
			d = b - a
			cnt = 0
		}
		ans += cnt
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberOfArithmeticSlices(nums: number[]): number {
    let ans = 0;
    let cnt = 0;
    let d = 3000;
    for (let i = 0; i < nums.length - 1; ++i) {
        const a = nums[i];
        const b = nums[i + 1];
        if (b - a == d) {
            ++cnt;
        } else {
            d = b - a;
            cnt = 0;
        }
        ans += cnt;
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

<p>如果一个数列 <strong>至少有三个元素</strong> ，并且任意两个相邻元素之差相同，则称该数列为等差数列。</p>

<ul>
	<li>例如，<code>[1,3,5,7,9]</code>、<code>[7,7,7,7]</code> 和 <code>[3,-1,-5,-9]</code> 都是等差数列。</li>
</ul>

<div class="original__bRMd">
<div>
<p>给你一个整数数组 <code>nums</code> ，返回数组 <code>nums</code> 中所有为等差数组的 <strong>子数组</strong> 个数。</p>

<p><strong>子数组</strong> 是数组中的一个连续序列。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,4]
<strong>输出：</strong>3
<strong>解释：</strong>nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1,2,3,4] 自身。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1]
<strong>输出：</strong>0
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 5000</code></li>
	<li><code>-1000 <= nums[i] <= 1000</code></li>
</ul>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历计数

我们用 $d$ 表示当前相邻两个元素的差值，用 $cnt$ 表示当前等差数列的长度，初始时 $d = 3000$, $cnt = 2$。

遍历数组 `nums`，对于相邻的两个元素 $a$ 和 $b$，如果 $b - a = d$，则说明当前元素 $b$ 也属于当前等差数列，此时 $cnt$ 自增 1；否则说明当前元素 $b$ 不属于当前等差数列，此时更新 $d = b - a$，且 $cnt = 2$。如果 $cnt \ge 3$，则说明当前等差数列的长度至少为 3，此时等差数列的个数为 $cnt - 2$，将其加到答案中。

遍历结束后，即可得到答案。

在代码实现上，我们也可以将 $cnt$ 初始化为 $0$，重置 $cnt$ 时，直接将 $cnt$ 置为 $0$；累加答案时，直接累加 $cnt$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(1)$。其中 $n$ 是数组 `nums` 的长度。

相似题目：

-   [1513. 仅含 1 的子串数](https://github.com/doocs/leetcode/blob/main/solution/1500-1599/1513.Number%20of%20Substrings%20With%20Only%201s/README.md)
-   [2348. 全 0 子数组的数目](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2348.Number%20of%20Zero-Filled%20Subarrays/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = cnt = 0
        d = 3000
        for a, b in pairwise(nums):
            if b - a == d:
                cnt += 1
            else:
                d = b - a
                cnt = 0
            ans += cnt
        return ans
```

#### Java

```java
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int ans = 0, cnt = 0;
        int d = 3000;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i + 1] - nums[i] == d) {
                ++cnt;
            } else {
                d = nums[i + 1] - nums[i];
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0, cnt = 0;
        int d = 3000;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] == d) {
                ++cnt;
            } else {
                d = nums[i + 1] - nums[i];
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
};
```

#### Go

```go
func numberOfArithmeticSlices(nums []int) (ans int) {
	cnt, d := 0, 3000
	for i, b := range nums[1:] {
		a := nums[i]
		if b-a == d {
			cnt++
		} else {
			d = b - a
			cnt = 0
		}
		ans += cnt
	}
	return
}
```

#### TypeScript

```ts
function numberOfArithmeticSlices(nums: number[]): number {
    let ans = 0;
    let cnt = 0;
    let d = 3000;
    for (let i = 0; i < nums.length - 1; ++i) {
        const a = nums[i];
        const b = nums[i + 1];
        if (b - a == d) {
            ++cnt;
        } else {
            d = b - a;
            cnt = 0;
        }
        ans += cnt;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [414. 第三大的数](https://leetcode.cn/problems/third-maximum-number){#414}

{{< tabs "414" >}}

{{% tab "python" %}}
```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        m1 = m2 = m3 = -inf
        for num in nums:
            if num in [m1, m2, m3]:
                continue
            if num > m1:
                m3, m2, m1 = m2, m1, num
            elif num > m2:
                m3, m2 = m2, num
            elif num > m3:
                m3 = num
        return m3 if m3 != -inf else m1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int thirdMax(int[] nums) {
        long m1 = Long.MIN_VALUE;
        long m2 = Long.MIN_VALUE;
        long m3 = Long.MIN_VALUE;
        for (int num : nums) {
            if (num == m1 || num == m2 || num == m3) {
                continue;
            }
            if (num > m1) {
                m3 = m2;
                m2 = m1;
                m1 = num;
            } else if (num > m2) {
                m3 = m2;
                m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }
        return (int) (m3 != Long.MIN_VALUE ? m3 : m1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        for (int num : nums) {
            if (num == m1 || num == m2 || num == m3) continue;
            if (num > m1) {
                m3 = m2;
                m2 = m1;
                m1 = num;
            } else if (num > m2) {
                m3 = m2;
                m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }
        return (int) (m3 != LONG_MIN ? m3 : m1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func thirdMax(nums []int) int {
	m1, m2, m3 := math.MinInt64, math.MinInt64, math.MinInt64
	for _, num := range nums {
		if num == m1 || num == m2 || num == m3 {
			continue
		}
		if num > m1 {
			m3, m2, m1 = m2, m1, num
		} else if num > m2 {
			m3, m2 = m2, num
		} else if num > m3 {
			m3 = num
		}
	}
	if m3 != math.MinInt64 {
		return m3
	}
	return m1
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个非空数组，返回此数组中 <strong>第三大的数</strong> 。如果不存在，则返回数组中最大的数。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>[3, 2, 1]
<strong>输出：</strong>1
<strong>解释：</strong>第三大的数是 1 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>[1, 2]
<strong>输出：</strong>2
<strong>解释：</strong>第三大的数不存在, 所以返回最大的数 2 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>[2, 2, 3, 1]
<strong>输出：</strong>1
<strong>解释：</strong>注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1</code></li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你能设计一个时间复杂度 <code>O(n)</code> 的解决方案吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以使用三个变量 $m_1$, $m_2$, $m_3$ 分别表示数组中的第一大、第二大和第三大的数。初始时，我们将这三个变量都赋值为负无穷大。

然后，我们遍历数组中的每个数，对于每个数，我们将其与 $m_1$, $m_2$, $m_3$ 进行比较，根据比较的结果更新这三个变量。具体地，我们遍历数组中的每个数，对于每个数：

-   如果这个数等于 $m_1$, $m_2$, $m_3$ 中的任何一个，我们跳过这个数；
-   如果这个数大于 $m_1$，我们将 $m_1$, $m_2$, $m_3$ 的值更新为 $m_2$, $m_3$, 这个数；
-   如果这个数大于 $m_2$，我们将 $m_2$, $m_3$ 的值更新为 $m_3$, 这个数；
-   如果这个数大于 $m_3$，我们将 $m_3$ 的值更新为这个数。

最后，如果 $m_3$ 的值没有被更新，说明数组中不存在第三大的数，那么我们返回 $m_1$，否则我们返回 $m_3$。

时间复杂度 $O(n)$，其中 $n$ 是数组 `nums` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        m1 = m2 = m3 = -inf
        for num in nums:
            if num in [m1, m2, m3]:
                continue
            if num > m1:
                m3, m2, m1 = m2, m1, num
            elif num > m2:
                m3, m2 = m2, num
            elif num > m3:
                m3 = num
        return m3 if m3 != -inf else m1
```

#### Java

```java
class Solution {
    public int thirdMax(int[] nums) {
        long m1 = Long.MIN_VALUE;
        long m2 = Long.MIN_VALUE;
        long m3 = Long.MIN_VALUE;
        for (int num : nums) {
            if (num == m1 || num == m2 || num == m3) {
                continue;
            }
            if (num > m1) {
                m3 = m2;
                m2 = m1;
                m1 = num;
            } else if (num > m2) {
                m3 = m2;
                m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }
        return (int) (m3 != Long.MIN_VALUE ? m3 : m1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long m1 = LONG_MIN, m2 = LONG_MIN, m3 = LONG_MIN;
        for (int num : nums) {
            if (num == m1 || num == m2 || num == m3) continue;
            if (num > m1) {
                m3 = m2;
                m2 = m1;
                m1 = num;
            } else if (num > m2) {
                m3 = m2;
                m2 = num;
            } else if (num > m3) {
                m3 = num;
            }
        }
        return (int) (m3 != LONG_MIN ? m3 : m1);
    }
};
```

#### Go

```go
func thirdMax(nums []int) int {
	m1, m2, m3 := math.MinInt64, math.MinInt64, math.MinInt64
	for _, num := range nums {
		if num == m1 || num == m2 || num == m3 {
			continue
		}
		if num > m1 {
			m3, m2, m1 = m2, m1, num
		} else if num > m2 {
			m3, m2 = m2, num
		} else if num > m3 {
			m3 = num
		}
	}
	if m3 != math.MinInt64 {
		return m3
	}
	return m1
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [415. 字符串相加](https://leetcode.cn/problems/add-strings){#415}

{{< tabs "415" >}}

{{% tab "python" %}}
```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i, j = len(num1) - 1, len(num2) - 1
        ans = []
        c = 0
        while i >= 0 or j >= 0 or c:
            a = 0 if i < 0 else int(num1[i])
            b = 0 if j < 0 else int(num2[j])
            c, v = divmod(a + b + c, 10)
            ans.append(str(v))
            i, j = i - 1, j - 1
        return "".join(ans[::-1])

    def subStrings(self, num1: str, num2: str) -> str:
        m, n = len(num1), len(num2)
        neg = m < n or (m == n and num1 < num2)
        if neg:
            num1, num2 = num2, num1
        i, j = len(num1) - 1, len(num2) - 1
        ans = []
        c = 0
        while i >= 0:
            c = int(num1[i]) - c - (0 if j < 0 else int(num2[j]))
            ans.append(str((c + 10) % 10))
            c = 1 if c < 0 else 0
            i, j = i - 1, j - 1
        while len(ans) > 1 and ans[-1] == '0':
            ans.pop()
        if neg:
            ans.append('-')
        return ''.join(ans[::-1])
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String addStrings(String num1, String num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        StringBuilder ans = new StringBuilder();
        for (int c = 0; i >= 0 || j >= 0 || c > 0; --i, --j) {
            int a = i < 0 ? 0 : num1.charAt(i) - '0';
            int b = j < 0 ? 0 : num2.charAt(j) - '0';
            c += a + b;
            ans.append(c % 10);
            c /= 10;
        }
        return ans.reverse().toString();
    }

    public String subStrings(String num1, String num2) {
        int m = num1.length(), n = num2.length();
        boolean neg = m < n || (m == n && num1.compareTo(num2) < 0);
        if (neg) {
            String t = num1;
            num1 = num2;
            num2 = t;
        }
        int i = num1.length() - 1, j = num2.length() - 1;
        StringBuilder ans = new StringBuilder();
        for (int c = 0; i >= 0; --i, --j) {
            c = (num1.charAt(i) - '0') - c - (j < 0 ? 0 : num2.charAt(j) - '0');
            ans.append((c + 10) % 10);
            c = c < 0 ? 1 : 0;
        }
        while (ans.length() > 1 && ans.charAt(ans.length() - 1) == '0') {
            ans.deleteCharAt(ans.length() - 1);
        }
        if (neg) {
            ans.append('-');
        }
        return ans.reverse().toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans;
        for (int c = 0; i >= 0 || j >= 0 || c; --i, --j) {
            int a = i < 0 ? 0 : num1[i] - '0';
            int b = j < 0 ? 0 : num2[j] - '0';
            c += a + b;
            ans += to_string(c % 10);
            c /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string subStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        bool neg = m < n || (m == n && num1 < num2);
        if (neg) {
            swap(num1, num2);
        }
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans;
        for (int c = 0; i >= 0; --i, --j) {
            c = (num1[i] - '0') - c - (j < 0 ? 0 : num2[j] - '0');
            ans += to_string((c + 10) % 10);
            c = c < 0 ? 1 : 0;
        }
        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        if (neg) {
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func addStrings(num1 string, num2 string) string {
	i, j := len(num1)-1, len(num2)-1
	ans := []byte{}
	for c := 0; i >= 0 || j >= 0 || c > 0; i, j = i-1, j-1 {
		if i >= 0 {
			c += int(num1[i] - '0')
		}
		if j >= 0 {
			c += int(num2[j] - '0')
		}
		ans = append(ans, byte(c%10+'0'))
		c /= 10
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}

func subStrings(num1 string, num2 string) string {
	m, n := len(num1), len(num2)
	neg := m < n || (m == n && num1 < num2)
	if neg {
		num1, num2 = num2, num1
	}
	i, j := len(num1)-1, len(num2)-1
	ans := []byte{}
	for c := 0; i >= 0; i, j = i-1, j-1 {
		c = int(num1[i]-'0') - c
		if j >= 0 {
			c -= int(num2[j] - '0')
		}
		ans = append(ans, byte((c+10)%10+'0'))
		if c < 0 {
			c = 1
		} else {
			c = 0
		}
	}
	for len(ans) > 1 && ans[len(ans)-1] == '0' {
		ans = ans[:len(ans)-1]
	}
	if neg {
		ans = append(ans, '-')
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function addStrings(num1: string, num2: string): string {
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans: number[] = [];
    for (let c = 0; i >= 0 || j >= 0 || c; --i, --j) {
        c += i < 0 ? 0 : +num1[i];
        c += j < 0 ? 0 : +num2[j];
        ans.push(c % 10);
        c = Math.floor(c / 10);
    }
    return ans.reverse().join('');
}

function subStrings(num1: string, num2: string): string {
    const m = num1.length;
    const n = num2.length;
    const neg = m < n || (m == n && num1 < num2);
    if (neg) {
        const t = num1;
        num1 = num2;
        num2 = t;
    }
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans: number[] = [];
    for (let c = 0; i >= 0; --i, --j) {
        c = +num1[i] - c;
        if (j >= 0) {
            c -= +num2[j];
        }
        ans.push((c + 10) % 10);
        c = c < 0 ? 1 : 0;
    }
    while (ans.length > 1 && ans.at(-1) === 0) {
        ans.pop();
    }
    return (neg ? '-' : '') + ans.reverse().join('');
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn add_strings(num1: String, num2: String) -> String {
        let mut res = vec![];
        let s1 = num1.as_bytes();
        let s2 = num2.as_bytes();
        let (mut i, mut j) = (s1.len(), s2.len());
        let mut is_over = false;
        while i != 0 || j != 0 || is_over {
            let mut sum = if is_over { 1 } else { 0 };
            if i != 0 {
                sum += (s1[i - 1] - b'0') as i32;
                i -= 1;
            }
            if j != 0 {
                sum += (s2[j - 1] - b'0') as i32;
                j -= 1;
            }
            is_over = sum >= 10;
            res.push((sum % 10).to_string());
        }
        res.into_iter().rev().collect()
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function (num1, num2) {
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans = [];
    for (let c = 0; i >= 0 || j >= 0 || c; --i, --j) {
        c += i < 0 ? 0 : +num1[i];
        c += j < 0 ? 0 : +num2[j];
        ans.push(c % 10);
        c = Math.floor(c / 10);
    }
    return ans.reverse().join('');
};

/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var subStrings = function (num1, num2) {
    const m = num1.length;
    const n = num2.length;
    const neg = m < n || (m == n && num1 < num2);
    if (neg) {
        const t = num1;
        num1 = num2;
        num2 = t;
    }
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans = [];
    for (let c = 0; i >= 0; --i, --j) {
        c = +num1[i] - c;
        if (j >= 0) {
            c -= +num2[j];
        }
        ans.push((c + 10) % 10);
        c = c < 0 ? 1 : 0;
    }
    while (ans.length > 1 && ans.at(-1) === 0) {
        ans.pop();
    }
    return (neg ? '-' : '') + ans.reverse().join('');
};
```
{{% /tab %}}
{{% tab "kotlin" %}}
```kotlin
class Solution {
    fun addStrings(num1: String, num2: String): String {
        val result = mutableListOf<Int>()

        val chars_1 = num1.toCharArray()
        val chars_2 = num2.toCharArray()
        var over = 0
        var i = num1.length
        var j = num2.length

        while (i > 0 || j > 0 || over > 0) {
            val a = if (i > 0) chars_1[--i] - '0' else 0
            val b = if (j > 0) chars_2[--j] - '0' else 0
            val sum = a + b + over
            over = sum / 10
            result.add(sum % 10)
        }

        return result.reversed().joinToString("")
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串形式的非负整数&nbsp;<code>num1</code> 和<code>num2</code>&nbsp;，计算它们的和并同样以字符串形式返回。</p>

<p>你不能使用任何內建的用于处理大整数的库（比如 <code>BigInteger</code>），&nbsp;也不能直接将输入的字符串转换为整数形式。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>num1 = "11", num2 = "123"
<strong>输出：</strong>"134"
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>num1 = "456", num2 = "77"
<strong>输出：</strong>"533"
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>num1 = "0", num2 = "0"
<strong>输出：</strong>"0"
</pre>

<p>&nbsp;</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= num1.length, num2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>num1</code> 和<code>num2</code> 都只包含数字&nbsp;<code>0-9</code></li>
	<li><code>num1</code> 和<code>num2</code> 都不包含任何前导零</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用两个指针 $i$ 和 $j$ 分别指向两个字符串的末尾，从末尾开始逐位相加。每次取出对应位的数字 $a$ 和 $b$，计算它们的和 $a + b + c$，其中 $c$ 表示上一次相加的进位，最后将 $a + b + c$ 的个位数添加到追加到答案字符串的末尾，然后将 $a + b + c$ 的十位数作为进位 $c$ 的值，循环此过程直至两个字符串的指针都已经指向了字符串的开头并且进位 $c$ 的值为 $0$。

最后将答案字符串反转并返回即可。

时间复杂度 $O(\max(m, n))$，其中 $m$ 和 $n$ 分别是两个字符串的长度。忽略答案字符串的空间消耗，空间复杂度 $O(1)$。

以下代码还实现了字符串相减，参考 `subStrings(num1, num2)` 函数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i, j = len(num1) - 1, len(num2) - 1
        ans = []
        c = 0
        while i >= 0 or j >= 0 or c:
            a = 0 if i < 0 else int(num1[i])
            b = 0 if j < 0 else int(num2[j])
            c, v = divmod(a + b + c, 10)
            ans.append(str(v))
            i, j = i - 1, j - 1
        return "".join(ans[::-1])

    def subStrings(self, num1: str, num2: str) -> str:
        m, n = len(num1), len(num2)
        neg = m < n or (m == n and num1 < num2)
        if neg:
            num1, num2 = num2, num1
        i, j = len(num1) - 1, len(num2) - 1
        ans = []
        c = 0
        while i >= 0:
            c = int(num1[i]) - c - (0 if j < 0 else int(num2[j]))
            ans.append(str((c + 10) % 10))
            c = 1 if c < 0 else 0
            i, j = i - 1, j - 1
        while len(ans) > 1 and ans[-1] == '0':
            ans.pop()
        if neg:
            ans.append('-')
        return ''.join(ans[::-1])
```

#### Java

```java
class Solution {
    public String addStrings(String num1, String num2) {
        int i = num1.length() - 1, j = num2.length() - 1;
        StringBuilder ans = new StringBuilder();
        for (int c = 0; i >= 0 || j >= 0 || c > 0; --i, --j) {
            int a = i < 0 ? 0 : num1.charAt(i) - '0';
            int b = j < 0 ? 0 : num2.charAt(j) - '0';
            c += a + b;
            ans.append(c % 10);
            c /= 10;
        }
        return ans.reverse().toString();
    }

    public String subStrings(String num1, String num2) {
        int m = num1.length(), n = num2.length();
        boolean neg = m < n || (m == n && num1.compareTo(num2) < 0);
        if (neg) {
            String t = num1;
            num1 = num2;
            num2 = t;
        }
        int i = num1.length() - 1, j = num2.length() - 1;
        StringBuilder ans = new StringBuilder();
        for (int c = 0; i >= 0; --i, --j) {
            c = (num1.charAt(i) - '0') - c - (j < 0 ? 0 : num2.charAt(j) - '0');
            ans.append((c + 10) % 10);
            c = c < 0 ? 1 : 0;
        }
        while (ans.length() > 1 && ans.charAt(ans.length() - 1) == '0') {
            ans.deleteCharAt(ans.length() - 1);
        }
        if (neg) {
            ans.append('-');
        }
        return ans.reverse().toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans;
        for (int c = 0; i >= 0 || j >= 0 || c; --i, --j) {
            int a = i < 0 ? 0 : num1[i] - '0';
            int b = j < 0 ? 0 : num2[j] - '0';
            c += a + b;
            ans += to_string(c % 10);
            c /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string subStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        bool neg = m < n || (m == n && num1 < num2);
        if (neg) {
            swap(num1, num2);
        }
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans;
        for (int c = 0; i >= 0; --i, --j) {
            c = (num1[i] - '0') - c - (j < 0 ? 0 : num2[j] - '0');
            ans += to_string((c + 10) % 10);
            c = c < 0 ? 1 : 0;
        }
        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        if (neg) {
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

#### Go

```go
func addStrings(num1 string, num2 string) string {
	i, j := len(num1)-1, len(num2)-1
	ans := []byte{}
	for c := 0; i >= 0 || j >= 0 || c > 0; i, j = i-1, j-1 {
		if i >= 0 {
			c += int(num1[i] - '0')
		}
		if j >= 0 {
			c += int(num2[j] - '0')
		}
		ans = append(ans, byte(c%10+'0'))
		c /= 10
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}

func subStrings(num1 string, num2 string) string {
	m, n := len(num1), len(num2)
	neg := m < n || (m == n && num1 < num2)
	if neg {
		num1, num2 = num2, num1
	}
	i, j := len(num1)-1, len(num2)-1
	ans := []byte{}
	for c := 0; i >= 0; i, j = i-1, j-1 {
		c = int(num1[i]-'0') - c
		if j >= 0 {
			c -= int(num2[j] - '0')
		}
		ans = append(ans, byte((c+10)%10+'0'))
		if c < 0 {
			c = 1
		} else {
			c = 0
		}
	}
	for len(ans) > 1 && ans[len(ans)-1] == '0' {
		ans = ans[:len(ans)-1]
	}
	if neg {
		ans = append(ans, '-')
	}
	for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
		ans[i], ans[j] = ans[j], ans[i]
	}
	return string(ans)
}
```

#### TypeScript

```ts
function addStrings(num1: string, num2: string): string {
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans: number[] = [];
    for (let c = 0; i >= 0 || j >= 0 || c; --i, --j) {
        c += i < 0 ? 0 : +num1[i];
        c += j < 0 ? 0 : +num2[j];
        ans.push(c % 10);
        c = Math.floor(c / 10);
    }
    return ans.reverse().join('');
}

function subStrings(num1: string, num2: string): string {
    const m = num1.length;
    const n = num2.length;
    const neg = m < n || (m == n && num1 < num2);
    if (neg) {
        const t = num1;
        num1 = num2;
        num2 = t;
    }
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans: number[] = [];
    for (let c = 0; i >= 0; --i, --j) {
        c = +num1[i] - c;
        if (j >= 0) {
            c -= +num2[j];
        }
        ans.push((c + 10) % 10);
        c = c < 0 ? 1 : 0;
    }
    while (ans.length > 1 && ans.at(-1) === 0) {
        ans.pop();
    }
    return (neg ? '-' : '') + ans.reverse().join('');
}
```

#### Rust

```rust
impl Solution {
    pub fn add_strings(num1: String, num2: String) -> String {
        let mut res = vec![];
        let s1 = num1.as_bytes();
        let s2 = num2.as_bytes();
        let (mut i, mut j) = (s1.len(), s2.len());
        let mut is_over = false;
        while i != 0 || j != 0 || is_over {
            let mut sum = if is_over { 1 } else { 0 };
            if i != 0 {
                sum += (s1[i - 1] - b'0') as i32;
                i -= 1;
            }
            if j != 0 {
                sum += (s2[j - 1] - b'0') as i32;
                j -= 1;
            }
            is_over = sum >= 10;
            res.push((sum % 10).to_string());
        }
        res.into_iter().rev().collect()
    }
}
```

#### JavaScript

```js
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function (num1, num2) {
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans = [];
    for (let c = 0; i >= 0 || j >= 0 || c; --i, --j) {
        c += i < 0 ? 0 : +num1[i];
        c += j < 0 ? 0 : +num2[j];
        ans.push(c % 10);
        c = Math.floor(c / 10);
    }
    return ans.reverse().join('');
};

/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var subStrings = function (num1, num2) {
    const m = num1.length;
    const n = num2.length;
    const neg = m < n || (m == n && num1 < num2);
    if (neg) {
        const t = num1;
        num1 = num2;
        num2 = t;
    }
    let i = num1.length - 1;
    let j = num2.length - 1;
    const ans = [];
    for (let c = 0; i >= 0; --i, --j) {
        c = +num1[i] - c;
        if (j >= 0) {
            c -= +num2[j];
        }
        ans.push((c + 10) % 10);
        c = c < 0 ? 1 : 0;
    }
    while (ans.length > 1 && ans.at(-1) === 0) {
        ans.pop();
    }
    return (neg ? '-' : '') + ans.reverse().join('');
};
```

#### Kotlin

```kotlin
class Solution {
    fun addStrings(num1: String, num2: String): String {
        val result = mutableListOf<Int>()

        val chars_1 = num1.toCharArray()
        val chars_2 = num2.toCharArray()
        var over = 0
        var i = num1.length
        var j = num2.length

        while (i > 0 || j > 0 || over > 0) {
            val a = if (i > 0) chars_1[--i] - '0' else 0
            val b = if (j > 0) chars_2[--j] - '0' else 0
            val sum = a + b + over
            over = sum / 10
            result.add(sum % 10)
        }

        return result.reversed().joinToString("")
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [416. 分割等和子集](https://leetcode.cn/problems/partition-equal-subset-sum){#416}

{{< tabs "416" >}}

{{% tab "python" %}}
```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        m, mod = divmod(sum(nums), 2)
        if mod:
            return False
        f = [True] + [False] * m
        for x in nums:
            for j in range(m, x - 1, -1):
                f[j] = f[j] or f[j - x]
        return f[m]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canPartition(int[] nums) {
        // int s = Arrays.stream(nums).sum();
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        if (s % 2 == 1) {
            return false;
        }
        int m = s >> 1;
        boolean[] f = new boolean[m + 1];
        f[0] = true;
        for (int x : nums) {
            for (int j = m; j >= x; --j) {
                f[j] |= f[j - x];
            }
        }
        return f[m];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1) {
            return false;
        }
        int m = s >> 1;
        bool f[m + 1];
        memset(f, false, sizeof(f));
        f[0] = true;
        for (int& x : nums) {
            for (int j = m; j >= x; --j) {
                f[j] |= f[j - x];
            }
        }
        return f[m];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canPartition(nums []int) bool {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s%2 == 1 {
		return false
	}
	m := s >> 1
	f := make([]bool, m+1)
	f[0] = true
	for _, x := range nums {
		for j := m; j >= x; j-- {
			f[j] = f[j] || f[j-x]
		}
	}
	return f[m]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canPartition(nums: number[]): boolean {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s % 2 === 1) {
        return false;
    }
    const m = s >> 1;
    const f: boolean[] = Array(m + 1).fill(false);
    f[0] = true;
    for (const x of nums) {
        for (let j = m; j >= x; --j) {
            f[j] = f[j] || f[j - x];
        }
    }
    return f[m];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let s: i32 = nums.iter().sum();
        if s % 2 != 0 {
            return false;
        }
        let m = (s / 2) as usize;
        let mut f = vec![false; m + 1];
        f[0] = true;

        for x in nums {
            let x = x as usize;
            for j in (x..=m).rev() {
                f[j] = f[j] || f[j - x];
            }
        }

        f[m]
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s % 2 === 1) {
        return false;
    }
    const m = s >> 1;
    const f = Array(m + 1).fill(false);
    f[0] = true;
    for (const x of nums) {
        for (let j = m; j >= x; --j) {
            f[j] = f[j] || f[j - x];
        }
    }
    return f[m];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <strong>只包含正整数 </strong>的 <strong>非空 </strong>数组 <code>nums</code> 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,11,5]
<strong>输出：</strong>true
<strong>解释：</strong>数组可以分割成 [1, 5, 5] 和 [11] 。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,2,3,5]
<strong>输出：</strong>false
<strong>解释：</strong>数组不能分割成两个元素和相等的子集。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 200</code></li>
	<li><code>1 <= nums[i] <= 100</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们先计算出数组的总和 $s$，如果总和是奇数，那么一定不能分割成两个和相等的子集，直接返回 $false$。如果总和是偶数，我们记目标子集的和为 $m = \frac{s}{2}$，那么问题就转化成了：是否存在一个子集，使得其元素的和为 $m$。

我们定义 $f[i][j]$ 表示前 $i$ 个数中选取若干个数，使得其元素的和恰好为 $j$。初始时 $f[0][0] = true$，其余 $f[i][j] = false$。答案为 $f[n][m]$。

考虑 $f[i][j]$，如果我们选取了第 $i$ 个数 $x$，那么 $f[i][j] = f[i - 1][j - x]$；如果我们没有选取第 $i$ 个数 $x$，那么 $f[i][j] = f[i - 1][j]$。因此状态转移方程为：

$$
f[i][j] = f[i - 1][j] \textit{ or } f[i - 1][j - x] \textit{ if } j \geq x
$$

最终答案为 $f[n][m]$。

时间复杂度 $(m \times n)$，空间复杂度 $(m \times n)$。其中 $m$ 和 $n$ 分别为数组的总和的一半和数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        m, mod = divmod(sum(nums), 2)
        if mod:
            return False
        n = len(nums)
        f = [[False] * (m + 1) for _ in range(n + 1)]
        f[0][0] = True
        for i, x in enumerate(nums, 1):
            for j in range(m + 1):
                f[i][j] = f[i - 1][j] or (j >= x and f[i - 1][j - x])
        return f[n][m]
```

#### Java

```java
class Solution {
    public boolean canPartition(int[] nums) {
        // int s = Arrays.stream(nums).sum();
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        if (s % 2 == 1) {
            return false;
        }
        int n = nums.length;
        int m = s >> 1;
        boolean[][] f = new boolean[n + 1][m + 1];
        f[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            for (int j = 0; j <= m; ++j) {
                f[i][j] = f[i - 1][j] || (j >= x && f[i - 1][j - x]);
            }
        }
        return f[n][m];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1) {
            return false;
        }
        int n = nums.size();
        int m = s >> 1;
        bool f[n + 1][m + 1];
        memset(f, false, sizeof(f));
        f[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            int x = nums[i - 1];
            for (int j = 0; j <= m; ++j) {
                f[i][j] = f[i - 1][j] || (j >= x && f[i - 1][j - x]);
            }
        }
        return f[n][m];
    }
};
```

#### Go

```go
func canPartition(nums []int) bool {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s%2 == 1 {
		return false
	}
	n, m := len(nums), s>>1
	f := make([][]bool, n+1)
	for i := range f {
		f[i] = make([]bool, m+1)
	}
	f[0][0] = true
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		for j := 0; j <= m; j++ {
			f[i][j] = f[i-1][j] || (j >= x && f[i-1][j-x])
		}
	}
	return f[n][m]
}
```

#### TypeScript

```ts
function canPartition(nums: number[]): boolean {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s % 2 === 1) {
        return false;
    }
    const n = nums.length;
    const m = s >> 1;
    const f: boolean[][] = Array.from({ length: n + 1 }, () => Array(m + 1).fill(false));
    f[0][0] = true;
    for (let i = 1; i <= n; ++i) {
        const x = nums[i - 1];
        for (let j = 0; j <= m; ++j) {
            f[i][j] = f[i - 1][j] || (j >= x && f[i - 1][j - x]);
        }
    }
    return f[n][m];
}
```

#### Rust

```rust
impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let s: i32 = nums.iter().sum();
        if s % 2 != 0 {
            return false;
        }
        let m = (s / 2) as usize;
        let n = nums.len();
        let mut f = vec![vec![false; m + 1]; n + 1];
        f[0][0] = true;

        for i in 1..=n {
            let x = nums[i - 1] as usize;
            for j in 0..=m {
                f[i][j] = f[i - 1][j] || (j >= x && f[i - 1][j - x]);
            }
        }

        f[n][m]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s % 2 === 1) {
        return false;
    }
    const n = nums.length;
    const m = s >> 1;
    const f = Array.from({ length: n + 1 }, () => Array(m + 1).fill(false));
    f[0][0] = true;
    for (let i = 1; i <= n; ++i) {
        const x = nums[i - 1];
        for (let j = 0; j <= m; ++j) {
            f[i][j] = f[i - 1][j] || (j >= x && f[i - 1][j - x]);
        }
    }
    return f[n][m];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划（空间优化）

我们注意到，方法一中 $f[i][j]$ 只与 $f[i - 1][\cdot]$ 有关，因此我们可以将二维数组压缩成一维数组。

时间复杂度 $O(n \times m)$，空间复杂度 $O(m)$。其中 $n$ 是数组的长度，而 $m$ 是数组的总和的一半。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        m, mod = divmod(sum(nums), 2)
        if mod:
            return False
        f = [True] + [False] * m
        for x in nums:
            for j in range(m, x - 1, -1):
                f[j] = f[j] or f[j - x]
        return f[m]
```

#### Java

```java
class Solution {
    public boolean canPartition(int[] nums) {
        // int s = Arrays.stream(nums).sum();
        int s = 0;
        for (int x : nums) {
            s += x;
        }
        if (s % 2 == 1) {
            return false;
        }
        int m = s >> 1;
        boolean[] f = new boolean[m + 1];
        f[0] = true;
        for (int x : nums) {
            for (int j = m; j >= x; --j) {
                f[j] |= f[j - x];
            }
        }
        return f[m];
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1) {
            return false;
        }
        int m = s >> 1;
        bool f[m + 1];
        memset(f, false, sizeof(f));
        f[0] = true;
        for (int& x : nums) {
            for (int j = m; j >= x; --j) {
                f[j] |= f[j - x];
            }
        }
        return f[m];
    }
};
```

#### Go

```go
func canPartition(nums []int) bool {
	s := 0
	for _, x := range nums {
		s += x
	}
	if s%2 == 1 {
		return false
	}
	m := s >> 1
	f := make([]bool, m+1)
	f[0] = true
	for _, x := range nums {
		for j := m; j >= x; j-- {
			f[j] = f[j] || f[j-x]
		}
	}
	return f[m]
}
```

#### TypeScript

```ts
function canPartition(nums: number[]): boolean {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s % 2 === 1) {
        return false;
    }
    const m = s >> 1;
    const f: boolean[] = Array(m + 1).fill(false);
    f[0] = true;
    for (const x of nums) {
        for (let j = m; j >= x; --j) {
            f[j] = f[j] || f[j - x];
        }
    }
    return f[m];
}
```

#### Rust

```rust
impl Solution {
    pub fn can_partition(nums: Vec<i32>) -> bool {
        let s: i32 = nums.iter().sum();
        if s % 2 != 0 {
            return false;
        }
        let m = (s / 2) as usize;
        let mut f = vec![false; m + 1];
        f[0] = true;

        for x in nums {
            let x = x as usize;
            for j in (x..=m).rev() {
                f[j] = f[j] || f[j - x];
            }
        }

        f[m]
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function (nums) {
    const s = nums.reduce((a, b) => a + b, 0);
    if (s % 2 === 1) {
        return false;
    }
    const m = s >> 1;
    const f = Array(m + 1).fill(false);
    f[0] = true;
    for (const x of nums) {
        for (let j = m; j >= x; --j) {
            f[j] = f[j] || f[j - x];
        }
    }
    return f[m];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [417. 太平洋大西洋水流问题](https://leetcode.cn/problems/pacific-atlantic-water-flow){#417}

{{< tabs "417" >}}

{{% tab "python" %}}
```python
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        def bfs(q, vis):
            while q:
                for _ in range(len(q)):
                    i, j = q.popleft()
                    for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                        x, y = i + a, j + b
                        if (
                            0 <= x < m
                            and 0 <= y < n
                            and (x, y) not in vis
                            and heights[x][y] >= heights[i][j]
                        ):
                            vis.add((x, y))
                            q.append((x, y))

        m, n = len(heights), len(heights[0])
        vis1, vis2 = set(), set()
        q1 = deque()
        q2 = deque()
        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0:
                    vis1.add((i, j))
                    q1.append((i, j))
                if i == m - 1 or j == n - 1:
                    vis2.add((i, j))
                    q2.append((i, j))
        bfs(q1, vis1)
        bfs(q2, vis2)
        return [
            (i, j)
            for i in range(m)
            for j in range(n)
            if (i, j) in vis1 and (i, j) in vis2
        ]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int[][] heights;
    private int m;
    private int n;

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        m = heights.length;
        n = heights[0].length;
        this.heights = heights;
        Deque<int[]> q1 = new LinkedList<>();
        Deque<int[]> q2 = new LinkedList<>();
        Set<Integer> vis1 = new HashSet<>();
        Set<Integer> vis2 = new HashSet<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    vis1.add(i * n + j);
                    q1.offer(new int[] {i, j});
                }
                if (i == m - 1 || j == n - 1) {
                    vis2.add(i * n + j);
                    q2.offer(new int[] {i, j});
                }
            }
        }
        bfs(q1, vis1);
        bfs(q2, vis2);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i * n + j;
                if (vis1.contains(x) && vis2.contains(x)) {
                    ans.add(Arrays.asList(i, j));
                }
            }
        }
        return ans;
    }

    private void bfs(Deque<int[]> q, Set<Integer> vis) {
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                int[] p = q.poll();
                for (int i = 0; i < 4; ++i) {
                    int x = p[0] + dirs[i];
                    int y = p[1] + dirs[i + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis.contains(x * n + y)
                        && heights[x][y] >= heights[p[0]][p[1]]) {
                        vis.add(x * n + y);
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> heights;
    int m;
    int n;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        this->heights = heights;
        queue<pii> q1;
        queue<pii> q2;
        unordered_set<int> vis1;
        unordered_set<int> vis2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    vis1.insert(i * n + j);
                    q1.emplace(i, j);
                }
                if (i == m - 1 || j == n - 1) {
                    vis2.insert(i * n + j);
                    q2.emplace(i, j);
                }
            }
        }
        bfs(q1, vis1);
        bfs(q2, vis2);
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i * n + j;
                if (vis1.count(x) && vis2.count(x)) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void bfs(queue<pii>& q, unordered_set<int>& vis) {
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                auto p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = p.first + dirs[i];
                    int y = p.second + dirs[i + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis.count(x * n + y) && heights[x][y] >= heights[p.first][p.second]) {
                        vis.insert(x * n + y);
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func pacificAtlantic(heights [][]int) [][]int {
	m, n := len(heights), len(heights[0])
	vis1 := make(map[int]bool)
	vis2 := make(map[int]bool)
	var q1 [][]int
	var q2 [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				vis1[i*n+j] = true
				q1 = append(q1, []int{i, j})
			}
			if i == m-1 || j == n-1 {
				vis2[i*n+j] = true
				q2 = append(q2, []int{i, j})
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	bfs := func(q [][]int, vis map[int]bool) {
		for len(q) > 0 {
			for k := len(q); k > 0; k-- {
				p := q[0]
				q = q[1:]
				for i := 0; i < 4; i++ {
					x, y := p[0]+dirs[i], p[1]+dirs[i+1]
					if x >= 0 && x < m && y >= 0 && y < n && !vis[x*n+y] && heights[x][y] >= heights[p[0]][p[1]] {
						vis[x*n+y] = true
						q = append(q, []int{x, y})
					}
				}
			}
		}
	}
	bfs(q1, vis1)
	bfs(q2, vis2)
	var ans [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			x := i*n + j
			if vis1[x] && vis2[x] {
				ans = append(ans, []int{i, j})
			}
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function pacificAtlantic(heights: number[][]): number[][] {
    const m = heights.length;
    const n = heights[0].length;
    const dirs = [
        [1, 0],
        [0, 1],
        [-1, 0],
        [0, -1],
    ];
    const gird = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const isVis = new Array(m).fill(0).map(() => new Array(n).fill(false));

    const dfs = (i: number, j: number) => {
        if (isVis[i][j]) {
            return;
        }
        gird[i][j]++;
        isVis[i][j] = true;
        const h = heights[i][j];
        for (const [x, y] of dirs) {
            if (h <= (heights[i + x] ?? [])[j + y]) {
                dfs(i + x, j + y);
            }
        }
    };

    for (let i = 0; i < n; i++) {
        dfs(0, i);
    }
    for (let i = 0; i < m; i++) {
        dfs(i, 0);
    }
    isVis.forEach(v => v.fill(false));
    for (let i = 0; i < n; i++) {
        dfs(m - 1, i);
    }
    for (let i = 0; i < m; i++) {
        dfs(i, n - 1);
    }

    const res = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (gird[i][j] === 2) {
                res.push([i, j]);
            }
        }
    }
    return res;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>有一个 <code>m × n</code> 的矩形岛屿，与 <strong>太平洋</strong> 和 <strong>大西洋</strong> 相邻。&nbsp;<strong>“太平洋”&nbsp;</strong>处于大陆的左边界和上边界，而 <strong>“大西洋”</strong> 处于大陆的右边界和下边界。</p>

<p>这个岛被分割成一个由若干方形单元格组成的网格。给定一个 <code>m x n</code> 的整数矩阵&nbsp;<code>heights</code>&nbsp;，&nbsp;<code>heights[r][c]</code>&nbsp;表示坐标 <code>(r, c)</code> 上单元格 <strong>高于海平面的高度</strong> 。</p>

<p>岛上雨水较多，如果相邻单元格的高度 <strong>小于或等于</strong> 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。</p>

<p>返回网格坐标 <code>result</code>&nbsp;的 <strong>2D 列表</strong> ，其中&nbsp;<code>result[i] = [r<sub>i</sub>, c<sub>i</sub>]</code>&nbsp;表示雨水从单元格 <code>(ri, ci)</code> 流动 <strong>既可流向太平洋也可流向大西洋</strong> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0417.Pacific%20Atlantic%20Water%20Flow/images/waterflow-grid.jpg" /></p>

<pre>
<strong>输入:</strong> heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
<strong>输出:</strong> [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> heights = [[2,1],[1,2]]
<strong>输出:</strong> [[0,0],[0,1],[1,0],[1,1]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == heights.length</code></li>
	<li><code>n == heights[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>0 &lt;= heights[r][c] &lt;= 10<sup>5</sup></code></li>
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
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        def bfs(q, vis):
            while q:
                for _ in range(len(q)):
                    i, j = q.popleft()
                    for a, b in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                        x, y = i + a, j + b
                        if (
                            0 <= x < m
                            and 0 <= y < n
                            and (x, y) not in vis
                            and heights[x][y] >= heights[i][j]
                        ):
                            vis.add((x, y))
                            q.append((x, y))

        m, n = len(heights), len(heights[0])
        vis1, vis2 = set(), set()
        q1 = deque()
        q2 = deque()
        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0:
                    vis1.add((i, j))
                    q1.append((i, j))
                if i == m - 1 or j == n - 1:
                    vis2.add((i, j))
                    q2.append((i, j))
        bfs(q1, vis1)
        bfs(q2, vis2)
        return [
            (i, j)
            for i in range(m)
            for j in range(n)
            if (i, j) in vis1 and (i, j) in vis2
        ]
```

#### Java

```java
class Solution {
    private int[][] heights;
    private int m;
    private int n;

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        m = heights.length;
        n = heights[0].length;
        this.heights = heights;
        Deque<int[]> q1 = new LinkedList<>();
        Deque<int[]> q2 = new LinkedList<>();
        Set<Integer> vis1 = new HashSet<>();
        Set<Integer> vis2 = new HashSet<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    vis1.add(i * n + j);
                    q1.offer(new int[] {i, j});
                }
                if (i == m - 1 || j == n - 1) {
                    vis2.add(i * n + j);
                    q2.offer(new int[] {i, j});
                }
            }
        }
        bfs(q1, vis1);
        bfs(q2, vis2);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i * n + j;
                if (vis1.contains(x) && vis2.contains(x)) {
                    ans.add(Arrays.asList(i, j));
                }
            }
        }
        return ans;
    }

    private void bfs(Deque<int[]> q, Set<Integer> vis) {
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            for (int k = q.size(); k > 0; --k) {
                int[] p = q.poll();
                for (int i = 0; i < 4; ++i) {
                    int x = p[0] + dirs[i];
                    int y = p[1] + dirs[i + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis.contains(x * n + y)
                        && heights[x][y] >= heights[p[0]][p[1]]) {
                        vis.add(x * n + y);
                        q.offer(new int[] {x, y});
                    }
                }
            }
        }
    }
}
```

#### C++

```cpp
typedef pair<int, int> pii;

class Solution {
public:
    vector<vector<int>> heights;
    int m;
    int n;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        this->heights = heights;
        queue<pii> q1;
        queue<pii> q2;
        unordered_set<int> vis1;
        unordered_set<int> vis2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    vis1.insert(i * n + j);
                    q1.emplace(i, j);
                }
                if (i == m - 1 || j == n - 1) {
                    vis2.insert(i * n + j);
                    q2.emplace(i, j);
                }
            }
        }
        bfs(q1, vis1);
        bfs(q2, vis2);
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = i * n + j;
                if (vis1.count(x) && vis2.count(x)) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void bfs(queue<pii>& q, unordered_set<int>& vis) {
        vector<int> dirs = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            for (int k = q.size(); k > 0; --k) {
                auto p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = p.first + dirs[i];
                    int y = p.second + dirs[i + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !vis.count(x * n + y) && heights[x][y] >= heights[p.first][p.second]) {
                        vis.insert(x * n + y);
                        q.emplace(x, y);
                    }
                }
            }
        }
    }
};
```

#### Go

```go
func pacificAtlantic(heights [][]int) [][]int {
	m, n := len(heights), len(heights[0])
	vis1 := make(map[int]bool)
	vis2 := make(map[int]bool)
	var q1 [][]int
	var q2 [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i == 0 || j == 0 {
				vis1[i*n+j] = true
				q1 = append(q1, []int{i, j})
			}
			if i == m-1 || j == n-1 {
				vis2[i*n+j] = true
				q2 = append(q2, []int{i, j})
			}
		}
	}
	dirs := []int{-1, 0, 1, 0, -1}
	bfs := func(q [][]int, vis map[int]bool) {
		for len(q) > 0 {
			for k := len(q); k > 0; k-- {
				p := q[0]
				q = q[1:]
				for i := 0; i < 4; i++ {
					x, y := p[0]+dirs[i], p[1]+dirs[i+1]
					if x >= 0 && x < m && y >= 0 && y < n && !vis[x*n+y] && heights[x][y] >= heights[p[0]][p[1]] {
						vis[x*n+y] = true
						q = append(q, []int{x, y})
					}
				}
			}
		}
	}
	bfs(q1, vis1)
	bfs(q2, vis2)
	var ans [][]int
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			x := i*n + j
			if vis1[x] && vis2[x] {
				ans = append(ans, []int{i, j})
			}
		}
	}
	return ans
}
```

#### TypeScript

```ts
function pacificAtlantic(heights: number[][]): number[][] {
    const m = heights.length;
    const n = heights[0].length;
    const dirs = [
        [1, 0],
        [0, 1],
        [-1, 0],
        [0, -1],
    ];
    const gird = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const isVis = new Array(m).fill(0).map(() => new Array(n).fill(false));

    const dfs = (i: number, j: number) => {
        if (isVis[i][j]) {
            return;
        }
        gird[i][j]++;
        isVis[i][j] = true;
        const h = heights[i][j];
        for (const [x, y] of dirs) {
            if (h <= (heights[i + x] ?? [])[j + y]) {
                dfs(i + x, j + y);
            }
        }
    };

    for (let i = 0; i < n; i++) {
        dfs(0, i);
    }
    for (let i = 0; i < m; i++) {
        dfs(i, 0);
    }
    isVis.forEach(v => v.fill(false));
    for (let i = 0; i < n; i++) {
        dfs(m - 1, i);
    }
    for (let i = 0; i < m; i++) {
        dfs(i, n - 1);
    }

    const res = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (gird[i][j] === 2) {
                res.push([i, j]);
            }
        }
    }
    return res;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [418. 屏幕可显示句子的数量 🔒](https://leetcode.cn/problems/sentence-screen-fitting){#418}

{{< tabs "418" >}}

{{% tab "python" %}}
```python
class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        s = " ".join(sentence) + " "
        m = len(s)
        cur = 0
        for _ in range(rows):
            cur += cols
            if s[cur % m] == " ":
                cur += 1
            while cur and s[(cur - 1) % m] != " ":
                cur -= 1
        return cur // m
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        String s = String.join(" ", sentence) + " ";
        int m = s.length();
        int cur = 0;
        while (rows-- > 0) {
            cur += cols;
            if (s.charAt(cur % m) == ' ') {
                ++cur;
            } else {
                while (cur > 0 && s.charAt((cur - 1) % m) != ' ') {
                    --cur;
                }
            }
        }
        return cur / m;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto& t : sentence) {
            s += t;
            s += " ";
        }
        int m = s.size();
        int cur = 0;
        while (rows--) {
            cur += cols;
            if (s[cur % m] == ' ') {
                ++cur;
            } else {
                while (cur && s[(cur - 1) % m] != ' ') {
                    --cur;
                }
            }
        }
        return cur / m;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wordsTyping(sentence []string, rows int, cols int) int {
	s := strings.Join(sentence, " ") + " "
	m := len(s)
	cur := 0
	for i := 0; i < rows; i++ {
		cur += cols
		if s[cur%m] == ' ' {
			cur++
		} else {
			for cur > 0 && s[(cur-1)%m] != ' ' {
				cur--
			}
		}
	}
	return cur / m
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function wordsTyping(sentence: string[], rows: number, cols: number): number {
    const s = sentence.join(' ') + ' ';
    let cur = 0;
    const m = s.length;
    for (let i = 0; i < rows; ++i) {
        cur += cols;
        if (s[cur % m] === ' ') {
            ++cur;
        } else {
            while (cur > 0 && s[(cur - 1) % m] !== ' ') {
                --cur;
            }
        }
    }
    return Math.floor(cur / m);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个 <code>rows x cols</code> 的屏幕和一个用 <strong>非空 </strong>的单词列表组成的句子，请你计算出给定句子可以在屏幕上完整显示的次数。</p>

<p>句子中的单词顺序必须保持不变，并且不能将一个单词分成两行。一行中的两个连续单词必须用空白分开。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>sentence = ["hello", "world"], rows = 2, cols = 8
<strong>输出：</strong>1
<strong>解释：</strong>
hello---
world---
字符 '-' 表示屏幕上的一个空白位置。
</pre>

<p>&nbsp;</p>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>sentence = ["a", "bcd", "e"], rows = 3, cols = 6
<strong>输出：</strong>2
<strong>解释：</strong>
a-bcd- 
e-a---
bcd-e-
字符 '-' 表示屏幕上的一个空白位置。
</pre>

<p>&nbsp;</p>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>sentence = ["i", "had", "apple", "pie"], rows = 4, cols = 5
<strong>输出：</strong>1
<strong>解释：</strong>
i-had
apple
pie-i
had--
字符 '-' 表示屏幕上的一个空白位置。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 100</code></li>
	<li><code>1 &lt;= sentence[i].length &lt;= 10</code></li>
	<li><code>sentence[i]</code>&nbsp;由小写英文字母组成。</li>
	<li><code>1 &lt;= rows, cols &lt;= 2 * 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：贪心

我们将句子的每个单词拼接上一个空格，然后把句子拼接起来，得到字符串 $s$。例如，对于句子 `["hello", "world"]`，得到的字符串为 `"hello world "`。记 $s$ 的长度为 $m$。

接下来，我们使用贪心的方法，找到最大的可显示句子数。定义一个变量 $cur$，表示当前已经在屏幕上显示的字符串的长度，初始时 $cur=0$。

我们循环 $rows$ 次，每次循环中，我们首先将 $cur$ 增加 $cols$，如果 $s[cur \bmod m]$ 是一个空格，说明我们可以将完整的若干个单词放置到当前行，因此我们将 $cur$ 增加一个额外的 $1$；否则，说明我们需要回退 $cur$，直到 $cur$ 指向的字符是一个空格为止。然后继续下一次循环。

循环结束，返回 $\lfloor \frac{cur}{m} \rfloor$ 即可。

时间复杂度 $O(rows \times M)$，空间复杂度 $O(L)$。其中 $M$ 是单词的最大长度，而 $L$ 是单词的总长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        s = " ".join(sentence) + " "
        m = len(s)
        cur = 0
        for _ in range(rows):
            cur += cols
            if s[cur % m] == " ":
                cur += 1
            while cur and s[(cur - 1) % m] != " ":
                cur -= 1
        return cur // m
```

#### Java

```java
class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        String s = String.join(" ", sentence) + " ";
        int m = s.length();
        int cur = 0;
        while (rows-- > 0) {
            cur += cols;
            if (s.charAt(cur % m) == ' ') {
                ++cur;
            } else {
                while (cur > 0 && s.charAt((cur - 1) % m) != ' ') {
                    --cur;
                }
            }
        }
        return cur / m;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto& t : sentence) {
            s += t;
            s += " ";
        }
        int m = s.size();
        int cur = 0;
        while (rows--) {
            cur += cols;
            if (s[cur % m] == ' ') {
                ++cur;
            } else {
                while (cur && s[(cur - 1) % m] != ' ') {
                    --cur;
                }
            }
        }
        return cur / m;
    }
};
```

#### Go

```go
func wordsTyping(sentence []string, rows int, cols int) int {
	s := strings.Join(sentence, " ") + " "
	m := len(s)
	cur := 0
	for i := 0; i < rows; i++ {
		cur += cols
		if s[cur%m] == ' ' {
			cur++
		} else {
			for cur > 0 && s[(cur-1)%m] != ' ' {
				cur--
			}
		}
	}
	return cur / m
}
```

#### TypeScript

```ts
function wordsTyping(sentence: string[], rows: number, cols: number): number {
    const s = sentence.join(' ') + ' ';
    let cur = 0;
    const m = s.length;
    for (let i = 0; i < rows; ++i) {
        cur += cols;
        if (s[cur % m] === ' ') {
            ++cur;
        } else {
            while (cur > 0 && s[(cur - 1) % m] !== ' ') {
                --cur;
            }
        }
    }
    return Math.floor(cur / m);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [419. 棋盘上的战舰](https://leetcode.cn/problems/battleships-in-a-board){#419}

{{< tabs "419" >}}

{{% tab "python" %}}
```python
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        m, n = len(board), len(board[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] == '.':
                    continue
                if i > 0 and board[i - 1][j] == 'X':
                    continue
                if j > 0 and board[i][j - 1] == 'X':
                    continue
                ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countBattleships(char[][] board) {
        int m = board.length, n = board[0].length;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
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
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
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
func countBattleships(board [][]byte) (ans int) {
	for i, row := range board {
		for j, c := range row {
			if c == '.' {
				continue
			}
			if i > 0 && board[i-1][j] == 'X' {
				continue
			}
			if j > 0 && board[i][j-1] == 'X' {
				continue
			}
			ans++
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countBattleships(board: string[][]): number {
    const m = board.length;
    const n = board[0].length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === '.') {
                continue;
            }
            if (i && board[i - 1][j] === 'X') {
                continue;
            }
            if (j && board[i][j - 1] === 'X') {
                continue;
            }
            ++ans;
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

<p>给你一个大小为 <code>m x n</code> 的矩阵 <code>board</code> 表示棋盘，其中，每个单元格可以是一艘战舰 <code>'X'</code> 或者是一个空位 <code>'.'</code> ，返回在棋盘 <code>board</code> 上放置的 <strong>舰队</strong> 的数量。</p>

<p><strong>舰队</strong> 只能水平或者垂直放置在 <code>board</code> 上。换句话说，舰队只能按 <code>1 x k</code>（<code>1</code> 行，<code>k</code> 列）或 <code>k x 1</code>（<code>k</code> 行，<code>1</code> 列）的形状放置，其中 <code>k</code> 可以是任意大小。两个舰队之间至少有一个水平或垂直的空格分隔 （即没有相邻的舰队）。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0400-0499/0419.Battleships%20in%20a%20Board/images/1719200420-KKnzye-image.png" style="width: 333px; height: 333px;" />
<pre>
<strong>输入：</strong>board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>board = [["."]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n == board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>board[i][j]</code> 是 <code>'.'</code> 或 <code>'X'</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你可以实现一次扫描算法，并只使用<strong> </strong><code>O(1)</code><strong> </strong>额外空间，并且不修改 <code>board</code> 的值来解决这个问题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接遍历

我们可以遍历矩阵，找到每个战舰的左上角，即当前位置为 `X` 且上方和左方都不是 `X` 的位置，将答案加一。

遍历结束后，返回答案即可。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        m, n = len(board), len(board[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] == '.':
                    continue
                if i > 0 and board[i - 1][j] == 'X':
                    continue
                if j > 0 and board[i][j - 1] == 'X':
                    continue
                ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countBattleships(char[][] board) {
        int m = board.length, n = board[0].length;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
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
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (i > 0 && board[i - 1][j] == 'X') {
                    continue;
                }
                if (j > 0 && board[i][j - 1] == 'X') {
                    continue;
                }
                ++ans;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func countBattleships(board [][]byte) (ans int) {
	for i, row := range board {
		for j, c := range row {
			if c == '.' {
				continue
			}
			if i > 0 && board[i-1][j] == 'X' {
				continue
			}
			if j > 0 && board[i][j-1] == 'X' {
				continue
			}
			ans++
		}
	}
	return
}
```

#### TypeScript

```ts
function countBattleships(board: string[][]): number {
    const m = board.length;
    const n = board[0].length;
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (board[i][j] === '.') {
                continue;
            }
            if (i && board[i - 1][j] === 'X') {
                continue;
            }
            if (j && board[i][j - 1] === 'X') {
                continue;
            }
            ++ans;
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
