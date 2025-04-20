#include <iostream>
using namespace std;

bool Checking1(int petrol[], int distance[], int size){

    for (int front=0; front<size; front++){
        
        int balance = petrol[front] - distance[front];

        if (balance>=0){
            for (int rear=(front+1)%size; rear!=front; rear++){
                balance = balance + petrol[rear] - distance[rear];
                if (balance<0){
                    break;
                }
            }
        }

        if (balance>=0){
            return true;
        }
    }

    return false;

}

bool Checking2(int petrol[], int distance[], int size){

    int front = 0;

    while (front<size){

        int balance = petrol[front] - distance[front];

        if (balance>=0){

            int rear = front+1;
            while ((rear%size)!=front && balance>=0){
                balance = balance + petrol[rear%size] - distance[rear%size];
                if (balance>=0){
                    rear++;
                }
            }

            if (balance>=0){
                return 1;
            }
            else{
                front = rear+1;
            }

        }

    }

    return 0;
}

bool Checking3(int petrol[], int distance[], int size) {

    int interleave = 0;
    int balance = 0;

    for (int i=0; i<size; i++){

        balance = balance + petrol[i] - distance[i];
        if (balance<0){
            interleave = interleave - balance;
            balance = 0;
        }

    }

    if (balance>=0){
        return 1;
    }
    return 0;
}

int main() {

    int petrol[] = {2,5,4,6,100};
    int distance[] = {2,45,4,20,5};
    int size = sizeof(petrol)/sizeof(petrol[0]);


    // Solution by Brute Force:         Time Complexity -----> O(n^2)       Space Complexity --------> 0(1)

    cout << endl << "Brute Force: " << endl;
    bool isPossible1 = Checking1(petrol, distance, size);

    if (isPossible1){
        cout << "Possible" << endl;
    }
    else{
        cout << "Not Possible" << endl;
    }


    // Solution by Better Solution:         Time Complexity -----> O(n)       Space Complexity --------> 0(1)

    cout << endl << "Better Solution: " << endl;
    bool isPossible2 = Checking2(petrol, distance, size);

    if (isPossible2){
        cout << "Possible" << endl;
    }
    else{
        cout << "Not Possible" << endl;
    }


    // // Solution by Optimised Solution:         Time Complexity -----> O(n^2)       Space Complexity --------> 0(1)

    cout << endl << "Optimised Solution: " << endl;
    bool isPossible3 = Checking3(petrol, distance, size);

    if (isPossible3){
        cout << "Possible" << endl;
    }
    else{
        cout << "Not Possible" << endl;
    }

}