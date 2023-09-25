// Given the following templated functions f(),
// which cout is called given f('a', 10);

#include<iostream>
#include <type_traits>

using namespace std;

template<typename T1, typename T2>
void f(T1 x, T2 y)
{
    if (is_same<T1, string>::value) {
        for (int i = y; i > 0; i--) {
            cout << x << " "; // Option #1
        }
    }
    else {
        for (int i = y; i > 0; i--) {
            cout << x << " "; // Option #2
        }
    }

}

template<>
void f<char, int>(char x, int y)
{
    for (int i = y; i > 0; i--) {
        cout << x << " "; // Option #3 <----------- This one
    }
}

template<>
void f<int, int>(int x, int y)
{
    for (int i = y; i > 0; i--) {
        cout << x << " "; // Option #4
    }
}

int main()
{
    f('a', 10);
}