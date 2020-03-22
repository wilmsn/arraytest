#include "buffer.h"

Buffer::Buffer(void) {
    p_initial = NULL;
}

void Buffer::new_entry(void* p_data_new) {
    buffer_t *p_search;
    Buffer::buffer_t* p_new = new buffer_t; 
    p_new->p_data = p_data_new;
    p_new->p_next = NULL;
//    char *debug =  (char*) malloc (DEBUGSTRINGSIZE);
/*    if (logger->verboselevel & VERBOSECONTENTOBUFFER) {
        sprintf(debug,"OrderBuffer: new_entry %p", new_ptr); 
        logger->logmsg(VERBOSECONTENTOBUFFER, debug);    
        sprintf(debug,"Bestand vorher"); 
        logger->logmsg(VERBOSECONTENTOBUFFER, debug);
        debug_print_buffer();
    } */
    if (p_initial) {
        p_search = p_initial;
        while (p_search->p_next) {
            p_search = p_search->p_next;
        }
        p_search->p_next = p_new;
    } else {
        p_initial = p_new;
    }
/*    if (logger->verboselevel & VERBOSECONTENTOBUFFER) {
        sprintf(debug,"Bestand nachher"); 
        logger->logmsg(VERBOSECONTENTOBUFFER, debug);
        debug_print_buffer();
    }
    free(debug); */
}

bool Buffer::del_entry(void* p_del_void) {
    bool retval = false;
    buffer_t *p_search, *p_tmp, *p_del;
    p_del = (buffer_t*) p_del_void;
    p_search = p_initial;
    p_tmp = p_initial;
    while (p_search) {
        if (p_search == p_del ) {
            if (p_search == p_initial) {
                if (p_initial->p_next) { 
                    p_tmp=p_initial->p_next;
                    delete p_initial;
                    p_initial=p_tmp;
                } else {
                    delete p_initial;
                    p_initial = NULL;
                }
            } else            {
                p_tmp->p_next = p_search->p_next;
                delete p_search;
            }
            p_search = NULL;
            retval = true;
        } else {
            p_tmp = p_search;   // Ist das nötig ??????
            p_search = p_search->p_next;
        }
    }
    return retval;
}

void* Buffer::next_entry(void* p_findbuffer_void) {
    buffer_t *p_search, *p_result, *p_findbuffer;
    p_findbuffer = (buffer_t*)p_findbuffer_void;
    p_search = p_initial;
    if ( p_findbuffer ) {
        while ( p_search != p_findbuffer && p_search->p_next ) {  
            p_search = p_search->p_next;
        }
        p_result = p_search->p_next;
    } else {
        p_result = p_initial;
    }

    return (void*) p_result;    
}

void* Buffer::get_data_ptr(void* p_buffer_void) {
    buffer_t* p_buffer;
    p_buffer = (buffer_t *)p_buffer_void;
    return p_buffer->p_data;
}
