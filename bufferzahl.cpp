#include "bufferzahl.h"

BufferZahl::BufferZahl(void) {
    p_buffer = NULL;
}

void BufferZahl::new_data(int zahl) {
    data_t* p_mydata;
    p_mydata = new data_t;
    p_mydata->zahl = zahl;
    new_entry((void*)p_mydata);
}

bool BufferZahl::del_data(data_t* p_record) {
    data_t* p_mydata;
    bool retval = false;
    void* p_delbuffer = p_initial;
    while ( p_delbuffer && ! retval ) {
        p_mydata = (data_t *)get_data_ptr(p_delbuffer);
        printf("###%d\n",p_mydata->zahl);
        if ( p_mydata->zahl == p_record-> zahl ) {
            retval = true;
            del_entry(p_delbuffer);
        } else {
            p_delbuffer = next_entry(p_delbuffer);
        }
    } 
    return retval;
}

bool BufferZahl::list_data(bool goto_start, data_t* p_record) {
    data_t* p_mydata;
    bool retval = false;
    if ( goto_start ) p_buffer = p_initial;
    if ( p_buffer ) {
        p_mydata = (data_t *)get_data_ptr(p_buffer);
        retval = true;
        p_record->zahl = p_mydata->zahl;
        p_buffer = next_entry(p_buffer);
    } else {
        retval = false;
    }
    return retval;
}
