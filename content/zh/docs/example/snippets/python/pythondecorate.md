
## pythondecorate
### 装饰器基本语法
```python
@decorator
def target_function():
    pass
```
等价于：
```python
def target_function():
    pass
target_function = decorator(target_function)
```


### 无参装饰器
```python
def simple_decorator(func):
    def wrapper(*args, **kwargs):
        print("函数执行前")
        result = func(*args, **kwargs)
        print("函数执行后")
        return result
    return wrapper

@simple_decorator
def say_hello(name):
    print(f"Hello, {name}!")
```

### 带参装饰器
```python
def param_decorator(level="INFO"):
    def decorator(func):
        def wrapper(*args, **kwargs):
            print(f"[{level 函数开始执行")
            result = func(*args, **kwargs)
            print(f"[{level 函数执行结束")
            return result
        return wrapper
    return decorator

@param_decorator("DEBUG")
def test_function():
    print("测试函数")
```

### 类装饰器
```python
class ClassDecorator:
    def __init__(self, func):
        self.func = func
        self.call_count = 0
    
    def __call__(self, *args, **kwargs):
        self.call_count += 1
        print(f"函数被调用第{self.call_count}次")
        return self.func(*args, **kwargs)

@ClassDecorator
def my_function():
    print("函数执行")
```

### 多个装饰器叠加
```python
@decorator1
@decorator2
@decorator3
def function():
    pass

# 执行顺序：decorator3 → decorator2 → decorator1
```


### @staticmethod

```python
class MyClass:
    @staticmethod
    def static_method():
        print("静态方法")
```

### @classmethod
```python
class MyClass:
    @classmethod
    def class_method(cls):
        print(f"类方法，类名：{cls.__name__}")
```

### @property
```python
class Person:
    def __init__(self, name):
        self._name = name
    
    @property
    def name(self):
        return self._name
    
    @name.setter
    def name(self, value):
        self._name = value
```


### 元信息丢失
```python
def my_decorator(func):
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return wrapper

@my_decorator
def example():
    """示例函数"""
    pass

print(example.__name__)  # 输出：wrapper（不是example）
```

### 元信息丢失解决方案
```python
from functools import wraps

def my_decorator(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        return func(*args, **kwargs)
    return wrapper
```


### 日志记录
```python
def log_decorator(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"调用函数：{func.__name__}")
        print(f"参数：args={args}, kwargs={kwargs}")
        result = func(*args, **kwargs)
        print(f"返回值：{result}")
        return result
    return wrapper
```

### 性能测试
```python
import time

def timer_decorator(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start_time = time.time()
        result = func(*args, **kwargs)
        end_time = time.time()
        print(f"函数 {func.__name__} 执行时间：{end_time - start_time:.4f}秒")
        return result
    return wrapper
```

### 权限验证
```python
def login_required(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        if not is_logged_in():
            return "请先登录"
        return func(*args, **kwargs)
    return wrapper
```

### 缓存机制
```python
def cache_decorator(func):
    cache = {}
    @wraps(func)
    def wrapper(*args):
        if args in cache:
            return cache[args]
        result = func(*args)
        cache[args] = result
        return result
    return wrapper
```


### 装饰器工厂模式
```python
def decorator_factory(condition=True):
    def decorator(func):
        if condition:
            # 添加功能
            @wraps(func)
            def wrapper(*args, **kwargs):
                print("装饰器生效")
                return func(*args, **kwargs)
            return wrapper
        else:
            # 直接返回原函数
            return func
    return decorator
```

### 可选参数装饰器
```python
def smart_decorator(arg=None):
    def decorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            if callable(arg):
                # 无参调用
                print("无参装饰器")
            else:
                # 有参调用
                print(f"参数为：{arg}")
            return func(*args, **kwargs)
        return wrapper
    
    if callable(arg):
        # @smart_decorator
        return decorator(arg)
    else:
        # @smart_decorator(...)
        return decorator
```

