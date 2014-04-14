#include "message.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
static bool logged = false;
void log(const char *msg)
{
	printf("%s\n", msg);
}
static void reg_callback(struct reg_response response)
{
	struct sign_in_packet packet;
	log("reg_callback");
	packet.user_id = response.user_id;
	packet.user_token = response.user_token;
	log(packet.user_id);
	log(packet.user_token);
	sign_in(packet);
	log("sign_in message sended");
}
static void sign_in_callback(struct sign_in_response response)
{
	if(response.err == sign_in_response::SUCCESS)
	{
		printf("sign_in success!%s\n", response.online_token);	
		logged = true;
	}
	else
	{
		printf("sign_in_failed\n");
	}

}
static void msg_callback(struct chat_packet packet)
{
	printf("other_id:%s\nmessage:%s\n", packet.other_id, packet.message);
}

static void chat_callback(struct chat_response packet)
{
	if(packet.err == chat_response::SUCCESS)
	{
		printf("message%d send success\n", packet.message_id);
	}
	else
	{
		printf("message send failed\n");
	}
}
static void conn_callback()
{
	log("connection callback register");
	struct reg_packet packet;
	packet.type = "iOS";
	packet.token = "test_token";
	packet.uuid = "hehe";
	packet.sys_version = "0.0.5";
	packet.soft_version = "0.0.1";
	device_register(packet);
}
int main()
{
	pthread_t ntid;
	set_connection_callback(conn_callback);
	set_register_callback(reg_callback);
	set_sign_in_callback(sign_in_callback);
	set_message_callback(msg_callback);
	set_chat_callback(chat_callback);
	init_message_module(log);
	pthread_create(&ntid, NULL, start_client, NULL);
	char buf[100];
	char user_id[30];
	memset(buf, 0, 100);
	memset(user_id, 0, 30);
	scanf("%s",user_id);
	scanf("%s",buf);
	struct chat_packet packet;
	packet.other_id = user_id;
	packet.message = buf;
	packet.message_id = 0;
	packet.time_stamp = time(0);
	send_message(packet);
	sleep(100);
	return 0;
}

