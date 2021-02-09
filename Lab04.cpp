// Joe Epperson, IV
// jee4cf@umsystem.edu
// February 8, 2021
// CS201L Lab 04

#include <iostream>
#include <string>
#include <cmath>
#include "checkingmodule.h"
using namespace std;


int main() {
	float accountValue = 0.0f;
	char usrInput = 'f';
	usrInput = toupper(usrInput);

	//while loop to continue until the user inputs q in order to quit
	while (usrInput != 'Q')
	{
		//main menu section, mainly to make things easy to see for the user
		cout << "Main Menu:" << endl;
		cout << "----------" << endl;
		cout << "Select one of the options below:" << endl;
		cout << "(D)eposit" << endl;
		cout << "(W)ithdraw" << endl;
		cout << "(L)oan" << endl;
		cout << "(Q)uit" << endl;
		cout << endl;
		cout << "What is your choice? ";

		cin >> usrInput;
		cout << endl;

		// making sure the usr input is upper cased so that my switch statements check correctly
		usrInput = toupper(usrInput);

		switch (usrInput)
		{
		case 'D':
			//calculations for the deposit as well as the statements required
			float depositVal;
			depositVal = GetValue("Please enter a value to deposit into your account: ");
			accountValue += depositVal;
			OutputAccount(accountValue);
			break;

		case 'W':
			//calculations for the withdraw as well as the statements required
			float withdrawVal;
			withdrawVal = GetValue("Please enter a value to withdraw from your account: ", accountValue);
			Withdraw(accountValue, withdrawVal);
			OutputAccount(accountValue);
			break;

		case 'L':
			//calculations for the loan as well as the statements required
			int creditScore;
			int loanMonths;
			float interestRate;
			float principalVal;
			float totalLoanAmt;

			creditScore = GetCreditRating();
			loanMonths = GetLoanMonths();

			principalVal = -10.0;
			//while loop in order to determine principal amount
			while (principalVal < 0)
			{
				cout << "How much do you want to borrow? ";
				cin >> principalVal;
				cout << endl;

				if (principalVal >= 0)
				{
					break;
				}
				else
				{
					cout << "Enter a value greater than or equal to zero" << endl;
					cout << endl;
					continue;
				}
			}
			//calculations for interest rate as well as total loan
			interestRate = GetInterestRate(creditScore);

			totalLoanAmt = CalculateLoanAmount(principalVal, interestRate, loanMonths);
			break;

		case 'Q':
			//ending statements as well as proper functions to exit the loop
			cout << "Thank you for using our service!" << endl;
			cout << endl;
			cout << "Your final account balance was $" << accountValue << endl;
			break;

		default:
			//default statement in order to fix any incorrect inputs from the user
			cout << "Please enter D, W, L, or Q" << endl;
			break;
		}
	}

	return 0;
}
