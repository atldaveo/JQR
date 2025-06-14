# Issue 66: Describe the concepts and terms associated with networking fundamentals

## Transmission Control Protocol (TCP) vs. User Datagram Protocol (UDP)

TCP communication protocol between clients and a server that allows transmission of data packets through a network with three primary forms transmission assurance in communication
- Synchronization
- Synchronization Acknowledgement
- Final Acknowledgement
These assurances ensure the integrity of the data being transmitted between the client and server. 

UDP, on the other hand, is a message-oriented communication protocol. Data is sent without as many assurances, if at all, between the server and clients as TCP would. This optimizes real-time communication and broadcast. In UDP, connection is not essential as the server transmits its data to its clients without a need for confirmation. Because of the lower amounts of overhead, UDP is typically a faster method of broadcasting information, though the integrity of the broadcast data (or the confirmation of the data being received) will not be as reliable.   
(Spiceworks 2025)

## Open Systems Interconnect (OSI) Model

A conceptual framework describing networking or telecommunications systems in the following seven layers (Bottom to Top):

1. **Physical** The absolute "nuts and bolts" of the system. This bottom layer includes the physial hardware involved in the system such as voltage, wiring/cables, etc.

2. **Data Link** Provides the node-to-node data transfer and error-handling capabilities. Two sub-layers constitute this layer - the Media Access Control (MAC) and the Logical Link Control (LLC) layers. Additionally, most network switches operate in this layer (with some virtualization exceptions to layer 3). 

3. **Network** Most routers and some switches operate in this layer. This layer is responsible for getting data packets to where they need to go. 

4. **Transport** Coordinates the data transfer between systems and hosts. TCP and UDP operate out of the transport later. 

5. **Session** This layer arises out of a need for two or more networked devices need to communicate directly with each other. This layer provides the platform for the communications process between the devices. 

6. **Presentation** This layer presents the data, with none of its transmission overhead, from the lower layers to the application itself. Encryption/decryption operates on this layer. 

7. **Application** Closest layer to the end user. Data is received directly from the user as input and data is output for the user to view at this layer. Web browsers are common layer 7-residing forms of communications 

(Shaw 2024)

## POSIX API / BSD Sockets
Using C, socket communications can be implemented by including the <arpa/inet.h> and <sys/socket.h>, establish a client-server connection, and then using that stream connection to communicate remotely. An in-depth implementation can be seen in the client-server/ repository.

## Purpose and use of sockets
"Sockets provide point-to-point, two-way communication between two processes. Sockets are a basic component of interprocess and intersystem communication. A socket is an endpoint of communication to which a name can be bound. It has a type and one or more associated processes" (Sockets Overview 2011).

## Request for comments (RFC's)
The Internet Engineering Task Force's publication of technical documentation of the "internet's technical foundations, such as addressing, routing, and transport technologies" through RFCs. RFCs are implemented and used around the world by all internet users. RFCs are always being developed and published via a variety of formats that are freely available for anyone interested. Once published, RFC's cannot be changed. Because RFCs are seldom perfect products, however, they are updated and archived regularly when correction/errata arise or users report vulnerabilities.
(About RFCs 2025)  

## Purpose of subnetting
Subnetting is done in order to allocate portions of the original network address space and piecemeal those portions to different local functions while maintaining a central host. Benefits include:
- Limiting the number of devices to manage
- Controlling the flow of network traffic
- Securing subnets instead of individual leasees
- Compartmentalizing makes it easier to find the right system during troubleshooting 
(Harrington C, Chubb I 2024)

## Works Cited
About RFCs: RFCs are the core output of the IETF. [Internet]. The Internet Engineering Task Force (IETF); [Accessed 2025 Jan 23]. Available from: https://www.ietf.org/process/rfcs/  

Harringon C, Chubb I. 07_subnetting.md. [class resource]. Basic Level Curriculum Repository; 2024 Aug. [US Army Cyber School]. 

Shaw K. What is the OSI model? How to explain and remember its 7 layers. [Internet]. NetworkWorld; 2024 Jul 9. Available from: https://www.networkworld.com/article/964816/the-osi-model-explained-and-how-to-easily-remember-its-7-layers.html 

Sockets Overview. [Internet]. Oracle Programming Interfaces Guide; [accessed 2025 Jan 23]. Available from: https://docs.oracle.com/cd/E23824_01/html/821-1602/svipc-13.html 

Spiceworks. TCP vs. UDP: Understanding the differences [Internet]. Austin (TX): Spiceworks; [accessed 2025 Jan 23]. Available from: https://www.spiceworks.com/tech/networking/articles/tcp-vs-udp/

