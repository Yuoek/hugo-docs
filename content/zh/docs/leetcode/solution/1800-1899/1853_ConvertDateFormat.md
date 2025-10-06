---
title: "1853_ConvertDateFormat"
date: 2025-10-06T00:42:37+08:00
weight: 1853
tags: [数据库]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [1853. 转换日期格式 🔒](https://leetcode.cn/problems/convert-date-format)

[English Version](../en/1853-53/1853_ConvertDateFormat)

## 题目描述

<!-- description:start -->

<p>表: <code>Days</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| day         | date |
+-------------+------+
day 是这个表的主键。
</pre>

<p>&nbsp;</p>

<p>给定一个<code>Days</code>表，请你编写SQL查询语句，将<code>Days</code>表中的每一个日期转化为<code>"day_name, month_name day, year"</code>格式的字符串。</p>

<p>返回的结果表 <strong>不计顺序</strong> 。</p>

<p>查询结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入：</strong>
Days table:
+------------+
| day        |
+------------+
| 2022-04-12 |
| 2021-08-09 |
| 2020-06-26 |
+------------+
<strong>输出：</strong>
+-------------------------+
| day                     |
+-------------------------+
| Tuesday, April 12, 2022 |
| Monday, August 9, 2021  |
| Friday, June 26, 2020   |
+-------------------------+
<strong>解释：</strong>请注意，输出对大小写敏感。</pre>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一

<!-- tabs:start -->

#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT DATE_FORMAT(day, '%W, %M %e, %Y') AS day FROM Days;
```
{{% /tab %}}
{{< /tabs>}}

