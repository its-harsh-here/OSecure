Port_No | Service Name              | Transport Protocol | Vulnerability Rating (/5)
--------------------------------------------------------------------------------------------------------------
135     | Microsoft EPMAP           | TCP/UDP            | 5/5
- Facilitates communication between Windows services via RPC and DCOM.
- Exposes RPC DCOM buffer‑overflow bugs (e.g. MS03‑026), exploited by Blaster worm to run code remotely. :contentReference[oaicite:1]{index=1}
- Mitigation: apply Microsoft patches, disable RPC/DCOM if unused, and block port 135 via firewall or Windows Defender. :contentReference[oaicite:2]{index=2}

20      | FTP‑Data                  | TCP                | 4/5
- Used for FTP data transfer in active mode.
- Transmits credentials and data in clear‑text; vulnerable to MITM, brute‑force, directory traversal, bounce attacks. :contentReference[oaicite:3]{index=3}
- Mitigation: disable FTP service if unused, block port 20 via firewall, use SFTP or FTPS instead. :contentReference[oaicite:4]{index=4}

21      | FTP                       | TCP                | 4/5
- Standard FTP control port for sending commands.
- Same risks as port 20: clear‑text credentials, brute‑force, directory traversal, FTP‑bounce. :contentReference[oaicite:5]{index=5}
- Mitigation: block or disable FTP‑control, enforce secure FTP alternatives. :contentReference[oaicite:6]{index=6}

22      | SSH                       | TCP                | 3/5
- Secure Shell for encrypted remote login.
- Potential brute‑force login, weak credentials, outdated implementations. :contentReference[oaicite:7]{index=7}
- Mitigation: use key‑based authentication, disable password login, update OpenSSH, deploy fail2ban/rate limits.

23      | Telnet                    | TCP                | 5/5
- Remote unencrypted shell access.
- Sends all data including credentials in plain text; trivial sniffing and hijacking. :contentReference[oaicite:8]{index=8}
- Mitigation: disable Telnet, use SSH; block port 23 via firewall.

25      | SMTP                      | TCP                | 3/5
- Simple Mail Transfer Protocol for sending email.
- Open relays, spoofing, spam abuse if misconfigured. :contentReference[oaicite:9]{index=9}
- Mitigation: configure SMTP securely, enforce authentication, use TLS, block or restrict port 25 access.

53      | DNS                       | TCP/UDP            | 4/5
- Domain Name System for queries and zone transfers.
- Can be abused in reflection/amplification DDoS attacks. :contentReference[oaicite:10]{index=10}
- Mitigation: restrict zone transfers, rate-limit queries, firewall port 53.

69      | TFTP                      | UDP                | 3/5
- Trivial File Transfer Protocol (used for boot, firmware).
- No authentication or encryption; vulnerable to unauthorized read/write, DoS. (General known issue)
- Mitigation: disable TFTP service, restrict with ACLs or firewall port 69.

80      | HTTP                      | TCP                | 4/5
- Unencrypted web traffic.
- Prone to XSS, SQLi, CSRF, DDoS if web app is weak. :contentReference[oaicite:11]{index=11}
- Mitigation: disable if unused; otherwise enforce HTTPS, secure web app, patch server, use WAF.

110     | POP3                      | TCP                | 3/5
- Post Office Protocol v3 for email retrieval.
- Sends credentials in plain text; vulnerable to MITM and credential theft. :contentReference[oaicite:12]{index=12}
- Mitigation: disable POP3 if unused, enable POP3S (SSL/TLS), block port 110.

135     | Microsoft EPMAP           | TCP/UDP            | 5/5
- Facilitates RPC/DCOM service location on Windows.
- Buffer‐overflow vulnerabilities allow remote code execution (e.g. Blaster worm). :contentReference[oaicite:13]{index=13}
- Mitigation: apply Windows patches, disable RPC/DCOM if not used, block port via firewall. :contentReference[oaicite:14]{index=14}
137     | NetBIOS Name Service        | UDP/TCP            | 4/5
- Provides NetBIOS name registration and resolution on Windows networks. :contentReference[oaicite:1]{index=1}  
- Vulnerabilities: attackers can use NBNS spoofing/enumeration (nbtscan, NBSTAT) to map hostnames, domains, shares; risk of NetBIOS botnets and malware. :contentReference[oaicite:2]{index=2}  
- Mitigation: disable NetBIOS if unused, block UDP/TCP port 137 via firewall (Windows Firewall rule: block UDP/TCP port 137). :contentReference[oaicite:3]{index=3}  

