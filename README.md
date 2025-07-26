# 🔍 Port Scanner Tool

This tool scans a list of ports from `ports.txt` and checks which ones are open on the provided IP address.

---

## 📦 Project Summary

This command-line tool uses **Nmap** to scan ports listed in a file and returns only those that are open. It's designed for use with a simple terminal command and can be extended for vulnerability management.

---

## ⚙️ Usage: ./main <IP Address>


This command will:
- Read a list of ports from `ports.txt`
- Scan each port using Nmap
- Print the open ports on the specified IP

---

## 🖥️ System Configuration

The code was written and tested on the following system:

- **Operating System**: Ubuntu 24.04.1 LTS  
- **Kernel**: Linux 6.8.0-49-generic  
- **Architecture**: x86-64  

---

## 🛠️ Tools Used

- [Nmap](https://nmap.org/) — for port scanning  
- `gcc` — to compile the code  
- Terminal — for executing the script

---

## 🚀 Future Add-ons

1. ✅ **Menu-driven Interface**  
   Add options for scanning only ports with a vulnerability rating (1–5).

2. ⚠️ **One-Time Scan Result**  
   Modify the logic to display open ports only the first time the tool is executed.

3. 🔐 **Port Vulnerability Info**  
   Create another menu-driven interface to:
   - Input a port number
   - Fetch its description from `ports.txt`
   - Explain its vulnerabilities and suggest ways to secure or close the port

---



