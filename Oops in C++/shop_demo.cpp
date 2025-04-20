
#include <iostream>
using namespace std;

class Shop{

    public:
    int price[100];
    int counter;

    Shop(){
        counter = 0;
    }

    void setPrice(void);
    void showProducts(void);
};

void Shop::setPrice(){
    cout << "Enter the price of product no. " << counter+1 << " : ";
        cin >> price[counter];
        counter++;
}

void Shop::showProducts(){
    for (int i=0; i<counter; i++){
        cout << "Price of product " << i+1 << " is " << price[i] << endl;
    }
}

int main(){
    Shop s1;
    s1.setPrice();
    s1.setPrice();
    s1.setPrice();
    s1.showProducts();
    return 0;
}