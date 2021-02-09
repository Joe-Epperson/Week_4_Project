#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float GetValue(string usrStr)
{
	// initializes the number to less than 0 so that the loop will execute
	float usrNum = -1;
	while (usrNum <= 0)
	{
		// while loop to continue until the input is greater than zero
		// I tried error handling for str and char but I couldnt do it
		cout << usrStr << endl;
		cin >> usrNum;
		cout << endl;
		if (usrNum > 0)
		{
			break;
		}
		else
		{
			cout << "Enter a number greater than zero" << endl;
			cout << endl;
			continue;
		}
	}
	return usrNum;
}

float GetValue(string usrStr, float limitUpper)
{
	// initializes the number to less than 0 so that the loop will execute
	float usrNum = -1;
	while ((usrNum <= 0) || (usrNum > limitUpper))
	{
		// while loop to continue until the input is greater than zero
		cout << usrStr << endl;
		cin >> usrNum;
		cout << endl;
		if ((usrNum > 0) && (usrNum <= limitUpper))
		{
			break;
		}
		else
		{
			cout << "Please enter a value inbetween your current balance: $" << limitUpper << " and zero." << endl;
			cout << endl;
			continue;
		}
	}
	return usrNum;
}

float GetInterestRate(int creditScore)
{
	double intRate;
	// using an if else if chain to determine the interest rate based on the value of the credit score
	if (creditScore <= 500)
	{
		intRate = 0.05;
	}
	else if ((creditScore > 500) && (creditScore <= 700))
	{
		intRate = 0.03;
	}
	else if (creditScore > 700)
	{
		intRate = 0.01;
	}

	return intRate;
}

void Withdraw(float& usrBalance, float withdrawAmount)
{
	// just reducing the account balance by the withdraw amount
	usrBalance = usrBalance - withdrawAmount;
}

int GetLoanMonths()
{
	int loanMonths = 0;
	// initialized the variable with zero so that the loop will execute at least once

	while ((loanMonths != 12) && (loanMonths != 24) && (loanMonths != 36) && (loanMonths != 60))
	{
		cout << "Please enter the number of months the loan will last for: " << endl;
		cin >> loanMonths;
		cout << endl;
		//check to see if the value inputted is what we are looking for, if not I tell them the limits to input and continue the loop

		if ((loanMonths != 12) && (loanMonths != 24) && (loanMonths != 36) && (loanMonths != 60))
		{
			cout << "Plese enter a value of 12, 24, 36, or 60" << endl;
			cout << endl;
			continue;
		}
		else
		{
			break;
		}
	}
	
	return loanMonths;

}

int GetCreditRating()
{
	int creditScore = 0;
	// initialized the variable with zero so that the loop will execute at least once

	while ((creditScore < 300) || (creditScore > 850))
	{
		cout << "Please enter your credit score: " << endl;
		cin >> creditScore;
		cout << endl;
		//check to see if the value inputted is what we are looking for, if not I tell them the limits to input and continue the loop

		if ((creditScore < 300) || (creditScore > 850))
		{
			cout << "Please enter a value between 300 and 850 inclusive" << endl;
			cout << endl;
			continue;
		}
		else
		{
			break;
		}
	}

	return creditScore;

}

float CalculateLoanAmount(float principalAmt, float intRate, int numMonths)
{
	// getting the value fot the parts of the expression early so that the calculations turn out correct
	int monthRate;
	float rateVal;
	float totalAmount;

	monthRate = numMonths / 12;
	rateVal = (intRate / 12) + 1;

	// calculate the total loan amount based on the variables above
	totalAmount = principalAmt * (pow(rateVal, monthRate));

	cout << "Interest Rate: " << intRate << endl;
	cout << endl;
	cout << "Principal: $" << principalAmt << endl;
	cout << endl;
	cout << "Months: " << numMonths << endl;
	cout << endl;
	cout << "Your total loan amount: $" << totalAmount << endl;
	cout << endl;

	return totalAmount;
}

void OutputAccount(float bankAmount)
{
	//outputting the account balance of the user
	cout << endl;
	cout << "You have money in your account!...  probably." << endl;
	cout << "Your current account balance is $" << bankAmount << endl;
}