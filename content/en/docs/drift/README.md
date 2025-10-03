---
bookFlatSection: false
date: 2025-09-02T09:11:26+08:00
---

## README 

{{< tikz width="90%" height="400px" >}}
\begin{tikzpicture}
,
    text height = 2ex}]
  \graph { tex -> dvi -> ps -> pdf,
           bib -> bbl,
           bbl -> dvi };
\end{tikzpicture}
{{< /tikz >}}

{{< tikz width="90%" height="400px" >}}
\usepackage{pgfplots}
\pgfplotsset{trig format plots=rad}
\begin{tikzpicture}
  \begin{axis}[axis lines = middle, axis equal,
      domain = 0:6*pi, ymin=-18, ymax=18,
      xtick = {-4*pi,-2*pi,pi,3*pi,5*pi},
      ytick = {pi, 2*pi, 3*pi, 4*pi, 5*pi},
      xticklabels = {$-4\pi$, $-2\pi$,
        $\vphantom{1}\pi$, $3\pi$, $5\pi$},
      yticklabels = {$\vphantom{1}\pi$, $2\pi$,
        $3\pi$, $4\pi$, $5\pi$}
    ]
    \addplot[samples=120, smooth, thick, variable=t]
      ( {t*cos(t)}, {t*sin(t)} );
\end{axis}
\end{tikzpicture}
{{< /tikz >}}




{{< tikz width="90%" height="400px" >}}
\usetikzlibrary {arrows.meta,trees}
\begin{tikzpicture}
  [edge from parent fork down, sibling distance=15mm, level distance=15mm,
   every node/.style={fill=red!30,rounded corners},
   edge from parent/.style={red,-{Circle[open]},thick,draw}]
  \node {root}
      child {node {left}}
      child {node {right}
        child {node {child}}
        child {node {child}}
      };
\end{tikzpicture}
{{< /tikz >}}

{{< tikz width="90%" height="400px" >}}
\usetikzlibrary {shapes.geometric}
\begin{tikzpicture}[fill=blue!20]
  \draw[help lines] (-1,-2) grid (6,3);
  \path (0,0)  node(a) [ellipse,rotate=10,draw,fill]    {An ellipse}
        (3,-1) node(b) [circle,draw,fill]               {A circle}
        (2,2)  node(c) [rectangle,rotate=20,draw,fill]  {A rectangle}
        (5,2)  node(d) [rectangle,rotate=-30,draw,fill] {Another rectangle};
  \draw[thick] (a.south) -- (b) -- (c) -- (d);
  \draw[thick,red,->] (a) |- +(1,3) -| (c) |- (b);
  \draw[thick,blue,<->] (b) .. controls +(right:2cm) and +(down:1cm) .. (d);
\end{tikzpicture}
{{< /tikz >}}

{{< tikz width="90%" height="400px" >}}
\usetikzlibrary {shapes.geometric}
\begin{tikzpicture}
  \node (start) [draw,shape=ellipse] {start};
  \foreach \angle in {-90, -80, ..., 90}
    \draw (node cs:name=start,angle=\angle)
      .. controls +(\angle:1cm) and +(-1,0) .. (2.5,0);
  \end{tikzpicture}
{{< /tikz >}}

{{< tikz width="90%" height="400px" >}}
\begin{tikzpicture}
  \draw (0,0) circle (1in);
  \draw[red, thick] (-1,0) -- (1,0);
  \draw[blue, thick] (0,-1) -- (0,1);
\end{tikzpicture}
{{< /tikz >}}


<script type="text/tikz">
  \begin{tikzpicture}
    \draw (0,0) circle (1in);
  \end{tikzpicture}
</script>

只用 tikz语法 画正弦函数

以下是使用 Hugo shortcode 的实现方式：


使用方式：

{{< tikz width="90%" height="400px" >}}
\begin{tikzpicture}
  \draw (0,0) circle (1in);
  \draw[red, thick] (-1,0) -- (1,0);
  \draw[blue, thick] (0,-1) -- (0,1);
\end{tikzpicture}
{{< /tikz >}}



