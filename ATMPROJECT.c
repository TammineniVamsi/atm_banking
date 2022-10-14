#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

int main(){
   int pin=1234,option,enteredpin,count=0,amount=1;
   float balance=10000;
   int continueTranscation=1;

    time_t now;
    time(&now);
    printf("\t\t\t\t\t    %s",ctime(&now));

    printf("\t\t\t\t        -------WELCOME TO SBL BANK-------");

    while(pin != enteredpin){
        printf("\n please enter your pin:");
        scanf("%d",&enteredpin);
        if(enteredpin != pin){ 
            Beep(450,500);   //(frequency,time(millisec))
            printf("\n Invalid pin entered");
        }
        count++;
        if(count==3 && pin != enteredpin){
            exit(0);
        }
    }
    
    while(continueTranscation !=0){
        printf("\n\t\t\t\t       -------Available Transactions-------");

    printf("\n\n\t 1.Withdrawl");
    printf("\n\t 2.Deposit");
    printf("\n\t 3.Check Balance");
    printf("\n\n\t Please select the option:");
    scanf("%d",&option);
    switch(option){
        case 1:
        while(amount % 500!=0){
            printf("\n\n\t Enter the amount:");
            scanf("%d",&amount);
            if(amount % 500 != 0)
                printf("\n\n Amount should be multiple of 500");
             }
            if( balance < amount){
                printf("\n\t Sorry insuffient balance");
                amount=1;   
                break;
            }
            else{
                balance -= amount;
                printf("\n\n\t You have withdrawn Rs.%d.Your balance is %.2f",amount,balance);
                amount=1;
                break;
            }
            case 2: 
            printf("\n\t\t Please enter the amount:");
            scanf("%d",&amount);
            balance+=amount;
            printf("\n\t\t You have deposited Rs.%d.Your new balance is:%.2f",amount,balance);
            printf("\n\t\t                            --------Thank YOU--------");
            amount=1;
            break;
            
            case 3: 
            printf("Available balance: %.2f",balance);
            break;

            default:
            Beep(600,500);
            printf("\n\t Invalid option selected");
        }   
        printf("\n\t\t Do you need any other transactions? press \t 1.YES\t 0.NO \t");
        scanf("%d",&continueTranscation);
            
    }
    return 0;
        
    }

