#include <stdio.h>
#include <stdlib.h>
#include "../Terminal/terminal.h"
#include "../Card/card.h"
#include "../Server/server.h"
#include "app.h"


void appStart(void){
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction transData;
	EN_terminalError_t ret_term;
	EN_cardError_t ret_card = getCardHolderName(&cardData);
	while (ret_card == WRONG_NAME) {
		printf("\n\t****WRONG_NAME****\n");
		printf("Re-enter:\n");
		ret_card = getCardHolderName(&cardData);
	}
	ret_card = getCardExpiryDate(&cardData);
	while (ret_card == WRONG_EXP_DATE) {
		printf("\n\t****WRONG_EXP_DATE****\n");
		printf("Re-enter:\n");
		ret_card = getCardExpiryDate(&cardData);
	}
	ret_card = getCardPAN(&cardData);
	while (ret_card == WRONG_PAN) {
		printf("\n\t****WRONG_PAN****\n");
		printf("Re-enter:\n");
		ret_card = getCardPAN(&cardData);
	}
	float amount = 0;
	printf("Please enter the transaction max amount: ");
	scanf("%f", &amount);
	ret_term = setMaxAmount(&termData, amount);
	while (ret_term == INVALID_AMOUNT) {
		printf("\n\t****INVALID AMOUNT****\n");
		printf("Re-enter:\n");
		printf("Please enter the transaction max amount: ");
		scanf("%f", &amount);
		ret_term = setMaxAmount(&termData, amount);
	}
	ret_term = getTransactionDate(&termData);
	while (ret_term == WRONG_DATE) {
		printf("\n\t****WRONG_DATE****\n");
		printf("Re-enter:\n");
		ret_term = getTransactionDate(&termData);
	}
	ret_term = isCardExpired(&cardData, &termData);
	if (ret_term == EXPIRED_CARD) {
		printf("\n\n\t****EXPIRED_CARD****\n");
		return;
	}
	ret_term = getTransactionAmount(&termData);
	while (ret_term == INVALID_AMOUNT) {
		printf("\n\t****INVALID_AMOUNT****\n");
		printf("Re-enter:\n");
		ret_term = getTransactionAmount(&termData);
	}
	ret_term = isBelowMaxAmount(&termData);
	if (ret_term == EXCEED_MAX_AMOUNT){
		printf("\n\t****DECLINED EXCEED_MAX_AMOUNT****\n");
		return;
	}
	transData.cardHolderData = cardData;
	transData.terminalData = termData;
	EN_transStat_t transSt = recieveTransactionData(&transData);
}
