#include <stdlib.h>
#include "ajh_types.h"

def_struct(List,
    void*  data;
    struct ajh_List* next;
);

intern ajh_List* ajh_make_list(void *data)
{
    ajh_List* list = malloc(sizeof(ajh_List));
    list->data     = data;
    list->next     = NULL;
    return list;
}

intern ajh_List* ajh_make_list_with_next(void* data,ajh_List* next)
{
    ajh_List* list = malloc(sizeof(ajh_List));
    list->data     = data;
    list->next     = next;
    return list;
}

intern ajh_size ajh_count_list(ajh_List* list)
{
    u64 depth = 0;
    for(;list;list = list->next)
    {
        depth += 1;
    }
    return depth;
}

intern void ajh_append_list(ajh_List* to,void* data)
{
    ajh_List* list = ajh_make_list(data);
    while(to->next)
    {
        to = to->next;
    }
    to->next = list;
}

intern void ajh_traverse_list(ajh_List* list,void (*function)(void*))
{
    while(list)
    {
        function(list->data);
        list = list->next;
    }
}

intern ajh_bool ajh_contains_list(ajh_List* list,ajh_bool (*function)(void*))
{
    while(list)
    {
        if(function(list->data)) return true;
        list = list->next;
    }
    return false;
}

intern void ajh_free_list(ajh_List* list)
{
    ajh_List* current = list;
    while ( list ) 
    {
        list = current->next;
        free(current);
        current = list;
    }
}
