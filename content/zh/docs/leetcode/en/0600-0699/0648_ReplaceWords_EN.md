---
title: "0648_ReplaceWords"
date: 2025-10-06T00:42:37+08:00
weight: 0648
tags: [Trie, Array, Hash Table, String]
---


{{< katex />}}

{{< badge title="Difficulty" value="Medium" >}}

<!-- problem:start -->

# [648. Replace Words](https://leetcode.com/problems/replace-words)

[中文文档](/solution/0600-0699/0648.Replace%20Words/README.md)

## Description

<!-- description:start -->

<p>In English, we have a concept called <strong>root</strong>, which can be followed by some other word to form another longer word - let&#39;s call this word <strong>derivative</strong>. For example, when the <strong>root</strong> <code>&quot;help&quot;</code> is followed by the word <code>&quot;ful&quot;</code>, we can form a derivative <code>&quot;helpful&quot;</code>.</p>

<p>Given a <code>dictionary</code> consisting of many <strong>roots</strong> and a <code>sentence</code> consisting of words separated by spaces, replace all the derivatives in the sentence with the <strong>root</strong> forming it. If a derivative can be replaced by more than one <strong>root</strong>, replace it with the <strong>root</strong> that has <strong>the shortest length</strong>.</p>

<p>Return <em>the <code>sentence</code></em> after the replacement.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> dictionary = [&quot;cat&quot;,&quot;bat&quot;,&quot;rat&quot;], sentence = &quot;the cattle was rattled by the battery&quot;
<strong>Output:</strong> &quot;the cat was rat by the bat&quot;
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> dictionary = [&quot;a&quot;,&quot;b&quot;,&quot;c&quot;], sentence = &quot;aadsfasf absbs bbab cadsfafs&quot;
<strong>Output:</strong> &quot;a a b c&quot;
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= dictionary.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 100</code></li>
	<li><code>dictionary[i]</code> consists of only lower-case letters.</li>
	<li><code>1 &lt;= sentence.length &lt;= 10<sup>6</sup></code></li>
	<li><code>sentence</code> consists of only lower-case letters and spaces.</li>
	<li>The number of words in <code>sentence</code> is in the range <code>[1, 1000]</code></li>
	<li>The length of each word in <code>sentence</code> is in the range <code>[1, 1000]</code></li>
	<li>Every two consecutive words in <code>sentence</code> will be separated by exactly one space.</li>
	<li><code>sentence</code> does not have leading or trailing spaces.</li>
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

#### Java



#### TypeScript



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.ref: int = -1

    def insert(self, w: str, i: int):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.ref = i

    def search(self, w: str) -> int:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return -1
            node = node.children[idx]
            if node.ref != -1:
                return node.ref
        return -1


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for i, w in enumerate(dictionary):
            trie.insert(w, i)
        ans = []
        for w in sentence.split():
            idx = trie.search(w)
            ans.append(dictionary[idx] if idx != -1 else w)
        return " ".join(ans)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Trie {
    private Trie[] children = new Trie[26];
    private int ref = -1;

    public void insert(String w, int i) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.ref = i;
    }

    public int search(String w) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                return -1;
            }
            node = node.children[idx];
            if (node.ref != -1) {
                return node.ref;
            }
        }
        return -1;
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie.insert(dictionary.get(i), i);
        }
        List<String> ans = new ArrayList<>();
        for (String w : sentence.split("\\s")) {
            int idx = trie.search(w);
            ans.add(idx == -1 ? w : dictionary.get(idx));
        }
        return String.join(" ", ans);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Trie {
private:
    Trie* children[26];
    int ref;

public:
    Trie()
        : ref(-1) {
        memset(children, 0, sizeof(children));
    }

    void insert(const string& w, int i) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->ref = i;
    }

    int search(const string& w) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return -1;
            }
            node = node->children[idx];
            if (node->ref != -1) {
                return node->ref;
            }
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie->insert(dictionary[i], i);
        }
        stringstream ss(sentence);
        string w;
        string ans;
        while (ss >> w) {
            int idx = trie->search(w);
            ans += (idx == -1 ? w : dictionary[idx]) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Trie struct {
	children [26]*Trie
	ref      int
}

func newTrie() *Trie {
	return &Trie{ref: -1}
}

func (this *Trie) insert(w string, i int) {
	node := this
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			node.children[idx] = newTrie()
		}
		node = node.children[idx]
	}
	node.ref = i
}

