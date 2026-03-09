#include "./include/ring_buffer.h"

int main() {
    RingBuffer rb;
    ring_buffer_init(&rb);

    printf("Adding elements...\n");

    ring_buffer_push(&rb, 10);
    ring_buffer_push(&rb, 20);
    ring_buffer_push(&rb, 30);
    ring_buffer_push(&rb, 40);

    rb_print(&rb);

    uint8_t value;

    printf("Popping elements...\n");

    ring_buffer_pop(&rb, &value);
    printf("Popped: %u\n", value);

    ring_buffer_pop(&rb, &value);
    printf("Popped: %u\n", value);

    rb_print(&rb);

    printf("Adding more elements (wraparound)...\n");

    ring_buffer_push(&rb, 50);
    ring_buffer_push(&rb, 60);
    ring_buffer_push(&rb, 70);
    ring_buffer_push(&rb, 80);
    ring_buffer_push(&rb, 90);

    for (int i = 0; i < 100; ++i)
    {
        ring_buffer_push(&rb, (uint8_t)i);
        rb_print(&rb);
    }

    rb_print(&rb);

    printf("head=%u tail=%u\n", rb.head, rb.tail);

    return 0;
}