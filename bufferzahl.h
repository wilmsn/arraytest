/*


*/
#ifndef _BUFFERZAHL_H_   
#define _BUFFERZAHL_H_
#include <stdint.h>
#include "buffer.h"

class BufferZahl : protected Buffer {
    
private:

protected:
    
public:

    struct data_t {
        int		zahl;
    };
    void* p_buffer;
    
    void new_data(int zahl);
    bool list_data(bool goto_start, data_t* p_record);
    bool del_data(data_t* p_record);
    BufferZahl(void);

};


#endif
