#include <iostream>
#include <string>

#include <zmq.h>
#include <unistd.h>



int main()
{
    zmq_context = zmq_ctx_new();

    void *socket = zmq_socket(zmq_context, ZMQ_PULL);

    zmq_bind(socket, "tcp://eth0:5556");


	int value;
    while (true)
    {
        int num = zmq_recv(socket, buffer, sizeof(buffer), 0);
        zmq_msg_t  msg;
        zmq_msg_init (&msg);

        int num = zmq_msg_recv(&msg, socket, 0);
        int value;
        memcpy(&value,  zmq_msg_data(&msg), num);
        cout << value << endl;
        zmq_msg_close(&msg);
	}
    zmq_close(socket);
    zmq_ctx_destroy(zmq_context);
}
