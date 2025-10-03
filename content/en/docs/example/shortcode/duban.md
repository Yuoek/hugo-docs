# 书影音卡片


### 例一 

{{< media-card 
    type="book" 
    title="书名" 
    author="作者名" 
    nationality="国籍" 
    time="出版时间" 
    image="/logo.png"
    rating="★★★★☆" 
    description="书籍描述" >}}
内容区域
{{< /media-card >}}


```markdown 
{{/* < media-card 
    type="book" 
    title="书名" 
    author="作者名" 
    nationality="国籍" 
    time="出版时间" 
    image="/logo.png"
    rating="★★★★☆" 
    description="书籍描述" */>}}
内容区域
{{</* /media-card */>}}

```


### 例二

{{< media-card 
  type="movie"
  director="皮埃尔·布特龙" 
  countries="法国/比利时" 
  date="2004 - 1h33m" 
  title="《沉静如海》"
  stars="Julie Delarme/Michel Galabru/Thomas Jouannet"
  types="爱情/战争"
  image="/p541622159.webp"
  backimage="/p791070481.webp"
  description="你沉静如海，我听见涛声"
  rating="⭐⭐⭐⭐⭐"
>}}

{{% details "观后感 " %}}
我之所以...喜欢大海     
是因为它的宁静  
我说的不是..海浪    
而是别的东西    
神秘的东西  

是隐藏在深处    
明亮的大海  
大海是宁静的    
要学会倾听  
------《沉静如海》
{{% /details %}}

{{< /media-card >}}

```markdown
{{</* media-card 
  type="movie"
  director="皮埃尔·布特龙" 
  countries="法国/比利时" 
  date="2004 - 1h33m" 
  title="《沉静如海》"
  stars="Julie Delarme/Michel Galabru/Thomas Jouannet"
  types="爱情/战争"
  image="/p541622159.webp"
  backimage="/p791070481.webp"
  description="你沉静如海，我听见涛声"
  rating="⭐⭐⭐⭐⭐"
*/>}}

{{/* %details "观后感 " */ %}}
我之所以...喜欢大海     
是因为它的宁静  
我说的不是..海浪    
而是别的东西    
神秘的东西  

是隐藏在深处    
明亮的大海  
大海是宁静的    
要学会倾听  
------《沉静如海》
{{/* %/details */ %}}

{{</*/*/*/*/*/*/*/* /media-card */>}}

```


### 例三

{{< media-card
type="movie"
title="《爱你罗茜》"
rating="★★★★★"
date="2014-1h2m"
image="/logo.png"
backimage="/p541622159.webp"
director="克里斯汀·迪特"
author="克里斯汀·迪特"
stars="莉莉·柯林斯/山姆·克拉弗林"
countries="德国"
language="德语/英语"
types="喜剧/爱情"
description="迟来的总比没有好... "
 >}}

{{% details "影评 " %}}
之所以...喜欢大海     
是因为它的宁静  
我说的不是..海浪    
而是别的东西    
神秘的东西  

是隐藏在深处    
明亮的大海  
大海是宁静的    
要学会倾听  

------《沉静如海》
{{% /details %}}

{{% details "观后感 " %}}
我之所以...喜欢大海     
是因为它的宁静  
我说的不是..海浪    
而是别的东西    
神秘的东西  

是隐藏在深处    
明亮的大海  
大海是宁静的    
要学会倾听  
------《沉静如海》
{{% /details %}}
{{< /media-card >}}
    

```markdown
{{</* media-card
type="movie"
title="《爱你罗茜》"
rating="★★★★★"
date="2014-1h2m"
image="/logo.png"
backimage="/p541622159.webp"
director="克里斯汀·迪特"
author="克里斯汀·迪特"
stars="莉莉·柯林斯/山姆·克拉弗林"
countries="德国"
language="德语/英语"
types="喜剧/爱情"
description="迟来的总比没有好... "
 */>}}

{{/* %details "影评 " */%}}
之所以...喜欢大海     
是因为它的宁静  
我说的不是..海浪    
而是别的东西    
神秘的东西  

是隐藏在深处    
明亮的大海  
大海是宁静的    
要学会倾听  

------《沉静如海》
{{/* %/details */%}}

{{/* %details "观后感 " */%}}
我之所以...喜欢大海     
是因为它的宁静  
我说的不是..海浪    
而是别的东西    
神秘的东西  

是隐藏在深处    
明亮的大海  
大海是宁静的    
要学会倾听  
------《沉静如海》
{{/* %/details */%}}
{{</* /media-card */>}}
```


