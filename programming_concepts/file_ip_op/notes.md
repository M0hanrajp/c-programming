### Notes.

- Operating systems, the software that powers your computer, rely on a crucial element known as the file system. Think of it as a virtual organizational tool that manages, stores, and retrieves your data efficiently.
```bash
$ df -Th
# EXT4 is the file system type used in linux machine (current)
Filesystem     Type     Size  Used Avail Use% Mounted on
none           overlay  3.8G     0  3.8G   0% /usr/lib/modules/5.15.167.4-microsoft-standard-WSL2
none           tmpfs    3.8G  4.0K  3.8G   1% /mnt/wsl
drivers        9p       476G   99G  378G  21% /usr/lib/wsl/drivers
/dev/sdc       ext4    1007G  5.3G  951G   1% /
none           tmpfs    3.8G  104K  3.8G   1% /mnt/wslg
none           overlay  3.8G     0  3.8G   0% /usr/lib/wsl/lib
rootfs         rootfs   3.7G  2.4M  3.7G   1% /init
none           tmpfs    3.8G  528K  3.8G   1% /run
none           tmpfs    3.8G     0  3.8G   0% /run/lock
none           tmpfs    3.8G     0  3.8G   0% /run/shm
tmpfs          tmpfs    4.0M     0  4.0M   0% /sys/fs/cgroup
none           overlay  3.8G  100K  3.8G   1% /mnt/wslg/versions.txt
none           overlay  3.8G  100K  3.8G   1% /mnt/wslg/doc
C:\            9p       476G   99G  378G  21% /mnt/c
$ lsblk -f
NAME FSTYPE FSVER LABEL UUID                                 FSAVAIL FSUSE% MOUNTPOINTS
sda  ext4   1.0
sdb  swap   1           390e0150-21c4-4f66-989f-8c4ff657808d                [SWAP]
sdc  ext4   1.0         c8f11315-c54c-447e-8ae8-196806471a6f  950.4G     1% /var/lib/docker
                                                                            /mnt/wslg/distro
                                                                            /
```
![Image](https://github.com/user-attachments/assets/82493809-b96b-4608-a8b8-d624f4719929)
```bash
$ sudo fdisk -l
Disk /dev/sda: 388.43 MiB, 407298048 bytes, 795504 sectors
Disk model: Virtual Disk
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes

Disk /dev/sdb: 2 GiB, 2147487744 bytes, 4194312 sectors
Disk model: Virtual Disk
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes

Disk /dev/sdc: 1 TiB, 1099511627776 bytes, 2147483648 sectors
Disk model: Virtual Disk
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 4096 bytes
I/O size (minimum/optimal): 4096 bytes / 4096 bytes
```
Summary of all the directory functionalities: https://en.wikipedia.org/wiki/Unix_filesystem#Conventional_directory_layout
![Image](https://github.com/user-attachments/assets/385e13e8-f2e2-4228-8b47-13c9601c450a)
![Image](https://github.com/user-attachments/assets/69734236-7413-4c06-8f68-c184fd66ccdb)

Simplified structure of the Linux kernel: ext4 is implemented between the Linux kernel Virtual File System and the generic block layer.
![Image](https://github.com/user-attachments/assets/d5ea81f8-bc89-4f16-93f2-fac65eecb8cb)

#### File access modes for fopen function
```bash
+--------+----------------+--------------------------------------+-------------------------------------+--------------------------------+
| Mode   | Meaning        | Explanation                          | Action if file already exists       | Action if file does not exist  |
+--------+----------------+--------------------------------------+-------------------------------------+--------------------------------+
| "r"    | read           | Open a file for reading              | Read from start                     | Failure to open                |
| "w"    | write          | Create a file for writing            | Destroy contents                    | Create new                     |
| "a"    | append         | Append to a file                     | Write to end                        | Create new                     |
| "r+"   | read extended  | Open a file for read/write           | Read from start                     | Error                          |
| "w+"   | write extended | Create a file for read/write         | Destroy contents                    | Create new                     |
| "a+"   | append extended| Open a file for read/write           | Write to end                        | Create new                     |
+--------+----------------+--------------------------------------+-------------------------------------+--------------------------------+
```
### Newline character counts
- Based on linux, \n is linefeed and it will be counted as 1 character
- Based on windows, \n is converted to \r\n, so there might be extra 1 character read.

### References
- https://unix.stackexchange.com/questions/652047/how-does-the-os-access-files-stored-on-the-hard-disk
- [Design and Implementation of the Second Extended Filesystem](https://e2fsprogs.sourceforge.net/ext2intro.html)
- https://linux.die.net/man/8/debugfs (debugfs - ext2/ext3/ext4 file system debugger)
- https://stackoverflow.com/questions/3983825/how-is-a-file-represented-on-a-disk (some important links inside)
- https://stackoverflow.com/questions/2299566/internals-of-a-linux-system-call
- https://stackoverflow.com/questions/34193698/how-does-a-file-system-information-stores
- https://en.wikipedia.org/wiki/Ext4
- https://stackoverflow.com/questions/2752517/basic-concepts-in-file-system-implementation
