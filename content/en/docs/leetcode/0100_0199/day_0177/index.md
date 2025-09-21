---
title: "day_0177 "
date: 2025-09-21T08:34:47+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0177 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique_salaries = employee.salary.unique()
    if len(unique_salaries) < N:
        return pd.DataFrame([np.NaN], columns=[f"getNthHighestSalary({N})"])
    else:
        salary = sorted(unique_salaries, reverse=True)[N - 1]
        return pd.DataFrame([salary], columns=[f"getNthHighestSalary({N})"]) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0177  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python
import pandas as pd
import numpy as np  # 需要导入numpy库来使用np.NaN


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    # 获取唯一的薪资值，去除重复项
    unique_salaries = employee.salary.unique()
    
    # 如果唯一薪资数量小于N，说明没有第N高的薪资，返回NaN
    if len(unique_salaries) < N:
        return pd.DataFrame([np.NaN], columns=[f"getNthHighestSalary({N})"])
    else:
        # 对唯一薪资进行降序排序，然后取第N-1个元素（因为索引从0开始）
        salary = sorted(unique_salaries, reverse=True)[N - 1]
        # 返回包含第N高薪资的DataFrame
        return pd.DataFrame([salary], columns=[f"getNthHighestSalary({N})"]) 
```

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0177  数学解释

```python 
import pandas as pd


def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique_salaries = employee.salary.unique()
    if len(unique_salaries) < N:
        return pd.DataFrame([np.NaN], columns=[f"getNthHighestSalary({N})"])
    else:
        salary = sorted(unique_salaries, reverse=True)[N - 1]
        return pd.DataFrame([salary], columns=[f"getNthHighestSalary({N})"]) 
```


这段代码使用了以下数学思想：

1. **集合论思想**：通过`unique()`方法获取唯一值，这相当于数学中的集合操作，去除重复元素，得到唯一的薪资集合。

2. **排序与选择**：使用`sorted(unique_salaries, reverse=True)`对唯一薪资进行降序排序，这体现了数学中的排序和选择思想。

3. **索引与位置关系**：通过`[N - 1]`访问第N大的薪资，这里体现了数学中的索引映射关系（第N大对应索引位置N-1）。

4. **边界条件处理**：检查`len(unique_salaries) < N`，这体现了数学中的边界条件和异常情况处理思想。

5. **函数映射思想**：整个函数将输入数据映射到特定的输出结果，体现了数学中的函数概念。

从数学角度看，这是一个典型的"选择第N大元素"问题，算法的时间复杂度主要由排序决定，为O(n log n)，其中n是唯一薪资的数量。

