#include "Message_generated.h"

int main()
{
    flatcc_builder_t builder, *B;

    B = &builder;

    flatcc_builder_init( B );

    Message_start_as_root( B );

    Message_timepoint_add( B, 42.0 );
    char data[] = { 1, 2, 3, 4, 5 };
    Message_data_create( B, data, sizeof( data ) );
    Message_end_as_root( B );

    size_t size;
    void* buffer = flatcc_builder_get_direct_buffer( B, &size );


    Message_table_t message = Message_as_root( buffer );
    double timepoint = Message_timepoint( message );
    flatbuffers_int8_vec_t data = Message_data( message );
}