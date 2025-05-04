#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


char accountsNum[3][12] = {"234-769-857", "127-824-316", "123-456-789", };
char accountsName[3][50] = {"Aidrhick Curacha", "Ian Agustin", "Andrei Delos Santos"};
char accountsPin[3][5] = {"1234", "4567", "7891"};

float accountsBalance[3] = {20000, 5000, 15000};
float currBalance;

char inputNum[12];
char inputName[50];
char inputPin[5];

int currId;
int isRunning = 1;
int validAccNum = 1;
int validPin = 1;
int validName = 1;

// prototypes
float deposit(float amount);
float withdraw(float amount);
void displayErrorMessage (char errorMessage[50]);


int main()
{
    displayTitleScreen();
    DisplayLoginScreen();
    DisplayHomeScreen();

    return 0;
}

void displayTitleScreen() {

    void printA() {
        printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\033[1;31m");
        printf("\n\n\n\t\t\t\t\t      _       \n");
        printf("\t\t\t\t\t     / \\      \n");
        printf("\t\t\t\t\t    / _ \\     \n");
        printf("\t\t\t\t\t   / ___ \\    \n");
        printf("\t\t\t\t\t _/ /   \\ \\_  \n");
        printf("\t\t\t\t\t|____| |____| \n\n\n");
        printf("\033[0m");
        printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\n\n\t\t\t\t\t Please Insert Your Card (Press Enter)");
    }
    void printT() {
        printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\033[1;32m");
        printf("\n\n\n\t\t\t\t\t             _________  \n");
        printf("\t\t\t\t\t            |  _   _  | \n");
        printf("\t\t\t\t\t            |_/ | | \\_| \n");
        printf("\t\t\t\t\t                | |     \n");
        printf("\t\t\t\t\t               _| |_    \n");
        printf("\t\t\t\t\t              |_____|   \n\n\n");
        printf("\033[0m");
        printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\n\n\t\t\t\t\t Please Insert Your Card (Press Enter)");
    }
    void printM() {
        printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\033[1;33m");
        printf("\n\n\n\t\t\t\t\t                       ____    ____  \n");
        printf("\t\t\t\t\t                      |_   \\  /   _| \n");
        printf("\t\t\t\t\t                        |   \\/   |   \n");
        printf("\t\t\t\t\t                        | |\\  /| |   \n");
        printf("\t\t\t\t\t                        | |_\\/_| |_  \n");
        printf("\t\t\t\t\t                      |_____||_____| \n\n\n");
        printf("\033[0m");
        printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\n\n\t\t\t\t\t Please Insert Your Card (Press Enter)");
    }
    void printATM() {
        printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\033[1;34m");
        printf("\n\n\n\t\t\t\t\t      _     _________  ____    ____  \n");
        printf("\t\t\t\t\t     / \\   |  _   _  ||_   \\  /   _| \n");
        printf("\t\t\t\t\t    / _ \\  |_/ | | \\_|  |   \\/   |   \n");
        printf("\t\t\t\t\t   / ___ \\     | |      | |\\  /| |   \n");
        printf("\t\t\t\t\t _/ /   \\ \\_  _| |_    _| |_\\/_| |_  \n");
        printf("\t\t\t\t\t|____| |____||_____|  |_____||_____| \n\n\n");
        printf("\033[0m");
         printf("\033[1;47m");
        printf("\t\t                                                                                          ");
        printf("\033[0m");
        printf("\n\n\t\t\t\t\t Please Insert Your Card (Press Enter)");
    }

    while (1) {
        if (_kbhit()) {
            char ch = getch();
            if (ch == '\r') {
                clearScreen();
                break;
            } else {
                continue;
            }

        }
        printA();
        Sleep(500);
        clearScreen();
        printT();
        Sleep(500);
        clearScreen();
        printM();
        Sleep(500);
        clearScreen();
        printATM();
        Sleep(500);
        clearScreen();
    }




}

void DisplayLoginScreen() {
    clearScreen();
    int answer;
    char strVal[1];

    printf("\nPlease choose to proceed\n\n");
    printf("<1>    Login\n\n");
    printf("<2>    Exit\n\n\n");
    printf("Input: ");

    scanf("%s", &strVal);

    answer = atoi(strVal);

    switch (answer) {
        case 1:
            clearScreen();
            int c;
            while ((c = getchar()) != '\n');
            DisplayInputScreen();
            break;
        case 2:
            printf("\n\t\tExiting the program. Thank you\n");
            Sleep(1000);
            clearScreen();
            main();
            break;
        case 0:
            displayErrorMessage("Please Enter Valid Input");
            DisplayLoginScreen();
            break;
    }
}

void DisplayInputScreen() {
    AccNumValidation();
    printf("\n");
    AccNameValidation();
    printf("\n");
    PasswordValidation();

    for (int i = 0; i < 3; i++) {
        if (strcmp(inputNum, accountsNum[i]) == 0 && strcmp(inputName, accountsName[i]) == 0 && strcmp(inputPin, accountsPin[i]) == 0) {
            currBalance = accountsBalance[i];
        }
    }

}

void DisplayHomeScreen() {
    int userInput;

    printf("\nChoose an option: \n");
    printf("<1> Deposit\n");
    printf("<2> Withdraw\n");
    printf("<3> Check Balance\n");
    printf("<4> Exit\n");
    scanf("%d", &userInput);

    switch (userInput) {
    case 1:
        clearScreen();
        DisplayDepositScreen();
        break;
    case 2:
        clearScreen();
        DisplayWithdrawScreen();
        break;
    case 3:
        clearScreen();
        DisplayCheckBalScreen();
        break;
    case 4:
        clearScreen();
        printf("Exiting the program. Thank you\n");
        Sleep(1000);
        clearScreen();
        main();
        break;
    default:
        printf("Invalid choice. Please enter a valid option.\n");
    }
}

void DisplayDepositScreen() {

    float amount;
    char strVal[50];
    int running = 1;

    while(running) {
        printf("Enter amount to Deposit: ");
        scanf("%s", &strVal);

        amount = atof(strVal);

        if (amount < 0) {
            displayErrorMessage("Invalid Input. Try Again");
            continue;
        } else if (amount == 0) {
            displayErrorMessage("Invalid Input. Try Again");
            continue;
        }
        else {
            currBalance = deposit(amount);
            running = 0;
        }
    }

    clearScreen();
    printf("The amount you withdrawed is PHP%.2f\nYour new balance is now PHP%.2f", amount, currBalance);
    Sleep(3000);
    clearScreen();
    DisplayHomeScreen();
}

void DisplayWithdrawScreen() {
    float amount;
    char strVal[50];
    int running = 1;


    while(running) {
        printf("Enter amount to withdraw: ");
        scanf("%s", &strVal);

        amount = atof(strVal);

        if (amount < 0) {
            displayErrorMessage("Invalid Input. Try Again");
            continue;
        } else if (amount > currBalance) {
            displayErrorMessage("Insufficient Funds. Try Again");
            continue;
        } else if (amount == 0) {
            displayErrorMessage("Invalid Input. Try Again");
            continue;
        }
        else {
            currBalance = withdraw(amount);
            running = 0;
        }
    }

    clearScreen();
    printf("The amount you withdrawed is PHP%.2f\nYour new balance is now PHP%.2f", amount, currBalance);
    Sleep(3000);
    clearScreen();
    DisplayHomeScreen();
}


void DisplayCheckBalScreen() {
    printf("Your current balance is PHP%.2f", currBalance);
    Sleep(3000);
    clearScreen();
    DisplayHomeScreen();
}


float deposit(float amount) {
    return (currBalance + amount);
}

float withdraw(float amount) {
    return (currBalance - amount);
}

void clearLine() {
    printf("\033[2K");
}

void clearScreen() {
    system("cls");
}

void displayErrorMessage (char errorMessage[50]) {
    printf("\033[F\r");
    clearLine();
    printf("\r%s", errorMessage);
    Sleep(1000);
    clearLine();
    printf("\033[F\r");

}

void AccNumValidation() {
    do {
        validAccNum = 0;
        puts("\rEnter your account number (xxx-xxx-xxx): ");
        gets(inputNum);

        for (int i = 0; i < 3; i++) {
            if (strcmp(inputNum, accountsNum[i]) == 0) {
                validAccNum = 1;
                currId = i;
                break;
            }
        }

        if (!validAccNum) {
            displayErrorMessage("Account Number Does Not Exist.");
        }

    } while (!validAccNum);

}

void PasswordValidation() {
    do {
        validPin = 0;
        puts("\rEnter your 4-digit PIN number: ");
        gets(inputPin);

        for (int i = 0; i < 3; i++) {
            if (strcmp(inputPin, accountsPin[currId]) == 0) {
                validPin = 1;
                break;
            }
        }
        if (!validPin) {
            displayErrorMessage("Invalid PIN. Please try again.");
        }
    } while (!validPin);
}

void AccNameValidation() {
    do {
        validName = 0;
        puts("\rEnter your name: ");
        gets(inputName);

        for (int i = 0; i < 3; i++) {
            if (strcmp(inputName, accountsName[currId]) == 0) {
                validName = 1;
                break;
            }
        }

        if (!validName) {
            displayErrorMessage("Invalid NAME. Please try again.");
        }

    } while (!validName);
}





