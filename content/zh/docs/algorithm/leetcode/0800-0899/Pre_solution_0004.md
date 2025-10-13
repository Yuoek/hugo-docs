---
title: "0830_较大分组的位置"
date: 2025-10-08T18:36:34+08:00
weight: 4
tags: [位运算, 几何, 动态规划, 双指针, 哈希表, 图, 字符串, 并查集, 广度优先搜索, 排序, 数学, 数组, 树, 概率与统计, 模拟, 深度优先搜索, 滑动窗口, 矩阵]
---

{{< markmap >}}
### [0830_较大分组的位置](#830)
#### [字符串](#830)
### [0831_隐藏个人信息](#831)
#### [字符串](#831)
### [0832_翻转图像](#832)
#### [位运算](#832)
#### [数组](#832)
#### [双指针](#832)
#### [矩阵](#832)
#### [模拟](#832)
### [0833_字符串中的查找与替换](#833)
#### [数组](#833)
#### [哈希表](#833)
#### [字符串](#833)
#### [排序](#833)
### [0834_树中距离之和](#834)
#### [树](#834)
#### [深度优先搜索](#834)
#### [图](#834)
#### [动态规划](#834)
### [0835_图像重叠](#835)
#### [数组](#835)
#### [矩阵](#835)
### [0836_矩形重叠](#836)
#### [几何](#836)
#### [数学](#836)
### [0837_新 21 点](#837)
#### [数学](#837)
#### [动态规划](#837)
#### [滑动窗口](#837)
#### [概率与统计](#837)
### [0838_推多米诺](#838)
#### [双指针](#838)
#### [字符串](#838)
#### [动态规划](#838)
### [0839_相似字符串组](#839)
#### [深度优先搜索](#839)
#### [广度优先搜索](#839)
#### [并查集](#839)
#### [数组](#839)
#### [哈希表](#839)
#### [字符串](#839)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 0830_较大分组的位置
___
#### 字符串
---
### 0831_隐藏个人信息
___
#### 字符串
---
### 0832_翻转图像
___
#### 位运算
___
#### 数组
___
#### 双指针
___
#### 矩阵
___
#### 模拟
---
### 0833_字符串中的查找与替换
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 排序
---
### 0834_树中距离之和
___
#### 树
___
#### 深度优先搜索
___
#### 图
___
#### 动态规划
---
### 0835_图像重叠
___
#### 数组
___
#### 矩阵
---
### 0836_矩形重叠
___
#### 几何
___
#### 数学
---
### 0837_新 21 点
___
#### 数学
___
#### 动态规划
___
#### 滑动窗口
___
#### 概率与统计
---
### 0838_推多米诺
___
#### 双指针
___
#### 字符串
___
#### 动态规划
---
### 0839_相似字符串组
___
#### 深度优先搜索
___
#### 广度优先搜索
___
#### 并查集
___
#### 数组
___
#### 哈希表
___
#### 字符串
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 位运算 | 几何 | 动态规划 |
| 双指针 | 哈希表 | 图 |
| 字符串 | 并查集 | 广度优先搜索 |
| 排序 | 数学 | 数组 |
| 树 | 概率与统计 | 模拟 |
| 深度优先搜索 | 滑动窗口 | 矩阵 |

# [830. 较大分组的位置](https://leetcode.cn/problems/positions-of-large-groups){#830}

{{< tabs "830" >}}

{{% tab "python" %}}
```python
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        i, n = 0, len(s)
        ans = []
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            if j - i >= 3:
                ans.append([i, j - 1])
            i = j
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        int n = s.length();
        int i = 0;
        List<List<Integer>> ans = new ArrayList<>();
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            if (j - i >= 3) {
                ans.add(List.of(i, j - 1));
            }
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
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func largeGroupPositions(s string) [][]int {
	i, n := 0, len(s)
	ans := [][]int{}
	for i < n {
		j := i
		for j < n && s[j] == s[i] {
			j++
		}
		if j-i >= 3 {
			ans = append(ans, []int{i, j - 1})
		}
		i = j
	}
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function largeGroupPositions(s: string): number[][] {
    const n = s.length;
    const ans: number[][] = [];

    for (let i = 0; i < n; ) {
        let j = i;
        while (j < n && s[j] === s[i]) {
            ++j;
        }
        if (j - i >= 3) {
            ans.push([i, j - 1]);
        }
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

<p>在一个由小写字母构成的字符串 <code>s</code> 中，包含由一些连续的相同字符所构成的分组。</p>

<p>例如，在字符串 <code>s = "abbxxxxzyy"</code> 中，就含有 <code>"a"</code>, <code>"bb"</code>, <code>"xxxx"</code>, <code>"z"</code> 和 <code>"yy"</code> 这样的一些分组。</p>

<p>分组可以用区间 <code>[start, end]</code> 表示，其中 <code>start</code> 和 <code>end</code> 分别表示该分组的起始和终止位置的下标。上例中的 <code>"xxxx"</code> 分组用区间表示为 <code>[3,6]</code> 。</p>

<p>我们称所有包含大于或等于三个连续字符的分组为 <strong>较大分组</strong> 。</p>

<p>找到每一个 <strong>较大分组</strong> 的区间，<strong>按起始位置下标递增顺序排序后</strong>，返回结果。</p>

<p> </p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "abbxxxxzzy"
<strong>输出：</strong>[[3,6]]
<strong>解释</strong><strong>：</strong><code>"xxxx" 是一个起始于 3 且终止于 6 的较大分组</code>。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abc"
<strong>输出：</strong>[]
<strong>解释：</strong>"a","b" 和 "c" 均不是符合要求的较大分组。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "abcdddeeeeaabbbcd"
<strong>输出：</strong>[[3,5],[6,9],[12,14]]
<strong>解释：</strong>较大分组为 "ddd", "eeee" 和 "bbb"</pre>

<p><strong>示例 4：</strong></p>

<pre>
<strong>输入：</strong>s = "aba"
<strong>输出：</strong>[]
</pre>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 <= s.length <= 1000</code></li>
	<li><code>s</code> 仅含小写英文字母</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们用双指针 $i$ 和 $j$ 找到每个分组的起始位置和终止位置，然后判断分组长度是否大于等于 $3$，若是则将其加入结果数组。

时间复杂度 $O(n)$，其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        i, n = 0, len(s)
        ans = []
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            if j - i >= 3:
                ans.append([i, j - 1])
            i = j
        return ans
```

#### Java

```java
class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        int n = s.length();
        int i = 0;
        List<List<Integer>> ans = new ArrayList<>();
        while (i < n) {
            int j = i;
            while (j < n && s.charAt(j) == s.charAt(i)) {
                ++j;
            }
            if (j - i >= 3) {
                ans.add(List.of(i, j - 1));
            }
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
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();
        int i = 0;
        vector<vector<int>> ans;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j;
        }
        return ans;
    }
};
```

#### Go

```go
func largeGroupPositions(s string) [][]int {
	i, n := 0, len(s)
	ans := [][]int{}
	for i < n {
		j := i
		for j < n && s[j] == s[i] {
			j++
		}
		if j-i >= 3 {
			ans = append(ans, []int{i, j - 1})
		}
		i = j
	}
	return ans
}
```

#### TypeScript

