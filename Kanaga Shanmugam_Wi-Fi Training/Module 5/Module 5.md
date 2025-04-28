# Module 5 - Advanced Features and Standard Extensions

### Q1. What are the key features of Wi-Fi 6, 6E and 7 and how do they differ from previous standards like Wi-Fi 5 (802.11ac)?
| **Wi-Fi 5** |**Wi-Fi 6** |	**Wi-Fi 6E**	| **Wi-Fi 7** |
|  :---:  |  :---:  |  :---:    |  :---:  |
| Uses 5 GHz frequency spectrum | Uses 2.4 and 5 GHz frequency spectrum | Uses 2.4 and 6 GHz frequency spectrum | Uses 2.4, 5 and 6 GHz frequency spectrum |
| Supports maximum of 3.5 Gbps data rate | Supports maximum of 9.6 Gbps data rate | Supports maximum of 9.6 Gbps data rate | Supports maximum of 46 Gbps data rate |
| The maximum channel width is 80 MHz and has an option of 160 MHz | The maximum channel width is 160 MHz | The maximum channel width is 160 MHz | The maximum channel width is 320 MHz |
| Supports 256-QAM Modulation |	Supports 1024-QAM Modulation | Supports 1024-QAM Modulation | Supports 4096-QAM Modulation |

### Q2. Explain the role of OFDMA in Wi-Fi 6 and how it improves network efficiency.
OFDMA (Orthogonal Frequency Division Multiple Access) is one of the key technologies introduced in Wi-Fi 6 (802.11ax) to improve efficiency, especially in environments with many connected devices. OFDMA being a upgraded version of OFDM which allows a single user to transmit data in different sub-carriers, allows multiple users to transmit and receive data in the sub-carriers.

By splitting the channel into multiple sub carriers and grouping them as Resource Units(RU), OFDMA allocates different devices,different RUs to allow them to transmit and receive data at the same time. By allowing multiple devices to transmit and receive data simultaneously over the same channel, Wi-Di 6 improves network efficiency.

### Q3. Discuss the benefits of Target Wake Time (TWT) in Wi-Fi 6 for IoT devices.
Target Wake Time is a key feature to improve power efficiency for IoT devices. Target Wake Time allows devices to negotiate time intervals for communication and allows the battery powered IoT devices to sleep otherwise. By doing so, it not only allows Power Management in IoT devices, it also reduces unnecessary network congestion. Station sends a Target Wake Time request to the AP proposing wake intervals. Once AP confirms the schedule, the Station sleeps and wakes up only at agreed times for communication.

### Q4. Explain the significance of the 6 GHz frequency band in Wi-Fi 6E.
Network congestion in 2.4 GHz and 5 GHz lead to the expansion of 6 GHz frequency spectrum. Wi-Fi 6E adds almost 1200 MHz of spectrum from 5.9 GHz to 7.1 GHz. Allows 14 80MHz channels or 7 160 MHz channels. While the 2.4 GHz and 5 GHz are crowded with Wi-Fi, Bluetooth and other devices, 6 GHz frequency spectrum is dedicated to devices using Wi-Fi 6E standard. 

### Q5. Compare and contrast Wi-Fi 6 and Wi-Fi 6E in terms of range, bandwidth, and interference.
| **Wi-Fi 6** | **Wi-Fi 6E** |
|    :---:    |     :---:    |
| Uses 2.4 GHz and 5 GHz frequency spectrum | Uses 2.4 GHz and 6 GHz frequency spectrum |
| They have a good range but can be prone to interference by other devices | Since their frequency range is dedicated to devices using Wi-Fi 6E standard, they have much less inteference |
| Supports bandwidths up to 160 MHz on the 5 GHz band, which is well-suited for many applications | The 6 GHz band offers significantly more bandwidth, with up to 1,200 MHz available offering wider channels for bandwidth-intensive tasks | 

### Q6. What are the major innovations introduced in Wi-Fi 7 (802.11be)?
Wi-Fi 7 also known as Extremely High Throughput brings various new additions to the existing standards by concentrating more on data rates, reliability and decreasing latency. By almost doubling the channel width from Wi-Fi 6/6E 's 160 MHz to 320 MHz allowing higher data rates. By modifying the modulation rates to accomodate more bit, it switches from existing 1024-QAM to 4096-QAM.

It allows use of multiple frequency band for the first time in Wi-Fi technology, allowing access to 2.4 GHz, 5 GHz and 6 GHz bands at the same time. It increases number of spatial streams to accomodate 16x16 MIMO.

### Q7. Explain the concept of Multi-Link Operation (MLO) and its impact on throughput and latency.
Earlier, even though the Wi-Fi standards use multiple frequency bands, the Wi-Fi device is allowed to connect only to one of the available frequency bands. With Multi Link Operation, Wi-Fi connected devices can now aggregate multiple links to transmit and receive data in parallel. Aggregation allows the throughput to increase and dynamic selection of these links will ensure that devices face much lower latency

### Q8. What is the purpose of 802.11k and v, and how does it aid in roaming?
Both 802.11k and 802.11v are IEEE standards designed to enhance Wi-Fi client roaming, particularly in networks with multiple access points (APs), such as enterprise or mesh environments.

- 802.11k helps a client device find the best available AP to roam to by providing information about the surrounding network. When roaming conditions are detected, the current AP responds to a neighbor report request from the client with a list of nearby APs and their details (e.g., channel, signal strength). This allows the client to quickly scan only relevant channels rather than the entire spectrum, reducing roaming time and improving connection stability.

- 802.11v allows the network to proactively assist the client in making roaming decisions. It introduces BSS Transition Management, enabling the AP to suggest better candidate APs based on signal quality, AP load, or network policy. Although the final decision to roam rests with the client, 802.11v ensures that the client has the necessary guidance to make an optimal choice.
### Q9. Explain the concept of Fast BSS Transition (802.11r) and its benefit in mobile environments.
802.11r is a Wi-Fi standard designed to reduce the time taken by a client to switch between APs with its applications concentrated to VoIP, Video calls and Video streaming. When a client connects to a Wireless Network, it goes through a series of authentication steps and 4 way handshake. When a client initially connects to an AP, it undergoes a 4 way handshake but each time it roams and connects to a new AP, it needs to undergo the same series of steps. 802.11r reduces this time by sharing the information it used to connect to the client to the neighboring APs. This allows the client to switch instantly.

### Q10. How do 802.11k/v/r work together to provide seamless roaming in enterprise networks?
802.11k, 802.11v and 802.11r work hand in hand to porovide seamless roaming for Wi-Fi devices ensuring that handoff between two clients are smooth.
- 802.11k provides neighbour reports giving the client information about nearby APs.
- 802.11v guides the client by suggesting the most optimal AP based on its capabilities advertised.
- While 802.11k and 802.11v allows a client to choose the best nearby AP, 802.11r standard ensures that the time taken for handoff is very short by pre authenticating devices to APs.
