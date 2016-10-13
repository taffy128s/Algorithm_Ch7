#include <cstdio>
#include <algorithm>

int arr[100] = {5, 4, 3, 2, 1, 6, 7, 9, 10, 8};
int size = 10; // 0, size - 1

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
    if (l >= r) return;
    int split = partition(l, r);
    quick_sort(l, split - 1);
    quick_sort(split + 1, r);
}

int main() {
    quick_sort(0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}