```ts
function largeGroupPositions(s: string): number[][] {
    const n = s.length;
    const ans: number[][] = [];

    for (let i = 0; i < n; ) {
        let j = i;
        while (j < n && s[j] === s[i]) {
            ++j;
        }
        if (j - i >= 3) {
            ans.push([i, j - 1]);
        }
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

# [831. 隐藏个人信息](https://leetcode.cn/problems/masking-personal-information){#831}

{{< tabs "831" >}}

{{% tab "python" %}}
```python
class Solution:
    def maskPII(self, s: str) -> str:
        if s[0].isalpha():
            s = s.lower()
            return s[0] + '*****' + s[s.find('@') - 1 :]
        s = ''.join(c for c in s if c.isdigit())
        cnt = len(s) - 10
        suf = '***-***-' + s[-4:]
        return suf if cnt == 0 else f'+{"*" * cnt}-{suf}'
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String maskPII(String s) {
        if (Character.isLetter(s.charAt(0))) {
            s = s.toLowerCase();
            int i = s.indexOf('@');
            return s.substring(0, 1) + "*****" + s.substring(i - 1);
        }
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                sb.append(c);
            }
        }
        s = sb.toString();
        int cnt = s.length() - 10;
        String suf = "***-***-" + s.substring(s.length() - 4);
        return cnt == 0 ? suf
                        : "+"
                + "*".repeat(cnt) + "-" + suf;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string maskPII(string s) {
        int i = s.find('@');
        if (i != -1) {
            string ans;
            ans += tolower(s[0]);
            ans += "*****";
            for (int j = i - 1; j < s.size(); ++j) {
                ans += tolower(s[j]);
            }
            return ans;
        }
        string t;
        for (char c : s) {
            if (isdigit(c)) {
                t += c;
            }
        }
        int cnt = t.size() - 10;
        string suf = "***-***-" + t.substr(t.size() - 4);
        return cnt == 0 ? suf : "+" + string(cnt, '*') + "-" + suf;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maskPII(s string) string {
	i := strings.Index(s, "@")
	if i != -1 {
		s = strings.ToLower(s)
		return s[0:1] + "*****" + s[i-1:]
	}
	t := []rune{}
	for _, c := range s {
		if c >= '0' && c <= '9' {
			t = append(t, c)
		}
	}
	s = string(t)
	cnt := len(s) - 10
	suf := "***-***-" + s[len(s)-4:]
	if cnt == 0 {
		return suf
	}
	return "+" + strings.Repeat("*", cnt) + "-" + suf
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maskPII(s: string): string {
    const i = s.indexOf('@');
    if (i !== -1) {
        let ans = s[0].toLowerCase() + '*****';
        for (let j = i - 1; j < s.length; ++j) {
            ans += s.charAt(j).toLowerCase();
        }
        return ans;
    }
    let t = '';
    for (const c of s) {
        if (/\d/.test(c)) {
            t += c;
        }
    }
    const cnt = t.length - 10;
    const suf = `***-***-${t.substring(t.length - 4)}`;
    return cnt === 0 ? suf : `+${'*'.repeat(cnt)}-${suf}`;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一条个人信息字符串 <code>s</code> ，可能表示一个 <strong>邮箱地址</strong> ，也可能表示一串 <strong>电话号码</strong> 。返回按如下规则 <strong>隐藏</strong> 个人信息后的结果：</p>

<p><em><strong>电子邮件地址：</strong></em></p>

<p>一个电子邮件地址由以下部分组成：</p>

<ul>
	<li>一个 <strong>名字</strong> ，由大小写英文字母组成，后面跟着</li>
	<li>一个 <code>'@'</code> 字符，后面跟着</li>
	<li>一个 <strong>域名</strong> ，由大小写英文字母和一个位于中间的 <code>'.'</code> 字符组成。<code>'.'</code> 不会是域名的第一个或者最后一个字符。</li>
</ul>

<p>要想隐藏电子邮件地址中的个人信息：</p>

<ul>
	<li><strong>名字</strong> 和 <strong>域名</strong> 部分的大写英文字母应当转换成小写英文字母。</li>
	<li><strong>名字</strong> 中间的字母（即，除第一个和最后一个字母外）必须用 5 个 <code>"*****"</code> 替换。</li>
</ul>

<p><em><strong>电话号码：</strong></em></p>

<p>一个电话号码应当按下述格式组成：</p>

<ul>
	<li>电话号码可以由 10-13 位数字组成</li>
	<li>后 10 位构成 <strong>本地号码</strong></li>
	<li>前面剩下的 0-3 位，构成 <strong>国家代码</strong></li>
	<li>利用 <code>{'+', '-', '(', ')', ' '}</code> 这些 <strong>分隔字符</strong> 按某种形式对上述数字进行分隔</li>
</ul>

<p>要想隐藏电话号码中的个人信息：</p>

<ul>
	<li>移除所有 <strong>分隔字符</strong></li>
	<li>隐藏个人信息后的电话号码应该遵从这种格式：
	<ul>
		<li><code>"***-***-XXXX"</code> 如果国家代码为 0 位数字</li>
		<li><code>"+*-***-***-XXXX"</code> 如果国家代码为 1 位数字</li>
		<li><code>"+**-***-***-XXXX"</code> 如果国家代码为 2 位数字</li>
		<li><code>"+***-***-***-XXXX"</code> 如果国家代码为 3 位数字</li>
	</ul>
	</li>
	<li><code>"XXXX"</code> 是最后 4 位 <strong>本地号码</strong></li>
</ul>
&nbsp;

<div class="top-view__1vxA">
<div class="original__bRMd">
<div>
<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>s = "LeetCode@LeetCode.com"
<strong>输出：</strong>"l*****e@leetcode.com"
<strong>解释：</strong>s 是一个电子邮件地址。
名字和域名都转换为小写，名字的中间用 5 个 * 替换。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "AB@qq.com"
<strong>输出：</strong>"a*****b@qq.com"
<strong>解释：</strong>s 是一个电子邮件地址。
名字和域名都转换为小写，名字的中间用 5 个 * 替换。
注意，尽管 "ab" 只有两个字符，但中间仍然必须有 5 个 * 。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>s = "1(234)567-890"
<strong>输出：</strong>"***-***-7890"
<strong>解释：</strong>s 是一个电话号码。
共计 10 位数字，所以本地号码为 10 位数字，国家代码为 0 位数字。
因此，隐藏后的电话号码应该是 "***-***-7890" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s</code> 是一个 <strong>有效</strong> 的电子邮件或者电话号码</li>
	<li>如果 <code>s</code> 是一个电子邮件：
	<ul>
		<li><code>8 &lt;= s.length &lt;= 40</code></li>
		<li><code>s</code> 是由大小写英文字母，恰好一个 <code>'@'</code> 字符，以及 <code>'.'</code> 字符组成</li>
	</ul>
	</li>
	<li>如果 <code>s</code> 是一个电话号码：
	<ul>
		<li><code>10 &lt;= s.length &lt;= 20</code></li>
		<li><code>s</code> 是由数字、空格、字符 <code>'('</code>、<code>')'</code>、<code>'-'</code> 和 <code>'+'</code> 组成</li>
	</ul>
	</li>
</ul>
</div>
</div>
</div>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

根据题目描述，我们可以先判断字符串 $s$ 是电子邮件还是电话号码，然后分别处理。

时间复杂度为 $O(n)$，空间复杂度为 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maskPII(self, s: str) -> str:
        if s[0].isalpha():
            s = s.lower()
            return s[0] + '*****' + s[s.find('@') - 1 :]
        s = ''.join(c for c in s if c.isdigit())
        cnt = len(s) - 10
        suf = '***-***-' + s[-4:]
        return suf if cnt == 0 else f'+{"*" * cnt}-{suf}'
```

#### Java

```java
class Solution {
    public String maskPII(String s) {
        if (Character.isLetter(s.charAt(0))) {
            s = s.toLowerCase();
            int i = s.indexOf('@');
            return s.substring(0, 1) + "*****" + s.substring(i - 1);
        }
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                sb.append(c);
            }
        }
        s = sb.toString();
        int cnt = s.length() - 10;
        String suf = "***-***-" + s.substring(s.length() - 4);
        return cnt == 0 ? suf
                        : "+"
                + "*".repeat(cnt) + "-" + suf;
    }
}
```

#### C++

```cpp
class Solution {
public:
    string maskPII(string s) {
        int i = s.find('@');
        if (i != -1) {
            string ans;
            ans += tolower(s[0]);
            ans += "*****";
            for (int j = i - 1; j < s.size(); ++j) {
                ans += tolower(s[j]);
            }
            return ans;
        }
        string t;
        for (char c : s) {
            if (isdigit(c)) {
                t += c;
            }
        }
        int cnt = t.size() - 10;
        string suf = "***-***-" + t.substr(t.size() - 4);
        return cnt == 0 ? suf : "+" + string(cnt, '*') + "-" + suf;
    }
};
```

#### Go

```go
func maskPII(s string) string {
	i := strings.Index(s, "@")
	if i != -1 {
		s = strings.ToLower(s)
		return s[0:1] + "*****" + s[i-1:]
	}
	t := []rune{}
	for _, c := range s {
		if c >= '0' && c <= '9' {
			t = append(t, c)
		}
	}
	s = string(t)
	cnt := len(s) - 10
	suf := "***-***-" + s[len(s)-4:]
	if cnt == 0 {
		return suf
	}
	return "+" + strings.Repeat("*", cnt) + "-" + suf
}
```

#### TypeScript

```ts
function maskPII(s: string): string {
    const i = s.indexOf('@');
    if (i !== -1) {
        let ans = s[0].toLowerCase() + '*****';
        for (let j = i - 1; j < s.length; ++j) {
            ans += s.charAt(j).toLowerCase();
        }
        return ans;
    }
    let t = '';
    for (const c of s) {
        if (/\d/.test(c)) {
            t += c;
        }
    }
    const cnt = t.length - 10;
    const suf = `***-***-${t.substring(t.length - 4)}`;
    return cnt === 0 ? suf : `+${'*'.repeat(cnt)}-${suf}`;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [832. 翻转图像](https://leetcode.cn/problems/flipping-an-image){#832}

{{< tabs "832" >}}

{{% tab "python" %}}
```python
class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        n = len(image)
        for row in image:
            i, j = 0, n - 1
            while i < j:
                if row[i] == row[j]:
                    row[i] ^= 1
                    row[j] ^= 1
                i, j = i + 1, j - 1
            if i == j:
                row[i] ^= 1
        return image
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        for (var row : image) {
            int i = 0, j = row.length - 1;
            for (; i < j; ++i, --j) {
                if (row[i] == row[j]) {
                    row[i] ^= 1;
                    row[j] ^= 1;
                }
            }
            if (i == j) {
                row[i] ^= 1;
            }
        }
        return image;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int i = 0, j = row.size() - 1;
            for (; i < j; ++i, --j) {
                if (row[i] == row[j]) {
                    row[i] ^= 1;
                    row[j] ^= 1;
                }
            }
            if (i == j) {
                row[i] ^= 1;
            }
        }
        return image;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func flipAndInvertImage(image [][]int) [][]int {
	for _, row := range image {
		i, j := 0, len(row)-1
		for ; i < j; i, j = i+1, j-1 {
			if row[i] == row[j] {
				row[i] ^= 1
				row[j] ^= 1
			}
		}
		if i == j {
			row[i] ^= 1
		}
	}
	return image
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {number[][]} image
 * @return {number[][]}
 */
var flipAndInvertImage = function (image) {
    for (const row of image) {
        let i = 0;
        let j = row.length - 1;
        for (; i < j; ++i, --j) {
            if (row[i] == row[j]) {
                row[i] ^= 1;
                row[j] ^= 1;
            }
        }
        if (i == j) {
            row[i] ^= 1;
        }
    }
    return image;
};
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个<meta charset="UTF-8" />&nbsp;<code>n x n</code>&nbsp;的二进制矩阵&nbsp;<code>image</code>&nbsp;，先 <strong>水平</strong> 翻转图像，然后&nbsp;<strong>反转&nbsp;</strong>图像并返回&nbsp;<em>结果</em>&nbsp;。</p>

<p><strong>水平</strong>翻转图片就是将图片的每一行都进行翻转，即逆序。</p>

<ul>
	<li>例如，水平翻转&nbsp;<code>[1,1,0]</code>&nbsp;的结果是&nbsp;<code>[0,1,1]</code>。</li>
</ul>

<p><strong>反转</strong>图片的意思是图片中的&nbsp;<code>0</code>&nbsp;全部被&nbsp;<code>1</code>&nbsp;替换，&nbsp;<code>1</code>&nbsp;全部被&nbsp;<code>0</code>&nbsp;替换。</p>

<ul>
	<li>例如，反转&nbsp;<code>[0,1,1]</code>&nbsp;的结果是&nbsp;<code>[1,0,0]</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>image = [[1,1,0],[1,0,1],[0,0,0]]
<strong>输出：</strong>[[1,0,0],[0,1,0],[1,1,1]]
<strong>解释：</strong>首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
     然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
<strong>输出：</strong>[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
<strong>解释：</strong>首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
     然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<p><meta charset="UTF-8" /></p>

<ul>
	<li><code>n == image.length</code></li>
	<li><code>n == image[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 20</code></li>
	<li><code>images[i][j]</code>&nbsp;==&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>.</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：双指针

我们可以遍历矩阵，对于遍历到的每一行 $\textit{row}$，我们使用双指针 $i$ 和 $j$ 分别指向该行的首尾元素，如果 $\textit{row}[i] = \textit{row}[j]$，交换后两者的值仍然保持不变，因此，我们只需要对 $\textit{row}[i]$ 和 $\textit{row}[j]$ 进行异或反转即可，然后将 $i$ 和 $j$ 分别向中间移动一位，直到 $i \geq j$。如果 $\textit{row}[i] \neq \textit{row}[j]$，此时交换后再反转两者的值，仍然保持不变，因此，可以不进行任何操作。

最后，如果 $i = j$，我们直接对 $\textit{row}[i]$ 进行反转即可。

时间复杂度 $O(n^2)$，其中 $n$ 是矩阵的行数或列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        n = len(image)
        for row in image:
            i, j = 0, n - 1
            while i < j:
                if row[i] == row[j]:
                    row[i] ^= 1
                    row[j] ^= 1
                i, j = i + 1, j - 1
            if i == j:
                row[i] ^= 1
        return image
```

#### Java

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        for (var row : image) {
            int i = 0, j = row.length - 1;
            for (; i < j; ++i, --j) {
                if (row[i] == row[j]) {
                    row[i] ^= 1;
                    row[j] ^= 1;
                }
            }
            if (i == j) {
                row[i] ^= 1;
            }
        }
        return image;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int i = 0, j = row.size() - 1;
            for (; i < j; ++i, --j) {
                if (row[i] == row[j]) {
                    row[i] ^= 1;
                    row[j] ^= 1;
                }
            }
            if (i == j) {
                row[i] ^= 1;
            }
        }
        return image;
    }
};
```

#### Go

```go
func flipAndInvertImage(image [][]int) [][]int {
	for _, row := range image {
		i, j := 0, len(row)-1
		for ; i < j; i, j = i+1, j-1 {
			if row[i] == row[j] {
				row[i] ^= 1
				row[j] ^= 1
			}
		}
		if i == j {
			row[i] ^= 1
		}
	}
	return image
}
```

#### JavaScript

```js
/**
 * @param {number[][]} image
 * @return {number[][]}
 */
