#include <stdio.h>

struct Bank
{
    int accountNo;
    char name[50];
    long long mobile;
    int age;
    float balance;
    int pin;
};

int main()
{
    struct Bank customer[200];

    int choice;
    int count = 0;

    while (1)
    {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Search Account\n");
        printf("3. Display All Accounts\n");
        printf("4. Update Account\n");
        printf("5. Delete Account\n");
        printf("6. Interest Calculation\n");
        printf("7. Login\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            // ================= CREATE ACCOUNT =================
            case 1:
            {
                if (count >= 200)
                {
                    printf("Bank account limit reached!\n");
                    break;
                }

                printf("\n--- Create Account ---\n");

                printf("Enter Account Number: ");
                scanf("%d", &customer[count].accountNo);

                printf("Enter Name: ");
                scanf("%49s", customer[count].name);

                printf("Enter Mobile Number: ");
                scanf("%lld", &customer[count].mobile);

                printf("Enter Age: ");
                scanf("%d", &customer[count].age);

                printf("Enter Initial Balance: ");
                scanf("%f", &customer[count].balance);

                printf("Enter PIN: ");
                scanf("%d", &customer[count].pin);

                count++;

                printf("Account Created Successfully!\n");

                break;
            }

            // ================= SEARCH ACCOUNT =================
            case 2:
            {
                int accNo;
                int found = 0;

                printf("Enter Account Number: ");
                scanf("%d", &accNo);

                for (int i = 0; i < count; i++)
                {
                    if (customer[i].accountNo == accNo)
                    {
                        printf("\n----- Account Details -----\n");
                        printf("Account Number : %d\n",
                               customer[i].accountNo);
                        printf("Name           : %s\n",
                               customer[i].name);
                        printf("Mobile Number  : %lld\n",
                               customer[i].mobile);
                        printf("Age            : %d\n",
                               customer[i].age);
                        printf("Balance        : %.2f\n",
                               customer[i].balance);

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account Not Found!\n");
                }

                break;
            }

            // ================= DISPLAY ALL =================
            case 3:
            {
                if (count == 0)
                {
                    printf("No Accounts Available!\n");
                }
                else
                {
                    printf("\n========== ALL ACCOUNTS ==========\n");

                    for (int i = 0; i < count; i++)
                    {
                        printf("\nCustomer %d\n", i + 1);

                        printf("Account Number : %d\n",
                               customer[i].accountNo);

                        printf("Name           : %s\n",
                               customer[i].name);

                        printf("Mobile Number  : %lld\n",
                               customer[i].mobile);

                        printf("Age            : %d\n",
                               customer[i].age);

                        printf("Balance        : %.2f\n",
                               customer[i].balance);
                    }
                }

                break;
            }

            // ================= UPDATE ACCOUNT =================
            case 4:
            {
                int accNo;
                int found = 0;

                printf("Enter Account Number to Update: ");
                scanf("%d", &accNo);

                for (int i = 0; i < count; i++)
                {
                    if (customer[i].accountNo == accNo)
                    {
                        found = 1;

                        printf("\n--- Enter New Details ---\n");

                        printf("Enter New Name: ");
                        scanf("%49s", customer[i].name);

                        printf("Enter New Mobile Number: ");
                        scanf("%lld", &customer[i].mobile);

                        printf("Enter New Age: ");
                        scanf("%d", &customer[i].age);

                        printf("Account Updated Successfully!\n");

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account Not Found!\n");
                }

                break;
            }

            // ================= DELETE ACCOUNT =================
            case 5:
            {
                int accNo;
                int found = 0;

                printf("Enter Account Number to Delete: ");
                scanf("%d", &accNo);

                for (int i = 0; i < count; i++)
                {
                    if (customer[i].accountNo == accNo)
                    {
                        found = 1;

                        for (int j = i; j < count - 1; j++)
                        {
                            customer[j] = customer[j + 1];
                        }

                        count--;

                        printf("Account Deleted Successfully!\n");

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account Not Found!\n");
                }

                break;
            }

            // ================= INTEREST =================
            case 6:
            {
                int accNo;
                int found = 0;
                float rate;
                float interest;

                printf("Enter Account Number: ");
                scanf("%d", &accNo);

                printf("Enter Interest Rate (%%): ");
                scanf("%f", &rate);

                for (int i = 0; i < count; i++)
                {
                    if (customer[i].accountNo == accNo)
                    {
                        interest =
                            customer[i].balance * rate / 100;

                        customer[i].balance += interest;

                        printf("\nInterest Added Successfully!\n");
                        printf("Interest Amount : %.2f\n",
                               interest);

                        printf("New Balance     : %.2f\n",
                               customer[i].balance);

                        found = 1;

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account Not Found!\n");
                }

                break;
            }

            // ================= LOGIN =================
            case 7:
            {
                int accNo;
                int pin;
                int found = 0;
                int loggedInIndex = -1;

                printf("\n========== LOGIN ==========\n");

                printf("Enter Account Number: ");
                scanf("%d", &accNo);

                for (int i = 0; i < count; i++)
                {
                    if (customer[i].accountNo == accNo)
                    {
                        found = 1;

                        printf("Enter PIN: ");
                        scanf("%d", &pin);

                        if (customer[i].pin == pin)
                        {
                            loggedInIndex = i;

                            printf("\nLogin Successful!\n");
                            printf("Welcome %s!\n",
                                   customer[i].name);

                            // ================= CUSTOMER MENU =================
                            while (1)
                            {
                                int customerChoice;

                                printf("\n===== CUSTOMER MENU =====\n");
                                printf("1. Deposit Money\n");
                                printf("2. Withdraw Money\n");
                                printf("3. Transfer Money\n");
                                printf("4. Check Balance\n");
                                printf("5. Account Details\n");
                                printf("6. Logout\n");

                                printf("Enter your choice: ");
                                scanf("%d", &customerChoice);

                                switch (customerChoice)
                                {
                                    // -------- DEPOSIT --------
                                    case 1:
                                    {
                                        float amount;

                                        printf("Enter Deposit Amount: ");
                                        scanf("%f", &amount);

                                        if (amount > 0)
                                        {
                                            customer[loggedInIndex].balance
                                                += amount;

                                            printf("Deposit Successful!\n");

                                            printf("Current Balance: %.2f\n",
                                                   customer[loggedInIndex].balance);
                                        }
                                        else
                                        {
                                            printf("Invalid Amount!\n");
                                        }

                                        break;
                                    }

                                    // -------- WITHDRAW --------
                                    case 2:
                                    {
                                        float amount;

                                        printf("Enter Withdrawal Amount: ");
                                        scanf("%f", &amount);

                                        if (amount <= 0)
                                        {
                                            printf("Invalid Amount!\n");
                                        }
                                        else if (amount >
                                                 customer[loggedInIndex].balance)
                                        {
                                            printf("Insufficient Balance!\n");
                                        }
                                        else
                                        {
                                            customer[loggedInIndex].balance
                                                -= amount;

                                            printf("Withdrawal Successful!\n");

                                            printf("Remaining Balance: %.2f\n",
                                                   customer[loggedInIndex].balance);
                                        }

                                        break;
                                    }

                                    // -------- TRANSFER --------
                                    case 3:
                                    {
                                        int toAcc;
                                        int receiverIndex = -1;
                                        float amount;

                                        printf("Enter Receiver Account Number: ");
                                        scanf("%d", &toAcc);

                                        if (toAcc ==
                                            customer[loggedInIndex].accountNo)
                                        {
                                            printf("Cannot transfer to your own account!\n");
                                            break;
                                        }

                                        for (int j = 0; j < count; j++)
                                        {
                                            if (customer[j].accountNo == toAcc)
                                            {
                                                receiverIndex = j;
                                                break;
                                            }
                                        }

                                        if (receiverIndex == -1)
                                        {
                                            printf("Receiver Account Not Found!\n");
                                        }
                                        else
                                        {
                                            printf("Enter Transfer Amount: ");
                                            scanf("%f", &amount);

                                            if (amount <= 0)
                                            {
                                                printf("Invalid Amount!\n");
                                            }
                                            else if (amount >
                                                     customer[loggedInIndex].balance)
                                            {
                                                printf("Insufficient Balance!\n");
                                            }
                                            else
                                            {
                                                customer[loggedInIndex].balance
                                                    -= amount;

                                                customer[receiverIndex].balance
                                                    += amount;

                                                printf("Transfer Successful!\n");

                                                printf("Remaining Balance: %.2f\n",
                                                       customer[loggedInIndex].balance);
                                            }
                                        }

                                        break;
                                    }

                                    // -------- CHECK BALANCE --------
                                    case 4:
                                    {
                                        printf("\nCurrent Balance: %.2f\n",
                                               customer[loggedInIndex].balance);

                                        break;
                                    }

                                    // -------- ACCOUNT DETAILS --------
                                    case 5:
                                    {
                                        printf("\n----- ACCOUNT DETAILS -----\n");

                                        printf("Account Number : %d\n",
                                               customer[loggedInIndex].accountNo);

                                        printf("Name           : %s\n",
                                               customer[loggedInIndex].name);

                                        printf("Mobile Number  : %lld\n",
                                               customer[loggedInIndex].mobile);

                                        printf("Age            : %d\n",
                                               customer[loggedInIndex].age);

                                        printf("Balance        : %.2f\n",
                                               customer[loggedInIndex].balance);

                                        break;
                                    }

                                    // -------- LOGOUT --------
                                    case 6:
                                    {
                                        printf("Logged Out Successfully!\n");
                                        break;
                                    }

                                    default:
                                    {
                                        printf("Invalid Choice!\n");
                                    }
                                }

                                if (customerChoice == 6)
                                {
                                    break;
                                }
                            }
                        }
                        else
                        {
                            printf("Incorrect PIN!\n");
                        }

                        break;
                    }
                }

                if (found == 0)
                {
                    printf("Account Not Found!\n");
                }

                break;
            }

            // ================= EXIT =================
            case 8:
            {
                printf("Thank You!\n");
                return 0;
            }

            default:
            {
                printf("Invalid Choice!\n");
            }
        }
    }

    return 0;
}