#ifndef NULL
	#define NULL 0
#endif
#include "message.h"
#include "KyoumeClient.h"

#ifdef __cplusplus
extern "C"
{
#endif
LogMethod log_method_;
static KyoumeClient *client_ = NULL;
static void default_reg_callback(struct reg_response response)
{
    log_method_("reg_callback");
}

static void default_sign_in_callback(struct sign_in_response response)
{
    log_method_("sign_in_callback");
}

static void default_chat_callback(struct chat_response response)
{
    log_method_("chat_callback");
}

static void default_msg_callback(struct chat_packet packet)
{
    log_method_("msg_callback");
}
static void default_conn_callback()
{
    log_method_("conn_callback");
}
    
static void default_error_callback()
{
    log_method_("error_callback");
}
static RegCallback reg_callback = default_reg_callback;
static SignInCallback sign_in_callback = default_sign_in_callback;
static ChatCallback chat_callback = default_chat_callback;
static MessageCallback msg_callback =  default_msg_callback;
static ConnectionCallback conn_callback = default_conn_callback;
static ErrorCallback error_callback = default_error_callback;
int device_register(struct reg_packet packet)
{
	client_ -> device_register(packet);
	return 0;
}
int sign_in(struct sign_in_packet packet)
{
    client_ -> sign_in(packet);
    return 0;
}
void set_connection_callback(ConnectionCallback callback)
{
    conn_callback = callback;
}

void set_error_callback(ErrorCallback callback)
{
    error_callback = callback;
}
void set_register_callback(RegCallback callback)
{
    reg_callback = callback;
}

void set_sign_in_callback(SignInCallback callback)
{
    sign_in_callback = callback;
}

void set_chat_callback(ChatCallback callback)
{
    chat_callback = callback;
}

void set_message_callback(MessageCallback callback)
{
    msg_callback = callback;
}

int send_message(struct chat_packet packet)
{
    client_ -> send_message(packet);
    return 0;
}

void init_message_module(LogMethod method)
{
    log_method_ = method;
}

void *start_client(void *)
{
	start_client_by_address("114.215.188.187", 24842);
    return (void *)0; 
}

void start_client_by_address(const char* address, int port)
{
	if(client_ == NULL)
    {
        UserCallbacks *callbacks = new UserCallbacks({conn_callback, error_callback, reg_callback, sign_in_callback, chat_callback, msg_callback});
        client_ = new KyoumeClient(callbacks, address, port);
        log_method_("start client");
    }
    //如果失败会返回非0值，如果成功则阻塞，正常结束连接后会返回0，如果非正常结束则返回非零
	client_ -> start();
}
int close_client(void)
{
    client_ -> stop();
    log_method_("stop client");
    return 0;
}
#ifdef __cplusplus
}
#endif
