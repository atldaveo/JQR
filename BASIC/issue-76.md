# Issue 76: Describe data serialization and deserialization

## Serialization
This is the process by which an object or structure is prepared for transfer over a network or storage. 

## Deserialization
The process by which data received in serial stream is aggregated and reconstituted into useful data. 

## Endianness
Different devices interpret endianness differently; One device may be little-endian, but receives data from a device that is big-endian. If this conflict is not rectified, the data will be mistranslated and will be otherwise unintelligible. As such, this issue is handled by using Python's `struct.pack` function or C's `ntohl`, `htonl`, `ntohs`, and `htons` functions.  

An example conversion is as follows:
Assuming data of 4 Bytes containing 0x78563412 (Little-Endian), it's translation into big-endian would yield 0x12345678 - Each Byte (octet) is preserved, but the order is reversed. 

## Works Cited
Allred J, Chubb I. 01_Describe_Serialization. [Class Resource]. Basic Level Curriculum 
Repository; 2024 Aug. [US Army Cyber School]. 