{{< tikz width="90%" height="400px" >}}
\begin{tikzpicture}
  \draw[gray,very thin] (-1.9,-1.9) grid (2.9,3.9)
          [step=0.25cm] (-1,-1) grid (1,1);
  \draw[blue] (1,-2.1) -- (1,4.1); % asymptote

  \draw[->] (-2,0) -- (3,0) node[right] {$x(t)$};
  \draw[->] (0,-2) -- (0,4) node[above] {$y(t)$};

  \foreach \pos in {-1,2}
    \draw[shift={(\pos,0)}] (0pt,2pt) -- (0pt,-2pt) node[below] {$\pos$};

  \foreach \pos in {-1,1,2,3}
    \draw[shift={(0,\pos)}] (2pt,0pt) -- (-2pt,0pt) node[left] {$\pos$};

  \fill (0,0) circle (0.064cm);
  \draw[thick,parametric,domain=0.4:1.5,samples=200]
    % The plot is reparameterised such that there are more samples
    % near the center.
    plot[id=asymptotic-example] function{(t*t*t)*sin(1/(t*t*t)),(t*t*t)*cos(1/(t*t*t))}
    node[right] {$\bigl(x(t),y(t)\bigr) = (t\sin \frac{1}{t}, t\cos \frac{1}{t})$};

  \fill[red] (0.63662,0) circle (2pt)
    node [below right,fill=white,yshift=-4pt] {$(\frac{2}{\pi},0)$};
\end{tikzpicture}
{{< /tikz >}}

这样您就可以在 Hugo 内容文件中轻松嵌入 TikZ 图形了。





{{< katex />}}



```mermaid
graph TB
    Start(开始) --> Open[打开冰箱门]
    Open --> Put[把大象放进去]
    Put[把大象放进去] --> IsFit{"冰箱小不小？"}
    
    IsFit -->|不小| Close[把冰箱门关上]
    Close --> End(结束)
        
    IsFit -->|小| Change[换个大冰箱]
    Change --> Open

```


```cpp 
#include <iostream> 
using namespace std;

void area(double a){
    const double PI = 3.14;
    cout << "圆形的面积为：" << PI*a*a;
}

int main(){
    double a = 6;
    area(a);
    return 0;
}

```


```mermaid
graph LR
     1 -.- 2 
     2 -.- 3 
     3 -.- 4 
     4 -.- 1
     1 -.- 4
     2 -.- 4
```

```mermaid

flowchart TD 
    subgraph A[基础]
      subgraph c 
         d[Data Types] --> p[Point]
      end 
      subgraph cpp 
        cd[Data Types] --> cp[Point]
      end 
     end
   
    subgraph AD[进阶]
      subgraph c 
         D[Data Types] --> P[Point]
      end 
      subgraph cpp 
        CD[Data Types] --> CP[Point]
      end 
     end
   
     A ---> AD
     AD --- A


    
     

```

如何使箭头不弯曲
```mermaid
graph LR
    A[P] ---> B[[2]]
    B --> C[[5]]
    C --> B
    C -.-> D[[8]]  
    D -.-> C
    D -.-> E[[11]]
    E --> G[[4]]
    G --> E
    E -.-> D
    F[[9]]
    C --> F
    F --> C
    F --> E 
    E --> F
    subgraph point 

    end
   

    style A fill:#fff0,stroke:#333,stroke-width:0px
    style Q fill:#fff0,stroke:#333,stroke-width:0px
    linkStyle default stroke-width:1px,fill:none,stroke:#333
```

```mermaid

erDiagram
    CAR ||--o{ NAMED-DRIVER : allows
    CAR {
        string registrationNumber
        string make
        string model
    }
    PERSON ||--o{ NAMED-DRIVER : is
    PERSON {
        string firstName
        string lastName
        int age
    }

```

```mermaid
classDiagram
    class BankAccount {
        -owner: String
        -balance: Number
        +deposit(amount Number)
        +withdraw(amount Number): Boolean
        #calculateInterest(): Number
}
```
```mermaid
classDiagram 
    class study {
    }
```

```mermaid
classDiagram 
    class study {
        +cpp: cpp
        +c: c
        +python: python  
        +java: java 
    }
```

```mermaid 
graph LR
    subgraph 1[第一阶梯学习]
        c --> cpp 
    end 

    subgraph 2[第二阶梯学习]
        python --> java 
    end 
    
    cpp --> python 
    java --> c

```

```mermaid 
graph TB 
    S[Sophie]
    Y[Yuoek]
    F[Film]
    Y -. Dear Sophie .- S
    Y -. To Find You .- F

```

```mermaid 

mindmap
    id)I am a cloud(
        id)I am a cloud(
        id)I am a cloud(
        id)I am a cloud(
        id)I am a cloud(

```

```mermaid

mindmap
    id1("`**Root** with 
a second line 
Unicode works too: 🤓`")
      id5(how are you)
      id5[how are you]
      id4[what are you doning?]
          id4[what are you doning?]
          id4[What are you doning?]
          id2["`The dog in **the** hog... a *very long text* that wraps to a new line`"]
          id3[Regular labels still works]
          id4[what are you doning?]
          id4[what are you doning?]
          id4[What are you doning?]
      id4[what are you doning?]
      id4[What are you doning?]
      id2["`The dog in **the** hog... a *very long text* that wraps to a new line`"]
      id3[Regular labels still works]
      id4[what are you doning?]
      id4[what are you doning?]
      id4[What are you doning?]
      id2["`The dog in **the** hog... a *very long text* that wraps to a new line`"]
      id3[Regular labels still works]
          id5[how are you]
          id4[what are you doning?]
          id4[what are you doning?]
          id4[What are you doning?]
      id4[Sophie]
          id5[How are you]
          id5[How are you]
          id5[How are you]
          id4[What are you doning?]
          id4[What are you doning?]
          id4[What are you doning?]

```

