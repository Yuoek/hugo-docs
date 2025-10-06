---
title: "1528_ShuffleString"
date: 2025-10-06T00:42:37+08:00
weight: 1528
tags: [数组, 字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1528. 重新排列字符串](https://leetcode.cn/problems/shuffle-string)

[English Version](../en/1528-28/1528_ShuffleString)

## 题目描述

<!-- description:start -->

<p>给你一个字符串 <code>s</code> 和一个 <strong>长度相同</strong> 的整数数组 <code>indices</code> 。</p>

<p>请你重新排列字符串 <code>s</code> ，其中第 <code>i</code> 个字符需要移动到 <code>indices[i]</code> 指示的位置。</p>

<p>返回重新排列后的字符串。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1528.Shuffle%20String/images/q1.jpg" /></p>

<pre>
<strong>输入：</strong>s = "codeleet", <code>indices</code> = [4,5,6,7,0,2,1,3]
<strong>输出：</strong>"leetcode"
<strong>解释：</strong>如图所示，"codeleet" 重新排列后变为 "leetcode" 。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入：</strong>s = "abc", <code>indices</code> = [0,1,2]
<strong>输出：</strong>"abc"
<strong>解释：</strong>重新排列后，每个字符都还留在原来的位置上。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>s.length == indices.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>s</code> 仅包含小写英文字母</li>
	<li><code>0 &lt;= indices[i] &lt;&nbsp;n</code></li>
	<li><code>indices</code> 的所有的值都是 <strong>唯一</strong> 的</li>
</ul>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### JavaScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ans = [0] * len(s)
        for i, c in enumerate(s):
            ans[indices[i]] = c
        return ''.join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String restoreString(String s, int[] indices) {
        int n = s.length();
        char[] ans = new char[n];
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s.charAt(i);
        }
        return String.valueOf(ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func restoreString(s string, indices []int) string {
	ans := make([]rune, len(s))
	for i, c := range s {
		ans[indices[i]] = c
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "js" %}}
```js
/**
 * @param {string} s
 * @param {number[]} indices
 * @return {string}
 */
var restoreString = function (s, indices) {
    let rs = [];
    for (let i = 0; i < s.length; i++) {
        rs[indices[i]] = s[i];
    }
    return rs.join('');
};
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        ans = [0] * len(s)
        for i, c in enumerate(s):
            ans[indices[i]] = c
        return ''.join(ans)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    public String restoreString(String s, int[] indices) {
        int n = s.length();
        char[] ans = new char[n];
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s.charAt(i);
        }
        return String.valueOf(ans);
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
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, 0);
        for (int i = 0; i < n; ++i) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}