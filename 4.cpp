// Soal ke 4
// Program menghilangkan angka nol diantara deret angka


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int num = 1429375420;   // variabel angka
typedef int variabel[num];

// Deklarasi prosedur yang digunakan

int main(int argc, char **argv){
    int angka;
    cout << "Masukkan Angka";
    cin >> angka;
    char string[20];
    sprintf(string, "%d", angka);
    cout << endl << string;
    char *str = string;
    int i=0, j=0;
    while(*str!='\0'){
        if(strcmp(string, "0")){
            while(!(string[j]!='0')){
                string[j] = string[j+1];
                ++j;
            }
        }
        ++i;
        ++str;
    }
    int result = strtol(string, (char**) NULL, 20);
    cout << endl << "Hasilnya adalah: " << result << endl;
    return 0;
}


