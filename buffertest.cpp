#include "buffertest.h"

int main()
{
    BufferZahl mybuffer;
    BufferZahl::data_t p_record;
    bool reset_datapointer;
    mybuffer.new_data(1);
    mybuffer.new_data(2);
    mybuffer.new_data(3);
    mybuffer.new_data(4);
    mybuffer.new_data(5);
    mybuffer.new_data(6);
    mybuffer.new_data(7);
    mybuffer.new_data(8);
    mybuffer.new_data(9);
    mybuffer.new_data(10);
//    printf("Zahl: %d\n",mybuffer.list_data(true));
    reset_datapointer = true;
    while ( mybuffer.list_data(reset_datapointer, &p_record) ) {
        printf("Zahl: %d\n", p_record.zahl);
        reset_datapointer = false;
    }
    p_record.zahl = 6;
    if (mybuffer.del_data(&p_record)) printf("=========>Zahl %d deleted\n", p_record.zahl); 
    p_record.zahl = 2;
    if (mybuffer.del_data(&p_record)) printf("=========>Zahl %d deleted\n", p_record.zahl); 
    p_record.zahl = 5;
    if (mybuffer.del_data(&p_record)) printf("=========>Zahl %d deleted\n", p_record.zahl); 
    reset_datapointer = true;
    while ( mybuffer.list_data(reset_datapointer, &p_record) ) {
        printf("Zahl: %d\n", p_record.zahl);
        reset_datapointer = false;
    }
}