139     | NetBIOS Session Service     | TCP (sometimes UDP) | 5/5
- Handles session establishment for SMB file/printer sharing over NetBIOS. :contentReference[oaicite:4]{index=4}  
- Vulnerabilities: exploited by malware (WannaCry via SMBv1, Sasser worm), NetBIOS session DoS (WinNuke), unauthorized access, SMB relay attacks. :contentReference[oaicite:5]{index=5}  
- Mitigation: disable SMBv1/NetBIOS over TCP/IP, block port 139 via firewall and restrict access to trusted internal systems only. :contentReference[oaicite:6]{index=6}  

143     | IMAP                        | TCP                | 3/5
- IMAP (Internet Message Access Protocol) allows email clients to access mail on a server in real time.
- Vulnerable to brute-force login attempts, and if not configured with SSL/TLS, credentials are sent in cleartext.
- Close by disabling IMAP on the server or allowing only secure IMAPS (port 993). Use firewall to block port 143.

381     | HP OpenView Network Node Manager | TCP           | 2/5
- Used for HP OpenView network management.
- Older versions had vulnerabilities allowing remote attackers to execute arbitrary commands.
- Close via firewall unless using HP OpenView; otherwise, update to latest secure version.

383     | HP OpenView Network Node Manager | TCP           | 2/5
- Companion port to 381, often used by HP OpenView agents.
- Vulnerable to remote execution via crafted packets.
- Close with firewall rules or disable unnecessary HP services.

443     | HTTPS                       | TCP                | 1/5
- Used for secure web traffic (HTTP over TLS/SSL).
- Misconfigurations (weak ciphers, expired certs, Heartbleed) can make it vulnerable.
- Keep TLS updated, disable weak ciphers, renew certs, use firewall to limit exposure.

464     | Kerberos Change/Set Password | TCP, UDP          | 3/5
- Used by Kerberos for password change requests.
- Vulnerabilities in implementations allow password guessing, downgrade attacks.
- Harden Kerberos config, allow only internal access, block externally.

465     | SMTPS (deprecated)         | TCP                | 3/5
- Used for sending email securely with SSL (now largely replaced by 587 with STARTTLS).
- Vulnerabilities in SSLv2/SSLv3 allow downgrade, MITM.
- Disable SSL versions, prefer TLS on port 587. Block 465 if unused.

587     | SMTP (email submission)    | TCP                | 3/5
- Used to send emails with STARTTLS encryption.
- Vulnerable to misconfigurations, brute force, and open relay if improperly secured.
- Enforce authentication, strong TLS; block externally unless used.

593     | Microsoft DCOM             | TCP                | 4/5
- Facilitates DCOM communication over RPC.
- Vulnerable to remote code execution (e.g. MS03-026), lateral movement.
- Block via Windows Firewall if not used; patch systems.

636     | LDAPS                      | TCP                | 3/5
- LDAP over SSL for secure directory queries.
- Exposed LDAPS servers can leak AD info or be targeted by MITM.
- Block externally, enforce strong TLS, allow only internal connections.

691     | MS Exchange (Link State Routing) | TCP           | 2/5
- Used in older Microsoft Exchange servers.
- Can be abused internally for information disclosure.
- Block externally, upgrade Exchange, restrict access.

902     | VMware ESXi Remote Console | TCP                | 4/5
- Used for VMware remote management.
- Vulnerable ESXi hosts can be exploited if left exposed.
- Block externally, limit to internal VLANs, patch ESXi hosts.

989     | FTPS (data)                | TCP                | 2/5
- Secure version of FTP for data channel.
- If misconfigured (e.g. passive mode + firewall), can leak data.
- Enforce TLS, configure firewall, block if unused.

990     | FTPS (control)             | TCP                | 2/5
- Secure version of FTP for control channel.
- Misconfiguration risks, like SSLv3 support, can open vulnerabilities.
- Enforce modern TLS, block port if not used.

