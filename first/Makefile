CC=g++
CFlAGS=-Wall -Werror -Wextra

all: log_server backend

log_server:
	$(CC) $(CFLAGS) log_srv/log_srv.cpp -o ../first_log_server

backend:
	$(CC) $(CFLAGS) server/backend.cpp -o ../first_server

clean:
	rm ../first_log_server
	rm ../first_server
