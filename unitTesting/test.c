#include <stdio.h>
#include "test.h"

void getCardHolderNameTest(void) {
	EN_cardError_t rtn;
	ST_cardData_t cardData;

	///less than 20
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: getCardHolderName\n");
	printf("Test case 1:\n");
	printf("Input Data: \n");
	rtn = getCardHolderName(&cardData);
	printf("Expected Result: %s\n", "WRONG_NAME");
	printf("Actual Result: %s\n", rtn == 0?"CARD_OK":"WRONG_NAME");

	//more than 24
	printf("Test case 2:\n");
	printf("Input Data: \n");
	rtn = getCardHolderName(&cardData);
	printf("Expected Result: %s\n", "WRONG_NAME");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_NAME");

	//empty name
	printf("Test case 3:\n");
	printf("Input Data: \n");
	rtn = getCardHolderName(&cardData);
	printf("Expected Result: %s\n", "WRONG_NAME");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_NAME");


	//equal 20
	printf("Test case 4:\n");
	printf("Input Data: \n");
	rtn = getCardHolderName(&cardData);
	printf("Expected Result: %s\n", "CARD_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_NAME");

	// equal 24
	printf("Test case 5:\n");
	printf("Input Data: \n");
	rtn = getCardHolderName(&cardData);
	printf("Expected Result: %s\n", "CARD_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_NAME");

	// between 20 & 24
	printf("Test case 6:\n");
	printf("Input Data: \n");
	rtn = getCardHolderName(&cardData);
	printf("Expected Result: %s\n", "CARD_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_NAME");
}


void getCardExpiryDateTest(void) {
	EN_cardError_t rtn;
	ST_cardData_t cardData;

	///empty date
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("Test case 1:\n");
	printf("Input Data: \n");
	rtn = getCardExpiryDate(&cardData);
	printf("Expected Result: %s\n", "WRONG_EXP_DATE");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_EXP_DATE");

	//more than 5
	printf("Test case 2:\n");
	printf("Input Data: \n");
	rtn = getCardExpiryDate(&cardData);
	printf("Expected Result: %s\n", "WRONG_EXP_DATE");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_EXP_DATE");

	//wrong format
	printf("Test case 3:\n");
	printf("Input Data: \n");
	rtn = getCardExpiryDate(&cardData);
	printf("Expected Result: %s\n", "WRONG_EXP_DATE");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_EXP_DATE");


	//valid date
	printf("Test case 4:\n");
	printf("Input Data: \n");
	rtn = getCardExpiryDate(&cardData);
	printf("Expected Result: %s\n", "CARD_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_EXP_DATE");

}


