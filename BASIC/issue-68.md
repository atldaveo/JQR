# Issue 68: Describe the addressing associated with key networking protocols

## IPv4
Four sets of octets (Total 32 bits) separated by a decimal point represented in either dot decimal or binary (eg. 172.217.168.238 or 10101100.11011001.10101000.11101110)

(What is IPv4? 2025)

## IPv6
In general, IPv6 addresses contain eight sets of 16 bits (Total 128 bits) separated by a colon. The numbers are usually represented in hexadecimal. The first three sets make up the **site prefix / Public Topology** (determines where packets are routed. Provided by ISP or RIR), the next hex number is the **subnet ID / Site Topology** (identifies the subnet that the device is a part of), and the final four hex numbers constitute the **interface ID** (Unique number set that identifies a specific device in the network - usually the device's MAC Address). 

2001.0db8:3c4d:0015:0000:0000:1a2f:1a2b is an example of an IPv6 Address

There are three types of addresses that IPv6 defines:
- **Unicast** (Individual node)
- **Multicast** (Groups of interfaces on different nodes - all memmbers of multicast group receive packets)
- **Anycast** (Packets are sent to the anycast member closest to sender)

(IPv6 Addressing Overview 2011)

## Ethernet
48-bits long and written in hexadecimal. The first 24 bits make up the **organizationally unique identifier (OUI)** (Unique number to NIC Card vendor) and the next 24 bits are the **serial number** (unique to the manufacturer). 

In addition to the MAC Address, ethernet also has three other addresses:
- **Unicast** Hardware identification (NIC) for the device on the network. MSB is 00.
- **Multicast** Group address. Odd value in MSB (01). Individually accepted packets. 
- **Broadcast** Must be received by all devices in local network. All bit fields are 1 (or hex F).

(Harrington C, Chubb I 2024)

## Works Cited
Harringon C, Chubb I. 03_ethernet_lan.md. [class resource]. Basic Level Curriculum 
Repository; 2024 Aug. [US Army Cyber School]. 

IPv6 Addressing Overview. [Internet]. Oracle System Administration Guide: IP Services; 2011. [accessed 2025 Jan 24]. Available from: https://docs.oracle.com/cd/E18752_01/html/816-4554/ipv6-overview-10.html

What is IPv4?. [Internet]. Uptrends. [accessed 2025 Jan 24]. Available from: https://www.
ptrends.com/what-is/ipv4 