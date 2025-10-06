---
title: "0831_MaskingPersonalInformation"
date: 2025-10-06T00:42:37+08:00
weight: 0831
tags: [字符串]
---


{{< katex />}}

{{< badge title="Difficulty" value="中等" >}}

<!-- problem:start -->

# [831. 隐藏个人信息](https://leetcode.cn/problems/masking-personal-information)

[English Version](../en/0831-31/0831_MaskingPersonalInformation)

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

## 解法

<!-- solution:start -->

### 方法一：模拟

根据题目描述，我们可以先判断字符串 $s$ 是电子邮件还是电话号码，然后分别处理。

时间复杂度为 $O(n)$，空间复杂度为 $O(n)$。其中 $n$ 为字符串 $s$ 的长度。

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
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
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def maskPII(self, s: str) -> str:
        if s[0].isalpha():
            s = s.lower()
            return s[0] + '*****' + s[s.find('@') - 1 :]
        s = ''.join(c for c in s if c.isdigit())
        cnt = len(s) - 10
        suf = '***-***-' + s[-4:]
        return suf if cnt == 0 else f'+{"*" * cnt}-{suf}'
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}