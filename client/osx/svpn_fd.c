#include "svpn_fd.h"
#include "svpn_client.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>

int svpn_tun_create(char *dev_name) {
}

int svpn_sock_create(struct svpn_client *psc,
		char *addr, unsigned short port) {
	psc->server_addr.sin_family = AF_INET;
	psc->server_addr.sin_addr.s_addr = inet_addr(addr);
	psc->server_addr.sin_port = htons(port);
	psc->sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if(psc->sock_fd < 0) {
		perror("socket");
		return -1;
	}
	return 0;
}