var flipAndInvertImage = function (image) {
    for (const row of image) {
        let i = 0;
        let j = row.length - 1;
        for (; i < j; ++i, --j) {
            if (row[i] == row[j]) {
                row[i] ^= 1;
                row[j] ^= 1;
            }
        }
        if (i == j) {
            row[i] ^= 1;
        }
    }
    return image;
};
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [833. 字符串中的查找与替换](https://leetcode.cn/problems/find-and-replace-in-string){#833}

{{< tabs "833" >}}

{{% tab "python" %}}
```python
class Solution:
    def findReplaceString(
        self, s: str, indices: List[int], sources: List[str], targets: List[str]
    ) -> str:
        n = len(s)
        d = [-1] * n
        for k, (i, src) in enumerate(zip(indices, sources)):
            if s.startswith(src, i):
                d[i] = k
        ans = []
        i = 0
        while i < n:
            if ~d[i]:
                ans.append(targets[d[i]])
                i += len(sources[d[i]])
            else:
                ans.append(s[i])
                i += 1
        return "".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        int n = s.length();
        var d = new int[n];
        Arrays.fill(d, -1);
        for (int k = 0; k < indices.length; ++k) {
            int i = indices[k];
            if (s.startsWith(sources[k], i)) {
                d[i] = k;
            }
        }
        var ans = new StringBuilder();
        for (int i = 0; i < n;) {
            if (d[i] >= 0) {
                ans.append(targets[d[i]]);
                i += sources[d[i]].length();
            } else {
                ans.append(s.charAt(i++));
            }
        }
        return ans.toString();
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<int> d(n, -1);
        for (int k = 0; k < indices.size(); ++k) {
            int i = indices[k];
            if (s.compare(i, sources[k].size(), sources[k]) == 0) {
                d[i] = k;
            }
        }
        string ans;
        for (int i = 0; i < n;) {
            if (~d[i]) {
                ans += targets[d[i]];
                i += sources[d[i]].size();
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func findReplaceString(s string, indices []int, sources []string, targets []string) string {
	n := len(s)
	d := make([]int, n)
	for k, i := range indices {
		if strings.HasPrefix(s[i:], sources[k]) {
			d[i] = k + 1
		}
	}
	ans := &strings.Builder{}
	for i := 0; i < n; {
		if d[i] > 0 {
			ans.WriteString(targets[d[i]-1])
			i += len(sources[d[i]-1])
		} else {
			ans.WriteByte(s[i])
			i++
		}
	}
	return ans.String()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function findReplaceString(
    s: string,
    indices: number[],
    sources: string[],
    targets: string[],
): string {
    const n = s.length;
    const d: number[] = Array(n).fill(-1);
    for (let k = 0; k < indices.length; ++k) {
        const [i, src] = [indices[k], sources[k]];
        if (s.startsWith(src, i)) {
            d[i] = k;
        }
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ) {
        if (d[i] >= 0) {
            ans.push(targets[d[i]]);
            i += sources[d[i]].length;
        } else {
            ans.push(s[i++]);
        }
    }
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>你会得到一个字符串 <code>s</code>&nbsp;(索引从 0 开始)，你必须对它执行 <code>k</code> 个替换操作。替换操作以三个长度均为 <code>k</code> 的并行数组给出：<code>indices</code>,&nbsp;<code>sources</code>,&nbsp;&nbsp;<code>targets</code>。</p>

<p>要完成第 <code>i</code> 个替换操作:</p>

<ol>
	<li>检查 <strong>子字符串</strong> &nbsp;<code>sources[i]</code>&nbsp;是否出现在 <strong>原字符串</strong> <code>s</code> 的索引&nbsp;<code>indices[i]</code>&nbsp;处。</li>
	<li>如果没有出现，&nbsp;<strong>什么也不做</strong>&nbsp;。</li>
	<li>如果出现，则用&nbsp;<code>targets[i]</code>&nbsp;<strong>替换</strong>&nbsp;该子字符串。</li>
</ol>

<p>例如，如果 <code>s = "abcd"</code>&nbsp;，&nbsp;<code>indices[i] = 0</code> ,&nbsp;<code>sources[i] = "ab"</code>， <code>targets[i] = "eee"</code> ，那么替换的结果将是 <code>"<u>eee</u>cd"</code> 。</p>

<p>所有替换操作必须 <strong>同时</strong> 发生，这意味着替换操作不应该影响彼此的索引。测试用例保证元素间<strong>不会重叠 </strong>。</p>

<ul>
	<li>例如，一个 <code>s = "abc"</code> ，&nbsp; <code>indices = [0,1]</code> ， <code>sources = ["ab"，"bc"]</code>&nbsp;的测试用例将不会生成，因为 <code>"ab"</code> 和 <code>"bc"</code> 替换重叠。</li>
</ul>

<p><em>在对 <code>s</code>&nbsp;执行所有替换操作后返回 <strong>结果字符串</strong> 。</em></p>

<p><strong>子字符串</strong> 是字符串中连续的字符序列。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0833.Find%20And%20Replace%20in%20String/images/833-ex1.png" /></p>

<pre>
<strong>输入：</strong>s = "abcd", indices = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
<strong>输出：</strong>"eeebffff"
<strong>解释：
</strong>"a" 从 s 中的索引 0 开始，所以它被替换为 "eee"。
"cd" 从 s 中的索引 2 开始，所以它被替换为 "ffff"。
</pre>

<p><strong>示例 2：</strong><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0833.Find%20And%20Replace%20in%20String/images/833-ex2-1.png" /></p>

<pre>
<strong>输入：</strong>s = "abcd", indices = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
<strong>输出：</strong>"eeecd"
<strong>解释：
</strong>"ab" 从 s 中的索引 0 开始，所以它被替换为 "eee"。
"ec" 没有从<strong>原始的</strong> S 中的索引 2 开始，所以它没有被替换。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>k == indices.length == sources.length == targets.length</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
	<li><code>0 &lt;= indices[i] &lt; s.length</code></li>
	<li><code>1 &lt;= sources[i].length, targets[i].length &lt;= 50</code></li>
	<li><code>s</code> 仅由小写英文字母组成</li>
	<li><code>sources[i]</code> 和 <code>targets[i]</code> 仅由小写英文字母组成</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们遍历每个替换操作，对于当前第 $k$ 个替换操作 $(i, \text{src})$，如果 $s[i..i+|\text{src}|-1]$ 与 $\text{src}$ 相等，此时我们记录下标 $i$ 处需要替换的是 $\text{targets}$ 的第 $k$ 个字符串，否则不需要替换。

接下来，我们只需要遍历原字符串 $s$，根据记录的信息进行替换即可。

时间复杂度 $O(L)$，空间复杂度 $O(n)$。其中 $L$ 是所有字符串的长度之和，而 $n$ 是字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def findReplaceString(
        self, s: str, indices: List[int], sources: List[str], targets: List[str]
    ) -> str:
        n = len(s)
        d = [-1] * n
        for k, (i, src) in enumerate(zip(indices, sources)):
            if s.startswith(src, i):
                d[i] = k
        ans = []
        i = 0
        while i < n:
            if ~d[i]:
                ans.append(targets[d[i]])
                i += len(sources[d[i]])
            else:
                ans.append(s[i])
                i += 1
        return "".join(ans)
```

#### Java

```java
class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        int n = s.length();
        var d = new int[n];
        Arrays.fill(d, -1);
        for (int k = 0; k < indices.length; ++k) {
            int i = indices[k];
            if (s.startsWith(sources[k], i)) {
                d[i] = k;
            }
        }
        var ans = new StringBuilder();
        for (int i = 0; i < n;) {
            if (d[i] >= 0) {
                ans.append(targets[d[i]]);
                i += sources[d[i]].length();
            } else {
                ans.append(s.charAt(i++));
            }
        }
        return ans.toString();
    }
}
```

#### C++

```cpp
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size();
        vector<int> d(n, -1);
        for (int k = 0; k < indices.size(); ++k) {
            int i = indices[k];
            if (s.compare(i, sources[k].size(), sources[k]) == 0) {
                d[i] = k;
            }
        }
        string ans;
        for (int i = 0; i < n;) {
            if (~d[i]) {
                ans += targets[d[i]];
                i += sources[d[i]].size();
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }
};
```

#### Go

```go
func findReplaceString(s string, indices []int, sources []string, targets []string) string {
	n := len(s)
	d := make([]int, n)
	for k, i := range indices {
		if strings.HasPrefix(s[i:], sources[k]) {
			d[i] = k + 1
		}
	}
	ans := &strings.Builder{}
	for i := 0; i < n; {
		if d[i] > 0 {
			ans.WriteString(targets[d[i]-1])
			i += len(sources[d[i]-1])
		} else {
			ans.WriteByte(s[i])
			i++
		}
	}
	return ans.String()
}
```

#### TypeScript

```ts
function findReplaceString(
    s: string,
    indices: number[],
    sources: string[],
    targets: string[],
): string {
    const n = s.length;
    const d: number[] = Array(n).fill(-1);
    for (let k = 0; k < indices.length; ++k) {
        const [i, src] = [indices[k], sources[k]];
        if (s.startsWith(src, i)) {
            d[i] = k;
        }
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ) {
        if (d[i] >= 0) {
            ans.push(targets[d[i]]);
            i += sources[d[i]].length;
        } else {
            ans.push(s[i++]);
        }
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [834. 树中距离之和](https://leetcode.cn/problems/sum-of-distances-in-tree){#834}

{{< tabs "834" >}}

{{% tab "python" %}}
```python
class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        def dfs1(i: int, fa: int, d: int):
            ans[0] += d
            size[i] = 1
            for j in g[i]:
                if j != fa:
                    dfs1(j, i, d + 1)
                    size[i] += size[j]

        def dfs2(i: int, fa: int, t: int):
            ans[i] = t
            for j in g[i]:
                if j != fa:
                    dfs2(j, i, t - size[j] + n - size[j])

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)

        ans = [0] * n
        size = [0] * n
        dfs1(0, -1, 0)
        dfs2(0, -1, ans[0])
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private int n;
    private int[] ans;
    private int[] size;
    private List<Integer>[] g;

    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        this.n = n;
        g = new List[n];
        ans = new int[n];
        size = new int[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1, ans[0]);
        return ans;
    }

    private void dfs1(int i, int fa, int d) {
        ans[0] += d;
        size[i] = 1;
        for (int j : g[i]) {
            if (j != fa) {
                dfs1(j, i, d + 1);
                size[i] += size[j];
            }
        }
    }

    private void dfs2(int i, int fa, int t) {
        ans[i] = t;
        for (int j : g[i]) {
            if (j != fa) {
                dfs2(j, i, t - size[j] + n - size[j]);
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
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> ans(n);
        vector<int> size(n);

        function<void(int, int, int)> dfs1 = [&](int i, int fa, int d) {
            ans[0] += d;
            size[i] = 1;
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs1(j, i, d + 1);
                    size[i] += size[j];
                }
            }
        };

        function<void(int, int, int)> dfs2 = [&](int i, int fa, int t) {
            ans[i] = t;
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs2(j, i, t - size[j] + n - size[j]);
                }
            }
        };

        dfs1(0, -1, 0);
        dfs2(0, -1, ans[0]);
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func sumOfDistancesInTree(n int, edges [][]int) []int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := make([]int, n)
	size := make([]int, n)
	var dfs1 func(i, fa, d int)
	dfs1 = func(i, fa, d int) {
		ans[0] += d
		size[i] = 1
		for _, j := range g[i] {
			if j != fa {
				dfs1(j, i, d+1)
				size[i] += size[j]
			}
		}
	}
	var dfs2 func(i, fa, t int)
	dfs2 = func(i, fa, t int) {
		ans[i] = t
		for _, j := range g[i] {
			if j != fa {
				dfs2(j, i, t-size[j]+n-size[j])
			}
		}
	}
	dfs1(0, -1, 0)
	dfs2(0, -1, ans[0])
	return ans
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function sumOfDistancesInTree(n: number, edges: number[][]): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const ans: number[] = new Array(n).fill(0);
    const size: number[] = new Array(n).fill(0);
    const dfs1 = (i: number, fa: number, d: number) => {
        ans[0] += d;
        size[i] = 1;
        for (const j of g[i]) {
            if (j !== fa) {
                dfs1(j, i, d + 1);
                size[i] += size[j];
            }
        }
    };
    const dfs2 = (i: number, fa: number, t: number) => {
        ans[i] = t;
        for (const j of g[i]) {
            if (j !== fa) {
                dfs2(j, i, t - size[j] + n - size[j]);
            }
        }
    };
    dfs1(0, -1, 0);
    dfs2(0, -1, ans[0]);
    return ans;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给定一个无向、连通的树。树中有 <code>n</code> 个标记为 <code>0...n-1</code> 的节点以及 <code>n-1</code>&nbsp;条边&nbsp;。</p>

