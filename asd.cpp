#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Addresses {
private:
    string city;
    string street;
    int house_number;
    int apartment_number;


public:
    Addresses(string city, string street, int house_number, int apartment_number) {

    }

    Addresses() {
        city = "Неизвестно";
        street = "Неизвестно";
        house_number = 1;
        apartment_number = 1;
    }

    void get_addresses(Addresses* ad) {
        int count_addres;
        ifstream in("in.txt");
        in >> count_addres;
        for (int i = 0; i < count_addres; i++) {
            in >> ad[i].city;
            in >> ad[i].street;
            in >> ad[i].house_number;
            in >> ad[i].apartment_number;
        }
        in.close();
    }

    string output_addresses(Addresses* ad,int x) {
        int count_addres;
        ifstream in("in.txt");
        in >> count_addres;
        string* line = new string[count_addres]; 
        for (int i = 0; i < count_addres; i++) {
            line[i] = ad[i].city + ", " + ad[i].street + ", " + to_string(ad[i].house_number) + ", " + to_string(ad[i].apartment_number);

        }
        return line[x];
        delete[] line;
        in.close();
    }

    };

    int main() {
        int count_addres;
        ifstream in("in.txt");
        if (in.is_open() == 0) {
            cout << "Не удалось открыть файл in.txt" << endl;
            return 0;
        }
        ofstream out("out.txt");
        if (out.is_open() == 0) {
            cout << "Не удалось открыть файл out.txt" << endl;
            return 0;
            in.close();
        }
        in >> count_addres;
        setlocale(LC_ALL, "Russian");

        Addresses* address = new Addresses[count_addres];
        address->get_addresses(address);
        out << count_addres << endl;
        for (int i = count_addres -1 ; i >= 0; i--) {
            out << address->output_addresses(address,i) << endl;
        }
        in.close();
        out.close();
        delete[] address;
        return 0;
    }