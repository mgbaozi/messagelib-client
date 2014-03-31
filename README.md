messagelib-client
=================

Message Library For iOS and Android

use it like this

```C
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
int main()
{
  set_connection_callback(conn_callback);
  set_error_callback(error_callback);
  set_register_callback(reg_callback);
  set_sign_in_callback(sign_in_callback);
  set_chat_callback(chat_callback);
  set_message_callback(msg_callback);
 
  start_client();
}
 
/****  !!After!! connection_callback is called ,you can call these  ****/
device_register(struct reg_packet packet);
send_message(struct chat_packet packet);
sign_in(struct sign_in_packet packet);
```
**** When error_callback is called, you need call start_client AGAIN ****

**** When user press HOME or TERMINATE the process ,need to call close_client ****

