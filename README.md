# Introduce

《剑指 offer》编程题目练手.

- 运行:

```
$ make
```

- 运行某个题目:
  在`Makefile`中将该题目取消注释, 然后在`main.cpp`中:

```
#include "Problem.h"

int main() {
    ProblemTest1();
}
```

# Format

```
clang-format -dump-config -style=Microsoft > .clang-format
```

# Accelerate

```
static auto magic = []() {ios_base::sync_with_stdio(false); cin.tie(nullptr); return false;}();
```

# Referance

https://web.stanford.edu/class/cs193d/handouts/make.pdf

https://leetcode-cn.com/problemset/lcof/

https://github.com/gatieme/CodingInterviews

https://github.com/xy00/books/blob/master/%E5%89%91%E6%8C%87OFFER%20%20%E5%90%8D%E4%BC%81%E9%9D%A2%E8%AF%95%E5%AE%98%E7%B2%BE%E8%AE%B2%E5%85%B8%E5%9E%8B%E7%BC%96%E7%A8%8B%E9%A2%98%20%20%E7%AC%AC2%E7%89%88.pdf

# LICENSE

几乎所有代码来源于[zhedahht/CodingInterviewChinese2](https://github.com/zhedahht/CodingInterviewChinese2),
原作者保留所有权利
