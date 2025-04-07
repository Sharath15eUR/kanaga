# Module 3 - WLAN PHY Layer

### Q1. What are the different 802.11 PHY layer standards? Compare their characteristics.
There are various PHY layer standards that 802.11 covers.

| **`STANDARD`** | **`MODULATION`** | **`FREQUENCY BAND`** | **`DATA RATE`** |
|    :---:     |     :---:      |       :---:        |     :---:     |
|   802.11     |    DSSS,FHSS   | 2.4 GHz | 2 Mbps |
|   802.11a    |    OFDM (BPSK,QPSK,16-QAM,64-QAM)   | 5 GHz | 54 Mbps |
|   802.11b    |    DSSS    | 2.4 GHz | 11 Mbps |
|   802.11g    |    OFDM (BPSK,QPSK,16-QAM,64-QAM) and DSSS   | 2.4 GHz | 54.2 Mbps |
|   802.11n    |    OFDM (BPSK,QPSK,16-QAM,64-QAM)   | 2.4 GHz and 5 GHz | 600 Mbps (MIMO upto 4 spatial streams |
|   802.11ac    |    OFDM (BPSK,QPSK,16-QAM,64-QAM)   | 5 GHz | 6.93 Gbps (MIMO,MU-MIMO upto 8 spatial streams |

> NOTE: 
- **DSSS - Direct Sequence Spread Spectrum** : A technique where data is transmitted over a wide frequency band by spreading it across multiple frequencies. 
- **FSSS - Frequency Hopping Spread Spectrum** : A method where the transmitter and receiver hop between different frequencies in a predetermined pattern
- **MIMO - Multiple Input Multiple Output** : Uses multiple antennas to send and receive data simultaneously, allowing for higher throughput.
- **MU-MIMO - Multi User Multiple Input Multiple Output** : Modification of MIMO which allows multiple devices are allowed to communicate with the AP at the same time instead of a single device.
- **OFDM - Orthogonal Frequency Division Multiplexing** : A technique which splits the signal into multiple subcarriers to improve the speed of the transmission, especially in noisy environments.
- **BPSK - Binary Phase Shift Keying** : Modulation technique by which data is transmitted by changing the phase of a carrier wave between two distinct states, representing binary 0 and 1.
- **QPSK - Quadrature Phase Shift Keying** : Modulation technique by which 2 bits of data is transmitted by changing the phase of a carrier wave.
- **QAM - Quadrature Amplitude Modulation** : A modulation technique which combines Amplitude Modulation and Phase Shift Keying to transmit data.
  
### Q2. What are DSSS and FHSS? How do they work?
DSSS and FHSS are spread spectrum modulation techniques which deals with how signals are spread over a frequency domain. 

- **DSSS :** Direct Sequence Spread Spectrum is a technique where data signal is spread over a wide frequency band. The original data signal is multiplied by a pseudorandom noise sequence, which is a series of binary digits. The resultant spread signal is transmitted over air.

- **FHSS :** Frequency Hopping Spread Spectrum is another Spread Spectrum technique which works by rapidly changing the transmission frequency between hops according to a predefined hopping pattern. The transmitter and receiver are synchronized on the hopping pattern to ensure that the communication is not lost.

### Q3. How do modulation schemes work in the PHY layer? Compare different modulation schemes and their performance across various Wi-Fi standards.
Modulation is the process of varying one or more properties of a carrier wave in order to carry information. There are two types of modulation namely Digital and Analog modulation.

| **`MODULATION TECHNINQUE`** | **`WIFI STANDARD`** | **`PERFORMANCE`** |
|      :---:                  | :---:               | :---:             |
| **BPSK** | 802.11b | Provides a maximum speed upto 11 Mbps best suitable for long range communication |
| **QPSK** | 802.11a , 802.11g | Capable of providing higher data rates than BPSK with a maximum speed of 54 Mbps.|
| **16-QAM** | 802.11a, 802.11g, 802.11n | Provides higher data rate by encoding 4 bits per symbol which allows to provide a maximum speed of 54 Mbps for 802.11a/g and 600 Mbps for 802.11n standards.|
| **ASK** | Not generally used in Wi-Fi standards | Data is encoded by varying the amplitude of a waveform. A wave with high amplitude is understood for data carrying 1 as its information and wave with low amplitude is understood as 0.|

Different modulation schemes are used depending on the data rate, range, and interference conditions, with each scheme offering a tradeoff between speed and reliability.

### Q4. What is the significance of OFDM in WLAN? How does it improve performance?
OFDM stands for Orthogonal Frequency Divison Multiplexing which is a crucial technology which improves performance by dividing available bandwidths into subcarriers reducing inteference and enabling efficient data transfer. By dividing the available frequency spectrum into subcarriers, data transfer can be made less prone to noise as inteference in one subchannel will not affect the data in another subchannel. This contributes to better data transfer. 

### Q5. How are frequency bands divided for Wi-Fi? Explain different bands and their channels.
Wi-Fi primarily operates in 2 frequency bands :
* **2.4 GHz :** This band has 14 channels out of which only 3 channels (Channels 1,6 and 11) are non-overlapping and suitable for data communication.Since it was the initially deployed frequency band, it faces inteference issues since it is heavily used by many devices. The Wi-Fi spectrum is 70 MHz wide and provides data rate upto 100 Mbps.
* **5 GHz :** This band operates on higher number of channels compared to the 2.4 GHz spectrum supporting almost upto 23 non-overlapping channels. This spectrum is 500 MHz wide,providing maximum data rate of 1 Gbps and supports newer Wi-Fi standards.

> Another important frequency band is the 6 GHz frequency band which provides more channels and lesser inteference. It is 1200 MHz wide and is accessible to new Wi-Fi 6E devices providing a maximum data rate of 2 Gbps. 

### Q6. What is the role of Guard Intervals in WLAN transmission? How does a short Guard Interval improve efficiency?
Guard Interval is the time gap between two OFDM symbols to prevent interference (Inter-Symbol Inteference,ISI) due to multipath propagation.There are two types of Guard Intervals :

- **Short Guard Interval (SGI)**: Reduces the time between transmissions, which improves efficiency by allowing more data to be transmitted in the same period.
  
- **Long Guard Interval (LGI)**: Ensures reliable data transfer but reduces throughput.
> Different Wi-Fi standards use different Guard Intervals which are usually in the order of Micro Seconds.

### Q7. Describe the structure of an 802.11 PHY layer frame. What are its key components?
There are two types of PPDU format namely Long Preamble PPDU and Short Preamble PPDU but the general format of the PHY layer frame is :

| **PREAMBLE** |**HEADER**|**PSDU**|
| :---:|:---:|:---:|

* **PREAMBLE :** Consists of a sequence of bits transmitted before the actual data, used for synchronization between the transmitter and receiver.
* **HEADER :** Contains information about the frame, such as modulation type, data rate, and frame length.
* **PSDU (Physical Service Data Unit):** Contains actual data payload or content being transmitted.
  
### Q8. What is the difference between OFDM and OFDMA?
|**`OFDM`**|**`OFDMA`**|
|:---:|:---:|
| Stands for Orthogonal Frequency Division Multiplexing | Stands for Orthogonal Frequency Division Multiple Access |
| It is the modulation scheme for high speed data transmission ensuring high throughput | Multi-access method to allow multiple users to share the same frequency spectrum |
| Used in point-to-point communication | Used for Multi User System |
| Allocates all subcarriers to a single user at a time | Allocates different subcarriers to multiple users simultaneously |
| One user uses all subcarriers | Different subcarriers are assigned to different users |

### Q9. What is the difference between MIMO and MU-MIMO?
|**`MIMO`**|**`MU-MIMO`**|
|:---:|:---:|
| Stands for Multiple Input Multiple Output | Stands for Multi User Multiple Input Multiple Output |
| Improves throughput of a single user | Improves throughput of the network |
| Uses multiple antennas to send and receive data streams pertaining a single device | Uses multiple antennas to send and receive data streams pertaining to multiple devices |
| Single device receives multiple data streams | Multiple devices receive multiple data streams |
| Only one device can use the channel at a time, reducing overall system efficiency | Multiple devices can use the channel at a time, increasing overall system efficiency |

### Q10. What are PPDU, PLCP, and PMD in the PHY layer?
- **PPDU :** The PHY Protocol Data Unit is the packet format transmitted over the wireless medium, containing preamble and data fields. The frame format of PPDU can vary over Wi-Fi generations but it contains three main fields namely Preamble, Header and PSDU. It adds or removes the Preamble and Header in the sender or receiver side respectively.

- **PLCP :** The Physical Layer Convergence Protocol acts as an interface between the PHY and MAC layers. It maps MPDUs into a frame format suitable for transmission by the Physical Medium Dependent (PMD) sublayer.

- **PMD :** The Physical Medium Dependent layer is responsible for defining the details of transmitting and receiving data bits over a physical medium

### Q11. What are the types of PPDU? Explain the PPDU frame format across different Wi-Fi generations.
There are two types of PPDU, namely :
- Long Preamble PPDU
- Short Preamble PPDU

The PPDU frame formats across Wi-Fi generations are :
1. **802.11b :**

| **SYNC** |**SFD**|**SIGNAL**|**SERVICE**|**LENGTH**|**CRC**|**PSDU**|
| :---:|:---:|:---:| :---:|:---:|:---:|:---:|
| (128 or 56 bits) Used for synchronization | (16 bits) Marks the start of frame | (8 bits) Mentions the data rate | (8 bits) Reserved for future purposes | (8 bits) Contains the frame length | (8 bits) Error detection technique | Payload/Data |

2. **802.11a/g :**

| **SFT** |**LFT**|**RATE**|**LENGTH**|**PARITY**|**TAIL**|**PSDU**|
| :---:|:---:|:---:| :---:|:---:|:---:|:---:|
| Short Training Field used for time synchronization | Long Training Field used for channel estimation | Modulation Scheme is specified | Contains the frame length | Error detection bit | Ensures signal Integrity | Payload/Data |

3. **802.11n :**

| **HT SIG1** | **HT STF** |**HT LTF**|**HT SIG2**|**SERVICE**|**LENGTH**| **TAIL** |**CRC**|**PSDU**|
| :---:|:---:|:---:| :---:|:---:|:---:|:---:|:---:|:---:|

There are three variations to the 802.11n frame format. Above frame format is the base frame format and additionally, Legacy Preamble may be added to support backward compatibility with 802.11a/g standards. 

4. **802.11ac :**

| **L-SFT** |**L-LFT**|**L-SIG**| **VHT SIG-A1**| **VHT SIG-A2** | **VHT STF** |**VHT LTF**|**VHT SIG-B**|**SERVICE**|**LENGTH**| **TAIL** |**CRC**|**PSDU**|
| :---:| :---:|:---:| :---:| :---:|:---:|:---:| :---:|:---:|:---:|:---:|:---:|:---:|

The 802.11ac frame format includes components such as L-SFT, L-LFT, and VHT SIG, designed to enhance throughput with higher data rates using Very High Throughput (VHT) features.
5. **802.11ax :**

| **L-SFT** |**L-LFT**|**L-SIG**| **HE SIG-A**| **HE SIG-B** | **HE STF** |**HE LTF**|**SERVICE**|**LENGTH**| **TAIL** |**CRC**|**PSDU**|
| :---:| :---:|:---:| :---:| :---:|:---:|:---:| :---:|:---:|:---:|:---:|:---:|

The 802.11ax frame format introduces HE (High Efficiency) features like HE SIG and HE LTF, optimizing performance in dense environments, improving spectrum efficiency, and supporting MU-MIMO.

### Q12. How is the data rate calculated?
Data Rate is calculated using the formula :

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(Number of Sub Carriers) x (Number of Coded Bits per Sub Carrier) x (Coding) x (Number of Spatial Streams) 

**Data Rate** =_________________________________________________________________________________________________________________

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(OFDM Symbol Duration) + (Guard Interval Duration)

[The MCS Index Table](https://mcsindex.com/) can be used to verify the data rates.
