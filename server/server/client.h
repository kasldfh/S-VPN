//
#ifndef __CLIENT_H__

#define CLIENT_STATUS_NOTEXIST 101
#define CLIENT_STATUS_CACHED 102
#define CLIENT_STATUS_CONNECTED 100
#define CLIENT_STATUS_EXPIRED 103
#define CLIENT_STATUS_ABNORMAL 104

struct client
{
	struct CodeTable* table;
	struct sockaddr_storage node_addr;
	uint32_t local_addr;
	int status;
	int option;
	long long last_login;
	int socket_id;
};

struct svpn_clients
{
	size_t client_count;
	struct svpn_client* clients_list[256];
	struct svpn_client* clients_by_local_addr[256]; // 192.168.3.2 ~ 192.168.3.254
};

// create client struct in memory
// return the client_id, negative if error
int cache_client(int sock_id, const char* username);

// destroy client struct
// return negative it error
int uncache_client(int client_id);

// find the client by its name
// return the client_id, negative if error
int find_client_by_name(const char* username);

// find the client by its name
// return the client id, negative if error
int find_client_by_addr(int sock_id, struct sockaddr_storage* addr, socklen_t len);

// set the client status to ready, initialize data
// containing login and keepalive
// return negative if failed
int activate_client(int client_id);

// set client status to illegal, forbid all communication
int deactivate_client(int client_id);

// get the status of the client
// return client status(positive value)
int check_client_status(int client_id);

// find a unused ip address
// return the address, negative if error
uint32_t get_unused_local_address();

// initialize the client management
int svpn_client_init();

// release
int svpn_client_release();

#endif