func (this *Trie) search(w string) int {
	node := this
	for _, c := range w {
		idx := c - 'a'
		if node.children[idx] == nil {
			return -1
		}
		node = node.children[idx]
		if node.ref != -1 {
			return node.ref
		}
	}
	return -1
}

func replaceWords(dictionary []string, sentence string) string {
	trie := newTrie()
	for i, w := range dictionary {
		trie.insert(w, i)
	}
	ans := strings.Builder{}
	for _, w := range strings.Split(sentence, " ") {
		if idx := trie.search(w); idx != -1 {
			ans.WriteString(dictionary[idx])
		} else {
			ans.WriteString(w)
		}
		ans.WriteByte(' ')
	}
	return ans.String()[:ans.Len()-1]
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function replaceWords(dictionary: string[], sentence: string): string {
    const words = sentence.split(' ');
    const trie: Trie = {};
    const TERMINAL_MARK = 'TERMINAL_MARK';

    for (const s of dictionary) {
        let t = trie;

        for (const ch of s) {
            t[ch] ??= {};
            t = t[ch] as Trie_;
        }
        t[TERMINAL_MARK] = TERMINAL_MARK;
    }

    for (let i = 0; i < words.length; i++) {
        const s = words[i];
        let t = trie;

        for (let j = 0; j < s.length; j++) {
            const ch = s[j];

            if (!t[ch]) break;

            if ((t[ch] as Trie_)[TERMINAL_MARK]) {
                words[i] = s.slice(0, j + 1);
                break;
            }
            t = t[ch] as Trie_;
        }
    }

    return words.join(' ');
}

// prettier-ignore
type Trie = { [key: string]: Trie} | string
type Trie_ = Exclude<Trie, string>;
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
class Trie:
    def __init__(self):
        self.children: List[Trie | None] = [None] * 26
        self.ref: int = -1

    def insert(self, w: str, i: int):
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                node.children[idx] = Trie()
            node = node.children[idx]
        node.ref = i

    def search(self, w: str) -> int:
        node = self
        for c in w:
            idx = ord(c) - ord("a")
            if node.children[idx] is None:
                return -1
            node = node.children[idx]
            if node.ref != -1:
                return node.ref
        return -1


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        trie = Trie()
        for i, w in enumerate(dictionary):
            trie.insert(w, i)
        ans = []
        for w in sentence.split():
            idx = trie.search(w)
            ans.append(dictionary[idx] if idx != -1 else w)
        return " ".join(ans)
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "java 可视化" %}}
{{< pythontutor width="100%" height="800" language="java" >}}
class Trie {
    private Trie[] children = new Trie[26];
    private int ref = -1;

    public void insert(String w, int i) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                node.children[idx] = new Trie();
            }
            node = node.children[idx];
        }
        node.ref = i;
    }

    public int search(String w) {
        Trie node = this;
        for (int j = 0; j < w.length(); ++j) {
            int idx = w.charAt(j) - 'a';
            if (node.children[idx] == null) {
                return -1;
            }
            node = node.children[idx];
            if (node.ref != -1) {
                return node.ref;
            }
        }
        return -1;
    }
}

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie.insert(dictionary.get(i), i);
        }
        List<String> ans = new ArrayList<>();
        for (String w : sentence.split("\\s")) {
            int idx = trie.search(w);
            ans.add(idx == -1 ? w : dictionary.get(idx));
        }
        return String.join(" ", ans);
    }
}
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "cpp 可视化" %}}
{{< pythontutor width="100%" height="800" language="cpp" >}}
class Trie {
private:
    Trie* children[26];
    int ref;

public:
    Trie()
        : ref(-1) {
        memset(children, 0, sizeof(children));
    }

    void insert(const string& w, int i) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new Trie();
            }
            node = node->children[idx];
        }
        node->ref = i;
    }

    int search(const string& w) {
        Trie* node = this;
        for (auto& c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return -1;
            }
            node = node->children[idx];
            if (node->ref != -1) {
                return node->ref;
            }
        }
        return -1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        for (int i = 0; i < dictionary.size(); ++i) {
            trie->insert(dictionary[i], i);
        }
        stringstream ss(sentence);
        string w;
        string ans;
        while (ss >> w) {
            int idx = trie->search(w);
            ans += (idx == -1 ? w : dictionary[idx]) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}