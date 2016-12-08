
### sort 函数
头文件中声明： #include <algorithm>

然后调用函数 sort(a, a + n) 对从 a 开始的 n 个数进行排序

|函数名|功能|
|:-:|:-:|
|sort|对给定区间所有元素进行排序|
|stable_sort|对给定区间所有元素进行稳定排序|
|partial_sort|对给定区间所有元素进行部分排序|
|partial_sort_copy|对给定区间复制并排序|
|nth_element|找出给定区间的某个位置对应的元素|
|is_sorted|判断一个区间是否已经排好序|
|partition|使得符合某个条件的元素放在前面|
|stable_partition|相对稳定的使得符合某个条件的元素放在前面|

sort(a, a + n) 排序的输出结果是升序的。

---

### pair 的用法
pair 为一种模板类型。每个 pair 可以存储两个值，类型无限制可以是自己写的 struct，例如：

pair<string, int> p;

pair<int, int> p;

pair<double, int> p;

应用 pair 可以省略个 struct，极端写法 pair<int, pair<int, int> > 可以写出三个属性。

pair<int, int> p(5, 6);

pair<int, int> p1 = make_pair(5, 6);

pair<string, double> p2("aa", 5.0);

pair<string, double> p3 = make_pair("aa", 5.0);

这两种写法可以生成一个 pair。

取得 pair 的值得方法是：cout << p1.first << p1.second;

要定义多个相同的 pair 类型时，可用 typedef 进行简化：

typedef pair<string, string> author;

author pro("May", "Lily");

author joye("James", "Joyce");

---

### compare 函数
根据 s 是等于、大于还是小于参数指定的字符串，s.compare 返回 0、正数或负数。

```c++
#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::endl;
using std::cin;
using std::string;
int main(void){
  string str1="hi,test,hello";
  string str2="hi,test";
  //字符串比较
  if(str1.compare(str2)>0)
    printf("str1>str2\n");
  else if(str1.compare(str2)<0)
    printf("str1<str2\n");
  else
    printf("str1==str2\n");
  
  //str1的子串（从索引3开始，包含4个字符）与str2进行比较
  if(str1.compare(3,4,str2)==0)
    printf("str1的指定子串等于str2\n");
  else
    printf("str1的指定子串不等于str2\n");
  
  //str1指定子串与str2的指定子串进行比较
  if(str1.compare(3,4,str2,3,4)==0)
    printf("str1的指定子串等于str2的指定子串\n");
  else
    printf("str1的指定子串不等于str2的指定子串\n");
  
  //str1指定子串与字符串的前n个字符进行比较
  if(str1.compare(0,2,"hi,hello",2)==0)
    printf("str1的指定子串等于指定字符串的前2个字符组成的子串\n");
  else
    printf("str1的指定子串不等于指定字符串的前2个字符组成的子串\n");
  return 0;
}
```
---

### memset 函数

memset(char *s, int ch, size_t n); 将 s 所指向的某一块内存的前 n 个字节全部设定为 ch 指定的 ASCLL 值，其返回值为指向 s 的指针。函数对数组操作时只能用于数组的置 0 或 -1，其他值无效。如：

```c++
char a[80];
memset(a, 0, sizeof(a)); //把从 a 开始的 80 个字符全置为 0。
```

对 bool 类型的数组，可以使用如下的方式初始化：

```
memset(visited, 0, sizeof(bool) * n);
```
---

### 一些 is* 函数

![](https://res.jisuanke.com/img/upload/20161017/a6eb78c0ab120d1fb74875838d27adebe9bea2c6.png)

---

### 举例描述

一张图，有 $n$ 个点和 $m$ 条边。

第一步：将所有的边按边权从小到大排序。

排序完成后，我们选择权值最小的边 JN。这样我们的图就变成了：

![](https://res.jisuanke.com/img/upload/20161025/229ab96a3e0759a048fb5d4d6ac1ad39051833e3.png)

第二步，在剩下的边中寻找权值最小的边 UX：

![](https://res.jisuanke.com/img/upload/20161025/9af251f35ce0ac1537dbc85251d3ce08821ec580.png)

依次类推我们找到 HU，图变成：

![](https://res.jisuanke.com/img/upload/20161025/d21d87286cafd41e2c1e794eca60f0360b56b3cb.png)

最后我们只需要再选择 HN：

![](https://res.jisuanke.com/img/upload/20161025/69acf7ccb03159cb70f9dde655e263ee905b6957.png)

至此所有的点都已经连通，一个最小生成树构建完成。

Kruskal 算法的时间复杂度由排序算法决定，若采用快排则时间复杂度为 $\mathcal{O}(m log m)$。

总的时间复杂度为 $\mathcal{O}(mlogm + n\alpha (n))$。

---
### 指针的删除问题

删除一个指针后，一定要把它设为空。
