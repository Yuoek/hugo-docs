
## pythoncomplex
### 复数表示
```python
z1 = 3 + 4j        # 直接表示法
z2 = complex(3, 4) # 构造函数法
print(z1)          # (3+4j)
print(z2)          # (3+4j)
```

### 复数属性
```python
z = 3 + 4j
print(z.real)           # 3.0
print(z.imag)           # 4.0
print(z.conjugate())    # (3-4j)
```

### 基本运算
```python
a = 2 + 3j
b = 1 - 2j

print(a + b)    # (3+1j)
print(a - b)    # (1+5j)
print(a * b)    # (8-1j)
print(a / b)    # (-0.8+1.4j)
```

### 数学函数
```python
import cmath

z = 1 + 1j
print(cmath.sqrt(z))    # 平方根
print(cmath.exp(z))     # 指数函数
print(cmath.log(z))     # 对数函数
print(cmath.sin(z))     # 正弦函数
print(cmath.phase(z))   # 相位角（弧度）
print(abs(z))           # 模/绝对值
```

### 极坐标表示
```python
import cmath

z = 1 + 1j
r, phi = cmath.polar(z)        # 转换为极坐标
print(f"模: {r}, 相位: {phi}")

z_new = cmath.rect(r, phi)     # 从极坐标转换回
print(z_new)                   # (1+1j)
```

### 特殊值检查
```python
z = 1 + 1j
print(cmath.isclose(z, 1+1j))  # 判断两个复数是否相近
