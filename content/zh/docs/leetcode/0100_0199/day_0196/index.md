---
title: "day_0196 "
date: 2025-09-21T07:53:36+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0196 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import pandas as pd


# Modify Person in place
def delete_duplicate_emails(person: pd.DataFrame) -> None:
    # Sort the rows based on id (Ascending order)
    person.sort_values(by="id", ascending=True, inplace=True)
    # Drop the duplicates based on email.
    person.drop_duplicates(subset="email", keep="first", inplace=True) 
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

## LeetCode_0196  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}


```python
import pandas as pd


# 原地修改Person表
def delete_duplicate_emails(person: pd.DataFrame) -> None:
    # 按id升序排序（从小到大）
    person.sort_values(by="id", ascending=True, inplace=True)
    # 根据email字段删除重复行，保留第一个出现的记录
    person.drop_duplicates(subset="email", keep="first", inplace=True) 
```
``

{{% /tab %}}
{{% tab "cpp " %}}

```cpp 
 
```

{{% /tab %}}
{{% tab "java " %}}

```java 
 
```

{{% /tab %}}{{< /tabs>}}

## LeetCode_0196  数学解释

```python 
import pandas as pd


# Modify Person in place
def delete_duplicate_emails(person: pd.DataFrame) -> None:
    # Sort the rows based on id (Ascending order)
    person.sort_values(by="id", ascending=True, inplace=True)
    # Drop the duplicates based on email.
    person.drop_duplicates(subset="email", keep="first", inplace=True) 
```


这段代码使用了两个重要的数学思想：

## 1. **排序思想（Ordering Principle）**
- 通过 `sort_values(by="id", ascending=True)` 对数据进行排序
- 这体现了数学中的**全序关系**，确保所有记录按照id的数值大小有序排列
- 排序后，较小的id值会排在前面，为后续的去重操作建立确定性

## 2. **集合论思想（Set Theory）**
- 使用 `drop_duplicates(subset="email")` 去除重复的email
- 这对应数学中的**集合的唯一性公理**：集合中的元素都是唯一的
- `keep="first"` 参数体现了**选择函数**的概念，在多个相同email的记录中，选择最先出现的（即id最小的）

## 数学原理的结合：
代码通过先排序再去重的策略，实现了：
- **确定性**：相同的输入总是产生相同的输出
- **最小id保留原则**：对于重复email，总是保留id最小的记录
- **函数映射的唯一性**：确保每个email只对应一个person记录

这种处理方式在数学上等价于：对于每个email，选择其对应的最小id值，然后构建一个从email到person记录的单射函数。


