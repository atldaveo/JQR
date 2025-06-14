# Issue 70: Describe different types of network communications

## LAN (Local Area Network)
Geographically constrained network (eg. home wifi) that connects devices with help from routers or network switches (if the LAN is in a large space). Most household LANs connect to the internet via a router using ethernet cables.

VLAN uses software to virtually divide the network as opposed to LAN's emnphasis on hardware. VLAN also assists in network management by distributing the workload into subdivisions 

(What is a LAN? 2025)

## WAN (Wide Area Network)
A group of LANs (a network of networks). WAN is not limited be geography or size (What is a LAN? 2025). WANs allow deveices from all around the world to connect with each other. WAN is owned by internet service providers who lease the WAN out to the parties that require it.

(What is a WAN? 2025)

## MAN (Metropolitan Area Network)
MAN is a network that connects devices found in large cities or areas with many buildings. MANs are smaller than WANs and larger than LANs. MANs are created when LANs in the city are connected using ISP's fiber optic cables. WANs run on dark fiber (fiber optic cable that were previously unused). 

(What is a metropolitan area network 2025)

## WLAN (Wireless LAN)
Distributes network connectivity over HF radio. Also serve as an access point to the internet. Wi-Fi is a subset of WLANs (not the same). Every device connected to a WLAN is called a **station**. Stations can be one of two types:
- **Access Point** (RX/TX radio signals to devices connected to the network)
- **Clients** (The device itself such as smart phones, computers, etc.)

Stations that are able to communicated with each other are called **basic service sets** (**BSS**). There are two forms of BSS:
- **Independent** (Two clients communicate without AP's, but cannot connect to other BSS)
- **Infrastructure** (Can only communicate with stations in other BSS)

The most common types of WLANs are:
- **Ad hoc** (Devices connected by proximity without a central AP)
- **Bridge** (Connects two separate wired networks / APs)
- **Infrastructure** (Central AP connects wireless devices to a wired network. Internet)
- **Public** (Use access pints connected to a wired network to grant internet access over a certain area)
- **Wireless Distribution System** (Multiple access points communicating wirelessly)

(Beal 2024)

## WWAN
WWAN uses cellular technology to support device communications in the WAN (instead of WLAN's use of Wi-Fi). Peripheral devices access the WWAN using wireless routers. WWANs come in three WWAN families:
- GSM/UMTS
- WiMAX
- CDMA One/CDMA2000

Like most wireless systems, WWAN's performance and throughput are inversely proportional to the vicinity of a device to the WWAN AP. However, this deficiency is made up as WWAN is able to provide global wireless coverage and better security than WLAN.  

(Overview of WWAN 2023)

## Works Cited
Beal V. Wireless Local Area Network (WLAN). [Internet]. Techopedia; 2024 Apr 28. [Accessed 2025 Jan 24]. Available from: https://www.techopedia.com/definition/5107/wireless-local-area-network-wlan

Overview of Wireless Wide Area Network (WWAN). [Internet]. Geeks for Geeks; 2023 Apr 18. [Accessed 2025 Jan 24]. Available from: https://www.geeksforgeeks.org/overview-of-wireless-wide-area-network-wwan/

What is a LAN (Local Area Network)? [Internet]. Cloudflare. [Accessed 2025 Jan 24]. Available from: https://www.cloudflare.com/learning/network-layer/what-is-a-router/

What is a metropolitan area network? (MAN)? [Internet]. Cloudflare. [Accessed 2025 Jan 24]. Available from: https://www.cloudflare.com/learning/network-layer/what-is-a-metropolitan-area-network/

What is WAN? How Wide Area Networks Function. [Internet]. CompTIA. [Accessed 2025 Jan 24]. Available from: https://www.comptia.org/content/guides/what-is-a-wide-area-network