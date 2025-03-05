# Module 3 - Local Area Network – Layer 2 Protocols and Ethernet
# Module 4 - Switching


### Q1. Simulate a small network with switches and multiple devices. Use ping to generate traffic and observe the MAC address table of the switch. Capture packets using Wireshark to analyze Ethernet frames and MAC addressing.


A small network consisting of Personal Computers/Laptops and switches can be simulated using either Cisco Packet Tracer or Graphical Network Simulator-3.

**USING CISCO PACKET TRACER :**

The requirement is to simulate a simple network. In order to perform this in Cisco Packet Tracer, choose appropriate _End Devices_ from the End Devices Tab and place a Switch of option from the _Networking Devices_ tab and connect the end devices to the switch using Copper Straight Through Cables.

![Screenshot (740)](https://github.com/user-attachments/assets/d8b7b890-3157-4dc2-9195-ef0a87582ea1)

IP address of the end devices can be assigned statically changing the address under _Config_ tab.

![Screenshot (744)](https://github.com/user-attachments/assets/dc2d7374-bacb-45d2-bf95-81c1d337e9eb)
![Screenshot (745)](https://github.com/user-attachments/assets/70736b61-5673-44a0-aa6b-bb03718f65de)

A simple ping will help the switch understand the MAC addresses of the PCs and the port it is connected to.The mac address table of the switched can be viewed by type `show mac address-table` under the CLI tab of the switch.

![Screenshot (742)](https://github.com/user-attachments/assets/f5421729-83d2-4b51-a0b7-ab2c638ce7fb)
![Screenshot (743)](https://github.com/user-attachments/assets/c281007a-1d15-4f72-b2c9-90c67f5bd9fd)

However, since we cannot sniff the packets using Wireshark in Cisco Packet Tracer, we use GNS3.

**USING GNS3 :**

GNS3 is a Network Simulation Tool similar to Cisco Packet Tracer. A simple network can be constructed by choosing VPCs from End Devices and connecting them to Ethernet Switch. The IP address of the VPCs can be configured using the command `ip <ip_address> <subnet_mask>` respectively in their consoles.

![Screenshot (759)](https://github.com/user-attachments/assets/7cff0c08-3e02-47a1-94e0-3333bbe91e0a)
![Screenshot (760)](https://github.com/user-attachments/assets/07b7bbd1-4c10-4b1f-b747-e980ac716a94)

Established connection can be verified using a ping command.

![Screenshot (761)](https://github.com/user-attachments/assets/c54c21ef-59da-4a88-8be5-8a003f5aaa6c)

In order analyse the packets using wireshark, the _Start Capture_ option should be selected in the link connecting the switch and PC's link that needs to be sniffed.

![Screenshot (762)](https://github.com/user-attachments/assets/aed6e700-9a71-4ea4-bd06-a63d9a9ba80b)
![Screenshot (763)](https://github.com/user-attachments/assets/20567752-f95b-4714-9cdb-0bc1379a86e0)

A `ping <ip_address> -t` command triggers a series of ICMP packets that can be sniffed and analysed using Wireshark.

![Screenshot (765)](https://github.com/user-attachments/assets/e5342474-7d98-4302-9dfb-0ae3d1eb340d)


### Q2. Capture and analyze Ethernet frames using Wireshark. Inspect the structure of the frame, including destination and source MAC addresses, Ethertype, payload, and FCS.


Using the packets captured during the above  `ping` command, the following can be observed :

**FRAME <frame_number>:** This procotol dissector represents overall packet and its size. It contains details like Frame Number, Frame Length,Capture Length, Protocols in the Frame, Arrival Time.

![image](https://github.com/user-attachments/assets/e151bcae-5f8c-444f-a9fb-a72cde4ec59e)


**ETHERNET II :** This protocol dissector provides information such as the Source and Destination MAC address and the version of IP used in the layer above it(Network Layer) and appropriate hex number(0x0800 for IPv4). 

![image](https://github.com/user-attachments/assets/57f258e5-54b9-483c-abdb-e82d1afbae8b)

As seen in the image, the 7th and 8th bit of the 1st byte of MAC address represents the IG and LG bit.
The I/G bit is shorthand for Individual/Group which represents whether the message is unicast(if the bit is 0) or multicast(if the bit is 1) and the L/G bit is shorthand for Local/Global which represents whether the address is Globally Unique(if the bit is 0) or Locally Administered(if the bit is 1).

**INTERNET PROTOCOL VERSION :** This protocol dissector provides information about the network layer containing details such as Source IP address, Destination IP address, Time to Live, Protocol, Header checksum and many more details.

![image](https://github.com/user-attachments/assets/a1026702-e892-46ac-af6f-46e3cc95bcdc)

**PROTOCOL :** Here,the procotol dissector is _Internet Control Message Protocol_ since ICMP packet is sniffed, it contains details like Type, Checksum, Sequence Number and Request frame/Response frame.

![image](https://github.com/user-attachments/assets/1497ebd9-3d4f-447e-a43e-f8777f457d87)


Analysing an HTTP packet:

![image](https://github.com/user-attachments/assets/95621cb2-ab89-41fa-bc0d-4c221dab888e)

The sniffed packets will have similar protocol dissectors for layers 1-3 but will differ in layers after that. For HTTP:

**PROTOCOL :** Earlier ping command generated ICMP protocol packets, but HTTP involves TCP protocol. The fields in TCP protocol dissector contain various informations like Source Port,Destination Port(usually 80 for HTTP), Sequence number, Acknowledgement Number, Timestamps, SEQ/ACK analysis and many more important fields.

![image](https://github.com/user-attachments/assets/e69a33df-0b30-47cd-8f8d-46e8c1822820)

**HYPERTEXT TRANSFER PROTOCOL :** This protocol dissector contains information specific to HTTP request and response and contains all related headers and information like GET/POST, Content Length, Type of encoding etc.

![image](https://github.com/user-attachments/assets/2631847b-ab1e-46c2-8726-5d108e66919d)


### Q3. Configure static IP addresses, modify MAC addresses, and verify network connectivity using ping and ifconfig commands.


Using the same network configuration used in [Q1](https://github.com/pkanagashanmugam/Networking-Training/blob/main/Module%203-4.md#q1-simulate-a-small-network-with-switches-and-multiple-devices-use-ping-to-generate-traffic-and-observe-the-mac-address-table-of-the-switch-capture-packets-using-wireshark-to-analyze-ethernet-frames-and-mac-addressing) , IP addresses can be statically assigned and the assigned MAC addresses can be modified.
The initially assigned MAC addresses are :

![Screenshot (755)](https://github.com/user-attachments/assets/70aa0e1f-99ca-42b3-9a86-336ab647fc4f)

The MAC address of a system can be changed by modifying the MAC address under _Config_ tab.

![Screenshot (756)](https://github.com/user-attachments/assets/22e0063f-2274-488a-9b76-538be7130609)
![Screenshot (757)](https://github.com/user-attachments/assets/49de28f2-b742-4faa-9995-8c59d054f8bc)

The modified MAC addresses can be verified by viewing the MAC address table of the switch.

![Screenshot (758)](https://github.com/user-attachments/assets/21136a8a-c498-4cbe-8db1-16c343e203d1)


### Q4. Troubleshoot Ethernet Communication with ping and traceroute using Cisco Packet Tracer. Create a simple LAN setup with two Linux machines connected via a switch. Ping from one machine to the other. If it fails, use ifconfig to ensure the IP addresses are configured correctly. Use traceroute to identify where the packets are being dropped if the ping fails.


A simple network consisting of two PCs connected to a switch is simulated and IP addresses of the two PCs are statically assigned to 192.168.1.3 and 192.168.1.4 respectively. 

![Screenshot (749)](https://github.com/user-attachments/assets/4f85dff1-2fc7-4be3-8834-b6d475fa3c08)
![Screenshot (750)](https://github.com/user-attachments/assets/62cb4c5a-717d-4b8b-9fb6-b70cb02bad98)

Since the two available IP addresses are 192.168.1.3 and 192.168.1.4, if we ping to any other IP address, packets will be lost.

![Screenshot (751)](https://github.com/user-attachments/assets/1f045682-339b-4a31-a2a3-1e51f623ba5f)

In order to identify where the packets are dropped, an alternative command to `traceroute` in windows, `tracert` is used.Since there is no PC with the specified IP address, the packets never reach the intended PC.

![Screenshot (752)](https://github.com/user-attachments/assets/ddb3e195-16ab-4700-a1a2-ffd00c7a8d0a)

`ping` and `tracert` command is used to check connectivity between the rightly configured PC(192.168.1.4).

![Screenshot (754)](https://github.com/user-attachments/assets/1bf37307-dfc2-4ab1-b68e-e48601d7e83f)


### Q5. Research the Linux kernel's handling of Ethernet devices and network interfaces. Write a short report on how the Linux kernel supports Ethernet communication .


The linux kernel handles Ethernet devices and Network Interfaces using Ethernet Device Drivers. There are multiple linux device drivers for various types of ethernet cards/devices like **Linux kernel driver for Elastic Network Adapter (ENA) family, Altera Triple-Speed Ethernet MAC driver, Linux Base Driver for the Intel(R) PRO/100 Family of Adapters, Linux Base Driver for Intel(R) Ethernet Network Connection** and many more. The Ethernet devices in Linux are managed through the kernel's network device subsystem. The network device is allocated using `alloc_netdev_mqs()` function, registered to the network stack using `register_netdevice()` function and is removed from the network stack using ` unregister_netdev()` function. Using physical layer support, Network Interface Cards and Device Drivers, the linux kernel handles Ethernet Devices and network interfaces.

The network interface copies data to the kernel memory using DMA and triggers an interrupt. Interrupts are divided into Top half(Light weight) and Bottom half(This is where the action of scheduled interrupt is performed). Polling is another way by which the kernel learns the data. On a high level, the kernel with the help of sockets and buffers called socket buffers , find their way through the layers of the network stack inorder to communicate with the network interface


### Q6. Describe how you would configure a basic LAN interface using the ip command in Linux.


The `ip` command comes with various options with which a network can be configured. Below are the steps to configure a simple LAN interface using the options of `ip` command:

The below command is used to list all the network interfaces and their configured parameters. The output is similar to that produced by `ipconfig/ifconfig`. 
```
ip link show
```
In order to see a specific device/interface, `ip link show dev <interface_name>` can be used. 
To add a device to the list of interfaces and activate it,
```
sudo ip addr[ess] add <ip_address> dev <interface_name>
sudo ip link set <interface_name> up
```
The interface has been set up one more additional configuration needs to be done before completion of setup.
```
sudo ip route add default via <default_ip_address>
```
This is the default gateway through which packets flow from and to the interface. 

The setup can be verified by using the `ip link show` command already mentioned. The route taken by a packet can be seen using the `ip route` command.


### Q7. Use Linux to view the MAC address table of a switch (if using a Linux-based network switch). Use the bridge or ip link commands to inspect the MAC table and demonstrate a basic switch's operation.


The MAC address table is the forwarding table used by a switch in order to effectively learn and forward packets intended to a host by learning the port number it is connected to. The MAC address table can be learnt using the `bridge link` or `bridge fdb show` command.

The basic operation of a switch is to learn the port numbers to which different hosts and connected to and forward packets only to the intended hosts. Switch operates on layer 2 device and operates only on MAC addresses. It maintains a MAC address table for this purpose and updates the table frequently to stay updated.
