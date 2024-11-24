#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
    char phoneNo[50];
    char accNo[50];
    char password[50];
    float balance;
};


// Function Main - Code Entry Point
int main(void) {
    // Variable Declaration
    struct user user, user1;
    FILE *fp;
    char fileName[50], phone[50], pword[50], pword1[50];
    int opt, choice;
    float deposit;
    char cont = 'y';

    system("cls");
    printf("\n\n\t\t\t Please Select an operation to perform? ");
    printf("\n\n1. Register an Account");
    printf("\n\n2. Login to an Account");

    printf("\n\nEnter your choice: \t");
    scanf("%d", &opt);

    if (opt == 1) {
        system("cls");
        printf("Please Enter your Account Number: ");
        scanf("%s", user.accNo);
        printf("\nPlease Enter your Phone Number: ");
        scanf("%s", user.phoneNo);
        printf("\nPlease Enter your new Password: ");
        scanf("%s", user.password);
        user.balance = 0.0;
        strcpy(fileName, user.phoneNo);
        fp = fopen(strcat(fileName, ".data"), "w");
        fwrite(&user, sizeof(struct user), 1, fp);
        if (fwrite != 0) {
            printf("\n\n\t Account Created Successfully! Your Current Account Balance is %.2f \n\n", user.balance);
        }
        else {  
            printf("\n\n\t Error Creating Account! Please try again.\n\n");
        }
    }

    else if (opt == 2) {
        system("cls");
        printf("Please Enter your Phone Number: ");
        scanf("%s", phone);
        printf("\nPlease Enter your Password: ");
        scanf("%s", pword);
        strcpy(fileName, phone);
        fp = fopen(strcat(fileName, ".data"), "r");
        if (fp == NULL) {
            printf("\n\n\t Account does not exist! Please try again.\n\n");
            return (0);
        }
        else {
            system("cls");
            printf("\n\n\t Account Found! Please wait while we log you in...\n");
            fread(&user, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(user.password, pword)) {
                // printf("\n\n\t Login Successful! Your Account Balance is %.2f \n\n", user.balance);
                printf("\n\n\t Login Successful! Welcome Dear %s \n\n", user.accNo);
                while(cont == 'y') {
                    system("cls");
                    printf("\n\n\t\t\t Please Select a transaction to perform? ");
                    printf("\n\n1. Balance Inquiry");
                    printf("\n\n2. Deposit an Amount");
                    printf("\n\n3. Cash Withdrawal");
                    printf("\n\n4. Online Transfer");
                    printf("\n\n5. Change Password");
                    printf("\n\nKindly select an operation: \t");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1: 
                            printf("\n\n\t Your Account Balance is $%.2f \n\n", user.balance);
                            break;

                        case 2:
                            printf("\n\n\t Enter the amount you want to deposit: \t");
                            scanf("%f", &deposit);
                            user.balance += deposit;
                            fp = fopen(fileName, "w");
                            fwrite(&user, sizeof(struct user), 1, fp);
                            if(fwrite != NULL) {
                                printf("\n\n\t Transcation Successful! Your new balance is $%.2f \n\n", user.balance);
                                fclose(fp);
                            }
                            else {
                                printf("\n\n\t Error Depositing Amount! Please try again.\n\n");
                            }
                            break;

                        case 3:
                            printf("\n\n\t Enter the amount you want to withdraw: \t");
                            scanf("%f", &deposit);
                            if (deposit > user.balance) {
                                printf("\n\n\t Insufficient Funds! Please try again.\n\n");
                            }
                            else {
                                user.balance -= deposit;
                                fp = fopen(fileName, "w");
                                fwrite(&user, sizeof(struct user), 1, fp);
                                if(fwrite != NULL) {
                                    printf("\n\n\t Transaction Successful! Your new balance is $%.2f \n\n", user.balance);
                                    fclose(fp);
                                }
                                else {
                                    printf("\n\n\t Error Withdrawing Amount! Please try again.\n\n");
                                }
                            }
                            break;
                        
                        case 4:
                            printf("\n\n\t Please enter the beneficiary's acct number: \t");
                            scanf("%s", phone);
                            printf("\n\n\t Enter the amount to transfer: \t");
                            scanf("%f", &deposit);
                            strcpy(fileName, phone);
                            fp = fopen(strcat(fileName, ".data"), "r");
                            if(fp == NULL) {
                                printf("\n\n\t Beneficiary Account does not exist! Please try again.\n\n");
                                break;
                            }
                            else {
                                fread(&user1, sizeof(struct user), 1, fp);
                                fclose(fp);

                                if (deposit > user.balance) {
                                    printf("\n\n\t Insufficient Funds! Please try again.\n\n");
                                }

                                else {
                                    fp = fopen(fileName, "w");
                                    user1.balance += deposit;
                                    fwrite(&user1, sizeof(struct user), 1, fp);
                                    fclose(fp);

                                    if(fwrite != NULL) {
                                        user.balance -= deposit;
                                        printf("\n\n\tTransaction Successful! Your new balance is $%.2f \n\n", user.balance);
                                        strcpy(fileName, user.phoneNo);
                                        fp = fopen(strcat(fileName, ".data"), "w");
                                        fwrite(&user, sizeof(struct user), 1, fp);
                                        fclose(fp);
                                    } 
                                    else {
                                        printf("\n\n\t Error Transferring Amount! Please try again.\n\n");
                                    }
                                }
                                
                            }
                            break;

                        case 5:
                            printf("\n\n\t Enter a new Password: \t");
                            scanf("%s", pword);
                            printf("\n\tConfirm the new password : ");
                            scanf("%s", pword1);

                            if (!strcmp(pword, pword1)) {
                                fp = fopen(fileName, "w");
                                strcpy(user.password, pword);
                                fwrite(&user, sizeof(struct user), 1, fp);
                                if (fwrite != NULL) {
                                    printf("\n\n\tPassword Successfully Changed.\n");
                                }
                                else {
                                    printf("\n\n\tSomething went wrong! Please try again.");
                                }
                            }
                            else{
                            printf("\n----- The passwords do not match Please try again -----");
                            }
                            break;

                        default:
                            printf("\n\n\t Invalid Option Selected! Please try again.\n\n");
                            break;

                    }
                    
                    printf("\n\n Would you like to perform another transaction? (y/n): \t");
                    scanf(" %c", &cont);
                    printf("\n\n");
                }

            } 
            
       }

    }

    else {
        printf("\n\n\t Invalid Option Selected! Please try again.\n\n");
    }

    return (0);
}
