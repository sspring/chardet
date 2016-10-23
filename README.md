# chardet
c++版本的chardet,功能类似于pyhon的chardet模块
支持 ascii,gb18030,utf-8等编码的自动检测

1.检测字符串编码
```c++
#include "chardet.h"
chardet.detect("\xb2\xe2\xca\xd4\xd7\xd6\xb7\xfb\xb4\xae") // GB18030
chardet.detect("\xe6\xb5\x8b\xe8\xaf\x95") // UTF-8
```

2.检测是否属于指定编码类型
```c++
#include "gb18030checker.h"
GB18030Checker.detect("\xe6\xb5\x8b\xe8\xaf\x95") // false
```
