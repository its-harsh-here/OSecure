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
int test(char* result);

int ports[] = {}; // Enter all port numbers

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid Input! Please try again with \"./main <IP Address>\"\n");
        return 1;
    }

    int pc = 0;
    char *ip = argv[1]; 
    char result[SIZE] = "";
    for(int i = 0, t = sizeof(ports) / sizeof(int); i < t; i++)
    {
        char cmd[100];  
        sprintf(cmd, "nmap -p %d %s", ports[i], ip);  
        runcmd(cmd, result, SIZE);  
        if(test(result))
        {
            printf("Port %d is open\n", ports[i]);
            pc++;            
        }
        memset(result, 0, SIZE);
    }
    printf("\nTotal Number of Open Ports: %d\n", pc);
    return 0;
}

void runcmd(char* F, char* output, int s)
{
    FILE* cmd = popen(F, "r");
    if (cmd == NULL) 
    {
        perror("popen failed");
        return;
    }
    char buffer[100];   
    while (fgets(buffer, sizeof(buffer), cmd) != NULL)
        strncat(output, buffer, s - strlen(output) - 1); 
    pclose(cmd);
}

int test(char* result)
{
    if (strstr(result, "open"))
        return 1;
    return 0;
}