<p>给定整数 <code>n</code> 和数组&nbsp;<code>edges</code>&nbsp;，&nbsp;<code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code>表示树中的节点&nbsp;<code>a<sub>i</sub></code>&nbsp;和&nbsp;<code>b<sub>i</sub></code>&nbsp;之间有一条边。</p>

<p>返回长度为 <code>n</code> 的数组&nbsp;<code>answer</code>&nbsp;，其中&nbsp;<code>answer[i]</code>&nbsp;是树中第 <code>i</code> 个节点与所有其他节点之间的距离之和。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<p><img src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0834.Sum%20of%20Distances%20in%20Tree/images/lc-sumdist1.jpg" /></p>

<pre>
<strong>输入: </strong>n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
<strong>输出: </strong>[8,12,6,10,10,10]
<strong>解释: </strong>树如图所示。
我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
</pre>

<p><strong>示例 2:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0834.Sum%20of%20Distances%20in%20Tree/images/lc-sumdist2.jpg" />
<pre>
<strong>输入:</strong> n = 1, edges = []
<strong>输出:</strong> [0]
</pre>

<p><strong>示例 3:</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0834.Sum%20of%20Distances%20in%20Tree/images/lc-sumdist3.jpg" />
<pre>
<strong>输入:</strong> n = 2, edges = [[1,0]]
<strong>输出:</strong> [1,1]
</pre>

<p>&nbsp;</p>

<p><strong>提示:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub>&nbsp;&lt; n</code></li>
	<li><code>a<sub>i</sub>&nbsp;!= b<sub>i</sub></code></li>
	<li>给定的输入保证为有效的树</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：树形 DP（换根）

我们先跑一遍 DFS，计算出每个节点的子树大小，记录在数组 $size$ 中，并且统计出节点 $0$ 到其他节点的距离之和，记录在 $ans[0]$ 中。

接下来，我们再跑一遍 DFS，枚举每个点作为根节点时，其他节点到根节点的距离之和。假设当前节点 $i$ 的答案为 $t$，当我们从节点 $i$ 转移到节点 $j$ 时，距离之和变为 $t - size[j] + n - size[j]$，即距离节点 $j$ 及其子树节点的距离之和减少 $size[j]$，而距离其它节点的距离之和增加 $n - size[j]$。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为树的节点数。

相似题目：

