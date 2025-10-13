---
title: "0320_列举单词的全部缩写 🔒"
date: 2025-10-08T18:35:54+08:00
weight: 3
tags: [二分查找, 位运算, 分治, 前缀和, 动态规划, 单调栈, 双指针, 哈希表, 回溯, 图, 字符串, 并查集, 广度优先搜索, 归并排序, 快速选择, 拓扑排序, 排序, 数学, 数组, 有序集合, 栈, 树状数组, 深度优先搜索, 矩阵, 线段树, 记忆化搜索, 贪心, 递归, 链表]
---

{{< markmap >}}
### [0320_列举单词的全部缩写 🔒](#320)
#### [位运算](#320)
#### [字符串](#320)
#### [回溯](#320)
### [0321_拼接最大数](#321)
#### [栈](#321)
#### [贪心](#321)
#### [数组](#321)
#### [双指针](#321)
#### [单调栈](#321)
### [0322_零钱兑换](#322)
#### [广度优先搜索](#322)
#### [数组](#322)
#### [动态规划](#322)
### [0323_无向图中连通分量的数目 🔒](#323)
#### [深度优先搜索](#323)
#### [广度优先搜索](#323)
#### [并查集](#323)
#### [图](#323)
### [0324_摆动排序 II](#324)
#### [贪心](#324)
#### [数组](#324)
#### [分治](#324)
#### [快速选择](#324)
#### [排序](#324)
### [0325_和等于 k 的最长子数组长度 🔒](#325)
#### [数组](#325)
#### [哈希表](#325)
#### [前缀和](#325)
### [0326_3 的幂](#326)
#### [递归](#326)
#### [数学](#326)
### [0327_区间和的个数](#327)
#### [树状数组](#327)
#### [线段树](#327)
#### [数组](#327)
#### [二分查找](#327)
#### [分治](#327)
#### [有序集合](#327)
#### [归并排序](#327)
### [0328_奇偶链表](#328)
#### [链表](#328)
### [0329_矩阵中的最长递增路径](#329)
#### [深度优先搜索](#329)
#### [广度优先搜索](#329)
#### [图](#329)
#### [拓扑排序](#329)
#### [记忆化搜索](#329)
#### [数组](#329)
#### [动态规划](#329)
#### [矩阵](#329)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0320_列举单词的全部缩写 🔒
___
#### 位运算
___
#### 字符串
___
#### 回溯
---
### 0321_拼接最大数
___
#### 栈
___
#### 贪心
___
#### 数组
___
#### 双指针
___
#### 单调栈
---
### 0322_零钱兑换
___
#### 广度优先搜索
___
#### 数组
___
#### 动态规划
---
### 0323_无向图中连通分量的数目 🔒
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 图
---
### 0324_摆动排序 II
___
#### 贪心
___
#### 数组
___
#### 分治
___
#### 快速选择
___
#### 排序
---
### 0325_和等于 k 的最长子数组长度 🔒
___
#### 数组
___
#### 哈希表
___
#### 前缀和
---
### 0326_3 的幂
___
#### 递归
___
#### 数学
---
### 0327_区间和的个数
___
#### 树状数组
___
#### 线段树
___
#### 数组
___
#### 二分查找
___
#### 分治
___
#### 有序集合
___
#### 归并排序
---
### 0328_奇偶链表
___
#### 链表
---
### 0329_矩阵中的最长递增路径
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 图
___
#### 拓扑排序
___
#### 记忆化搜索
___
#### 数组
___
#### 动态规划
___
#### 矩阵
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 二分查找 | 位运算 | 分治 |
| 前缀和 | 动态规划 | 单调栈 |
| 双指针 | 哈希表 | 回溯 |
| 图 | 字符串 | 并查集 |
| 广度优先搜索 | 归并排序 | 快速选择 |
| 拓扑排序 | 排序 | 数学 |
| 数组 | 有序集合 | 栈 |
| 树状数组 | 深度优先搜索 | 矩阵 |
| 线段树 | 记忆化搜索 | 贪心 |
| 递归 | 链表 |  |

# [320. 列举单词的全部缩写 🔒](https://leetcode.cn/problems/generalized-abbreviation){#320}

{{< tabs "320" >}}

{{% tab "python" %}}
```python
class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        n = len(word)
        ans = []
        for i in range(1 << n):
            cnt = 0
            s = []
            for j in range(n):
                if i >> j & 1:
                    cnt += 1
                else:
                    if cnt:
                        s.append(str(cnt))
                        cnt = 0
                    s.append(word[j])
            if cnt:
                s.append(str(cnt))
            ans.append("".join(s))
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<String> generateAbbreviations(String word) {
        int n = word.length();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            StringBuilder s = new StringBuilder();
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    ++cnt;
                } else {
                    if (cnt > 0) {
                        s.append(cnt);
                        cnt = 0;
                    }
                    s.append(word.charAt(j));
                }
            }
            if (cnt > 0) {
                s.append(cnt);
            }
            ans.add(s.toString());
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
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> ans;
        for (int i = 0; i < 1 << n; ++i) {
            string s;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    ++cnt;
                } else {
                    if (cnt) {
                        s += to_string(cnt);
                        cnt = 0;
                    }
                    s.push_back(word[j]);
                }
            }
            if (cnt) {
                s += to_string(cnt);
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
func generateAbbreviations(word string) (ans []string) {
	n := len(word)
	for i := 0; i < 1<<n; i++ {
		s := &strings.Builder{}
		cnt := 0
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				cnt++
			} else {
				if cnt > 0 {
					s.WriteString(strconv.Itoa(cnt))
					cnt = 0
				}
				s.WriteByte(word[j])
			}
		}
		if cnt > 0 {
			s.WriteString(strconv.Itoa(cnt))
		}
		ans = append(ans, s.String())
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function generateAbbreviations(word: string): string[] {
    const n = word.length;
    const dfs = (i: number): string[] => {
        if (i >= n) {
            return [''];
        }
        const ans: string[] = [];
        for (const s of dfs(i + 1)) {
            ans.push(word[i] + s);
        }
        for (let j = i + 1; j <= n; ++j) {
            for (const s of dfs(j + 1)) {
                ans.push((j - i).toString() + (j < n ? word[j] : '') + s);
            }
        }
        return ans;
    };
    return dfs(0);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>单词的 <strong>广义缩写词</strong> 可以通过下述步骤构造：先取任意数量的 <strong>不重叠、不相邻</strong> 的<span data-keyword="substring-nonempty">子字符串</span>，再用它们各自的长度进行替换。</p>

<ul>
	<li>例如，<code>"abcde"</code> 可以缩写为：

    <ul>
    	<li><code>"a3e"</code>（<code>"bcd"</code> 变为 <code>"3"</code> ）</li>
    	<li><code>"1bcd1"</code>（<code>"a"</code> 和 <code>"e"</code> 都变为 <code>"1"</code>）<meta charset="UTF-8" /></li>
    	<li><code>"5"</code>&nbsp;(<code>"abcde"</code>&nbsp;变为&nbsp;<code>"5"</code>)</li>
    	<li><code>"abcde"</code>&nbsp;(没有子字符串被代替)</li>
    </ul>
    </li>
    <li>然而，这些缩写是 <strong>无效的</strong> ：
    <ul>
    	<li><code>"23"</code>（<code>"ab"</code> 变为 <code>"2"</code> ，<code>"cde"</code> 变为 <code>"3"</code> ）是无效的，因为被选择的字符串是相邻的</li>
    	<li><meta charset="UTF-8" /><code>"22de"</code>&nbsp;(<code>"ab"</code> 变为&nbsp;<code>"2"</code>&nbsp;，&nbsp;<code>"bc"</code>&nbsp;变为&nbsp;<code>"2"</code>) &nbsp;是无效的，因为被选择的字符串是重叠的</li>
    </ul>
    </li>

</ul>

<p>给你一个字符串&nbsp;<code>word</code> ，返回&nbsp;<em>一个由</em>&nbsp;<code>word</code> 的<em>所有可能 <strong>广义缩写词</strong> 组成的列表</em>&nbsp;。按 <strong>任意顺序</strong> 返回答案。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "word"
<strong>输出：</strong>["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "a"
<strong>输出：</strong>["1","a"]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 15</code></li>
	<li><code>word</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们设计一个函数 $dfs(i)$，表示对于字符串 $word[i:]$，返回其所有可能的缩写。

函数 $dfs(i)$ 的执行逻辑如下：

如果 $i \geq n$，说明已经处理完了字符串 $word$，直接返回一个空字符串组成的列表。

否则，我们可以选择保留 $word[i]$，然后对 $dfs(i + 1)$ 返回的列表中的每个字符串前面添加 $word[i]$，将得到的结果添加到答案中。

我们也可以选择删除 $word[i]$ 及其后面的若干个字符，假设我们删除了 $word[i..j)$，那么第 $j$ 个字符不删除，然后对 $dfs(j + 1)$ 返回的列表中的每个字符串前面添加 $j - i$，将得到的结果添加到答案中。

最后，我们在主函数中调用 $dfs(0)$ 即可。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $word$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        def dfs(i: int) -> List[str]:
            if i >= n:
                return [""]
            ans = [word[i] + s for s in dfs(i + 1)]
            for j in range(i + 1, n + 1):
                for s in dfs(j + 1):
                    ans.append(str(j - i) + (word[j] if j < n else "") + s)
            return ans

        n = len(word)
        return dfs(0)
```

#### Java

```java
class Solution {
    private String word;
    private int n;

    public List<String> generateAbbreviations(String word) {
        this.word = word;
        n = word.length();
        return dfs(0);
    }

    private List<String> dfs(int i) {
        if (i >= n) {
            return List.of("");
        }
        List<String> ans = new ArrayList<>();
        for (String s : dfs(i + 1)) {
            ans.add(String.valueOf(word.charAt(i)) + s);
        }
        for (int j = i + 1; j <= n; ++j) {
            for (String s : dfs(j + 1)) {
                ans.add((j - i) + "" + (j < n ? String.valueOf(word.charAt(j)) : "") + s);
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
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        function<vector<string>(int)> dfs = [&](int i) -> vector<string> {
            if (i >= n) {
                return {""};
            }
            vector<string> ans;
            for (auto& s : dfs(i + 1)) {
                string p(1, word[i]);
                ans.emplace_back(p + s);
            }
            for (int j = i + 1; j <= n; ++j) {
                for (auto& s : dfs(j + 1)) {
                    string p = j < n ? string(1, word[j]) : "";
                    ans.emplace_back(to_string(j - i) + p + s);
                }
            }
            return ans;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func generateAbbreviations(word string) []string {
	n := len(word)
	var dfs func(int) []string
	dfs = func(i int) []string {
		if i >= n {
			return []string{""}
		}
		ans := []string{}
		for _, s := range dfs(i + 1) {
			ans = append(ans, word[i:i+1]+s)
		}
		for j := i + 1; j <= n; j++ {
			for _, s := range dfs(j + 1) {
				p := ""
				if j < n {
					p = word[j : j+1]
				}
				ans = append(ans, strconv.Itoa(j-i)+p+s)
			}
		}
		return ans
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function generateAbbreviations(word: string): string[] {
    const n = word.length;
    const dfs = (i: number): string[] => {
        if (i >= n) {
            return [''];
        }
        const ans: string[] = [];
        for (const s of dfs(i + 1)) {
            ans.push(word[i] + s);
        }
        for (let j = i + 1; j <= n; ++j) {
            for (const s of dfs(j + 1)) {
                ans.push((j - i).toString() + (j < n ? word[j] : '') + s);
            }
        }
        return ans;
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：二进制枚举

由于字符串 $word$ 的长度不超过 $15$，因此我们可以使用二进制枚举的方法枚举所有的缩写。我们用一个长度为 $n$ 的二进制数 $i$ 表示一种缩写方式，其中 $0$ 表示保留对应的字符，而 $1$ 表示删除对应的字符。我们在 $[0, 2^n)$ 的范围内枚举所有 $i$，并将其转换成对应的缩写，添加到答案列表中即可。

时间复杂度 $O(n \times 2^n)$，空间复杂度 $O(n)$。其中 $n$ 是字符串 $word$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        n = len(word)
        ans = []
        for i in range(1 << n):
            cnt = 0
            s = []
            for j in range(n):
                if i >> j & 1:
                    cnt += 1
                else:
                    if cnt:
                        s.append(str(cnt))
                        cnt = 0
                    s.append(word[j])
            if cnt:
                s.append(str(cnt))
            ans.append("".join(s))
        return ans
```

