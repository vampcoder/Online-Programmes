#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;
int heap_size;
void build_heap(int a[]);
void heapify_max(int a[], int i);
void heap_sort(int a[], int n) {
    build_heap(a);
    int x;
    for (int i = n; i > 0; i--){
        x = a[0];
        a[0] = a[heap_size];
        a[heap_size] = x;
        heap_size--;
        heapify_max(a, 0);
    }
}
void heapify_max(int heap[], int i) {
   // cout << "in heapify\n";
    int max1;
    if (i < 0){
        cout << " 0 ";
        cout << "heap underflow\n";
        return ;
    }
    if (i > heap_size) {
        return;
    }
    int l = 2*i + 1;
    int r = l + 1;
    if (l <= heap_size && heap[l] > heap[i]){
        //cout << "1 ";
        max1 = l;
    }else {
        //cout << "2 ";
        max1 = i;
    }
    if(r <= heap_size && heap[r] > heap[max1]) {
        //cout << "3 ";
        max1 = r;
    }
    int x;
    //cout << "max = " << max1 << " "  << " i = " << i <<" ";
    if (max1 != i) {
      //  cout << "4 \n";
        x = heap[i];
        heap[i] = heap[max1];
        heap[max1] = x;

        heapify_max(heap, max1);
    }
}
void build_heap(int a[]) {
    for (int i = heap_size/2; i >=0; i--) {
        heapify_max(a, i);
    }
}
int heap_max(int heap[]){
    return heap[0];
}
int heap_extract_max(int a[]) {
    if (heap_size < 0) {
        cout << "heap_underflow\n";
        exit(1);
    }
    int max1 = a[0];
    a[0] = a[heap_size];
    heap_size--;
    heapify_max(a, 0);
    return max1;
}
void inc_key(int a[], int key, int i){
    if (key < a[i]) {
        cout << "new key is smaller original value";
        exit(1);
    }
    int x;
    while (i > 0 && a[i/2] < a[i]) {
        x = a[i];
        a[i] = a[i/2];
        a[i/2] = x;
        i = i/2;
    }
}
void insert_heapkey(int a[], int key) {
    heap_size++;
    a[heap_size] = (-1) * INT_MAX;
    inc_key(a,key, heap_size);
}
void print(int a[],int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
        }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int heap[n];
    for (int i = 0; i < n; i++)
        cin >> heap[i];
    heap_size = n-1;
    //cout << "heap size = " << heap_size << endl;
    build_heap(heap);
    heap_sort(heap, n);
  //  print (heap, n);
    for (int i = 0; i < n; i++) {
       // cout << heap_extract_max(heap) << " ";
       cout << heap[i] << " ";
    }
    cout << endl;
    return 0;
}