-   [2581. 统计可能的树根数目](https://github.com/doocs/leetcode/blob/main/solution/2500-2599/2581.Count%20Number%20of%20Possible%20Root%20Nodes/README.md)

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        def dfs1(i: int, fa: int, d: int):
            ans[0] += d
            size[i] = 1
            for j in g[i]:
                if j != fa:
                    dfs1(j, i, d + 1)
                    size[i] += size[j]

        def dfs2(i: int, fa: int, t: int):
            ans[i] = t
            for j in g[i]:
                if j != fa:
                    dfs2(j, i, t - size[j] + n - size[j])

        g = defaultdict(list)
        for a, b in edges:
            g[a].append(b)
            g[b].append(a)

        ans = [0] * n
        size = [0] * n
        dfs1(0, -1, 0)
        dfs2(0, -1, ans[0])
        return ans
```

#### Java

```java
class Solution {
    private int n;
    private int[] ans;
    private int[] size;
    private List<Integer>[] g;

    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        this.n = n;
        g = new List[n];
        ans = new int[n];
        size = new int[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        for (var e : edges) {
            int a = e[0], b = e[1];
            g[a].add(b);
            g[b].add(a);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1, ans[0]);
        return ans;
    }

    private void dfs1(int i, int fa, int d) {
        ans[0] += d;
        size[i] = 1;
        for (int j : g[i]) {
            if (j != fa) {
                dfs1(j, i, d + 1);
                size[i] += size[j];
            }
        }
    }

    private void dfs2(int i, int fa, int t) {
        ans[i] = t;
        for (int j : g[i]) {
            if (j != fa) {
                dfs2(j, i, t - size[j] + n - size[j]);
            }
        }
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> ans(n);
        vector<int> size(n);

        function<void(int, int, int)> dfs1 = [&](int i, int fa, int d) {
            ans[0] += d;
            size[i] = 1;
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs1(j, i, d + 1);
                    size[i] += size[j];
                }
            }
        };

        function<void(int, int, int)> dfs2 = [&](int i, int fa, int t) {
            ans[i] = t;
            for (int& j : g[i]) {
                if (j != fa) {
                    dfs2(j, i, t - size[j] + n - size[j]);
                }
            }
        };

        dfs1(0, -1, 0);
        dfs2(0, -1, ans[0]);
        return ans;
    }
};
```

#### Go

```go
func sumOfDistancesInTree(n int, edges [][]int) []int {
	g := make([][]int, n)
	for _, e := range edges {
		a, b := e[0], e[1]
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	ans := make([]int, n)
	size := make([]int, n)
	var dfs1 func(i, fa, d int)
	dfs1 = func(i, fa, d int) {
		ans[0] += d
		size[i] = 1
		for _, j := range g[i] {
			if j != fa {
				dfs1(j, i, d+1)
				size[i] += size[j]
			}
		}
	}
	var dfs2 func(i, fa, t int)
	dfs2 = func(i, fa, t int) {
		ans[i] = t
		for _, j := range g[i] {
			if j != fa {
				dfs2(j, i, t-size[j]+n-size[j])
			}
		}
	}
	dfs1(0, -1, 0)
	dfs2(0, -1, ans[0])
	return ans
}
```

#### TypeScript

```ts
function sumOfDistancesInTree(n: number, edges: number[][]): number[] {
    const g: number[][] = Array.from({ length: n }, () => []);
    for (const [a, b] of edges) {
        g[a].push(b);
        g[b].push(a);
    }
    const ans: number[] = new Array(n).fill(0);
    const size: number[] = new Array(n).fill(0);
    const dfs1 = (i: number, fa: number, d: number) => {
        ans[0] += d;
        size[i] = 1;
        for (const j of g[i]) {
            if (j !== fa) {
                dfs1(j, i, d + 1);
                size[i] += size[j];
            }
        }
    };
    const dfs2 = (i: number, fa: number, t: number) => {
        ans[i] = t;
        for (const j of g[i]) {
            if (j !== fa) {
                dfs2(j, i, t - size[j] + n - size[j]);
            }
        }
    };
    dfs1(0, -1, 0);
    dfs2(0, -1, ans[0]);
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [835. 图像重叠](https://leetcode.cn/problems/image-overlap){#835}

{{< tabs "835" >}}

{{% tab "python" %}}
```python
class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        cnt = Counter()
        for i in range(n):
            for j in range(n):
                if img1[i][j]:
                    for h in range(n):
                        for k in range(n):
                            if img2[h][k]:
                                cnt[(i - h, j - k)] += 1
        return max(cnt.values()) if cnt else 0
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        Map<List<Integer>, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) {
                    for (int h = 0; h < n; ++h) {
                        for (int k = 0; k < n; ++k) {
                            if (img2[h][k] == 1) {
                                List<Integer> t = List.of(i - h, j - k);
                                ans = Math.max(ans, cnt.merge(t, 1, Integer::sum));
                            }
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
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        map<pair<int, int>, int> cnt;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j]) {
                    for (int h = 0; h < n; ++h) {
                        for (int k = 0; k < n; ++k) {
                            if (img2[h][k]) {
                                ans = max(ans, ++cnt[{i - h, j - k}]);
                            }
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
func largestOverlap(img1 [][]int, img2 [][]int) (ans int) {
	type pair struct{ x, y int }
	cnt := map[pair]int{}
	for i, row1 := range img1 {
		for j, x1 := range row1 {
			if x1 == 1 {
				for h, row2 := range img2 {
					for k, x2 := range row2 {
						if x2 == 1 {
							t := pair{i - h, j - k}
							cnt[t]++
							ans = max(ans, cnt[t])
						}
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
function largestOverlap(img1: number[][], img2: number[][]): number {
    const n = img1.length;
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (img1[i][j] === 1) {
                for (let h = 0; h < n; ++h) {
                    for (let k = 0; k < n; ++k) {
                        if (img2[h][k] === 1) {
                            const t = (i - h) * 200 + (j - k);
                            cnt.set(t, (cnt.get(t) ?? 0) + 1);
                            ans = Math.max(ans, cnt.get(t)!);
                        }
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

<p>给你两个图像 <code>img1</code> 和 <code>img2</code> ，两个图像的大小都是 <code>n x n</code> ，用大小相同的二进制正方形矩阵表示。二进制矩阵仅由若干 <code>0</code> 和若干 <code>1</code> 组成。</p>

<p><strong>转换</strong> 其中一个图像，将所有的 <code>1</code> 向左，右，上，或下滑动任何数量的单位；然后把它放在另一个图像的上面。该转换的 <strong>重叠</strong> 是指两个图像 <strong>都</strong> 具有 <code>1</code> 的位置的数目。</p>

<div class="original__bRMd">
<div>
<p>请注意，转换 <strong>不包括</strong> 向任何方向旋转。越过矩阵边界的 <code>1</code> 都将被清除。</p>

<p>最大可能的重叠数量是多少？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0835.Image%20Overlap/images/overlap1.jpg" style="width: 450px; height: 231px;" />
<pre>
<strong>输入：</strong>img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
<strong>输出：</strong>3
<strong>解释：</strong>将 img1 向右移动 1 个单位，再向下移动 1 个单位。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0835.Image%20Overlap/images/overlap_step1.jpg" style="width: 450px; height: 105px;" />
两个图像都具有 <code>1</code> 的位置的数目是 3（用红色标识）。
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0835.Image%20Overlap/images/overlap_step2.jpg" style="width: 450px; height: 231px;" />
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>img1 = [[1]], img2 = [[1]]
<strong>输出：</strong>1
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>img1 = [[0]], img2 = [[0]]
<strong>输出：</strong>0
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == img1.length == img1[i].length</code></li>
	<li><code>n == img2.length == img2[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 30</code></li>
	<li><code>img1[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
	<li><code>img2[i][j]</code> 为 <code>0</code> 或 <code>1</code></li>
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

### 方法一：枚举

我们可以枚举 $\textit{img1}$ 和 $\textit{img2}$ 的每个 $1$ 的位置，分别记为 $(i, j)$ 和 $(h, k)$。然后我们计算得到偏移量 $(i - h, j - k)$，记为 $(dx, dy)$，用哈希表 $\textit{cnt}$ 记录每个偏移量出现的次数。最后我们遍历哈希表 $\textit{cnt}$，找到出现次数最多的偏移量，即为答案。

时间复杂度 $O(n^4)$，空间复杂度 $O(n^2)$。其中 $n$ 是 $\textit{img1}$ 的边长。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n = len(img1)
        cnt = Counter()
        for i in range(n):
            for j in range(n):
                if img1[i][j]:
                    for h in range(n):
                        for k in range(n):
                            if img2[h][k]:
                                cnt[(i - h, j - k)] += 1
        return max(cnt.values()) if cnt else 0
```

#### Java

```java
class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int n = img1.length;
        Map<List<Integer>, Integer> cnt = new HashMap<>();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) {
                    for (int h = 0; h < n; ++h) {
                        for (int k = 0; k < n; ++k) {
                            if (img2[h][k] == 1) {
                                List<Integer> t = List.of(i - h, j - k);
                                ans = Math.max(ans, cnt.merge(t, 1, Integer::sum));
                            }
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
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        map<pair<int, int>, int> cnt;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j]) {
                    for (int h = 0; h < n; ++h) {
                        for (int k = 0; k < n; ++k) {
                            if (img2[h][k]) {
                                ans = max(ans, ++cnt[{i - h, j - k}]);
                            }
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
func largestOverlap(img1 [][]int, img2 [][]int) (ans int) {
	type pair struct{ x, y int }
	cnt := map[pair]int{}
	for i, row1 := range img1 {
		for j, x1 := range row1 {
			if x1 == 1 {
				for h, row2 := range img2 {
					for k, x2 := range row2 {
						if x2 == 1 {
							t := pair{i - h, j - k}
							cnt[t]++
							ans = max(ans, cnt[t])
						}
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
function largestOverlap(img1: number[][], img2: number[][]): number {
    const n = img1.length;
    const cnt: Map<number, number> = new Map();
    let ans = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (img1[i][j] === 1) {
                for (let h = 0; h < n; ++h) {
                    for (let k = 0; k < n; ++k) {
                        if (img2[h][k] === 1) {
                            const t = (i - h) * 200 + (j - k);
                            cnt.set(t, (cnt.get(t) ?? 0) + 1);
                            ans = Math.max(ans, cnt.get(t)!);
                        }
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

# [836. 矩形重叠](https://leetcode.cn/problems/rectangle-overlap){#836}

{{< tabs "836" >}}

{{% tab "python" %}}
```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1, x2, y2 = rec1
        x3, y3, x4, y4 = rec2
        return not (y3 >= y2 or y4 <= y1 or x3 >= x2 or x4 <= x1)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1);
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	x1, y1, x2, y2 := rec1[0], rec1[1], rec1[2], rec1[3]
	x3, y3, x4, y4 := rec2[0], rec2[1], rec2[2], rec2[3]
	return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function isRectangleOverlap(rec1: number[], rec2: number[]): boolean {
    const [x1, y1, x2, y2] = rec1;
    const [x3, y3, x4, y4] = rec2;
    return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>矩形以列表 <code>[x1, y1, x2, y2]</code> 的形式表示，其中 <code>(x1, y1)</code> 为左下角的坐标，<code>(x2, y2)</code> 是右上角的坐标。矩形的上下边平行于 x 轴，左右边平行于 y 轴。</p>

<p>如果相交的面积为 <strong>正</strong> ，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。</p>

<p>给出两个矩形 <code>rec1</code> 和 <code>rec2</code> 。如果它们重叠，返回 <code>true</code>；否则，返回 <code>false</code> 。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>rec1 = [0,0,2,2], rec2 = [1,1,3,3]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>rec1 = [0,0,1,1], rec2 = [1,0,2,1]
<strong>输出：</strong>false
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>rec1 = [0,0,1,1], rec2 = [2,2,3,3]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>rect1.length == 4</code></li>
	<li><code>rect2.length == 4</code></li>
	<li><code>-10<sup>9</sup> &lt;= rec1[i], rec2[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>rec1</code> 和 <code>rec2</code> 表示一个面积不为零的有效矩形</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：判断不重叠的情况

我们记矩形 $\text{rec1}$ 的坐标点为 $(x_1, y_1, x_2, y_2)$，矩形 $\text{rec2}$ 的坐标点为 $(x_3, y_3, x_4, y_4)$。

那么当满足以下任一条件时，矩形 $\text{rec1}$ 和 $\text{rec2}$ 不重叠：

-   满足 $y_3 \geq y_2$，即 $\text{rec2}$ 在 $\text{rec1}$ 的上方；
-   满足 $y_4 \leq y_1$，即 $\text{rec2}$ 在 $\text{rec1}$ 的下方；
-   满足 $x_3 \geq x_2$，即 $\text{rec2}$ 在 $\text{rec1}$ 的右方；
-   满足 $x_4 \leq x_1$，即 $\text{rec2}$ 在 $\text{rec1}$ 的左方。

当以上条件都不满足时，矩形 $\text{rec1}$ 和 $\text{rec2}$ 重叠。

时间复杂度 $O(1)$，空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        x1, y1, x2, y2 = rec1
        x3, y3, x4, y4 = rec2
        return not (y3 >= y2 or y4 <= y1 or x3 >= x2 or x4 <= x1)
```

#### Java

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec1[2], y2 = rec1[3];
        int x3 = rec2[0], y3 = rec2[1], x4 = rec2[2], y4 = rec2[3];
        return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1);
    }
};
```

#### Go

```go
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	x1, y1, x2, y2 := rec1[0], rec1[1], rec1[2], rec1[3]
	x3, y3, x4, y4 := rec2[0], rec2[1], rec2[2], rec2[3]
	return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1)
}
```

#### TypeScript

```ts
function isRectangleOverlap(rec1: number[], rec2: number[]): boolean {
    const [x1, y1, x2, y2] = rec1;
    const [x3, y3, x4, y4] = rec2;
    return !(y3 >= y2 || y4 <= y1 || x3 >= x2 || x4 <= x1);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [837. 新 21 点](https://leetcode.cn/problems/new-21-game){#837}

{{< tabs "837" >}}

{{% tab "python" %}}
```python
class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        f = [0] * (k + maxPts)
        for i in range(k, min(n + 1, k + maxPts)):
            f[i] = 1
        f[k - 1] = min(n - k + 1, maxPts) / maxPts
        for i in range(k - 2, -1, -1):
            f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts
        return f[0]
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }
        double[] f = new double[k + maxPts];
        for (int i = k; i < Math.min(n + 1, k + maxPts); ++i) {
            f[i] = 1;
        }
        f[k - 1] = Math.min(n - k + 1, maxPts) * 1.0 / maxPts;
        for (int i = k - 2; i >= 0; --i) {
            f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts;
        }
        return f[0];
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }
        double f[k + maxPts];
        memset(f, 0, sizeof(f));
        for (int i = k; i < min(n + 1, k + maxPts); ++i) {
            f[i] = 1;
        }
        f[k - 1] = min(n - k + 1, maxPts) * 1.0 / maxPts;
        for (int i = k - 2; i >= 0; --i) {
            f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts;
        }
        return f[0];
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func new21Game(n int, k int, maxPts int) float64 {
	if k == 0 {
		return 1
	}
	f := make([]float64, k+maxPts)
	for i := k; i < min(n+1, k+maxPts); i++ {
		f[i] = 1
	}
	f[k-1] = float64(min(n-k+1, maxPts)) / float64(maxPts)
	for i := k - 2; i >= 0; i-- {
		f[i] = f[i+1] + (f[i+1]-f[i+maxPts+1])/float64(maxPts)
	}
	return f[0]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function new21Game(n: number, k: number, maxPts: number): number {
    if (k === 0) {
        return 1;
    }
    const f: number[] = Array(k + maxPts).fill(0);
    for (let i = k; i < Math.min(n + 1, k + maxPts); ++i) {
        f[i] = 1;
    }
    f[k - 1] = Math.min(n - k + 1, maxPts) / maxPts;
    for (let i = k - 2; i >= 0; --i) {
        f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts;
    }
    return f[0];
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>爱丽丝参与一个大致基于纸牌游戏 <strong>“21点”</strong> 规则的游戏，描述如下：</p>

<p>爱丽丝以 <code>0</code> 分开始，并在她的得分少于 <code>k</code> 分时抽取数字。 抽取时，她从 <code>[1, maxPts]</code> 的范围中随机获得一个整数作为分数进行累计，其中 <code>maxPts</code> 是一个整数。 每次抽取都是独立的，其结果具有相同的概率。</p>

<p>当爱丽丝获得 <code>k</code> 分 <strong>或更多分</strong> 时，她就停止抽取数字。</p>

<p>爱丽丝的分数不超过 <code>n</code> 的概率是多少？</p>

<p>与实际答案误差不超过&nbsp;<code>10<sup>-5</sup></code> 的答案将被视为正确答案。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>n = 10, k = 1, maxPts = 10
<strong>输出：</strong>1.00000
<strong>解释：</strong>爱丽丝得到一张牌，然后停止。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>n = 6, k = 1, maxPts = 10
<strong>输出：</strong>0.60000
<strong>解释：</strong>爱丽丝得到一张牌，然后停止。 在 10 种可能性中的 6 种情况下，她的得分不超过 6 分。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入：</strong>n = 21, k = 17, maxPts = 10
<strong>输出：</strong>0.73278
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>0 &lt;= k &lt;= n &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= maxPts &lt;= 10<sup>4</sup></code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：记忆化搜索

我们设计一个函数 $dfs(i)$，表示当前分数为 $i$ 时，到最终停止抽取数字时，分数不超过 $n$ 的概率。那么答案就是 $dfs(0)$。

函数 $dfs(i)$ 的计算方法如下：

-   如果 $i \ge k$，那么停止抽取数字，如果 $i \le n$，返回 $1$，否则返回 $0$；
-   否则，可以在 $[1,..\textit{maxPts}]$ 范围内抽取下一个数字 $j$，那么 $dfs(i) = \frac{1}{maxPts} \sum_{j=1}^{maxPts} dfs(i+j)$。

这里我们可以使用记忆化搜索来加速计算。

以上方法的时间复杂度为 $O(k \times \textit{maxPts})$，会超出时间限制，我们需要优化一下。

当 $i \lt k$ 时，以下等式成立：

$$
\begin{aligned}
dfs(i) &= (dfs(i + 1) + dfs(i + 2) + \cdots + dfs(i + \textit{maxPts})) / \ & (1)
\end{aligned}
$$

当 $i \lt k - 1$ 时，以下等式成立：

$$
\begin{aligned}
dfs(i+1) &= (dfs(i + 2) + dfs(i + 3) + \cdots + dfs(i + \textit{maxPts} + 1)) / \textit{maxPts} & (2)
\end{aligned}
$$

因此，当 $i \lt k-1$ 时，我们将等式 $(1)$ 减去等式 $(2)$，得到：

$$
\begin{aligned}
dfs(i) - dfs(i+1) &= (dfs(i + 1) - dfs(i + \textit{maxPts} + 1)) / \textit{maxPts}
\end{aligned}
$$

即：

$$
\begin{aligned}
dfs(i) &= dfs(i + 1) + (dfs(i + 1) - dfs(i + \textit{maxPts} + 1)) / \textit{maxPts}
\end{aligned}
$$

如果 $i=k-1$，有：

$$
\begin{aligned}
dfs(i) &= dfs(k - 1) &= dfs(k) + dfs(k + 1) + \cdots + dfs(k + \textit{maxPts} - 1) / \textit{maxPts} & (3)
\end{aligned}
$$

我们假设有 $i$ 个数不超过 $n$，那么 $k+i-1 \leq n$，又因为 $i\leq \textit{maxPts}$，所以 $i \leq \min(n-k+1, \textit{maxPts})$，因此等式 $(3)$ 可以写成：

$$
\begin{aligned}
dfs(k-1) &= \min(n-k+1, \textit{maxPts}) / \textit{maxPts}
\end{aligned}
$$

综上所述，有以下状态转移方程：

$$
\begin{aligned}
dfs(i) &= \begin{cases}
1, & i \geq k, i \leq n \\
0, & i \geq k, i \gt n \\
\min(n-k+1, \textit{maxPts}) / \textit{maxPts}, & i = k - 1 \\
dfs(i + 1) + (dfs(i + 1) - dfs(i + \textit{maxPts} + 1)) / \textit{maxPts}, & i < k - 1
\end{cases}
\end{aligned}
$$

时间复杂度 $O(k + \textit{maxPts})$，空间复杂度 $O(k + \textit{maxPts})$。其中 $k$ 为最大分数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        @cache
        def dfs(i: int) -> float:
            if i >= k:
                return int(i <= n)
            if i == k - 1:
                return min(n - k + 1, maxPts) / maxPts
            return dfs(i + 1) + (dfs(i + 1) - dfs(i + maxPts + 1)) / maxPts

        return dfs(0)
```

#### Java

```java
class Solution {
    private double[] f;
    private int n, k, maxPts;

    public double new21Game(int n, int k, int maxPts) {
        f = new double[k];
        this.n = n;
        this.k = k;
        this.maxPts = maxPts;
        return dfs(0);
    }

    private double dfs(int i) {
        if (i >= k) {
            return i <= n ? 1 : 0;
        }
        if (i == k - 1) {
            return Math.min(n - k + 1, maxPts) * 1.0 / maxPts;
        }
        if (f[i] != 0) {
            return f[i];
        }
        return f[i] = dfs(i + 1) + (dfs(i + 1) - dfs(i + maxPts + 1)) / maxPts;
    }
}
```

#### C++

```cpp
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> f(k);
        function<double(int)> dfs = [&](int i) -> double {
            if (i >= k) {
                return i <= n ? 1 : 0;
            }
            if (i == k - 1) {
                return min(n - k + 1, maxPts) * 1.0 / maxPts;
            }
            if (f[i]) {
                return f[i];
            }
            return f[i] = dfs(i + 1) + (dfs(i + 1) - dfs(i + maxPts + 1)) / maxPts;
        };
        return dfs(0);
    }
};
```

#### Go

```go
func new21Game(n int, k int, maxPts int) float64 {
	f := make([]float64, k)
	var dfs func(int) float64
	dfs = func(i int) float64 {
		if i >= k {
			if i <= n {
				return 1
			}
			return 0
		}
		if i == k-1 {
			return float64(min(n-k+1, maxPts)) / float64(maxPts)
		}
		if f[i] > 0 {
			return f[i]
		}
		f[i] = dfs(i+1) + (dfs(i+1)-dfs(i+maxPts+1))/float64(maxPts)
		return f[i]
	}
	return dfs(0)
}
```

#### TypeScript

```ts
function new21Game(n: number, k: number, maxPts: number): number {
    const f: number[] = Array(k).fill(0);
    const dfs = (i: number): number => {
        if (i >= k) {
            return i <= n ? 1 : 0;
        }
        if (i === k - 1) {
            return Math.min(n - k + 1, maxPts) / maxPts;
        }
        if (f[i] !== 0) {
            return f[i];
        }
        return (f[i] = dfs(i + 1) + (dfs(i + 1) - dfs(i + maxPts + 1)) / maxPts);
    };
    return dfs(0);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二：动态规划

我们可以将方法一中的记忆化搜索改成动态规划。

定义 $f[i]$ 表示当前分数为 $i$ 时，到最终停止抽取数字时，分数不超过 $n$ 的概率。那么答案就是 $f[0]$。

当 $k \leq i \leq \min(n, k + \textit{maxPts} - 1)$ 时，有 $f[i] = 1$。

当 $i = k - 1$ 时，有 $f[i] = \min(n-k+1, \textit{maxPts}) / \textit{maxPts}$。

当 $i \lt k - 1$ 时，有 $f[i] = f[i + 1] + (f[i + 1] - f[i + \textit{maxPts} + 1]) / \textit{maxPts}$。

时间复杂度 $O(k + \textit{maxPts})$，空间复杂度 $O(k + \textit{maxPts})$。其中 $k$ 为最大分数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        f = [0] * (k + maxPts)
        for i in range(k, min(n + 1, k + maxPts)):
            f[i] = 1
        f[k - 1] = min(n - k + 1, maxPts) / maxPts
        for i in range(k - 2, -1, -1):
            f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts
        return f[0]
```

#### Java

```java
class Solution {
    public double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }
        double[] f = new double[k + maxPts];
        for (int i = k; i < Math.min(n + 1, k + maxPts); ++i) {
            f[i] = 1;
        }
        f[k - 1] = Math.min(n - k + 1, maxPts) * 1.0 / maxPts;
        for (int i = k - 2; i >= 0; --i) {
            f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts;
        }
        return f[0];
    }
}
```

#### C++

```cpp
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) {
            return 1.0;
        }
        double f[k + maxPts];
        memset(f, 0, sizeof(f));
        for (int i = k; i < min(n + 1, k + maxPts); ++i) {
            f[i] = 1;
        }
        f[k - 1] = min(n - k + 1, maxPts) * 1.0 / maxPts;
        for (int i = k - 2; i >= 0; --i) {
            f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts;
        }
        return f[0];
    }
};
```

#### Go

```go
func new21Game(n int, k int, maxPts int) float64 {
	if k == 0 {
		return 1
	}
	f := make([]float64, k+maxPts)
	for i := k; i < min(n+1, k+maxPts); i++ {
		f[i] = 1
	}
	f[k-1] = float64(min(n-k+1, maxPts)) / float64(maxPts)
	for i := k - 2; i >= 0; i-- {
		f[i] = f[i+1] + (f[i+1]-f[i+maxPts+1])/float64(maxPts)
	}
	return f[0]
}
```

#### TypeScript

```ts
function new21Game(n: number, k: number, maxPts: number): number {
    if (k === 0) {
        return 1;
    }
    const f: number[] = Array(k + maxPts).fill(0);
    for (let i = k; i < Math.min(n + 1, k + maxPts); ++i) {
        f[i] = 1;
    }
    f[k - 1] = Math.min(n - k + 1, maxPts) / maxPts;
    for (let i = k - 2; i >= 0; --i) {
        f[i] = f[i + 1] + (f[i + 1] - f[i + maxPts + 1]) / maxPts;
    }
    return f[0];
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [838. 推多米诺](https://leetcode.cn/problems/push-dominoes){#838}

{{< tabs "838" >}}

{{% tab "python" %}}
```python
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        q = deque()
        time = [-1] * n
        force = defaultdict(list)
        for i, f in enumerate(dominoes):
            if f != '.':
                q.append(i)
                time[i] = 0
                force[i].append(f)
        ans = ['.'] * n
        while q:
            i = q.popleft()
            if len(force[i]) == 1:
                ans[i] = f = force[i][0]
                j = i - 1 if f == 'L' else i + 1
                if 0 <= j < n:
                    t = time[i]
                    if time[j] == -1:
                        q.append(j)
                        time[j] = t + 1
                        force[j].append(f)
                    elif time[j] == t + 1:
                        force[j].append(f)
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        Deque<Integer> q = new ArrayDeque<>();
        int[] time = new int[n];
        Arrays.fill(time, -1);
        List<Character>[] force = new List[n];
        for (int i = 0; i < n; ++i) {
            force[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; ++i) {
            char f = dominoes.charAt(i);
            if (f != '.') {
                q.offer(i);
                time[i] = 0;
                force[i].add(f);
            }
        }
        char[] ans = new char[n];
        Arrays.fill(ans, '.');
        while (!q.isEmpty()) {
            int i = q.poll();
            if (force[i].size() == 1) {
                ans[i] = force[i].get(0);
                char f = ans[i];
                int j = f == 'L' ? i - 1 : i + 1;
                if (j >= 0 && j < n) {
                    int t = time[i];
                    if (time[j] == -1) {
                        q.offer(j);
                        time[j] = t + 1;
                        force[j].add(f);
                    } else if (time[j] == t + 1) {
                        force[j].add(f);
                    }
                }
            }
        }
        return new String(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, -1);
        vector<string> force(n);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') continue;
            q.emplace(i);
            time[i] = 0;
            force[i].push_back(dominoes[i]);
        }

        string ans(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                ans[i] = f;
                int j = (f == 'L') ? (i - 1) : (i + 1);
                if (j >= 0 && j < n) {
                    int t = time[i];
                    if (time[j] == -1) {
                        q.emplace(j);
                        time[j] = t + 1;
                        force[j].push_back(f);
                    } else if (time[j] == t + 1)
                        force[j].push_back(f);
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
func pushDominoes(dominoes string) string {
	n := len(dominoes)
	q := []int{}
	time := make([]int, n)
	for i := range time {
		time[i] = -1
	}
	force := make([][]byte, n)
	for i, c := range dominoes {
		if c != '.' {
			q = append(q, i)
			time[i] = 0
			force[i] = append(force[i], byte(c))
		}
	}

	ans := bytes.Repeat([]byte{'.'}, n)
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		if len(force[i]) > 1 {
			continue
		}
		f := force[i][0]
		ans[i] = f
		j := i - 1
		if f == 'R' {
			j = i + 1
		}
		if 0 <= j && j < n {
			t := time[i]
			if time[j] == -1 {
				q = append(q, j)
				time[j] = t + 1
				force[j] = append(force[j], f)
			} else if time[j] == t+1 {
				force[j] = append(force[j], f)
			}
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function pushDominoes(dominoes: string): string {
    const n = dominoes.length;
    const q: number[] = [];
    const time: number[] = Array(n).fill(-1);
    const force: string[][] = Array.from({ length: n }, () => []);

    for (let i = 0; i < n; i++) {
        const f = dominoes[i];
        if (f !== '.') {
            q.push(i);
            time[i] = 0;
            force[i].push(f);
        }
    }

    const ans: string[] = Array(n).fill('.');
    let head = 0;
    while (head < q.length) {
        const i = q[head++];
        if (force[i].length === 1) {
            const f = force[i][0];
            ans[i] = f;
            const j = f === 'L' ? i - 1 : i + 1;
            if (j >= 0 && j < n) {
                const t = time[i];
                if (time[j] === -1) {
                    q.push(j);
                    time[j] = t + 1;
                    force[j].push(f);
                } else if (time[j] === t + 1) {
                    force[j].push(f);
                }
            }
        }
    }
    return ans.join('');
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p><code>n</code> 张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。</p>

<p>每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。</p>

<p>如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。</p>

<p>就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。</p>

<p>给你一个字符串 <code>dominoes</code> 表示这一行多米诺骨牌的初始状态，其中：</p>

<ul>
	<li><code>dominoes[i] = 'L'</code>，表示第 <code>i</code> 张多米诺骨牌被推向左侧，</li>
	<li><code>dominoes[i] = 'R'</code>，表示第 <code>i</code> 张多米诺骨牌被推向右侧，</li>
	<li><code>dominoes[i] = '.'</code>，表示没有推动第 <code>i</code> 张多米诺骨牌。</li>
</ul>

<p>返回表示最终状态的字符串。</p>
&nbsp;

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>dominoes = "RR.L"
<strong>输出：</strong>"RR.L"
<strong>解释：</strong>第一张多米诺骨牌没有给第二张施加额外的力。
</pre>

<p><strong>示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/0800-0899/0838.Push%20Dominoes/images/domino.png" style="height: 196px; width: 512px;" />
<pre>
<strong>输入：</strong>dominoes = ".L.R...LR..L.."
<strong>输出：</strong>"LL.RR.LLRRLL.."
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>n == dominoes.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>dominoes[i]</code> 为 <code>'L'</code>、<code>'R'</code> 或 <code>'.'</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：多源 BFS

把所有初始受到推力的骨牌（`L` 或 `R`）视作 **源点**，它们会同时向外扩散各自的力。用队列按时间层级（0, 1, 2 …）进行 BFS：

我们定义 $\text{time[i]}$ 记录第 *i* 张骨牌第一次受力的时刻，`-1` 表示尚未受力，定义 $\text{force[i]}$ 是一个长度可变的列表，存放该骨牌在同一时刻收到的方向（`'L'`、`'R'`）。初始时把所有 `L/R` 的下标压入队列，并将它们的时间置 0。

当弹出下标 *i* 时，若 $\text{force[i]}$ 只有一个方向，骨牌就会倒向该方向 $f$。设下一张骨牌下标为

$$
j =
\begin{cases}
i - 1, & f = L,\\
i + 1, & f = R.
\end{cases}
$$

若 $0 \leq j < n$：

-   若 $\text{time[j]}=-1$，说明 *j* 从未受力，记录 $\text{time[j]}=\text{time[i]}+1$ 并入队，同时把 $f$ 写入 $\text{force[j]}$。
-   若 $\text{time[j]}=\text{time[i]}+1$，说明它在同一“下一刻”已受过另一股力，此时只把 $f$ 追加到 $\text{force[j]}$，形成对冲；后续因 `len(force[j])==2`，它将保持竖直。

队列清空后，所有 $\text{force[i]}$ 长度为 1 的位置倒向对应方向；长度为 2 的位置保持 `.`。最终将字符数组拼接为答案。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 是骨牌的数量。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        q = deque()
        time = [-1] * n
        force = defaultdict(list)
        for i, f in enumerate(dominoes):
            if f != '.':
                q.append(i)
                time[i] = 0
                force[i].append(f)
        ans = ['.'] * n
        while q:
            i = q.popleft()
            if len(force[i]) == 1:
                ans[i] = f = force[i][0]
                j = i - 1 if f == 'L' else i + 1
                if 0 <= j < n:
                    t = time[i]
                    if time[j] == -1:
                        q.append(j)
                        time[j] = t + 1
                        force[j].append(f)
                    elif time[j] == t + 1:
                        force[j].append(f)
        return ''.join(ans)
```

#### Java

```java
class Solution {
    public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        Deque<Integer> q = new ArrayDeque<>();
        int[] time = new int[n];
        Arrays.fill(time, -1);
        List<Character>[] force = new List[n];
        for (int i = 0; i < n; ++i) {
            force[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; ++i) {
            char f = dominoes.charAt(i);
            if (f != '.') {
                q.offer(i);
                time[i] = 0;
                force[i].add(f);
            }
        }
        char[] ans = new char[n];
        Arrays.fill(ans, '.');
        while (!q.isEmpty()) {
            int i = q.poll();
            if (force[i].size() == 1) {
                ans[i] = force[i].get(0);
                char f = ans[i];
                int j = f == 'L' ? i - 1 : i + 1;
                if (j >= 0 && j < n) {
                    int t = time[i];
                    if (time[j] == -1) {
                        q.offer(j);
                        time[j] = t + 1;
                        force[j].add(f);
                    } else if (time[j] == t + 1) {
                        force[j].add(f);
                    }
                }
            }
        }
        return new String(ans);
    }
}
```

#### C++

```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        queue<int> q;
        vector<int> time(n, -1);
        vector<string> force(n);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') continue;
            q.emplace(i);
            time[i] = 0;
            force[i].push_back(dominoes[i]);
        }

        string ans(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                ans[i] = f;
                int j = (f == 'L') ? (i - 1) : (i + 1);
                if (j >= 0 && j < n) {
                    int t = time[i];
                    if (time[j] == -1) {
                        q.emplace(j);
                        time[j] = t + 1;
                        force[j].push_back(f);
                    } else if (time[j] == t + 1)
                        force[j].push_back(f);
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func pushDominoes(dominoes string) string {
	n := len(dominoes)
	q := []int{}
	time := make([]int, n)
	for i := range time {
		time[i] = -1
	}
	force := make([][]byte, n)
	for i, c := range dominoes {
		if c != '.' {
			q = append(q, i)
			time[i] = 0
			force[i] = append(force[i], byte(c))
		}
	}

	ans := bytes.Repeat([]byte{'.'}, n)
	for len(q) > 0 {
		i := q[0]
		q = q[1:]
		if len(force[i]) > 1 {
			continue
		}
		f := force[i][0]
		ans[i] = f
		j := i - 1
		if f == 'R' {
			j = i + 1
		}
		if 0 <= j && j < n {
			t := time[i]
			if time[j] == -1 {
				q = append(q, j)
				time[j] = t + 1
				force[j] = append(force[j], f)
			} else if time[j] == t+1 {
				force[j] = append(force[j], f)
			}
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function pushDominoes(dominoes: string): string {
    const n = dominoes.length;
    const q: number[] = [];
    const time: number[] = Array(n).fill(-1);
    const force: string[][] = Array.from({ length: n }, () => []);

    for (let i = 0; i < n; i++) {
        const f = dominoes[i];
        if (f !== '.') {
            q.push(i);
            time[i] = 0;
            force[i].push(f);
        }
    }

    const ans: string[] = Array(n).fill('.');
    let head = 0;
    while (head < q.length) {
        const i = q[head++];
        if (force[i].length === 1) {
            const f = force[i][0];
            ans[i] = f;
            const j = f === 'L' ? i - 1 : i + 1;
            if (j >= 0 && j < n) {
                const t = time[i];
                if (time[j] === -1) {
                    q.push(j);
                    time[j] = t + 1;
                    force[j].push(f);
                } else if (time[j] === t + 1) {
                    force[j].push(f);
                }
            }
        }
    }
    return ans.join('');
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [839. 相似字符串组](https://leetcode.cn/problems/similar-string-groups){#839}

{{< tabs "839" >}}

{{% tab "python" %}}
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
    def numSimilarGroups(self, strs: List[str]) -> int:
        n, m = len(strs), len(strs[0])
        uf = UnionFind(n)
        for i, s in enumerate(strs):
            for j, t in enumerate(strs[:i]):
                if sum(s[k] != t[k] for k in range(m)) <= 2 and uf.union(i, j):
                    n -= 1
        return n
```
{{% /tab %}}
{{% tab "java" %}}
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
    public int numSimilarGroups(String[] strs) {
        int n = strs.length, m = strs[0].length();
        UnionFind uf = new UnionFind(n);
        int cnt = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = 0;
                for (int k = 0; k < m; ++k) {
                    if (strs[i].charAt(k) != strs[j].charAt(k)) {
                        ++diff;
                    }
                }
                if (diff <= 2 && uf.union(i, j)) {
                    --cnt;
                }
            }
        }
        return cnt;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int cnt = n;
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = 0;
                for (int k = 0; k < m; ++k) {
                    diff += strs[i][k] != strs[j][k];
                }
                if (diff <= 2 && uf.unite(i, j)) {
                    --cnt;
                }
            }
        }
        return cnt;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
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

