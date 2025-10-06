---
title: "2985_CalculateCompressedMean"
date: 2025-10-06T00:42:37+08:00
weight: 2985
tags: [数据库]
---


{{< katex />}}

{{< badge title="Difficulty" value="简单" >}}

<!-- problem:start -->

# [2985. 计算订单平均商品数量 🔒](https://leetcode.cn/problems/calculate-compressed-mean)

[English Version](../en/2985-85/2985_CalculateCompressedMean)

## 题目描述

<!-- description:start -->

<p>表：&nbsp;<code>Orders</code></p>

<pre>
+-------------------+------+
| Column Name       | Type |
+-------------------+------+
| order_id          | int  |
| item_count        | int  |
| order_occurrences | int  |
+-------------------+------+
order_id 是这张表具有唯一值的列。
这张表包括 order_id, item_count,和 order_occurrences。
</pre>

<p>编写一个计算每个订单的 <strong>平均</strong> 商品数量的解决方案，保留 <code>2</code> <strong>位小数。</strong></p>

<p>以<em>&nbsp;<strong>任意</strong>&nbsp;顺序返回结果表。</em></p>

<p>结果格式如下例所示。</p>

<p>&nbsp;</p>

<p><b>示例 1:</b></p>

<pre>
<b>输入：</b>
Orders table:
+----------+------------+-------------------+
| order_id | item_count | order_occurrences | 
+----------+------------+-------------------+
| 10       | 1          | 500               | 
| 11       | 2          | 1000              |     
| 12       | 3          | 800               |  
| 13       | 4          | 1000              | 
+----------+------------+-------------------+
<b>输出</b>
+-------------------------+
| average_items_per_order | 
+-------------------------+
| 2.70                    |
+-------------------------+
<b>解释</b>
计算如下：
 - 总商品数：(1 * 500) + (2 * 1000) + (3 * 800) + (4 * 1000) = 8900 
 - 总订单数：500 + 1000 + 800 + 1000 = 3300 
 - 因此，每个订单的平均商品数量为 8900 / 3300 = 2.70
</pre>

<!-- description:end -->

## 解法

<!-- solution:start -->

### 方法一：求和

我们使用 `SUM` 函数求出总的商品数量和总的订单数，然后相除，得到平均值，最后使用 `ROUND` 函数保留两位小数即可。

<!-- tabs:start -->

#### MySQL



<!-- tabs:end -->

<!-- solution:end -->

<!-- problem:end -->

{{< tabs id >}}
{{% tab "sql" %}}
```sql
# Write your MySQL query statement below
SELECT
    ROUND(
        SUM(item_count * order_occurrences) / SUM(order_occurrences),
        2
    ) AS average_items_per_order
FROM Orders;
```
{{% /tab %}}
{{< /tabs>}}

