---
title: "0752_OpentheLock"
date: 2025-10-06T00:42:37+08:00
weight: 0752
tags: [Breadth-First Search, Array, Hash Table, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [752. Open the Lock](https://leetcode.com/problems/open-the-lock)

[中文文档](/solution/0700-0799/0752.Open%20the%20Lock/README.md)

## Description

<!-- description:start -->

<p>You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: <code>&#39;0&#39;, &#39;1&#39;, &#39;2&#39;, &#39;3&#39;, &#39;4&#39;, &#39;5&#39;, &#39;6&#39;, &#39;7&#39;, &#39;8&#39;, &#39;9&#39;</code>. The wheels can rotate freely and wrap around: for example we can turn <code>&#39;9&#39;</code> to be <code>&#39;0&#39;</code>, or <code>&#39;0&#39;</code> to be <code>&#39;9&#39;</code>. Each move consists of turning one wheel one slot.</p>

<p>The lock initially starts at <code>&#39;0000&#39;</code>, a string representing the state of the 4 wheels.</p>

<p>You are given a list of <code>deadends</code> dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.</p>

<p>Given a <code>target</code> representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> deadends = [&quot;0201&quot;,&quot;0101&quot;,&quot;0102&quot;,&quot;1212&quot;,&quot;2002&quot;], target = &quot;0202&quot;
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
A sequence of valid moves would be &quot;0000&quot; -&gt; &quot;1000&quot; -&gt; &quot;1100&quot; -&gt; &quot;1200&quot; -&gt; &quot;1201&quot; -&gt; &quot;1202&quot; -&gt; &quot;0202&quot;.
Note that a sequence like &quot;0000&quot; -&gt; &quot;0001&quot; -&gt; &quot;0002&quot; -&gt; &quot;0102&quot; -&gt; &quot;0202&quot; would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end &quot;0102&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> deadends = [&quot;8888&quot;], target = &quot;0009&quot;
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can turn the last wheel in reverse to move from &quot;0000&quot; -&gt; &quot;0009&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> deadends = [&quot;8887&quot;,&quot;8889&quot;,&quot;8878&quot;,&quot;8898&quot;,&quot;8788&quot;,&quot;8988&quot;,&quot;7888&quot;,&quot;9888&quot;], target = &quot;8888&quot;
<strong>Output:</strong> -1
<strong>Explanation:</strong> We cannot reach the target without getting stuck.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= deadends.length &lt;= 500</code></li>
	<li><code>deadends[i].length == 4</code></li>
	<li><code>target.length == 4</code></li>
	<li>target <strong>will not be</strong> in the list <code>deadends</code>.</li>
	<li><code>target</code> and <code>deadends[i]</code> consist of digits only.</li>
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



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 2

<!-- tabs:start -->

#### Python3



#### Java



#### C++



#### Go



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### Solution 3

<!-- tabs:start -->

#### Python3



#### Java



#### C++



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def next(s):
            res = []
            s = list(s)
            for i in range(4):
                c = s[i]
                s[i] = '9' if c == '0' else str(int(c) - 1)
                res.append(''.join(s))
                s[i] = '0' if c == '9' else str(int(c) + 1)
                res.append(''.join(s))
                s[i] = c
            return res

        def f(s):
            ans = 0
            for i in range(4):
                a = ord(s[i]) - ord('0')
                b = ord(target[i]) - ord('0')
                if a > b:
                    a, b = b, a
                ans += min(b - a, a + 10 - b)
            return ans

        if target == '0000':
            return 0
        s = set(deadends)
        if '0000' in s:
            return -1
        start = '0000'
        q = [(f(start), start)]
        dist = {start: 0}
        while q:
            _, state = heappop(q)
            if state == target:
                return dist[state]
            for t in next(state):
                if t in s:
                    continue
                if t not in dist or dist[t] > dist[state] + 1:
                    dist[t] = dist[state] + 1
                    heappush(q, (dist[t] + f(t), t))
        return -1
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    private String target;

    public int openLock(String[] deadends, String target) {
        if ("0000".equals(target)) {
            return 0;
        }
        String start = "0000";
        this.target = target;
        Set<String> s = new HashSet<>();
        for (String d : deadends) {
            s.add(d);
        }
        if (s.contains(start)) {
            return -1;
        }
        PriorityQueue<Pair<Integer, String>> q
            = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
        q.offer(new Pair<>(f(start), start));
        Map<String, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        while (!q.isEmpty()) {
            String state = q.poll().getValue();
            int step = dist.get(state);
            if (target.equals(state)) {
                return step;
            }
            for (String t : next(state)) {
                if (s.contains(t)) {
                    continue;
                }
                if (!dist.containsKey(t) || dist.get(t) > step + 1) {
                    dist.put(t, step + 1);
                    q.offer(new Pair<>(step + 1 + f(t), t));
                }
            }
        }
        return -1;
    }

    private int f(String s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s.charAt(i) - '0';
            int b = target.charAt(i) - '0';
            if (a > b) {
                int t = a;
                a = b;
                b = a;
            }
            ans += Math.min(b - a, a + 10 - b);
        }
        return ans;
    }

    private List<String> next(String t) {
        List res = new ArrayList<>();
        char[] chars = t.toCharArray();
        for (int i = 0; i < 4; ++i) {
            char c = chars[i];
            chars[i] = c == '0' ? '9' : (char) (c - 1);
            res.add(String.valueOf(chars));
            chars[i] = c == '9' ? '0' : (char) (c + 1);
            res.add(String.valueOf(chars));
            chars[i] = c;
        }
        return res;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    string target;

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> s(deadends.begin(), deadends.end());
        if (s.count("0000")) return -1;
        string start = "0000";
        this->target = target;
        typedef pair<int, string> PIS;
        priority_queue<PIS, vector<PIS>, greater<PIS>> q;
        unordered_map<string, int> dist;
        dist[start] = 0;
        q.push({f(start), start});
        while (!q.empty()) {
            PIS t = q.top();
            q.pop();
            string state = t.second;
            int step = dist[state];
            if (state == target) return step;
            for (string& t : next(state)) {
                if (s.count(t)) continue;
                if (!dist.count(t) || dist[t] > step + 1) {
                    dist[t] = step + 1;
                    q.push({step + 1 + f(t), t});
                }
            }
        }
        return -1;
    }

    int f(string s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s[i] - '0';
            int b = target[i] - '0';
            if (a < b) {
                int t = a;
                a = b;
                b = t;
            }
            ans += min(b - a, a + 10 - b);
        }
        return ans;
    }

    vector<string> next(string& t) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            char c = t[i];
            t[i] = c == '0' ? '9' : (char) (c - 1);
            res.push_back(t);
            t[i] = c == '9' ? '0' : (char) (c + 1);
            res.push_back(t);
            t[i] = c;
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func openLock(deadends []string, target string) int {
	if target == "0000" {
		return 0
	}
	s := make(map[string]bool)
	for _, d := range deadends {
		s[d] = true
	}
	if s["0000"] {
		return -1
	}
	next := func(t string) []string {
		s := []byte(t)
		var res []string
		for i, b := range s {
			s[i] = b - 1
			if s[i] < '0' {
				s[i] = '9'
			}
			res = append(res, string(s))
			s[i] = b + 1
			if s[i] > '9' {
				s[i] = '0'
			}
			res = append(res, string(s))
			s[i] = b
		}
		return res
	}

	extend := func(m1, m2 map[string]int, q *[]string) int {
		for n := len(*q); n > 0; n-- {
			p := (*q)[0]
			*q = (*q)[1:]
			step, _ := m1[p]
			for _, t := range next(p) {
				if s[t] {
					continue
				}
				if _, ok := m1[t]; ok {
					continue
				}
				if v, ok := m2[t]; ok {
					return step + 1 + v
				}
				m1[t] = step + 1
				*q = append(*q, t)
			}
		}
		return -1
	}

	bfs := func() int {
		q1 := []string{"0000"}
		q2 := []string{target}
		m1 := map[string]int{"0000": 0}
		m2 := map[string]int{target: 0}
		for len(q1) > 0 && len(q2) > 0 {
			t := -1
			if len(q1) <= len(q2) {
				t = extend(m1, m2, &q1)
			} else {
				t = extend(m2, m1, &q2)
			}
			if t != -1 {
				return t
			}
		}
		return -1
	}

	return bfs()
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function openLock(deadends: string[], target: string): number {
    const vis = Array<boolean>(10_000);
    const q = [[0, 0, 0, 0, 0]];
    const t = +target;
    deadends.forEach(s => (vis[+s] = true));

    for (const [a, b, c, d, ans] of q) {
        const key = a * 1000 + b * 100 + c * 10 + d;
        if (vis[key]) {
            continue;
        }

        vis[key] = true;
        if (key === t) {
            return ans;
        }

        for (let i = 0; i < 4; i++) {
            const next = [a, b, c, d, ans + 1];
            const prev = [a, b, c, d, ans + 1];
            next[i] = (next[i] + 11) % 10;
            prev[i] = (prev[i] + 9) % 10;
            q.push(prev, next);
        }
    }

    return -1;
}
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        def next(s):
            res = []
            s = list(s)
            for i in range(4):
                c = s[i]
                s[i] = '9' if c == '0' else str(int(c) - 1)
                res.append(''.join(s))
                s[i] = '0' if c == '9' else str(int(c) + 1)
                res.append(''.join(s))
                s[i] = c
            return res

        def f(s):
            ans = 0
            for i in range(4):
                a = ord(s[i]) - ord('0')
                b = ord(target[i]) - ord('0')
                if a > b:
                    a, b = b, a
                ans += min(b - a, a + 10 - b)
            return ans

        if target == '0000':
            return 0
        s = set(deadends)
        if '0000' in s:
            return -1
        start = '0000'
        q = [(f(start), start)]
        dist = {start: 0}
        while q:
            _, state = heappop(q)
            if state == target:
                return dist[state]
            for t in next(state):
                if t in s:
                    continue
                if t not in dist or dist[t] > dist[state] + 1:
                    dist[t] = dist[state] + 1
                    heappush(q, (dist[t] + f(t), t))
        return -1
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Solution {
    private String target;

    public int openLock(String[] deadends, String target) {
        if ("0000".equals(target)) {
            return 0;
        }
        String start = "0000";
        this.target = target;
        Set<String> s = new HashSet<>();
        for (String d : deadends) {
            s.add(d);
        }
        if (s.contains(start)) {
            return -1;
        }
        PriorityQueue<Pair<Integer, String>> q
            = new PriorityQueue<>(Comparator.comparingInt(Pair::getKey));
        q.offer(new Pair<>(f(start), start));
        Map<String, Integer> dist = new HashMap<>();
        dist.put(start, 0);
        while (!q.isEmpty()) {
            String state = q.poll().getValue();
            int step = dist.get(state);
            if (target.equals(state)) {
                return step;
            }
            for (String t : next(state)) {
                if (s.contains(t)) {
                    continue;
                }
                if (!dist.containsKey(t) || dist.get(t) > step + 1) {
                    dist.put(t, step + 1);
                    q.offer(new Pair<>(step + 1 + f(t), t));
                }
            }
        }
        return -1;
    }

    private int f(String s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s.charAt(i) - '0';
            int b = target.charAt(i) - '0';
            if (a > b) {
                int t = a;
                a = b;
                b = a;
            }
            ans += Math.min(b - a, a + 10 - b);
        }
        return ans;
    }

    private List<String> next(String t) {
        List res = new ArrayList<>();
        char[] chars = t.toCharArray();
        for (int i = 0; i < 4; ++i) {
            char c = chars[i];
            chars[i] = c == '0' ? '9' : (char) (c - 1);
            res.add(String.valueOf(chars));
            chars[i] = c == '9' ? '0' : (char) (c + 1);
            res.add(String.valueOf(chars));
            chars[i] = c;
        }
        return res;
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
    string target;

    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> s(deadends.begin(), deadends.end());
        if (s.count("0000")) return -1;
        string start = "0000";
        this->target = target;
        typedef pair<int, string> PIS;
        priority_queue<PIS, vector<PIS>, greater<PIS>> q;
        unordered_map<string, int> dist;
        dist[start] = 0;
        q.push({f(start), start});
        while (!q.empty()) {
            PIS t = q.top();
            q.pop();
            string state = t.second;
            int step = dist[state];
            if (state == target) return step;
            for (string& t : next(state)) {
                if (s.count(t)) continue;
                if (!dist.count(t) || dist[t] > step + 1) {
                    dist[t] = step + 1;
                    q.push({step + 1 + f(t), t});
                }
            }
        }
        return -1;
    }

    int f(string s) {
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int a = s[i] - '0';
            int b = target[i] - '0';
            if (a < b) {
                int t = a;
                a = b;
                b = t;
            }
            ans += min(b - a, a + 10 - b);
        }
        return ans;
    }

    vector<string> next(string& t) {
        vector<string> res;
        for (int i = 0; i < 4; ++i) {
            char c = t[i];
            t[i] = c == '0' ? '9' : (char) (c - 1);
            res.push_back(t);
            t[i] = c == '9' ? '0' : (char) (c + 1);
            res.push_back(t);
            t[i] = c;
        }
        return res;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}