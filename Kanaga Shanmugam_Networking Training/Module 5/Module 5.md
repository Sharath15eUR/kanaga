# Module 5 - Layer 3 – Session 1
### Q1. Capture and analyze ARP packets using Wireshark. Inspect the ARP request and reply frames, and discuss the role of the sender's IP and MAC address in these packets.

ARP stands for Address Resolution Protocol whose primary function is to retrieve MAC address of a device given its IP address. So a ARP request is sent through the network having destination MAC address set to 00:00:00:00:00:00.

![image](https://github.com/user-attachments/assets/004b6977-0b58-4e33-b88a-6f573adcb887)

When the host having the specified MAC address receives the request, it responds to the request. The host which initiated the ARP request learns the desired host's MAC address by analyzing the Source MAC address field in the reply packet.

![image](https://github.com/user-attachments/assets/f928082e-71df-4eeb-aa72-8ba2f40a809a)

### Q2. Using Packet Tracer, simulate an ARP spoofing attack. Analyze the behavior of devices on the network when they receive a malicious ARP response.

ARP spoofing refers to the attack where a malicious host sends falsified ARP. This can be simulated using Packet Tracer by setting up a simple LAN network consisting of 4 End devices (having IP address in the range of 192.168.1.2 - 192.168.1.5) connected to a switch which is in turn connected to a router(IP : 192.168.1.1). 

ARP spoofing can be carried out by modifying the MAC address of the router which communicates to other networks with the MAC address of the host performing ARP spoofing. Below is the MAC address of the all devices connected in the network before it is spoofed.

![Screenshot (770)](https://github.com/user-attachments/assets/9794e825-c409-442d-b384-dc63b7bc0d4f)

Now the MAC address of the router is replaced a duplicate MAC address. The mac address table of all devices post spoofing is.

![Screenshot (771)](https://github.com/user-attachments/assets/4bea71a5-c234-42b5-8a07-12f3af6a83ed)

This creates a problem since any message/packet(s) intended to the router can be sniffed by the host with the same MAC address of the router.

![image](https://github.com/user-attachments/assets/f93b50a4-e123-41da-b352-9f2e90e867ee)

### Q3. Manually configure static IPs on the client devices(like Pc or your mobile phone) and verify connectivity using ping.

IP address on a client device can be configured in two ways either statically or using DHCP. Below is configuration of a Mobile Phone manually.

**Before Configuration :**

![WhatsApp Image 2025-03-09 at 14 25 14](https://github.com/user-attachments/assets/60491091-a15f-45a1-9813-fd40fe668174)

**After Configuration :**

![WhatsApp Image 2025-03-09 at 14 25 13](https://github.com/user-attachments/assets/32dd6453-f6c4-484c-8d5d-e400685e28e9)

**Verifying Connectivity:**

![Screenshot (769)](https://github.com/user-attachments/assets/37789fe6-4fa8-4564-b8da-209b3a9275d1)

### Q4. Use Wireshark to capture DHCP Discover, Offer, Request, and Acknowledge messages and explain the process.
DHCP follows an approach called DORA - Discover, Offer, Request and Acknowledge. Analysing the wireshark packet capture will give more details about the mentioned processes.

**DISCOVER :** This is a broadcast message sent from the client device to find the DHCP server. As it can be seen, the source IP address is not yet assigned (0.0.0.0) and the destination IP is broadcast address(255.255.255.0)

![image](https://github.com/user-attachments/assets/06db414c-9d23-4bb4-b7fa-5b3f429d95fb)

**OFFER :** In this process, the DHCP server offers an IP address to the client device.

![image](https://github.com/user-attachments/assets/bde7f352-af0d-440b-9c3b-94c9edebaf0e)

**REQUEST :** Out of the given IP address options, the client requests for an IP address to the server. The IP of the device is not yet assigned as it can be seen in the source IP address which still remains as 0.0.0.0

![image](https://github.com/user-attachments/assets/2ed3a2bb-445b-4843-a0d4-76d5987f2c7d)

**ACKNOWLEDGE :** The server offers the client with the IP address and presents some additional details such as **_Lease Time, Renewal Time and Rebinding Time_**.

![image](https://github.com/user-attachments/assets/ea67e6bd-6ac8-40dc-b181-739799525f29)

### Q5. Given an IP address range of 192.168.1.0/24, divide the network into 4 subnets. Task: Manually calculate the new subnet mask and the range of valid IP addresses for each subnet. Assign IP addresses from these subnets to devices in Cisco Packet Tracer and verify connectivity using ping between them.

**Given IP address range :** 192.168.1.0/24. In the given IP address range, the host is identified by the last 8 bits of the IP address. 

The given questions asks us to divide the network into 4 subnets. Therefore, additional 2 bits (since 2^2 =4). Therefore the IP addresses network involving subnets will be represented by **192.168.1.0/26**. Which leaves the hosts to be identified using 5 bits. There 2^5=32 hosts are possible out of which first and last IP addresses are reserved for Network Address and Broadcast Address respectively.

**VALID IP ADDRESSES FOR EACH SUBNET :**

| Subnet |	Network Address	| Usable IP Range	| Broadcast Address |
| :---:        |    :----:   |          :---: | :---: |
|**Subnet 1**	| 192.168.1.0/26	| 192.168.1.1 – 192.168.1.62	| 192.168.1.63 |
|**Subnet 2**	| 192.168.1.64/26	| 192.168.1.65 – 192.168.1.126	| 192.168.1.127 |
|**Subnet 3**	| 192.168.1.128/26 |	192.168.1.129 – 192.168.1.190	| 192.168.1.191 |
|**Subnet 4**	| 192.168.1.192/26 |	192.168.1.193 – 192.168.1.254 |	192.168.1.255 |

The above network can be simulated in Packet Tracer. For sake of simplicity, we have restricted the number of hosts to 3 in each subnet. All the hosts are connected to a switch which is in turn connected to a router. The router should be configured in order to enable packet flow within network.

**ROUTER CONFIGRUATION :** Go inside the CLI of the router and type the below commands in order:
```
configure terminal
interface <interface_name>
no shutdown
exit
```
Perform the above operations on all connected interfaces.

![Screenshot (772)](https://github.com/user-attachments/assets/0f4536aa-375c-492f-9e0a-43c0f871b605)

**NETWORK :**

![Screenshot (773)](https://github.com/user-attachments/assets/f6de52e0-e45b-4c8c-88d6-a863b64c31de)

**VERIFIYING CONNECTIVITY USING PING :** All the hosts in the network must be configured to their respective IP address in the appropriate range as specified above and the default gateway should by one of the IP address in the usable IP address range. It is the IP address of the router connnected to that particular interface.

![Screenshot (775)](https://github.com/user-attachments/assets/7119831b-1411-4629-a91a-79d07d364b2a)

### Q6. You are given three IP addresses: 10.1.1.1, 172.16.5.10, and 192.168.1.5. Identify the class of each IP address (Class A, B, or C). What is the default subnet mask for each class? Provide the range of IP addresses for each class.

The given IP addresses belong to Classes A,B and C. The detailed information is tabulated below.

| Given IP address |	Class	| IP Address Range Class | Subnet Mask |
| :---:        |    :----:   |          :---: | :---: |
| 10.1.1.1 | **Class A** | **1.0.0.0 - 126.255.255.255** | 255.0.0.0|
| 172.16.5.10 | **Class B** | **128.0.0.0 - 191.255.255.255** | 255.255.0.0|
| 192.168.1.5 | **Class C** | **192.0.0.0 - 223.255.255.255** | 255.255.255.0|

### Q7. In Cisco Packet Tracer, create a small network with multiple devices (e.g., 2 PCs and a router). Use private IP addresses (e.g., 192.168.1.x) on the PCs and configure the router to perform NAT to allow the PCs to access the internet. Test the NAT configuration by pinging an external IP address from the PCs and capture the traffic using Wireshark. What is the source IP address before and after NAT?

A small network is configured by connecting two hosts PCs (with IP addresses 192.168.1.10 and 192.168.1.20) to a switch which is in turn connected to a router which connects the external network, a server (with IP address 200.0.0.2) in this case. Router plays a key role by connecting the private network and public network. It uses Network Address Translation using IP address 192.168.1.1 for the private network and 200.0.0.1 for the public network. So the packets flowing from the host PC will have a private IP address in the range of 192.168.1.x and when it passes through the router, it translates into a public IP 200.0.0.1. 

In order to perform this, the router must be configured by performing the following commands in the CLI of router:
```
configure terminal

interface GigabitEthernet0/0
ip address 192.168.1.1 255.255.255.0
no shutdown
ip nat inside
exit

interface GigabitEthernet0/1
ip address 200.0.0.1 255.255.0.0
no shutdown
ip nat outside
exit

access-list 1 permit 192.168.1.0 0.0.0.255

ip nat inside source list 1 interface GigabitEthernet0/1 overload
exit
```

![Screenshot (776)](https://github.com/user-attachments/assets/92b331e8-41cd-4916-a970-653c43b31877)

Connectivity can be checked using ping command.

![Screenshot (777)](https://github.com/user-attachments/assets/77b6f16a-1247-4409-bb0c-5e1c9c851fbc)

The NAT address translation can viewed by typing `show ip nat translations` in the CLI of router.

![Screenshot (778)](https://github.com/user-attachments/assets/c1545530-6739-485d-a9b0-477e99060b83)

**SNIFFING PACKETS USING PACKET TRACER :**

The packets can be captured/analyzed using the simulation mode of packet tracer. Host PC0 is selected as source and server is selected as destination. The PDU details at the Router will explain the address translation process.The inbound PDU Details contain source IP address as **192.168.1.10** which is the IP of PC0.

![Screenshot (779)](https://github.com/user-attachments/assets/93346f93-ccc8-4d9f-bba4-c718e5f35597)

 But when it passes to the external network, it changes to the IP to a public IP. As seen in the outbound PDU Details, the earlier source IP address is changed from **192.168.1.10** to **200.0.0.1**.

 ![Screenshot (780)](https://github.com/user-attachments/assets/8900f3aa-e805-47cf-974b-7f27bcef63c3)