func numSimilarGroups(strs []string) int {
	n := len(strs)
	uf := newUnionFind(n)
	for i, s := range strs {
		for j, t := range strs[:i] {
			diff := 0
			for k := range s {
				if s[k] != t[k] {
					diff++
				}
			}
			if diff <= 2 && uf.union(i, j) {
				n--
			}
		}
	}
	return n
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
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

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }
}

function numSimilarGroups(strs: string[]): number {
    const n = strs.length;
    const m = strs[0].length;
    const uf = new UnionFind(n);
    let cnt = n;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            let diff = 0;
            for (let k = 0; k < m; ++k) {
                if (strs[i][k] !== strs[j][k]) {
                    diff++;
                }
            }
            if (diff <= 2 && uf.union(i, j)) {
                cnt--;
            }
        }
    }
    return cnt;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>如果交换字符串&nbsp;<code>X</code> 中的两个不同位置的字母，使得它和字符串&nbsp;<code>Y</code> 相等，那么称 <code>X</code> 和 <code>Y</code> 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。</p>

<p>例如，<code>"tars"</code> 和 <code>"rats"</code> 是相似的 (交换 <code>0</code> 与 <code>2</code> 的位置)；&nbsp;<code>"rats"</code> 和 <code>"arts"</code> 也是相似的，但是 <code>"star"</code> 不与 <code>"tars"</code>，<code>"rats"</code>，或 <code>"arts"</code> 相似。</p>