993     | IMAPS                      | TCP                | 1/5
- Secure IMAP over SSL/TLS.
- Weak cipher use or expired certificates can introduce risks.
- Use strong TLS, monitor certs, block if unused.

995     | POP3S                      | TCP                | 2/5
- Secure POP3 with SSL/TLS.
- Vulnerable only with weak encryption or misconfig.
- Block if using IMAP instead; enforce TLS.

1025    | Microsoft RPC              | TCP                | 3/5
- Dynamic port for Microsoft RPC.
- Attackers can enumerate services, DCOM abuse.
- Use a firewall to restrict port range; enable RPC filtering.

1194    | OpenVPN                    | UDP                | 2/5
- Used by OpenVPN for secure VPN tunnels.
- Weak keys or open access can allow DoS or brute-force.
- Use strong encryption, firewall rules, updated software.

1337    | Elite / Custom App         | TCP/UDP            | 5/5
- Not standardized; often used by trojans or backdoors (e.g., Back Orifice).
- High-risk if open unexpectedly.
- Close with firewall, scan system for malware.

1589    | Cisco VQP (VLAN Query Protocol) | UDP            | 3/5
- Used by Cisco switches for VLAN assignment.
- Can be spoofed to gain unauthorized VLAN access.
- Disable VQP; prefer 802.1X and secure VLAN setup.

1725    | Steam Friends             | TCP                | 2/5
- Used for messaging in Steam games.
- May be abused for spoofing or DoS on exposed systems.
- Block via firewall if not needed.

2082    | cPanel (non-SSL)          | TCP                | 4/5
- Used to access cPanel admin interface over HTTP.
- If not secured, attackers can steal credentials or inject scripts.
- Use HTTPS (2083), block 2082 externally.

2083    | cPanel (SSL)              | TCP                | 2/5
- cPanel admin interface over HTTPS.
- Vulnerable only if SSL is weak or login brute-force allowed.
- Enforce 2FA, strong TLS; monitor access.

2483    | Oracle DB (default)       | TCP                | 4/5
- Used by Oracle database listener service.
- Attackers can query DB metadata or DoS Oracle listener.
- Use strong access control, block externally.

2484    | Oracle DB (SSL)           | TCP                | 2/5
- Same as 2483 but encrypted.
- Risks arise if SSL is misconfigured.
- Block externally, enforce strong TLS.

2967    | Symantec AV               | TCP                | 4/5
- Used by Symantec AV for communication.
- Was targeted by malware (e.g. Trojan horses).
- Block port, update AV, monitor traffic.

3306    | MySQL                     | TCP                | 4/5
- Default port for MySQL database connections. [cbtnuggets.com, Kinsta] :contentReference[oaicite:1]{index=1}  
- Vulnerabilities: exposed to SQL injection, brute‑forcing credentials, unauthorized access, and DoS if open publicly. [nvd, hackingarticles, general] :contentReference[oaicite:2]{index=2}  
- Mitigation: restrict access to trusted IPs via firewall; enforce strong credentials; disable remote access if not needed; enable SSL/TLS; patch server. :contentReference[oaicite:3]{index=3}  

5900    | VNC (RFB)                 | TCP                | 5/5
- Port for Remote Framebuffer (RFB) protocol used by VNC to share desktop GUIs over network. [Wikipedia, CBT Nuggets] :contentReference[oaicite:4]{index=4}  
- Vulnerabilities: weak authentication, no encryption, exploits leading to unauthorized access or DoS (e.g. RealVNC versions prior to patched). Exposed VNC is often scanned and attacked. [Rapid7, ISC, Medium] :contentReference[oaicite:5]{index=5}  
- Mitigation: disable VNC if unused; block port 5900 on firewall or restrict to internal IPs; tunnel via SSH/VPN; enforce strong passwords, encryption, and updates. :contentReference[oaicite:6]{index=6}  


