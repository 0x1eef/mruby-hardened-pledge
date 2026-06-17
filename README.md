## About

mruby-hardened-pledge provides mruby bindings for
HardenedBSD's pledge feature &ndash; which is inspired
by and based on OpenBSD's pledge feature.

For the time being the library does nothing more than
bridge `pledge_string` from libpledge as `Kernel#pledge`
in mruby, and it is implemented as 22 lines of simple C
code. I might build abstractions on top of it later.

## Quick start

#### Example

```ruby
##
# Allow DNS. Fail with errno.
pledge("dns softfail")

##
# Raises SystemCallError
File.open("/etc/passwd", "r") { f.gets }
```

#### Introduction

The `Kernel#pledge` method is a wrapper around `pledge_string`,
and it is almost identical to the C version. It accepts a string,
where each pledge is separated by a space. A pledge represents
one or more system calls, and when you opt into a pledge, you also
opt into a restricted environment where only those system calls
are allowed.

System calls which were not covered by a pledge become
violations, and the kernel will crash the program when a
pledge is violated. The `Kernel#pledge` method can be called
multiple times, and each time privileges can be dropped
further.

#### Pledges

A pledge combines one or more system calls into a single unit
that has a label:

| Pledge String | C Constant |
|---|---|

| `rpath` | `PLEDGE_RPATH` |
| `wpath` | `PLEDGE_WPATH` |
| `cpath` | `PLEDGE_CPATH` |
| `stdio` | `PLEDGE_STDIO` |
| `tmppath` | `PLEDGE_TMPPATH` |
| `dns` | `PLEDGE_DNS` |
| `inet` | `PLEDGE_INET` |
| `flock` | `PLEDGE_FLOCK` |
| `unix` | `PLEDGE_UNIX` |
| `id` | `PLEDGE_ID` |
| `tape` | `PLEDGE_TAPE` |
| `getpw` | `PLEDGE_GETPW` |
| `proc` | `PLEDGE_PROC` |
| `settime` | `PLEDGE_SETTIME` |
| `fattr` | `PLEDGE_FATTR` |
| `protexec` | `PLEDGE_PROTEXEC` |
| `tty` | `PLEDGE_TTY` |
| `sendfd` | `PLEDGE_SENDFD` |
| `recvfd` | `PLEDGE_RECVFD` |
| `exec` | `PLEDGE_EXEC` |
| `route` | `PLEDGE_ROUTE` |
| `mcast` | `PLEDGE_MCAST` |
| `vminfo` | `PLEDGE_VMINFO` |
| `ps` | `PLEDGE_PS` |
| `disklabel` | `PLEDGE_DISKLABEL` |
| `pf` | `PLEDGE_PF` |
| `audio` | `PLEDGE_AUDIO` |
| `dpath` | `PLEDGE_DPATH` |
| `drm` | `PLEDGE_DRM` |
| `vmm` | `PLEDGE_VMM` |
| `chown` | `PLEDGE_CHOWN` |
| `chownuid` | `PLEDGE_CHOWNUID` |
| `bpf` | `PLEDGE_BPF` |
| `device` | `PLEDGE_DEVICE` |
| `kld` | `PLEDGE_KLD` |
| `aio` | `PLEDGE_AIO` |
| `softfail` | `PLEDGE_SOFTFAIL` |
| `nolearn` | `PLEDGE_NOLEARN` |
| `sysctl` | `PLEDGE_SYSCTL` |
| `ioctl` | `PLEDGE_IOCTL` |
| `capsicum` | `PLEDGE_CAPSICUM` |
| `none` | `PLEDGE_NONE` |

## License

0BSD. <br>
See [LICENSE].