<p>总之，它们通过相似性形成了两个关联组：<code>{"tars", "rats", "arts"}</code> 和 <code>{"star"}</code>。注意，<code>"tars"</code> 和 <code>"arts"</code> 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。</p>

<p>给你一个字符串列表 <code>strs</code>。列表中的每个字符串都是 <code>strs</code> 中其它所有字符串的一个字母异位词。请问 <code>strs</code> 中有多少个相似字符串组？</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>strs = ["tars","rats","arts","star"]
<strong>输出：</strong>2
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>strs = ["omv","ovm"]
<strong>输出：</strong>1
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 300</code></li>
	<li><code>1 &lt;= strs[i].length &lt;= 300</code></li>
	<li><code>strs[i]</code> 只包含小写字母。</li>
	<li><code>strs</code> 中的所有单词都具有相同的长度，且是彼此的字母异位词。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：并查集

我们可以枚举字符串列表中的任意两个字符串 $s$ 和 $t$，由于 $s$ 和 $t$ 是字母异位词，因此如果 $s$ 和 $t$ 的对应位置字符不同的数量不超过 $2$，那么 $s$ 和 $t$ 是相似的，我们就可以使用并查集将 $s$ 和 $t$ 合并，如果合并成功，那么相似字符串组的数量减少 $1$。

