#include "../include/ring_buffer.h"

#define RB_CAPACITY 128

void ring_buffer_init(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
};
void ring_buffer_push(RingBuffer *rb, uint8_t data) {
    uint16_t next = (rb->head + 1) % RB_CAPACITY;

    rb->buffer[rb->head] = data;
    rb->head = next;
}

bool ring_buffer_safe_push(RingBuffer *rb, uint8_t data) {
    if (is_full(rb)) {
        return false;
    } else {
        ring_buffer_push(rb, data);
        return true;
    }
}

bool ring_buffer_pop(RingBuffer *rb, uint8_t* data) {
    if (is_empty(rb)) return false;

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % RB_CAPACITY;

    return true;
}
bool is_empty(const RingBuffer *rb) {
    return rb->tail == rb->head;
}; 
bool is_full(const RingBuffer *rb); // check if ringbuffer is full
uint16_t ring_buffer_size(const RingBuffer *rb); // check the size of the ringbuffer

int main() {
    RingBuffer *rb;
    ring_buffer_init(rb);
}