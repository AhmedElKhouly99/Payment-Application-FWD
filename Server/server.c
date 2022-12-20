#include "server.h"

ST_accountsDB_t accountsDB[255] = { {2000.0, RUNNING, "8989374615436851"},
    {100000.0, BLOCKED, "5807007076043875"}, 
    {1200, RUNNING, "1234567890123456"}, 
    {600, BLOCKED, "12345678901234567"}, 
    {1500, RUNNING, "123456789012345678"} };
ST_transaction ST_transactions[255] = { 0 };
uint32_t squenceNum = 0;
uint32_t indexFound = -1;

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence) {
    uint32_t i;
    for (i = 0; i < 255; i++) {
        if (strcmp(cardData->primaryAccountNumber, accountRefrence[i].primaryAccountNumber) == 0) {
            indexFound = i;
            return SERVER_OK;
        }
    }
    accountRefrence = NULL;
    return ACCOUNT_NOT_FOUND;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence) {
    if (accountRefrence->state == RUNNING) {
        return SERVER_OK;
    }
    return BLOCKED_ACCOUNT;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence) {
    if (termData->transAmount <= accountRefrence->balance) {
        return SERVER_OK;
    }
    return LOW_BALANCE;
}

EN_serverError_t saveTransaction(ST_transaction* transData) {
    ST_transactions[squenceNum].terminalData = transData->terminalData;
    ST_transactions[squenceNum].cardHolderData = transData->cardHolderData;
    ST_transactions[squenceNum].transactionSequenceNumber = squenceNum;
    ST_transactions[squenceNum].transState = transData->transState;
    squenceNum++;
    listSavedTransactions();
    return SERVER_OK;
}

void listSavedTransactions(void) {
    uint8_t state[28] = {0};
    for (uint32_t i = 0; i < squenceNum; i++)
    {
        switch (ST_transactions[i].transState)
        {
        case 0:
            strcpy(state, "APPROVED");
            break;
        case 1:
            strcpy(state, "DECLINED_INSUFFECIENT_FUND");
            break;
        case 2:
            strcpy(state, "DECLINED_STOLEN_CARD");
            break;
        case 3:
            strcpy(state, "FRAUD_CARD");
            break;
        case 4:
            strcpy(state, "INTERNAL_SERVER_ERROR");
            break;
        default:
            break;
        }
        
        printf("#########################\n"
            "Transaction Sequence Number : %d\n"
            "Transaction Date : %s\nTransaction Amount : %f\n"
            "Transaction State : %s\nTerminal Max Amount : %f\n"
            "Cardholder Name : %s\n"
            "PAN: %s\n"
            "Card Expiration Date : %s\n"
            "#########################\n",
            ST_transactions[i].transactionSequenceNumber, ST_transactions[i].terminalData.transactionDate,
            ST_transactions[i].terminalData.transAmount, state,
            ST_transactions[i].terminalData.maxTransAmount,ST_transactions[i].cardHolderData.cardHolderName, 
            ST_transactions[i].cardHolderData.primaryAccountNumber, 
            ST_transactions[i].cardHolderData.cardExpirationDate);
    }
}

EN_transStat_t recieveTransactionData(ST_transaction* transData) {
    ST_accountsDB_t* accountRefrence = accountsDB;
    EN_transStat_t state = APPROVED;
    if (isValidAccount(&(transData->cardHolderData), accountRefrence) == ACCOUNT_NOT_FOUND) {
        state = FRAUD_CARD;
    }else
    if (isBlockedAccount(accountRefrence+indexFound) == BLOCKED_ACCOUNT) {
        state = DECLINED_STOLEN_CARD;
    }else
    if (isAmountAvailable(&(transData->terminalData), accountRefrence+indexFound) == LOW_BALANCE) {
        state = DECLINED_INSUFFECIENT_FUND;
    }
    transData->transState = state;
    if (saveTransaction(transData) != SERVER_OK) {
        return INTERNAL_SERVER_ERROR;
    }
    if (state == APPROVED) {
        printf("Amount after withdraw %f\n", (accountRefrence + indexFound)->balance);
        (accountRefrence+indexFound)->balance -= transData->terminalData.transAmount;
    }
    printf("Amount after withdraw %f\n", (accountRefrence + indexFound)->balance);
    return state;
}

