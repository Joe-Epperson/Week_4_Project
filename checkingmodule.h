#pragma once
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


float GetValue(string usrStr);

float GetValue(string usrStr, float limitUpper);

float GetInterestRate(int creditScore);

void Withdraw(float& usrBalance, float withdrawAmount);

int GetLoanMonths();

int GetCreditRating();

float CalculateLoanAmount(float Principal, float intRate, int numMonths);

void OutputAccount(float bankAmount);
