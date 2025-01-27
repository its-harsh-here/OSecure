/*
Summary: This code checks scans the list of ports in "ports.txt" and returns the ports which are open. 
An input of user's IP address by running the following command in your terminal: ./main <IP Address>

Code was written and tested on: 
- Operating System: Ubuntu 24.04.1 LTS                              
- Kernel: Linux 6.8.0-49-generic
- Architecture: x86-64

Tools Used: 
- Nmap
- Terminal

Future Add-ons:
1. Write a menu driven code which gives the user a choice to get a description of the open port and how to close it. 
2. TBD
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void runcmd(char *, char *, int);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid Input!\n Please try again with \"./main <IP Address>\"\n");
        return 1;
    }
    char *ip = argv[0]; // User IP
    char result[SIZE];
    printf("Checking system security...\n\n");
    int c = 0, i = 0;
    system("w");
    runcmd("nmap -p 21", argv[0], result, SIZE);
}

void runcmd(char* F, char* output, int s)
{
    FILE* cmd = popen(F, "r");
    char buffer[100];   
    strcat(output, buffer);
    pclose(cmd);
}

int open(char* result)
{
    if(strstr(result, open) == 0))
        return 0;
    return 1;
}
