#include <cstring>
#include <iostream>
#include <string>
#include <zmq.h>

void *zmq_context;
void *socket;
using namespace std;
int main ()
{
    zmq_context = zmq_ctx_new();
    socket = zmq_socket(zmq_context, ZMQ_PUSH);
    std::string zmq_endpoint = "tcp://<MY IP>:5556";
    zmq_connect(socket, zmq_endpoint.c_str());

    zmq_msg_t msg;

    int value = 123;
    int rc = zmq_msg_init_size (&msg, sizeof(value));

    memcpy( zmq_msg_data(&msg), &value, sizeof(value) ) ;
    zmq_msg_send(&msg, socket, 0);
    zmq_msg_close(&msg);

    zmq_close(socket);
    zmq_ctx_destroy(zmq_context);
}

