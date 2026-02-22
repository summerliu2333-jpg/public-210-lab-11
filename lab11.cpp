//COMSC-210-5068, Lab 11, Yang Liu
#include <iostream>
using namespace std;

const int NR_BATCHES = 2, NR_PRODUCTS = 3;

struct Product {
    string name;
    string sku;
    int *batch_quantities;

    //memory cleanup
    ~Product() {
        if (batch_quantities)
            delete[] batch_quantities;
        batch_quantities = nullptr;
    }
};

void inputProduct(Product *);
void displayProduct(Product *);

int main() {
    return 0;
}