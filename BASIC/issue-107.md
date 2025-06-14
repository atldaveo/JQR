# Issue 107: Describe RF and EW development concepts, capabilities, and considerations.

## Purpose
- Electronic Attack (Jamming / Spoofing adversary electronics)
- Electronic Protection (Defend friendly systems)
- Electronic Support (Detect and analyze enemy electronic signals)

## Common reachback process
A reachback refers to the process of leveraging remote experise, intelligence, and technical support from non-deployed units / agencies. Critical in providing real-time analysis, operational support, and rapid adaptation of technologies. The following are commonn reachback processes:
- SIGINT
- Electronic Order of Battle (EOB) Updates
- Remote RF Spectrum Analysis
- Software-defined Radio (SDR) and EW firmware updates
- CEMA coordination
- Remote Jamming Effectiveness Evaluation
- RF propagation modeling support
- Counter-UAS Threat Updates
(FM 3-12 2017)

## Equipment
- Tactical Electronic Warfare System (TEWS) - Provides electronic support and attack
- EW Manpack - Scan electromagnetic spectrum for enemy activity
- Electromagnetic Skins and Smart RF Radomes - absorb, scatterm or alter the polarization of unwanted RF radiation
- Tactical Desmounted Electronic Warfare and Signals Intelligence (TDEWS) - Tactical sensor that enable EW and SIGINT capabilites to a Brigade
(Electromagnetic Skins 2023)

## Supporting and Supported Organizations
RF and EW capabilities serve to support Brigades and MDO. RF / EW teams themselves are supported by the Program Executive Office of Intelligence, Electronic Warfare, and Sensors (PM EW&C 2025), Combat Capabilities Development Command CSISR Center, Foundational Research for Electronic Warfare in MDS, and several defense industry partners like BAE and L3Harris (Foundational Research 2025). 

## Capabilities and Considerations
In RF/EW, development follows two paths depending on the use of the program. For instance, a "breaking" requirement entails 
1. Hardware Delivery
2. Exploitation/Research
3. Development and Testing
4. Release

On the other hand, "building" requirements are as follows
1. Acquire Hardware and Design
2. Develop Software
3. Integrate SW/HW and Test
4. Release

Additionally, developers may use the Field Programmable Gate Array (FPGA) to verify digital logic circuits. The FPGA approach is outlined below.
1. Analysis (Understand protocol, rapidly prototype, evaluate, and build test vectors)
2. Prep (Port prototype code to real-time implementation and handle practical details)
3. Implementation and Testing (Generate hardware, test, block integration)
(Miller 2023)

## Works Cited
Electromagnetic Skins and Smart RF Radomes for Spectrum Camouflage. [Internet]. US Army SBIR; 2023 Apr 19. [Accessed 2025 Jan 30]. Available from: https://www.armysbir.army.mil/topics/uas-continuous-time-spectrum-situational-awareness/?

FM 3-12 Cyberspace Operations and Electronic Warfare. US Department of Defense; 2017

Foundational Research for Electronic Warfare in Multi-Domain Operations (FREEDOM). [Internet]. CEVCOM CSISR Center; 2025. [Accessed 2025 Jan 30]. Available from: https://arl.devcom.army.mil/what-we-do/freedom/? 

Harrington C. E_RF_Development. [Class Resource]. US Army Cyber School - CCD Basic Lessons Repository; 2023. [Accessed 2025 Jan 29].

Miller S. Project Management in RF/Hardware Development [Class Resource]. 11th Cyber Battalion; 2023 Aug 7. [Accessed 2025 Jan 29].

PM EW&C. [Intenet] US Army PEO IEW&S; 2025 Jan 23. [Accessed 2025 Jan 30]. Available from: https://peoiews.army.mil/pm-ewc/?