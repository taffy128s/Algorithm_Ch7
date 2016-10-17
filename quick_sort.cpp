#include <cstdio>
#include <algorithm>
#define HOARE

int arr[100] = {5, 4, 3, 2, 1, 6, 7, 9, 10, 8};
int size = 10; // 0, size - 1

int hoare(int p, int r) {
    int x = arr[p];
    int i = p - 1, j = r + 1;
    while (true) {
        do {
            ++i;
        } while (arr[i] < x);
        do {
            --j;
        } while (arr[j] > x);
        if (i < j) std::swap(arr[i], arr[j]);
        else return j;
    }
}

int partition(int l, int r) {
    int idx = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < arr[r])
            std::swap(arr[i], arr[idx++]);
    }
    std::swap(arr[r], arr[idx]);
    return idx;
}

void quick_sort(int l, int r) {
    #ifdef HOARE
    if (l >= r) return;
    int split = hoare(l, r);
    quick_sort(l, split);
    quick_sort(split + 1, r);
    #else
    if (l >= r) return;
    int split = partition(l, r);
    quick_sort(l, split - 1);
    quick_sort(split + 1, r);
    #endif
}

int main() {
    quick_sort(0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
