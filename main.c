#include <stdio.h>
#include "Application/app.h"
#include "unitTesting/test.h"
#pragma warning( disable : 4996 )


void main(void) {
	//getCardHolderNameTest();
	//getCardExpiryDateTest();
	//getCardPANTest();
	//getTransactionDateTest();
	//isCardExpiredTest();
	//getTransactionAmountTest();
	//setMaxAmountTest();
	//isBelowMaxAmountTest();
	//appStart();
	//recieveTransactionDataTest();
	//isValidAccountTest();
	//isBlockedAccountTest();
	//isAmountAvailableTest();
	//saveTransactionTest();
	//listSavedTransactionsTest();


	while (1)
	{
		fflush(stdin);
		appStart();

		uint8_t again = 0;
		printf("\n\t****Do you want to make a new transaction? (Y/N)****\n");
		again = getchar();
		again = getchar();
		if (again == 'Y' || again == 'y') {
			
			continue;
		}
		else
		{
			return;
		}
	}
}