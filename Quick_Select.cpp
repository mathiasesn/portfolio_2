#include "Quick_Select.h"

// PUBLIC

Quick_Select::Quick_Select() {}

Quick_Select::Quick_Select(vector<int> v, int k) {
    table = v;
    quick_select(table, 0, table.size()-1, k);
}

Quick_Select::~Quick_Select() { }

void Quick_Select::print() {
    for (unsigned i = 0; i < table.size(); i++) {
        cout << table[i] << " ";
    }
    cout << endl;
}

void Quick_Select::restart_counter() {
    counter = 0;
}

int Quick_Select::get_counter() {
    return counter;
}

// PRIVATE
void Quick_Select::quick_select(vector<int> &v, int left, int right, int k) {
    if (left + 10 <= right ) {
        int pivot = median3(v, left, right);
        int i = left; int j = right;
        while (true) {
            while( v[++i] < pivot ) {}
            while( pivot < v[--j] ) {}

            if ( i<j ) {
                swap( v[i], v[j] );
                counter++;
            }
            else {
                break;
            }
        }

        swap( v[i], v[ right-1 ] );

        if ( k<=i ) {
            quick_select(v, left, i-1, k);
        }
        else if ( k>i+1 ) {
            quick_select(v, i+1, right, k);
        }
    }
    else {
        insertion_sort(v);
    }
}

void Quick_Select::insertion_sort(vector<int> &v) {
    for (unsigned i = 1; i < v.size(); ++i) {
        int tmp = v[i];

        int j;
        for ( j = i; j > 0 && tmp < v[j-1]; --j) {
            v[j] = v[j-1];
        }

        v[j] = tmp;
    }
}

int Quick_Select::median3(vector<int> v, int left, int right) {
    int center = ( left + right ) / 2;

    if ( v[ center ] < v[ left ] )
        swap( v[ left ], v[center] );

    if ( v[ right ] < v[ left ] )
        swap( v[ left ], v[ right ] );

    if ( v[ right ] < v[ center ] )
        swap( v[ center ], v[ right ] );

    swap( v[ center ], v[ right-1 ] );
    return v[ right-1 ];
}
