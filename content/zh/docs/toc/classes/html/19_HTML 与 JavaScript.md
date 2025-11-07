---
title: "HTML 与 JavaScript"
date: 2025-10-25T09:02:10+08:00
weight: 19
---

{{< markmap >}}
### 1 [HTML 基础](#1)
#### 1.1 [HTML 概述](#1)
#### 1.2 [HTML 发展历史与版本演进](#1)
#### 1.3 [HTML 文档结构与基本语法](#1)
#### 1.4 [HTML 标签分类与语义化](#1)
#### 1.5 [DOCTYPE 声明与文档类型](#1)
#### 1.6 [常用 HTML 标签](#1)
#### 1.7 [文本标签：h1-h6、p、span、strong、em](#1)
#### 1.8 [列表标签：ul、ol、li、dl、dt、dd](#1)
#### 1.9 [表格标签：table、tr、td、th、thead、tbody](#1)
#### 1.10 [表单标签：form、input、textarea、select、button](#1)
#### 1.11 [多媒体标签：img、audio、video、canvas](#1)
#### 1.12 [HTML5 新特性](#1)
#### 1.13 [语义化标签：header、nav、section、article、footer](#1)
#### 1.14 [表单增强：新的 input 类型和属性](#1)
#### 1.15 [多媒体支持：audio 和 video 标签](#1)
#### 1.16 [Canvas 绘图与 SVG 图形](#1)
#### 1.17 [本地存储：localStorage 和 sessionStorage](#1)
### 2 [JavaScript 基础](#2)
#### 2.1 [JavaScript 核心语法](#2)
#### 2.2 [变量声明：var、let、const](#2)
#### 2.3 [数据类型：原始类型与引用类型](#2)
#### 2.4 [运算符：算术、比较、逻辑、赋值运算符](#2)
#### 2.5 [流程控制：if-else、switch、for、while](#2)
#### 2.6 [函数与作用域](#2)
#### 2.7 [函数定义与调用](#2)
#### 2.8 [参数传递与返回值](#2)
#### 2.9 [作用域链与闭包](#2)
#### 2.10 [箭头函数与 this 绑定](#2)
#### 2.11 [对象与数组](#2)
#### 2.12 [对象创建与属性访问](#2)
#### 2.13 [数组方法与操作](#2)
#### 2.14 [JSON 数据格式](#2)
#### 2.15 [原型与原型链](#2)
### 3 [DOM 操作](#3)
#### 3.1 [DOM 基础概念](#3)
#### 3.2 [DOM 树结构解析](#3)
#### 3.3 [节点类型与关系](#3)
#### 3.4 [DOM 查询方法：getElementById、querySelector](#3)
#### 3.5 [DOM 遍历与导航](#3)
#### 3.6 [DOM 操作技术](#3)
#### 3.7 [元素创建与删除](#3)
#### 3.8 [属性操作与样式修改](#3)
#### 3.9 [内容插入与替换](#3)
#### 3.10 [事件处理机制](#3)
#### 3.11 [事件系统](#3)
#### 3.12 [事件流与事件冒泡](#3)
#### 3.13 [事件委托模式](#3)
#### 3.14 [常用事件类型：click、submit、keydown](#3)
#### 3.15 [自定义事件与事件对象](#3)
### 4 [HTML 与 JavaScript 交互](#4)
#### 4.1 [脚本引入方式](#4)
#### 4.2 [内联脚本与外部脚本](#4)
#### 4.3 [script 标签属性：async、defer](#4)
#### 4.4 [模块化与 ES6 模块](#4)
#### 4.5 [表单处理](#4)
#### 4.6 [表单验证技术](#4)
#### 4.7 [表单数据获取与提交](#4)
#### 4.8 [文件上传处理](#4)
#### 4.9 [富文本编辑器集成](#4)
#### 4.10 [数据存储与通信](#4)
#### 4.11 [Cookie 操作与管理](#4)
#### 4.12 [Web Storage API 使用](#4)
#### 4.13 [AJAX 技术与 Fetch API](#4)
#### 4.14 [WebSocket 实时通信](#4)
### 5 [现代 Web 开发实践](#5)
#### 5.1 [性能优化](#5)
#### 5.2 [页面加载优化策略](#5)
#### 5.3 [代码分割与懒加载](#5)
#### 5.4 [缓存机制与资源压缩](#5)
#### 5.5 [渲染性能优化](#5)
#### 5.6 [安全考虑](#5)
#### 5.7 [XSS 攻击与防护](#5)
#### 5.8 [CSRF 攻击与防护](#5)
#### 5.9 [内容安全策略 CSP](#5)
#### 5.10 [数据验证与清理](#5)
#### 5.11 [响应式设计](#5)
#### 5.12 [媒体查询与响应式布局](#5)
#### 5.13 [移动端适配技术](#5)
#### 5.14 [渐进式 Web 应用 PWA](#5)
#### 5.15 [无障碍访问支持](#5)
### 6 [开发工具与调试](#6)
#### 6.1 [开发环境搭建](#6)
#### 6.2 [代码编辑器配置](#6)
#### 6.3 [浏览器开发者工具](#6)
#### 6.4 [构建工具：Webpack、Vite](#6)
#### 6.5 [版本控制与 Git](#6)
#### 6.6 [调试技术](#6)
#### 6.7 [控制台调试方法](#6)
#### 6.8 [断点设置与单步调试](#6)
#### 6.9 [网络请求分析](#6)
#### 6.10 [性能监控与分析](#6)
#### 6.11 [测试与部署](#6)
#### 6.12 [单元测试框架](#6)
#### 6.13 [端到端测试工具](#6)
#### 6.14 [代码质量检查](#6)
#### 6.15 [部署流程与持续集成](#6)
{{< /markmap >}}

