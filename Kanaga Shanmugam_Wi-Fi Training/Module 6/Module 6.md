# Module 6 - Security in Wi-Fi

### Q1. What are the pillars of Wi-Fi security?
There are three basic pillars of Wi-Fi security commonly known as CIA triad. These are:
- **Confidentiality :** Confidentiality is the property pertaining to the message not being able to be read by users other than the intended recipient. Wi-Fi security ensures that message passed over the Wireless medium are encrypted such that only the intended recipient can decrypt the message. 

- **Authentication :** Authentication ensures that messages are sent to the right user and not any other user.

- **Integrity :** Integrity is the property of message being delivered unchanged. Integrity ensures that the message a recipient receives is the same message the sender has sent and the message is not altered by any external source during its transmission.
  
### Q2. Explain the difference between authentication and encryption in WiFi security.
| **AUTHENTICATION** | **ENCRYPTION** |
|       :---:        |      :---:     |
| Process of verifying users in a communication | Process of converting Plain text into Cipher text which cannot be read without decrypting it |
| Ensures that only authorized users or devices can access the network | Ensures that data transmitted over the network is unreadable to unauthorized parties |
| Involves checking credentials for users and checks if they are correct | Involves scrambling original data into a unreadable form using keys |
| It is the very first step in Wi-Fi connection setup | Usually occurs when a device is connected to a network and starts transmitting data |

### Q3. Explain the differences between WEP, WPA, WPA2, and WPAЗ.
**WEP :**
- Stands for Wireless Equivalent Privacy which was introduced to provide same level of security to Wi-Fi as given for Wired Communication and hence the name.
- It used RC4 encryption which was a very weak encryption protocol
- Used 24 bit random Initialization Vector along with 40 or 104 bit Key(constant key)
- Since it used the same base key for all communication, larger sample spaces can lead to the base key to be exposed. Hence this Wi-Fi security protocol was considered to be weak.

**WPA :**
- Stands for Wireless Protoced Access
- It was introduced to overcome the shortcomings of WEP by introducing unique per packet encryption keys.
- It uses reciever's MAC address to generate the keys and uses MIC to check the message's integrity.
- Uses TKIP (Temporal Key Integrity Protocol) for stronger encryption than WEP. But they are still prone to Brute Force Attacks.

**WPA 2:**
- This was enhanced version of the WPA protocol which uses advanced encryption methods like AES algorithm.
- Packet Number is used to prevent replay attacks and CCM ensures user of new temporal key for each session.
- APs can support WPA+WPA2 modes for backward compatibility.
- However unlike WPA, WPA2 needs hardware supports and weaker passwords were prone to attacks.

**WPA 3:**
- This was an enhancement to WPA2 where 128/192/256-bit keys are used for data encryption.
- One main improvement was to encrypt Management Frames in addition to encrypting Data Frames.
- Replaces use of Pre Shared Keys with Simultaneous Authentication of Equals.
### Q4. Why is WEP considered insecure compared to WPA2 or WPA3?
WEP is considered insecure to WPA2 and WPA3 as the encryption methods and security promised in WEP is very low in comparison to WPA2 or WPA3. Since it was the very first standard to be introduced in Wi-Fi security, it main goal was to ensure security to messages and it did not use the most complex methods to ensure security. It used a weak encryption mechanism like RC4 and used the same base key along with a random 24 bit Initialization Vector. WPA2 and WPA3 by using much stronger encryption mechanisms like AES, Secure Hash Algorithm etc ensure that messages sent over the wireless medium cannot be easily sniffed by others.

### Q5. Why was WPA2 introduced?
WPA2 was introduced to address the shortcomings of WPA. While WPA promised better security than WEP, it still had its shortcomings. It still used RC4 cipher as its encryption algorithm and had Message Integrity Check as its hashing algorithm. By providing a much stronger and complex encryption algorithm like AES, WPA2 promised better security than WPA. It also replaced Cipher Block Chaining Message Authentication Code as its Hashing Algorithm and moved away from MIC.

### Q6. What is the role of the Pairwise Master Key (PMK) in the 4-way handshake?
The Pairwise Master Key plays a vital role in the 4-way handshake mechanism. Being derived from the Pre-Shared Key or Authentication server, it does not get involved in the directly in the handshake but it generates keys which are used in the handshake. Using PMK, the Pairwise Transient Key(PTK) is generated at the client side which is later used to generate GTK. By not actually sending keys over the medium, PMK ensures session keys are generated in a secure way which enables communication between the authenticator and the supplicant.

### Q7. How does the 4-way handshake ensure mutual authentication between the client and the access point?
4-way Handshake ensures mutual authentication between the client and the access point by a series of handshakes:
1. The Access Point initiates the communication by sending its ANonce to the Supplicant. Supplicant uses this ANonce number to generate the PTK.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `PTK = PRF (PMK + ANonce + SNonce + MAC(Authenticator) + MAC(Supplicant)`

2. The supplicant then unicasts its SNonce number to the Access Point along with a MIC. Then Access Point generates the PTK and verifies its correctness using MIC.
3. The AP generates GTK which can be used for multicast and broadcast messages and send it to the Client.
4. Now both ends have GTK as well as PTK installed in them. The client acknowledges this by sending out an acknowledgement to the AP.

### Q8. What will happen if we put a wrong passphrase during a 4Way handshake?
If a wrong passphrase has been sent during a 4-Way handshake, the authenication fails and the client will not be able to connect to the Wi-Fi network. PMK is the primary key needed to generate subsequent keys and PMK is generated with the help of Pre Shared Key which is nothing but the passphrase. When the client enters a wrong passphrase,
1. The AP initiates the communication by sending its ANonce to the Client which it uses to generate the PTK. 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `PTK(Client) = PRF (PMK (Wrong PMK Generated) + ANonce + SNonce + MAC(Authenticator) + MAC(Supplicant)`

2. The wrong PTK is generated as an effect of Wrong PMK being generated. The client sends its SNonce number to the AP. AP uses this to generate the PTK.

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; `PTK(AP) = PRF (PMK + ANonce + SNonce + MAC(Authenticator) + MAC(Supplicant)`

After generating the PTK it compares with the message it received by looking at MIC and it observes that PTK generated by AP is not matching the PTK generated by Client ie. PTK(AP) != PTK(Client).

Hence the connection is teared down and authentication fails at Second Handshake.


### Q9. What problem does 802.1X solve in a network?
802.1X solves the problem of unauthorized network access by providing centralized authentication network by using RADIUS server for authentication and taking away authentication overhead from the Access Points. This enhances network security, supports flexible access control for different users (including guests), and protects sensitive data through encrypted authentication processes. It is especially important for large networks like Enterprise Networks.

### Q10. How does 802.1X enhance security over wireless networks?
802.1X enhances security over wireless networks by ensuring that only authenticated devices or users can access the network. The client must establish a new connection to the Authenticator. The Authenticator sends Request Identity to which the client responds with Reponse Identity. The Authenticator forwards this response as a RADIUS Access Request to the Authentication Server. The Authenticator passes the challenge request server sends to supplicant and its response back to the server.The authentication server, Accepts or rejects the connection with respect to the challenge response.
