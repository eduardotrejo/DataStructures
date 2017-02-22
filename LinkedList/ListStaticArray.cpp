
#include <iostream>

using namespace std;

void show(int *l, int sz) {
    cout << "(";
    for (int i = 0; i < sz; i++) {
        if (i > 0) cout << ", ";
        cout << l[i];
    }
    if (sz == 0) cout << "<empty>";
    cout << ")" << endl;
}

int add(int *l, int &s, int cap, int v) {
    int r = -1;
    if (s < cap) {
        l[s++] = v;
        r = s;
    }
    return r;
}

int insert(int *l, int &s, int cap, int v, int index) {
    int r = -1;
    if (s == 0) {
        r = add(l, s, cap, v);
    } else {
        if (s < cap) {
            if (index >= s) index = s - 1;
            if (index < 0) index = 0;
            for (int i = (s - 1); i >= index; i--) {
                l[i + 1] = l[i];
            }
            l[index] = v;
            r = ++s;
        }
    }
    return r;
}

int main(int argc, const char * argv[])
{
    const int capacity = 1024;
    int list[capacity];
    int size = 0;

    show(list, size);

    // add(list, size, capacity, 42);
    for (int i = 0; i < 5; i++)
        add(list, size, capacity, i * 2);
    show(list, size);

    insert(list, size, capacity, 42, 3);
    show(list, size);

    return 0;
}