#### Java

```java
class Solution {
    public List<String> generateAbbreviations(String word) {
        int n = word.length();
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 1 << n; ++i) {
            StringBuilder s = new StringBuilder();
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j & 1) == 1) {
                    ++cnt;
                } else {
                    if (cnt > 0) {
                        s.append(cnt);
                        cnt = 0;
                    }
                    s.append(word.charAt(j));
                }
            }
            if (cnt > 0) {
                s.append(cnt);
            }
            ans.add(s.toString());
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        vector<string> ans;
        for (int i = 0; i < 1 << n; ++i) {
            string s;
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    ++cnt;
                } else {
                    if (cnt) {
                        s += to_string(cnt);
                        cnt = 0;
                    }
                    s.push_back(word[j]);
                }
            }
            if (cnt) {
                s += to_string(cnt);
            }
            ans.push_back(s);
        }
        return ans;
    }
};
```

#### Go

```go
func generateAbbreviations(word string) (ans []string) {
	n := len(word)
	for i := 0; i < 1<<n; i++ {
		s := &strings.Builder{}
		cnt := 0
		for j := 0; j < n; j++ {
			if i>>j&1 == 1 {
				cnt++
			} else {
				if cnt > 0 {
					s.WriteString(strconv.Itoa(cnt))
					cnt = 0
				}
				s.WriteByte(word[j])
			}
		}
		if cnt > 0 {
			s.WriteString(strconv.Itoa(cnt))
		}
		ans = append(ans, s.String())
	}
	return
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number){#321}

{{< tabs "321" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def f(nums: List[int], k: int) -> List[int]:
            n = len(nums)
            stk = [0] * k
            top = -1
            remain = n - k
            for x in nums:
                while top >= 0 and stk[top] < x and remain > 0:
                    top -= 1
                    remain -= 1
                if top + 1 < k:
                    top += 1
                    stk[top] = x
                else:
                    remain -= 1
            return stk

        def compare(nums1: List[int], nums2: List[int], i: int, j: int) -> bool:
            if i >= len(nums1):
                return False
            if j >= len(nums2):
                return True
            if nums1[i] > nums2[j]:
                return True
            if nums1[i] < nums2[j]:
                return False
            return compare(nums1, nums2, i + 1, j + 1)

        def merge(nums1: List[int], nums2: List[int]) -> List[int]:
            m, n = len(nums1), len(nums2)
            i = j = 0
            ans = [0] * (m + n)
            for k in range(m + n):
                if compare(nums1, nums2, i, j):
                    ans[k] = nums1[i]
                    i += 1
                else:
                    ans[k] = nums2[j]
                    j += 1
            return ans

        m, n = len(nums1), len(nums2)
        l, r = max(0, k - n), min(k, m)
        ans = [0] * k
        for x in range(l, r + 1):
            arr1 = f(nums1, x)
            arr2 = f(nums2, k - x)
            arr = merge(arr1, arr2)
            if ans < arr:
                ans = arr
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int m = nums1.length, n = nums2.length;
        int l = Math.max(0, k - n), r = Math.min(k, m);
        int[] ans = new int[k];
        for (int x = l; x <= r; ++x) {
            int[] arr1 = f(nums1, x);
            int[] arr2 = f(nums2, k - x);
            int[] arr = merge(arr1, arr2);
            if (compare(arr, ans, 0, 0)) {
                ans = arr;
            }
        }
        return ans;
    }

    private int[] f(int[] nums, int k) {
        int n = nums.length;
        int[] stk = new int[k];
        int top = -1;
        int remain = n - k;
        for (int x : nums) {
            while (top >= 0 && stk[top] < x && remain > 0) {
                --top;
                --remain;
            }
            if (top + 1 < k) {
                stk[++top] = x;
            } else {
                --remain;
            }
        }
        return stk;
    }

    private int[] merge(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int i = 0, j = 0;
        int[] ans = new int[m + n];
        for (int k = 0; k < m + n; ++k) {
            if (compare(nums1, nums2, i, j)) {
                ans[k] = nums1[i++];
            } else {
                ans[k] = nums2[j++];
            }
        }
        return ans;
    }

    private boolean compare(int[] nums1, int[] nums2, int i, int j) {
        if (i >= nums1.length) {
            return false;
        }
        if (j >= nums2.length) {
            return true;
        }
        if (nums1[i] > nums2[j]) {
            return true;
        }
        if (nums1[i] < nums2[j]) {
            return false;
        }
        return compare(nums1, nums2, i + 1, j + 1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        auto f = [](vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> stk(k);
            int top = -1;
            int remain = n - k;
            for (int x : nums) {
                while (top >= 0 && stk[top] < x && remain > 0) {
                    --top;
                    --remain;
                }
                if (top + 1 < k) {
                    stk[++top] = x;
                } else {
                    --remain;
                }
            }
            return stk;
        };
        function<bool(vector<int>&, vector<int>&, int, int)> compare = [&](vector<int>& nums1, vector<int>& nums2, int i, int j) -> bool {
            if (i >= nums1.size()) {
                return false;
            }
            if (j >= nums2.size()) {
                return true;
            }
            if (nums1[i] > nums2[j]) {
                return true;
            }
            if (nums1[i] < nums2[j]) {
                return false;
            }
            return compare(nums1, nums2, i + 1, j + 1);
        };

        auto merge = [&](vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
            int i = 0, j = 0;
            vector<int> ans(m + n);
            for (int k = 0; k < m + n; ++k) {
                if (compare(nums1, nums2, i, j)) {
                    ans[k] = nums1[i++];
                } else {
                    ans[k] = nums2[j++];
                }
            }
            return ans;
        };

        int m = nums1.size(), n = nums2.size();
        int l = max(0, k - n), r = min(k, m);
        vector<int> ans(k);
        for (int x = l; x <= r; ++x) {
            vector<int> arr1 = f(nums1, x);
            vector<int> arr2 = f(nums2, k - x);
            vector<int> arr = merge(arr1, arr2);
            if (ans < arr) {
                ans = move(arr);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxNumber(nums1 []int, nums2 []int, k int) []int {
	m, n := len(nums1), len(nums2)
	l, r := max(0, k-n), min(k, m)
	f := func(nums []int, k int) []int {
		n := len(nums)
		stk := make([]int, k)
		top := -1
		remain := n - k
		for _, x := range nums {
			for top >= 0 && stk[top] < x && remain > 0 {
				top--
				remain--
			}
			if top+1 < k {
				top++
				stk[top] = x
			} else {
				remain--
			}
		}
		return stk
	}

	var compare func(nums1, nums2 []int, i, j int) bool
	compare = func(nums1, nums2 []int, i, j int) bool {
		if i >= len(nums1) {
			return false
		}
		if j >= len(nums2) {
			return true
		}
		if nums1[i] > nums2[j] {
			return true
		}
		if nums1[i] < nums2[j] {
			return false
		}
		return compare(nums1, nums2, i+1, j+1)
	}

	merge := func(nums1, nums2 []int) []int {
		m, n := len(nums1), len(nums2)
		ans := make([]int, m+n)
		i, j := 0, 0
		for k := range ans {
			if compare(nums1, nums2, i, j) {
				ans[k] = nums1[i]
				i++
			} else {
				ans[k] = nums2[j]
				j++
			}
		}
		return ans
	}

	ans := make([]int, k)
	for x := l; x <= r; x++ {
		arr1 := f(nums1, x)
		arr2 := f(nums2, k-x)
		arr := merge(arr1, arr2)
		if compare(arr, ans, 0, 0) {
			ans = arr
		}
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxNumber(nums1: number[], nums2: number[], k: number): number[] {
    const m = nums1.length;
    const n = nums2.length;
    const l = Math.max(0, k - n);
    const r = Math.min(k, m);
    let ans: number[] = Array(k).fill(0);
    for (let x = l; x <= r; ++x) {
        const arr1 = f(nums1, x);
        const arr2 = f(nums2, k - x);
        const arr = merge(arr1, arr2);
        if (compare(arr, ans, 0, 0)) {
            ans = arr;
        }
    }
    return ans;
}

function f(nums: number[], k: number): number[] {
    const n = nums.length;
    const stk: number[] = Array(k).fill(0);
    let top = -1;
    let remain = n - k;
    for (const x of nums) {
        while (top >= 0 && stk[top] < x && remain > 0) {
            --top;
            --remain;
        }
        if (top + 1 < k) {
            stk[++top] = x;
        } else {
            --remain;
        }
    }
    return stk;
}

function compare(nums1: number[], nums2: number[], i: number, j: number): boolean {
    if (i >= nums1.length) {
        return false;
    }
    if (j >= nums2.length) {
        return true;
    }
    if (nums1[i] > nums2[j]) {
        return true;
    }
    if (nums1[i] < nums2[j]) {
        return false;
    }
    return compare(nums1, nums2, i + 1, j + 1);
}

function merge(nums1: number[], nums2: number[]): number[] {
    const m = nums1.length;
    const n = nums2.length;
    const ans: number[] = Array(m + n).fill(0);
    let i = 0;
    let j = 0;
    for (let k = 0; k < m + n; ++k) {
        if (compare(nums1, nums2, i, j)) {
            ans[k] = nums1[i++];
        } else {
            ans[k] = nums2[j++];
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

<p>给你两个整数数组 <code>nums1</code> 和 <code>nums2</code>，它们的长度分别为 <code>m</code> 和 <code>n</code>。数组 <code>nums1</code> 和 <code>nums2</code> 分别代表两个数各位上的数字。同时你也会得到一个整数 <code>k</code>。</p>

<p>请你利用这两个数组中的数字创建一个长度为 <code>k &lt;= m + n</code> 的最大数。同一数组中数字的相对顺序必须保持不变。</p>

<p>返回代表答案的长度为 <code>k</code> 的数组。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
<strong>输出：</strong>[9,8,6,5,3]
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [6,7], nums2 = [6,0,4], k = 5
<strong>输出：</strong>[6,7,6,0,4]
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>nums1 = [3,9], nums2 = [8,9], k = 3
<strong>输出：</strong>[9,8,9]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == nums1.length</code></li>
	<li><code>n == nums2.length</code></li>
	<li><code>1 &lt;= m, n &lt;= 500</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 9</code></li>
	<li><code>1 &lt;= k &lt;= m + n</code></li>
	<li><code>nums1</code>&nbsp;和&nbsp;<code>nums2</code> 没有前导 0。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 单调栈

我们可以枚举从数组 $nums1$ 中取出 $x$ 个数，那么从数组 $nums2$ 中就需要取出 $k-x$ 个数。其中 $x \in [max(0, k-n), min(k, m)]$。

对于每一个 $x$，我们可以使用单调栈求出数组 $nums1$ 中长度为 $x$ 的最大子序列，以及数组 $nums2$ 中长度为 $k-x$ 的最大子序列。然后将这两个子序列合并得到长度为 $k$ 的最大子序列。

最后，我们比较所有的长度为 $k$ 的最大子序列，找出最大的序列即可。

时间复杂度 $O(k \times (m + n + k^2))$，空间复杂度 $O(k)$。其中 $m$ 和 $n$ 分别是数组 $nums1$ 和 $nums2$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def f(nums: List[int], k: int) -> List[int]:
            n = len(nums)
            stk = [0] * k
            top = -1
            remain = n - k
            for x in nums:
                while top >= 0 and stk[top] < x and remain > 0:
                    top -= 1
                    remain -= 1
                if top + 1 < k:
                    top += 1
                    stk[top] = x
                else:
                    remain -= 1
            return stk

        def compare(nums1: List[int], nums2: List[int], i: int, j: int) -> bool:
            if i >= len(nums1):
                return False
            if j >= len(nums2):
                return True
            if nums1[i] > nums2[j]:
                return True
            if nums1[i] < nums2[j]:
                return False
            return compare(nums1, nums2, i + 1, j + 1)

        def merge(nums1: List[int], nums2: List[int]) -> List[int]:
            m, n = len(nums1), len(nums2)
            i = j = 0
            ans = [0] * (m + n)
            for k in range(m + n):
                if compare(nums1, nums2, i, j):
                    ans[k] = nums1[i]
                    i += 1
                else:
                    ans[k] = nums2[j]
                    j += 1
            return ans

        m, n = len(nums1), len(nums2)
        l, r = max(0, k - n), min(k, m)
        ans = [0] * k
        for x in range(l, r + 1):
            arr1 = f(nums1, x)
            arr2 = f(nums2, k - x)
            arr = merge(arr1, arr2)
            if ans < arr:
                ans = arr
        return ans
```

