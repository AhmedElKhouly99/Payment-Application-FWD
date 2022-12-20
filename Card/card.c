#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
   char name[25];
    printf("Please enter your name:\n");
    gets(name);
    if(strlen(name) > 24 || strlen(name) < 20 || name == NULL){
        return WRONG_NAME;
    }else{
        strcpy(cardData->cardHolderName, name);
        return CARD_OK;
    }
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    char expiryDate[20];
    printf("Enter card expiry date:\n");
    gets(expiryDate);

    ///"MM/YY"
    if(strlen(expiryDate) != 5
       || expiryDate[2] != '/'
       || !(expiryDate[0] >= '0' && expiryDate[0] <= '1')
       || !(expiryDate[1] >= '0' && expiryDate[1] <= '9')
       || !(expiryDate[3] >= '0' && expiryDate[3] <= '9')
       || !(expiryDate[4] >= '0' && expiryDate[4] <= '9')
       ){
        return WRONG_EXP_DATE;
    }else{
        strcpy(cardData->cardExpirationDate, expiryDate);
        return CARD_OK;
    }
}

EN_cardError_t getCardPAN(ST_cardData_t *cardData){
    char accNum[20];
    printf("Enter card's primary account number:\n");
    gets( accNum);
    if(strlen(accNum) >= 16 && strlen(accNum) <= 19){
        for(int i = 0; i < strlen(accNum); i++){
            if(accNum[i] >= '0' && accNum[i] <= '9'){
                continue;
            }else{
                return WRONG_PAN;
            }
        }
        strcpy(cardData->primaryAccountNumber, accNum);
        return CARD_OK;
    }else{
        return WRONG_PAN;
    }
}
