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
    Addresses() {
        city = "Неизвестно";
        street = "Неизвестно";
        house_number = 1;
        apartment_number = 1;
    }

    static int get_output_addresses() {
        ifstream in("in.txt");
        if (in.is_open() == 0) {
            cout << "Не удалось открыть in.txt" << endl;
            return 0;
        }
        ofstream out("out.txt");
        if (out.is_open() == 0) {
            cout << "Не удалось открыть out.txt" << endl;
            in.close();
            return 0;
        }
        int size;
        string line;
        in >> size;
        Addresses* ad = new Addresses[size];

        for (int i = 0; i < size; i++) {
            in >> ad[i].city;
            in >> ad[i].street;
            in >> ad[i].house_number;
            in >> ad[i].apartment_number;
        }
        for (int i = size-1; i >= 0; i--) {
            line = ad[i].city + ", " + ad[i].street + ", " + to_string(ad[i].house_number) + ", " + to_string(ad[i].apartment_number) + "\n";

            out << line;
        }


        out.close();
        in.close();
        delete[] ad;
        return size;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Addresses address;
    address.get_output_addresses();

    return 0;
}