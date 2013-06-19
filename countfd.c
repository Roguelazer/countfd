#define _XOPEN_SOURCE 700
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <linux/limits.h>


void usage() {
    fprintf(stderr, "Usage: countfds PID\n");
    exit(2);
}


int main(int argc, char **argv) {
    pid_t pid = 0;
    char pathbuf[PATH_MAX];
    char* endptr;
    DIR* dir;
    struct dirent* entry = NULL;
    size_t counter = 0;

    if (argc != 2) {
        usage();
    }
    pid = strtol(argv[1], &endptr, 10);
    if (endptr[0] != '\0') {
        usage();
    }

    if (snprintf(pathbuf, PATH_MAX, "/proc/%d/fd", pid) < 0) {
        fprintf(stderr, "Something went wrong constructing path buffer: %s", strerror(errno));
        return 1;
    }

    if ((dir = opendir(pathbuf)) == NULL) {
        fprintf(stderr, "Could not open %s (%s)\n", pathbuf, strerror(errno));
        return 1;
    }
    while ((entry = readdir(dir)) != NULL) {
        ++counter;
    }
    printf("%llu\n", (long long unsigned)counter);
    return 0;
}