void getCardPANTest(void) {
	EN_cardError_t rtn;
	ST_cardData_t cardData;

	///empty PAN
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: getCardPAN\n");
	printf("Test case 1:\n");
	printf("Input Data: \n");
	rtn = getCardPAN(&cardData);
	printf("Expected Result: %s\n", "WRONG_PAN");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_PAN");

	//more than 19
	printf("Test case 2:\n");
	printf("Input Data: \n");
	rtn = getCardPAN(&cardData);
	printf("Expected Result: %s\n", "WRONG_PAN");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_PAN");

	//less than 16
	printf("Test case 3:\n");
	printf("Input Data: \n");
	rtn = getCardPAN(&cardData);
	printf("Expected Result: %s\n", "WRONG_PAN");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_PAN");


	//equal 19
	printf("Test case 4:\n");
	printf("Input Data: \n");
	rtn = getCardPAN(&cardData);
	printf("Expected Result: %s\n", "CARD_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_PAN");

	//equal 16
	printf("Test case 5:\n");
	printf("Input Data: \n");
	rtn = getCardPAN(&cardData);
	printf("Expected Result: %s\n", "CARD_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_PAN");

	//between 16 & 19
	printf("Test case 6:\n");
	printf("Input Data: \n");
	rtn = getCardPAN(&cardData);
	printf("Expected Result: %s\n", "CARD_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "CARD_OK" : "WRONG_PAN");

}

void getTransactionDateTest(void) {
	EN_terminalError_t rtn;
	ST_terminalData_t termData;

	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: getTransactionDate\n");
	printf("Test case 1:\n");
	printf("Input Data: \n");
	rtn = getTransactionDate(&termData);
	printf("Expected Result: %s\n", "TERMINAL_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "WRONG_DATE");

}

void isCardExpiredTest(void) {
	ST_cardData_t cardData;

	EN_terminalError_t rtn;
	ST_terminalData_t termData;
	rtn = getTransactionDate(&termData);
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: isCardExpired\n");
	
	strcpy(cardData.cardExpirationDate, "10/22");
	printf("Test case 1:\n");
	printf("Input Data: %s\n", cardData.cardExpirationDate);
	rtn = isCardExpired(&cardData, &termData);
	printf("Expected Result: %s\n", "TERMINAL_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "EXPIRED_CARD");

	strcpy(cardData.cardExpirationDate, "09/22");
	printf("Test case 2:\n");
	printf("Input Data: %s\n", cardData.cardExpirationDate);
	rtn = isCardExpired(&cardData, &termData);
	printf("Expected Result: %s\n", "EXPIRED_CARD");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "EXPIRED_CARD");

	strcpy(cardData.cardExpirationDate, "10/23");
	printf("Test case 3:\n");
	printf("Input Data: %s\n", cardData.cardExpirationDate);
	rtn = isCardExpired(&cardData, &termData);
	printf("Expected Result: %s\n", "TERMINAL_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "EXPIRED_CARD");
}

void getTransactionAmountTest(void) {
	EN_terminalError_t rtn;
	ST_terminalData_t termData;

	//0
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: getTransactionAmount\n");
	printf("Test case 1:\n");
	printf("Input Data: \n");
	rtn = getTransactionAmount(&termData);
	printf("Expected Result: %s\n", "INVALID_AMOUNT");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "INVALID_AMOUNT");

	//-1
	printf("Test case 2:\n");
	printf("Input Data: \n");
	rtn = getTransactionAmount(&termData);
	printf("Expected Result: %s\n", "INVALID_AMOUNT");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "INVALID_AMOUNT");

	//0.1
	printf("Test case 3:\n");
	printf("Input Data: \n");
	rtn = getTransactionAmount(&termData);
	printf("Expected Result: %s\n", "TERMINAL_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "INVALID_AMOUNT");
}

void setMaxAmountTest(void) {
	EN_terminalError_t rtn;
	ST_terminalData_t termData;

	//0
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: setMaxAmount\n");
	printf("Test case 1:\n");
	printf("Input Data: 0\n");
	rtn = setMaxAmount(&termData, 0);
	printf("Expected Result: %s\n", "INVALID_MAX_AMOUNT");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "INVALID_MAX_AMOUNT");

	//-1
	printf("Test case 2:\n");
	printf("Input Data: -1\n");
	rtn = setMaxAmount(&termData, -1);
	printf("Expected Result: %s\n", "INVALID_MAX_AMOUNT");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "INVALID_MAX_AMOUNT");

	//1
	printf("Test case 3:\n");
	printf("Input Data: 1\n");
	rtn = setMaxAmount(&termData, 1);
	printf("Expected Result: %s\n", "TERMINAL_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "INVALID_MAX_AMOUNT");
}

void isBelowMaxAmountTest(void) {
EN_terminalError_t rtn;
ST_terminalData_t termData;
termData.maxTransAmount = 100;

//below
printf("Tester Name: Ahmed ElKhouly\n");
printf("Function Name: isBelowMaxAmount\n");

termData.transAmount = 99.9;
printf("Test case 1:\n");
printf("Input Data: %f\n", termData.transAmount);
rtn = isBelowMaxAmount(&termData);
printf("Expected Result: %s\n", "TERMINAL_OK");
printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "EXCEED_MAX_AMOUNT");

//equal
termData.transAmount = 100;
printf("Test case 2:\n");
printf("Input Data: %f\n", termData.transAmount);
rtn = isBelowMaxAmount(&termData);
printf("Expected Result: %s\n", "TERMINAL_OK");
printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "EXCEED_MAX_AMOUNT");