#### Java

```java
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int m = nums1.length, n = nums2.length;
        int l = Math.max(0, k - n), r = Math.min(k, m);
        int[] ans = new int[k];
        for (int x = l; x <= r; ++x) {
            int[] arr1 = f(nums1, x);
            int[] arr2 = f(nums2, k - x);
            int[] arr = merge(arr1, arr2);
            if (compare(arr, ans, 0, 0)) {
                ans = arr;
            }
        }
        return ans;
    }

    private int[] f(int[] nums, int k) {
        int n = nums.length;
        int[] stk = new int[k];
        int top = -1;
        int remain = n - k;
        for (int x : nums) {
            while (top >= 0 && stk[top] < x && remain > 0) {
                --top;
                --remain;
            }
            if (top + 1 < k) {
                stk[++top] = x;
            } else {
                --remain;
            }
        }
        return stk;
    }

    private int[] merge(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int i = 0, j = 0;
        int[] ans = new int[m + n];
        for (int k = 0; k < m + n; ++k) {
            if (compare(nums1, nums2, i, j)) {
                ans[k] = nums1[i++];
            } else {
                ans[k] = nums2[j++];
            }
        }
        return ans;
    }

    private boolean compare(int[] nums1, int[] nums2, int i, int j) {
        if (i >= nums1.length) {
            return false;
        }
        if (j >= nums2.length) {
            return true;
        }
        if (nums1[i] > nums2[j]) {
            return true;
        }
        if (nums1[i] < nums2[j]) {
            return false;
        }
        return compare(nums1, nums2, i + 1, j + 1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        auto f = [](vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> stk(k);
            int top = -1;
            int remain = n - k;
            for (int x : nums) {
                while (top >= 0 && stk[top] < x && remain > 0) {
                    --top;
                    --remain;
                }
                if (top + 1 < k) {
                    stk[++top] = x;
                } else {
                    --remain;
                }
            }
            return stk;
        };
        function<bool(vector<int>&, vector<int>&, int, int)> compare = [&](vector<int>& nums1, vector<int>& nums2, int i, int j) -> bool {
            if (i >= nums1.size()) {
                return false;
            }
            if (j >= nums2.size()) {
                return true;
            }
            if (nums1[i] > nums2[j]) {
                return true;
            }
            if (nums1[i] < nums2[j]) {
                return false;
            }
            return compare(nums1, nums2, i + 1, j + 1);
        };

        auto merge = [&](vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(), n = nums2.size();
            int i = 0, j = 0;
            vector<int> ans(m + n);
            for (int k = 0; k < m + n; ++k) {
                if (compare(nums1, nums2, i, j)) {
                    ans[k] = nums1[i++];
                } else {
                    ans[k] = nums2[j++];
                }
            }
            return ans;
        };

        int m = nums1.size(), n = nums2.size();
        int l = max(0, k - n), r = min(k, m);
        vector<int> ans(k);
        for (int x = l; x <= r; ++x) {
            vector<int> arr1 = f(nums1, x);
            vector<int> arr2 = f(nums2, k - x);
            vector<int> arr = merge(arr1, arr2);
            if (ans < arr) {
                ans = move(arr);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxNumber(nums1 []int, nums2 []int, k int) []int {
	m, n := len(nums1), len(nums2)
	l, r := max(0, k-n), min(k, m)
	f := func(nums []int, k int) []int {
		n := len(nums)
		stk := make([]int, k)
		top := -1
		remain := n - k
		for _, x := range nums {
			for top >= 0 && stk[top] < x && remain > 0 {
				top--
				remain--
			}
			if top+1 < k {
				top++
				stk[top] = x
			} else {
				remain--
			}
		}
		return stk
	}

	var compare func(nums1, nums2 []int, i, j int) bool
	compare = func(nums1, nums2 []int, i, j int) bool {
		if i >= len(nums1) {
			return false
		}
		if j >= len(nums2) {
			return true
		}
		if nums1[i] > nums2[j] {
			return true
		}
		if nums1[i] < nums2[j] {
			return false
		}
		return compare(nums1, nums2, i+1, j+1)
	}

	merge := func(nums1, nums2 []int) []int {
		m, n := len(nums1), len(nums2)
		ans := make([]int, m+n)
		i, j := 0, 0
		for k := range ans {
			if compare(nums1, nums2, i, j) {
				ans[k] = nums1[i]
				i++
			} else {
				ans[k] = nums2[j]
				j++
			}
		}
		return ans
	}

	ans := make([]int, k)
	for x := l; x <= r; x++ {
		arr1 := f(nums1, x)
		arr2 := f(nums2, k-x)
		arr := merge(arr1, arr2)
		if compare(arr, ans, 0, 0) {
			ans = arr
		}
	}
	return ans
}
```

#### TypeScript

