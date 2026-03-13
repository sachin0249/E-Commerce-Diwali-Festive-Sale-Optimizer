#include <iostream>
#include <string>
using namespace std;

struct Product {
    int productID;
    string productName;
    int productSale;
};

void heapify(Product arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].productSale > arr[largest].productSale)
        largest = left;

    if (right < n && arr[right].productSale > arr[largest].productSale)
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Product arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product p[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter ProductID ProductName Sales: ";
        cin >> p[i].productID >> p[i].productName >> p[i].productSale;
    }

    heapSort(p, n);

    cout << "\nTop 5 Best Selling Products:\n";
    int limit = (n < 5) ? n : 5;

    for (int i = n - 1; i >= n - limit; i--) {
        cout << p[i].productID << " "
             << p[i].productName << " "
             << p[i].productSale << endl;
    }

    return 0;
}
