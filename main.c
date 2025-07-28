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

void pline(int n);
void runcmd(char *, char *, int);
int test(char* result);

struct port 
{
    int num;
    char name[30];
    char protocol[20];
};

struct port p[] = {
                    {7, "Echo", "TCP, UDP"}, 
                    {20, "FTP-Data", "TCP"}, 
                    {21, "FTP", "TCP"},
                    {22, "SSH", "TCP"},
                    {23, "Telnet", "TCP"},
                    {25, "SMTP", "TCP"},
                    {53, "DNS", "TCP, UDP"},
                    {69, "TFTP", "UDP"},
                    {80, "HTTP", "TCP"}, 
                    {88, "Kerberos", "TCP, UDP"}, 
                    {102, "ISO-TSAP / Siemens S7", "TCP"}, 
                    {110, "POP3", "TCP"}, 
                    {135, "Microsoft RPC Endpoint Mapper", "TCP"}, 
                    {137, "NetBIOS Name Service", "UDP"}, 
                    {139, "NetBIOS Session Service", "TCP"}, 
                    {143, "IMAP", "TCP"}, 
                    {381, "HP OpenView", "TCP"}, 
                    {383, "HP Data Protector", "TCP"}, 
                    {443, "HTTPS", "TCP"}, 
                    {464, "Kerberos Change/Set Password", "TCP, UDP"}, 
                    {465, "SMTPS", "TCP"}, 
                    {587, "SMTP Submission", "TCP"}, 
                    {593, "Microsoft RPC over HTTP", "TCP"}, 
                    {636, "LDAPS", "TCP"}, 
                    {691, "MS Exchange Routing", "TCP"}, 
                    {902, "VMware Server / ESXi", "TCP"}, 
                    {989, "FTPS-Data", "TCP"}, 
                    {990, "FTPS", "TCP"}, 
                    {993, "IMAPS", "TCP"}, 
                    {995, "POP3S", "TCP"}, 
                    {1025, "Microsoft RPC / Ephemeral", "TCP"}, 
                    {1194, "OpenVPN", "UDP, TCP"}, 
                    {1337, "WASTE / Backdoor", "TCP"}, 
                    {1589, "Cisco VQP", "TCP"}, 
                    {1725, "Valve RC / Steam", "TCP"}, 
                    {2082, "cPanel", "TCP"}, 
                    {2083, "cPanel (SSL)", "TCP"}, 
                    {2483, "Oracle DB Service", "TCP"}, 
                    {2484, "Oracle DB Service (SSL)", "TCP"}, 
                    {2967, "Symantec AV", "TCP"}, 
                    {3074, "Xbox Live / Game Traffic", "TCP, UDP"}, 
                    {3306, "MySQL", "TCP"}, 
                    {3724, "World of Warcraft", "TCP"}, 
                    {4664, "Google Desktop Search", "TCP"}, 
                    {5432, "PostgreSQL", "TCP"}, 
                    {5900, "VNC", "TCP"}, 
                    {6665, "IRC", "TCP"}, 
                    {6666, "IRC", "TCP"}, 
                    {6667, "IRC", "TCP"}, 
                    {6668, "IRC", "TCP"}, 
                    {6669, "IRC", "TCP"}, 
                    {6881, "BitTorrent", "TCP"}, 
                    {6999, "BitTorrent", "TCP"}, 
                    {6970, "RealAudio (RTP)", "UDP"}, 
                    {8086, "InfluxDB / HTTP Alt", "TCP"}, 
                    {8087, "HTTP Alt", "TCP"}, 
                    {8222, "VMware Server Console (HTTP)", "TCP"}, 
                    {9100, "HP JetDirect (RAW Printing)", "TCP"}, 
                    {10000, "Webmin", "TCP"}, 
                    {12345, "NetBus (Trojan)", "TCP"}, 
                    {27374, "Sub7 (Trojan)", "TCP"}, 
                    {31337, "Back Orifice (Trojan)", "TCP"}

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
    printf("\n\t\t\t     ***Scanning for Open Ports***\n");
    char s_n[] = "Service Name", t_p[] = "Transport Protocol";
    for(int i = 0; i < 80; i++)
        printf("_");
    printf("\n");
    printf("| Port Number | %30s | %20s | Status \t|\n", s_n, t_p);
    pline(80);
    for(int i = 0, t = sizeof(p) / sizeof(struct port); i < t; i++)
    {
        char cmd[100];  
        sprintf(cmd, "nmap -p %d %s", p[i].num, ip);  
        runcmd(cmd, result, SIZE);  
        if(test(result))
        {
            op[pc] = p[i];
            printf("|%12d | %30s | %20s | open\t|\n", p[i].num, p[i].name, p[i].protocol);
            pc++;            
        }
        else
            printf("|%12d | %30s | %20s | close\t|\n", p[i].num, p[i].name, p[i].protocol);

        (result, 0, SIZE);
    }
    pline(80);
    printf("\nTotal Number of Open Ports: %d\n\n", pc);
    int f;
    do
    {
        printf("Enter:\n\t 1. to get a list of all open ports\n\t 2. to quit\n\n >>>>> ");
        scanf("%d", &f);
    } while (f < 1 || f > 2);
    if (f == 1 && pc > 0)
    {
        printf("| Port Number | %30s | %20s | Status \t|\n", s_n, t_p);
        pline(80);
        for(int i = 0, t = pc; i < t; i++)
            printf("|%12d | %30s | %20s | open\t|\n", op[i].num, op[i].name, op[i].protocol);
        pline(80);
    }
    else if (f == 1)
        printf("\nNo Open Ports!\n");
    else   
        printf("\nQuiting!\n");
    printf("\n");
    return 0;
}

void pline(int n)
{
    printf("|");
    for(int i = 1; i < 80; i++)
        printf("_");
    printf("|\n");
    return;
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
