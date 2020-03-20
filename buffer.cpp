#include "buffer.h"

Buffer::Buffer(void) {
    p_initial = NULL;
}

void Buffer::new_entry(Buffer::buffer_t* p_new) {
    buffer_t *p_search;
    p_new->next = NULL;
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
        while (p_search->next) {
            p_search = p_search->next;
        }
        p_search->next = p_new;
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

bool Buffer::del_entry(Buffer::buffer_t* p_del) {
    bool retval = false;
    buffer_t *p_search, *p_tmp;
    p_search = p_initial;
    p_tmp = p_initial;
    while (p_search) {
        if (p_search == p_del ) {
            if (p_search == p_initial) {
                if (p_initial->next) { 
                    p_tmp=p_initial->next;
                    delete p_initial;
                    p_initial=p_tmp;
                } else {
                    delete p_initial;
                    p_initial = NULL;
                }
            } else            {
                p_tmp->next = p_search->next;
                delete p_search;
            }
            p_search = NULL;
            retval = true;
        } else {
            p_tmp = p_search;   // Ist das nötig ??????
            p_search = p_search->next;
        }
    }
    return retval;
}
