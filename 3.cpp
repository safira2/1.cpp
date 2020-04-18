// Soal ke-3
// 3.cpp
// Oleh: Safira Khoirunnisa

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool segitiga(int length, char character){
    if(length>0){
        for(int i = 1, k = 0; i <= length; ++i, k = 0)
        {
            for(int l = 1; l <= length-i; ++l)
            {
                cout <<"  ";
            }

            while(k != 2*i-1)
            {
                cout << character << ' ';
                ++k;
            }
            cout << endl;
        }
        return 0;
    } else{
        return 1;
    }
}

int main(int argc, char **argv){
    int length;
    char character;
    cout << "Enter the triangle's length: ";
    cin >> length;
    cout << endl << "Enter character that what you want (only one character): ";
    cin >> character;
    if(!character) { character = '*'; }
    bool run_segitiga = segitiga(length, character);
    if(run_segitiga){
        return 1;
    } else {
        return 0;
    }
}
