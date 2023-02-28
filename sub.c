#include <zmq.h>
#include <string.h>
#include <stdio.h>

int main () {
    // Initialize ZeroMQ context and socket
    void* context = zmq_ctx_new();
    void* subscriber = zmq_socket(context, ZMQ_SUB);
    zmq_connect(subscriber, "tcp://localhost:5555");

    // Subscribe to all messages
    zmq_setsockopt(subscriber, ZMQ_SUBSCRIBE, "", 0);

    // Receive and print messages
    while (1) {
        char message[20];
        zmq_recv(subscriber, message, 20, 0);
        printf("Received message: %s\n", message);
    }

    // Cleanup ZeroMQ context and socket
    zmq_close(subscriber);
    zmq_ctx_destroy(context);
    return 0;
}

