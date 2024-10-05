#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

enum Transaction { DEPOSIT, WITHDRAWAL, BALANCE_CHECK }; 

void deposit(float *balance, char transactions[][50], int *transaction_count){
    float amount;
    printf("Enter the transaction amount: ");
    scanf("%f", &amount);
    *balance += amount;
    sprintf(transactions[(*transaction_count)++], "Deposited amount: %.2f", amount);
}

void withdraw(float *balance, char transactions[][50], int *transaction_count) {
    float amount;
    printf("Enter the withdrawal amount: ");
    scanf("%f", &amount);
    if (amount <= *balance) {
        *balance -= amount;
        sprintf(transactions[(*transaction_count)++], "Withdrawal amount: %.2f", amount);
    } else {
        printf("Insufficient Balance\n");
    }
}

void check_balance(float balance) {
    printf("Your Balance is: %.2f\n", balance);
}

void display_transactions(char transactions[][50], int transaction_count) {
    printf("\nTransaction History:\n");
    for (int i = 0; i < transaction_count; i++) {
        printf("%s\n", transactions[i]);
    }
}

int main() {
    char name[50], account_number[15];
    float balance = 0;
    char transactions[100][50]; // Array to store transaction history
    int transaction_count = 0;

    printf("Enter Your Name: ");
    scanf("%s", name); // No need for '&' with arrays
    printf("Enter Your Account Number: ");
    scanf("%s", account_number); // No need for '&' with arrays

    int choice;
    do {
        printf("\n1 - Deposit\n2 - Withdrawal\n3 - Check Balance\n4 - Exit\n");
        printf("Choose a Transaction: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(&balance, transactions, &transaction_count);
                break;
            case 2:
                withdraw(&balance, transactions, &transaction_count);
                break;
            case 3:
                check_balance(balance);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 4);

    display_transactions(transactions, transaction_count);
    printf("Thank You\n");

    return 0;
}
