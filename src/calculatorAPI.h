#ifndef CALCULATOR_API_H
#define CALCULATOR_API_H

#include "soap/soapH.h"

const char * g_serviceURL;
extern struct soap * g_soap;

void startCalculatorAPI();
void closeCalculatorAPI();

const int additionOperation(const int firstNumber, const int secondNumber);
const int subtractionOperation(const int firstNumber, const int secondNumber);
const int multiplyOperation(const int firstNumber, const int secondNumber);
const int divideOperation(const int firstNumber, const int secondNumber);

#endif
