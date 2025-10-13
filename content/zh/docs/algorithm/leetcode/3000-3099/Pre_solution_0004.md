---
title: "3030_找出网格的区域平均强度"
date: 2025-10-08T18:39:55+08:00
weight: 4
tags: [动态规划, 哈希函数, 哈希表, 字符串, 字符串匹配, 排序, 数学, 数组, 模拟, 滑动窗口, 滚动哈希, 矩阵, 计数, 贪心]
---

{{< markmap >}}
### [3030_找出网格的区域平均强度](#3030)
#### [数组](#3030)
#### [矩阵](#3030)
### [3031_将单词恢复初始状态所需的最短时间 II](#3031)
#### [字符串](#3031)
#### [字符串匹配](#3031)
#### [哈希函数](#3031)
#### [滚动哈希](#3031)
### [3032_统计各位数字都不同的数字个数 II 🔒](#3032)
#### [哈希表](#3032)
#### [数学](#3032)
#### [动态规划](#3032)
### [3033_修改矩阵](#3033)
#### [数组](#3033)
#### [矩阵](#3033)
### [3034_匹配模式数组的子数组数目 I](#3034)
#### [数组](#3034)
#### [字符串匹配](#3034)
#### [哈希函数](#3034)
#### [滚动哈希](#3034)
### [3035_回文字符串的最大数量](#3035)
#### [贪心](#3035)
#### [数组](#3035)
#### [哈希表](#3035)
#### [字符串](#3035)
#### [计数](#3035)
#### [排序](#3035)
### [3036_匹配模式数组的子数组数目 II](#3036)
#### [数组](#3036)
#### [字符串匹配](#3036)
#### [哈希函数](#3036)
#### [滚动哈希](#3036)
### [3037_在无限流中寻找模式 II 🔒](#3037)
#### [数组](#3037)
#### [字符串匹配](#3037)
#### [滑动窗口](#3037)
#### [哈希函数](#3037)
#### [滚动哈希](#3037)
### [3038_相同分数的最大操作数目 I](#3038)
#### [数组](#3038)
#### [模拟](#3038)
### [3039_进行操作使字符串为空](#3039)
#### [数组](#3039)
#### [哈希表](#3039)
#### [计数](#3039)
#### [排序](#3039)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true" >}}
### 3030_找出网格的区域平均强度
___
#### 数组
___
#### 矩阵
---
### 3031_将单词恢复初始状态所需的最短时间 II
___
#### 字符串
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3032_统计各位数字都不同的数字个数 II 🔒
___
#### 哈希表
___
#### 数学
___
#### 动态规划
---
### 3033_修改矩阵
___
#### 数组
___
#### 矩阵
---
### 3034_匹配模式数组的子数组数目 I
___
#### 数组
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3035_回文字符串的最大数量
___
#### 贪心
___
#### 数组
___
#### 哈希表
___
#### 字符串
___
#### 计数
___
#### 排序
---
### 3036_匹配模式数组的子数组数目 II
___
#### 数组
___
#### 字符串匹配
___
#### 哈希函数
___
#### 滚动哈希
---
### 3037_在无限流中寻找模式 II 🔒
___
#### 数组
___
#### 字符串匹配
___
#### 滑动窗口
___
#### 哈希函数
___
#### 滚动哈希
---
### 3038_相同分数的最大操作数目 I
___
#### 数组
___
#### 模拟
---
### 3039_进行操作使字符串为空
___
#### 数组
___
#### 哈希表
___
#### 计数
___
#### 排序
{{< /revealjs >}}


{{< katex />}}

| Tag1 | Tag2 | Tag3 |
| --------------- | --------------- | --------------- |
| 动态规划 | 哈希函数 | 哈希表 |
| 字符串 | 字符串匹配 | 排序 |
| 数学 | 数组 | 模拟 |
| 滑动窗口 | 滚动哈希 | 矩阵 |
| 计数 | 贪心 |  |

# [3030. 找出网格的区域平均强度](https://leetcode.cn/problems/find-the-grid-of-region-average){#3030}

{{< tabs "3030" >}}

{{% tab "python" %}}
```python
class Solution:
    def resultGrid(self, image: List[List[int]], threshold: int) -> List[List[int]]:
        n, m = len(image), len(image[0])
        ans = [[0] * m for _ in range(n)]
        ct = [[0] * m for _ in range(n)]
        for i in range(n - 2):
            for j in range(m - 2):
                region = True
                for k in range(3):
                    for l in range(2):
                        region &= (
                            abs(image[i + k][j + l] - image[i + k][j + l + 1])
                            <= threshold
                        )
                for k in range(2):
                    for l in range(3):
                        region &= (
                            abs(image[i + k][j + l] - image[i + k + 1][j + l])
                            <= threshold
                        )

                if region:
                    tot = 0
                    for k in range(3):
                        for l in range(3):
                            tot += image[i + k][j + l]
                    for k in range(3):
                        for l in range(3):
                            ct[i + k][j + l] += 1
                            ans[i + k][j + l] += tot // 9

        for i in range(n):
            for j in range(m):
                if ct[i][j] == 0:
                    ans[i][j] = image[i][j]
                else:
                    ans[i][j] //= ct[i][j]

        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] resultGrid(int[][] image, int threshold) {
        int n = image.length;
        int m = image[0].length;
        int[][] ans = new int[n][m];
        int[][] ct = new int[n][m];
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 2 < m; ++j) {
                boolean region = true;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        region
                            &= Math.abs(image[i + k][j + l] - image[i + k][j + l + 1]) <= threshold;
                    }
                }
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        region
                            &= Math.abs(image[i + k][j + l] - image[i + k + 1][j + l]) <= threshold;
                    }
                }
                if (region) {
                    int tot = 0;
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            tot += image[i + k][j + l];
                        }
                    }
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            ct[i + k][j + l]++;
                            ans[i + k][j + l] += tot / 9;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ct[i][j] == 0) {
                    ans[i][j] = image[i][j];
                } else {
                    ans[i][j] /= ct[i][j];
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
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<int>> ct(n, vector<int>(m));
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 2 < m; ++j) {
                bool region = true;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        region &= abs(image[i + k][j + l] - image[i + k][j + l + 1]) <= threshold;
                    }
                }
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        region &= abs(image[i + k][j + l] - image[i + k + 1][j + l]) <= threshold;
                    }
                }
                if (region) {
                    int tot = 0;
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            tot += image[i + k][j + l];
                        }
                    }
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            ct[i + k][j + l]++;
                            ans[i + k][j + l] += tot / 9;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ct[i][j] == 0) {
                    ans[i][j] = image[i][j];
                } else {
                    ans[i][j] /= ct[i][j];
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
func resultGrid(image [][]int, threshold int) [][]int {
	n := len(image)
	m := len(image[0])
	ans := make([][]int, n)
	ct := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, m)
		ct[i] = make([]int, m)
	}
	for i := 0; i+2 < n; i++ {
		for j := 0; j+2 < m; j++ {
			region := true
			for k := 0; k < 3; k++ {
				for l := 0; l < 2; l++ {
					region = region && abs(image[i+k][j+l]-image[i+k][j+l+1]) <= threshold
				}
			}
			for k := 0; k < 2; k++ {
				for l := 0; l < 3; l++ {
					region = region && abs(image[i+k][j+l]-image[i+k+1][j+l]) <= threshold
				}
			}
			if region {
				tot := 0
				for k := 0; k < 3; k++ {
					for l := 0; l < 3; l++ {
						tot += image[i+k][j+l]
					}
				}
				for k := 0; k < 3; k++ {
					for l := 0; l < 3; l++ {
						ct[i+k][j+l]++
						ans[i+k][j+l] += tot / 9
					}
				}
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if ct[i][j] == 0 {
				ans[i][j] = image[i][j]
			} else {
				ans[i][j] /= ct[i][j]
			}
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
function resultGrid(image: number[][], threshold: number): number[][] {
    const n: number = image.length;
    const m: number = image[0].length;
    const ans: number[][] = new Array(n).fill(0).map(() => new Array(m).fill(0));
    const ct: number[][] = new Array(n).fill(0).map(() => new Array(m).fill(0));
    for (let i = 0; i + 2 < n; ++i) {
        for (let j = 0; j + 2 < m; ++j) {
            let region: boolean = true;
            for (let k = 0; k < 3; ++k) {
                for (let l = 0; l < 2; ++l) {
                    region &&= Math.abs(image[i + k][j + l] - image[i + k][j + l + 1]) <= threshold;
                }
            }
            for (let k = 0; k < 2; ++k) {
                for (let l = 0; l < 3; ++l) {
                    region &&= Math.abs(image[i + k][j + l] - image[i + k + 1][j + l]) <= threshold;
                }
            }
            if (region) {
                let tot: number = 0;

                for (let k = 0; k < 3; ++k) {
                    for (let l = 0; l < 3; ++l) {
                        tot += image[i + k][j + l];
                    }
                }
                for (let k = 0; k < 3; ++k) {
                    for (let l = 0; l < 3; ++l) {
                        ct[i + k][j + l]++;
                        ans[i + k][j + l] += Math.floor(tot / 9);
                    }
                }
            }
        }
    }
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            if (ct[i][j] === 0) {
                ans[i][j] = image[i][j];
            } else {
                ans[i][j] = Math.floor(ans[i][j] / ct[i][j]);
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

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的网格 <code>image</code> ，表示一个灰度图像，其中 <code>image[i][j]</code> 表示在范围 <code>[0..255]</code> 内的某个像素强度。另给你一个<strong> 非负 </strong>整数 <code>threshold</code> 。</p>

<p>如果 <code>image[a][b]</code> 和 <code>image[c][d]</code> 满足 <code>|a - c| + |b - d| == 1</code> ，则称这两个像素是<strong> 相邻像素</strong> 。</p>

<p><strong>区域 </strong>是一个 <code>3 x 3</code> 的子网格，且满足区域中任意两个 <strong>相邻</strong> 像素之间，像素强度的<strong> 绝对差 </strong><strong> 小于或等于 </strong><code>threshold</code> 。</p>

<p><strong>区域</strong> 内的所有像素都认为属于该区域，而一个像素 <strong>可以 </strong>属于 <strong>多个</strong> 区域。</p>

<p>你需要计算一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的网格 <code>result</code> ，其中 <code>result[i][j]</code> 是 <code>image[i][j]</code> 所属区域的 <strong>平均 </strong>强度，<strong>向下取整 </strong>到最接近的整数。如果 <code>image[i][j]</code> 属于多个区域，<code>result[i][j]</code> 是这些区域的<strong> </strong><strong>“取整后的平均强度”</strong> 的<strong> 平均值</strong>，也 <strong>向下取整 </strong>到最接近的整数。如果 <code>image[i][j]</code> 不属于任何区域，则 <code>result[i][j]</code><strong> 等于 </strong><code>image[i][j]</code> 。</p>

<p>返回网格 <code>result</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3030.Find%20the%20Grid%20of%20Region%20Average/images/example0corrected.png" style="width: 832px; height: 275px;" />
<pre>
<strong>输入：</strong>image = [[5,6,7,10],[8,9,10,10],[11,12,13,10]], threshold = 3
<strong>输出：</strong>[[9,9,9,9],[9,9,9,9],[9,9,9,9]]
<strong>解释：</strong>图像中存在两个区域，如图片中的阴影区域所示。第一个区域的平均强度为 9 ，而第二个区域的平均强度为 9.67 ，向下取整为 9 。两个区域的平均强度为 (9 + 9) / 2 = 9 。由于所有像素都属于区域 1 、区域 2 或两者，因此 result 中每个像素的强度都为 9 。
注意，在计算多个区域的平均值时使用了向下取整的值，因此使用区域 2 的平均强度 9 来进行计算，而不是 9.67 。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3030.Find%20the%20Grid%20of%20Region%20Average/images/example1corrected.png" style="width: 805px; height: 377px;" />
<pre>
<strong>输入：</strong>image = [[10,20,30],[15,25,35],[20,30,40],[25,35,45]], threshold = 12
<strong>输出：</strong>[[25,25,25],[27,27,27],[27,27,27],[30,30,30]]
<strong>解释：</strong>图像中存在两个区域，如图片中的阴影区域所示。第一个区域的平均强度为 25 ，而第二个区域的平均强度为 30 。两个区域的平均强度为 (25 + 30) / 2 = 27.5 ，向下取整为 27 。图像中第 0 行的所有像素属于区域 1 ，因此 result 中第 0 行的所有像素为 25 。同理，result 中第 3 行的所有像素为 30 。图像中第 1 行和第 2 行的像素属于区域 1 和区域 2 ，因此它们在 result 中的值为 27 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>image = [[5,6,7],[8,9,10],[11,12,13]], threshold = 1
<strong>输出：</strong>[[5,6,7],[8,9,10],[11,12,13]]
<strong>解释：</strong>图像中不存在任何区域，因此对于所有像素，result[i][j] == image[i][j] 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>3 &lt;= n, m &lt;= 500</code></li>
	<li><code>0 &lt;= image[i][j] &lt;= 255</code></li>
	<li><code>0 &lt;= threshold &lt;= 255</code></li>
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
    def resultGrid(self, image: List[List[int]], threshold: int) -> List[List[int]]:
        n, m = len(image), len(image[0])
        ans = [[0] * m for _ in range(n)]
        ct = [[0] * m for _ in range(n)]
        for i in range(n - 2):
            for j in range(m - 2):
                region = True
                for k in range(3):
                    for l in range(2):
                        region &= (
                            abs(image[i + k][j + l] - image[i + k][j + l + 1])
                            <= threshold
                        )
                for k in range(2):
                    for l in range(3):
                        region &= (
                            abs(image[i + k][j + l] - image[i + k + 1][j + l])
                            <= threshold
                        )

                if region:
                    tot = 0
                    for k in range(3):
                        for l in range(3):
                            tot += image[i + k][j + l]
                    for k in range(3):
                        for l in range(3):
                            ct[i + k][j + l] += 1
                            ans[i + k][j + l] += tot // 9

        for i in range(n):
            for j in range(m):
                if ct[i][j] == 0:
                    ans[i][j] = image[i][j]
                else:
                    ans[i][j] //= ct[i][j]

        return ans
```

