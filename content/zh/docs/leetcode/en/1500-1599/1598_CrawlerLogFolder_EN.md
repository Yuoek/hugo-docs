---
title: "1598_CrawlerLogFolder"
date: 2025-10-06T00:42:37+08:00
weight: 1598
tags: [Stack, Array, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Easy" >}}

<!-- problem:start -->

# [1598. Crawler Log Folder](https://leetcode.com/problems/crawler-log-folder)

[中文文档](/solution/1500-1599/1598.Crawler%20Log%20Folder/README.md)

## Description

<!-- description:start -->

<p>The Leetcode file system keeps a log each time some user performs a <em>change folder</em> operation.</p>

<p>The operations are described below:</p>

<ul>
	<li><code>&quot;../&quot;</code> : Move to the parent folder of the current folder. (If you are already in the main folder, <strong>remain in the same folder</strong>).</li>
	<li><code>&quot;./&quot;</code> : Remain in the same folder.</li>
	<li><code>&quot;x/&quot;</code> : Move to the child folder named <code>x</code> (This folder is <strong>guaranteed to always exist</strong>).</li>
</ul>

<p>You are given a list of strings <code>logs</code> where <code>logs[i]</code> is the operation performed by the user at the <code>i<sup>th</sup></code> step.</p>

<p>The file system starts in the main folder, then the operations in <code>logs</code> are performed.</p>

<p>Return <em>the minimum number of operations needed to go back to the main folder after the change folder operations.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1598.Crawler%20Log%20Folder/images/sample_11_1957.png" style="width: 775px; height: 151px;" /></p>

<pre>
<strong>Input:</strong> logs = [&quot;d1/&quot;,&quot;d2/&quot;,&quot;../&quot;,&quot;d21/&quot;,&quot;./&quot;]
<strong>Output:</strong> 2
<strong>Explanation: </strong>Use this change folder operation &quot;../&quot; 2 times and go back to the main folder.
</pre>

<p><strong class="example">Example 2:</strong></p>

<p><img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/1500-1599/1598.Crawler%20Log%20Folder/images/sample_22_1957.png" style="width: 600px; height: 270px;" /></p>

<pre>
<strong>Input:</strong> logs = [&quot;d1/&quot;,&quot;d2/&quot;,&quot;./&quot;,&quot;d3/&quot;,&quot;../&quot;,&quot;d31/&quot;]
<strong>Output:</strong> 3
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> logs = [&quot;d1/&quot;,&quot;../&quot;,&quot;../&quot;,&quot;../&quot;]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= logs.length &lt;= 10<sup>3</sup></code></li>
	<li><code>2 &lt;= logs[i].length &lt;= 10</code></li>
	<li><code>logs[i]</code> contains lowercase English letters, digits, <code>&#39;.&#39;</code>, and <code>&#39;/&#39;</code>.</li>
	<li><code>logs[i]</code> follows the format described in the statement.</li>
	<li>Folder names consist of lowercase English letters and digits.</li>
</ul>

<!-- description:end -->

## Solutions

<!-- solution:start -->

### Solution 1

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



#### TypeScript



#### JavaScript



#### Rust



#### C



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
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
{{% /tab %}}
{{% tab "js" %}}
```js
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
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def minOperations(self, logs: List[str]) -> int:
        ans = 0
        for v in logs:
            if v == "../":
                ans = max(0, ans - 1)
            elif v[0] != ".":
                ans += 1
        return ans
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "c 可视化" %}}
{{< pythontutor width="100%" height="800" language="c" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
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
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}