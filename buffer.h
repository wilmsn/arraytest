/*


*/
#ifndef _BUFFER_H_   
#define _BUFFER_H_
#include <stdio.h> 
#include <iostream>
#include <stdint.h>
#include <cstring>
#include <unistd.h>

class Buffer {
    
private:

protected:
    
public:

    struct buffer_t {
        uint64_t		entrytime;
        void*     	    p_data;
        buffer_t*       p_next;          // poiter to the next record
    };
    
    buffer_t* p_initial;
    void new_entry(void*);
    bool del_entry(void*);
    void* next_entry(void*);
    void* get_data_ptr(void*);
    Buffer(void);

};

#endif // _BUFFER_H_
