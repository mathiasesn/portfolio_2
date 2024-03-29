#include "Priority_Queue.h"

Priority_Queue::Priority_Queue() { }

Priority_Queue::Priority_Queue(vector<int> v) {
    for (unsigned i = 0; i < v.size(); i++) {
        p_queue.push_back(v[i]);
    }
    build_heap();
    make_list();
}

Priority_Queue::~Priority_Queue() { }

void Priority_Queue::restart_counter() {
    counter = 0;
}

int Priority_Queue::get_counter() {
    return counter;
}

void Priority_Queue::print_queue() {
    for (unsigned i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

int Priority_Queue::delete_min() {
    int result = p_queue[1];
    p_queue[1] = p_queue[ p_queue.size()-1 ];
    percolate_down(1);
    p_queue.pop_back();
    return result;
}

void Priority_Queue::build_heap() {
    for (unsigned i = (p_queue.size()-1)/2; i > 0 ; i--) {
        percolate_down(i);
    }
    counter=0;
}

void Priority_Queue::percolate_down(int node) {
    int child;
    int temp = p_queue[node];

    for ( ; node * 2 <= (int)p_queue.size()-1; node = child) {
        counter++;
        child = node * 2;   // Left child first

        if ( ( child!=(int)p_queue.size()-1 ) && ( p_queue[child+1]<p_queue[child] ) ) {
            ++child;    // Go to right child
        }

        if ( p_queue[child] < temp ) {
            p_queue[node] = p_queue[child];
        }
        else {
            break;
        }
    }

    p_queue[node] = temp;
}

void Priority_Queue::make_list() {
    while ( p_queue.size() > 1 ) {
        list.push_back( delete_min() );
    }
}
