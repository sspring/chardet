# chardet
c++版本的chardet,功能类似于pyhon的chardet模块
支持 ascii(iso_ir 100),gb18030,gbk,big5,utf-8(iso_ir 192),shift-jp等编码的自动检测
主要有detect和check两个核心方法。

1.检测字符串编码
```c++
#include "chardet.h"
detect("\xb2\xe2\xca\xd4\xd7\xd6\xb7\xfb\xb4\xae") // gb18030
detect("\xe6\xb5\x8b\xe8\xaf\x95") // utf-8
```

2.检测是否属于指定编码类型
```c++
#include "chardet.h"
check("utf-8","\xe6\xb5\x8b\xe8\xaf\x95"); // true
```
