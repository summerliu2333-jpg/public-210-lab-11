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

void inputProduct(Product *pptr) {
    static int nrProd = 1;
    cout << "Input data for Product #" << nrProd << ": ";
    cout << "Name: ";
    getline(cin, pptr->name);
    cout << "SKU: ";
    cin >> pptr->sku;
    
    // Allocate dynamic array for batch quantities
    pptr->batch_quantities = new int[NR_BATCHES];  
    for (int i = 0; i < NR_BATCHES; i++) {
        cout << "Batch #" << i + 1 << " quantity: ";
        cin >> pptr->batch_quantities[i];
    }
    
    cin.ignore();
    cout << endl << endl;
    nrProd++;
}

void inputProduct(Product *);
void displayProduct(Product *);

int main() {
    Product *inventory = new Product[NR_PRODUCTS];
    
    // Input product data
    for (int i = 0; i < NR_PRODUCTS; i++)
    inputProduct(&inventory[i]);

    delete[] inventory;
    inventory = nullptr;
    return 0;
}