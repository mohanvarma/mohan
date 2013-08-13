typedef struct _aList {
    struct _aList* next;
    struct _aList* prev; // Optional.
    // some data
} aList;

aList* merge_sort_list_recursive(aList *list,int (*compare)(aList *one,aList *two))
{
    // Trivial case.
    if (!list || !list->next)
        return list;

    aList *right = list,
          *temp  = list,
          *last  = list,
          *result = 0,
          *next   = 0,
          *tail   = 0;

    // Find halfway through the list (by running two pointers, one at twice the speed of the other).
    while (temp && temp->next)
    {
        last = right;
        right = right->next;
        temp = temp->next->next;
    }

    // Break the list in two. (prev pointers are broken here, but we fix later)
    last->next = 0;

    // Recurse on the two smaller lists:
    list = merge_sort_list_recursive(list, compare);
    right = merge_sort_list_recursive(right, compare);

    // Merge:
    while (list || right)
    {
        // Take from empty lists, or compare:
        if (!right) {
            next = list;
            list = list->next;
        } else if (!list) {
            next = right;
            right = right->next;
        } else if (compare(list, right) < 0) {
            next = list;
            list = list->next;
        } else {
            next = right;
            right = right->next;
        }
        if (!result) {
            result=next;
        } else {
            tail->next=next;
        }
        next->prev = tail;  // Optional.
        tail = next;
    }
    return result;
}

