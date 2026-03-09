#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t buffer[128];
    int head;
    int tail;
} RingBuffer;

void rb_print(const RingBuffer *rb); // prints the ring buffer
void ring_buffer_init(RingBuffer *rb); // initializes a ring buffer object
void ring_buffer_push(RingBuffer *rb, uint8_t data); // push data into the ring buffer regardless of size.
bool ring_buffer_safe_push(RingBuffer *rb, uint8_t data); // pushes data nto the ring if the ring is not full.
bool ring_buffer_pop(RingBuffer *rb, uint8_t* data); // pop data in the ring buffer
bool is_empty(const RingBuffer *rb); // check if ringbuffer is empty
bool is_full(const RingBuffer *rb); // check if ringbuffer is full
uint16_t ring_buffer_size(const RingBuffer *rb); // check the size of the ringbuffer
