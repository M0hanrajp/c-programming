### Commands for examining process:

- VIMP:[Understanding the Memory Layout of Linux Executables](https://gist.github.com/CMCDragonkai/10ab53654b2aa6ce55c11cfc5b2432a4)

### pmap

[How to analyze a Linux process' memory map with pmap](https://www.redhat.com/en/blog/pmap-command)
```bash
$ sudo pmap -x 182
182:   @dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
Address           Kbytes     RSS   Dirty Mode  Mapping
000055a0e46da000      36      36       0 r---- dbus-daemon
000055a0e46e3000     140     140       0 r-x-- dbus-daemon
000055a0e4706000      44      44       0 r---- dbus-daemon
000055a0e4711000       8       8       8 r---- dbus-daemon
000055a0e4713000       4       4       4 rw--- dbus-daemon
000055a0ea43e000     620     552     552 rw---   [ anon ]
00007f57aa9c8000      24      24       0 r---- libnss_systemd.so.2
00007f57aa9ce000     200     200       0 r-x-- libnss_systemd.so.2
00007f57aaa00000      64      60       0 r---- libnss_systemd.so.2
00007f57aaa10000      16      16      16 r---- libnss_systemd.so.2
00007f57aaa14000       4       4       4 rw--- libnss_systemd.so.2
00007f57aaa15000      20      16      16 rw---   [ anon ]
...
00007f57ab12e000       8       8       8 rw---   [ anon ]
00007f57ab130000       8       8       0 r---- ld-linux-x86-64.so.2
00007f57ab132000     168     168       0 r-x-- ld-linux-x86-64.so.2
00007f57ab15c000      44      40       0 r---- ld-linux-x86-64.so.2
00007f57ab168000       8       8       8 r---- ld-linux-x86-64.so.2
00007f57ab16a000       8       8       8 rw--- ld-linux-x86-64.so.2
00007ffc6d262000     132      40      40 rw---   [ stack ]
00007ffc6d39d000      16       0       0 r----   [ anon ]
00007ffc6d3a1000       8       4       0 r-x--   [ anon ]
---------------- ------- ------- -------
total kB            8788    5068     900
# 8788 kB is the total virtual memory you have mapped (the sum of all VMAs).
# 5068 kB is the subset of those pages that are resident in RAM at this moment.
# 900 kB of that resident memory has been dirtied (modified) and would need to be written back if it were to be paged out.
```
### Using /proc/$PID/maps

This is also helpful to get process output
```bash
$ sudo cat /proc/182/maps
55a0e46da000-55a0e46e3000 r--p 00000000 08:20 1555                       /usr/bin/dbus-daemon
...
7f57ab168000-7f57ab16a000 r--p 00037000 08:20 53400                      /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7f57ab16a000-7f57ab16c000 rw-p 00039000 08:20 53400                      /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffc6d262000-7ffc6d283000 rw-p 00000000 00:00 0                          [stack]
7ffc6d39d000-7ffc6d3a1000 r--p 00000000 00:00 0                          [vvar]
7ffc6d3a1000-7ffc6d3a3000 r-xp 00000000 00:00 0                          [vdso]
```
Doc: https://tldp.org/LDP/Linux-Filesystem-Hierarchy/html/proc.html

### References
- https://linux.die.net/man/1/pmap
- https://stackoverflow.com/questions/1966920/more-info-on-memory-layout-of-an-executable-program-process

### Misc commands:
Examine devices attached to the device in linux:

shows block devices like hard drives and SSDs.
```bash
$ lsblk -Ta
lsblk: unknown column: a
NAME MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
sda    8:0    0 388.4M  1 disk
sdb    8:16   0     2G  0 disk [SWAP]
sdc    8:32   0     1T  0 disk /var/lib/docker
                               /mnt/wslg/distro
                               /
```
lspci displays PCI devices
```bash
$ lspci -v
0e2b:00:00.0 3D controller: Microsoft Corporation Device 008e
        Physical Slot: 1250944341
        Flags: bus master, fast devsel, latency 0
        Capabilities: <access denied>
        Kernel driver in use: dxgkrnl

5582:00:00.0 SCSI storage controller: Red Hat, Inc. Virtio console (rev 01)
        Subsystem: Red Hat, Inc. Virtio console
        Physical Slot: 3300344309
        Flags: bus master, fast devsel, latency 64
        Memory at 9ffe00000 (64-bit, non-prefetchable) [size=4K]
        Memory at 9ffe01000 (64-bit, non-prefetchable) [size=4K]
        Memory at 9ffe02000 (64-bit, non-prefetchable) [size=4K]
        Capabilities: <access denied>
        Kernel driver in use: virtio-pci

ead9:00:00.0 System peripheral: Red Hat, Inc. Virtio file system (rev 01)
        Subsystem: Red Hat, Inc. Virtio file system
        Physical Slot: 1063357650
        Flags: bus master, fast devsel, latency 64
        Memory at e00000000 (64-bit, non-prefetchable) [size=4K]
        Memory at e00001000 (64-bit, non-prefetchable) [size=4K]
        Memory at c00000000 (64-bit, non-prefetchable) [size=8G]
        Capabilities: <access denied>
        Kernel driver in use: virtio-pci
```
lsusb lists USB devices
```bash
$ lsusb
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
```