{{< revealjs theme="white" transition="slide" progress="true" controls="true" history="true"  >}}



### 1 HTML 基础



---
### 1 HTML 基础
___
#### 1.1 HTML 概述
___
#### 1.2 HTML 发展历史与版本演进
___
#### 1.3 HTML 文档结构与基本语法
___
#### 1.4 HTML 标签分类与语义化
___
#### 1.5 DOCTYPE 声明与文档类型
___
#### 1.6 常用 HTML 标签
___
#### 1.7 文本标签：h1-h6、p、span、strong、em
___
#### 1.8 列表标签：ul、ol、li、dl、dt、dd
___
#### 1.9 表格标签：table、tr、td、th、thead、tbody
___
#### 1.10 表单标签：form、input、textarea、select、button
___
#### 1.11 多媒体标签：img、audio、video、canvas
___
#### 1.12 HTML5 新特性
___
#### 1.13 语义化标签：header、nav、section、article、footer
___
#### 1.14 表单增强：新的 input 类型和属性
___
#### 1.15 多媒体支持：audio 和 video 标签
___
#### 1.16 Canvas 绘图与 SVG 图形
___
#### 1.17 本地存储：localStorage 和 sessionStorage
### 2 JavaScript 基础



---
### 2 JavaScript 基础
___
#### 2.1 JavaScript 核心语法
___
#### 2.2 变量声明：var、let、const
___
#### 2.3 数据类型：原始类型与引用类型
___
#### 2.4 运算符：算术、比较、逻辑、赋值运算符
___
#### 2.5 流程控制：if-else、switch、for、while
___
#### 2.6 函数与作用域
___
#### 2.7 函数定义与调用
___
#### 2.8 参数传递与返回值
___
#### 2.9 作用域链与闭包
___
#### 2.10 箭头函数与 this 绑定
___
#### 2.11 对象与数组
___
#### 2.12 对象创建与属性访问
___
#### 2.13 数组方法与操作
___
#### 2.14 JSON 数据格式
___
#### 2.15 原型与原型链
### 3 DOM 操作



---
### 3 DOM 操作
___
#### 3.1 DOM 基础概念
___
#### 3.2 DOM 树结构解析
___
#### 3.3 节点类型与关系
___
#### 3.4 DOM 查询方法：getElementById、querySelector
___
#### 3.5 DOM 遍历与导航
___
#### 3.6 DOM 操作技术
___
#### 3.7 元素创建与删除
___
#### 3.8 属性操作与样式修改
___
#### 3.9 内容插入与替换
___
#### 3.10 事件处理机制
___
#### 3.11 事件系统
___
#### 3.12 事件流与事件冒泡
___
#### 3.13 事件委托模式
___
#### 3.14 常用事件类型：click、submit、keydown
___
#### 3.15 自定义事件与事件对象
### 4 HTML 与 JavaScript 交互



---
### 4 HTML 与 JavaScript 交互
___
#### 4.1 脚本引入方式
___
#### 4.2 内联脚本与外部脚本
___
#### 4.3 script 标签属性：async、defer
___
#### 4.4 模块化与 ES6 模块
___
#### 4.5 表单处理
___
#### 4.6 表单验证技术
___
#### 4.7 表单数据获取与提交
___
#### 4.8 文件上传处理
___
#### 4.9 富文本编辑器集成
___
#### 4.10 数据存储与通信
___
#### 4.11 Cookie 操作与管理
___
#### 4.12 Web Storage API 使用
___
#### 4.13 AJAX 技术与 Fetch API
___
#### 4.14 WebSocket 实时通信
### 5 现代 Web 开发实践