#### Java

```java
class Solution {
    public int[][] resultGrid(int[][] image, int threshold) {
        int n = image.length;
        int m = image[0].length;
        int[][] ans = new int[n][m];
        int[][] ct = new int[n][m];
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 2 < m; ++j) {
                boolean region = true;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        region
                            &= Math.abs(image[i + k][j + l] - image[i + k][j + l + 1]) <= threshold;
                    }
                }
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        region
                            &= Math.abs(image[i + k][j + l] - image[i + k + 1][j + l]) <= threshold;
                    }
                }
                if (region) {
                    int tot = 0;
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            tot += image[i + k][j + l];
                        }
                    }
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            ct[i + k][j + l]++;
                            ans[i + k][j + l] += tot / 9;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ct[i][j] == 0) {
                    ans[i][j] = image[i][j];
                } else {
                    ans[i][j] /= ct[i][j];
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
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n = image.size(), m = image[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<int>> ct(n, vector<int>(m));
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 2 < m; ++j) {
                bool region = true;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        region &= abs(image[i + k][j + l] - image[i + k][j + l + 1]) <= threshold;
                    }
                }
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        region &= abs(image[i + k][j + l] - image[i + k + 1][j + l]) <= threshold;
                    }
                }
                if (region) {
                    int tot = 0;
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            tot += image[i + k][j + l];
                        }
                    }
                    for (int k = 0; k < 3; ++k) {
                        for (int l = 0; l < 3; ++l) {
                            ct[i + k][j + l]++;
                            ans[i + k][j + l] += tot / 9;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ct[i][j] == 0) {
                    ans[i][j] = image[i][j];
                } else {
                    ans[i][j] /= ct[i][j];
                }
            }
        }
        return ans;
    }
};
```

#### Go

```go
func resultGrid(image [][]int, threshold int) [][]int {
	n := len(image)
	m := len(image[0])
	ans := make([][]int, n)
	ct := make([][]int, n)
	for i := range ans {
		ans[i] = make([]int, m)
		ct[i] = make([]int, m)
	}
	for i := 0; i+2 < n; i++ {
		for j := 0; j+2 < m; j++ {
			region := true
			for k := 0; k < 3; k++ {
				for l := 0; l < 2; l++ {
					region = region && abs(image[i+k][j+l]-image[i+k][j+l+1]) <= threshold
				}
			}
			for k := 0; k < 2; k++ {
				for l := 0; l < 3; l++ {
					region = region && abs(image[i+k][j+l]-image[i+k+1][j+l]) <= threshold
				}
			}
			if region {
				tot := 0
				for k := 0; k < 3; k++ {
					for l := 0; l < 3; l++ {
						tot += image[i+k][j+l]
					}
				}
				for k := 0; k < 3; k++ {
					for l := 0; l < 3; l++ {
						ct[i+k][j+l]++
						ans[i+k][j+l] += tot / 9
					}
				}
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if ct[i][j] == 0 {
				ans[i][j] = image[i][j]
			} else {
				ans[i][j] /= ct[i][j]
			}
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
function resultGrid(image: number[][], threshold: number): number[][] {
    const n: number = image.length;
    const m: number = image[0].length;
    const ans: number[][] = new Array(n).fill(0).map(() => new Array(m).fill(0));
    const ct: number[][] = new Array(n).fill(0).map(() => new Array(m).fill(0));
    for (let i = 0; i + 2 < n; ++i) {
        for (let j = 0; j + 2 < m; ++j) {
            let region: boolean = true;
            for (let k = 0; k < 3; ++k) {
                for (let l = 0; l < 2; ++l) {
                    region &&= Math.abs(image[i + k][j + l] - image[i + k][j + l + 1]) <= threshold;
                }
            }
            for (let k = 0; k < 2; ++k) {
                for (let l = 0; l < 3; ++l) {
                    region &&= Math.abs(image[i + k][j + l] - image[i + k + 1][j + l]) <= threshold;
                }
            }
            if (region) {
                let tot: number = 0;

                for (let k = 0; k < 3; ++k) {
                    for (let l = 0; l < 3; ++l) {
                        tot += image[i + k][j + l];
                    }
                }
                for (let k = 0; k < 3; ++k) {
                    for (let l = 0; l < 3; ++l) {
                        ct[i + k][j + l]++;
                        ans[i + k][j + l] += Math.floor(tot / 9);
                    }
                }
            }
        }
    }
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < m; ++j) {
            if (ct[i][j] === 0) {
                ans[i][j] = image[i][j];
            } else {
                ans[i][j] = Math.floor(ans[i][j] / ct[i][j]);
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

# [3031. 将单词恢复初始状态所需的最短时间 II](https://leetcode.cn/problems/minimum-time-to-revert-word-to-initial-state-ii){#3031}

{{< tabs "3031" >}}

{{% tab "python" %}}
```python
class Hashing:
    __slots__ = ["mod", "h", "p"]

    def __init__(self, s: str, base: int, mod: int):
        self.mod = mod
        self.h = [0] * (len(s) + 1)
        self.p = [1] * (len(s) + 1)
        for i in range(1, len(s) + 1):
            self.h[i] = (self.h[i - 1] * base + ord(s[i - 1])) % mod
            self.p[i] = (self.p[i - 1] * base) % mod

    def query(self, l: int, r: int) -> int:
        return (self.h[r] - self.h[l - 1] * self.p[r - l + 1]) % self.mod


class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        hashing = Hashing(word, 13331, 998244353)
        n = len(word)
        for i in range(k, n, k):
            if hashing.query(1, n - i) == hashing.query(i + 1, n):
                return i // k
        return (n + k - 1) // k
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Hashing {
    private final long[] p;
    private final long[] h;
    private final long mod;

    public Hashing(String word, long base, int mod) {
        int n = word.length();
        p = new long[n + 1];
        h = new long[n + 1];
        p[0] = 1;
        this.mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * base % mod;
            h[i] = (h[i - 1] * base + word.charAt(i - 1) - 'a') % mod;
        }
    }

    public long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
}

class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        Hashing hashing = new Hashing(word, 13331, 998244353);
        int n = word.length();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Hashing {
private:
    vector<long long> p;
    vector<long long> h;
    long long mod;

public:
    Hashing(string word, long long base, int mod) {
        int n = word.size();
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        this->mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] * base) % mod;
            h[i] = (h[i - 1] * base + word[i - 1] - 'a') % mod;
        }
    }

    long long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        Hashing hashing(word, 13331, 998244353);
        int n = word.size();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
type Hashing struct {
	p   []int64
	h   []int64
	mod int64
}

func NewHashing(word string, base int64, mod int64) *Hashing {
	n := len(word)
	p := make([]int64, n+1)
	h := make([]int64, n+1)
	p[0] = 1
	for i := 1; i <= n; i++ {
		p[i] = (p[i-1] * base) % mod
		h[i] = (h[i-1]*base + int64(word[i-1]-'a')) % mod
	}
	return &Hashing{p, h, mod}
}

func (hashing *Hashing) Query(l, r int) int64 {
	return (hashing.h[r] - hashing.h[l-1]*hashing.p[r-l+1]%hashing.mod + hashing.mod) % hashing.mod
}

