PREFIX := /usr

all: countfd

countfd: countfd.c
	$(CC) -o $@ $<

.PHONY: install
install: countfd
	/usr/bin/install -d $(DESTDIR)$(PREFIX)/sbin
	/usr/bin/install -m 4775 -o root -g root $< $(DESTDIR)$(PREFIX)/sbin

clean:
	rm -f countfd *.o
