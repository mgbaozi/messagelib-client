#ifndef MESSAGE_H
#define MESSAGE_H

/*
 use it like this
 #include "message.h"
 void reg_callback(struct reg_response response)
 {
    //do something
 }
 
 void sign_in_callback(struct sign_in_response response)
 {
    //do something
 }
 
 void chat_callback(struct chat_response response)
 {
    //do something
 }
 
 void msg_callback(struct chat_packet packet)
 {
    //do something
 }
 void conn_callback()
 {
    //do something
 }
 
 void error_callback()
 {
    //do something
 }
 
 set_connection_callback(conn_callback);
 set_error_callback(error_callback);
 set_register_callback(reg_callback);
 set_sign_in_callback(sign_in_callback);
 set_chat_callback(chat_callback);
 set_message_callback(msg_callback);
 
 start_client();
 
 ****  !!After!! connection_callback is called ,you can call these  ****
 device_register(struct reg_packet packet);
 send_message(struct chat_packet packet);
 sign_in(struct sign_in_packet packet);
 
 **** When error_callback is called, you need call start_client AGAIN ****
 
 **** When user press HOME or TERMINATE the process ,need to call close_client ****
 */
#ifdef __cplusplus
extern "C"
{
#endif
#include <stdio.h>
#include <time.h>
struct reg_packet
{
	const char *type;
	const char *token;
	const char *uuid;
	const char *sys_version;
	const char *soft_version;
};


struct reg_response
{
	enum
	{
		SUCCESS = 0,
		UNKNOWN_DEVICE = 1
	} err;
	const char *user_id;
	const char *user_token;
};

struct sign_in_packet
{
    const char *user_id;
    const char *user_token;
};

struct sign_in_response
{
    enum
    {
        SUCCESS = 0,
        TOKEN_NOT_AVAILABLE = 1
    } err;
    const char *online_token;
};

struct chat_packet
{
    const char *other_id;
    const char *message;
    int message_id;
	time_t time_stamp;
};

struct chat_response
{
    enum
    {
        SUCCESS = 0,
        OTHER_SIDE_OFFLINE = 1,
        WAIT_FOR_OTHER_REPLY = 2,
        YOU_OFFLINE = 3,
		UNKNOWN_ERROR = 4
    } err;
    int message_id;
};

typedef void (*LogMethod)(const char *);
void init_message_module(LogMethod method);
typedef void (*ConnectionCallback)(void);
typedef void (*ErrorCallback)(void);
typedef void (*RegCallback)(struct reg_response response);
// return 0 if success
int device_register(struct reg_packet packet);

typedef void (*SignInCallback)(struct sign_in_response response);
int sign_in(struct sign_in_packet packet);

typedef void (*ChatCallback)(struct chat_response response);
typedef void (*MessageCallback)(struct chat_packet packet);

//callback setters
void set_connection_callback(ConnectionCallback callback);
void set_error_callback(ErrorCallback callback);
void set_register_callback(RegCallback callback);
void set_sign_in_callback(SignInCallback callback);
//this callback will be call when message send successful or faild
void set_chat_callback(ChatCallback callback);
//this callback will be call when other send message
void set_message_callback(MessageCallback callback);

int send_message(struct chat_packet packet);

void *start_client(void*);
void start_client_by_address(const char* address, int port);
int close_client(void);
#ifdef __cplusplus
}
#endif
struct UserCallbacks
{
    ConnectionCallback conn_cb;
    ErrorCallback error_cb;
    RegCallback reg_cb;
    SignInCallback sing_in_cb;
    ChatCallback chat_cb;
    MessageCallback msg_cb;
};
#endif