---
### 5 现代 Web 开发实践
___
#### 5.1 性能优化
___
#### 5.2 页面加载优化策略
___
#### 5.3 代码分割与懒加载
___
#### 5.4 缓存机制与资源压缩
___
#### 5.5 渲染性能优化
___
#### 5.6 安全考虑
___
#### 5.7 XSS 攻击与防护
___
#### 5.8 CSRF 攻击与防护
___
#### 5.9 内容安全策略 CSP
___
#### 5.10 数据验证与清理
___
#### 5.11 响应式设计
___
#### 5.12 媒体查询与响应式布局
___
#### 5.13 移动端适配技术
___
#### 5.14 渐进式 Web 应用 PWA
___
#### 5.15 无障碍访问支持
### 6 开发工具与调试





---
### 6 开发工具与调试
___
#### 6.1 开发环境搭建
___
#### 6.2 代码编辑器配置
___
#### 6.3 浏览器开发者工具
___
#### 6.4 构建工具：Webpack、Vite
___
#### 6.5 版本控制与 Git
___
#### 6.6 调试技术
___
#### 6.7 控制台调试方法
___
#### 6.8 断点设置与单步调试
___
#### 6.9 网络请求分析
___
#### 6.10 性能监控与分析
___
#### 6.11 测试与部署
___
#### 6.12 单元测试框架
___
#### 6.13 端到端测试工具
___
#### 6.14 代码质量检查
___
#### 6.15 部署流程与持续集成
{{< /revealjs >}}




### 1 HTML 基础{#1}



{{% columns ratio="1:1" %}}
```mermaid
mindmap
    id1[HTML 基础]
        id1-1[HTML 概述]
        id1-2[HTML 发展历史与版本演进]
        id1-3[HTML 文档结构与基本语法]
        id1-4[HTML 标签分类与语义化]
        id1-5[DOCTYPE 声明与文档类型]
        id1-6[常用 HTML 标签]
        id1-7[文本标签：h1-h6、p、span、strong、em]
        id1-8[列表标签：ul、ol、li、dl、dt、dd]
        id1-9[表格标签：table、tr、td、th、thead、tbody]
        id1-10[表单标签：form、input、textarea、select、button]
        id1-11[多媒体标签：img、audio、video、canvas]
        id1-12[HTML5 新特性]
        id1-13[语义化标签：header、nav、section、article、footer]
        id1-14[表单增强：新的 input 类型和属性]
        id1-15[多媒体支持：audio 和 video 标签]
        id1-16[Canvas 绘图与 SVG 图形]
        id1-17[本地存储：localStorage 和 sessionStorage]
```

<--->
{{% details "HTML 概述" %}}
{{% /details %}}
{{% details "HTML 发展历史与版本演进" %}}
{{% /details %}}
{{% details "HTML 文档结构与基本语法" %}}
{{% /details %}}
{{% details "HTML 标签分类与语义化" %}}
{{% /details %}}
{{% details "DOCTYPE 声明与文档类型" %}}
{{% /details %}}
{{% details "常用 HTML 标签" %}}
{{% /details %}}
{{% details "文本标签：h1-h6、p、span、strong、em" %}}
{{% /details %}}
{{% details "列表标签：ul、ol、li、dl、dt、dd" %}}
{{% /details %}}
{{% details "表格标签：table、tr、td、th、thead、tbody" %}}
{{% /details %}}
{{% details "表单标签：form、input、textarea、select、button" %}}
{{% /details %}}
{{% details "多媒体标签：img、audio、video、canvas" %}}
{{% /details %}}
{{% details "HTML5 新特性" %}}
{{% /details %}}
{{% details "语义化标签：header、nav、section、article、footer" %}}
{{% /details %}}
{{% details "表单增强：新的 input 类型和属性" %}}
{{% /details %}}
{{% details "多媒体支持：audio 和 video 标签" %}}
{{% /details %}}
{{% details "Canvas 绘图与 SVG 图形" %}}
{{% /details %}}
{{% details "本地存储：localStorage 和 sessionStorage" %}}
{{% /details %}}
{{% /columns %}}

### 2 JavaScript 基础{#2}



