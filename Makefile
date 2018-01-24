CC=gcc
#we set -std=gnu89 so that inline methods work as in the original. 
CFLAGS= -std=gnu89 -Iinclude -Isrc/minicomp 
CLINK= -lz -lm

BLASPHEMY= src/lib/crypt.c src/lib/md5.c src/lib/util.c
MINICOMP= src/minicomp/minicomp.c src/minicomp/dc_bytecounter.c 

all: sserver sclient

sclient: src/client/main_client.c src/client/svpn_client.c
	$(CC) $(CFLAGS) src/client/main_client.c src/client/svpn_client.c src/client/svpn_fd.c \
		$(BLASPHEMY) \
		-o sclient $(CLINK)

sserver: src/server/main_server.c src/server/svpn_server.c 
	$(CC) $(CFLAGS) src/server/main_server.c src/server/svpn_server.c src/server/svpn_fd.c \
		$(BLASPHEMY) \
		-osserver $(CLINK)
	
