# Issue 67: Describe the concepts and terms associated with common protocols and their associated ports

## Address Resolution Protocol (ARP)
A translation protocol that assigns an IP Address to a device's MAC address. This information is then held in a directory. This translation is critical in network connectivity between devices over a network. ARP works in the following process:

1. Data sent over a LAN arrives at a specific device
2. Gateway machine halts transmission and the ARP program is asked to confirm the MAC Address associated with the IP Address within the sent data. 
3. Once confirmed, the data is released.

ARP requests include fields like hardware type, protocol type, hardware address length, protocol address length, sender hardware address, sender protocol address, target hardware address, and target protocol address.

ARP is not a fixed process, but rather can be manipulated based on need such as inverse ARP (instead of requesting a MAC Address, request an IP address), proxy (ARP request-handling for devices not on LAN), or more sinister needs such as spoofing. 

As such alternatives to ARP have been formulated via the release of IPv6.

(Address Resulution Protocol 2024)

## Hypertext Transfer Protocol / Secure (HTTP/HTTPS)
HTTP is an application-layer protocol based on TCP using hypertext to establish a logical link between text nodes. They do not depend on previous 'run' commands but, rather, each command is executed separately. HTTP requests gives access to information necessary to render a webpage. HTTP uses port 80 by default. 

HTTPS is a secure version of HTTP using port 443 (Data Communication) that encrypts/scrambles data (using TLS or SSL) and securely authenticates network servers,  

(Leo 2024)

## Domain Name System (DNS)
Essentially works as a telephone book for the internet; translates human-readable host names (eg. google.com) into machine readable IP addresses (eg. 196.168.1.1) in order for browswers to obtain the domain's internet resources. Loading a webpage requires 4 DNS servers:
- DNS recursor (Receive and route queries from the client)
- Root nameserver (Reference to other, more specific locations)
- TLD (Top Level Domain) nameserver (Next step in resolving host name and IP. Hosts last portion of a  hostname.)
- Authoritative nameserver (Returns IP address for hostname back to DNS recursor)
(What is DNS? 2025)

## Simple Mail Transfer Protocol (SMTP)
Allows for the exchange of emails between servers. Operates on ports 587 and 25 (SMTP Relay, not submission). Always on (listening). Establishes a TCP connection to SMTP server and then sends mail through connection. 

There are two models for SMTP
- End-to-End (Communicate between different organizations)
- Store-and-Forward (Inter-organizational)

Components of SMTP
- Mail User Agent (MUA) (Computer app. Origin of email to be sent)
- Mail Submission Agent (MSA) (Receives mail from MUA and interacts with MTA for transfer)
- Mail Transfer Agent (MTA) (Transfers mail between devices with SMTP)
- Mail Delivery Agent (MDA) (Delivers the mail to new local system)

SMTP envelopes contain information that guides email delivery between servers. They usually contain
- Sender Address
- Recipient Addresses
- Routing Information 

(SMTP 2024)

## Internet Control Message Protocol (ICMP)
Network later protocol used by network devices to troubleshoot network problems. Checks if data transmitted arrived at its destination intact and on time. Authenticates via the TCP handshake. Protocol is independent of port and connection.  

(ICMP 2025)

## Dynamic Host Configuration Protocol (DHCP)
Mechanism that automates the assignment of IP addresses to fixed, mobile, and connected hosts. In order to access a DHCP network, the entrant requests an IP address, gets assigned an IP address, and then has IP address returned (after a certain amount of time or if the entrant device shuts down). 

(Weinberg 2022)

## Internet Protocol v4 (IPv4)
4th version of packet-switching network framework since 1982. Characteristics are
- 32-bit Address Space
- Decimal separated 32-bit addresses
- Limited number of unique addresses

IP Addresses are unique groups of numbers that enables network communication. Can either be viewed in dot-decimal (eg. 172.217.168.238) or binary 
(eg. 10101100.11011001.10101000.11101110).

With the implementation of Classless Inter-Domain Routing (CIDR) in 1993, IP addressing became more flexible and available. CIDR adds a suffix to IP address to determine how many leading bits represent the network address.  

(What is IPv4? 2025)

## Internet Protocol v6 (IPv6)
An updated internet protocol that addresses networking issues inherent in IPv4 (eg. smaller routing tables, simplified packet headers, and broadcasting). Key difference are:
- IPv6 uses 128 bits for an IP address (vs. IPv4's 32) where 64 bits are used for the network number and 64 bits are reserved for the host number (usually derived from MAC address).
- Fuses MAC address with IP address (eg. 2001:0DB8:1234:A1EA:A004:1001:53C8)
- Supports IP address autoconfiguration without the need for manual input of DHCP

(TechTarget Contributor 2024)

## Works Cited
Address Resolution Protocol (ARP): What It Is and How It Works. [Internet]. OKTA; 2024 Aug 
30. Available from: https://www.okta.com/identity-101/address-resolution-protocol-arp/

Harringon C, Chubb I. Common Protocols [class resource]. Basic Level Curriculum 
Repository; 2024 Aug. [US Army Cyber School]. 

Leo B. HTTP vs HTTPS - Difference Between Them. [Internet]. Guru99; 2024 Jun 27. [accessed 
2025 Jan 23]. Avaiblable from: https://www.guru99.com/difference-http-vs-https.html

Simple Mail Transfer Protocol (SMTP). [Internet]. Geeks For Geeks; 2024 Dec 19. [accessed 
2025 Jan 23]. Available from: https://www.geeksforgeeks.org/
simple-mail-transfer-protocol-smtp/
 
TechTarget Contributor. [Internet]. Tech Target; 2024 Oct. [accessed 2025 Jan 23]. Available from: https://www.techtarget.com/searchnetworking/definition/IPv6-Internet-Protocol-Version-6 

Weinberg N. DHCP defined and how it works. [Internet]. Network World; 2022 Mar 14.
[accessed 2025 Jan 23]. Available from: https://www.networkworld.com/article/966242/
dhcp-defined-and-how-it-works.html 

What is DNS? | How DNS works. [Internet]. Cloudfare. [accessed 2025 Jan 23]. Available 
from: https://www.cloudflare.com/learning/dns/what-is-dns/ 

What is IPv4?. [Internet]. Uptrends. [accessed 2025 Jan 23]. Available from: https://www.
ptrends.com/what-is/ipv4  

What is the Internet Control Message Protocol (ICMP)?. [Internet]. Cloudfare; [accessed 
2025 Jan 23]. Available from: 
https://www.cloudflare.com/learning/ddos/glossary/internet-control-message-protocol-icmp/a