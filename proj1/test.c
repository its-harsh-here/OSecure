#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000


void runcmd(char *, char *, int);
// int uip(char*, char*);
int pswsudo(char*);
int rootlogin(char*);


int main(int argc, char *argv[])
{
    char *ip = argv[0]; // User IP
    char rone[SIZE], rtwo[SIZE], rthree[SIZE]; // Result of 1st, 2nd and 3rd test cases   
    printf("Checking system security...\n\n");
    int c = 0, i = 0;
    system("w");
    runcmd("sudo -n true", rtwo, SIZE);
    runcmd("grep 'PermitRootLogin' /etc/ssh/sshd_config",rthree, SIZE);
    printf("\nTest Cases: \n");
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
    char *line = strtok((char *) result, "\n");
    while(line)
    {
        if(strstr(line, "broadcast") && strstr(line, ip) == NULL)
            return 1;
        strtok(NULL, "\n");
    }
    return 0;
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