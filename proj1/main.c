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
    char rone[SIZE], rtwo[SIZE], rthree[SIZE]; // Result of 1st, 2nd and 3rd test cases   
    printf("Checking system security...\n\n");
    int c = 0, i = 0;
    system("w");
    runcmd("hostname --ip-address",rone, SIZE);
    runcmd("sudo -n true", rtwo, SIZE);
    runcmd("grep 'PermitRootLogin' /etc/ssh/sshd_config",rthree, SIZE);
    printf("\n\tTest Cases: ");
    if (uip(ip,rone))
    {
        printf("\n\t%d Unauthorized IP address logged in!\n", ++c);
        i++;
    }
    else 
        printf("\n\t%d Authorized IP address logged in!\n", ++c);


    if (pswsudo(rtwo) == 0)
    {
        printf("\t%d Passwordless sudo is enabled\n", ++c);
        i++;
    }
    else
        printf("\t%d Passwordless sudo is disabled!\n", ++c);
    if (rootlogin(rthree))
    {
        printf("\t%d SSH Root Login is enabled!\n\n", ++c);
        i++;
    }
    else
        printf("\t%d SSH Root Login is disabled!\n\n", ++c);
    printf("Result: ");
    i ? printf("System is Insecure with %d vulnerabilities!\n", i) : printf("System is Secured!\n");
    return 0;
}

void runcmd(char* F, char* output, int s)
{
    FILE* cmd = popen(F, "r");
    char buffer[100];   
    strcat(output, buffer);
    pclose(cmd);
}

int uip(char* ip, char* result)
{
    if(strstr(result, ip) == 0)
        return 0;
    return 1;
}

int pswsudo(char* result)
{
    return strcmp(result, "sudo: a password is required");
}

int rootlogin(char* result)
{
    int r = 0;
    if (strstr(result, "prohibit-password"))
        r++;
    return r;
}
