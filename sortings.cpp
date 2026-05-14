#include "sortings.h"

using namespace std;

void sort_insert(vector<Ship>& my_vector) {
    for (int i = 1; i < my_vector.size(); i++) {
        Ship key = my_vector[i];
        int j = i - 1;
        while (j >= 0 && my_vector[j] > key) {
            my_vector[j + 1] = my_vector[j];
            j--;
        }
        my_vector[j + 1] = key;
    }
}

void go_down(vector<Ship>& my_vector, int n, int i) {
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    if (left_child < n && my_vector[left_child] > my_vector[largest]) {
        largest = left_child;
    }
    if (right_child < n && my_vector[right_child] > my_vector[largest]) {
        largest = right_child;
    }
    if (largest != i) {
        swap(my_vector[largest], my_vector[i]);
        go_down(my_vector, n, largest);
    }
}

void sort_pyramid(vector<Ship>& my_vector) {
    int n = my_vector.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        go_down(my_vector, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(my_vector[0], my_vector[i]);
        go_down(my_vector, i, 0);
    }
}

void merging(vector<Ship>& my_vector, int start, int mid, int end) {
    vector<Ship> left, right;
    for (int i = start; i <= mid; i++) left.push_back(my_vector[i]);
    for (int i = mid + 1; i <= end; i++) right.push_back(my_vector[i]);

    int i_left = 0, i_right = 0;
    int i_total = start;
    while (i_left < left.size() && i_right < right.size()) {
        if (left[i_left] <= right[i_right]) {
            my_vector[i_total] = left[i_left];
            i_left++;
        } else {
            my_vector[i_total] = right[i_right];
            i_right++;
        }
        i_total++;
    }
    while (i_left < left.size()) {
        my_vector[i_total] = left[i_left];
        i_left++; 
        i_total++;
    }
    while (i_right < right.size()) {
        my_vector[i_total] = right[i_right];
        i_right++; 
        i_total++;
    }
}

void sort_merge(vector<Ship>& my_vector, int start, int end) {
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    sort_merge(my_vector, start, mid);
    sort_merge(my_vector, mid + 1, end);
    merging(my_vector, start, mid, end);
}