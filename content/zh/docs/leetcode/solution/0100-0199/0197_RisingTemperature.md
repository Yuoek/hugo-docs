---
title: "0197_RisingTemperature"
date: 2025-10-06T00:42:37+08:00
weight: 0197
tags: [数据库]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [197. 上升的温度](https://leetcode.cn/problems/rising-temperature)

[English Version](../en/0197-97/0197_RisingTemperature)

## 题目描述

<!-- description:start -->

<div class="original__bRMd">
<div>
<p>表：&nbsp;<code>Weather</code></p>

<pre>
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id 是该表具有唯一值的列。
没有具有相同 recordDate 的不同行。
该表包含特定日期的温度信息</pre>

<p>&nbsp;</p>

<p>编写解决方案，找出与之前（昨天的）日期相比温度更高的所有日期的 <code>id</code> 。</p>

<p>返回结果 <strong>无顺序要求</strong> 。</p>

<p>结果格式如下例子所示。</p>

<p>&nbsp;</p>

<p><strong class="example">示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Weather 表：
+----+------------+-------------+
| id | recordDate | Temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
<strong>输出：</strong>
+----+
| id |
+----+
| 2  |
| 4  |
+----+
<strong>解释：</strong>
2015-01-02 的温度比前一天高（10 -&gt; 25）
2015-01-04 的温度比前一天高（20 -&gt; 30）</pre>
</div>
</div>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：自连接 + DATEDIFF/SUBDATE 函数

我们可以通过自连接的方式，将 `Weather` 表中的每一行与它的前一行进行比较，如果温度更高，并且日期相差一天，那么就是我们要找的结果。

<!-- tabs:start -->

#### Python3



#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- solution:start -->

### 方法二

<!-- tabs:start -->

#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "python" %}}
```python
import pandas as pd


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)
    return weather[
        (weather.temperature.diff() > 0) & (weather.recordDate.diff().dt.days == 1)
    ][["id"]]
```
{{% /tab %}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT w1.id
FROM
    Weather AS w1
    JOIN Weather AS w2
        ON SUBDATE(w1.recordDate, 1) = w2.recordDate AND w1.temperature > w2.temperature;
```
{{% /tab %}}
{{< /tabs>}}

{{% hint info %}}
{{% details "python 可视化" %}}
{{< pythontutor width="100%" height="800" language="python" >}}
import pandas as pd


def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    weather.sort_values(by="recordDate", inplace=True)
    return weather[
        (weather.temperature.diff() > 0) & (weather.recordDate.diff().dt.days == 1)
    ][["id"]]
{{< /pythontutor >}}
{{% /details %}}
{{% /hint %}}