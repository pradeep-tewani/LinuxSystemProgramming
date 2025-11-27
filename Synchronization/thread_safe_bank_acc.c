#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Define the BankAccount structure with a mutex
typedef struct 
{
    double balance;
    pthread_mutex_t mutex;
} BankAccount;

// Initialize the bank account
void init_account(BankAccount *account, double initial_balance) 
{
    account->balance = initial_balance;
    // TODO 1: Initialize the mutex
}

// Function to deposit money
void deposit(BankAccount *account, double amount) 
{
    // TODO 2: Lock & Unlock the mutex to ensure exclusive access
    account->balance += amount;
    printf("Deposit: +$%.2f. New balance: $%.2f\n", amount, account->balance);
    // Unlock the mutex
}

// Function to withdraw money
int withdraw(BankAccount *account, double amount) 
{
    int success = 0;
    // TODO 3: Lock & Unlock the mutex to ensure consistency
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdraw: -$%.2f. New balance: $%.2f\n", amount, account->balance);
        success = 1;
    } else {
        printf("Withdraw: -$%.2f. Insufficient funds. Balance: $%.2f\n", amount, account->balance);
    }
    // Unlock the mutex
    return success;
}

// Thread function for concurrent transactions
void* perform_transactions(void* arg) 
{
    BankAccount* account = (BankAccount*)arg;
    for (int i = 0; i < 5; i++) {
        deposit(account, 100.0);
        withdraw(account, 50.0);
    }
    return NULL;
}

int main() 
{
    BankAccount my_account;
    init_account(&my_account, 1000.0);

    pthread_t thread1, thread2;

    printf("Initial balance: $%.2f\n\n", my_account.balance);

    // Create two threads to perform transactions
    pthread_create(&thread1, NULL, perform_transactions, &my_account);
    pthread_create(&thread2, NULL, perform_transactions, &my_account);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nFinal balance: $%.2f\n", my_account.balance);
    
	//TODO 4: Destroy the Mutex

    return 0;
}
