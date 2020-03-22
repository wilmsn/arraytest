#include "buffer.h"
#include "buffertest.h"

int main()
{
    Buffer mybuffer;
    data_t* p_mydata;
    void* p_mybuffer;
    p_mydata = new data_t;
    p_mydata->zahl = 1;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 2;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 3;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 4;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 5;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 6;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 7;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 8;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 9;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 10;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 11;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 12;
    mybuffer.new_entry((void*)p_mydata);
    p_mydata = new data_t;
    p_mydata->zahl = 13;
    mybuffer.new_entry((void*)p_mydata);
    p_mybuffer = mybuffer.next_entry(NULL);
    while ( p_mybuffer ) {
        printf("%p\n",p_mybuffer);
        p_mydata = (data_t *)mybuffer.get_data_ptr(p_mybuffer);
        printf("Zahl: %d\n",p_mydata->zahl);
        p_mybuffer = mybuffer.next_entry(p_mybuffer);
    }
    p_mybuffer = mybuffer.next_entry(NULL);
    while ( p_mybuffer ) {
        p_mydata = (data_t *)mybuffer.get_data_ptr(p_mybuffer);
        if ( p_mydata->zahl == 7 ) {
            mybuffer.del_entry(p_mybuffer);
            printf("====>%p=====>deleted\n",p_mybuffer); 
            p_mybuffer = NULL;
        } else {
            p_mybuffer = mybuffer.next_entry(p_mybuffer);
        }
    }
    p_mybuffer = mybuffer.next_entry(NULL);
    while ( p_mybuffer ) {
        printf("%p\n",p_mybuffer);
        p_mydata = (data_t *)mybuffer.get_data_ptr(p_mybuffer);
        printf("Zahl: %d\n",p_mydata->zahl);
        p_mybuffer = mybuffer.next_entry(p_mybuffer);
    }
    
    
/*    struct Order::order_t neworder;
    Order::order_t* order_ptr;
    for (int i=1; i<101; ++i) {
        neworder.orderno = i;
        myorder.new_entry(&neworder);
    }
    order_ptr=myorder.initial_order_ptr;
    while ( order_ptr ) {
      printf("%d\n",order_ptr->orderno);
      order_ptr=order_ptr->next;
    }
    myorder.del_entry(98);
    myorder.del_entry(97);
    myorder.del_entry(96);
    myorder.del_entry(95);
    myorder.del_entry(93);
    myorder.del_entry(92);
    myorder.del_entry(98);
    myorder.del_entry(80);
    myorder.del_entry(79);
    myorder.del_entry(50);
    order_ptr=myorder.initial_order_ptr;
    while ( order_ptr ) {
      printf("%d\n",order_ptr->orderno);
      order_ptr=order_ptr->next;
    }
*/    
}
