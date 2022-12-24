#include "mydeque.h"
#include "my_assert.h"

///размер очереди
size_t deq_size(const MyDeque& deq)
{
    return deq.size;
}

///первый элемент очереди
const deque_t& deq_front(const MyDeque& deq)
{
    //Для проверки условий, при которых операция может выполняться следует писать assert
    assert(deq.size>0);
    return deq.data[(deq.head + 1) % deq_data_size];
}

///последний элемент очереди
const deque_t& deq_back(const MyDeque& deq)
{
    assert(deq.size>0);
    return deq.data[deq.tail];
}

///Очистить очередь
void deq_clear(MyDeque& deq)
{
    assert(deq.size > 0);
    deq.size = 0;
    deq.head = 0;
    deq.tail = 0;
}

///вставить элемент в конец очереди
void deq_push_back(MyDeque& deq, deque_t elem)
{
    assert(deq.size < deq_data_size );
    deq.tail = (deq.tail + 1) % deq_data_size;
    deq.data[deq.tail] = elem;
    deq.size ++;
}

///вставить элемент в начало очереди
void deq_push_front(MyDeque& deq, deque_t elem)
{
    assert(deq.size < deq_data_size);
    deq.data[deq.head] = elem;
    deq.head = (deq.head + deq_data_size - 1) % deq_data_size;
    deq.size++;
}

///достать элемент с конца очереди
deque_t deq_pop_back(MyDeque& deq)
{
    assert(deq.size > 0);
    deque_t answer = deq.data[deq.tail];
    deq.tail = (deq.tail + deq_data_size - 1) % deq_data_size;
    deq.size--;
    return answer;
}

///достать элемент с начала очереди
deque_t deq_pop_front(MyDeque& deq)
{
    assert(deq.size > 0);
    deq.head = (deq.head + 1) % deq_data_size;
    deque_t answer = deq.data[deq.head];
    deq.size--;
    return answer;
}
