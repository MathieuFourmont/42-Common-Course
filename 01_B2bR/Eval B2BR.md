<u>Eval B2BR</u>

1. Signature

   Powershell:

   `cd C:\Users\mathi\VirtualBox VMs\Born2beRoot\`

   `certUtil -hashfile Born2beRoot.vdi sha1 > signature1.txt`

   `diff (cat signature.txt) (cat signature1.txt)`

2. How VM works

   VMs is using the virtualization process, which means creating a software-based, or "virtual" version of a computer, which dedicated amount of CPU, memory and storage that are "borrowed" from a physical host computer.

   In that way we can have a separated system with its own OS, meaning to run Debian GNU/Linux on Windows for example.

3. Why choosing Debian?

   As I started more or less to use a VM with this project, Debian seemed to be easier to install and configure than CentOS for the beginners. Also I'm already using Ubuntu and Kali which are Debian-based.

4. Diff between CentOS and Debian

   CentOS and Debian are both Linux distributions.

   CentOS is a free downstream rebuild of the commercial Red Hat Enterprise Linux distribution (based on their open source code) while Debian is the free upstream distribution that is the base for other distributions.

5. Purpose of VMs

   The main purpose is to operate multiple OS at the same time, from the same piece of hardware. Without virtualization, operating multiple systems, like Windows ans Linux, would require 2 different physical units. 

6. Difference between aptitude and apt

   Aptitude is a high-level package manager while APT is lower-level package manager which can be used by other higher-level package managers.
   Aptitude is text-based but user friendly.
   Apt-get is command-line, you have to know the exact name of the package.

7. What is APPArmor

   It is a Linux kernel security module that allows the system admin to restrict programs' capabilities with per-program profiles

   Profiles can allow capabilities like network access, raw socket access, and the permission to read, write, or execute files on matching paths.

   `sudo aa-status`

8. Check UFW

   `sudo ufw status`

9. Check SSH

   `sudo service ssh status`

10. Check OS

    `cat /etc/os-release`

11. Check groups

    `groups mmaxime-`

12. Password policy

    `sudo vi /etc/login.defs` = expiry

    `sudo vi /etc/pam.d/common-password` = rules

13. Create new user

    `sudo adduser test`

    `sudo userdel test`

14. Create new group and assign new user

    `sudo addgroup evaluating`

    `sudo adduser test evaluating`

    `groups test`

15. Advantages of the password policy

    To implement this policy helps to enforce the use of complex and unique passwords which are harder to hack. More we have different requirements, higher is the number of possible combinations.

    By limiting the number of attemps, the password can't be discover using brut force hacking.

    The main problem of this policy is, that is it is creating complex passwords, harder to remember for users. Which can write somewhere on a paper or another file easy to hack.

16. Check hostname

    `hostname`

17. Modify the hostname

    `sudo adduser test sudo`

    `su test`

    `sudo vi /etc/hostname` = change to test42

    `sudo reboot`

18. Restaure original hostname

    `sudo vi /etc/hostname` = change to mmaxime-42

    `sudo reboot`

19. View partition

    `lsblk`

20. How LVM works

    LVM = Logical Volume Management

    It allows to allocate storage/memory in a flexible way to the applications and users

    The storage volumes created with LVM can be resized and moved almost at will.

21. Check sudo

    `dpkg -l | grep sudo`

22. Assign user to sudo

    `sudo adduser test sudo`

23. Value and operation of sudo

    Sudo stands for SuperUser DO and is used to access restricted files and operations. By default, Linux restricts access to certain parts of the system preventing sensitive files from being compromised.

    The sudo command temporarily elevates privileges allowing users to complete sensitive tasks without logging in as the root user.

24. Sudo rules

    `sudo vi /etc/sudoers.d/config_sudo`

25. Check /var/log/sudo if it exists

    `sudo ls /var/log/sudo`

    Has file `seq` = last sudo command

    `sudo ls /var/log/sudo/00/00` = to see the history

    `sudo ls /var/log/sudo/00/00` = to see the new folder created by using the sudo command again

26. Check ufw

    `dpkg -l | grep ufw` = correctly installed

    `sudo ufw status`

27. What is ufw and value of using it

    UFW = Uncomplicated FireWall

    It is a program for managing a netfilter firewall designed to be easy to use. It uses a command-line interface consisting of a small number of simple commands, and uses iptables for configuration.

    UFW aims to provide an easy to use interface for people unfamiliar with firewall concepts, while at the same time simplifies complicated iptables commands to help an administrator who knows what he or she is doing.

28. Active rule 4242

    `sudo ufw status | grep 4242`

29. Add port 8080

    `sudo ufw allow 8080`

    `sudo ufw status`

30. Delete the rule

    `sudo ufw status numbered`

    `sudo ufw delete <number>`

31. Check SSH

    `dpkg -l | grep openssh-server` = correctly installed

    `sudo service ssh status`

32. What is SSH and value of using it

    SSH = Secure SHell

    It's a cryptographic network protocol for operating network services securely over an unsecured network. It provides a secure channel over an unsecured network by using a client/server architecture which allows to users (SSH client) to connect remotly to host systems (SSH server).

33. Check SSH port 4242

    `sudo service ssh | grep listening`

    or

    `sudo vi /etc/ssh/sshd_config` and `sudo vi /etc/ssh/ssh_config`

34. Login with SSH from hostmachine

    In Ubuntu:

    `ssh mmaxime@localhost -p 4242`

    `login root` => to try to connect to root 
    
35. How script monitoring works

    `cd /home`

    `sudo vi monitoring.sh` 

36. What cron is

    This is a job scheduler which allows to manage the recurring tasks (hourly, daily, monthly, ...)

37. Modify cron every 10 minutes

    `sudo crontab -e`

    */10 * * * * /home/monitoring.sh = every 10 minutes

    */1 * * * * /home/monitoring.sh = every minute

38. Make the script stop running after reboot without modifying it

    `sudo crontab -e`

    Delete the lines from @reboot