3074   | Xbox Live (Game Traffic)   | TCP/UDP           | 3/5
- Used by Xbox consoles and related games for multiplayer and voice services. ([speedguide.net](https://www.speedguide.net/port.php?port=3074), [nordvpn.com](https://nordvpn.com/blog/port-forwarding-xbox-one/))  
- If port‑forwarded or publicly exposed, can be scanned and probed; although risk is low for exploits on Xbox itself, home networks may be targeted. UPnP can open ports automatically. ([reddit.com](https://www.reddit.com/r/xboxone/comments/idl6q2/open_nat_securely/))  
- Mitigation: Only forward on trusted LAN devices; disable UPnP if not needed; restrict incoming exposure using router/firewall.

5432   | PostgreSQL                  | TCP               | 4/5
- Default port for PostgreSQL database client-server communication. ([cbtnuggets.com](https://www.cbtnuggets.com/blog/cloud/what-is-mysql-port-3306?utm_source=chatgpt.com), [hackviser.com](https://hackviser.com/tactics/pentesting/services/postgresql))  
- Risks: Exposed databases may allow brute‑forcing credentials, exploit known RCE vulnerabilities, unauthorized access to data. ([cbtnuggets.com](https://www.cbtnuggets.com/common-ports/what-is-port-5432), [orc a.security](https://orca.security/resources/blog/aws-ec2-instance-allows-public-ingress-access-on-postgresql-port-5432/), [stream.security](https://www.stream.security/rules/ensure-there-is-no-unrestricted-inbound-access-to-tcp-port-5432-postgresql))  
- Mitigation: Restrict to trusted IPs with firewall or security groups; enable TLS; enforce strong authentication; patch PostgreSQL; disable if unused.

8086   | InfluxDB / HTTP Alternate   | TCP               | 3/5
- Often used by InfluxDB for admin interface or alternate HTTP services.
- If left exposed, attackers can access metrics or admin endpoints; potential data leak or DoS.
- Mitigation: Restrict access to localhost or secure network; require authentication; firewall port 8086 externally.

10000  | Webmin                      | TCP               | 4/5
- Default port for Webmin—web‑based system administration tool.
- Known for high-severity CVEs allowing remote code execution if not protected. ([general security advisories])
- Mitigation: Restrict access via firewall, enforce strong admin passwords, enable SSL, update regularly, use IP whitelisting.

6665‑6669 | IRC ports (IRC services) | TCP              | 3/5
- Used by IRC networks for chat services and bots.
- Can allow abuse via bots, spam, open proxy or reflection attacks.
- Mitigation: Disable if not used; restrict to trusted hosts; firewall ports.

6881   | BitTorrent                  | TCP               | 3/5
- Used by BitTorrent clients for P2P file sharing.
- Can expose node to DDoS, location tracking, open peer abuse.
- Mitigation: Avoid public exposure; use VPN/P2P proxies; block if unnecessary.

6999   | BitTorrent variant          | TCP               | 3/5
- Alternative port for torrent clients.
- Same risks: exposure to P2P threats, DDoS, and malware distribution.
- Mitigation: same as for 6881.

8222   | VMware Web Interface / HTTPS alternate | TCP      | 3/5
- Often used for VMware or other admin tools over HTTPS.
- If exposed, can lead to unauthorized access, brute-force attempts, outdated SSL/TLS vulnerabilities.
- Mitigation: Restrict to local/admin network, enable strong SSL, disable external access if unnecessary.

9100   | JetDirect / Print Services             | TCP      | 2/5
- Used by HP JetDirect printers and related services.
- Attackers can spam print jobs, DoS printers, or abuse misconfigured print servers.
- Mitigation: Close externally, restrict to local trusted systems, disable unused printer sharing.

12345  | NetBus (Trojan)                        | TCP      | 5/5
- Originally used by the NetBus remote access Trojan.
- Port scanning may detect this as a backdoor if open.
- Mitigation: Ensure system is clean of malware; block this port via firewall; scan for rootkits.

27374  | Sub7 (SubSeven Trojan)                 | TCP      | 5/5
- Associated with SubSeven Trojan—one of the most popular backdoors.
- If open, attacker may have full access to system, keystrokes, webcam, etc.
- Mitigation: Run antivirus/malware scan, block the port, reinstall OS if compromised.

31337  | Back Orifice (Hacking Tool)            | TCP      | 5/5
- Famous port used by the Back Orifice backdoor tool.
- Extremely risky if open; often associated with hacked systems.
- Mitigation: Disconnect infected system, clean install OS, monitor for lateral movement, block port.
