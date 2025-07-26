/*
Summary: This code checks scans the list of ports in "ports.txt" and returns the ports which are open. 
An input of user's IP address by running the following command in your terminal: ./main <IP Address>

Code was written and tested on: 
- Operating System: Ubuntu 24.04.1 LTS                              
- Kernel: Linux 6.8.0-49-generic
- Architecture: x86-64

Tools Used: 
- Nmap
- Terminal(gcc)

Future Add-ons:
1. Write a menu driven code which gives the user a choice to get a list of the open port with a certain vulnerable rating(out of 5). 
2. Only print out open ports when executed for the first time.
3. Write another menu driven code to fetch data for each port number entered(from port.txt). Give description about the port; why is it vulnerable and how to close it!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void runcmd(char *, char *, int);
int test(char* result);

struct port 
{
    int num;
    char name[10];
    char protocol[20];
};

struct port p[] = {
                    {7, "Echo", "TCP, UDP"}, 
                    {20, "n", "m"}, 
                    {21, "n", "m"},
                    {22, "n", "m"},
                    {23, "n", "m"},
                    {25, "n", "m"},
                    {53, "n", "m"},
                    {69, "n", "m"},
                    {80, "n", "m"}, 
                    {88, "n", "m"}, 
                    {102, "n", "m"}, 
                    {110, "n", "m"}, 
                    {135, "n", "m"}, 
                    {137, "n", "m"}, 
                    {139, "n", "m"}, 
                    {143, "n", "m"}, 
                    {381, "n", "m"}, 
                    {383, "n", "m"}, 
                    {443, "n", "m"}, 
                    {464, "n", "m"}, 
                    {465, "n", "m"}, 
                    {587, "n", "m"}, 
                    {593, "n", "m"}, 
                    {636, "n", "m"}, 
                    {691, "n", "m"}, 
                    {902, "n", "m"}, 
                    {989, "n", "m"}, 
                    {990, "n", "m"}, 
                    {993, "n", "m"}, 
                    {995, "n", "m"}, 
                    {1025, "n", "m"}, 
                    {1194, "n", "m"}, 
                    {1337, "n", "m"}, 
                    {1589, "n", "m"}, 
                    {1725, "n", "m"}, 
                    {2082, "n", "m"}, 
                    {2083, "n", "m"}, 
                    {2483, "n", "m"}, 
                    {2484, "n", "m"}, 
                    {2967, "n", "m"}, 
                    {3074, "n", "m"}, 
                    {3306, "n", "m"}, 
                    {3724, "n", "m"}, 
                    {4664, "n", "m"}, 
                    {5432, "n", "m"}, 
                    {5900, "n", "m"}, 
                    {6665, "n", "m"}, 
                    {6666, "n", "m"}, 
                    {6667, "n", "m"}, 
                    {6668, "n", "m"}, 
                    {6669, "n", "m"}, 
                    {6881, "n", "m"}, 
                    {6999, "n", "m"}, 
                    {6970, "n", "m"}, 
                    {8086, "n", "m"}, 
                    {8087, "n", "m"}, 
                    {8222, "n", "m"}, 
                    {9100, "n", "m"}, 
                    {10000, "n", "m"}, 
                    {12345, "n", "m"}, 
                    {27374, "n", "m"}, 
                    {31337, "n", "m"}
                }; 


int main(int argc, char *argv[])
{
    struct port op[50];
    if (argc != 2)
    {
        printf("Invalid Input! Please try again with \"./main <IP Address>\"\n");
        return 1;
    }

    int pc = 0;
    char *ip = argv[1]; 
    char result[SIZE] = "";
    printf("\n\t     ***Scanning for Open Ports***\n\n");
    printf("Port Number | Service Name | Transport Protocol | Status\n");
    for(int i = 0, t = sizeof(p) / sizeof(struct port); i < t; i++)
    {
        char cmd[100];  
        sprintf(cmd, "nmap -p %d %s", p[i].num, ip);  
        runcmd(cmd, result, SIZE);  
        if(test(result))
        {
            op[pc] = p[i];
            printf("%11d | %12s | %18s | open\n", p[i].num, p[i].name, p[i].protocol);
            pc++;            
        }
        else
            printf("%11d | %12s | %18s | close\n", p[i].num, p[i].name, p[i].protocol);

        (result, 0, SIZE);
    }
    printf("\nTotal Number of Open Ports: %d\n\n", pc);
    int f;
    do
    {
        printf("Enter:\n\t 1. to get a list of all open ports\n\t 2. to quit\n\n >>>>> ");
        scanf("%d", &f);
    } while (f < 1 || f > 2);
    if (f == 1 && pc > 0)
    {
        printf("\nPort Number | Service Name | Transport Protocol | Status\n");
        for(int i = 0, t = pc; i < t; i++)
            printf("%11d | %12s | %18s | open\n", op[i].num, op[i].name, op[i].protocol);
    }
    else if (f == 1)
        printf("\nNo Open Ports!\n");
    else   
        printf("\nQuiting!\n");
    printf("\n");
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
