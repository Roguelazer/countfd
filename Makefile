countfd: countfd.c
	$(CC) -o $@ $<

clean:
	rm -f countfd *.o
