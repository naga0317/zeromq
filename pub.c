#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main () {
    // Initialize ZeroMQ context and socket
    void* context = zmq_ctx_new();
    void* publisher = zmq_socket(context, ZMQ_PUB);
    zmq_bind(publisher, "tcp://*:5555");

    // Publish messages every second
    while (1) {
        char message[20];
        sprintf(message, "Hello, world! %d", rand());
        zmq_send(publisher, message, strlen(message), 0);
        sleep(1);
    }

    // Cleanup ZeroMQ context and socket
    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}

