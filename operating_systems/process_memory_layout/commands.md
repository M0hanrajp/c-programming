### Commands for examining process:
[How to analyze a Linux process' memory map with pmap](https://www.redhat.com/en/blog/pmap-command)

[Understanding the Memory Layout of Linux Executables](https://gist.github.com/CMCDragonkai/10ab53654b2aa6ce55c11cfc5b2432a4)


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
