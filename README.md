
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

## 📁 Sample File: `ports.txt`

This file should include a list of port numbers (one per line), and optionally vulnerability ratings or descriptions in a future version.

Example:

