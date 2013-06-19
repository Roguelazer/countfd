**Scenario**: you want to monitor how many open file descriptors a process has
open. You aren't running as that process's user, or as root. Seems like
setuid is your friend here, but that can only be used on binaries. Well,
here's the binary you were looking for.
