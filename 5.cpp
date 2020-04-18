// Soal ke-5
// 5.cpp
// Oleh: Safira Khoirunnisa

#include <iostream>
#include <string>
#include <cstring>
#include <random>

using namespace std;

class Matrix{
public:
    int Number;
    int *NumberMatrix;
    int FirstSum;
    int SecondSum;
    Matrix(){}
    ~Matrix(){}
    void SearchRandomNumber(int InitialNumber, int Range);
    bool InsertMatrix(int Order);
    void ShowNumberMatrix(int Order);
};

void Matrix::SearchRandomNumber(int InitialNumber, int Range){
    std::random_device Device;
    std::mt19937 RandomNumberGenerator(Device());
    std::uniform_int_distribution<std::mt19937::result_type> random_number(InitialNumber, Range);
    Number = random_number(RandomNumberGenerator);
}
bool Matrix::InsertMatrix(int Order){
    NumberMatrix = new int[Order*Order+1];
    for(int i=0;i<=((Order*Order)-1); ++i){
        SearchRandomNumber(1, 99);
        NumberMatrix[i] = Number;
    }
    int j = 0, k = 0;
    for(int i=0;i<=(Order*Order); ++i){
        if(j == 0 || j == (j+(Order+1))){
            FirstSum = FirstSum+NumberMatrix[j];
        }
        if(k == (Order-1) || k == (k+(Order-1))){
            SecondSum = SecondSum+NumberMatrix[k];
        }
        ++j;
        ++k;
    }
    return 0;
}
void Matrix::ShowNumberMatrix(int Order){
    for(int i=0;i<=(Order*Order); ++i){
        cout << endl;
        cout << "Matriks ke-"<< i << " = " << NumberMatrix[Order] << endl;
    }
    cout << "Hasil diagonal kiri: " << FirstSum << endl;
    cout << "Hasil diagonal kanan: " << SecondSum << endl;
}

int main(int argc, char **argv){
    int order;
    cout << "Masukkan banyak Ordo (Angka x Angka): ";
    cin >> order;
    Matrix matrix;
    matrix.InsertMatrix(order);
    matrix.ShowNumberMatrix(order);
    return 0;
}
