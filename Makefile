CC=g++
CFlAGS=-Wall -Werror -Wextra

all: first second 

second: 
	$(CC) $(CFLAGS) -o second_server second/backend.cpp -lX11 -DPORT=12345 
	$(CC) $(CFLAGS) -o second_log log/log_srv.cpp -DSECOND_SERVER

first:
	$(CC) $(CFLAGS) -o first_log log/log_srv.cpp -DFIRST_SERVER
	$(CC) $(CFLAGS) -o first_server first/backend.cpp -DPORT=12344

clean: 
	rm first_server second_server first_log second_log
