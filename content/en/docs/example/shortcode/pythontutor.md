
## Pythontutor

### java 

{{< pythontutor language="java" height="300">}}
// Java代码
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
{{< /pythontutor >}}

```markdown
{{</* pythontutor language="java" height="300" */>}}
// Java代码
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
{{</* /pythontutor */>}}

```

### python 

{{< pythontutor >}}
def decorator_function(original_function):
    def wrapper(*args, **kwargs):
        # 这里是在调用原始函数前添加的新功能
        before_call_code()
        
        result = original_function(*args, **kwargs)
        
        # 这里是在调用原始函数后添加的新功能
        after_call_code()
        
        return result
    return wrapper

# 使用装饰器
@decorator_function
def target_function(arg1, arg2):
    pass  # 原始函数的实现
{{< /pythontutor >}}

```markdown
{{</* pythontutor */>}}
def decorator_function(original_function):
    def wrapper(*args, **kwargs):
        # 这里是在调用原始函数前添加的新功能
        before_call_code()
        
        result = original_function(*args, **kwargs)
        
        # 这里是在调用原始函数后添加的新功能
        after_call_code()
        
        return result
    return wrapper

# 使用装饰器
@decorator_function
def target_function(arg1, arg2):
    pass  # 原始函数的实现
{{</* /pythontutor */>}}

```

###  c

{{< pythontutor language="c" height="400">}}
#include <stdio.h>
int main() {
    printf("Hello");
    int m = pow(10,2);
    printf("%d\n",m);
    return 0;
}
{{< /pythontutor >}}

```markdown
{{</* pythontutor language="c" height="400" */>}}
#include <stdio.h>
int main() {
    printf("Hello");
    int m = pow(10,2);
    printf("%d\n",m);
    return 0;
}
{{</* /pythontutor */>}}

```

### cpp 

{{< pythontutor width="100%" height="500" language="cpp" >}}
#include <iostream>
using namespace std;
int main() {
    int x = 5;
    int y = 10;
    cout << "Sum: " << x + y << endl;
    return 0;
}
{{< /pythontutor >}}

```markdown
{{</* pythontutor width="100%" height="500" language="cpp" */>}}
#include <iostream>
using namespace std;
int main() {
    int x = 5;
    int y = 10;
    cout << "Sum: " << x + y << endl;
    return 0;
}
{{</* /pythontutor */>}}



```
