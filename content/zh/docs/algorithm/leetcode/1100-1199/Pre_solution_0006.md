---
title: "1150_检查一个数是否在数组中占绝大多数 🔒"
date: 2025-10-08T18:36:57+08:00
weight: 6
tags: [二分查找, 动态规划, 哈希表, 图, 字符串, 排序, 数学, 数据库, 数组, 树状数组, 滑动窗口, 线段树, 设计]
---

{{< markmap >}}
### [1150_检查一个数是否在数组中占绝大多数 🔒](#1150)
#### [数组](#1150)
#### [二分查找](#1150)
### [1151_最少交换次数来组合所有的 1 🔒](#1151)
#### [数组](#1151)
#### [滑动窗口](#1151)
### [1152_用户网站访问行为分析 🔒](#1152)
#### [数组](#1152)
#### [哈希表](#1152)
#### [字符串](#1152)
#### [排序](#1152)
### [1153_字符串转化 🔒](#1153)
#### [图](#1153)
#### [哈希表](#1153)
#### [字符串](#1153)
### [1154_一年中的第几天](#1154)
#### [数学](#1154)
#### [字符串](#1154)
### [1155_掷骰子等于目标和的方法数](#1155)
#### [动态规划](#1155)
### [1156_单字符重复子串的最大长度](#1156)
#### [哈希表](#1156)
#### [字符串](#1156)
#### [滑动窗口](#1156)
### [1157_子数组中占绝大多数的元素](#1157)
#### [设计](#1157)
#### [树状数组](#1157)
#### [线段树](#1157)
#### [数组](#1157)
#### [二分查找](#1157)
### [1158_市场分析 I](#1158)
#### [数据库](#1158)
### [1159_市场分析 II 🔒](#1159)
#### [数据库](#1159)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 1150_检查一个数是否在数组中占绝大多数 🔒
___
#### 数组
___
#### 二分查找
---
### 1151_最少交换次数来组合所有的 1 🔒
___
#### 数组
___
#### 滑动窗口
---
### 1152_用户网站访问行为分析 🔒
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 1153_字符串转化 🔒
___
#### 图
___
#### 哈希表
___
#### 字符串
---
### 1154_一年中的第几天
___
#### 数学
___
#### 字符串
---
### 1155_掷骰子等于目标和的方法数
___
#### 动态规划
---
### 1156_单字符重复子串的最大长度
___
#### 哈希表
___
#### 字符串
___
#### 滑动窗口
---
### 1157_子数组中占绝大多数的元素
___
#### 设计
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
---
### 1158_市场分析 I
___
#### 数据库
---
### 1159_市场分析 II 🔒
___
#### 数据库
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 动态规划 | 哈希表 |
| 图 | 字符串 | 排序 |
| 数学 | 数据库 | 数组 |
| 树状数组 | 滑动窗口 | 线段树 |
| 设计 |  |  |

# [1150. 检查一个数是否在数组中占绝大多数 🔒](https://leetcode.cn/problems/check-if-a-number-is-majority-element-in-a-sorted-array){#1150}

{{< tabs "1150" >}}

{{% tab "python" %}}
```python
class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        left = bisect_left(nums, target)
        right = left + len(nums) // 2
        return right < len(nums) and nums[right] == target
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int n = nums.length;
        int left = search(nums, target);
        int right = left + n / 2;
        return right < n && nums[right] == target;
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = left + n / 2;
        return right < n && nums[right] == target;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isMajorityElement(nums []int, target int) bool {
	n := len(nums)
	left := sort.SearchInts(nums, target)
	right := left + n/2
	return right < n && nums[right] == target
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isMajorityElement(nums: number[], target: number): boolean {
    const search = (x: number) => {
        let left = 0;
        let right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const n = nums.length;
    const left = search(target);
    const right = left + (n >> 1);
    return right < n && nums[right] === target;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个按 <strong>非递减</strong> 顺序排列的数组 <code>nums</code>，和一个目标数值 <code>target</code>。假如数组 <code>nums</code> 中绝大多数元素的数值都等于 <code>target</code>，则返回 <code>True</code>，否则请返回 <code>False</code>。</p>

<p>所谓占绝大多数，是指在长度为 <code>N</code> 的数组中出现必须<strong> 超过 <code>N/2</code></strong> <strong>次</strong>。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [2,4,5,5,5,5,5,6,6], target = 5
<strong>输出：</strong>true
<strong>解释：</strong>
数字 5 出现了 5 次，而数组的长度为 9。
所以，5 在数组中占绝大多数，因为 5 次 > 9/2。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [10,100,101,101], target = 101
<strong>输出：</strong>false
<strong>解释：</strong>
数字 101 出现了 2 次，而数组的长度是 4。
所以，101 <strong>不是 </strong>数组占绝大多数的元素，因为 2 次 = 4/2。
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 1000</code></li>
	<li><code>1 <= nums[i] <= 10^9</code></li>
	<li><code>1 <= target <= 10^9</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：二分查找

我们注意到，数组 $nums$ 中的元素是非递减的，也就是说，数组 $nums$ 中的元素单调递增。因此，我们可以使用二分查找的方法，找到数组 $nums$ 中第一个大于等于 $target$ 的元素的下标 $left$，以及第一个大于 $target$ 的元素的下标 $right$。如果 $right - left > \frac{n}{2}$，则说明数组 $nums$ 中的元素 $target$ 出现的次数超过了数组长度的一半，因此返回 $true$，否则返回 $false$。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        left = bisect_left(nums, target)
        right = bisect_right(nums, target)
        return right - left > len(nums) // 2
```

#### Java

```java
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int left = search(nums, target);
        int right = search(nums, target + 1);
        return right - left > nums.length / 2;
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        return right - left > nums.size() / 2;
    }
};
```

#### Go

```go
func isMajorityElement(nums []int, target int) bool {
	left := sort.SearchInts(nums, target)
	right := sort.SearchInts(nums, target+1)
	return right-left > len(nums)/2
}
```

#### TypeScript

```ts
function isMajorityElement(nums: number[], target: number): boolean {
    const search = (x: number) => {
        let left = 0;
        let right = nums.length;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const left = search(target);
    const right = search(target + 1);
    return right - left > nums.length >> 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二分查找（优化）

方法一中，我们使用了两次二分查找，分别找到数组 $nums$ 中第一个大于等于 $target$ 的元素的下标 $left$，以及第一个大于 $target$ 的元素的下标 $right$。但是，我们可以使用一次二分查找，找到数组 $nums$ 中第一个大于等于 $target$ 的元素的下标 $left$，然后判断 $nums[left + \frac{n}{2}]$ 是否等于 $target$，如果相等，说明数组 $nums$ 中的元素 $target$ 出现的次数超过了数组长度的一半，因此返回 $true$，否则返回 $false$。

时间复杂度 $O(\log n)$，空间复杂度 $O(1)$。其中 $n$ 为数组 $nums$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        left = bisect_left(nums, target)
        right = left + len(nums) // 2
        return right < len(nums) and nums[right] == target
```

#### Java

```java
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int n = nums.length;
        int left = search(nums, target);
        int right = left + n / 2;
        return right < n && nums[right] == target;
    }

    private int search(int[] nums, int x) {
        int left = 0, right = nums.length;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = left + n / 2;
        return right < n && nums[right] == target;
    }
};
```

#### Go

```go
func isMajorityElement(nums []int, target int) bool {
	n := len(nums)
	left := sort.SearchInts(nums, target)
	right := left + n/2
	return right < n && nums[right] == target
}
```

#### TypeScript

