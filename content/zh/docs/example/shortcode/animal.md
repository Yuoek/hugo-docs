## Animate + gsap

<script src="https://cdn.jsdelivr.net/npm/gsap@3.13.0/dist/gsap.min.js"></script>


## 创建 svg 

<svg viewBox='0 0 1200 600' style='background: white'>
<rect id='r1' x='50' y='100' width='100' height='100' fill='blue'/>
<rect id='r2' x='350' y='100' width='100' height='100'/>
</svg>

```markdown 
<svg viewBox='0 0 1200 600' style='background: white'>
<rect id='r1' x='50' y='100' width='100' height='100' fill='blue'/>
<rect id='r2' x='350' y='100' width='100' height='100'/>
</svg>
```

## 引用 gsap

<script>

gsap.set('#r1', {transformOrigin:'center'});
gsap.set('#r2', {transformOrigin:'center'});

// 修正语法错误和标点符号
var t1 = gsap.timeline();
t1.to('#r1',{
    x:100, 
    y:100, 
    scaleX:2,
    fill:'red',
    stroke:'white',
    rotation:360,
    strokeWidth:5, // 修正拼写
    duration:5,
}).from('#r2',{
    x:100,
    y:100,
    scaleX:2, 
    fill:'red', 
    stroke: 'white',
    rotation:360, 
    strokeWidth:5, // 修正拼写
    duration:2,
}, '>-1');

</script>


```markdown 
<script>

gsap.set('#r1', {transformOrigin:'center'});
gsap.set('#r2', {transformOrigin:'center'});

// 修正语法错误和标点符号
var t1 = gsap.timeline();
t1.to('#r1',{
    x:100, 
    y:100, 
    scaleX:2,
    fill:'red',
    stroke:'white',
    rotation:360,
    strokeWidth:5, // 修正拼写
    duration:5,
}).from('#r2',{
    x:100,
    y:100,
    scaleX:2, 
    fill:'red', 
    stroke: 'white',
    rotation:360, 
    strokeWidth:5, // 修正拼写
    duration:2,
}, '>-1');

</script>
```