```mermaid

    requirementDiagram

    requirement test_req {
    id: 1
    text: the test text.
    risk: high
    verifymethod: test
    }

    functionalRequirement test_req2 {
    id: 1.1
    text: the second test text.
    risk: low
    verifymethod: inspection
    }

    performanceRequirement test_req3 {
    id: 1.2
    text: the third test text.
    risk: medium
    verifymethod: demonstration
    }

    interfaceRequirement test_req4 {
    id: 1.2.1
    text: the fourth test text.
    risk: medium
    verifymethod: analysis
    }

    physicalRequirement test_req5 {
    id: 1.2.2
    text: the fifth test text.
    risk: medium
    verifymethod: analysis
    }

    designConstraint test_req6 {
    id: 1.2.3
    text: the sixth test text.
    risk: medium
    verifymethod: analysis
    }

    element test_entity {
    type: simulation
    }

    element test_entity2 {
    type: word doc
    docRef: reqs/test_entity
    }

    element test_entity3 {
    type: "test suite"
    docRef: github.com/all_the_tests
    }


    test_entity - satisfies -> test_req2
    test_req - traces -> test_req2
    test_req - contains -> test_req3
    test_req3 - contains -> test_req4
    test_req4 - derives -> test_req5
    test_req5 - refines -> test_req6
    test_entity3 - verifies -> test_req5
    test_req <- copies - test_entity2

```

```mermaid 
flowchart TD
    A@{ shape: comment, label: "Line 1<br>Line 2<br>Line 3" }
```

在Mermaid流程图语法中，当出现"多个label"的情况时，通常有以下几种处理方式：

## 1. 使用HTML标签实现多行文本
```mermaid
flowchart TD
    A@{ shape: comment, label: "Line 1<br>Line 2<br>Line 3" }
```

## 2. 使用转义字符
```mermaid
flowchart TD
    A@{ shape: comment, label: "First Label\nSecond Label" }
```

## 3. 使用HTML div标签
```mermaid
flowchart TD
    A@{ shape: comment, label: "<div>Label 1</div><div>Label 2</div>" }
```

## 4. 多个标签的完整示例
```mermaid
flowchart TD
    A@{ shape: comment, label: "开始<br>Start" }
    B@{ shape: rect, label: "处理1\nProcess 1" }
    A --> B
```

**注意：** 在Mermaid中，换行需要使用HTML的`<br>`标签或转义字符`\n`来实现多行文本效果。




flowchart TD
    A@{ shape: comment, label: "Comment" }


分数：\( \frac{X ^y  }{Z } {4} \) 

\\( \frac{X ^{y + z } }{X _{1 } } \\)   


\\( \lim_{X  \to \infty} \\) 

\\[
 \lim_{x  \to \infty}
\\]

\\[
\lim_{x  \to 100 ^-}
\\]

\\[
 \int_1 ^100  f(x )\,dx 
\\]

\\[
 \int_{1 }^{100 } f(x ) \, dx 
\\]


\[
  \int_a^b \! f(x) \, dx = \lim_{\Delta x \rightarrow 0}
  \sum_{i=1}^{n} f(x_i) \,\Delta x_i
\]

\\[
\iint_D f(x,y)\,dA
\\]


$$
\iint_D f(x,y)\,dA
$$

\\[
\iint_D f(x, y) dB
\\]

\\[
 \int_V f(x, y, z) dC 
\\]


\\[
\binom{i }{j } = \frac{i }{j !(i -j )!}
\\]


您提供的公式有笔误。正确的组合数（二项式系数）公式应为：

\\[
\binom{i}{j} = \frac{i!}{j! \cdot (i - j)!}
\\]

**说明：**

1.  **符号**：`\binom{i}{j}` 表示组合数，也写作 C(i, j) 或 ⁿCᵣ。
2.  **定义**：它表示从 `i` 个不同元素中不计顺序地选取 `j` 个元素的所有不同方法的数量。
3.  **公式修正**：
    *   您原公式中的 `\frack{i }` 应为 `\frac{i!}`。关键是要有 **阶乘符号 `!`**。
    *   分母是 `j!` 和 `(i - j)!` 的乘积。

**使用条件**：
这个公式在 `i` 和 `j` 都是非负整数，且 `0 ≤ j ≤ i` 时成立。



