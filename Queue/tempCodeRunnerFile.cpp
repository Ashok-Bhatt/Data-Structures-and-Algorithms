
bool Checking2(int petrol[], int distance[], int size){

    int front = 0;

    while (front<size){

        int balance = petrol[front] - distance[front];
        int rear = (front+1)%size;