{{% columns ratio="1:1" %}}
{{% details "JavaScript 核心语法" %}}
{{% /details %}}
{{% details "变量声明：var、let、const" %}}
{{% /details %}}
{{% details "数据类型：原始类型与引用类型" %}}
{{% /details %}}
{{% details "运算符：算术、比较、逻辑、赋值运算符" %}}
{{% /details %}}
{{% details "流程控制：if-else、switch、for、while" %}}
{{% /details %}}
{{% details "函数与作用域" %}}
{{% /details %}}
{{% details "函数定义与调用" %}}
{{% /details %}}
{{% details "参数传递与返回值" %}}
{{% /details %}}
{{% details "作用域链与闭包" %}}
{{% /details %}}
{{% details "箭头函数与 this 绑定" %}}
{{% /details %}}
{{% details "对象与数组" %}}
{{% /details %}}
{{% details "对象创建与属性访问" %}}
{{% /details %}}
{{% details "数组方法与操作" %}}
{{% /details %}}
{{% details "JSON 数据格式" %}}
{{% /details %}}
{{% details "原型与原型链" %}}
{{% /details %}}
<--->
```mermaid
mindmap
    id2[JavaScript 基础]
        id2-1[JavaScript 核心语法]
        id2-2[变量声明：var、let、const]
        id2-3[数据类型：原始类型与引用类型]
        id2-4[运算符：算术、比较、逻辑、赋值运算符]
        id2-5[流程控制：if-else、switch、for、while]
        id2-6[函数与作用域]
        id2-7[函数定义与调用]
        id2-8[参数传递与返回值]
        id2-9[作用域链与闭包]
        id2-10[箭头函数与 this 绑定]
        id2-11[对象与数组]
        id2-12[对象创建与属性访问]
        id2-13[数组方法与操作]
        id2-14[JSON 数据格式]
        id2-15[原型与原型链]
```

{{% /columns %}}

### 3 DOM 操作{#3}



{{% columns ratio="1:1" %}}
```mermaid
mindmap
    id3[DOM 操作]
        id3-1[DOM 基础概念]
        id3-2[DOM 树结构解析]
        id3-3[节点类型与关系]
        id3-4[DOM 查询方法：getElementById、querySelector]
        id3-5[DOM 遍历与导航]
        id3-6[DOM 操作技术]
        id3-7[元素创建与删除]
        id3-8[属性操作与样式修改]
        id3-9[内容插入与替换]
        id3-10[事件处理机制]
        id3-11[事件系统]
        id3-12[事件流与事件冒泡]
        id3-13[事件委托模式]
        id3-14[常用事件类型：click、submit、keydown]
        id3-15[自定义事件与事件对象]
```

<--->
{{% details "DOM 基础概念" %}}
{{% /details %}}
{{% details "DOM 树结构解析" %}}
{{% /details %}}
{{% details "节点类型与关系" %}}
{{% /details %}}
{{% details "DOM 查询方法：getElementById、querySelector" %}}
{{% /details %}}
{{% details "DOM 遍历与导航" %}}
{{% /details %}}
{{% details "DOM 操作技术" %}}
{{% /details %}}
{{% details "元素创建与删除" %}}
{{% /details %}}
{{% details "属性操作与样式修改" %}}
{{% /details %}}
{{% details "内容插入与替换" %}}
{{% /details %}}
{{% details "事件处理机制" %}}
{{% /details %}}
{{% details "事件系统" %}}
{{% /details %}}
{{% details "事件流与事件冒泡" %}}
{{% /details %}}
{{% details "事件委托模式" %}}
{{% /details %}}
{{% details "常用事件类型：click、submit、keydown" %}}
{{% /details %}}
{{% details "自定义事件与事件对象" %}}
{{% /details %}}
{{% /columns %}}

### 4 HTML 与 JavaScript 交互{#4}



