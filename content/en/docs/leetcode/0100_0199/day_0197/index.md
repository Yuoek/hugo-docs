---
title: "day_0197 "
date: 2025-09-21T07:50:10+08:00
categories: ""
tags: ""
series: ""
series_order: ""
type: ""
---

{{< katex />}}


## LeetCode_0197 

{{< tabs id="1" >}}
{{% tab "python " %}}

```python 
import pandas as pd


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)
    return weather[
        (weather.temperature.diff() > 0) & (weather.recordDate.diff().dt.days == 1)
    ][["id"]] 
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

## LeetCode_0197  行解释

{{< tabs id="2" >}}
{{% tab "python " %}}

```python 
import pandas as pd  # 导入pandas库，用于数据处理和分析


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)  # 按日期升序排序天气数据
    return weather[
        (weather.temperature.diff() > 0) & (weather.recordDate.diff().dt.days == 1)  # 筛选条件：温度比前一天高且日期差正好为1天
    ][["id"]]  # 返回满足条件的记录ID
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

## LeetCode_0197  数学解释

```python 
import pandas as pd


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)
    return weather[
        (weather.temperature.diff() > 0) & (weather.recordDate.diff().dt.days == 1)
    ][["id"]] 
```


这段代码使用了**差分思想**和**滑动窗口比较**的数学思想：

## 数学思想解析：

1. **差分运算 (Finite Difference)**：
   - `weather.temperature.diff()` 计算相邻两天的温度差值
   - 这是数值分析中常用的有限差分法，用于近似导数

2. **滑动窗口比较**：
   - 代码通过 `diff()` 函数隐式地创建了一个大小为2的滑动窗口
   - 在每个窗口内比较当前元素与前一个元素

3. **条件筛选的布尔代数**：
   - 使用逻辑与运算 `&` 组合两个条件：
     - 温度差 > 0（温度上升）
     - 日期差 = 1天（连续两天）

## 数学表达式：
对于时间序列数据中的每个点 i，筛选条件为：
```
(temperature[i] - temperature[i-1] > 0) ∧ (recordDate[i] - recordDate[i-1] = 1天)
```

## 算法复杂度：
- 排序：O(n log n)
- 差分运算：O(n)
- 总体复杂度主要由排序决定

这种差分方法在时间序列分析中非常高效，避免了显式的循环遍历。


