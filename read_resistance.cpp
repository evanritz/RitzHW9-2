// read_resistance.cpp
//
// This program takes no arguments
// This program uses the analogIn class 
// This program reads the ADC value on p9.39 
// and calculates the resistance on the voltage
// divider circuit
//
// Circuit Resistance: 820 Ohms
//
// Written by Evan

#include <iostream>

#include "analogIn.h"

using namespace std;

#define MAX_ADC 4095
#define Vin 1.8f
#define R1 10000

int main(int argc, char* argv[]) {
    
    AnalogIn AIN(0);

    int adc_val = AIN.readADCsample();

    float Vout = (Vin * adc_val)/MAX_ADC;

    float R2 = (Vout * R1)/(Vin - Vout);
    
    cout << "Using AIN" << AIN.getNumber() << " to read analog value" << endl;
    cout << "Reading resistance..." << endl;    
    cout << "Vout ADC Value: " << adc_val << endl;
    cout << "Vout: " << Vout << "V" << endl;
    cout << "R2: " << R2 << "Ohms" << endl;

}
