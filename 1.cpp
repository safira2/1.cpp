// PROGRAM Biodata
// Program untuk membuat Biodata
// oleh Safira Khoirunnisa untuk Bootcamp Arkademy
// Compiler: LLVM Clang 9.0.1 x86_64-unknown-linux-musl
// OS: Linux 5.4.25_1 (Void Linux)

#include <iostream>
#include <fstream>
#include <memory>
#include <cstring>
#include <json/value.h>
#include <json/writer.h>

using namespace std;

// Fungsi biodata (bool)
// name adalah string dan age adalah angka (int) dalam fungsi biodata
bool biodata(char *name, int age){
    // Membuat dan Membuka file JSON untuk manipulasi data
    ofstream FileJSONBiodata;
    FileJSONBiodata.open("Biodata.json");

    // Mengisikan file JSON
    Json::Value Biodata;
    Biodata["name"] = Json::Value(name);
    Biodata["age"] = Json::Value(age); // age (Number)
    Biodata["address"] = Json::Value("Jalan Kiara Raya No. 20 RT. 007 / RW. 05 Jatirasa, Jatiasih"); // address (String)

    Json::Value Hobbies; // Array hobbies
    Hobbies[0] = Json::Value("Berenang (Swimming)");
    // Isikan ke entri hobbies
    Biodata["hobbies"] = Hobbies;
    Biodata["is_married"] = Json::Value(false);

    Json::Value ListSchool; // Array of Object list_school
    ListSchool["name"] = Json::Value("SMA Negeri 8 Kota Bekasi");
    ListSchool["year_in"] = Json::Value(2017);
    ListSchool["year_out"] = Json::Value(2020);
    ListSchool["major"] = Json::Value("null"); // Why are you using American English "Major"?! We are using "degree" although it's different from American Education System
    // Isikan ke entri list_school
    Biodata["list_school"] = ListSchool;

    Json::Value Skills; // Array of Object skills
    Skills["skill_name"] = Json::Value("Programming");
    Skills["level"] = Json::Value("beginner");
    // Isikan ke entri skills
    Biodata["skills"] = Skills;

    Biodata["interest_in_coding"] = Json::Value(true); // interest_in_coding (bool)

    // Tuliskan JSON yang telah jadi ke file JSON
    Json::StreamWriterBuilder WriteJSONtoFile;
    std::unique_ptr<Json::StreamWriter> writer(WriteJSONtoFile.newStreamWriter());
    writer->write(Biodata, &FileJSONBiodata);

    // Menutup File
    FileJSONBiodata.close();
    return 0;
}

int main(int argc, char **argv) {
    if((strcmp(argv[0], "biodata")) || (strcmp(argv[0], "GuessYourself"))){
        bool running_biodata_function;
        running_biodata_function = biodata("Safira Khoirunnisa", 32);
        if(!running_biodata_function){ return 0; }
        else { return 1; }
    } else{
        cout << endl << "You must type your program in Console like:" << endl;
        cout << endl << "biodata <Your name> <Your age>" << endl << endl;
        return 1;
    }
}
