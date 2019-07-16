# Common concepts inspired frontend

There are some concepts in C++ which I think might inspired the development of javascript/typescript.

## Iterator

- begin
- end

## Algorithm

## lambda, with reference in current scope

very likely to arrow function in javascript

in cpp:

```cpp
#include <vector>
#include <algorithm>

int count3 = 0;
int count13 = 0;
std::vector<int> numbers(100);

std::for_each(numbers.begin(), numbers.end(), [&](int x){
    count3 += (x % 3 == 0 ? 1 : 0);
    count13 += (x % 13 == 0 ? 1 : 0);
})
```

in js:

```js
var count3 = 0;
var count13 = 0;
var numbers = new Array(100);

numbers.forEach((num) => {
    count3 += (num % 3 == 0 ? 1 : 0);
    count13 += (num % 13 == 0 ? 1 : 0);
});
```