```ts
function isMajorityElement(nums: number[], target: number): boolean {
    const search = (x: number) => {
        let left = 0;
        let right = n;
        while (left < right) {
            const mid = (left + right) >> 1;
            if (nums[mid] >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    };
    const n = nums.length;
    const left = search(target);
    const right = left + (n >> 1);
    return right < n && nums[right] === target;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1151. 最少交换次数来组合所有的 1 🔒](https://leetcode.cn/problems/minimum-swaps-to-group-all-1s-together){#1151}

{{< tabs "1151" >}}

{{% tab "python" %}}
```python
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        k = data.count(1)
        mx = t = sum(data[:k])
        for i in range(k, len(data)):
            t += data[i]
            t -= data[i - k]
            mx = max(mx, t)
        return k - mx
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int minSwaps(int[] data) {
        int k = 0;
        for (int v : data) {
            k += v;
        }
        int t = 0;
        for (int i = 0; i < k; ++i) {
            t += data[i];
        }
        int mx = t;
        for (int i = k; i < data.length; ++i) {
            t += data[i];
            t -= data[i - k];
            mx = Math.max(mx, t);
        }
        return k - mx;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int k = 0;
        for (int& v : data) {
            k += v;
        }
        int t = 0;
        for (int i = 0; i < k; ++i) {
            t += data[i];
        }
        int mx = t;
        for (int i = k; i < data.size(); ++i) {
            t += data[i];
            t -= data[i - k];
            mx = max(mx, t);
        }
        return k - mx;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func minSwaps(data []int) int {
	k := 0
	for _, v := range data {
		k += v
	}
	t := 0
	for _, v := range data[:k] {
		t += v
	}
	mx := t
	for i := k; i < len(data); i++ {
		t += data[i]
		t -= data[i-k]
		mx = max(mx, t)
	}
	return k - mx
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function minSwaps(data: number[]): number {
    const k = data.reduce((acc, cur) => acc + cur, 0);
    let t = data.slice(0, k).reduce((acc, cur) => acc + cur, 0);
    let mx = t;
    for (let i = k; i < data.length; ++i) {
        t += data[i] - data[i - k];
        mx = Math.max(mx, t);
    }
    return k - mx;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MinSwaps(int[] data) {
        int k = data.Count(x => x == 1);
        int t = data.Take(k).Sum();
        int mx = t;
        for (int i = k; i < data.Length; ++i) {
            t += data[i];
            t -= data[i - k];
            mx = Math.Max(mx, t);
        }
        return k - mx;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出一个二进制数组&nbsp;<code>data</code>，你需要通过交换位置，将数组中 <strong>任何位置</strong> 上的 1 组合到一起，并返回所有可能中所需&nbsp;<strong>最少的交换次数</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入:</strong> data = [1,0,1,0,1]
<strong>输出:</strong> 1
<strong>解释: </strong>
有三种可能的方法可以把所有的 1 组合在一起：
[1,1,1,0,0]，交换 1 次；
[0,1,1,1,0]，交换 2 次；
[0,0,1,1,1]，交换 1 次。
所以最少的交换次数为 1。
</pre>

<p><strong>示例&nbsp; 2:</strong></p>

<pre>
<strong>输入：</strong>data =&nbsp;[0,0,0,1,0]
<strong>输出：</strong>0
<strong>解释： </strong>
由于数组中只有一个 1，所以不需要交换。</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入：</strong>data =&nbsp;[1,0,1,0,1,0,0,1,1,0,1]
<strong>输出：3
解释：
</strong>交换 3 次，一种可行的只用 3 次交换的解决方案是 [0,0,0,0,0,1,1,1,1,1,1]。
</pre>

<p><strong>示例 4:</strong></p>

<pre>
<strong>输入:</strong> data = [1,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1]
<strong>输出:</strong> 8
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= data.length &lt;= 10<sup>5</sup></code></li>
	<li><code>data[i]</code>&nbsp;==&nbsp;<code>0</code>&nbsp;or&nbsp;<code>1</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：滑动窗口

我们先统计数组中 $1$ 的个数，记为 $k$。然后我们使用滑动窗口，窗口大小为 $k$，窗口右边界从左向右移动，统计窗口内 $1$ 的个数，记为 $t$。每次移动窗口时，都更新 $t$ 的值，最后窗口右边界移动到数组末尾时，窗口内 $1$ 的个数最多，记为 $mx$。最后答案为 $k - mx$。

时间复杂度 $O(n)$，其中 $n$ 为数组长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def minSwaps(self, data: List[int]) -> int:
        k = data.count(1)
        mx = t = sum(data[:k])
        for i in range(k, len(data)):
            t += data[i]
            t -= data[i - k]
            mx = max(mx, t)
        return k - mx
```

#### Java

```java
class Solution {
    public int minSwaps(int[] data) {
        int k = 0;
        for (int v : data) {
            k += v;
        }
        int t = 0;
        for (int i = 0; i < k; ++i) {
            t += data[i];
        }
        int mx = t;
        for (int i = k; i < data.length; ++i) {
            t += data[i];
            t -= data[i - k];
            mx = Math.max(mx, t);
        }
        return k - mx;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int k = 0;
        for (int& v : data) {
            k += v;
        }
        int t = 0;
        for (int i = 0; i < k; ++i) {
            t += data[i];
        }
        int mx = t;
        for (int i = k; i < data.size(); ++i) {
            t += data[i];
            t -= data[i - k];
            mx = max(mx, t);
        }
        return k - mx;
    }
};
```

#### Go

```go
func minSwaps(data []int) int {
	k := 0
	for _, v := range data {
		k += v
	}
	t := 0
	for _, v := range data[:k] {
		t += v
	}
	mx := t
	for i := k; i < len(data); i++ {
		t += data[i]
		t -= data[i-k]
		mx = max(mx, t)
	}
	return k - mx
}
```

#### TypeScript

```ts
function minSwaps(data: number[]): number {
    const k = data.reduce((acc, cur) => acc + cur, 0);
    let t = data.slice(0, k).reduce((acc, cur) => acc + cur, 0);
    let mx = t;
    for (let i = k; i < data.length; ++i) {
        t += data[i] - data[i - k];
        mx = Math.max(mx, t);
    }
    return k - mx;
}
```

#### C#

```cs
public class Solution {
    public int MinSwaps(int[] data) {
        int k = data.Count(x => x == 1);
        int t = data.Take(k).Sum();
        int mx = t;
        for (int i = k; i < data.Length; ++i) {
            t += data[i];
            t -= data[i - k];
            mx = Math.Max(mx, t);
        }
        return k - mx;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1152. 用户网站访问行为分析 🔒](https://leetcode.cn/problems/analyze-user-website-visit-pattern){#1152}

{{< tabs "1152" >}}

{{% tab "python" %}}
```python
class Solution:
    def mostVisitedPattern(
        self, username: List[str], timestamp: List[int], website: List[str]
    ) -> List[str]:
        d = defaultdict(list)
        for user, _, site in sorted(
            zip(username, timestamp, website), key=lambda x: x[1]
        ):
            d[user].append(site)

        cnt = Counter()
        for sites in d.values():
            m = len(sites)
            s = set()
            if m > 2:
                for i in range(m - 2):
                    for j in range(i + 1, m - 1):
                        for k in range(j + 1, m):
                            s.add((sites[i], sites[j], sites[k]))
            for t in s:
                cnt[t] += 1
        return sorted(cnt.items(), key=lambda x: (-x[1], x[0]))[0][0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website) {
        Map<String, List<Node>> d = new HashMap<>();
        int n = username.length;
        for (int i = 0; i < n; ++i) {
            String user = username[i];
            int ts = timestamp[i];
            String site = website[i];
            d.computeIfAbsent(user, k -> new ArrayList<>()).add(new Node(user, ts, site));
        }
        Map<String, Integer> cnt = new HashMap<>();
        for (var sites : d.values()) {
            int m = sites.size();
            Set<String> s = new HashSet<>();
            if (m > 2) {
                Collections.sort(sites, (a, b) -> a.ts - b.ts);
                for (int i = 0; i < m - 2; ++i) {
                    for (int j = i + 1; j < m - 1; ++j) {
                        for (int k = j + 1; k < m; ++k) {
                            s.add(sites.get(i).site + "," + sites.get(j).site + ","
                                + sites.get(k).site);
                        }
                    }
                }
            }
            for (String t : s) {
                cnt.put(t, cnt.getOrDefault(t, 0) + 1);
            }
        }
        int mx = 0;
        String t = "";
        for (var e : cnt.entrySet()) {
            if (mx < e.getValue() || (mx == e.getValue() && e.getKey().compareTo(t) < 0)) {
                mx = e.getValue();
                t = e.getKey();
            }
        }
        return Arrays.asList(t.split(","));
    }
}

class Node {
    String user;
    int ts;
    String site;

    Node(String user, int ts, String site) {
        this.user = user;
        this.ts = ts;
        this.site = site;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> d;
        int n = username.size();
        for (int i = 0; i < n; ++i) {
            auto user = username[i];
            int ts = timestamp[i];
            auto site = website[i];
            d[user].emplace_back(ts, site);
        }
        unordered_map<string, int> cnt;
        for (auto& [_, sites] : d) {
            int m = sites.size();
            unordered_set<string> s;
            if (m > 2) {
                sort(sites.begin(), sites.end());
                for (int i = 0; i < m - 2; ++i) {
                    for (int j = i + 1; j < m - 1; ++j) {
                        for (int k = j + 1; k < m; ++k) {
                            s.insert(sites[i].second + "," + sites[j].second + "," + sites[k].second);
                        }
                    }
                }
            }
            for (auto& t : s) {
                cnt[t]++;
            }
        }
        int mx = 0;
        string t;
        for (auto& [p, v] : cnt) {
            if (mx < v || (mx == v && t > p)) {
                mx = v;
                t = p;
            }
        }
        return split(t, ',');
    }

    vector<string> split(string& s, char c) {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, c)) {
            res.push_back(t);
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func mostVisitedPattern(username []string, timestamp []int, website []string) []string {
	d := map[string][]pair{}
	for i, user := range username {
		ts := timestamp[i]
		site := website[i]
		d[user] = append(d[user], pair{ts, site})
	}
	cnt := map[string]int{}
	for _, sites := range d {
		m := len(sites)
		s := map[string]bool{}
		if m > 2 {
			sort.Slice(sites, func(i, j int) bool { return sites[i].ts < sites[j].ts })
			for i := 0; i < m-2; i++ {
				for j := i + 1; j < m-1; j++ {
					for k := j + 1; k < m; k++ {
						s[sites[i].site+","+sites[j].site+","+sites[k].site] = true
					}
				}
			}
		}
		for t := range s {
			cnt[t]++
		}
	}
	mx, t := 0, ""
	for p, v := range cnt {
		if mx < v || (mx == v && p < t) {
			mx = v
			t = p
		}
	}
	return strings.Split(t, ",")
}

type pair struct {
	ts   int
	site string
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定两个字符串数组&nbsp;<code>username</code>&nbsp;和&nbsp;<code>website</code>&nbsp;和一个整数数组&nbsp;<code>timestamp</code>&nbsp;。给定的数组长度相同，其中元组&nbsp;<code>[username[i], website[i], timestamp[i]]</code>&nbsp;表示用户&nbsp;<code>username[i]</code>&nbsp;在时间&nbsp;<code>timestamp[i]</code>&nbsp;访问了网站&nbsp;<code>website[i]</code>&nbsp;。</p>

<p><strong>访问模式</strong> 是包含三个网站的列表(不一定是完全不同的)。</p>

<ul>
	<li>例如，<code>["home"， "away"， "love"]</code>， <code>["leetcode"， "love"， "leetcode"]</code>，和 <code>["luffy"， "luffy"， "luffy"]</code> 都是模式。</li>
</ul>

<p>一种&nbsp;<strong>访问</strong><strong>模式</strong> 的 <strong>得分</strong> 是访问该模式中所有网站的用户数量，这些网站在该模式中出现的顺序相同。</p>

<ul>
	<li>例如，如果模式是 <code>[“home”，“away”，“love”] </code>，那么分数就是用户数量 <code>x</code> , <code>x</code> 访问了 “<code>home”</code> ，然后访问了 <code>“away”</code> ，然后访问了 <code>“love” </code>。</li>
	<li>同样，如果模式是 <code>["leetcode"， "love"， "leetcode"]</code> ，那么分数就是用户数量&nbsp;<code>x</code>&nbsp;，使得 <code>x</code> 访问了<code>"leetcode"</code>，然后访问了 <code>"love"</code> ，之后又访问了 <code>"leetcode"</code> 。</li>
	<li>另外，如果模式是 <code>[“luffy”，“luffy”，“luffy”]</code>&nbsp;，那么分数就是用户数量 <code>x</code> ，使得&nbsp;<code>x</code> 就可以在不同的时间戳上访问 <code>“luffy”</code> 三次。</li>
</ul>

<p>返回<em> <strong>得分</strong> 最大的 <strong>访问</strong><strong>模式</strong></em> 。如果有多个访问模式具有相同的最大分数，则返回字典序最小的。</p>

<p>请注意，模式中的网站不需要连续访问，只需按照模式中出现的顺序访问即可。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
<strong>输出：</strong>["home","about","career"]
<strong>解释：</strong>本例中的元组是:
["joe","home",1],["joe","about",2],["joe","career",3],["james","home",4],["james","cart",5],["james","maps",6],["james","home",7],["mary","home",8],["mary","about",9] 和 ["mary","career",10]。
模式 ("home", "about", "career") 的得分为 2（joe 和 mary）。
模式 ("home", "cart", "maps") 的得分为 1 (james).
模式 ("home", "cart", "home") 的得分为 1 (james).
模式 ("home", "maps", "home") 的得分为 1 (james).
模式 ("cart", "maps", "home") 的得分为 1 (james).
模式 ("home", "home", "home") 的得分为 0(没有用户访问过 home 3次)。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入:</strong> username = ["ua","ua","ua","ub","ub","ub"], timestamp = [1,2,3,4,5,6], website = ["a","b","a","a","b","c"]
<strong>输出:</strong> ["a","b","a"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= username.length &lt;= 50</code></li>
	<li><code>1 &lt;= username[i].length &lt;= 10</code></li>
	<li><code>timestamp.length == username.length</code></li>
	<li><code>1 &lt;= timestamp[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>website.length == username.length</code></li>
	<li><code>1 &lt;= website[i].length &lt;= 10</code></li>
	<li><code>username[i]</code> 和&nbsp;<code>website[i]</code>&nbsp;都只含小写字符</li>
	<li>它保证至少有一个用户访问了至少三个网站</li>
	<li>所有元组&nbsp;<code>[username[i]， timestamp[i]， website[i]</code>&nbsp;均<strong>&nbsp;不重复</strong></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 排序

我们先用哈希表 $d$ 记录每个用户访问的网站，然后遍历 $d$，对于每个用户，我们枚举其访问的所有三元组，统计去重三元组的出现次数，最后遍历所有三元组，返回出现次数最多的、字典序最小的三元组。

时间复杂度 $O(n^3)$，空间复杂度 $O(n^3)$。其中 $n$ 是 `username` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def mostVisitedPattern(
        self, username: List[str], timestamp: List[int], website: List[str]
    ) -> List[str]:
        d = defaultdict(list)
        for user, _, site in sorted(
            zip(username, timestamp, website), key=lambda x: x[1]
        ):
            d[user].append(site)

        cnt = Counter()
        for sites in d.values():
            m = len(sites)
            s = set()
            if m > 2:
                for i in range(m - 2):
                    for j in range(i + 1, m - 1):
                        for k in range(j + 1, m):
                            s.add((sites[i], sites[j], sites[k]))
            for t in s:
                cnt[t] += 1
        return sorted(cnt.items(), key=lambda x: (-x[1], x[0]))[0][0]
```

#### Java

```java
class Solution {
    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website) {
        Map<String, List<Node>> d = new HashMap<>();
        int n = username.length;
        for (int i = 0; i < n; ++i) {
            String user = username[i];
            int ts = timestamp[i];
            String site = website[i];
            d.computeIfAbsent(user, k -> new ArrayList<>()).add(new Node(user, ts, site));
        }
        Map<String, Integer> cnt = new HashMap<>();
        for (var sites : d.values()) {
            int m = sites.size();
            Set<String> s = new HashSet<>();
            if (m > 2) {
                Collections.sort(sites, (a, b) -> a.ts - b.ts);
                for (int i = 0; i < m - 2; ++i) {
                    for (int j = i + 1; j < m - 1; ++j) {
                        for (int k = j + 1; k < m; ++k) {
                            s.add(sites.get(i).site + "," + sites.get(j).site + ","
                                + sites.get(k).site);
                        }
                    }
                }
            }
            for (String t : s) {
                cnt.put(t, cnt.getOrDefault(t, 0) + 1);
            }
        }
        int mx = 0;
        String t = "";
        for (var e : cnt.entrySet()) {
            if (mx < e.getValue() || (mx == e.getValue() && e.getKey().compareTo(t) < 0)) {
                mx = e.getValue();
                t = e.getKey();
            }
        }
        return Arrays.asList(t.split(","));
    }
}

class Node {
    String user;
    int ts;
    String site;

    Node(String user, int ts, String site) {
        this.user = user;
        this.ts = ts;
        this.site = site;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> d;
        int n = username.size();
        for (int i = 0; i < n; ++i) {
            auto user = username[i];
            int ts = timestamp[i];
            auto site = website[i];
            d[user].emplace_back(ts, site);
        }
        unordered_map<string, int> cnt;
        for (auto& [_, sites] : d) {
            int m = sites.size();
            unordered_set<string> s;
            if (m > 2) {
                sort(sites.begin(), sites.end());
                for (int i = 0; i < m - 2; ++i) {
                    for (int j = i + 1; j < m - 1; ++j) {
                        for (int k = j + 1; k < m; ++k) {
                            s.insert(sites[i].second + "," + sites[j].second + "," + sites[k].second);
                        }
                    }
                }
            }
            for (auto& t : s) {
                cnt[t]++;
            }
        }
        int mx = 0;
        string t;
        for (auto& [p, v] : cnt) {
            if (mx < v || (mx == v && t > p)) {
                mx = v;
                t = p;
            }
        }
        return split(t, ',');
    }

    vector<string> split(string& s, char c) {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, c)) {
            res.push_back(t);
        }
        return res;
    }
};
```

#### Go

```go
func mostVisitedPattern(username []string, timestamp []int, website []string) []string {
	d := map[string][]pair{}
	for i, user := range username {
		ts := timestamp[i]
		site := website[i]
		d[user] = append(d[user], pair{ts, site})
	}
	cnt := map[string]int{}
	for _, sites := range d {
		m := len(sites)
		s := map[string]bool{}
		if m > 2 {
			sort.Slice(sites, func(i, j int) bool { return sites[i].ts < sites[j].ts })
			for i := 0; i < m-2; i++ {
				for j := i + 1; j < m-1; j++ {
					for k := j + 1; k < m; k++ {
						s[sites[i].site+","+sites[j].site+","+sites[k].site] = true
					}
				}
			}
		}
		for t := range s {
			cnt[t]++
		}
	}
	mx, t := 0, ""
	for p, v := range cnt {
		if mx < v || (mx == v && p < t) {
			mx = v
			t = p
		}
	}
	return strings.Split(t, ",")
}

type pair struct {
	ts   int
	site string
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1153. 字符串转化 🔒](https://leetcode.cn/problems/string-transforms-into-another-string){#1153}

{{< tabs "1153" >}}

{{% tab "python" %}}
```python
class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2:
            return True
        if len(set(str2)) == 26:
            return False
        d = {}
        for a, b in zip(str1, str2):
            if a not in d:
                d[a] = b
            elif d[a] != b:
                return False
        return True
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean canConvert(String str1, String str2) {
        if (str1.equals(str2)) {
            return true;
        }
        int m = 0;
        int[] cnt = new int[26];
        int n = str1.length();
        for (int i = 0; i < n; ++i) {
            if (++cnt[str2.charAt(i) - 'a'] == 1) {
                ++m;
            }
        }
        if (m == 26) {
            return false;
        }
        int[] d = new int[26];
        for (int i = 0; i < n; ++i) {
            int a = str1.charAt(i) - 'a';
            int b = str2.charAt(i) - 'a';
            if (d[a] == 0) {
                d[a] = b + 1;
            } else if (d[a] != b + 1) {
                return false;
            }
        }
        return true;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        int cnt[26]{};
        int m = 0;
        for (char& c : str2) {
            if (++cnt[c - 'a'] == 1) {
                ++m;
            }
        }
        if (m == 26) {
            return false;
        }
        int d[26]{};
        for (int i = 0; i < str1.size(); ++i) {
            int a = str1[i] - 'a';
            int b = str2[i] - 'a';
            if (d[a] == 0) {
                d[a] = b + 1;
            } else if (d[a] != b + 1) {
                return false;
            }
        }
        return true;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func canConvert(str1 string, str2 string) bool {
	if str1 == str2 {
		return true
	}
	s := map[rune]bool{}
	for _, c := range str2 {
		s[c] = true
		if len(s) == 26 {
			return false
		}
	}
	d := [26]int{}
	for i, c := range str1 {
		a, b := int(c-'a'), int(str2[i]-'a')
		if d[a] == 0 {
			d[a] = b + 1
		} else if d[a] != b+1 {
			return false
		}
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function canConvert(str1: string, str2: string): boolean {
    if (str1 === str2) {
        return true;
    }
    if (new Set(str2).size === 26) {
        return false;
    }
    const d: Map<string, string> = new Map();
    for (const [i, c] of str1.split('').entries()) {
        if (!d.has(c)) {
            d.set(c, str2[i]);
        } else if (d.get(c) !== str2[i]) {
            return false;
        }
    }
    return true;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给出两个长度相同的字符串&nbsp;<code>str1</code>&nbsp;和 <code>str2</code>。请你帮忙判断字符串 <code>str1</code> 能不能在 <strong>零次</strong>&nbsp;或 <strong>多次</strong>&nbsp;<em>转化</em>&nbsp;后变成字符串 <code>str2</code>。</p>

<p>每一次转化时，你可以将 <code>str1</code> 中出现的&nbsp;<strong>所有</strong>&nbsp;相同字母变成其他&nbsp;<strong>任何</strong>&nbsp;小写英文字母。</p>

<p>只有在字符串 <code>str1</code>&nbsp;能够通过上述方式顺利转化为字符串 <code>str2</code>&nbsp;时才能返回 <code>true</code>&nbsp;。​​</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>str1 = "aabcc", str2 = "ccdee"
<strong>输出：</strong>true
<strong>解释：</strong>将 'c' 变成 'e'，然后把 'b' 变成 'd'，接着再把 'a' 变成 'c'。注意，转化的顺序也很重要。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>str1 = "leetcode", str2 = "codeleet"
<strong>输出：</strong>false
<strong>解释：</strong>我们没有办法能够把 str1 转化为 str2。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= str1.length == str2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>str1</code>&nbsp;和 <code>str2</code> 中都只会出现小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表

我们可以先判断 `str1` 和 `str2` 是否相等，若相等，直接返回 `true`。

然后我们统计 `str2` 中每个字母出现的次数，若出现的次数等于 $26$，说明 `str2` 包含了所有的小写字母，那么无论 `str1` 如何转换，都无法得到 `str2`，直接返回 `false`。

否则，我们用数组或哈希表 `d` 记录 `str1` 中每个字母转换后的字母。遍历字符串 `str1` 和 `str2`，若 `str1` 中的某个字母已经转换过，那么其转换后的字母必须与 `str2` 中对应位置的字母相同，否则返回 `false`。

遍历结束后，返回 `true`。

时间复杂度 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串 `str1` 的长度，而 $C$ 为字符集大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2:
            return True
        if len(set(str2)) == 26:
            return False
        d = {}
        for a, b in zip(str1, str2):
            if a not in d:
                d[a] = b
            elif d[a] != b:
                return False
        return True
```

#### Java

```java
class Solution {
    public boolean canConvert(String str1, String str2) {
        if (str1.equals(str2)) {
            return true;
        }
        int m = 0;
        int[] cnt = new int[26];
        int n = str1.length();
        for (int i = 0; i < n; ++i) {
            if (++cnt[str2.charAt(i) - 'a'] == 1) {
                ++m;
            }
        }
        if (m == 26) {
            return false;
        }
        int[] d = new int[26];
        for (int i = 0; i < n; ++i) {
            int a = str1.charAt(i) - 'a';
            int b = str2.charAt(i) - 'a';
            if (d[a] == 0) {
                d[a] = b + 1;
            } else if (d[a] != b + 1) {
                return false;
            }
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        int cnt[26]{};
        int m = 0;
        for (char& c : str2) {
            if (++cnt[c - 'a'] == 1) {
                ++m;
            }
        }
        if (m == 26) {
            return false;
        }
        int d[26]{};
        for (int i = 0; i < str1.size(); ++i) {
            int a = str1[i] - 'a';
            int b = str2[i] - 'a';
            if (d[a] == 0) {
                d[a] = b + 1;
            } else if (d[a] != b + 1) {
                return false;
            }
        }
        return true;
    }
};
```

#### Go

```go
func canConvert(str1 string, str2 string) bool {
	if str1 == str2 {
		return true
	}
	s := map[rune]bool{}
	for _, c := range str2 {
		s[c] = true
		if len(s) == 26 {
			return false
		}
	}
	d := [26]int{}
	for i, c := range str1 {
		a, b := int(c-'a'), int(str2[i]-'a')
		if d[a] == 0 {
			d[a] = b + 1
		} else if d[a] != b+1 {
			return false
		}
	}
	return true
}
```

#### TypeScript

```ts
function canConvert(str1: string, str2: string): boolean {
    if (str1 === str2) {
        return true;
    }
    if (new Set(str2).size === 26) {
        return false;
    }
    const d: Map<string, string> = new Map();
    for (const [i, c] of str1.split('').entries()) {
        if (!d.has(c)) {
            d.set(c, str2[i]);
        } else if (d.get(c) !== str2[i]) {
            return false;
        }
    }
    return true;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1154. 一年中的第几天](https://leetcode.cn/problems/day-of-the-year){#1154}

{{< tabs "1154" >}}

{{% tab "python" %}}
```python
class Solution:
    def dayOfYear(self, date: str) -> int:
        y, m, d = (int(s) for s in date.split('-'))
        v = 29 if y % 400 == 0 or (y % 4 == 0 and y % 100) else 28
        days = [31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        return sum(days[: m - 1]) + d
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int dayOfYear(String date) {
        int y = Integer.parseInt(date.substring(0, 4));
        int m = Integer.parseInt(date.substring(5, 7));
        int d = Integer.parseInt(date.substring(8));
        int v = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0) ? 29 : 28;
        int[] days = {31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = d;
        for (int i = 0; i < m - 1; ++i) {
            ans += days[i];
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
    int dayOfYear(string date) {
        int y, m, d;
        sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
        int v = y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
        int days[] = {31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = d;
        for (int i = 0; i < m - 1; ++i) {
            ans += days[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func dayOfYear(date string) (ans int) {
	var y, m, d int
	fmt.Sscanf(date, "%d-%d-%d", &y, &m, &d)
	days := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	if y%400 == 0 || (y%4 == 0 && y%100 != 0) {
		days[1] = 29
	}
	ans += d
	for _, v := range days[:m-1] {
		ans += v
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function dayOfYear(date: string): number {
    const y = +date.slice(0, 4);
    const m = +date.slice(5, 7);
    const d = +date.slice(8);
    const v = y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
    const days = [31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days.slice(0, m - 1).reduce((a, b) => a + b, d);
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function (date) {
    const y = +date.slice(0, 4);
    const m = +date.slice(5, 7);
    const d = +date.slice(8);
    const v = y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
    const days = [31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days.slice(0, m - 1).reduce((a, b) => a + b, d);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个字符串&nbsp;<code>date</code> ，按 <code>YYYY-MM-DD</code> 格式表示一个 <a href="https://baike.baidu.com/item/公元/17855" target="_blank">现行公元纪年法</a> 日期。返回该日期是当年的第几天。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>date = "2019-01-09"
<strong>输出：</strong>9
<strong>解释：</strong>给定日期是2019年的第九天。</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>date = "2019-02-10"
<strong>输出：</strong>41
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>date.length == 10</code></li>
	<li><code>date[4] == date[7] == '-'</code>，其他的&nbsp;<code>date[i]</code>&nbsp;都是数字</li>
	<li><code>date</code> 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：直接计算

根据题意，给定的日期是公元纪年法的日期，因此可以直接计算出该日期是当年的第几天。

首先，根据给定的日期计算出年月日，分别为 $y$, $m$, $d$。

然后，根据公元纪年法的闰年规则，计算出当年二月份的天数，闰年的二月份有 $29$ 天，平年的二月份有 $28$ 天。

> 闰年的计算规则是：年份能被 $400$ 整除，或者年份能被 $4$ 整除且不能被 $100$ 整除。

最后，根据给定的日期计算出当年的第几天，即把前面每个月的天数累加起来，再加上当月的天数即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def dayOfYear(self, date: str) -> int:
        y, m, d = (int(s) for s in date.split('-'))
        v = 29 if y % 400 == 0 or (y % 4 == 0 and y % 100) else 28
        days = [31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        return sum(days[: m - 1]) + d
```

#### Java

```java
class Solution {
    public int dayOfYear(String date) {
        int y = Integer.parseInt(date.substring(0, 4));
        int m = Integer.parseInt(date.substring(5, 7));
        int d = Integer.parseInt(date.substring(8));
        int v = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0) ? 29 : 28;
        int[] days = {31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = d;
        for (int i = 0; i < m - 1; ++i) {
            ans += days[i];
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int dayOfYear(string date) {
        int y, m, d;
        sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);
        int v = y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
        int days[] = {31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int ans = d;
        for (int i = 0; i < m - 1; ++i) {
            ans += days[i];
        }
        return ans;
    }
};
```

#### Go

```go
func dayOfYear(date string) (ans int) {
	var y, m, d int
	fmt.Sscanf(date, "%d-%d-%d", &y, &m, &d)
	days := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	if y%400 == 0 || (y%4 == 0 && y%100 != 0) {
		days[1] = 29
	}
	ans += d
	for _, v := range days[:m-1] {
		ans += v
	}
	return
}
```

#### TypeScript

```ts
function dayOfYear(date: string): number {
    const y = +date.slice(0, 4);
    const m = +date.slice(5, 7);
    const d = +date.slice(8);
    const v = y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
    const days = [31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days.slice(0, m - 1).reduce((a, b) => a + b, d);
}
```

#### JavaScript

```js
/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function (date) {
    const y = +date.slice(0, 4);
    const m = +date.slice(5, 7);
    const d = +date.slice(8);
    const v = y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
    const days = [31, v, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    return days.slice(0, m - 1).reduce((a, b) => a + b, d);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1155. 掷骰子等于目标和的方法数](https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum){#1155}

{{< tabs "1155" >}}

{{% tab "python" %}}
```python
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        f = [1] + [0] * target
        mod = 10**9 + 7
        for i in range(1, n + 1):
            g = [0] * (target + 1)
            for j in range(1, min(i * k, target) + 1):
                for h in range(1, min(j, k) + 1):
                    g[j] = (g[j] + f[j - h]) % mod
            f = g
        return f[target]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int[] g = new int[target + 1];
            for (int j = 1; j <= Math.min(target, i * k); ++j) {
                for (int h = 1; h <= Math.min(j, k); ++h) {
                    g[j] = (g[j] + f[j - h]) % mod;
                }
            }
            f = g;
        }
        return f[target];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod = 1e9 + 7;
        vector<int> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> g(target + 1);
            for (int j = 1; j <= min(target, i * k); ++j) {
                for (int h = 1; h <= min(j, k); ++h) {
                    g[j] = (g[j] + f[j - h]) % mod;
                }
            }
            f = move(g);
        }
        return f[target];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numRollsToTarget(n int, k int, target int) int {
	const mod int = 1e9 + 7
	f := make([]int, target+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		g := make([]int, target+1)
		for j := 1; j <= min(target, i*k); j++ {
			for h := 1; h <= min(j, k); h++ {
				g[j] = (g[j] + f[j-h]) % mod
			}
		}
		f = g
	}
	return f[target]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numRollsToTarget(n: number, k: number, target: number): number {
    const f = Array(target + 1).fill(0);
    f[0] = 1;
    const mod = 1e9 + 7;
    for (let i = 1; i <= n; ++i) {
        const g = Array(target + 1).fill(0);
        for (let j = 1; j <= Math.min(i * k, target); ++j) {
            for (let h = 1; h <= Math.min(j, k); ++h) {
                g[j] = (g[j] + f[j - h]) % mod;
            }
        }
        f.splice(0, target + 1, ...g);
    }
    return f[target];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        let _mod = 1_000_000_007;
        let n = n as usize;
        let k = k as usize;
        let target = target as usize;
        let mut f = vec![0; target + 1];
        f[0] = 1;

        for i in 1..=n {
            let mut g = vec![0; target + 1];
            for j in 1..=target {
                for h in 1..=j.min(k) {
                    g[j] = (g[j] + f[j - h]) % _mod;
                }
            }
            f = g;
        }

        f[target]
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>这里有&nbsp;<code>n</code>&nbsp;个一样的骰子，每个骰子上都有&nbsp;<code>k</code>&nbsp;个面，分别标号为&nbsp;<code>1</code>&nbsp;到 <code>k</code> 。</p>

<p>给定三个整数 <code>n</code>、<code>k</code> 和 <code>target</code>，请返回投掷骰子的所有可能得到的结果（共有 <code>k<sup>n</sup></code> 种方式），使得骰子面朝上的数字总和等于 <code>target</code>。</p>

<p>由于答案可能很大，你需要对 <code>10<sup>9</sup> + 7</code> <strong>取模</strong>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 1, k = 6, target = 3
<strong>输出：</strong>1
<strong>解释：</strong>你掷了一个有 6 个面的骰子。
得到总和为 3 的结果的方式只有一种。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 2, k = 6, target = 7
<strong>输出：</strong>6
<strong>解释：</strong>你掷了两个骰子，每个骰子有 6 个面。
有 6 种方式得到总和为 7 的结果: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 30, k = 30, target = 500
<strong>输出：</strong>222616187
<strong>解释：</strong>返回的结果必须对 10<sup>9</sup> + 7 取模。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n, k &lt;= 30</code></li>
	<li><code>1 &lt;= target &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划

我们定义 $f[i][j]$ 表示使用 $i$ 个骰子，和为 $j$ 的方案数。那么我们可以得到状态转移方程：

$$
f[i][j] = \sum_{h=1}^{\min(j, k)} f[i-1][j-h]
$$

其中 $h$ 表示第 $i$ 个骰子的点数。

初始时 $f[0][0] = 1$，最终的答案即为 $f[n][target]$。

时间复杂度 $O(n \times k \times target)$，空间复杂度 $O(n \times target)$。

我们注意到，状态 $f[i][j]$ 只和 $f[i-1][]$ 有关，因此我们可以使用滚动数组的方式，将空间复杂度优化到 $O(target)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        f = [[0] * (target + 1) for _ in range(n + 1)]
        f[0][0] = 1
        mod = 10**9 + 7
        for i in range(1, n + 1):
            for j in range(1, min(i * k, target) + 1):
                for h in range(1, min(j, k) + 1):
                    f[i][j] = (f[i][j] + f[i - 1][j - h]) % mod
        return f[n][target]
```

#### Java

```java
class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        final int mod = (int) 1e9 + 7;
        int[][] f = new int[n + 1][target + 1];
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= Math.min(target, i * k); ++j) {
                for (int h = 1; h <= Math.min(j, k); ++h) {
                    f[i][j] = (f[i][j] + f[i - 1][j - h]) % mod;
                }
            }
        }
        return f[n][target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod = 1e9 + 7;
        int f[n + 1][target + 1];
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(target, i * k); ++j) {
                for (int h = 1; h <= min(j, k); ++h) {
                    f[i][j] = (f[i][j] + f[i - 1][j - h]) % mod;
                }
            }
        }
        return f[n][target];
    }
};
```

#### Go

```go
func numRollsToTarget(n int, k int, target int) int {
	const mod int = 1e9 + 7
	f := make([][]int, n+1)
	for i := range f {
		f[i] = make([]int, target+1)
	}
	f[0][0] = 1
	for i := 1; i <= n; i++ {
		for j := 1; j <= min(target, i*k); j++ {
			for h := 1; h <= min(j, k); h++ {
				f[i][j] = (f[i][j] + f[i-1][j-h]) % mod
			}
		}
	}
	return f[n][target]
}
```

#### TypeScript

```ts
function numRollsToTarget(n: number, k: number, target: number): number {
    const f = Array.from({ length: n + 1 }, () => Array(target + 1).fill(0));
    f[0][0] = 1;
    const mod = 1e9 + 7;
    for (let i = 1; i <= n; ++i) {
        for (let j = 1; j <= Math.min(i * k, target); ++j) {
            for (let h = 1; h <= Math.min(j, k); ++h) {
                f[i][j] = (f[i][j] + f[i - 1][j - h]) % mod;
            }
        }
    }
    return f[n][target];
}
```

#### Rust

```rust
impl Solution {
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        let _mod = 1_000_000_007;
        let n = n as usize;
        let k = k as usize;
        let target = target as usize;
        let mut f = vec![vec![0; target + 1]; n + 1];
        f[0][0] = 1;

        for i in 1..=n {
            for j in 1..=target.min(i * k) {
                for h in 1..=j.min(k) {
                    f[i][j] = (f[i][j] + f[i - 1][j - h]) % _mod;
                }
            }
        }

        f[n][target]
    }
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
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        f = [1] + [0] * target
        mod = 10**9 + 7
        for i in range(1, n + 1):
            g = [0] * (target + 1)
            for j in range(1, min(i * k, target) + 1):
                for h in range(1, min(j, k) + 1):
                    g[j] = (g[j] + f[j - h]) % mod
            f = g
        return f[target]
```

#### Java

```java
class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        final int mod = (int) 1e9 + 7;
        int[] f = new int[target + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int[] g = new int[target + 1];
            for (int j = 1; j <= Math.min(target, i * k); ++j) {
                for (int h = 1; h <= Math.min(j, k); ++h) {
                    g[j] = (g[j] + f[j - h]) % mod;
                }
            }
            f = g;
        }
        return f[target];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod = 1e9 + 7;
        vector<int> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> g(target + 1);
            for (int j = 1; j <= min(target, i * k); ++j) {
                for (int h = 1; h <= min(j, k); ++h) {
                    g[j] = (g[j] + f[j - h]) % mod;
                }
            }
            f = move(g);
        }
        return f[target];
    }
};
```

#### Go

```go
func numRollsToTarget(n int, k int, target int) int {
	const mod int = 1e9 + 7
	f := make([]int, target+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		g := make([]int, target+1)
		for j := 1; j <= min(target, i*k); j++ {
			for h := 1; h <= min(j, k); h++ {
				g[j] = (g[j] + f[j-h]) % mod
			}
		}
		f = g
	}
	return f[target]
}
```

#### TypeScript

```ts
function numRollsToTarget(n: number, k: number, target: number): number {
    const f = Array(target + 1).fill(0);
    f[0] = 1;
    const mod = 1e9 + 7;
    for (let i = 1; i <= n; ++i) {
        const g = Array(target + 1).fill(0);
        for (let j = 1; j <= Math.min(i * k, target); ++j) {
            for (let h = 1; h <= Math.min(j, k); ++h) {
                g[j] = (g[j] + f[j - h]) % mod;
            }
        }
        f.splice(0, target + 1, ...g);
    }
    return f[target];
}
```

#### Rust

```rust
impl Solution {
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        let _mod = 1_000_000_007;
        let n = n as usize;
        let k = k as usize;
        let target = target as usize;
        let mut f = vec![0; target + 1];
        f[0] = 1;

        for i in 1..=n {
            let mut g = vec![0; target + 1];
            for j in 1..=target {
                for h in 1..=j.min(k) {
                    g[j] = (g[j] + f[j - h]) % _mod;
                }
            }
            f = g;
        }

        f[target]
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1156. 单字符重复子串的最大长度](https://leetcode.cn/problems/swap-for-longest-repeated-character-substring){#1156}

{{< tabs "1156" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        cnt = Counter(text)
        n = len(text)
        ans = i = 0
        while i < n:
            j = i
            while j < n and text[j] == text[i]:
                j += 1
            l = j - i
            k = j + 1
            while k < n and text[k] == text[i]:
                k += 1
            r = k - j - 1
            ans = max(ans, min(l + r + 1, cnt[text[i]]))
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxRepOpt1(String text) {
        int[] cnt = new int[26];
        int n = text.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[text.charAt(i) - 'a'];
        }
        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text.charAt(j) == text.charAt(i)) {
                ++j;
            }
            int l = j - i;
            int k = j + 1;
            while (k < n && text.charAt(k) == text.charAt(i)) {
                ++k;
            }
            int r = k - j - 1;
            ans = Math.max(ans, Math.min(l + r + 1, cnt[text.charAt(i) - 'a']));
            i = j;
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
    int maxRepOpt1(string text) {
        int cnt[26] = {0};
        for (char& c : text) {
            ++cnt[c - 'a'];
        }
        int n = text.size();
        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text[j] == text[i]) {
                ++j;
            }
            int l = j - i;
            int k = j + 1;
            while (k < n && text[k] == text[i]) {
                ++k;
            }
            int r = k - j - 1;
            ans = max(ans, min(l + r + 1, cnt[text[i] - 'a']));
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxRepOpt1(text string) (ans int) {
	cnt := [26]int{}
	for _, c := range text {
		cnt[c-'a']++
	}
	n := len(text)
	for i, j := 0, 0; i < n; i = j {
		j = i
		for j < n && text[j] == text[i] {
			j++
		}
		l := j - i
		k := j + 1
		for k < n && text[k] == text[i] {
			k++
		}
		r := k - j - 1
		ans = max(ans, min(l+r+1, cnt[text[i]-'a']))
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxRepOpt1(text: string): number {
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const cnt: number[] = new Array(26).fill(0);
    for (const c of text) {
        cnt[idx(c)]++;
    }
    let ans = 0;
    let i = 0;
    const n = text.length;
    while (i < n) {
        let j = i;
        while (j < n && text[j] === text[i]) {
            ++j;
        }
        const l = j - i;
        let k = j + 1;
        while (k < n && text[k] === text[i]) {
            ++k;
        }
        const r = k - j - 1;
        ans = Math.max(ans, Math.min(cnt[idx(text[i])], l + r + 1));
        i = j;
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

<p>如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。</p>

<p>给你一个字符串&nbsp;<code>text</code>，你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>text = &quot;ababa&quot;
<strong>输出：</strong>3
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>text = &quot;aaabaaa&quot;
<strong>输出：</strong>6
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>text = &quot;aaabbaaa&quot;
<strong>输出：</strong>4
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>text = &quot;aaaaa&quot;
<strong>输出：</strong>5
</pre>

<p><strong>示例 5：</strong></p>

<pre><strong>输入：</strong>text = &quot;abcdef&quot;
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 20000</code></li>
	<li><code>text</code> 仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们先用哈希表或数组 $cnt$ 统计字符串 $text$ 中每个字符出现的次数。

接下来，我们定义一个指针 $i$，初始时 $i = 0$。每一次，我们将指针 $j$ 指向 $i$，并不断地向右移动 $j$，直到 $j$ 指向的字符与 $i$ 指向的字符不同，此时我们得到了一个长度为 $l = j - i$ 的子串 $text[i..j-1]$，其中所有字符都相同。

然后我们跳过指针 $j$ 指向的字符，用指针 $k$ 继续向右移动，直到 $k$ 指向的字符与 $i$ 指向的字符不同，此时我们得到了一个长度为 $r = k - j - 1$ 的子串 $text[j+1..k-1]$，其中所有字符都相同。那么我们最多通过一次交换操作，可以得到的最长单字符重复子串的长度为 $\min(l + r + 1, cnt[text[i]])$。接下来，我们将指针 $i$ 移动到 $j$，继续寻找下一个子串。我们取所有满足条件的子串的最大长度即可。

时间复杂度为 $O(n)$，空间复杂度 $O(C)$。其中 $n$ 为字符串的长度；而 $C$ 为字符集的大小，本题中 $C = 26$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxRepOpt1(self, text: str) -> int:
        cnt = Counter(text)
        n = len(text)
        ans = i = 0
        while i < n:
            j = i
            while j < n and text[j] == text[i]:
                j += 1
            l = j - i
            k = j + 1
            while k < n and text[k] == text[i]:
                k += 1
            r = k - j - 1
            ans = max(ans, min(l + r + 1, cnt[text[i]]))
            i = j
        return ans
```

#### Java

```java
class Solution {
    public int maxRepOpt1(String text) {
        int[] cnt = new int[26];
        int n = text.length();
        for (int i = 0; i < n; ++i) {
            ++cnt[text.charAt(i) - 'a'];
        }
        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text.charAt(j) == text.charAt(i)) {
                ++j;
            }
            int l = j - i;
            int k = j + 1;
            while (k < n && text.charAt(k) == text.charAt(i)) {
                ++k;
            }
            int r = k - j - 1;
            ans = Math.max(ans, Math.min(l + r + 1, cnt[text.charAt(i) - 'a']));
            i = j;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxRepOpt1(string text) {
        int cnt[26] = {0};
        for (char& c : text) {
            ++cnt[c - 'a'];
        }
        int n = text.size();
        int ans = 0, i = 0;
        while (i < n) {
            int j = i;
            while (j < n && text[j] == text[i]) {
                ++j;
            }
            int l = j - i;
            int k = j + 1;
            while (k < n && text[k] == text[i]) {
                ++k;
            }
            int r = k - j - 1;
            ans = max(ans, min(l + r + 1, cnt[text[i] - 'a']));
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func maxRepOpt1(text string) (ans int) {
	cnt := [26]int{}
	for _, c := range text {
		cnt[c-'a']++
	}
	n := len(text)
	for i, j := 0, 0; i < n; i = j {
		j = i
		for j < n && text[j] == text[i] {
			j++
		}
		l := j - i
		k := j + 1
		for k < n && text[k] == text[i] {
			k++
		}
		r := k - j - 1
		ans = max(ans, min(l+r+1, cnt[text[i]-'a']))
	}
	return
}
```

#### TypeScript

```ts
function maxRepOpt1(text: string): number {
    const idx = (c: string) => c.charCodeAt(0) - 'a'.charCodeAt(0);
    const cnt: number[] = new Array(26).fill(0);
    for (const c of text) {
        cnt[idx(c)]++;
    }
    let ans = 0;
    let i = 0;
    const n = text.length;
    while (i < n) {
        let j = i;
        while (j < n && text[j] === text[i]) {
            ++j;
        }
        const l = j - i;
        let k = j + 1;
        while (k < n && text[k] === text[i]) {
            ++k;
        }
        const r = k - j - 1;
        ans = Math.max(ans, Math.min(cnt[idx(text[i])], l + r + 1));
        i = j;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1157. 子数组中占绝大多数的元素](https://leetcode.cn/problems/online-majority-element-in-subarray){#1157}

{{< tabs "1157" >}}

{{% tab "python" %}}
```python
class Node:
    __slots__ = ("l", "r", "x", "cnt")

    def __init__(self):
        self.l = self.r = 0
        self.x = self.cnt = 0


class SegmentTree:
    def __init__(self, nums):
        self.nums = nums
        n = len(nums)
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].x = self.nums[l - 1]
            self.tr[u].cnt = 1
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].x, self.tr[u].cnt
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if r <= mid:
            return self.query(u << 1, l, r)
        if l > mid:
            return self.query(u << 1 | 1, l, r)
        x1, cnt1 = self.query(u << 1, l, r)
        x2, cnt2 = self.query(u << 1 | 1, l, r)
        if x1 == x2:
            return x1, cnt1 + cnt2
        if cnt1 >= cnt2:
            return x1, cnt1 - cnt2
        else:
            return x2, cnt2 - cnt1

    def pushup(self, u):
        if self.tr[u << 1].x == self.tr[u << 1 | 1].x:
            self.tr[u].x = self.tr[u << 1].x
            self.tr[u].cnt = self.tr[u << 1].cnt + self.tr[u << 1 | 1].cnt
        elif self.tr[u << 1].cnt >= self.tr[u << 1 | 1].cnt:
            self.tr[u].x = self.tr[u << 1].x
            self.tr[u].cnt = self.tr[u << 1].cnt - self.tr[u << 1 | 1].cnt
        else:
            self.tr[u].x = self.tr[u << 1 | 1].x
            self.tr[u].cnt = self.tr[u << 1 | 1].cnt - self.tr[u << 1].cnt


class MajorityChecker:
    def __init__(self, arr: List[int]):
        self.tree = SegmentTree(arr)
        self.d = defaultdict(list)
        for i, x in enumerate(arr):
            self.d[x].append(i)

    def query(self, left: int, right: int, threshold: int) -> int:
        x, _ = self.tree.query(1, left + 1, right + 1)
        l = bisect_left(self.d[x], left)
        r = bisect_left(self.d[x], right + 1)
        return x if r - l >= threshold else -1


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Node {
    int l, r;
    int x, cnt;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    private void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].x = nums[l - 1];
            tr[u].cnt = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public int[] query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return new int[] {tr[u].x, tr[u].cnt};
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (r <= mid) {
            return query(u << 1, l, r);
        }
        if (l > mid) {
            return query(u << 1 | 1, l, r);
        }
        var left = query(u << 1, l, r);
        var right = query(u << 1 | 1, l, r);
        if (left[0] == right[0]) {
            left[1] += right[1];
        } else if (left[1] >= right[1]) {
            left[1] -= right[1];
        } else {
            right[1] -= left[1];
            left = right;
        }
        return left;
    }

    private void pushup(int u) {
        if (tr[u << 1].x == tr[u << 1 | 1].x) {
            tr[u].x = tr[u << 1].x;
            tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
        } else if (tr[u << 1].cnt >= tr[u << 1 | 1].cnt) {
            tr[u].x = tr[u << 1].x;
            tr[u].cnt = tr[u << 1].cnt - tr[u << 1 | 1].cnt;
        } else {
            tr[u].x = tr[u << 1 | 1].x;
            tr[u].cnt = tr[u << 1 | 1].cnt - tr[u << 1].cnt;
        }
    }
}

class MajorityChecker {
    private SegmentTree tree;
    private Map<Integer, List<Integer>> d = new HashMap<>();

    public MajorityChecker(int[] arr) {
        tree = new SegmentTree(arr);
        for (int i = 0; i < arr.length; ++i) {
            d.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
    }

    public int query(int left, int right, int threshold) {
        int x = tree.query(1, left + 1, right + 1)[0];
        int l = search(d.get(x), left);
        int r = search(d.get(x), right + 1);
        return r - l >= threshold ? x : -1;
    }

    private int search(List<Integer> arr, int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr.get(mid) >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker obj = new MajorityChecker(arr);
 * int param_1 = obj.query(left,right,threshold);
 */
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Node {
public:
    int l = 0, r = 0;
    int x = 0, cnt = 0;
};

using pii = pair<int, int>;

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    pii query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return {tr[u]->x, tr[u]->cnt};
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (r <= mid) {
            return query(u << 1, l, r);
        }
        if (l > mid) {
            return query(u << 1 | 1, l, r);
        }
        auto left = query(u << 1, l, r);
        auto right = query(u << 1 | 1, l, r);
        if (left.first == right.first) {
            left.second += right.second;
        } else if (left.second >= right.second) {
            left.second -= right.second;
        } else {
            right.second -= left.second;
            left = right;
        }
        return left;
    }

private:
    vector<Node*> tr;
    vector<int> nums;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->x = nums[l - 1];
            tr[u]->cnt = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        if (tr[u << 1]->x == tr[u << 1 | 1]->x) {
            tr[u]->x = tr[u << 1]->x;
            tr[u]->cnt = tr[u << 1]->cnt + tr[u << 1 | 1]->cnt;
        } else if (tr[u << 1]->cnt >= tr[u << 1 | 1]->cnt) {
            tr[u]->x = tr[u << 1]->x;
            tr[u]->cnt = tr[u << 1]->cnt - tr[u << 1 | 1]->cnt;
        } else {
            tr[u]->x = tr[u << 1 | 1]->x;
            tr[u]->cnt = tr[u << 1 | 1]->cnt - tr[u << 1]->cnt;
        }
    }
};

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        tree = new SegmentTree(arr);
        for (int i = 0; i < arr.size(); ++i) {
            d[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        int x = tree->query(1, left + 1, right + 1).first;
        auto l = lower_bound(d[x].begin(), d[x].end(), left);
        auto r = lower_bound(d[x].begin(), d[x].end(), right + 1);
        return r - l >= threshold ? x : -1;
    }

private:
    unordered_map<int, vector<int>> d;
    SegmentTree* tree;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```
{{% /tab %}}
{{% tab "go" %}}
```go
type node struct {
	l, r, x, cnt int
}

type segmentTree struct {
	nums []int
	tr   []*node
}

type pair struct{ x, cnt int }

func newSegmentTree(nums []int) *segmentTree {
	n := len(nums)
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{nums, tr}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		t.tr[u].x = t.nums[l-1]
		t.tr[u].cnt = 1
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) query(u, l, r int) pair {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return pair{t.tr[u].x, t.tr[u].cnt}
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if r <= mid {
		return t.query(u<<1, l, r)
	}
	if l > mid {
		return t.query(u<<1|1, l, r)
	}
	left, right := t.query(u<<1, l, r), t.query(u<<1|1, l, r)
	if left.x == right.x {
		left.cnt += right.cnt
	} else if left.cnt >= right.cnt {
		left.cnt -= right.cnt
	} else {
		right.cnt -= left.cnt
		left = right
	}
	return left
}

func (t *segmentTree) pushup(u int) {
	if t.tr[u<<1].x == t.tr[u<<1|1].x {
		t.tr[u].x = t.tr[u<<1].x
		t.tr[u].cnt = t.tr[u<<1].cnt + t.tr[u<<1|1].cnt
	} else if t.tr[u<<1].cnt >= t.tr[u<<1|1].cnt {
		t.tr[u].x = t.tr[u<<1].x
		t.tr[u].cnt = t.tr[u<<1].cnt - t.tr[u<<1|1].cnt
	} else {
		t.tr[u].x = t.tr[u<<1|1].x
		t.tr[u].cnt = t.tr[u<<1|1].cnt - t.tr[u<<1].cnt
	}
}

type MajorityChecker struct {
	tree *segmentTree
	d    map[int][]int
}

func Constructor(arr []int) MajorityChecker {
	tree := newSegmentTree(arr)
	d := map[int][]int{}
	for i, x := range arr {
		d[x] = append(d[x], i)
	}
	return MajorityChecker{tree, d}
}

func (this *MajorityChecker) Query(left int, right int, threshold int) int {
	x := this.tree.query(1, left+1, right+1).x
	l := sort.SearchInts(this.d[x], left)
	r := sort.SearchInts(this.d[x], right+1)
	if r-l >= threshold {
		return x
	}
	return -1
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,threshold);
 */
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>设计一个数据结构，有效地找到给定子数组的 <strong>多数元素</strong> 。</p>

<p>子数组的 <strong>多数元素</strong> 是在子数组中出现&nbsp;<code>threshold</code>&nbsp;次数或次数以上的元素。</p>

<p>实现 <code>MajorityChecker</code> 类:</p>

<ul>
	<li><code>MajorityChecker(int[] arr)</code>&nbsp;会用给定的数组 <code>arr</code>&nbsp;对&nbsp;<code>MajorityChecker</code> 初始化。</li>
	<li><code>int query(int left, int right, int threshold)</code>&nbsp;返回子数组中的元素 &nbsp;<code>arr[left...right]</code>&nbsp;至少出现&nbsp;<code>threshold</code>&nbsp;次数，如果不存在这样的元素则返回 <code>-1</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong>
["MajorityChecker", "query", "query", "query"]
[[[1, 1, 2, 2, 1, 1]], [0, 5, 4], [0, 3, 3], [2, 3, 2]]
<strong>输出：</strong>
[null, 1, -1, 2]

<b>解释：</b>
MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // 返回 1
majorityChecker.query(0,3,3); // 返回 -1
majorityChecker.query(2,3,2); // 返回 2
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt; arr.length</code></li>
	<li><code>threshold &lt;= right - left + 1</code></li>
	<li><code>2 * threshold &gt; right - left + 1</code></li>
	<li>调用&nbsp;<code>query</code>&nbsp;的次数最多为&nbsp;<code>10<sup>4</sup></code>&nbsp;</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：线段树 + 摩尔投票 + 二分查找

我们注意到，题目需要我们找出特定区间内可能的众数，考虑使用线段树来维护每个区间内的候选众数以及其出现的次数。

我们定义线段树的每个节点为 `Node`，每个节点包含如下属性：

-   `l`：节点的左端点，下标从 $1$ 开始。
-   `r`：节点的右端点，下标从 $1$ 开始。
-   `x`：节点的候选众数。
-   `cnt`：节点的候选众数出现的次数。

线段树主要有以下几个操作：

-   `build(u, l, r)`：建立线段树。
-   `pushup(u)`：用子节点的信息更新父节点的信息。
-   `query(u, l, r)`：查询区间和。

在主函数的初始化方法中，我们先创建一个线段树，并且用哈希表 $d$ 记录每个元素在数组中的所有下标。

在 `query(left, right, threshold)` 方法中，我们直接调用线段树的 `query` 方法，得到候选众数 $x$。然后使用二分查找，找到 $x$ 在数组中第一个大于等于 $left$ 的下标 $l$，以及第一个大于 $right$ 的下标 $r$。如果 $r - l \ge threshold$，则返回 $x$，否则返回 $-1$。

时间复杂度方面，初始化方法的时间复杂度为 $O(n)$，查询方法的时间复杂度为 $O(\log n)$。空间复杂度为 $O(n)$。其中 $n$ 为数组的长度。

<!-- tabs:start -->

#### Python3

```python
class Node:
    __slots__ = ("l", "r", "x", "cnt")

    def __init__(self):
        self.l = self.r = 0
        self.x = self.cnt = 0


class SegmentTree:
    def __init__(self, nums):
        self.nums = nums
        n = len(nums)
        self.tr = [Node() for _ in range(n << 2)]
        self.build(1, 1, n)

    def build(self, u, l, r):
        self.tr[u].l, self.tr[u].r = l, r
        if l == r:
            self.tr[u].x = self.nums[l - 1]
            self.tr[u].cnt = 1
            return
        mid = (l + r) >> 1
        self.build(u << 1, l, mid)
        self.build(u << 1 | 1, mid + 1, r)
        self.pushup(u)

    def query(self, u, l, r):
        if self.tr[u].l >= l and self.tr[u].r <= r:
            return self.tr[u].x, self.tr[u].cnt
        mid = (self.tr[u].l + self.tr[u].r) >> 1
        if r <= mid:
            return self.query(u << 1, l, r)
        if l > mid:
            return self.query(u << 1 | 1, l, r)
        x1, cnt1 = self.query(u << 1, l, r)
        x2, cnt2 = self.query(u << 1 | 1, l, r)
        if x1 == x2:
            return x1, cnt1 + cnt2
        if cnt1 >= cnt2:
            return x1, cnt1 - cnt2
        else:
            return x2, cnt2 - cnt1

    def pushup(self, u):
        if self.tr[u << 1].x == self.tr[u << 1 | 1].x:
            self.tr[u].x = self.tr[u << 1].x
            self.tr[u].cnt = self.tr[u << 1].cnt + self.tr[u << 1 | 1].cnt
        elif self.tr[u << 1].cnt >= self.tr[u << 1 | 1].cnt:
            self.tr[u].x = self.tr[u << 1].x
            self.tr[u].cnt = self.tr[u << 1].cnt - self.tr[u << 1 | 1].cnt
        else:
            self.tr[u].x = self.tr[u << 1 | 1].x
            self.tr[u].cnt = self.tr[u << 1 | 1].cnt - self.tr[u << 1].cnt


class MajorityChecker:
    def __init__(self, arr: List[int]):
        self.tree = SegmentTree(arr)
        self.d = defaultdict(list)
        for i, x in enumerate(arr):
            self.d[x].append(i)

    def query(self, left: int, right: int, threshold: int) -> int:
        x, _ = self.tree.query(1, left + 1, right + 1)
        l = bisect_left(self.d[x], left)
        r = bisect_left(self.d[x], right + 1)
        return x if r - l >= threshold else -1


# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)
```

#### Java

```java
class Node {
    int l, r;
    int x, cnt;
}

class SegmentTree {
    private Node[] tr;
    private int[] nums;

    public SegmentTree(int[] nums) {
        int n = nums.length;
        this.nums = nums;
        tr = new Node[n << 2];
        for (int i = 0; i < tr.length; ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    private void build(int u, int l, int r) {
        tr[u].l = l;
        tr[u].r = r;
        if (l == r) {
            tr[u].x = nums[l - 1];
            tr[u].cnt = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    public int[] query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) {
            return new int[] {tr[u].x, tr[u].cnt};
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (r <= mid) {
            return query(u << 1, l, r);
        }
        if (l > mid) {
            return query(u << 1 | 1, l, r);
        }
        var left = query(u << 1, l, r);
        var right = query(u << 1 | 1, l, r);
        if (left[0] == right[0]) {
            left[1] += right[1];
        } else if (left[1] >= right[1]) {
            left[1] -= right[1];
        } else {
            right[1] -= left[1];
            left = right;
        }
        return left;
    }

    private void pushup(int u) {
        if (tr[u << 1].x == tr[u << 1 | 1].x) {
            tr[u].x = tr[u << 1].x;
            tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
        } else if (tr[u << 1].cnt >= tr[u << 1 | 1].cnt) {
            tr[u].x = tr[u << 1].x;
            tr[u].cnt = tr[u << 1].cnt - tr[u << 1 | 1].cnt;
        } else {
            tr[u].x = tr[u << 1 | 1].x;
            tr[u].cnt = tr[u << 1 | 1].cnt - tr[u << 1].cnt;
        }
    }
}

class MajorityChecker {
    private SegmentTree tree;
    private Map<Integer, List<Integer>> d = new HashMap<>();

    public MajorityChecker(int[] arr) {
        tree = new SegmentTree(arr);
        for (int i = 0; i < arr.length; ++i) {
            d.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }
    }

    public int query(int left, int right, int threshold) {
        int x = tree.query(1, left + 1, right + 1)[0];
        int l = search(d.get(x), left);
        int r = search(d.get(x), right + 1);
        return r - l >= threshold ? x : -1;
    }

    private int search(List<Integer> arr, int x) {
        int left = 0, right = arr.size();
        while (left < right) {
            int mid = (left + right) >> 1;
            if (arr.get(mid) >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker obj = new MajorityChecker(arr);
 * int param_1 = obj.query(left,right,threshold);
 */
```

#### C++

```cpp
class Node {
public:
    int l = 0, r = 0;
    int x = 0, cnt = 0;
};

using pii = pair<int, int>;

class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    pii query(int u, int l, int r) {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return {tr[u]->x, tr[u]->cnt};
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (r <= mid) {
            return query(u << 1, l, r);
        }
        if (l > mid) {
            return query(u << 1 | 1, l, r);
        }
        auto left = query(u << 1, l, r);
        auto right = query(u << 1 | 1, l, r);
        if (left.first == right.first) {
            left.second += right.second;
        } else if (left.second >= right.second) {
            left.second -= right.second;
        } else {
            right.second -= left.second;
            left = right;
        }
        return left;
    }

private:
    vector<Node*> tr;
    vector<int> nums;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->x = nums[l - 1];
            tr[u]->cnt = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        if (tr[u << 1]->x == tr[u << 1 | 1]->x) {
            tr[u]->x = tr[u << 1]->x;
            tr[u]->cnt = tr[u << 1]->cnt + tr[u << 1 | 1]->cnt;
        } else if (tr[u << 1]->cnt >= tr[u << 1 | 1]->cnt) {
            tr[u]->x = tr[u << 1]->x;
            tr[u]->cnt = tr[u << 1]->cnt - tr[u << 1 | 1]->cnt;
        } else {
            tr[u]->x = tr[u << 1 | 1]->x;
            tr[u]->cnt = tr[u << 1 | 1]->cnt - tr[u << 1]->cnt;
        }
    }
};

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        tree = new SegmentTree(arr);
        for (int i = 0; i < arr.size(); ++i) {
            d[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        int x = tree->query(1, left + 1, right + 1).first;
        auto l = lower_bound(d[x].begin(), d[x].end(), left);
        auto r = lower_bound(d[x].begin(), d[x].end(), right + 1);
        return r - l >= threshold ? x : -1;
    }

private:
    unordered_map<int, vector<int>> d;
    SegmentTree* tree;
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```

#### Go

```go
type node struct {
	l, r, x, cnt int
}

type segmentTree struct {
	nums []int
	tr   []*node
}

type pair struct{ x, cnt int }

func newSegmentTree(nums []int) *segmentTree {
	n := len(nums)
	tr := make([]*node, n<<2)
	for i := range tr {
		tr[i] = &node{}
	}
	t := &segmentTree{nums, tr}
	t.build(1, 1, n)
	return t
}

func (t *segmentTree) build(u, l, r int) {
	t.tr[u].l, t.tr[u].r = l, r
	if l == r {
		t.tr[u].x = t.nums[l-1]
		t.tr[u].cnt = 1
		return
	}
	mid := (l + r) >> 1
	t.build(u<<1, l, mid)
	t.build(u<<1|1, mid+1, r)
	t.pushup(u)
}

func (t *segmentTree) query(u, l, r int) pair {
	if t.tr[u].l >= l && t.tr[u].r <= r {
		return pair{t.tr[u].x, t.tr[u].cnt}
	}
	mid := (t.tr[u].l + t.tr[u].r) >> 1
	if r <= mid {
		return t.query(u<<1, l, r)
	}
	if l > mid {
		return t.query(u<<1|1, l, r)
	}
	left, right := t.query(u<<1, l, r), t.query(u<<1|1, l, r)
	if left.x == right.x {
		left.cnt += right.cnt
	} else if left.cnt >= right.cnt {
		left.cnt -= right.cnt
	} else {
		right.cnt -= left.cnt
		left = right
	}
	return left
}

func (t *segmentTree) pushup(u int) {
	if t.tr[u<<1].x == t.tr[u<<1|1].x {
		t.tr[u].x = t.tr[u<<1].x
		t.tr[u].cnt = t.tr[u<<1].cnt + t.tr[u<<1|1].cnt
	} else if t.tr[u<<1].cnt >= t.tr[u<<1|1].cnt {
		t.tr[u].x = t.tr[u<<1].x
		t.tr[u].cnt = t.tr[u<<1].cnt - t.tr[u<<1|1].cnt
	} else {
		t.tr[u].x = t.tr[u<<1|1].x
		t.tr[u].cnt = t.tr[u<<1|1].cnt - t.tr[u<<1].cnt
	}
}

type MajorityChecker struct {
	tree *segmentTree
	d    map[int][]int
}

func Constructor(arr []int) MajorityChecker {
	tree := newSegmentTree(arr)
	d := map[int][]int{}
	for i, x := range arr {
		d[x] = append(d[x], i)
	}
	return MajorityChecker{tree, d}
}

func (this *MajorityChecker) Query(left int, right int, threshold int) int {
	x := this.tree.query(1, left+1, right+1).x
	l := sort.SearchInts(this.d[x], left)
	r := sort.SearchInts(this.d[x], right+1)
	if r-l >= threshold {
		return x
	}
	return -1
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,threshold);
 */
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1158. 市场分析 I](https://leetcode.cn/problems/market-analysis-i){#1158}

{{< tabs "1158" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    user_id AS buyer_id,
    join_date,
    IFNULL(SUM(YEAR(order_date) = 2019), 0) AS orders_in_2019
FROM
    Users AS u
    LEFT JOIN Orders AS o ON u.user_id = buyer_id
GROUP BY 1;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Users</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| join_date      | date    |
| favorite_brand | varchar |
+----------------+---------+
user_id 是此表主键（具有唯一值的列）。
表中描述了购物网站的用户信息，用户可以在此网站上进行商品买卖。
</pre>

<p>&nbsp;</p>

<p>表：&nbsp;<code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| item_id       | int     |
| buyer_id      | int     |
| seller_id     | int     |
+---------------+---------+
order_id 是此表主键（具有唯一值的列）。
item_id 是 Items 表的外键（reference 列）。
（buyer_id，seller_id）是 User 表的外键。
</pre>

<p>&nbsp;</p>

<p>表：<code>Items</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| item_id       | int     |
| item_brand    | varchar |
+---------------+---------+
item_id 是此表的主键（具有唯一值的列）。
</pre>

<p>&nbsp;</p>

<p>编写解决方案找出每个用户的注册日期和在 <strong><code>2019</code> </strong>年作为买家的订单总数。</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>查询结果格式如下。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入：</strong>
Users 表:
+---------+------------+----------------+
| user_id | join_date  | favorite_brand |
+---------+------------+----------------+
| 1       | 2018-01-01 | Lenovo         |
| 2       | 2018-02-09 | Samsung        |
| 3       | 2018-01-19 | LG             |
| 4       | 2018-05-21 | HP             |
+---------+------------+----------------+
Orders 表:
+----------+------------+---------+----------+-----------+
| order_id | order_date | item_id | buyer_id | seller_id |
+----------+------------+---------+----------+-----------+
| 1        | 2019-08-01 | 4       | 1        | 2         |
| 2        | 2018-08-02 | 2       | 1        | 3         |
| 3        | 2019-08-03 | 3       | 2        | 3         |
| 4        | 2018-08-04 | 1       | 4        | 2         |
| 5        | 2018-08-04 | 1       | 3        | 4         |
| 6        | 2019-08-05 | 2       | 2        | 4         |
+----------+------------+---------+----------+-----------+
Items 表:
+---------+------------+
| item_id | item_brand |
+---------+------------+
| 1       | Samsung    |
| 2       | Lenovo     |
| 3       | LG         |
| 4       | HP         |
+---------+------------+
<strong>输出：</strong>
+-----------+------------+----------------+
| buyer_id  | join_date  | orders_in_2019 |
+-----------+------------+----------------+
| 1         | 2018-01-01 | 1              |
| 2         | 2018-02-09 | 2              |
| 3         | 2018-01-19 | 0              |
| 4         | 2018-05-21 | 0              |
+-----------+------------+----------------+</pre>

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
    u.user_id AS buyer_id,
    u.join_date,
    COUNT(order_id) AS orders_in_2019
FROM
    Users AS u
    LEFT JOIN Orders AS o ON u.user_id = o.buyer_id AND YEAR(order_date) = 2019
GROUP BY user_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL

```sql
# Write your MySQL query statement below
SELECT
    user_id AS buyer_id,
    join_date,
    IFNULL(SUM(YEAR(order_date) = 2019), 0) AS orders_in_2019
FROM
    Users AS u
    LEFT JOIN Orders AS o ON u.user_id = buyer_id
GROUP BY 1;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [1159. 市场分析 II 🔒](https://leetcode.cn/problems/market-analysis-ii){#1159}

{{< tabs "1159" >}}

{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    u.user_id AS seller_id,
    CASE
        WHEN u.favorite_brand = i.item_brand THEN 'yes'
        ELSE 'no'
    END AS 2nd_item_fav_brand
FROM
    users AS u
    LEFT JOIN (
        SELECT
            order_date,
            item_id,
            seller_id,
            RANK() OVER (
                PARTITION BY seller_id
                ORDER BY order_date
            ) AS rk
        FROM orders
    ) AS o
        ON u.user_id = o.seller_id AND o.rk = 2
    LEFT JOIN items AS i ON o.item_id = i.item_id;
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>表: <code>Users</code></p>

<pre>
+----------------+---------+
| Column Name    | Type    |
+----------------+---------+
| user_id        | int     |
| join_date      | date    |
| favorite_brand | varchar |
+----------------+---------+
user_id 是该表的主键(具有唯一值的列)。
表中包含一位在线购物网站用户的个人信息，用户可以在该网站出售和购买商品。
</pre>

<p>表: <code>Orders</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| order_id      | int     |
| order_date    | date    |
| item_id       | int     |
| buyer_id      | int     |
| seller_id     | int     |
+---------------+---------+
order_id 是该表的主键(具有唯一值的列)。
item_id 是 Items 表的外键(reference 列)。
buyer_id 和 seller_id 是 Users 表的外键。
</pre>

<p>表: <code>Items</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| item_id       | int     |
| item_brand    | varchar |
+---------------+---------+
item_id 是该表的主键(具有唯一值的列)。
</pre>

<p>&nbsp;</p>

<p>编写一个解决方案，为每个用户找出他们出售的第二件商品(按日期)的品牌是否是他们最喜欢的品牌。如果用户售出的商品少于两件，则该用户的结果为否。保证卖家不会在一天内卖出一件以上的商品。</p>

<p>&nbsp;</p>

<p>以 <strong>任意顺序</strong> 返回结果表。</p>

<p>返回结果格式如下例所示：</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Users table:
+---------+------------+----------------+
| user_id | join_date  | favorite_brand |
+---------+------------+----------------+
| 1       | 2019-01-01 | Lenovo         |
| 2       | 2019-02-09 | Samsung        |
| 3       | 2019-01-19 | LG             |
| 4       | 2019-05-21 | HP             |
+---------+------------+----------------+
Orders table:
+----------+------------+---------+----------+-----------+
| order_id | order_date | item_id | buyer_id | seller_id |
+----------+------------+---------+----------+-----------+
| 1        | 2019-08-01 | 4       | 1        | 2         |
| 2        | 2019-08-02 | 2       | 1        | 3         |
| 3        | 2019-08-03 | 3       | 2        | 3         |
| 4        | 2019-08-04 | 1       | 4        | 2         |
| 5        | 2019-08-04 | 1       | 3        | 4         |
| 6        | 2019-08-05 | 2       | 2        | 4         |
+----------+------------+---------+----------+-----------+
Items table:
+---------+------------+
| item_id | item_brand |
+---------+------------+
| 1       | Samsung    |
| 2       | Lenovo     |
| 3       | LG         |
| 4       | HP         |
+---------+------------+
<strong>输出：</strong>
+-----------+--------------------+
| seller_id | 2nd_item_fav_brand |
+-----------+--------------------+
| 1         | no                 |
| 2         | yes                |
| 3         | yes                |
| 4         | no                 |
+-----------+--------------------+
<strong>解释：</strong>
id 为 1 的用户的查询结果是 no，因为他什么也没有卖出
id为 2 和 3 的用户的查询结果是 yes，因为他们卖出的第二件商品的品牌是他们最喜爱的品牌
id为 4 的用户的查询结果是 no，因为他卖出的第二件商品的品牌不是他最喜爱的品牌
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
SELECT
    u.user_id AS seller_id,
    CASE
        WHEN u.favorite_brand = i.item_brand THEN 'yes'
        ELSE 'no'
    END AS 2nd_item_fav_brand
FROM
    users AS u
    LEFT JOIN (
        SELECT
            order_date,
            item_id,
            seller_id,
            RANK() OVER (
                PARTITION BY seller_id
                ORDER BY order_date
            ) AS rk
        FROM orders
    ) AS o
        ON u.user_id = o.seller_id AND o.rk = 2
    LEFT JOIN items AS i ON o.item_id = i.item_id;
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
