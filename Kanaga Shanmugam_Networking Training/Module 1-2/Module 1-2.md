# Module 1 - Communication Fundamentals
# Module 2 - Evolution of Computer Networks

### Q1. Consider a case, a folder has multiple files and how would copy it to destination machine path (Try using SCP, cp options in Linux)
The `scp` command stands for **_Secure Copy Protocol_** which is an efficient method to copy files from one host to another in a network. Using the general syntax of 
```
$ scp [options] source destination
```
We transfer a file from the kali user to hadoop user using the below command which performs the copy operation post authentication
```
scp understanding_ping.txt hadoop@kali:/home/hadoop/
```

![Screenshot (720)](https://github.com/user-attachments/assets/598a2f76-ca88-4ea3-90a1-30dc78e4e50c)

### Q2. Host a FTP and SFTP server and try PUT and GET operations.
FTP stands for _**File Transfer Protocol**_ and SFTP stands for _**Secure File Transfer Protocol**_ which is a more secure method of performing the latter command which is used to transfer file over a network in a fast and secure manner.
In order to host a FTP server in Kali Linux, the `vsftpd` package needs to be installed and configured.

**Installation and Configuration Commands:**
```
apt-get update
apt-get install vsftpd
cd /etc/
vim vsftpd.conf
->local_enable=YES
->write_enable=YES
->chroot_local_user=YES
->chroot_list_enable=YES
->chroot_list_file=/etc/vsftpd.chroot_list
touch vsftpd.chroot_list(To add list of users having access to the server)
```
![Screenshot (721)](https://github.com/user-attachments/assets/06245a98-4f80-415e-b7fc-9141da12e66c)

In this example,we have provided the **hadoop** user with access to the server.In order to start the server, the following command has to be given which starts the server post authentication
```
service vsftpd start
```
![Screenshot (724)](https://github.com/user-attachments/assets/5c48cdc5-4e90-4319-80ec-9a645231d6a5)
We can access the server using the command `ftp <ip_address>`. Server can be accessed using normal linux commands.In order to get a file from the server, `get filename` is used which saves the file from the server to the present working directory

![Screenshot (726)](https://github.com/user-attachments/assets/9516fd59-c7e8-4864-8f1d-455e4830b3d2)
![Screenshot (727)](https://github.com/user-attachments/assets/a9d92fb2-fa55-43ec-af97-f7ca111c0e47)

Alternatively, the server can also be accessed from Windows by connecting to `ftp://ip_address` from the File Explorer and files from Windows can be put into the server

![Screenshot (728)](https://github.com/user-attachments/assets/631df8c5-939b-44ac-8f45-2036dba3d5b9)
![Screenshot (729)](https://github.com/user-attachments/assets/f1acbc68-f52d-42d9-93bb-0783837f07b5)

**USING SFTP :**

The FTP server can be connected using SFTP by using the command `sftp username@ip_address`.  Files can be uploaded into the server using the command `put source destination`

![Screenshot (730)](https://github.com/user-attachments/assets/4324d8ca-5c65-4e23-bc0a-e59eb51d764a)

### Q3. Explore with Wireshark/TCP-dump/cisco packet tracer tools and learn about packets filters.
Wireshark is a packet sniffing tool which is predominantly used for networking monitoring. Since it is a GUI based tool, packets can be easily sniffed.

![Screenshot (731)](https://github.com/user-attachments/assets/566a5b73-3ab8-43e8-95be-0cfc2e019ee1)
The sniffed packets can be analyzed and filtered by using common filtering options like host,port,protocol. Like in the below example, the packets can be sniffed by using protocol name like `arp` and ip address like `ip.addr == 192.168.1.11`

![Screenshot (732)](https://github.com/user-attachments/assets/3d67bfb8-889f-4a09-8749-662ff2ee6390)
![Screenshot (733)](https://github.com/user-attachments/assets/99967c7a-be59-401f-ba1e-a2d815dabb77)

### Q4. Understand linux utility commands like - ping, arp (Understand each params from ifconfig output).
Ping is a command which is used to check network connectivity. This command can be modified using various options like -c,-q. The -c option is used to limit the packets.

![Screenshot (717)](https://github.com/user-attachments/assets/12db9327-9821-4f4f-ab29-9a9073a0f9a8)

ARP command stands for Address Resolution Protocol which is used to identify the MAC address of a host computer that is connected in the same network as the source. By sending out packets targetting the Destination IP address and flooding it over the network, the source computer gets to know the MAC address of the destination computer.

![Screenshot (718)](https://github.com/user-attachments/assets/aea86bf0-2a1a-46dd-b6ac-925f482934a3)

### Q5. Understand what happens when duplicate IPs configured in a network.
When duplicate IPs are configured in a network, it leads to a conflict scenario. This leads to connectivity issues where a packet that is intended to a specific IP will have 2 or more possible destination to send the packet to and it does not know where to send the packet to. This issue commonly arises in the cases of Static IP configuration. This scenario leads to instability in ARP tables and routing issues.
The solution to this issue is using DHCP for automatic IP configuration or simply restarting the device.

### Q6. Understand how to access remote system using (VNC viewer, Anydesk, teamviewer and remote desktop connections)
While all of the above mentioned softwares are used for accessing a remote machine from the host machine, Team Viewer is a popular remote access tool that provides a simple setup and secure connections. By installing the software on both ends(Host and Remote System) and connecting to the remote system using remote system's ID and Password, the session is started. Team Viewer is Cross Platform Compatible and can be supported over various devices and operating systems.

AnyDesk is also another popular remote access software which is lightweight and has encryption. Similar to TeamViewer's installation steps, AnyDesk also connects to the remote machine but with using a numerical code instead of ID and Password. 

### Q7. How to check your default gateway is reachable or not and understand about default gateway.
In order to check the default gateway of a network, the `ip route` command can be used. With the help of `awk` command, the default gateway is retreived and its connectivity can be checked using the ping command.
A gateway is a device that acts as a bridge between two different networks. It is the device to which packets are sent to when the destination address is not directly present in the network's routing table. 

![Screenshot (734)](https://github.com/user-attachments/assets/bbdf9644-248f-4bb8-999b-ac1e341a0848)

### Q8. Check iwconfig/ifconfig to understand in detail about network interfaces (check about interface speed, MTU and other parameters).
The ifconfig command is used to display and configure all network interfaces in a system.But in use, ifconfig command is commonly used to obtain the IP address of the system. In addition to the IP address, it provides us with lot of information.

**MTU :** Stands for Maximum Transmission Unit which is the largest size of a single packet. By default, it is set to 1500(bytes). The MTU value can be changed however it should be set to a optimum level in order to avoid segmentation or overheads.

**FLAGS :** There are other important flags which denote whether is interface is _up or down_,_Supports Broadcast or not_,_Is Running or not_,_Supports Multicast or Not_.

**OTHER ADDRESSES :** The command produces MAC address, IPv6 address and Broadcast Address in addition to the IPv4 address.
In order to obtain the speed of the interface, the `ethtool interface_name` command is used.

![Screenshot (735)](https://github.com/user-attachments/assets/5851cedc-0bbd-4f9f-a58d-cb40fe5550c5)

### Q9. Log in to your home router's web interface (usually at 192.168.1.1 or 192.168.0.1) and check the connected devices list.
By logging into the home router's web interface using username and password, various statistics about the network can be studied. The Web Interface provides us with the information about the number of devices connected and the names of those devices. Moreover, the IP address and the bandwidth used by each device can be seen under the statistics tab of the interface.

![Screenshot (715)](https://github.com/user-attachments/assets/17071791-fdf1-4999-aa4e-bb32e15b59a9)

### Q10. Explain how a DHCP server assigns IP addresses to devices in your network.
DHCP stands for Dynamic Host Configuration Protocol, as the name stands for, it automatically assigns IP addresses to the host systems thereby eliminating the need for Static/Manual IP configuration. Using the DORA proccess, a host is assigned with an IP address.

**Discover :** The client sends a broadcast message by sending DHCPDISCOVER message to discover the server.

**Offer :** The server once it receives the DHCPDISCOVER message, checks it IP Address table to see if it can accomodate the client and if it can, it sends DHCPOFFER message

**Request :** The client receiving the DHCPOFFER message, chooses one offer and sends a DHCPREQUEST indicating the IP Address it wants.

**Acknowledgement :** After accepting the DHCPREQUEST and assigning the IP Address, the server sends a DHCPACK to acknowledge and confirm assignment of IP.

### Q11. Using a terminal, connect to a remote machine via SSH and telnet.
SSH stands for Secure Shell which is used for securely accessing and managing a remote device. In the below example, ssh is used in windows machine to access the linux system in the Virtual Box. By accessing the IP address of the linux system, and using the command `ssh <ip_address>`, the windows system can remotely access the linux system post authentication. In order to quit/exit the session, the exit command is used.

![Screenshot (737)](https://github.com/user-attachments/assets/20c170d3-8ad3-491d-9b7a-b9ee200abacb)
