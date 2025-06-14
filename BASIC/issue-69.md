# Issue 69: Describe the concepts and terms associated with physical and logical network infrastructure

## Hubs
An ethernet hub allows for multiple devices to communicate with each other on a single network via a series of ports and cables. There are three basic types of hubs:
- **Passive Hub** (Incoming packets are unchanged before routing)
- **Active Hub** (Amplify packets prior to routing)
- **Intelligent Hub** (Oftentimes software defined with SNMP and VLAN capability. Also possible to stack these hubs together)

All arriving packets are routed to every single port in a hub regardless of origin because the hub has no way of knowing which device / port requested the packet. This lack of discrimination often impacts network performance; adds unnecessary steps in routing data.   

(Mitchell 2024)

## Switches
Similar to a hub, switches also connect network segments operating out of OSI layer 2 (and layer 3 for routing). Switches differ from hubs in that incoming packets are sent directly to the intended recipient of the packet instead of to all the physical ports. This capability, in conjunction with full-duplex communication, performance data analysis, and efficient bandwidth use creates a more optimal course of action to multi-device network users than a hub. 

Network switches identify a connected device's network-interface card via its MAC address to determine origin / destination of data packets. Switches' use of the entire bandwidth to which it is connected allows for two-way communication and reduces the possibility of collisions in network traffic.  

Types of switches include:
- **Unmanaged** (Basic and fixed configuration. Inexpensive)
- **Managed** (CLI configuration. Contain SNMP agents for troubleshooting. Can support VLANs)
- **Smart / Intelligent** (Slightly fewer features than a managed switch. Likely to use  Web GUI rather than CLI to manage)
- **KVM** (Keyboard, Video, Mouse. Enables periphery control of many servers) 

Switches can also be used for security by facilitating intrusion detection, performance analytics, and firewalling. This is done by connecting a switch just outside the router so that data flow through the switch before the router. 

(Shaw 2024)

## Routers
Routers, like switches, also forward network traffic across ports. However, routers operate primarily in OSI Layer 3 (As opposed to switches' primarily layer 2 operation) and are intended to connect networks to other networks instead of between devices on the same network as a switch is intended. However, modern Wifi / WAN routers also come with extra physical ports that accomplish the same thing as a hub - local and external routing (Shaw 2024).

Routers serve two primary functions: 
- Managing traffic between networks   
- Allow multiple devices to use the same internet connection

A router works by reading the header of a data packet to determine destination, consulting an internal routing table for the most efficient path, and then forward that packet to the next network / destination. Moreover, a router distributes internet connectivity from a modem to devices that want access.    

Routers typically come in the following forms:
- Wireless / Wired Router (Distribute internet over wifi or ethernet, respectively)
- Core Router (Supports high volume network traffic and operates at the core of LAN)
- Edge Router (Communicates with both core routers and external networks using BGP)
- Virtual Router (Software app that works the same as a traditional router)

(What is a Router 2025)

## Firewalls
Firewalls are mechanisms that oversees network traffic. Specifically, firewalls examine packet contents and, based on predetermined rules, makes a decision to accept or reject the data. Firewalls serve as the first line of defense against malicious code or external access.   

Below are the primary types of firewalls
- **Packet-Filtering** (Basic firewall. Inspects packet headers and respond accordingly)
- **Stateful Inspection** (Examines state of the network connections and make decisions based on that state using predefined rules)
- **Proxy Firewall** (Separates internal and external networks. Possibly slower due the comprehensive nature of the deep packet inspection)
- **Web Application Firewall (WAF)** (Protect against web-based attacks by inspecting HTTP traffic and can detect / block threats like SQL Injectionm XSS, etc)
- **Unified Threat Management (UTM)** (Integrates intrusion prevention, anti-virus, content filtering, and possibly VPN functionality)
- **Next-Gen Firewall (NGFW)** (Modernized version of traditional firewalls. Provides deep packet inspection, application-level filtering, and intrusion detection)

(Network Firewall 2025)

## Works Cited

Mitchell B. What are Ethernet and Network Hubs? [Internet]. Lifewire: Tech for Humans; 2022 Jun 24. [Accessed 2025 Jan 24]. Available from: https://www.lifewire.com/ethernet-and-network-hubs-816358

Network Firewall. [Internet]. Barracuda. [Accessed 2025 Jan 24]. Available from: https://www.barracuda.com/support/glossary/network-firewall

Shaw K. What is a network switch and how does it work? [Internet]. NetworkWorld; 2024 Apr 11. [Accessed 2025 Jan 24]. Available from: https://www.networkworld.com/article/969239/what-is-a-network-switch-and-how-does-it-work.html

What is a Router? [Internet]. Cloudfare. [Accessed 2025 Jan 24]. Available from: https://www.cloudflare.com/learning/network-layer/what-is-a-router/