最终相似字符串组的数量就是并查集中连通分量的数量。

时间复杂度 $O(n^2 \times (m + \alpha(n)))$，空间复杂度 $O(n)$。其中 $n$ 和 $m$ 分别是字符串列表的长度和字符串的长度，而 $\alpha(n)$ 是 Ackermann 函数的反函数，可以看成是一个很小的常数。

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
    def numSimilarGroups(self, strs: List[str]) -> int:
        n, m = len(strs), len(strs[0])
        uf = UnionFind(n)
        for i, s in enumerate(strs):
            for j, t in enumerate(strs[:i]):
                if sum(s[k] != t[k] for k in range(m)) <= 2 and uf.union(i, j):
                    n -= 1
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
    public int numSimilarGroups(String[] strs) {
        int n = strs.length, m = strs[0].length();
        UnionFind uf = new UnionFind(n);
        int cnt = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = 0;
                for (int k = 0; k < m; ++k) {
                    if (strs[i].charAt(k) != strs[j].charAt(k)) {
                        ++diff;
                    }
                }
                if (diff <= 2 && uf.union(i, j)) {
                    --cnt;
                }
            }
        }
        return cnt;
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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int cnt = n;
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = 0;
                for (int k = 0; k < m; ++k) {
                    diff += strs[i][k] != strs[j][k];
                }
                if (diff <= 2 && uf.unite(i, j)) {
                    --cnt;
                }
            }
        }
        return cnt;
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

func numSimilarGroups(strs []string) int {
	n := len(strs)
	uf := newUnionFind(n)
	for i, s := range strs {
		for j, t := range strs[:i] {
			diff := 0
			for k := range s {
				if s[k] != t[k] {
					diff++
				}
			}
			if diff <= 2 && uf.union(i, j) {
				n--
			}
		}
	}
	return n
}
```

#### TypeScript

```ts
class UnionFind {
    private p: number[];
    private size: number[];

    constructor(n: number) {
        this.p = Array.from({ length: n }, (_, i) => i);
        this.size = Array(n).fill(1);
    }

    union(a: number, b: number): boolean {
        const pa = this.find(a);
        const pb = this.find(b);
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

    find(x: number): number {
        if (this.p[x] !== x) {
            this.p[x] = this.find(this.p[x]);
        }
        return this.p[x];
    }
}

function numSimilarGroups(strs: string[]): number {
    const n = strs.length;
    const m = strs[0].length;
    const uf = new UnionFind(n);
    let cnt = n;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < i; ++j) {
            let diff = 0;
            for (let k = 0; k < m; ++k) {
                if (strs[i][k] !== strs[j][k]) {
                    diff++;
                }
            }
            if (diff <= 2 && uf.union(i, j)) {
                cnt--;
            }
        }
    }
    return cnt;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}
