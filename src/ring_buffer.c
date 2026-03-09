#include "../include/ring_buffer.h"

#define RB_CAPACITY 8

void rb_print(const RingBuffer *rb) {
    uint16_t tail = rb->tail;
    while(tail!=rb->head) {
        printf("%u ", rb->buffer[tail]);
        tail = (tail + 1) % RB_CAPACITY;
    };
    printf("\n");
}

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
bool is_full(const RingBuffer *rb) {
    return ((rb->head+1)%RB_CAPACITY)==rb->tail;
}// check if ringbuffer is full
uint16_t ring_buffer_size(const RingBuffer *rb){
    if (rb-> head >= rb->tail) {
        return rb->head - rb->tail;
    } else {
        return RB_CAPACITY + rb->head - rb->tail;
    }

}; // check the size of the ringbuffer