```ts
function maxNumber(nums1: number[], nums2: number[], k: number): number[] {
    const m = nums1.length;
    const n = nums2.length;
    const l = Math.max(0, k - n);
    const r = Math.min(k, m);
    let ans: number[] = Array(k).fill(0);
    for (let x = l; x <= r; ++x) {
        const arr1 = f(nums1, x);
        const arr2 = f(nums2, k - x);
        const arr = merge(arr1, arr2);
        if (compare(arr, ans, 0, 0)) {
            ans = arr;
        }
    }
    return ans;
}

function f(nums: number[], k: number): number[] {
    const n = nums.length;
    const stk: number[] = Array(k).fill(0);
    let top = -1;
    let remain = n - k;
    for (const x of nums) {
        while (top >= 0 && stk[top] < x && remain > 0) {
            --top;
            --remain;
        }
        if (top + 1 < k) {
            stk[++top] = x;
        } else {
            --remain;
        }
    }
    return stk;
}

function compare(nums1: number[], nums2: number[], i: number, j: number): boolean {
    if (i >= nums1.length) {
        return false;
    }
    if (j >= nums2.length) {
        return true;
    }
    if (nums1[i] > nums2[j]) {
        return true;
    }
    if (nums1[i] < nums2[j]) {
        return false;
    }
    return compare(nums1, nums2, i + 1, j + 1);
}

function merge(nums1: number[], nums2: number[]): number[] {
    const m = nums1.length;
    const n = nums2.length;
    const ans: number[] = Array(m + n).fill(0);
    let i = 0;
    let j = 0;
    for (let k = 0; k < m + n; ++k) {
        if (compare(nums1, nums2, i, j)) {
            ans[k] = nums1[i++];
        } else {
            ans[k] = nums2[j++];
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

# [322. 零钱兑换](https://leetcode.cn/problems/coin-change){#322}

{{< tabs "322" >}}

{{% tab "python" %}}
```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = amount
        f = [0] + [inf] * n
        for x in coins:
            for j in range(x, n + 1):
                f[j] = min(f[j], f[j - x] + 1)
        return -1 if f[n] >= inf else f[n]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        final int inf = 1 << 30;
        int n = amount;
        int[] f = new int[n + 1];
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] = Math.min(f[j], f[j - x] + 1);
            }
        }
        return f[n] >= inf ? -1 : f[n];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] = min(f[j], f[j - x] + 1);
            }
        }
        return f[n] > n ? -1 : f[n];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func coinChange(coins []int, amount int) int {
	n := amount
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1 << 30
	}
	f[0] = 0
	for _, x := range coins {
		for j := x; j <= n; j++ {
			f[j] = min(f[j], f[j-x]+1)
		}
	}
	if f[n] > n {
		return -1
	}
	return f[n]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function coinChange(coins: number[], amount: number): number {
    const n = amount;
    const f: number[] = Array(n + 1).fill(1 << 30);
    f[0] = 0;
    for (const x of coins) {
        for (let j = x; j <= n; ++j) {
            f[j] = Math.min(f[j], f[j - x] + 1);
        }
    }
    return f[n] > n ? -1 : f[n];
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let n = amount as usize;
        let mut f = vec![n + 1; n + 1];
        f[0] = 0;
        for &x in &coins {
            for j in x as usize..=n {
                f[j] = f[j].min(f[j - (x as usize)] + 1);
            }
        }
        if f[n] > n {
            -1
        } else {
            f[n] as i32
        }
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
    const n = amount;
    const f = Array(n + 1).fill(1 << 30);
    f[0] = 0;
    for (const x of coins) {
        for (let j = x; j <= n; ++j) {
            f[j] = Math.min(f[j], f[j - x] + 1);
        }
    }
    return f[n] > n ? -1 : f[n];
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>coins</code> ，表示不同面额的硬币；以及一个整数 <code>amount</code> ，表示总金额。</p>

<p>计算并返回可以凑成总金额所需的 <strong>最少的硬币个数</strong> 。如果没有任何一种硬币组合能组成总金额，返回&nbsp;<code>-1</code> 。</p>

<p>你可以认为每种硬币的数量是无限的。</p>

<p>&nbsp;</p>

<p><strong>示例&nbsp;1：</strong></p>

<pre>
<strong>输入：</strong>coins = <code>[1, 2, 5]</code>, amount = <code>11</code>
<strong>输出：</strong><code>3</code> 
<strong>解释：</strong>11 = 5 + 5 + 1</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>coins = <code>[2]</code>, amount = <code>3</code>
<strong>输出：</strong>-1</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>coins = [1], amount = 0
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= coins.length &lt;= 12</code></li>
	<li><code>1 &lt;= coins[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>0 &lt;= amount &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：动态规划(完全背包)

我们定义 $f[i][j]$ 表示使用前 $i$ 种硬币，凑出金额 $j$ 的最少硬币数。初始时 $f[0][0] = 0$，其余位置的值均为正无穷。

我们可以枚举使用的最后一枚硬币的数量 $k$，那么有：

$$
f[i][j] = \min(f[i - 1][j], f[i - 1][j - x] + 1, \cdots, f[i - 1][j - k \times x] + k)
$$

其中 $x$ 表示第 $i$ 种硬币的面值。

不妨令 $j = j - x$，那么有：

$$
f[i][j - x] = \min(f[i - 1][j - x], f[i - 1][j - 2 \times x] + 1, \cdots, f[i - 1][j - k \times x] + k - 1)
$$

将二式代入一式，我们可以得到以下状态转移方程：

$$
f[i][j] = \min(f[i - 1][j], f[i][j - x] + 1)
$$

最后答案即为 $f[m][n]$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别为硬币的种类数和总金额。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        m, n = len(coins), amount
        f = [[inf] * (n + 1) for _ in range(m + 1)]
        f[0][0] = 0
        for i, x in enumerate(coins, 1):
            for j in range(n + 1):
                f[i][j] = f[i - 1][j]
                if j >= x:
                    f[i][j] = min(f[i][j], f[i][j - x] + 1)
        return -1 if f[m][n] >= inf else f[m][n]
```

#### Java

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        final int inf = 1 << 30;
        int m = coins.length;
        int n = amount;
        int[][] f = new int[m + 1][n + 1];
        for (var g : f) {
            Arrays.fill(g, inf);
        }
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= coins[i - 1]) {
                    f[i][j] = Math.min(f[i][j], f[i][j - coins[i - 1]] + 1);
                }
            }
        }
        return f[m][n] >= inf ? -1 : f[m][n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size(), n = amount;
        int f[m + 1][n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0][0] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                if (j >= coins[i - 1]) {
                    f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
                }
            }
        }
        return f[m][n] > n ? -1 : f[m][n];
    }
};
```

#### Go

```go
func coinChange(coins []int, amount int) int {
	m, n := len(coins), amount
	f := make([][]int, m+1)
	const inf = 1 << 30
	for i := range f {
		f[i] = make([]int, n+1)
		for j := range f[i] {
			f[i][j] = inf
		}
	}
	f[0][0] = 0
	for i := 1; i <= m; i++ {
		for j := 0; j <= n; j++ {
			f[i][j] = f[i-1][j]
			if j >= coins[i-1] {
				f[i][j] = min(f[i][j], f[i][j-coins[i-1]]+1)
			}
		}
	}
	if f[m][n] > n {
		return -1
	}
	return f[m][n]
}
```

#### TypeScript

```ts
function coinChange(coins: number[], amount: number): number {
    const m = coins.length;
    const n = amount;
    const f: number[][] = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(1 << 30));
    f[0][0] = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= coins[i - 1]) {
                f[i][j] = Math.min(f[i][j], f[i][j - coins[i - 1]] + 1);
            }
        }
    }
    return f[m][n] > n ? -1 : f[m][n];
}
```

#### Rust

```rust
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let n = amount as usize;
        let mut f = vec![n + 1; n + 1];
        f[0] = 0;
        for &x in &coins {
            for j in x as usize..=n {
                f[j] = f[j].min(f[j - (x as usize)] + 1);
            }
        }
        if f[n] > n {
            -1
        } else {
            f[n] as i32
        }
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
    const m = coins.length;
    const n = amount;
    const f = Array(m + 1)
        .fill(0)
        .map(() => Array(n + 1).fill(1 << 30));
    f[0][0] = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 0; j <= n; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= coins[i - 1]) {
                f[i][j] = Math.min(f[i][j], f[i][j - coins[i - 1]] + 1);
            }
        }
    }
    return f[m][n] > n ? -1 : f[m][n];
};
```

<!-- tabs:end -->

我们注意到 $f[i][j]$ 只与 $f[i - 1][j]$ 和 $f[i][j - x]$ 有关，因此我们可以将二维数组优化为一维数组，空间复杂度降为 $O(n)$。

相似题目：

-   [279. 完全平方数](https://github.com/doocs/leetcode/blob/main/solution/0200-0299/0279.Perfect%20Squares/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = amount
        f = [0] + [inf] * n
        for x in coins:
            for j in range(x, n + 1):
                f[j] = min(f[j], f[j - x] + 1)
        return -1 if f[n] >= inf else f[n]
```

#### Java

```java
class Solution {
    public int coinChange(int[] coins, int amount) {
        final int inf = 1 << 30;
        int n = amount;
        int[] f = new int[n + 1];
        Arrays.fill(f, inf);
        f[0] = 0;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] = Math.min(f[j], f[j - x] + 1);
            }
        }
        return f[n] >= inf ? -1 : f[n];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        int f[n + 1];
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int x : coins) {
            for (int j = x; j <= n; ++j) {
                f[j] = min(f[j], f[j - x] + 1);
            }
        }
        return f[n] > n ? -1 : f[n];
    }
};
```

#### Go

```go
func coinChange(coins []int, amount int) int {
	n := amount
	f := make([]int, n+1)
	for i := range f {
		f[i] = 1 << 30
	}
	f[0] = 0
	for _, x := range coins {
		for j := x; j <= n; j++ {
			f[j] = min(f[j], f[j-x]+1)
		}
	}
	if f[n] > n {
		return -1
	}
	return f[n]
}
```

#### TypeScript

```ts
function coinChange(coins: number[], amount: number): number {
    const n = amount;
    const f: number[] = Array(n + 1).fill(1 << 30);
    f[0] = 0;
    for (const x of coins) {
        for (let j = x; j <= n; ++j) {
            f[j] = Math.min(f[j], f[j - x] + 1);
        }
    }
    return f[n] > n ? -1 : f[n];
}
```

#### JavaScript

```js
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function (coins, amount) {
    const n = amount;
    const f = Array(n + 1).fill(1 << 30);
    f[0] = 0;
    for (const x of coins) {
        for (let j = x; j <= n; ++j) {
            f[j] = Math.min(f[j], f[j - x] + 1);
        }
    }
    return f[n] > n ? -1 : f[n];
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [323. 无向图中连通分量的数目 🔒](https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph){#323}

{{< tabs "323" >}}

{{% tab "python" %}}
```python
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set()
        ans = 0
        for i in range(n):
            if i in vis:
                continue
            vis.add(i)
            q = deque([i])
            while q:
                a = q.popleft()
                for b in g[a]:
                    if b not in vis:
                        vis.add(b)
                        q.append(b)
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countComponents(int n, int[][] edges) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(i);
            while (!q.isEmpty()) {
                int a = q.poll();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.offer(b);
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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            queue<int> q{{i}};
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.push(b);
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
func countComponents(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	vis := make([]bool, n)
	for i := range g {
		if vis[i] {
			continue
		}
		vis[i] = true
		ans++
		q := []int{i}
		for len(q) > 0 {
			a := q[0]
			q = q[1:]
			for _, b := range g[a] {
				if !vis[b] {
					vis[b] = true
					q = append(q, b)
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
function countComponents(n: number, edges: number[][]): number {
    const g: Map<number, number[]> = new Map(Array.from({ length: n }, (_, i) => [i, []]));
    for (const [a, b] of edges) {
        g.get(a)!.push(b);
        g.get(b)!.push(a);
    }

    const vis = new Set<number>();
    let ans = 0;
    for (const [i] of g) {
        if (vis.has(i)) {
            continue;
        }
        const q = [i];
        for (const j of q) {
            if (vis.has(j)) {
                continue;
            }
            vis.add(j);
            q.push(...g.get(j)!);
        }
        ans++;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countComponents = function (n, edges) {
    const g = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const vis = Array(n).fill(false);
    const dfs = i => {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        for (const j of g[i]) {
            dfs(j);
        }
        return 1;
    };
    return g.reduce((acc, _, i) => acc + dfs(i), 0);
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你有一个包含&nbsp;<code>n</code> 个节点的图。给定一个整数 <code>n</code> 和一个数组&nbsp;<code>edges</code>&nbsp;，其中&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>&nbsp;表示图中&nbsp;<code>a<sub>i</sub></code>&nbsp;和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边。</p>

<p>返回 <em>图中已连接分量的数目</em>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0323.Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph/images/conn1-graph.jpg" /></p>

<pre>
<strong>输入: </strong><code>n = 5</code>, <code>edges = [[0, 1], [1, 2], [3, 4]]</code>
<strong>输出: </strong>2
</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0323.Number%20of%20Connected%20Components%20in%20an%20Undirected%20Graph/images/conn2-graph.jpg" /></p>

<pre>
<strong>输入: </strong><code>n = 5,</code> <code>edges = [[0,1], [1,2], [2,3], [3,4]]</code>
<strong>输出:&nbsp;&nbsp;</strong>1</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2000</code></li>
	<li><code>1 &lt;= edges.length &lt;= 5000</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>&nbsp;&lt;= b<sub>i</sub>&nbsp;&lt; n</code></li>
	<li><code>a<sub>i</sub>&nbsp;!= b<sub>i</sub></code></li>
	<li><code>edges</code> 中不会出现重复的边</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：DFS

我们先根据给定的边构建一个邻接表 $g$，其中 $g[i]$ 表示节点 $i$ 的所有邻居节点。

然后我们遍历所有节点，对于每个节点，我们使用 DFS 遍历所有与其相邻的节点，并将其标记为已访问，直到所有与其相邻的节点都被访问过，这样我们就找到了一个连通分量，答案加一。然后我们继续遍历下一个未访问的节点，直到所有节点都被访问过。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        def dfs(i: int) -> int:
            if i in vis:
                return 0
            vis.add(i)
            for j in g[i]:
                dfs(j)
            return 1

        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set()
        return sum(dfs(i) for i in range(n))
```

#### Java

```java
class Solution {
    private List<Integer>[] g;
    private boolean[] vis;

    public int countComponents(int n, int[][] edges) {
        g = new List[n];
        vis = new boolean[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dfs(i);
        }
        return ans;
    }

    private int dfs(int i) {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        for (int j : g[i]) {
            dfs(j);
        }
        return 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vis(n);
        function<int(int)> dfs = [&](int i) {
            if (vis[i]) {
                return 0;
            }
            vis[i] = true;
            for (int j : g[i]) {
                dfs(j);
            }
            return 1;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += dfs(i);
        }
        return ans;
    }
};
```

#### Go

```go
func countComponents(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	vis := make([]bool, n)
	var dfs func(int) int
	dfs = func(i int) int {
		if vis[i] {
			return 0
		}
		vis[i] = true
		for _, j := range g[i] {
			dfs(j)
		}
		return 1
	}
	for i := range g {
		ans += dfs(i)
	}
	return
}
```

#### TypeScript

```ts
function countComponents(n: number, edges: number[][]): number {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const vis: boolean[] = Array(n).fill(false);
    const dfs = (i: number): number => {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        for (const j of g[i]) {
            dfs(j);
        }
        return 1;
    };
    return g.reduce((acc, _, i) => acc + dfs(i), 0);
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var countComponents = function (n, edges) {
    const g = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const vis = Array(n).fill(false);
    const dfs = i => {
        if (vis[i]) {
            return 0;
        }
        vis[i] = true;
        for (const j of g[i]) {
            dfs(j);
        }
        return 1;
    };
    return g.reduce((acc, _, i) => acc + dfs(i), 0);
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：并查集

我们可以使用并查集来维护图中的连通分量。

我们首先初始化一个并查集，然后遍历所有的边，对于每条边 $(a, b)$，我们将节点 $a$ 和节点 $b$ 合并到同一个连通分量中，如果连接成功，说明节点 $a$ 和节点 $b$ 之前不在同一个连通分量中，连通分量数目减一。

最后我们返回连通分量的数目。

时间复杂度 $O(n + m \times \alpha(n))$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是节点数和边数，而 $\alpha(n)$ 是 Ackermann 函数的反函数，可以看作是一个很小的常数。

<!-- tabs:start -->

#### Python3

```python
class UnionFind:
    def __init__(self, n):
        self.p = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, a, b):
        pa, pb = self.find(a), self.find(b)
        if pa == pb:
            return False
        if self.size[pa] > self.size[pb]:
            self.p[pb] = pa
            self.size[pa] += self.size[pb]
        else:
            self.p[pa] = pb
            self.size[pb] += self.size[pa]
        return True


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        uf = UnionFind(n)
        for a, b in edges:
            n -= uf.union(a, b)
        return n
```

#### Java

```java
class UnionFind {
    private final int[] p;
    private final int[] size;

    public UnionFind(int n) {
        p = new int[n];
        size = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
    }

    public int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    public boolean union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }
}