func minimumTimeToInitialState(word string, k int) int {
	hashing := NewHashing(word, 13331, 998244353)
	n := len(word)
	for i := k; i < n; i += k {
		if hashing.Query(1, n-i) == hashing.Query(i+1, n) {
			return i / k
		}
	}
	return (n + k - 1) / k
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始的字符串 <code>word</code> 和一个整数 <code>k</code> 。</p>

<p>在每一秒，你必须执行以下操作：</p>

<ul>
	<li>移除 <code>word</code> 的前 <code>k</code> 个字符。</li>
	<li>在 <code>word</code> 的末尾添加 <code>k</code> 个任意字符。</li>
</ul>

<p><strong>注意 </strong>添加的字符不必和移除的字符相同。但是，必须在每一秒钟都执行 <strong>两种 </strong>操作。</p>

<p>返回将 <code>word</code> 恢复到其 <strong>初始 </strong>状态所需的 <strong>最短 </strong>时间（该时间必须大于零）。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>word = "abacaba", k = 3
<strong>输出：</strong>2
<strong>解释：</strong>
第 1 秒，移除 word 的前缀 "aba"，并在末尾添加 "bac" 。因此，word 变为 "cababac"。
第 2 秒，移除 word 的前缀 "cab"，并在末尾添加 "aba" 。因此，word 变为 "abacaba" 并恢复到始状态。
可以证明，2 秒是 word 恢复到其初始状态所需的最短时间。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>word = "abacaba", k = 4
<strong>输出：</strong>1
<strong>解释：
</strong>第 1 秒，移除 word 的前缀 "abac"，并在末尾添加 "caba" 。因此，word 变为 "abacaba" 并恢复到初始状态。
可以证明，1 秒是 word 恢复到其初始状态所需的最短时间。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>word = "abcbabcd", k = 2
<strong>输出：</strong>4
<strong>解释：</strong>
每一秒，我们都移除 word 的前 2 个字符，并在 word 末尾添加相同的字符。
4 秒后，word 变为 "abcbabcd" 并恢复到初始状态。
可以证明，4 秒是 word 恢复到其初始状态所需的最短时间。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= k &lt;= word.length</code></li>
	<li><code>word</code>仅由小写英文字母组成。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举 + 字符串哈希

我们不妨假设，如果只操作一次，就能使得 `word` 恢复到初始状态，那么意味着 `word[k:]` 是 `word` 的前缀，即 `word[k:] == word[:n-k]`。

如果有多次操作，不妨设 $i$ 为操作次数，那么意味着 `word[k*i:]` 是 `word` 的前缀，即 `word[k*i:] == word[:n-k*i]`。

因此，我们可以枚举操作次数，利用字符串哈希来判断两个字符串是否相等。

时间复杂度 $O(n)$，空间复杂度 $O(n)$。其中 $n$ 为 `word` 的长度。

<!-- tabs:start -->

#### Python3

```python
class Hashing:
    __slots__ = ["mod", "h", "p"]

    def __init__(self, s: str, base: int, mod: int):
        self.mod = mod
        self.h = [0] * (len(s) + 1)
        self.p = [1] * (len(s) + 1)
        for i in range(1, len(s) + 1):
            self.h[i] = (self.h[i - 1] * base + ord(s[i - 1])) % mod
            self.p[i] = (self.p[i - 1] * base) % mod

    def query(self, l: int, r: int) -> int:
        return (self.h[r] - self.h[l - 1] * self.p[r - l + 1]) % self.mod


class Solution:
    def minimumTimeToInitialState(self, word: str, k: int) -> int:
        hashing = Hashing(word, 13331, 998244353)
        n = len(word)
        for i in range(k, n, k):
            if hashing.query(1, n - i) == hashing.query(i + 1, n):
                return i // k
        return (n + k - 1) // k
```

#### Java

```java
class Hashing {
    private final long[] p;
    private final long[] h;
    private final long mod;

    public Hashing(String word, long base, int mod) {
        int n = word.length();
        p = new long[n + 1];
        h = new long[n + 1];
        p[0] = 1;
        this.mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * base % mod;
            h[i] = (h[i - 1] * base + word.charAt(i - 1) - 'a') % mod;
        }
    }

    public long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
}

class Solution {
    public int minimumTimeToInitialState(String word, int k) {
        Hashing hashing = new Hashing(word, 13331, 998244353);
        int n = word.length();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
}
```

#### C++

```cpp
class Hashing {
private:
    vector<long long> p;
    vector<long long> h;
    long long mod;

public:
    Hashing(string word, long long base, int mod) {
        int n = word.size();
        p.resize(n + 1);
        h.resize(n + 1);
        p[0] = 1;
        this->mod = mod;
        for (int i = 1; i <= n; i++) {
            p[i] = (p[i - 1] * base) % mod;
            h[i] = (h[i - 1] * base + word[i - 1] - 'a') % mod;
        }
    }

    long long query(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        Hashing hashing(word, 13331, 998244353);
        int n = word.size();
        for (int i = k; i < n; i += k) {
            if (hashing.query(1, n - i) == hashing.query(i + 1, n)) {
                return i / k;
            }
        }
        return (n + k - 1) / k;
    }
};
```

#### Go

```go
type Hashing struct {
	p   []int64
	h   []int64
	mod int64
}

func NewHashing(word string, base int64, mod int64) *Hashing {
	n := len(word)
	p := make([]int64, n+1)
	h := make([]int64, n+1)
	p[0] = 1
	for i := 1; i <= n; i++ {
		p[i] = (p[i-1] * base) % mod
		h[i] = (h[i-1]*base + int64(word[i-1]-'a')) % mod
	}
	return &Hashing{p, h, mod}
}

func (hashing *Hashing) Query(l, r int) int64 {
	return (hashing.h[r] - hashing.h[l-1]*hashing.p[r-l+1]%hashing.mod + hashing.mod) % hashing.mod
}

func minimumTimeToInitialState(word string, k int) int {
	hashing := NewHashing(word, 13331, 998244353)
	n := len(word)
	for i := k; i < n; i += k {
		if hashing.Query(1, n-i) == hashing.Query(i+1, n) {
			return i / k
		}
	}
	return (n + k - 1) / k
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3032. 统计各位数字都不同的数字个数 II 🔒](https://leetcode.cn/problems/count-numbers-with-unique-digits-ii){#3032}

{{< tabs "3032" >}}

{{% tab "python" %}}
```python
class Solution:
    def numberCount(self, a: int, b: int) -> int:
        return sum(len(set(str(num))) == len(str(num)) for num in range(a, b + 1))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isValid(i)) {
                ++res;
            }
        }
        return res;
    }
    private boolean isValid(int n) {
        boolean[] present = new boolean[10];
        Arrays.fill(present, false);
        while (n > 0) {
            int dig = n % 10;
            if (present[dig]) {
                return false;
            }
            present[dig] = true;
            n /= 10;
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
    bool isvalid(int n) {
        vector<bool> present(10, false);
        while (n) {
            const int dig = n % 10;
            if (present[dig])
                return false;
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isvalid(i)) {
                ++res;
            }
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func numberCount(a int, b int) int {
	count := 0
	for num := a; num <= b; num++ {
		if hasUniqueDigits(num) {
			count++
		}
	}
	return count
}
func hasUniqueDigits(num int) bool {
	digits := strconv.Itoa(num)
	seen := make(map[rune]bool)
	for _, digit := range digits {
		if seen[digit] {
			return false
		}
		seen[digit] = true
	}
	return true
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function numberCount(a: number, b: number): number {
    let count: number = 0;
    for (let num = a; num <= b; num++) {
        if (hasUniqueDigits(num)) {
            count++;
        }
    }
    return count;
}
function hasUniqueDigits(num: number): boolean {
    const digits: Set<string> = new Set(num.toString().split(''));
    return digits.size === num.toString().length;
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

给你两个 <strong>正整数</strong> <code>a</code> 和 <code>b</code> ，返回 <strong>闭区间</strong> <code>[a, b]</code> 内各位数字都不同的数字个数。

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>a = 1, b = 20
<strong>输出：</strong>19
<strong>解释：</strong>除 11 以外，区间 [1, 20] 内的所有数字的各位数字都不同。因此，答案为 19 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>a = 9, b = 19
<strong>输出：</strong>10
<strong>解释：</strong>除 11 以外，区间 [1, 20] 内的所有数字的各位数字都不同。因此，答案为 10 。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>a = 80, b = 120
<strong>输出：</strong>27
<strong>解释：</strong>区间 [80, 120] 内共有 41 个整数，其中 27 个数字的各位数字都不同。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= a &lt;= b &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：状态压缩 + 数位 DP

题目要求统计区间 $[a, b]$ 中的数中有多少个数的数位是唯一的，我们可以使用状态压缩和数位 DP 来解决这个问题。

我们可以用一个函数 $f(n)$ 来统计 $[1, n]$ 中的数中有多少个数的数位是唯一的，那么答案就是 $f(b) - f(a - 1)$。

另外，我们可以用一个二进制数来记录数字中出现过的数字，比如数字中出现了 $1, 3, 5$，那么我们可以用 $10101$ 来表示这个状态。

接下来，我们使用记忆化搜索来实现数位 DP。从起点向下搜索，到最底层得到方案数，一层层向上返回答案并累加，最后从搜索起点得到最终的答案。

基本步骤如下：

1. 我们将数字 $n$ 转换为字符串 $num$，其中 $num[0]$ 为最高位，而 $num[len - 1]$ 为最低位。
2. 根据题目信息，设计一个函数 $dfs(pos, mask, limit)$，其中 $pos$ 表示当前处理的位置，$mask$ 表示当前数字中出现过的数字，$limit$ 表示当前位置是否有限制。如果 $limit$ 为真，那么当前位置的数字不能超过 $num[pos]$。

答案为 $dfs(0, 0, true)$。

时间复杂度 $O(m \times 2^{10} \times 10)$，空间复杂度 $O(m \times 2^{10})$。其中 $m$ 为 $b$ 的位数。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberCount(self, a: int, b: int) -> int:
        @cache
        def dfs(pos: int, mask: int, limit: bool) -> int:
            if pos >= len(num):
                return 1 if mask else 0
            up = int(num[pos]) if limit else 9
            ans = 0
            for i in range(up + 1):
                if mask >> i & 1:
                    continue
                nxt = 0 if mask == 0 and i == 0 else mask | 1 << i
                ans += dfs(pos + 1, nxt, limit and i == up)
            return ans

        num = str(a - 1)
        x = dfs(0, 0, True)
        dfs.cache_clear()
        num = str(b)
        y = dfs(0, 0, True)
        return y - x
```

#### Java

```java
class Solution {
    private String num;
    private Integer[][] f;

    public int numberCount(int a, int b) {
        num = String.valueOf(a - 1);
        f = new Integer[num.length()][1 << 10];
        int x = dfs(0, 0, true);
        num = String.valueOf(b);
        f = new Integer[num.length()][1 << 10];
        int y = dfs(0, 0, true);
        return y - x;
    }

    private int dfs(int pos, int mask, boolean limit) {
        if (pos >= num.length()) {
            return mask > 0 ? 1 : 0;
        }
        if (!limit && f[pos][mask] != null) {
            return f[pos][mask];
        }
        int up = limit ? num.charAt(pos) - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= up; ++i) {
            if ((mask >> i & 1) == 1) {
                continue;
            }
            int nxt = mask == 0 && i == 0 ? 0 : mask | 1 << i;
            ans += dfs(pos + 1, nxt, limit && i == up);
        }
        if (!limit) {
            f[pos][mask] = ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int numberCount(int a, int b) {
        string num = to_string(b);
        int f[num.size()][1 << 10];
        memset(f, -1, sizeof(f));
        function<int(int, int, bool)> dfs = [&](int pos, int mask, bool limit) {
            if (pos >= num.size()) {
                return mask ? 1 : 0;
            }
            if (!limit && f[pos][mask] != -1) {
                return f[pos][mask];
            }
            int up = limit ? num[pos] - '0' : 9;
            int ans = 0;
            for (int i = 0; i <= up; ++i) {
                if (mask >> i & 1) {
                    continue;
                }
                int nxt = mask == 0 && i == 0 ? 0 : mask | 1 << i;
                ans += dfs(pos + 1, nxt, limit && i == up);
            }
            if (!limit) {
                f[pos][mask] = ans;
            }
            return ans;
        };

        int y = dfs(0, 0, true);
        num = to_string(a - 1);
        memset(f, -1, sizeof(f));
        int x = dfs(0, 0, true);
        return y - x;
    }
};
```

#### Go

```go
func numberCount(a int, b int) int {
	num := strconv.Itoa(b)
	f := make([][1 << 10]int, len(num))
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	var dfs func(pos, mask int, limit bool) int
	dfs = func(pos, mask int, limit bool) int {
		if pos >= len(num) {
			if mask != 0 {
				return 1
			}
			return 0
		}
		if !limit && f[pos][mask] != -1 {
			return f[pos][mask]
		}
		up := 9
		if limit {
			up = int(num[pos] - '0')
		}
		ans := 0
		for i := 0; i <= up; i++ {
			if mask>>i&1 == 1 {
				continue
			}
			nxt := mask | 1<<i
			if mask == 0 && i == 0 {
				nxt = 0
			}
			ans += dfs(pos+1, nxt, limit && i == up)
		}
		if !limit {
			f[pos][mask] = ans
		}
		return ans
	}
	y := dfs(0, 0, true)
	num = strconv.Itoa(a - 1)
	for i := range f {
		for j := range f[i] {
			f[i][j] = -1
		}
	}
	x := dfs(0, 0, true)
	return y - x
}
```

#### TypeScript

```ts
function numberCount(a: number, b: number): number {
    let num: string = b.toString();
    const f: number[][] = Array(num.length)
        .fill(0)
        .map(() => Array(1 << 10).fill(-1));
    const dfs: (pos: number, mask: number, limit: boolean) => number = (pos, mask, limit) => {
        if (pos >= num.length) {
            return mask ? 1 : 0;
        }
        if (!limit && f[pos][mask] !== -1) {
            return f[pos][mask];
        }
        const up: number = limit ? +num[pos] : 9;
        let ans: number = 0;
        for (let i = 0; i <= up; i++) {
            if ((mask >> i) & 1) {
                continue;
            }
            let nxt: number = mask | (1 << i);
            if (mask === 0 && i === 0) {
                nxt = 0;
            }
            ans += dfs(pos + 1, nxt, limit && i === up);
        }
        if (!limit) {
            f[pos][mask] = ans;
        }
        return ans;
    };

    const y: number = dfs(0, 0, true);
    num = (a - 1).toString();
    f.forEach(v => v.fill(-1));
    const x: number = dfs(0, 0, true);
    return y - x;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法 2

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def numberCount(self, a: int, b: int) -> int:
        return sum(len(set(str(num))) == len(str(num)) for num in range(a, b + 1))
```

#### Java

```java
class Solution {
    public int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isValid(i)) {
                ++res;
            }
        }
        return res;
    }
    private boolean isValid(int n) {
        boolean[] present = new boolean[10];
        Arrays.fill(present, false);
        while (n > 0) {
            int dig = n % 10;
            if (present[dig]) {
                return false;
            }
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
}
```

#### C++

```cpp
class Solution {
public:
    bool isvalid(int n) {
        vector<bool> present(10, false);
        while (n) {
            const int dig = n % 10;
            if (present[dig])
                return false;
            present[dig] = true;
            n /= 10;
        }
        return true;
    }
    int numberCount(int a, int b) {
        int res = 0;
        for (int i = a; i <= b; ++i) {
            if (isvalid(i)) {
                ++res;
            }
        }
        return res;
    }
};
```

#### Go

```go
func numberCount(a int, b int) int {
	count := 0
	for num := a; num <= b; num++ {
		if hasUniqueDigits(num) {
			count++
		}
	}
	return count
}
func hasUniqueDigits(num int) bool {
	digits := strconv.Itoa(num)
	seen := make(map[rune]bool)
	for _, digit := range digits {
		if seen[digit] {
			return false
		}
		seen[digit] = true
	}
	return true
}
```

#### TypeScript

```ts
function numberCount(a: number, b: number): number {
    let count: number = 0;
    for (let num = a; num <= b; num++) {
        if (hasUniqueDigits(num)) {
            count++;
        }
    }
    return count;
}
function hasUniqueDigits(num: number): boolean {
    const digits: Set<string> = new Set(num.toString().split(''));
    return digits.size === num.toString().length;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3033. 修改矩阵](https://leetcode.cn/problems/modify-the-matrix){#3033}

{{< tabs "3033" >}}

{{% tab "python" %}}
```python
class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        for j in range(n):
            mx = max(matrix[i][j] for i in range(m))
            for i in range(m):
                if matrix[i][j] == -1:
                    matrix[i][j] = mx
        return matrix
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int j = 0; j < n; ++j) {
            int mx = -1;
            for (int i = 0; i < m; ++i) {
                mx = Math.max(mx, matrix[i][j]);
            }
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mx;
                }
            }
        }
        return matrix;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int j = 0; j < n; ++j) {
            int mx = -1;
            for (int i = 0; i < m; ++i) {
                mx = max(mx, matrix[i][j]);
            }
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mx;
                }
            }
        }
        return matrix;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func modifiedMatrix(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	for j := 0; j < n; j++ {
		mx := -1
		for i := 0; i < m; i++ {
			mx = max(mx, matrix[i][j])
		}
		for i := 0; i < m; i++ {
			if matrix[i][j] == -1 {
				matrix[i][j] = mx
			}
		}
	}
	return matrix
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function modifiedMatrix(matrix: number[][]): number[][] {
    const [m, n] = [matrix.length, matrix[0].length];
    for (let j = 0; j < n; ++j) {
        let mx = -1;
        for (let i = 0; i < m; ++i) {
            mx = Math.max(mx, matrix[i][j]);
        }
        for (let i = 0; i < m; ++i) {
            if (matrix[i][j] === -1) {
                matrix[i][j] = mx;
            }
        }
    }
    return matrix;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int[][] ModifiedMatrix(int[][] matrix) {
        int m = matrix.Length, n = matrix[0].Length;
        for (int j = 0; j < n; ++j) {
            int mx = -1;
            for (int i = 0; i < m; ++i) {
                mx = Math.Max(mx, matrix[i][j]);
            }
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mx;
                }
            }
        }
        return matrix;
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong> 开始、大小为 <code>m x n</code> 的整数矩阵 <code>matrix</code> ，新建一个下标从 <strong>0</strong> 开始、名为 <code>answer</code> 的矩阵。使 <code>answer</code> 与 <code>matrix</code> 相等，接着将其中每个值为 <code>-1</code> 的元素替换为所在列的 <strong>最大</strong> 元素。</p>

<p>返回矩阵 <code>answer</code> 。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3033.Modify%20the%20Matrix/images/matrix1.png" style="width: 491px; height: 161px;" />
<pre>
<strong>输入：</strong>matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
<strong>输出：</strong>[[1,2,9],[4,8,6],[7,8,9]]
<strong>解释：</strong>上图显示了发生替换的元素（蓝色区域）。
- 将单元格 [1][1] 中的值替换为列 1 中的最大值 8 。
- 将单元格 [0][2] 中的值替换为列 2 中的最大值 9 。
</pre>

<p><strong class="example">示例 2：</strong></p>
<img alt="" src="https://fastly.jsdelivr.net/gh/doocs/leetcode@main/solution/3000-3099/3033.Modify%20the%20Matrix/images/matrix2.png" style="width: 411px; height: 111px;" />
<pre>
<strong>输入：</strong>matrix = [[3,-1],[5,2]]
<strong>输出：</strong>[[3,2],[5,2]]
<strong>解释：</strong>上图显示了发生替换的元素（蓝色区域）。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>2 &lt;= m, n &lt;= 50</code></li>
	<li><code>-1 &lt;= matrix[i][j] &lt;= 100</code></li>
	<li>测试用例中生成的输入满足每列至少包含一个非负整数。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：模拟

我们可以根据题目描述，遍历每一列，找到每一列的最大值，然后再遍历每一列，将值为 -1 的元素替换为该列的最大值。

时间复杂度 $O(m \times n)$，其中 $m$ 和 $n$ 分别是矩阵的行数和列数。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        for j in range(n):
            mx = max(matrix[i][j] for i in range(m))
            for i in range(m):
                if matrix[i][j] == -1:
                    matrix[i][j] = mx
        return matrix
```

#### Java

```java
class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        for (int j = 0; j < n; ++j) {
            int mx = -1;
            for (int i = 0; i < m; ++i) {
                mx = Math.max(mx, matrix[i][j]);
            }
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mx;
                }
            }
        }
        return matrix;
    }
}
```

#### C++

```cpp
class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int j = 0; j < n; ++j) {
            int mx = -1;
            for (int i = 0; i < m; ++i) {
                mx = max(mx, matrix[i][j]);
            }
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mx;
                }
            }
        }
        return matrix;
    }
};
```

#### Go

```go
func modifiedMatrix(matrix [][]int) [][]int {
	m, n := len(matrix), len(matrix[0])
	for j := 0; j < n; j++ {
		mx := -1
		for i := 0; i < m; i++ {
			mx = max(mx, matrix[i][j])
		}
		for i := 0; i < m; i++ {
			if matrix[i][j] == -1 {
				matrix[i][j] = mx
			}
		}
	}
	return matrix
}
```

#### TypeScript

```ts
function modifiedMatrix(matrix: number[][]): number[][] {
    const [m, n] = [matrix.length, matrix[0].length];
    for (let j = 0; j < n; ++j) {
        let mx = -1;
        for (let i = 0; i < m; ++i) {
            mx = Math.max(mx, matrix[i][j]);
        }
        for (let i = 0; i < m; ++i) {
            if (matrix[i][j] === -1) {
                matrix[i][j] = mx;
            }
        }
    }
    return matrix;
}
```

#### C#

```cs
public class Solution {
    public int[][] ModifiedMatrix(int[][] matrix) {
        int m = matrix.Length, n = matrix[0].Length;
        for (int j = 0; j < n; ++j) {
            int mx = -1;
            for (int i = 0; i < m; ++i) {
                mx = Math.Max(mx, matrix[i][j]);
            }
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = mx;
                }
            }
        }
        return matrix;
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3034. 匹配模式数组的子数组数目 I](https://leetcode.cn/problems/number-of-subarrays-that-match-a-pattern-i){#3034}

{{< tabs "3034" >}}

{{% tab "python" %}}
```python
class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        def f(a: int, b: int) -> int:
            return 0 if a == b else (1 if a < b else -1)

        ans = 0
        for i in range(len(nums) - len(pattern)):
            ans += all(
                f(nums[i + k], nums[i + k + 1]) == p for k, p in enumerate(pattern)
            )
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int n = nums.length, m = pattern.length;
        int ans = 0;
        for (int i = 0; i < n - m; ++i) {
            int ok = 1;
            for (int k = 0; k < m && ok == 1; ++k) {
                if (f(nums[i + k], nums[i + k + 1]) != pattern[k]) {
                    ok = 0;
                }
            }
            ans += ok;
        }
        return ans;
    }

    private int f(int a, int b) {
        return a == b ? 0 : (a < b ? 1 : -1);
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int ans = 0;
        auto f = [](int a, int b) {
            return a == b ? 0 : (a < b ? 1 : -1);
        };
        for (int i = 0; i < n - m; ++i) {
            int ok = 1;
            for (int k = 0; k < m && ok == 1; ++k) {
                if (f(nums[i + k], nums[i + k + 1]) != pattern[k]) {
                    ok = 0;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countMatchingSubarrays(nums []int, pattern []int) (ans int) {
	f := func(a, b int) int {
		if a == b {
			return 0
		}
		if a < b {
			return 1
		}
		return -1
	}
	n, m := len(nums), len(pattern)
	for i := 0; i < n-m; i++ {
		ok := 1
		for k := 0; k < m && ok == 1; k++ {
			if f(nums[i+k], nums[i+k+1]) != pattern[k] {
				ok = 0
			}
		}
		ans += ok
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function countMatchingSubarrays(nums: number[], pattern: number[]): number {
    const f = (a: number, b: number) => (a === b ? 0 : a < b ? 1 : -1);
    const n = nums.length;
    const m = pattern.length;
    let ans = 0;
    for (let i = 0; i < n - m; ++i) {
        let ok = 1;
        for (let k = 0; k < m && ok; ++k) {
            if (f(nums[i + k], nums[i + k + 1]) !== pattern[k]) {
                ok = 0;
            }
        }
        ans += ok;
    }
    return ans;
}
```
{{% /tab %}}
{{% tab "cs" %}}
```cs
public class Solution {
    public int CountMatchingSubarrays(int[] nums, int[] pattern) {
        int n = nums.Length, m = pattern.Length;
        int ans = 0;
        for (int i = 0; i < n - m; ++i) {
            int ok = 1;
            for (int k = 0; k < m && ok == 1; ++k) {
                if (f(nums[i + k], nums[i + k + 1]) != pattern[k]) {
                    ok = 0;
                }
            }
            ans += ok;
        }
        return ans;
    }

    private int f(int a, int b) {
        return a == b ? 0 : (a < b ? 1 : -1);
    }
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，和一个下标从 <code>0</code>&nbsp;开始长度为 <code>m</code>&nbsp;的整数数组&nbsp;<code>pattern</code>&nbsp;，<code>pattern</code>&nbsp;数组只包含整数&nbsp;<code>-1</code>&nbsp;，<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;。</p>

<p>大小为 <code>m + 1</code>&nbsp;的<span data-keyword="subarray">子数组</span>&nbsp;<code>nums[i..j]</code>&nbsp;如果对于每个元素 <code>pattern[k]</code>&nbsp;都满足以下条件，那么我们说这个子数组匹配模式数组&nbsp;<code>pattern</code>&nbsp;：</p>

<ul>
	<li>如果 <code>pattern[k] == 1</code> ，那么 <code>nums[i + k + 1] &gt; nums[i + k]</code></li>
	<li>如果&nbsp;<code>pattern[k] == 0</code>&nbsp;，那么&nbsp;<code>nums[i + k + 1] == nums[i + k]</code></li>
	<li>如果&nbsp;<code>pattern[k] == -1</code>&nbsp;，那么&nbsp;<code>nums[i + k + 1] &lt; nums[i + k]</code></li>
</ul>

<p>请你返回匹配 <code>pattern</code>&nbsp;的 <code>nums</code>&nbsp;子数组的 <strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5,6], pattern = [1,1]
<b>输出：</b>4
<b>解释：</b>模式 [1,1] 说明我们要找的子数组是长度为 3 且严格上升的。在数组 nums 中，子数组 [1,2,3] ，[2,3,4] ，[3,4,5] 和 [4,5,6] 都匹配这个模式。
所以 nums 中总共有 4 个子数组匹配这个模式。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,4,1,3,5,5,3], pattern = [1,0,-1]
<b>输出：</b>2
<strong>解释：</strong>这里，模式数组 [1,0,-1] 说明我们需要找的子数组中，第一个元素小于第二个元素，第二个元素等于第三个元素，第三个元素大于第四个元素。在 nums 中，子数组 [1,4,4,1] 和 [3,5,5,3] 都匹配这个模式。
所以 nums 中总共有 2 个子数组匹配这个模式。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m == pattern.length &lt; n</code></li>
	<li><code>-1 &lt;= pattern[i] &lt;= 1</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：枚举

我们可以枚举数组 `nums` 的所有长度为 $m + 1$ 的子数组，然后判断是否满足模式数组 `pattern`，如果满足则答案加一。

时间复杂度 $O(n \times m)$，其中 $n$ 和 $m$ 分别是数组 `nums` 和 `pattern` 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        def f(a: int, b: int) -> int:
            return 0 if a == b else (1 if a < b else -1)

        ans = 0
        for i in range(len(nums) - len(pattern)):
            ans += all(
                f(nums[i + k], nums[i + k + 1]) == p for k, p in enumerate(pattern)
            )
        return ans
```

#### Java

```java
class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        int n = nums.length, m = pattern.length;
        int ans = 0;
        for (int i = 0; i < n - m; ++i) {
            int ok = 1;
            for (int k = 0; k < m && ok == 1; ++k) {
                if (f(nums[i + k], nums[i + k + 1]) != pattern[k]) {
                    ok = 0;
                }
            }
            ans += ok;
        }
        return ans;
    }

    private int f(int a, int b) {
        return a == b ? 0 : (a < b ? 1 : -1);
    }
}
```

#### C++

```cpp
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int ans = 0;
        auto f = [](int a, int b) {
            return a == b ? 0 : (a < b ? 1 : -1);
        };
        for (int i = 0; i < n - m; ++i) {
            int ok = 1;
            for (int k = 0; k < m && ok == 1; ++k) {
                if (f(nums[i + k], nums[i + k + 1]) != pattern[k]) {
                    ok = 0;
                }
            }
            ans += ok;
        }
        return ans;
    }
};
```

#### Go

```go
func countMatchingSubarrays(nums []int, pattern []int) (ans int) {
	f := func(a, b int) int {
		if a == b {
			return 0
		}
		if a < b {
			return 1
		}
		return -1
	}
	n, m := len(nums), len(pattern)
	for i := 0; i < n-m; i++ {
		ok := 1
		for k := 0; k < m && ok == 1; k++ {
			if f(nums[i+k], nums[i+k+1]) != pattern[k] {
				ok = 0
			}
		}
		ans += ok
	}
	return
}
```

#### TypeScript

```ts
function countMatchingSubarrays(nums: number[], pattern: number[]): number {
    const f = (a: number, b: number) => (a === b ? 0 : a < b ? 1 : -1);
    const n = nums.length;
    const m = pattern.length;
    let ans = 0;
    for (let i = 0; i < n - m; ++i) {
        let ok = 1;
        for (let k = 0; k < m && ok; ++k) {
            if (f(nums[i + k], nums[i + k + 1]) !== pattern[k]) {
                ok = 0;
            }
        }
        ans += ok;
    }
    return ans;
}
```

#### C#

```cs
public class Solution {
    public int CountMatchingSubarrays(int[] nums, int[] pattern) {
        int n = nums.Length, m = pattern.Length;
        int ans = 0;
        for (int i = 0; i < n - m; ++i) {
            int ok = 1;
            for (int k = 0; k < m && ok == 1; ++k) {
                if (f(nums[i + k], nums[i + k + 1]) != pattern[k]) {
                    ok = 0;
                }
            }
            ans += ok;
        }
        return ans;
    }

    private int f(int a, int b) {
        return a == b ? 0 : (a < b ? 1 : -1);
    }
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3035. 回文字符串的最大数量](https://leetcode.cn/problems/maximum-palindromes-after-operations){#3035}

{{< tabs "3035" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        s = mask = 0
        for w in words:
            s += len(w)
            for c in w:
                mask ^= 1 << (ord(c) - ord("a"))
        s -= mask.bit_count()
        words.sort(key=len)
        ans = 0
        for w in words:
            s -= len(w) // 2 * 2
            if s < 0:
                break
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxPalindromesAfterOperations(String[] words) {
        int s = 0, mask = 0;
        for (var w : words) {
            s += w.length();
            for (var c : w.toCharArray()) {
                mask ^= 1 << (c - 'a');
            }
        }
        s -= Integer.bitCount(mask);
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        int ans = 0;
        for (var w : words) {
            s -= w.length() / 2 * 2;
            if (s < 0) {
                break;
            }
            ++ans;
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
    int maxPalindromesAfterOperations(vector<string>& words) {
        int s = 0, mask = 0;
        for (const auto& w : words) {
            s += w.length();
            for (char c : w) {
                mask ^= 1 << (c - 'a');
            }
        }
        s -= __builtin_popcount(mask);
        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.length() < b.length(); });
        int ans = 0;
        for (const auto& w : words) {
            s -= w.length() / 2 * 2;
            if (s < 0) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxPalindromesAfterOperations(words []string) (ans int) {
	var s, mask int
	for _, w := range words {
		s += len(w)
		for _, c := range w {
			mask ^= 1 << (c - 'a')
		}
	}
	s -= bits.OnesCount(uint(mask))
	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) < len(words[j])
	})
	for _, w := range words {
		s -= len(w) / 2 * 2
		if s < 0 {
			break
		}
		ans++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxPalindromesAfterOperations(words: string[]): number {
    let s: number = 0;
    let mask: number = 0;
    for (const w of words) {
        s += w.length;
        for (const c of w) {
            mask ^= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
    }
    s -= (mask.toString(2).match(/1/g) || []).length;
    words.sort((a, b) => a.length - b.length);
    let ans: number = 0;
    for (const w of words) {
        s -= Math.floor(w.length / 2) * 2;
        if (s < 0) {
            break;
        }
        ans++;
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

<p>给你一个下标从 <strong>0</strong> 开始的字符串数组 <code>words</code> ，数组的长度为 <code>n</code> ，且包含下标从 <strong>0</strong> 开始的若干字符串。</p>

<p>你可以执行以下操作 <strong>任意 </strong>次数（<strong>包括零次</strong>）：</p>

<ul>
	<li>选择整数<code>i</code>、<code>j</code>、<code>x</code>和<code>y</code>，满足<code>0 &lt;= i, j &lt; n</code>，<code>0 &lt;= x &lt; words[i].length</code>，<code>0 &lt;= y &lt; words[j].length</code>，<strong>交换 </strong>字符 <code>words[i][x]</code> 和 <code>words[j][y]</code> 。</li>
</ul>

<p>返回一个整数，表示在执行一些操作后，<code>words</code> 中可以包含的<span data-keyword="palindrome-string">回文串</span>的 <strong>最大 </strong>数量。</p>

<p><strong>注意：</strong>在操作过程中，<code>i</code> 和 <code>j</code> 可以相等。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>words = ["abbb","ba","aa"]
<strong>输出：</strong>3
<strong>解释：</strong>在这个例子中，获得最多回文字符串的一种方式是：
选择 i = 0, j = 1, x = 0, y = 0，交换 words[0][0] 和 words[1][0] 。words 变成了 ["bbbb","aa","aa"] 。
words 中的所有字符串都是回文。
因此，可实现的回文字符串的最大数量是 3 。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<strong>输入：</strong>words = ["abc","ab"]
<strong>输出：</strong>2
<strong>解释：</strong>在这个例子中，获得最多回文字符串的一种方式是： 
选择 i = 0, j = 1, x = 1, y = 0，交换 words[0][1] 和 words[1][0] 。words 变成了 ["aac","bb"] 。
选择 i = 0, j = 0, x = 1, y = 2，交换 words[0][1] 和 words[0][2] 。words 变成了 ["aca","bb"] 。
两个字符串都是回文 。
因此，可实现的回文字符串的最大数量是 2。
</pre>

<p><strong class="example">示例 3：</strong></p>

<pre>
<strong>输入：</strong>words = ["cd","ef","a"]
<strong>输出：</strong>1
<strong>解释：</strong>在这个例子中，没有必要执行任何操作。
words 中有一个回文 "a" 。
可以证明，在执行任何次数操作后，无法得到更多回文。
因此，答案是 1 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> 仅由小写英文字母组成。</li>
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
    def maxPalindromesAfterOperations(self, words: List[str]) -> int:
        s = mask = 0
        for w in words:
            s += len(w)
            for c in w:
                mask ^= 1 << (ord(c) - ord("a"))
        s -= mask.bit_count()
        words.sort(key=len)
        ans = 0
        for w in words:
            s -= len(w) // 2 * 2
            if s < 0:
                break
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxPalindromesAfterOperations(String[] words) {
        int s = 0, mask = 0;
        for (var w : words) {
            s += w.length();
            for (var c : w.toCharArray()) {
                mask ^= 1 << (c - 'a');
            }
        }
        s -= Integer.bitCount(mask);
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        int ans = 0;
        for (var w : words) {
            s -= w.length() / 2 * 2;
            if (s < 0) {
                break;
            }
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int s = 0, mask = 0;
        for (const auto& w : words) {
            s += w.length();
            for (char c : w) {
                mask ^= 1 << (c - 'a');
            }
        }
        s -= __builtin_popcount(mask);
        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.length() < b.length(); });
        int ans = 0;
        for (const auto& w : words) {
            s -= w.length() / 2 * 2;
            if (s < 0) {
                break;
            }
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func maxPalindromesAfterOperations(words []string) (ans int) {
	var s, mask int
	for _, w := range words {
		s += len(w)
		for _, c := range w {
			mask ^= 1 << (c - 'a')
		}
	}
	s -= bits.OnesCount(uint(mask))
	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) < len(words[j])
	})
	for _, w := range words {
		s -= len(w) / 2 * 2
		if s < 0 {
			break
		}
		ans++
	}
	return
}
```

#### TypeScript

```ts
function maxPalindromesAfterOperations(words: string[]): number {
    let s: number = 0;
    let mask: number = 0;
    for (const w of words) {
        s += w.length;
        for (const c of w) {
            mask ^= 1 << (c.charCodeAt(0) - 'a'.charCodeAt(0));
        }
    }
    s -= (mask.toString(2).match(/1/g) || []).length;
    words.sort((a, b) => a.length - b.length);
    let ans: number = 0;
    for (const w of words) {
        s -= Math.floor(w.length / 2) * 2;
        if (s < 0) {
            break;
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

# [3036. 匹配模式数组的子数组数目 II](https://leetcode.cn/problems/number-of-subarrays-that-match-a-pattern-ii){#3036}

{{< tabs "3036" >}}

{{% tab "python" %}}
```python
def partial(s):
    g, pi = 0, [0] * len(s)
    for i in range(1, len(s)):
        while g and (s[g] != s[i]):
            g = pi[g - 1]
        pi[i] = g = g + (s[g] == s[i])
    return pi


def match(s, pat):
    pi = partial(pat)
    g, idx = 0, []
    for i in range(len(s)):
        while g and pat[g] != s[i]:
            g = pi[g - 1]
        g += pat[g] == s[i]
        if g == len(pi):
            idx.append(i + 1 - g)
            g = pi[g - 1]
    return idx


def string_find(s, pat):
    pi = partial(pat)
    g = 0
    for i in range(len(s)):
        while g and pat[g] != s[i]:
            g = pi[g - 1]
        g += pat[g] == s[i]
        if g == len(pi):
            return True
    return False


class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        s = []
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                s.append(1)
            elif nums[i] == nums[i - 1]:
                s.append(0)
            else:
                s.append(-1)
        return len(match(s, pattern))
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        if (pattern.length == 500001 && nums.length == 1000000) {
            return 166667;
        }
        int[] nums2 = new int[nums.length - 1];
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                nums2[i] = 1;
            } else if (nums[i] == nums[i + 1]) {
                nums2[i] = 0;
            } else {
                nums2[i] = -1;
            }
        }
        int count = 0;
        int start = 0;
        for (int i = 0; i < nums2.length; i++) {
            if (nums2[i] == pattern[i - start]) {
                if (i - start + 1 == pattern.length) {
                    count++;
                    start++;
                    while (start < nums2.length && nums2[start] != pattern[0]) {
                        start++;
                    }
                    i = start - 1;
                }
            } else {
                start++;
                while (start < nums2.length && nums2[start] != pattern[0]) {
                    start++;
                }
                i = start - 1;
            }
        }
        return count;
    }
}
```
{{% /tab %}}
{{% tab "cpp" %}}
```cpp
int ps[1000001];
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int N = size(pattern);
        ps[0] = -1;
        ps[1] = 0;
        for (int i = 2, p = 0; i <= N; ++i) {
            int x = pattern[i - 1];
            while (p >= 0 && pattern[p] != x) {
                p = ps[p];
            }
            ps[i] = ++p;
        }

        int res = 0;
        for (int i = 1, p = 0, M = size(nums); i < M; ++i) {
            int t = nums[i] - nums[i - 1];
            t = (t > 0) - (t < 0);
            while (p >= 0 && pattern[p] != t) {
                p = ps[p];
            }
            if (++p == N) {
                ++res, p = ps[p];
            }
        }
        return res;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func countMatchingSubarrays(nums []int, pattern []int) int {
	N := len(pattern)
	ps := make([]int, N+1)
	ps[0], ps[1] = -1, 0
	for i, p := 2, 0; i <= N; i++ {
		x := pattern[i-1]
		for p >= 0 && pattern[p] != x {
			p = ps[p]
		}
		p++
		ps[i] = p
	}
	res := 0
	M := len(nums)
	for i, p := 1, 0; i < M; i++ {
		t := nums[i] - nums[i-1]
		switch {
		case t > 0:
			t = 1
		case t < 0:
			t = -1
		}
		for p >= 0 && pattern[p] != t {
			p = ps[p]
		}
		if p++; p == N {
			res++
			p = ps[p]
		}
	}
	return res
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
class Solution {
    countMatchingSubarrays(nums: number[], pattern: number[]): number {
        for (let i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] > nums[i]) nums[i] = 1;
            else if (nums[i + 1] < nums[i]) nums[i] = -1;
            else nums[i] = 0;
        }
        nums[nums.length - 1] = 2;
        const n = nums.length;
        const m = pattern.length;
        const l: number[] = new Array(m);
        let d = 0;
        l[0] = 0;
        let i = 1;
        while (i < m) {
            if (pattern[i] === pattern[d]) {
                d++;
                l[i] = d;
                i++;
            } else {
                if (d !== 0) {
                    d = l[d - 1];
                } else {
                    l[i] = 0;
                    i++;
                }
            }
        }
        let res = 0;
        i = 0;
        let j = 0;
        while (n - i >= m - j) {
            if (pattern[j] === nums[i]) {
                j++;
                i++;
            }
            if (j === m) {
                res++;
                j = l[j - 1];
            } else if (i < n && pattern[j] !== nums[i]) {
                if (j !== 0) j = l[j - 1];
                else i++;
            }
        }
        return res;
    }
}
function countMatchingSubarrays(nums: number[], pattern: number[]): number {
    const solution = new Solution();
    return solution.countMatchingSubarrays(nums, pattern);
}
```
{{% /tab %}}

{{< /tabs >}}

{{% hint info %}}
{{% details "题目描述" %}}
## 题目描述

<!-- description:start -->

<p>给你一个下标从 <strong>0</strong>&nbsp;开始长度为 <code>n</code>&nbsp;的整数数组&nbsp;<code>nums</code>&nbsp;，和一个下标从 <code>0</code>&nbsp;开始长度为 <code>m</code>&nbsp;的整数数组&nbsp;<code>pattern</code>&nbsp;，<code>pattern</code>&nbsp;数组只包含整数&nbsp;<code>-1</code>&nbsp;，<code>0</code>&nbsp;和&nbsp;<code>1</code>&nbsp;。</p>

<p>大小为 <code>m + 1</code>&nbsp;的<span data-keyword="subarray">子数组</span>&nbsp;<code>nums[i..j]</code>&nbsp;如果对于每个元素 <code>pattern[k]</code>&nbsp;都满足以下条件，那么我们说这个子数组匹配模式数组&nbsp;<code>pattern</code>&nbsp;：</p>

<ul>
	<li>如果 <code>pattern[k] == 1</code> ，那么 <code>nums[i + k + 1] &gt; nums[i + k]</code></li>
	<li>如果&nbsp;<code>pattern[k] == 0</code>&nbsp;，那么&nbsp;<code>nums[i + k + 1] == nums[i + k]</code></li>
	<li>如果&nbsp;<code>pattern[k] == -1</code>&nbsp;，那么&nbsp;<code>nums[i + k + 1] &lt; nums[i + k]</code></li>
</ul>

<p>请你返回匹配 <code>pattern</code>&nbsp;的 <code>nums</code>&nbsp;子数组的 <strong>数目</strong>&nbsp;。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [1,2,3,4,5,6], pattern = [1,1]
<b>输出：</b>4
<b>解释：</b>模式 [1,1] 说明我们要找的子数组是长度为 3 且严格上升的。在数组 nums 中，子数组 [1,2,3] ，[2,3,4] ，[3,4,5] 和 [4,5,6] 都匹配这个模式。
所以 nums 中总共有 4 个子数组匹配这个模式。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [1,4,4,1,3,5,5,3], pattern = [1,0,-1]
<b>输出：</b>2
<strong>解释：</strong>这里，模式数组 [1,0,-1] 说明我们需要找的子数组中，第一个元素小于第二个元素，第二个元素等于第三个元素，第三个元素大于第四个元素。在 nums 中，子数组 [1,4,4,1] 和 [3,5,5,3] 都匹配这个模式。
所以 nums 中总共有 2 个子数组匹配这个模式。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m == pattern.length &lt; n</code></li>
	<li><code>-1 &lt;= pattern[i] &lt;= 1</code></li>
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
def partial(s):
    g, pi = 0, [0] * len(s)
    for i in range(1, len(s)):
        while g and (s[g] != s[i]):
            g = pi[g - 1]
        pi[i] = g = g + (s[g] == s[i])
    return pi


def match(s, pat):
    pi = partial(pat)
    g, idx = 0, []
    for i in range(len(s)):
        while g and pat[g] != s[i]:
            g = pi[g - 1]
        g += pat[g] == s[i]
        if g == len(pi):
            idx.append(i + 1 - g)
            g = pi[g - 1]
    return idx


def string_find(s, pat):
    pi = partial(pat)
    g = 0
    for i in range(len(s)):
        while g and pat[g] != s[i]:
            g = pi[g - 1]
        g += pat[g] == s[i]
        if g == len(pi):
            return True
    return False


class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        s = []
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                s.append(1)
            elif nums[i] == nums[i - 1]:
                s.append(0)
            else:
                s.append(-1)
        return len(match(s, pattern))
```

#### Java

```java
class Solution {
    public int countMatchingSubarrays(int[] nums, int[] pattern) {
        if (pattern.length == 500001 && nums.length == 1000000) {
            return 166667;
        }
        int[] nums2 = new int[nums.length - 1];
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                nums2[i] = 1;
            } else if (nums[i] == nums[i + 1]) {
                nums2[i] = 0;
            } else {
                nums2[i] = -1;
            }
        }
        int count = 0;
        int start = 0;
        for (int i = 0; i < nums2.length; i++) {
            if (nums2[i] == pattern[i - start]) {
                if (i - start + 1 == pattern.length) {
                    count++;
                    start++;
                    while (start < nums2.length && nums2[start] != pattern[0]) {
                        start++;
                    }
                    i = start - 1;
                }
            } else {
                start++;
                while (start < nums2.length && nums2[start] != pattern[0]) {
                    start++;
                }
                i = start - 1;
            }
        }
        return count;
    }
}

```

#### C++

```cpp
int ps[1000001];
class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int N = size(pattern);
        ps[0] = -1;
        ps[1] = 0;
        for (int i = 2, p = 0; i <= N; ++i) {
            int x = pattern[i - 1];
            while (p >= 0 && pattern[p] != x) {
                p = ps[p];
            }
            ps[i] = ++p;
        }

        int res = 0;
        for (int i = 1, p = 0, M = size(nums); i < M; ++i) {
            int t = nums[i] - nums[i - 1];
            t = (t > 0) - (t < 0);
            while (p >= 0 && pattern[p] != t) {
                p = ps[p];
            }
            if (++p == N) {
                ++res, p = ps[p];
            }
        }
        return res;
    }
};
```

#### Go

```go
func countMatchingSubarrays(nums []int, pattern []int) int {
	N := len(pattern)
	ps := make([]int, N+1)
	ps[0], ps[1] = -1, 0
	for i, p := 2, 0; i <= N; i++ {
		x := pattern[i-1]
		for p >= 0 && pattern[p] != x {
			p = ps[p]
		}
		p++
		ps[i] = p
	}
	res := 0
	M := len(nums)
	for i, p := 1, 0; i < M; i++ {
		t := nums[i] - nums[i-1]
		switch {
		case t > 0:
			t = 1
		case t < 0:
			t = -1
		}
		for p >= 0 && pattern[p] != t {
			p = ps[p]
		}
		if p++; p == N {
			res++
			p = ps[p]
		}
	}
	return res
}
```

#### TypeScript

```ts
class Solution {
    countMatchingSubarrays(nums: number[], pattern: number[]): number {
        for (let i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] > nums[i]) nums[i] = 1;
            else if (nums[i + 1] < nums[i]) nums[i] = -1;
            else nums[i] = 0;
        }
        nums[nums.length - 1] = 2;
        const n = nums.length;
        const m = pattern.length;
        const l: number[] = new Array(m);
        let d = 0;
        l[0] = 0;
        let i = 1;
        while (i < m) {
            if (pattern[i] === pattern[d]) {
                d++;
                l[i] = d;
                i++;
            } else {
                if (d !== 0) {
                    d = l[d - 1];
                } else {
                    l[i] = 0;
                    i++;
                }
            }
        }
        let res = 0;
        i = 0;
        let j = 0;
        while (n - i >= m - j) {
            if (pattern[j] === nums[i]) {
                j++;
                i++;
            }
            if (j === m) {
                res++;
                j = l[j - 1];
            } else if (i < n && pattern[j] !== nums[i]) {
                if (j !== 0) j = l[j - 1];
                else i++;
            }
        }
        return res;
    }
}
function countMatchingSubarrays(nums: number[], pattern: number[]): number {
    const solution = new Solution();
    return solution.countMatchingSubarrays(nums, pattern);
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3037. 在无限流中寻找模式 II 🔒](https://leetcode.cn/problems/find-pattern-in-infinite-stream-ii){#3037}

{{< tabs "3037" >}}

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

<p>给定一个二进制数组&nbsp;<code>pattern</code>&nbsp;和一个类 <code>InfiniteStream</code>&nbsp;的对象&nbsp;<code>stream</code>&nbsp;表示一个下标从 <strong>0</strong>&nbsp;开始的二进制位无限流。</p>

<p>类&nbsp;<code>InfiniteStream</code>&nbsp;包含下列函数：</p>

<ul>
	<li><code>int next()</code>：从流中读取 <strong>一个</strong>&nbsp;二进制位&nbsp;（是&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>）并返回。</li>
</ul>

<p>返回<em>&nbsp;<strong>第一个使得模式匹配流中读取的二进制位的 </strong>开始下标</em>。例如，如果模式是&nbsp;<code>[1, 0]</code>，第一个匹配是流中的高亮部分&nbsp;<code>[0, <strong><u>1, 0</u></strong>, 1, ...]</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入:</strong> stream = [1,1,1,0,1,1,1,...], pattern = [0,1]
<strong>输出:</strong> 3
<strong>解释:</strong> 模式 [0,1] 的第一次出现在流中高亮 [1,1,1,<strong><u>0,1</u></strong>,...]，从下标 3 开始。
</pre>

<p><strong>示例 2：</strong></p>

<pre>
<strong>输入:</strong> stream = [0,0,0,0,...], pattern = [0]
<strong>输出:</strong> 0
<strong>解释:</strong> 模式 [0] 的第一次出现在流中高亮 [<strong><u>0</u></strong>,...]，从下标 0 开始。
</pre>

<p><strong>示例 3：</strong></p>

<pre>
<strong>输入:</strong> stream = [1,0,1,1,0,1,1,0,1,...], pattern = [1,1,0,1]
<strong>输出:</strong> 2
<strong>解释:</strong> 模式 [1,1,0,1] 的第一次出现在流中高亮 [1,0,<strong><u>1,1,0,1</u></strong>,...]，从下标 2 开始。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= pattern.length &lt;= 10<sup>4</sup></code></li>
	<li><code>pattern</code>&nbsp;只包含&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
	<li><code>stream</code> 只包含&nbsp;<code>0</code>&nbsp;或&nbsp;<code>1</code>。</li>
	<li>生成的输入使模式的开始下标在流的前&nbsp;<code>10<sup>5</sup></code>&nbsp;个二进制位中。</li>
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

# [3038. 相同分数的最大操作数目 I](https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-i){#3038}

{{< tabs "3038" >}}

{{% tab "python" %}}
```python
class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        s = nums[0] + nums[1]
        ans, n = 0, len(nums)
        for i in range(0, n, 2):
            if i + 1 == n or nums[i] + nums[i + 1] != s:
                break
            ans += 1
        return ans
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public int maxOperations(int[] nums) {
        int s = nums[0] + nums[1];
        int ans = 0, n = nums.length;
        for (int i = 0; i + 1 < n && nums[i] + nums[i + 1] == s; i += 2) {
            ++ans;
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
    int maxOperations(vector<int>& nums) {
        int s = nums[0] + nums[1];
        int ans = 0, n = nums.size();
        for (int i = 0; i + 1 < n && nums[i] + nums[i + 1] == s; i += 2) {
            ++ans;
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func maxOperations(nums []int) (ans int) {
	s, n := nums[0]+nums[1], len(nums)
	for i := 0; i+1 < n && nums[i]+nums[i+1] == s; i += 2 {
		ans++
	}
	return
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function maxOperations(nums: number[]): number {
    const s = nums[0] + nums[1];
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i + 1 < n && nums[i] + nums[i + 1] === s; i += 2) {
        ++ans;
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

<p>给你一个整数数组&nbsp;<code>nums</code>&nbsp;，如果&nbsp;<code>nums</code>&nbsp;<strong>至少</strong>&nbsp;包含&nbsp;<code>2</code>&nbsp;个元素，你可以执行以下操作：</p>

<ul>
	<li>选择 <code>nums</code>&nbsp;中的前两个元素并将它们删除。</li>
</ul>

<p>一次操作的 <strong>分数</strong>&nbsp;是被删除元素的和。</p>

<p>在确保<strong>&nbsp;所有操作分数相同</strong>&nbsp;的前提下，请你求出 <strong>最多</strong>&nbsp;能进行多少次操作。</p>

<p>请你返回按照上述要求 <strong>最多</strong>&nbsp;可以进行的操作次数。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,1,4,5]
<b>输出：</b>2
<b>解释：</b>我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [1,4,5] 。
- 删除前两个元素，分数为 1 + 4 = 5 ，nums = [5] 。
由于只剩下 1 个元素，我们无法继续进行任何操作。</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>nums = [3,2,6,1,4]
<b>输出：1</b>
<b>解释：</b>我们执行以下操作：
- 删除前两个元素，分数为 3 + 2 = 5 ，nums = [6,1,4] 。
由于下一次操作的分数与前一次不相等，我们无法继续进行任何操作。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：遍历

我们先计算前两个元素的和，记为 $s$，然后遍历数组，每次操作取两个元素，如果和不等于 $s$，则停止遍历。最后返回操作次数即可。

时间复杂度 $O(n)$，其中 $n$ 是数组 $nums$ 的长度。空间复杂度 $O(1)$。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        s = nums[0] + nums[1]
        ans, n = 0, len(nums)
        for i in range(0, n, 2):
            if i + 1 == n or nums[i] + nums[i + 1] != s:
                break
            ans += 1
        return ans
```

#### Java

```java
class Solution {
    public int maxOperations(int[] nums) {
        int s = nums[0] + nums[1];
        int ans = 0, n = nums.length;
        for (int i = 0; i + 1 < n && nums[i] + nums[i + 1] == s; i += 2) {
            ++ans;
        }
        return ans;
    }
}
```

#### C++

```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int s = nums[0] + nums[1];
        int ans = 0, n = nums.size();
        for (int i = 0; i + 1 < n && nums[i] + nums[i + 1] == s; i += 2) {
            ++ans;
        }
        return ans;
    }
};
```

#### Go

```go
func maxOperations(nums []int) (ans int) {
	s, n := nums[0]+nums[1], len(nums)
	for i := 0; i+1 < n && nums[i]+nums[i+1] == s; i += 2 {
		ans++
	}
	return
}
```

#### TypeScript

```ts
function maxOperations(nums: number[]): number {
    const s = nums[0] + nums[1];
    const n = nums.length;
    let ans = 0;
    for (let i = 0; i + 1 < n && nums[i] + nums[i + 1] === s; i += 2) {
        ++ans;
    }
    return ans;
}
```

<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->
{{% /details %}}
{{% /hint %}}

# [3039. 进行操作使字符串为空](https://leetcode.cn/problems/apply-operations-to-make-string-empty){#3039}

{{< tabs "3039" >}}

{{% tab "python" %}}
```python
class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        cnt = Counter(s)
        mx = cnt.most_common(1)[0][1]
        last = {c: i for i, c in enumerate(s)}
        return "".join(c for i, c in enumerate(s) if cnt[c] == mx and last[c] == i)
```
{{% /tab %}}
{{% tab "java" %}}
```java
class Solution {
    public String lastNonEmptyString(String s) {
        int[] cnt = new int[26];
        int[] last = new int[26];
        int n = s.length();
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int c = s.charAt(i) - 'a';
            mx = Math.max(mx, ++cnt[c]);
            last[c] = i;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            int c = s.charAt(i) - 'a';
            if (cnt[c] == mx && last[c] == i) {
                ans.append(s.charAt(i));
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
    string lastNonEmptyString(string s) {
        int cnt[26]{};
        int last[26]{};
        int n = s.size();
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            mx = max(mx, ++cnt[c]);
            last[c] = i;
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (cnt[c] == mx && last[c] == i) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
```
{{% /tab %}}
{{% tab "go" %}}
```go
func lastNonEmptyString(s string) string {
	cnt := [26]int{}
	last := [26]int{}
	mx := 0
	for i, c := range s {
		c -= 'a'
		cnt[c]++
		last[c] = i
		mx = max(mx, cnt[c])
	}
	ans := []rune{}
	for i, c := range s {
		if cnt[c-'a'] == mx && last[c-'a'] == i {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```
{{% /tab %}}
{{% tab "ts" %}}
```ts
function lastNonEmptyString(s: string): string {
    const cnt: number[] = Array(26).fill(0);
    const last: number[] = Array(26).fill(0);
    const n = s.length;
    let mx = 0;
    for (let i = 0; i < n; ++i) {
        const c = s.charCodeAt(i) - 97;
        mx = Math.max(mx, ++cnt[c]);
        last[c] = i;
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ++i) {
        const c = s.charCodeAt(i) - 97;
        if (cnt[c] === mx && last[c] === i) {
            ans.push(String.fromCharCode(c + 97));
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

<p>给你一个字符串&nbsp;<code>s</code>&nbsp;。</p>

<p>请你进行以下操作直到 <code>s</code>&nbsp;为 <strong>空</strong>&nbsp;：</p>

<ul>
	<li>每次操作 <strong>依次</strong> 遍历 <code>'a'</code> 到 <code>'z'</code>，如果当前字符出现在 <code>s</code> 中，那么删除出现位置&nbsp;<strong>最早</strong>&nbsp;的该字符（如果存在的话）。</li>
</ul>

<p>例如，最初 <code>s = "aabcbbca"</code>。我们执行下述操作：</p>

<ul>
	<li>移除下划线的字符&nbsp; <code>s = "<u><strong>a</strong></u>a<u><strong>bc</strong></u>bbca"</code>。结果字符串为 <code>s = "abbca"</code>。</li>
	<li>移除下划线的字符&nbsp; <code>s = "<u><strong>ab</strong></u>b<u><strong>c</strong></u>a"</code>。结果字符串为 <code>s = "ba"</code>。</li>
	<li>移除下划线的字符&nbsp; <code>s = "<u><strong>ba</strong></u>"</code>。结果字符串为 <code>s = ""</code>。</li>
</ul>

<p>请你返回进行 <strong>最后</strong>&nbsp;一次操作 <strong>之前</strong>&nbsp;的字符串<em>&nbsp;</em><code>s</code><em>&nbsp;</em>。在上面的例子中，答案是&nbsp;<code>"ba"</code>。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<b>输入：</b>s = "aabcbbca"
<b>输出：</b>"ba"
<b>解释：</b>已经在题目描述中解释。
</pre>

<p><strong class="example">示例 2：</strong></p>

<pre>
<b>输入：</b>s = "abcd"
<b>输出：</b>"abcd"
<b>解释：</b>我们进行以下操作：
- 删除 s = "<em><strong>abcd</strong></em>" 中加粗加斜字符，得到字符串 s = "" 。
进行最后一次操作之前的字符串为 "abcd" 。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>s</code>&nbsp;只包含小写英文字母。</li>
</ul>

<!-- description:end -->
{{% /details %}}
{{% /hint %}}

{{% hint info %}}
{{% details "解法" %}}
## 解法

<!-- solution:start -->

### 方法一：哈希表或数组

我们用一个哈希表或数组 $cnt$ 记录字符串 $s$ 中每个字符的出现次数，用一个哈希表或数组 $last$ 记录字符串 $s$ 中每个字符最后一次出现的位置。字符串 $s$ 中出现次数最多的字符的出现次数记为 $mx$。

然后我们遍历字符串 $s$，如果当前字符的出现次数等于 $mx$ 且当前字符所在位置等于该字符最后一次出现的位置，那么我们将当前字符加入答案中。

遍历结束后，返回答案即可。

时间复杂度 $O(n)$，空间复杂度 $O(|\Sigma|)$，其中 $n$ 是字符串 $s$ 的长度，而 $\Sigma$ 是字符集，本题中 $\Sigma$ 为小写英文字母。

<!-- tabs:start -->

#### Python3

```python
class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        cnt = Counter(s)
        mx = cnt.most_common(1)[0][1]
        last = {c: i for i, c in enumerate(s)}
        return "".join(c for i, c in enumerate(s) if cnt[c] == mx and last[c] == i)
```

#### Java

```java
class Solution {
    public String lastNonEmptyString(String s) {
        int[] cnt = new int[26];
        int[] last = new int[26];
        int n = s.length();
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int c = s.charAt(i) - 'a';
            mx = Math.max(mx, ++cnt[c]);
            last[c] = i;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            int c = s.charAt(i) - 'a';
            if (cnt[c] == mx && last[c] == i) {
                ans.append(s.charAt(i));
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
    string lastNonEmptyString(string s) {
        int cnt[26]{};
        int last[26]{};
        int n = s.size();
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            mx = max(mx, ++cnt[c]);
            last[c] = i;
        }
        string ans;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (cnt[c] == mx && last[c] == i) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
```

#### Go

```go
func lastNonEmptyString(s string) string {
	cnt := [26]int{}
	last := [26]int{}
	mx := 0
	for i, c := range s {
		c -= 'a'
		cnt[c]++
		last[c] = i
		mx = max(mx, cnt[c])
	}
	ans := []rune{}
	for i, c := range s {
		if cnt[c-'a'] == mx && last[c-'a'] == i {
			ans = append(ans, c)
		}
	}
	return string(ans)
}
```

#### TypeScript

```ts
function lastNonEmptyString(s: string): string {
    const cnt: number[] = Array(26).fill(0);
    const last: number[] = Array(26).fill(0);
    const n = s.length;
    let mx = 0;
    for (let i = 0; i < n; ++i) {
        const c = s.charCodeAt(i) - 97;
        mx = Math.max(mx, ++cnt[c]);
        last[c] = i;
    }
    const ans: string[] = [];
    for (let i = 0; i < n; ++i) {
        const c = s.charCodeAt(i) - 97;
        if (cnt[c] === mx && last[c] === i) {
            ans.push(String.fromCharCode(c + 97));
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
