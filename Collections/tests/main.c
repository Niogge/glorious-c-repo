#include <aiv-cunit.h>
#include "aiv-vector_test.ct"

CUNIT_RUNNER(test_vector_creation,
            test_vector_add_one_item,
            test_vector_get_at_index_in_range,
            test_vector_get_at_index_out_of_range,
            test_vector_resize,
            test_vector_create_with_capacity,
            test_vector_autoresize_on_add,
            test_vector_foreach,
            test_vector_is_empty,
            test_vector_set,
            test_vector_add_all,
            test_vector_remove_at,
            test_vector_size,
            test_vector_downsize,
            test_vector_insert_at,
            test_vector_find_one,
            test_vector_find_one_absent,
            test_vector_find_all,
            test_vector_bubble_sort
            );