class Solution {
    public int countComponents(int n, int[][] edges) {
        UnionFind uf = new UnionFind(n);
        for (var e : edges) {
            n -= uf.union(e[0], e[1]) ? 1 : 0;
        }
        return n;
    }
}
```

#### C++

```cpp
class UnionFind {
public:
    UnionFind(int n) {
        p = vector<int>(n);
        size = vector<int>(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& e : edges) {
            n -= uf.unite(e[0], e[1]);
        }
        return n;
    }
};
```

#### Go

```go
type unionFind struct {
	p, size []int
}

func newUnionFind(n int) *unionFind {
	p := make([]int, n)
	size := make([]int, n)
	for i := range p {
		p[i] = i
		size[i] = 1
	}
	return &unionFind{p, size}
}

func (uf *unionFind) find(x int) int {
	if uf.p[x] != x {
		uf.p[x] = uf.find(uf.p[x])
	}
	return uf.p[x]
}

func (uf *unionFind) union(a, b int) bool {
	pa, pb := uf.find(a), uf.find(b)
	if pa == pb {
		return false
	}
	if uf.size[pa] > uf.size[pb] {
		uf.p[pb] = pa
		uf.size[pa] += uf.size[pb]
	} else {
		uf.p[pa] = pb
		uf.size[pb] += uf.size[pa]
	}
	return true
}

func countComponents(n int, edges [][]int) int {
	uf := newUnionFind(n)
	for _, e := range edges {
		if uf.union(e[0], e[1]) {
			n--
		}
	}
	return n
}
```

#### TypeScript

```ts
class UnionFind {
    p: number[];
    size: number[];
    constructor(n: number) {
        this.p = Array(n)
            .fill(0)
            .map((_, i) => i);
        this.size = Array(n).fill(1);
    }

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }

    union(a: number, b: number): boolean {
        const [pa, pb] = [this.find(a), this.find(b)];
        if (pa === pb) {
            return false;
        }
        if (this.size[pa] > this.size[pb]) {
            this.p[pb] = pa;
            this.size[pa] += this.size[pb];
        } else {
            this.p[pa] = pb;
            this.size[pb] += this.size[pa];
        }
        return true;
    }
}