//above
termData.transAmount = 100.1;
printf("Test case 3:\n");
printf("Input Data: %f\n", termData.transAmount);
rtn = isBelowMaxAmount(&termData);
printf("Expected Result: %s\n", "EXCEED_MAX_AMOUNT");
printf("Actual Result: %s\n", rtn == 0 ? "TERMINAL_OK" : "EXCEED_MAX_AMOUNT");
}

void recieveTransactionDataTest(void) {
	EN_transStat_t rtn;
	ST_transaction transData = { {"aaaaaaaaaaaaaaaaaaaaa", "12345678901234561", "1/23"}, 
		{1300, 1500, "28/10/2202"}, APPROVED, 0};

	
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: recieveTransactionData\n");
	//below not found
	printf("Test case 1:\n");
	printf("Input Data: 12345678901234561\n");
	rtn = recieveTransactionData(&transData);
	printf("Expected Result: %s\n", "FRAUD_CARD");
	printf("Actual Result: %s\n", rtn == 0 ? "APPROVED" : "FRAUD_CARD");

	//amount is not available
	strcpy(transData.cardHolderData.primaryAccountNumber, "1234567890123456");
	printf("Test case 2:\n");
	printf("Input Data: 1300\n");
	rtn = recieveTransactionData(&transData);
	printf("Expected Result: %s\n", "DECLINED_INSUFFECIENT_FUND");
	printf("Actual Result: %s\n", rtn == 0 ? "APPROVED" : "DECLINED_INSUFFECIENT_FUND");

	//account is blocked
	strcpy(transData.cardHolderData.primaryAccountNumber, "12345678901234567");
	printf("Test case 3:\n");
	printf("Input Data: 1300\n");
	rtn = recieveTransactionData(&transData);
	printf("Expected Result: %s\n", "DECLINED_STOLEN_CARD");
	printf("Actual Result: %s\n", rtn == 0 ? "APPROVED" : "DECLINED_STOLEN_CARD");

	//transaction APPROVED
	strcpy(transData.cardHolderData.primaryAccountNumber, "123456789012345678");
	printf("Test case 4:\n");
	printf("Input Data: 1300\n");
	rtn = recieveTransactionData(&transData);
	printf("Expected Result: %s\n", "APPROVED");
	printf("Actual Result: %s\n", rtn == 0 ? "APPROVED" : "DECLINED_STOLEN_CARD");
}

void isValidAccountTest(void) {
	ST_transaction transData = { {"aaaaaaaaaaaaaaaaaaaaa", "12345678901234561", "1/23"},
		{1300, 1500, "28/10/2202"}, APPROVED, 0 };
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: isValidAccount\n");
	//below not found
	EN_transStat_t rtn = isValidAccount(&transData.cardHolderData, &accountsDB);
	printf("Test case 1:\n");
	printf("Input Data: 12345678901234561\n");
	printf("Expected Result: %s\n", "ACCOUNT_NOT_FOUND");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "ACCOUNT_NOT_FOUND");

	//found
	strcpy(transData.cardHolderData.primaryAccountNumber, "1234567890123456");
	printf("Test case 2:\n");
	printf("Input Data: 1234567890123456\n");
	rtn = isValidAccount(&transData.cardHolderData, &accountsDB);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "ACCOUNT_NOT_FOUND");
}

void isBlockedAccountTest(void) {
	ST_transaction transData = { {"aaaaaaaaaaaaaaaaaaaaa", "12345678901234567", "1/23"},
		{1300, 1500, "28/10/2202"}, APPROVED, 0 };
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: isBlockedAccount\n");
	//blocked
	EN_transStat_t rtn = isValidAccount(&transData.cardHolderData, &accountsDB);
	rtn = isBlockedAccount(&accountsDB[indexFound]);
	printf("Test case 1:\n");
	printf("Input Data: 12345678901234567\n");
	printf("Expected Result: %s\n", "BLOCKED_ACCOUNT");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "BLOCKED_ACCOUNT");

	//running
	strcpy(transData.cardHolderData.primaryAccountNumber, "1234567890123456");
	printf("Test case 2:\n");
	printf("Input Data: 1234567890123456\n");
	rtn = isValidAccount(&transData.cardHolderData, &accountsDB);
	rtn = isBlockedAccount(&accountsDB[indexFound]);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "BLOCKED_ACCOUNT");
}

