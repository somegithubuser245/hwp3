#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "plottyfile.h"

using namespace std;

B15F& drv = B15F::getInstance();

struct VoltageData {
    double voltageIn;
    double voltageOut;

    VoltageData(double in, double out) : voltageIn(in), voltageOut(out) {}
};

// Function to store data in a .txt file
void storeData(const vector<VoltageData>& data, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : data) {
            file << entry.voltageIn << ";" << entry.voltageOut << endl;
        }
        file.close();
        cout << "Data stored successfully in " << filename << endl;
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

int main() {
    return 0;
}

void case6() {

    drv.analogWrite0(0);
    vector<VoltageData> voltageData;
    std::string filename = "lowhigh";
    int plottyf_count = 1;

    for(int i = 0; i < 1024; i+= 20)
    {
        double voltageOut = double (drv.analogWrite(i));
        double voltageIn = double (drv.analogRead0() / 1023);
        voltageData.emplace_back(voltageIn, voltageOut);
    }

    filename += std::to_string(plottyf_count);
    storeData(voltageData, filename);
    plottyf_count += 1;
}

void case7() {

    drv.analogWrite0(0);
    vector<VoltageData> voltageData;
    std::string filename = "lowhigh";
    double verluste[6];
    int plottyf_count = 1;

    for(int i = 1; i < 7; ++i)
    {
        double out = drv.analogWrite0(1023);
        double in = drv.analogRead0();
        double verlust = double ((out - in) / 1023);
        verluste[i-1] = verlust;
        std::cout << "NAND " << i << " " << verlust << "V\n";
    }

}