function countComponents(n: number, edges: number[][]): number {
    const uf = new UnionFind(n);
    for (const [a, b] of edges) {
        n -= uf.union(a, b) ? 1 : 0;
    }
    return n;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法三：BFS

我们也可以使用 BFS 来统计图中的连通分量。

与方法一类似，我们首先根据给定的边构建一个邻接表 $g$，然后遍历所有节点，对于每个节点，如果它没有被访问过，我们就从该节点开始进行 BFS 遍历，将所有与其相邻的节点都标记为已访问，直到所有与其相邻的节点都被访问过，这样我们就找到了一个连通分量，答案加一。

遍历所有节点后，我们就得到了图中连通分量的数目。

时间复杂度 $O(n + m)$，空间复杂度 $O(n + m)$。其中 $n$ 和 $m$ 分别是节点数和边数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        g = [[] for _ in range(n)]
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)
        vis = set()
        ans = 0
        for i in range(n):
            if i in vis:
                continue
            vis.add(i)
            q = deque([i])
            while q:
                a = q.popleft()
                for b in g[a]:
                    if b not in vis:
                        vis.add(b)
                        q.append(b)
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int countComponents(int n, int[][] edges) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        int ans = 0;
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            Deque<Integer> q = new ArrayDeque<>();
            q.offer(i);
            while (!q.isEmpty()) {
                int a = q.poll();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.offer(b);
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
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++ans;
            queue<int> q{{i}};
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (int b : g[a]) {
                    if (!vis[b]) {
                        vis[b] = true;
                        q.push(b);
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
func countComponents(n int, edges [][]int) (ans int) {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	vis := make([]bool, n)
	for i := range g {
		if vis[i] {
			continue
		}
		vis[i] = true
		ans++
		q := []int{i}
		for len(q) > 0 {
			a := q[0]
			q = q[1:]
			for _, b := range g[a] {
				if !vis[b] {
					vis[b] = true
					q = append(q, b)
				}
			}
		}
	}
	return
}
```

#### TypeScript

```ts
function countComponents(n: number, edges: number[][]): number {
    const g: Map<number, number[]> = new Map(Array.from({ length: n }, (_, i) => [i, []]));
    for (const [a, b] of edges) {
        g.get(a)!.push(b);
        g.get(b)!.push(a);
    }

    const vis = new Set<number>();
    let ans = 0;
    for (const [i] of g) {
        if (vis.has(i)) {
            continue;
        }
        const q = [i];
        for (const j of q) {
            if (vis.has(j)) {
                continue;
            }
            vis.add(j);
            q.push(...g.get(j)!);
        }
        ans++;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [324. 摆动排序 II](https://leetcode.cn/problems/wiggle-sort-ii){#324}

{{< tabs "324" >}}

{{% tab "python" %}}
```python
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        bucket = [0] * 5001
        for v in nums:
            bucket[v] += 1
        n = len(nums)
        j = 5000
        for i in range(1, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
        for i in range(0, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public void wiggleSort(int[] nums) {
        int[] bucket = new int[5001];
        for (int v : nums) {
            ++bucket[v];
        }
        int n = nums.length;
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> bucket(5001);
        for (int& v : nums) ++bucket[v];
        int n = nums.size();
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func wiggleSort(nums []int) {
	bucket := make([]int, 5001)
	for _, v := range nums {
		bucket[v]++
	}
	n, j := len(nums), 5000
	for i := 1; i < n; i += 2 {
		for bucket[j] == 0 {
			j--
		}
		nums[i] = j
		bucket[j]--
	}
	for i := 0; i < n; i += 2 {
		for bucket[j] == 0 {
			j--
		}
		nums[i] = j
		bucket[j]--
	}
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function (nums) {
    let bucket = new Array(5001).fill(0);
    for (const v of nums) {
        bucket[v]++;
    }
    const n = nums.length;
    let j = 5000;
    for (let i = 1; i < n; i += 2) {
        while (bucket[j] == 0) {
            --j;
        }
        nums[i] = j;
        --bucket[j];
    }
    for (let i = 0; i < n; i += 2) {
        while (bucket[j] == 0) {
            --j;
        }
        nums[i] = j;
        --bucket[j];
    }
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code>，将它重新排列成 <code>nums[0] < nums[1] > nums[2] < nums[3]...</code> 的顺序。</p>

<p>你可以假设所有输入数组都可以得到满足题目要求的结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,5,1,1,6,4]
<strong>输出：</strong>[1,6,1,5,1,4]
<strong>解释：</strong>[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [1,3,2,2,3,1]
<strong>输出：</strong>[2,3,1,3,1,2]
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 5 * 10<sup>4</sup></code></li>
	<li><code>0 <= nums[i] <= 5000</code></li>
	<li>题目数据保证，对于给定的输入 <code>nums</code> ，总能产生满足题目要求的结果</li>
</ul>

<p> </p>

<p><strong>进阶：</strong>你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：排序

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        arr = sorted(nums)
        n = len(arr)
        i, j = (n - 1) >> 1, n - 1
        for k in range(n):
            if k % 2 == 0:
                nums[k] = arr[i]
                i -= 1
            else:
                nums[k] = arr[j]
                j -= 1
```

#### Java

```java
class Solution {
    public void wiggleSort(int[] nums) {
        int[] arr = nums.clone();
        Arrays.sort(arr);
        int n = nums.length;
        int i = (n - 1) >> 1, j = n - 1;
        for (int k = 0; k < n; ++k) {
            if (k % 2 == 0) {
                nums[k] = arr[i--];
            } else {
                nums[k] = arr[j--];
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int n = nums.size();
        int i = (n - 1) >> 1, j = n - 1;
        for (int k = 0; k < n; ++k) {
            if (k % 2 == 0)
                nums[k] = arr[i--];
            else
                nums[k] = arr[j--];
        }
    }
};
```

#### Go

```go
func wiggleSort(nums []int) {
	n := len(nums)
	arr := make([]int, n)
	copy(arr, nums)
	sort.Ints(arr)
	i, j := (n-1)>>1, n-1
	for k := 0; k < n; k++ {
		if k%2 == 0 {
			nums[k] = arr[i]
			i--
		} else {
			nums[k] = arr[j]
			j--
		}
	}
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function (nums) {
    let bucket = new Array(5001).fill(0);
    for (const v of nums) {
        bucket[v]++;
    }
    const n = nums.length;
    let j = 5000;
    for (let i = 1; i < n; i += 2) {
        while (bucket[j] == 0) {
            --j;
        }
        nums[i] = j;
        --bucket[j];
    }
    for (let i = 0; i < n; i += 2) {
        while (bucket[j] == 0) {
            --j;
        }
        nums[i] = j;
        --bucket[j];
    }
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：桶排序

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        bucket = [0] * 5001
        for v in nums:
            bucket[v] += 1
        n = len(nums)
        j = 5000
        for i in range(1, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
        for i in range(0, n, 2):
            while bucket[j] == 0:
                j -= 1
            nums[i] = j
            bucket[j] -= 1
```

#### Java

```java
class Solution {
    public void wiggleSort(int[] nums) {
        int[] bucket = new int[5001];
        for (int v : nums) {
            ++bucket[v];
        }
        int n = nums.length;
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) {
                --j;
            }
            nums[i] = j;
            --bucket[j];
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> bucket(5001);
        for (int& v : nums) ++bucket[v];
        int n = nums.size();
        int j = 5000;
        for (int i = 1; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
        for (int i = 0; i < n; i += 2) {
            while (bucket[j] == 0) --j;
            nums[i] = j;
            --bucket[j];
        }
    }
};
```

#### Go

```go
func wiggleSort(nums []int) {
	bucket := make([]int, 5001)
	for _, v := range nums {
		bucket[v]++
	}
	n, j := len(nums), 5000
	for i := 1; i < n; i += 2 {
		for bucket[j] == 0 {
			j--
		}
		nums[i] = j
		bucket[j]--
	}
	for i := 0; i < n; i += 2 {
		for bucket[j] == 0 {
			j--
		}
		nums[i] = j
		bucket[j]--
	}
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [325. 和等于 k 的最长子数组长度 🔒](https://leetcode.cn/problems/maximum-size-subarray-sum-equals-k){#325}

{{< tabs "325" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        d = {0: -1}
        ans = s = 0
        for i, x in enumerate(nums):
            s += x
            if s - k in d:
                ans = max(ans, i - d[s - k])
            if s not in d:
                d[s] = i
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        Map<Long, Integer> d = new HashMap<>();
        d.put(0L, -1);
        int ans = 0;
        long s = 0;
        for (int i = 0; i < nums.length; ++i) {
            s += nums[i];
            ans = Math.max(ans, i - d.getOrDefault(s - k, i));
            d.putIfAbsent(s, i);
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
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> d{{0, -1}};
        int ans = 0;
        long long s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if (d.count(s - k)) {
                ans = max(ans, i - d[s - k]);
            }
            if (!d.count(s)) {
                d[s] = i;
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxSubArrayLen(nums []int, k int) (ans int) {
	d := map[int]int{0: -1}
	s := 0
	for i, x := range nums {
		s += x
		if j, ok := d[s-k]; ok && ans < i-j {
			ans = i - j
		}
		if _, ok := d[s]; !ok {
			d[s] = i
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxSubArrayLen(nums: number[], k: number): number {
    const d: Map<number, number> = new Map();
    d.set(0, -1);
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i];
        if (d.has(s - k)) {
            ans = Math.max(ans, i - d.get(s - k)!);
        }
        if (!d.has(s)) {
            d.set(s, i);
        }
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
use std::collections::HashMap;

impl Solution {
    pub fn max_sub_array_len(nums: Vec<i32>, k: i32) -> i32 {
        let mut d = HashMap::new();
        d.insert(0, -1);
        let mut ans = 0;
        let mut s = 0;

        for (i, &x) in nums.iter().enumerate() {
            s += x;
            if let Some(&j) = d.get(&(s - k)) {
                ans = ans.max((i as i32) - j);
            }
            d.entry(s).or_insert(i as i32);
        }

        ans
    }
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
var maxSubArrayLen = function (nums, k) {
    const d = new Map();
    d.set(0, -1);
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i];
        if (d.has(s - k)) {
            ans = Math.max(ans, i - d.get(s - k));
        }
        if (!d.has(s)) {
            d.set(s, i);
        }
    }
    return ans;
};
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int MaxSubArrayLen(int[] nums, int k) {
        var d = new Dictionary<int, int>();
        d[0] = -1;
        int ans = 0;
        int s = 0;
        for (int i = 0; i < nums.Length; i++) {
            s += nums[i];
            if (d.ContainsKey(s - k)) {
                ans = Math.Max(ans, i - d[s - k]);
            }
            if (!d.ContainsKey(s)) {
                d[s] = i;
            }
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

<p>给定一个数组 <code><em>nums</em></code> 和一个目标值 <code><em>k</em></code>，找到和等于<em> <code>k</code> </em>的最长连续<span data-keyword="subarray">子数组</span>长度。如果不存在任意一个符合要求的子数组，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre>
<strong>输入: </strong><em>nums</em> = <code>[1,-1,5,-2,3]</code>, <em>k</em> = <code>3</code>
<strong>输出: </strong>4 
<strong>解释: </strong>子数组 <code>[1, -1, 5, -2]</code> 和等于 3，且长度最长。
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入: </strong><em>nums</em> = <code>[-2,-1,2,1]</code>, <em>k</em> = <code>1</code>
<strong>输出: </strong>2 <strong>
解释: </strong>子数组<code> [-1, 2]</code> 和等于 1，且长度最长。</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup>&nbsp;&lt;= k &lt;= 10<sup>9</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表 + 前缀和

我们可以用一个哈希表 $\textit{d}$ 记录数组 $\textit{nums}$ 中每个前缀和第一次出现的下标，初始时 $\textit{d}[0] = -1$。另外定义一个变量 $\textit{s}$ 记录前缀和。

接下来，遍历数组 $\textit{nums}$，对于当前遍历到的数字 $\textit{nums}[i]$，我们更新前缀和 $\textit{s} = \textit{s} + \textit{nums}[i]$，如果 $\textit{s}-k$ 在哈希表 $\textit{d}$ 中存在，不妨记 $j = \textit{d}[\textit{s} - k]$，那么以 $\textit{nums}[i]$ 结尾的符合条件的子数组的长度为 $i - j$，我们使用一个变量 $\textit{ans}$ 来维护最长的符合条件的子数组的长度。然后，如果 $\textit{s}$ 在哈希表中不存在，我们记录 $\textit{s}$ 和对应的下标 $i$，即 $\textit{d}[\textit{s}] = i$，否则我们不更新 $\textit{d}[\textit{s}]$。需要注意的是，可能会有多个位置 $i$ 都满足 $\textit{s}$ 的值，因此我们只记录最小的 $i$，这样就能保证子数组的长度最长。

遍历结束之后，我们返回 $\textit{ans}$ 即可。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是数组 $\textit{nums}$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        d = {0: -1}
        ans = s = 0
        for i, x in enumerate(nums):
            s += x
            if s - k in d:
                ans = max(ans, i - d[s - k])
            if s not in d:
                d[s] = i
        return ans
```

#### Java

```java
class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        Map<Long, Integer> d = new HashMap<>();
        d.put(0L, -1);
        int ans = 0;
        long s = 0;
        for (int i = 0; i < nums.length; ++i) {
            s += nums[i];
            ans = Math.max(ans, i - d.getOrDefault(s - k, i));
            d.putIfAbsent(s, i);
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long long, int> d{{0, -1}};
        int ans = 0;
        long long s = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if (d.count(s - k)) {
                ans = max(ans, i - d[s - k]);
            }
            if (!d.count(s)) {
                d[s] = i;
            }
        }
        return ans;
    }
};
```

#### Go

```go
func maxSubArrayLen(nums []int, k int) (ans int) {
	d := map[int]int{0: -1}
	s := 0
	for i, x := range nums {
		s += x
		if j, ok := d[s-k]; ok && ans < i-j {
			ans = i - j
		}
		if _, ok := d[s]; !ok {
			d[s] = i
		}
	}
	return
}
```

#### TypeScript

```ts
function maxSubArrayLen(nums: number[], k: number): number {
    const d: Map<number, number> = new Map();
    d.set(0, -1);
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i];
        if (d.has(s - k)) {
            ans = Math.max(ans, i - d.get(s - k)!);
        }
        if (!d.has(s)) {
            d.set(s, i);
        }
    }
    return ans;
}
```

#### Rust

```rust
use std::collections::HashMap;

impl Solution {
    pub fn max_sub_array_len(nums: Vec<i32>, k: i32) -> i32 {
        let mut d = HashMap::new();
        d.insert(0, -1);
        let mut ans = 0;
        let mut s = 0;

        for (i, &x) in nums.iter().enumerate() {
            s += x;
            if let Some(&j) = d.get(&(s - k)) {
                ans = ans.max((i as i32) - j);
            }
            d.entry(s).or_insert(i as i32);
        }

        ans
    }
}
```

#### JavaScript

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxSubArrayLen = function (nums, k) {
    const d = new Map();
    d.set(0, -1);
    let ans = 0;
    let s = 0;
    for (let i = 0; i < nums.length; ++i) {
        s += nums[i];
        if (d.has(s - k)) {
            ans = Math.max(ans, i - d.get(s - k));
        }
        if (!d.has(s)) {
            d.set(s, i);
        }
    }
    return ans;
};
```

#### C#

```cs
public class Solution {
    public int MaxSubArrayLen(int[] nums, int k) {
        var d = new Dictionary<int, int>();
        d[0] = -1;
        int ans = 0;
        int s = 0;
        for (int i = 0; i < nums.Length; i++) {
            s += nums[i];
            if (d.ContainsKey(s - k)) {
                ans = Math.Max(ans, i - d[s - k]);
            }
            if (!d.ContainsKey(s)) {
                d[s] = i;
            }
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

# [326. 3 的幂](https://leetcode.cn/problems/power-of-three){#326}

{{< tabs "326" >}}

{{% tab "python" %}}
```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isPowerOfThree(n int) bool {
	return n > 0 && 1162261467%n == 0
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isPowerOfThree(n: number): boolean {
    return n > 0 && 1162261467 % n == 0;
}
```
{{% /tab %}}
{{% tab "rust" %}}
```rust
impl Solution {
    pub fn is_power_of_three(mut n: i32) -> bool {
        n > 0 && 1162261467 % n == 0
    }
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function (n) {
    return n > 0 && 1162261467 % n == 0;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个整数，写一个函数来判断它是否是 3&nbsp;的幂次方。如果是，返回 <code>true</code> ；否则，返回 <code>false</code> 。</p>

<p>整数 <code>n</code> 是 3 的幂次方需满足：存在整数 <code>x</code> 使得 <code>n == 3<sup>x</sup></code></p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 27
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 0
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 9
<strong>输出：</strong>true
</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>n = 45
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>-2<sup>31</sup> &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>进阶：</strong>你能不使用循环或者递归来完成本题吗？</p>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：试除法

如果 $n \gt 2$，我们可以不断地将 $n$ 除以 $3$，如果不能整除，说明 $n$ 不是 $3$ 的幂，否则继续除以 $3$，直到 $n$ 小于等于 $2$。如果 $n$ 等于 $1$，说明 $n$ 是 $3$ 的幂，否则不是 $3$ 的幂。

时间复杂度 $O(\log_3n)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        while n > 2:
            if n % 3:
                return False
            n //= 3
        return n == 1
```

#### Java

```java
class Solution {
    public boolean isPowerOfThree(int n) {
        while (n > 2) {
            if (n % 3 != 0) {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 2) {
            if (n % 3) {
                return false;
            }
            n /= 3;
        }
        return n == 1;
    }
};
```

#### Go

```go
func isPowerOfThree(n int) bool {
	for n > 2 {
		if n%3 != 0 {
			return false
		}
		n /= 3
	}
	return n == 1
}
```

#### TypeScript

```ts
function isPowerOfThree(n: number): boolean {
    while (n > 2) {
        if (n % 3 !== 0) {
            return false;
        }
        n = Math.floor(n / 3);
    }
    return n === 1;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_power_of_three(mut n: i32) -> bool {
        while n > 2 {
            if n % 3 != 0 {
                return false;
            }
            n /= 3;
        }
        n == 1
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function (n) {
    while (n > 2) {
        if (n % 3 !== 0) {
            return false;
        }
        n = Math.floor(n / 3);
    }
    return n === 1;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：数学

如果 $n$ 是 $3$ 的幂，那么 $n$ 最大是 $3^{19} = 1162261467$，因此我们只需要判断 $n$ 是否是 $3^{19}$ 的约数即可。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 1162261467 % n == 0
```

#### Java

```java
class Solution {
    public boolean isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};
```

#### Go

```go
func isPowerOfThree(n int) bool {
	return n > 0 && 1162261467%n == 0
}
```

#### TypeScript

```ts
function isPowerOfThree(n: number): boolean {
    return n > 0 && 1162261467 % n == 0;
}
```

#### Rust

```rust
impl Solution {
    pub fn is_power_of_three(mut n: i32) -> bool {
        n > 0 && 1162261467 % n == 0
    }
}
```

#### JavaScript

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function (n) {
    return n > 0 && 1162261467 % n == 0;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [327. 区间和的个数](https://leetcode.cn/problems/count-of-range-sum){#327}

{{< tabs "327" >}}

{{% tab "python" %}}
```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, v):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x):
        s = 0
        while x > 0:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        s = list(accumulate(nums, initial=0))
        arr = sorted(set(v for x in s for v in (x, x - lower, x - upper)))
        tree = BinaryIndexedTree(len(arr))
        ans = 0
        for x in s:
            l = bisect_left(arr, x - upper) + 1
            r = bisect_left(arr, x - lower) + 1
            ans += tree.query(r) - tree.query(l - 1)
            tree.update(bisect_left(arr, x) + 1, 1)
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x != 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long[] arr = new long[n * 3 + 3];
        for (int i = 0, j = 0; i <= n; ++i, j += 3) {
            arr[j] = s[i];
            arr[j + 1] = s[i] - lower;
            arr[j + 2] = s[i] - upper;
        }
        Arrays.sort(arr);
        int m = 0;
        for (int i = 0; i < arr.length; ++i) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                arr[m++] = arr[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        int ans = 0;
        for (long x : s) {
            int l = search(arr, m, x - upper);
            int r = search(arr, m, x - lower);
            ans += tree.query(r) - tree.query(l - 1);
            tree.update(search(arr, m, x), 1);
        }
        return ans;
    }

    private int search(long[] nums, int r, long x) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        using ll = long long;
        int n = nums.size();
        ll s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        ll arr[(n + 1) * 3];
        for (int i = 0, j = 0; i <= n; ++i, j += 3) {
            arr[j] = s[i];
            arr[j + 1] = s[i] - lower;
            arr[j + 2] = s[i] - upper;
        }
        sort(arr, arr + (n + 1) * 3);
        int m = unique(arr, arr + (n + 1) * 3) - arr;
        BinaryIndexedTree tree(m);
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int l = lower_bound(arr, arr + m, s[i] - upper) - arr + 1;
            int r = lower_bound(arr, arr + m, s[i] - lower) - arr + 1;
            ans += tree.query(r) - tree.query(l - 1);
            tree.update(lower_bound(arr, arr + m, s[i]) - arr + 1, 1);
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func countRangeSum(nums []int, lower int, upper int) (ans int) {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	arr := make([]int, (n+1)*3)
	for i, j := 0, 0; i <= n; i, j = i+1, j+3 {
		arr[j] = s[i]
		arr[j+1] = s[i] - lower
		arr[j+2] = s[i] - upper
	}
	sort.Ints(arr)
	m := 0
	for i := range arr {
		if i == 0 || arr[i] != arr[i-1] {
			arr[m] = arr[i]
			m++
		}
	}
	arr = arr[:m]
	tree := newBinaryIndexedTree(m)
	for _, x := range s {
		l := sort.SearchInts(arr, x-upper) + 1
		r := sort.SearchInts(arr, x-lower) + 1
		ans += tree.query(r) - tree.query(l-1)
		tree.update(sort.SearchInts(arr, x)+1, 1)
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number) {
        while (x <= this.n) {
            this.c[x] += v;
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function countRangeSum(nums: number[], lower: number, upper: number): number {
    const n = nums.length;
    const s = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    let arr: number[] = Array((n + 1) * 3);
    for (let i = 0, j = 0; i <= n; ++i, j += 3) {
        arr[j] = s[i];
        arr[j + 1] = s[i] - lower;
        arr[j + 2] = s[i] - upper;
    }
    arr.sort((a, b) => a - b);
    let m = 0;
    for (let i = 0; i < arr.length; ++i) {
        if (i === 0 || arr[i] !== arr[i - 1]) {
            arr[m++] = arr[i];
        }
    }
    arr = arr.slice(0, m);
    const tree = new BinaryIndexedTree(m);
    let ans = 0;
    for (const x of s) {
        const l = search(arr, m, x - upper);
        const r = search(arr, m, x - lower);
        ans += tree.query(r) - tree.query(l - 1);
        tree.update(search(arr, m, x), 1);
    }
    return ans;
}

function search(nums: number[], r: number, x: number): number {
    let l = 0;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个整数数组 <code>nums</code> 以及两个整数 <code>lower</code> 和 <code>upper</code> 。求数组中，值位于范围 <code>[lower, upper]</code> （包含 <code>lower</code> 和 <code>upper</code>）之内的 <strong>区间和的个数</strong> 。</p>

<p><strong>区间和</strong> <code>S(i, j)</code> 表示在 <code>nums</code> 中，位置从 <code>i</code> 到 <code>j</code> 的元素之和，包含 <code>i</code> 和 <code>j</code> (<code>i</code> ≤ <code>j</code>)。</p>

<p> </p>
<strong>示例 1：</strong>

<pre>
<strong>输入：</strong>nums = [-2,5,-1], lower = -2, upper = 2
<strong>输出：</strong>3
<strong>解释：</strong>存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>nums = [0], lower = 0, upper = 0
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= nums.length <= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1</code></li>
	<li><code>-10<sup>5</sup> <= lower <= upper <= 10<sup>5</sup></code></li>
	<li>题目数据保证答案是一个 <strong>32 位</strong> 的整数</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：前缀和 + 树状数组

题目要求区间和，因此我们可以先求出前缀和数组 $s$，其中 $s[i]$ 表示 $nums$ 中前 $i$ 个元素的和。那么对于任意的 $i \lt j$，$s[j+1] - s[i]$ 就是 $nums$ 中下标在 $[i, j]$ 的元素之和。

而 $lower \leq s[j+1] - s[i] \leq upper$，可以转换为 $s[j+1] - upper \leq s[i] \leq s[j+1] - lower$，也就是说，对于当前前缀和 $s[j+1]$，我们需要统计 $s$ 中有多少个下标 $i$ 满足 $s[j+1] - upper \leq s[i] \leq s[j+1] - lower$。

我们可以用树状数组来维护每个前缀和出现的次数，这样对于每个前缀和 $s[j+1]$，我们只需要查询树状数组中有多少个前缀和 $s[i]$ 满足 $s[j+1] - upper \leq s[i] \leq s[j+1] - lower$ 即可。

时间复杂度 $O(n \times \log n)$，空间复杂度 $O(n)$。其中 $n$ 为数组长度。

<!-- tabs:start -->

#### Python3

```python
class BinaryIndexedTree:
    def __init__(self, n):
        self.n = n
        self.c = [0] * (n + 1)

    def update(self, x, v):
        while x <= self.n:
            self.c[x] += v
            x += x & -x

    def query(self, x):
        s = 0
        while x > 0:
            s += self.c[x]
            x -= x & -x
        return s


class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        s = list(accumulate(nums, initial=0))
        arr = sorted(set(v for x in s for v in (x, x - lower, x - upper)))
        tree = BinaryIndexedTree(len(arr))
        ans = 0
        for x in s:
            l = bisect_left(arr, x - upper) + 1
            r = bisect_left(arr, x - lower) + 1
            ans += tree.query(r) - tree.query(l - 1)
            tree.update(bisect_left(arr, x) + 1, 1)
        return ans
```

#### Java

```java
class BinaryIndexedTree {
    private int n;
    private int[] c;

    public BinaryIndexedTree(int n) {
        this.n = n;
        this.c = new int[n + 1];
    }

    public void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    public int query(int x) {
        int s = 0;
        while (x != 0) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }
}

class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] s = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        long[] arr = new long[n * 3 + 3];
        for (int i = 0, j = 0; i <= n; ++i, j += 3) {
            arr[j] = s[i];
            arr[j + 1] = s[i] - lower;
            arr[j + 2] = s[i] - upper;
        }
        Arrays.sort(arr);
        int m = 0;
        for (int i = 0; i < arr.length; ++i) {
            if (i == 0 || arr[i] != arr[i - 1]) {
                arr[m++] = arr[i];
            }
        }
        BinaryIndexedTree tree = new BinaryIndexedTree(m);
        int ans = 0;
        for (long x : s) {
            int l = search(arr, m, x - upper);
            int r = search(arr, m, x - lower);
            ans += tree.query(r) - tree.query(l - 1);
            tree.update(search(arr, m, x), 1);
        }
        return ans;
    }

    private int search(long[] nums, int r, long x) {
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l + 1;
    }
}
```

#### C++

```cpp
class BinaryIndexedTree {
public:
    BinaryIndexedTree(int _n)
        : n(_n)
        , c(_n + 1) {}

    void update(int x, int v) {
        while (x <= n) {
            c[x] += v;
            x += x & -x;
        }
    }

    int query(int x) {
        int s = 0;
        while (x) {
            s += c[x];
            x -= x & -x;
        }
        return s;
    }

private:
    int n;
    vector<int> c;
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        using ll = long long;
        int n = nums.size();
        ll s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        ll arr[(n + 1) * 3];
        for (int i = 0, j = 0; i <= n; ++i, j += 3) {
            arr[j] = s[i];
            arr[j + 1] = s[i] - lower;
            arr[j + 2] = s[i] - upper;
        }
        sort(arr, arr + (n + 1) * 3);
        int m = unique(arr, arr + (n + 1) * 3) - arr;
        BinaryIndexedTree tree(m);
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int l = lower_bound(arr, arr + m, s[i] - upper) - arr + 1;
            int r = lower_bound(arr, arr + m, s[i] - lower) - arr + 1;
            ans += tree.query(r) - tree.query(l - 1);
            tree.update(lower_bound(arr, arr + m, s[i]) - arr + 1, 1);
        }
        return ans;
    }
};
```

#### Go

```go
type BinaryIndexedTree struct {
	n int
	c []int
}

func newBinaryIndexedTree(n int) *BinaryIndexedTree {
	c := make([]int, n+1)
	return &BinaryIndexedTree{n, c}
}

func (this *BinaryIndexedTree) update(x, delta int) {
	for x <= this.n {
		this.c[x] += delta
		x += x & -x
	}
}

func (this *BinaryIndexedTree) query(x int) int {
	s := 0
	for x > 0 {
		s += this.c[x]
		x -= x & -x
	}
	return s
}

func countRangeSum(nums []int, lower int, upper int) (ans int) {
	n := len(nums)
	s := make([]int, n+1)
	for i, x := range nums {
		s[i+1] = s[i] + x
	}
	arr := make([]int, (n+1)*3)
	for i, j := 0, 0; i <= n; i, j = i+1, j+3 {
		arr[j] = s[i]
		arr[j+1] = s[i] - lower
		arr[j+2] = s[i] - upper
	}
	sort.Ints(arr)
	m := 0
	for i := range arr {
		if i == 0 || arr[i] != arr[i-1] {
			arr[m] = arr[i]
			m++
		}
	}
	arr = arr[:m]
	tree := newBinaryIndexedTree(m)
	for _, x := range s {
		l := sort.SearchInts(arr, x-upper) + 1
		r := sort.SearchInts(arr, x-lower) + 1
		ans += tree.query(r) - tree.query(l-1)
		tree.update(sort.SearchInts(arr, x)+1, 1)
	}
	return
}
```

#### TypeScript

```ts
class BinaryIndexedTree {
    private n: number;
    private c: number[];

    constructor(n: number) {
        this.n = n;
        this.c = Array(n + 1).fill(0);
    }

    update(x: number, v: number) {
        while (x <= this.n) {
            this.c[x] += v;
            x += x & -x;
        }
    }

    query(x: number): number {
        let s = 0;
        while (x > 0) {
            s += this.c[x];
            x -= x & -x;
        }
        return s;
    }
}

function countRangeSum(nums: number[], lower: number, upper: number): number {
    const n = nums.length;
    const s = Array(n + 1).fill(0);
    for (let i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nums[i];
    }
    let arr: number[] = Array((n + 1) * 3);
    for (let i = 0, j = 0; i <= n; ++i, j += 3) {
        arr[j] = s[i];
        arr[j + 1] = s[i] - lower;
        arr[j + 2] = s[i] - upper;
    }
    arr.sort((a, b) => a - b);
    let m = 0;
    for (let i = 0; i < arr.length; ++i) {
        if (i === 0 || arr[i] !== arr[i - 1]) {
            arr[m++] = arr[i];
        }
    }
    arr = arr.slice(0, m);
    const tree = new BinaryIndexedTree(m);
    let ans = 0;
    for (const x of s) {
        const l = search(arr, m, x - upper);
        const r = search(arr, m, x - lower);
        ans += tree.query(r) - tree.query(l - 1);
        tree.update(search(arr, m, x), 1);
    }
    return ans;
}

function search(nums: number[], r: number, x: number): number {
    let l = 0;
    while (l < r) {
        const mid = (l + r) >> 1;
        if (nums[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l + 1;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [328. 奇偶链表](https://leetcode.cn/problems/odd-even-linked-list){#328}

{{< tabs "328" >}}

{{% tab "python" %}}
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        a = head
        b = c = head.next
        while b and b.next:
            a.next = b.next
            a = a.next
            b.next = a.next
            b = b.next
        a.next = c
        return head
```
{{% /tab %}}
{{% tab "java" %}}
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode a = head;
        ListNode b = head.next, c = b;
        while (b != null && b.next != null) {
            a.next = b.next;
            a = a.next;
            b.next = a.next;
            b = b.next;
        }
        a.next = c;
        return head;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* a = head;
        ListNode *b = head->next, *c = b;
        while (b && b->next) {
            a->next = b->next;
            a = a->next;
            b->next = a->next;
            b = b->next;
        }
        a->next = c;
        return head;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	a := head
	b, c := head.Next, head.Next
	for b != nil && b.Next != nil {
		a.Next = b.Next
		a = a.Next
		b.Next = a.Next
		b = b.Next
	}
	a.Next = c
	return head
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function oddEvenList(head: ListNode | null): ListNode | null {
    if (!head) {
        return null;
    }
    let [a, b, c] = [head, head.next, head.next];
    while (b && b.next) {
        a.next = b.next;
        a = a.next;
        b.next = a.next;
        b = b.next;
    }
    a.next = c;
    return head;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定单链表的头节点&nbsp;<code>head</code>&nbsp;，将所有索引为奇数的节点和索引为偶数的节点分别分组，保持它们原有的相对顺序，然后把偶数索引节点分组连接到奇数索引节点分组之后，返回重新排序的链表。</p>

<p><strong>第一个</strong>节点的索引被认为是 <strong>奇数</strong> ， <strong>第二个</strong>节点的索引为&nbsp;<strong>偶数</strong> ，以此类推。</p>

<p>请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。</p>

<p>你必须在&nbsp;<code>O(1)</code>&nbsp;的额外空间复杂度和&nbsp;<code>O(n)</code>&nbsp;的时间复杂度下解决这个问题。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0328.Odd%20Even%20Linked%20List/images/oddeven-linked-list.jpg" style="height: 123px; width: 300px;" /></p>

<pre>
<strong>输入: </strong>head = [1,2,3,4,5]
<strong>输出:</strong>&nbsp;[1,3,5,2,4]</pre>

<p><strong>示例 2:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0328.Odd%20Even%20Linked%20List/images/oddeven2-linked-list.jpg" style="height: 142px; width: 500px;" /></p>

<pre>
<strong>输入:</strong> head = [2,1,3,5,6,4,7]
<strong>输出:</strong> [2,3,6,7,1,5,4]</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>n ==&nbsp;</code> 链表中的节点数</li>
	<li><code>0 &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>6</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>6</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：一次遍历

我们可以用两个指针 $a$ 和 $b$ 分别表示奇数节点和偶数节点的尾节点。初始时，指针 $a$ 指向链表的头节点 $head$，指针 $b$ 指向链表的第二个节点 $head.next$。另外，我们用一个指针 $c$ 指向偶数节点的头节点 $head.next$，即指针 $b$ 的初始位置。

遍历链表，我们将指针 $a$ 指向 $b$ 的下一个节点，即 $a.next = b.next$，然后将指针 $a$ 向后移动一位，即 $a = a.next$；将指针 $b$ 指向 $a$ 的下一个节点，即 $b.next = a.next$，然后将指针 $b$ 向后移动一位，即 $b = b.next$。继续遍历，直到 $b$ 到达链表的末尾。

最后，我们将奇数节点的尾节点 $a$ 指向偶数节点的头节点 $c$，即 $a.next = c$，然后返回链表的头节点 $head$ 即可。

时间复杂度 $O(n)$，其中 $n$ 是链表的长度，需要遍历链表一次。空间复杂度 $O(1)$。只需要维护有限的指针。

<!-- tabs:start -->

#### Python3

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        a = head
        b = c = head.next
        while b and b.next:
            a.next = b.next
            a = a.next
            b.next = a.next
            b = b.next
        a.next = c
        return head
```

#### Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode a = head;
        ListNode b = head.next, c = b;
        while (b != null && b.next != null) {
            a.next = b.next;
            a = a.next;
            b.next = a.next;
            b = b.next;
        }
        a.next = c;
        return head;
    }
}
```

#### C++

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* a = head;
        ListNode *b = head->next, *c = b;
        while (b && b->next) {
            a->next = b->next;
            a = a->next;
            b->next = a->next;
            b = b->next;
        }
        a->next = c;
        return head;
    }
};
```

#### Go

```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	a := head
	b, c := head.Next, head.Next
	for b != nil && b.Next != nil {
		a.Next = b.Next
		a = a.Next
		b.Next = a.Next
		b = b.Next
	}
	a.Next = c
	return head
}
```

#### TypeScript

```ts
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function oddEvenList(head: ListNode | null): ListNode | null {
    if (!head) {
        return null;
    }
    let [a, b, c] = [head, head.next, head.next];
    while (b && b.next) {
        a.next = b.next;
        a = a.next;
        b.next = a.next;
        b = b.next;
    }
    a.next = c;
    return head;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [329. 矩阵中的最长递增路径](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix){#329}

{{< tabs "329" >}}

{{% tab "python" %}}
```python
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            ans = 0
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and matrix[x][y] > matrix[i][j]:
                    ans = max(ans, dfs(x, y))
            return ans + 1

        m, n = len(matrix), len(matrix[0])
        return max(dfs(i, j) for i in range(m) for j in range(n))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int m;
    private int n;
    private int[][] matrix;
    private int[][] f;

    public int longestIncreasingPath(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;
        f = new int[m][n];
        this.matrix = matrix;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (f[i][j] != 0) {
            return f[i][j];
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                f[i][j] = Math.max(f[i][j], dfs(x, y));
            }
        }
        return ++f[i][j];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int f[m][n];
        memset(f, 0, sizeof(f));
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (f[i][j]) {
                return f[i][j];
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    f[i][j] = max(f[i][j], dfs(x, y));
                }
            }
            return ++f[i][j];
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func longestIncreasingPath(matrix [][]int) (ans int) {
	m, n := len(matrix), len(matrix[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if f[i][j] != 0 {
			return f[i][j]
		}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if 0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j] {
				f[i][j] = max(f[i][j], dfs(x, y))
			}
		}
		f[i][j]++
		return f[i][j]
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans = max(ans, dfs(i, j))
		}
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function longestIncreasingPath(matrix: number[][]): number {
    const m = matrix.length;
    const n = matrix[0].length;
    const f: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        if (f[i][j] > 0) {
            return f[i][j];
        }
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                f[i][j] = Math.max(f[i][j], dfs(x, y));
            }
        }
        return ++f[i][j];
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans = Math.max(ans, dfs(i, j));
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

<p>给定一个 <code>m x n</code> 整数矩阵 <code>matrix</code> ，找出其中 <strong>最长递增路径</strong> 的长度。</p>

<p>对于每个单元格，你可以往上，下，左，右四个方向移动。 你 <strong>不能</strong> 在 <strong>对角线</strong> 方向上移动或移动到 <strong>边界外</strong>（即不允许环绕）。</p>

<p> </p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0329.Longest%20Increasing%20Path%20in%20a%20Matrix/images/grid1.jpg" style="width: 242px; height: 242px;" />
<pre>
<strong>输入：</strong>matrix = [[9,9,4],[6,6,8],[2,1,1]]
<strong>输出：</strong>4 
<strong>解释：</strong>最长递增路径为 <code>[1, 2, 6, 9]</code>。</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0300-0399/0329.Longest%20Increasing%20Path%20in%20a%20Matrix/images/tmp-grid.jpg" style="width: 253px; height: 253px;" />
<pre>
<strong>输入：</strong>matrix = [[3,4,5],[3,2,6],[2,2,1]]
<strong>输出：</strong>4 
<strong>解释：</strong>最长递增路径是 <code>[3, 4, 5, 6]</code>。注意不允许在对角线方向上移动。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>matrix = [[1]]
<strong>输出：</strong>1
</pre>

<p> </p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 <= m, n <= 200</code></li>
	<li><code>0 <= matrix[i][j] <= 2<sup>31</sup> - 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i, j)$，它表示从矩阵中的坐标 $(i, j)$ 出发，可以得到的最长递增路径的长度。那么答案就是 $\max_{i, j} \textit{dfs}(i, j)$。

函数 $dfs(i, j)$ 的执行逻辑如下：

-   如果 $(i, j)$ 已经被访问过，直接返回 $\textit{f}(i, j)$；
-   否则对 $(i, j)$ 进行搜索，搜索四个方向的坐标 $(x, y)$，如果满足 $0 \le x < m, 0 \le y < n$ 以及 $matrix[x][y] \gt matrix[i][j]$，那么对 $(x, y)$ 进行搜索。搜索结束后，将 $\textit{f}(i, j)$ 更新为 $\textit{f}(i, j) = \max(\textit{f}(i, j), \textit{f}(x, y) + 1)$。最后返回 $\textit{f}(i, j)$。

时间复杂度 $O(m \times n)$，空间复杂度 $O(m \times n)$。其中 $m$ 和 $n$ 分别是矩阵的行数和列数。

相似题目：

-   [2328. 网格图中递增路径的数目](https://github.com/doocs/leetcode/blob/main/solution/2300-2399/2328.Number%20of%20Increasing%20Paths%20in%20a%20Grid/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        @cache
        def dfs(i: int, j: int) -> int:
            ans = 0
            for a, b in pairwise((-1, 0, 1, 0, -1)):
                x, y = i + a, j + b
                if 0 <= x < m and 0 <= y < n and matrix[x][y] > matrix[i][j]:
                    ans = max(ans, dfs(x, y))
            return ans + 1

        m, n = len(matrix), len(matrix[0])
        return max(dfs(i, j) for i in range(m) for j in range(n))
```

#### Java

```java
class Solution {
    private int m;
    private int n;
    private int[][] matrix;
    private int[][] f;

    public int longestIncreasingPath(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;
        f = new int[m][n];
        this.matrix = matrix;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = Math.max(ans, dfs(i, j));
            }
        }
        return ans;
    }

    private int dfs(int i, int j) {
        if (f[i][j] != 0) {
            return f[i][j];
        }
        int[] dirs = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                f[i][j] = Math.max(f[i][j], dfs(x, y));
            }
        }
        return ++f[i][j];
    }
}
```

#### C++

```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int f[m][n];
        memset(f, 0, sizeof(f));
        int ans = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (f[i][j]) {
                return f[i][j];
            }
            for (int k = 0; k < 4; ++k) {
                int x = i + dirs[k], y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                    f[i][j] = max(f[i][j], dfs(x, y));
                }
            }
            return ++f[i][j];
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};
```

#### Go

```go
func longestIncreasingPath(matrix [][]int) (ans int) {
	m, n := len(matrix), len(matrix[0])
	f := make([][]int, m)
	for i := range f {
		f[i] = make([]int, n)
	}
	dirs := [5]int{-1, 0, 1, 0, -1}
	var dfs func(i, j int) int
	dfs = func(i, j int) int {
		if f[i][j] != 0 {
			return f[i][j]
		}
		for k := 0; k < 4; k++ {
			x, y := i+dirs[k], j+dirs[k+1]
			if 0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j] {
				f[i][j] = max(f[i][j], dfs(x, y))
			}
		}
		f[i][j]++
		return f[i][j]
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ans = max(ans, dfs(i, j))
		}
	}
	return
}
```

#### TypeScript

```ts
function longestIncreasingPath(matrix: number[][]): number {
    const m = matrix.length;
    const n = matrix[0].length;
    const f: number[][] = Array(m)
        .fill(0)
        .map(() => Array(n).fill(0));
    const dirs = [-1, 0, 1, 0, -1];
    const dfs = (i: number, j: number): number => {
        if (f[i][j] > 0) {
            return f[i][j];
        }
        for (let k = 0; k < 4; ++k) {
            const x = i + dirs[k];
            const y = j + dirs[k + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                f[i][j] = Math.max(f[i][j], dfs(x, y));
            }
        }
        return ++f[i][j];
    };
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            ans = Math.max(ans, dfs(i, j));
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
