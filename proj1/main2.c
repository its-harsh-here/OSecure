/*

Summary: This code would do basic system checkup to see if system is secure or not. An input of user's IP address by 
running the following command in your terminal: ./main <IP Address>


Code was written and tested on: 
- Operating System: Ubuntu 24.04.1 LTS                              
- Kernel: Linux 6.8.0-49-generic
- Architecture: x86-64


This code checks the following loopholes: 

0. Checks if unauthorized User is logged in using the command "w"
    "w" returns information about users that are currently logged in so if there is another user logged in, we would get to 
    know that the system is insure as they would be logged in by a different IP address. We use system(w) to run and print
    the result of w in the terminal.

1. Checks brodcast IP address using the command ifconfig
    ifconfig returns the inet, netmask and broadcast IP address. This code checks for Broadcast IP address by using the 
    strtok function to break the result into different lines, and strstr to check if IP address is there in the line which
    has broadcast given.

2. Checks if password less sudo is enabled which
    "sudo" grants a user temporary privileges which can be used to carry out system administrative duties. Thus a device's
    security would be heavily compromised if password less sudo is enabled. We used to command "sudo -n true" to check if
    sudo requires a password or not. The command return "sudo: a password is required" if password is required, and exits
    if passwordless sudo is enabled. 

3. Checks if SSH root login is enabled
    SSH(Secure Shell) is a protocol with which one can login to a device remotely. If root login is enabled, one can login
    to the device remotely without the need of a password, so the device's security is heavily compromised. 
    The command used is "grep "PermitRootLogin" /etc/ssh/sshd_config" which returns 
    1. PermitRootLogin yes: Root login is enabled.
    2. PermitRootLogin no: Root login is disabled.
    3. PermitRootLogin prohibit-password: Root login is allowed only with key-based authentication.   


Future Add-ons:

1. Check audit log of logged users for suspicious activities
2. Check file permissions to see who all have permissions
3. Check Firewall Configuration to find any security flaws
4. Automate Monitoring and Reporting

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void runcmd(char *, char *, int);
int uip(char*, char*);
int pswsudo(char*);
int rootlogin(char*);


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid Input!\n");
        return 1;
    }
    char *ip = argv[0]; // User IP
    char rone[SIZE], rtwo[SIZE], rthree[SIZE]; // Result of 1st, 2nd and 3rd test cases   
    printf("Checking system security...\n\n");
    int c = 0, i = 0;
    printf("\n\nChecking for active users: \n\n");

    system("w");
    printf("\n\nChecking for Open Ports Using nmap:\n\n");
    char s1[20] = "nmap ";
    strcat(s1, argv[1]);
    system(s1);

    printf("\n\n");
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