{{% columns ratio="1:1" %}}
{{% details "脚本引入方式" %}}
{{% /details %}}
{{% details "内联脚本与外部脚本" %}}
{{% /details %}}
{{% details "script 标签属性：async、defer" %}}
{{% /details %}}
{{% details "模块化与 ES6 模块" %}}
{{% /details %}}
{{% details "表单处理" %}}
{{% /details %}}
{{% details "表单验证技术" %}}
{{% /details %}}
{{% details "表单数据获取与提交" %}}
{{% /details %}}
{{% details "文件上传处理" %}}
{{% /details %}}
{{% details "富文本编辑器集成" %}}
{{% /details %}}
{{% details "数据存储与通信" %}}
{{% /details %}}
{{% details "Cookie 操作与管理" %}}
{{% /details %}}
{{% details "Web Storage API 使用" %}}
{{% /details %}}
{{% details "AJAX 技术与 Fetch API" %}}
{{% /details %}}
{{% details "WebSocket 实时通信" %}}
{{% /details %}}
<--->
```mermaid
mindmap
    id4[HTML 与 JavaScript 交互]
        id4-1[脚本引入方式]
        id4-2[内联脚本与外部脚本]
        id4-3[script 标签属性：async、defer]
        id4-4[模块化与 ES6 模块]
        id4-5[表单处理]
        id4-6[表单验证技术]
        id4-7[表单数据获取与提交]
        id4-8[文件上传处理]
        id4-9[富文本编辑器集成]
        id4-10[数据存储与通信]
        id4-11[Cookie 操作与管理]
        id4-12[Web Storage API 使用]
        id4-13[AJAX 技术与 Fetch API]
        id4-14[WebSocket 实时通信]
```

{{% /columns %}}

### 5 现代 Web 开发实践{#5}



{{% columns ratio="1:1" %}}
```mermaid
mindmap
    id5[现代 Web 开发实践]
        id5-1[性能优化]
        id5-2[页面加载优化策略]
        id5-3[代码分割与懒加载]
        id5-4[缓存机制与资源压缩]
        id5-5[渲染性能优化]
        id5-6[安全考虑]
        id5-7[XSS 攻击与防护]
        id5-8[CSRF 攻击与防护]
        id5-9[内容安全策略 CSP]
        id5-10[数据验证与清理]
        id5-11[响应式设计]
        id5-12[媒体查询与响应式布局]
        id5-13[移动端适配技术]
        id5-14[渐进式 Web 应用 PWA]
        id5-15[无障碍访问支持]
```

<--->
{{% details "性能优化" %}}
{{% /details %}}
{{% details "页面加载优化策略" %}}
{{% /details %}}
{{% details "代码分割与懒加载" %}}
{{% /details %}}
{{% details "缓存机制与资源压缩" %}}
{{% /details %}}
{{% details "渲染性能优化" %}}
{{% /details %}}
{{% details "安全考虑" %}}
{{% /details %}}
{{% details "XSS 攻击与防护" %}}
{{% /details %}}
{{% details "CSRF 攻击与防护" %}}
{{% /details %}}
{{% details "内容安全策略 CSP" %}}
{{% /details %}}
{{% details "数据验证与清理" %}}
{{% /details %}}
{{% details "响应式设计" %}}
{{% /details %}}
{{% details "媒体查询与响应式布局" %}}
{{% /details %}}
{{% details "移动端适配技术" %}}
{{% /details %}}
{{% details "渐进式 Web 应用 PWA" %}}
{{% /details %}}
{{% details "无障碍访问支持" %}}
{{% /details %}}
{{% /columns %}}

### 6 开发工具与调试{#6}





{{% columns ratio="1:1" %}}
{{% details "开发环境搭建" %}}
{{% /details %}}
{{% details "代码编辑器配置" %}}
{{% /details %}}
{{% details "浏览器开发者工具" %}}
{{% /details %}}
{{% details "构建工具：Webpack、Vite" %}}
{{% /details %}}
{{% details "版本控制与 Git" %}}
{{% /details %}}
{{% details "调试技术" %}}
{{% /details %}}
{{% details "控制台调试方法" %}}
{{% /details %}}
{{% details "断点设置与单步调试" %}}
{{% /details %}}
{{% details "网络请求分析" %}}
{{% /details %}}
{{% details "性能监控与分析" %}}
{{% /details %}}
{{% details "测试与部署" %}}
{{% /details %}}
{{% details "单元测试框架" %}}
{{% /details %}}
{{% details "端到端测试工具" %}}
{{% /details %}}
{{% details "代码质量检查" %}}
{{% /details %}}
{{% details "部署流程与持续集成" %}}
{{% /details %}}
<--->
```mermaid
mindmap
    id6[开发工具与调试]
        id6-1[开发环境搭建]
        id6-2[代码编辑器配置]
        id6-3[浏览器开发者工具]
        id6-4[构建工具：Webpack、Vite]
        id6-5[版本控制与 Git]
        id6-6[调试技术]
        id6-7[控制台调试方法]
        id6-8[断点设置与单步调试]
        id6-9[网络请求分析]
        id6-10[性能监控与分析]
        id6-11[测试与部署]
        id6-12[单元测试框架]
        id6-13[端到端测试工具]
        id6-14[代码质量检查]
        id6-15[部署流程与持续集成]
```

{{% /columns %}}
