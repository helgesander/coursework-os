CC=g++
CFlAGS=-Wall -Werror -Wextra

all: log_server backend

log_server:
	$(CC) $(CFLAGS) log_srv/log_srv.cpp -o ../log_server

backend:
	$(CC) $(CFLAGS) server/backend.cpp -o ../second_server -lX11

clean:
	rm ../log_server
	rm ../second_server