void isAmountAvailableTest(void) {
	ST_transaction transData = { {"aaaaaaaaaaaaaaaaaaaaa", "1234567890123456", "1/23"},
		{1300, 1500, "28/10/2202"}, APPROVED, 0 };
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: isAmountAvailable\n");
	//INSUFFECIENT 
	EN_transStat_t rtn = isValidAccount(&transData.cardHolderData, &accountsDB);
	rtn = isAmountAvailable(&transData.terminalData, &accountsDB[indexFound]);
	printf("Test case 1:\n");
	printf("Input Data: 1300\n");
	printf("Expected Result: %s\n", "LOW_BALANCE");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "LOW_BALANCE");

	//available
	transData.terminalData.transAmount = 1200;
	printf("Test case 2:\n");
	printf("Input Data: 1200\n");
	//rtn = isValidAccount(&transData.cardHolderData, &accountsDB);
	rtn = isAmountAvailable(&transData.terminalData, &accountsDB[indexFound]);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "LOW_BALANCE");
}

void saveTransactionTest(void) {
	EN_transStat_t rtn;
	ST_transaction transData = { {"aaaaaaaaaaaaaaaaaaaaa", "12345678901234561", "1/23"},
		{1300, 1500, "28/10/2202"}, APPROVED, 0 };
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: saveTransaction\n");
	//not found
	printf("Test case 1:\n");
	printf("Input Data: FRAUD_CARD\n");
	transData.transState = FRAUD_CARD;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");

	//amount is not available
	strcpy(transData.cardHolderData.primaryAccountNumber, "1234567890123456");
	printf("Test case 2:\n");
	printf("Input Data: DECLINED_INSUFFECIENT_FUND\n");
	transData.transState = DECLINED_INSUFFECIENT_FUND;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");

	//account is blocked
	strcpy(transData.cardHolderData.primaryAccountNumber, "12345678901234567");
	printf("Test case 3:\n");
	printf("Input Data: DECLINED_STOLEN_CARD\n");
	transData.transState = DECLINED_STOLEN_CARD;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");

	//transaction APPROVED
	strcpy(transData.cardHolderData.primaryAccountNumber, "123456789012345678");
	printf("Test case 4:\n");
	printf("Input Data: APPROVED\n");
	transData.transState = APPROVED;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");
}

void listSavedTransactionsTest(void) {
	EN_transStat_t rtn;
	ST_transaction transData = { {"aaaaaaaaaaaaaaaaaaaaa", "12345678901234561", "1/23"},
		{1300, 1500, "28/10/2202"}, APPROVED, 0 };
	printf("Tester Name: Ahmed ElKhouly\n");
	printf("Function Name: listSavedTransactions\n");
	//not found
	printf("Test case 1:\n");
	printf("Input Data: FRAUD_CARD\n");
	transData.transState = FRAUD_CARD;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");

	//amount is not available
	strcpy(transData.cardHolderData.primaryAccountNumber, "1234567890123456");
	printf("Test case 2:\n");
	printf("Input Data: DECLINED_INSUFFECIENT_FUND\n");
	transData.transState = DECLINED_INSUFFECIENT_FUND;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");

	//account is blocked
	strcpy(transData.cardHolderData.primaryAccountNumber, "12345678901234567");
	printf("Test case 3:\n");
	printf("Input Data: DECLINED_STOLEN_CARD\n");
	transData.transState = DECLINED_STOLEN_CARD;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");

	//transaction APPROVED
	strcpy(transData.cardHolderData.primaryAccountNumber, "123456789012345678");
	printf("Test case 4:\n");
	printf("Input Data: APPROVED\n");
	transData.transState = APPROVED;
	rtn = saveTransaction(&transData);
	printf("Expected Result: %s\n", "SERVER_OK");
	printf("Actual Result: %s\n", rtn == 0 ? "SERVER_OK" : "INTERNAL_SERVER_ERROR");
}