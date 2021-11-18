/**
 * @file 003-struct.c
 * @author your name (you@domain.com)
 * @brief 
 * Compare and update the inventory stored in a 2D array against a second 2D array of a fresh delivery. 
 * Update the current existing inventory item quantities (in arr1). If an item cannot be found, add 
 * the new item and quantity into the inventory array. 
 * 
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// rm ./a.out; gcc 003-struct.c; ./a.out

#include <stdio.h>
#include <stdlib.h>

typedef struct inventory_item
{
    int id;
    char* desc;
} item;

typedef struct inventory_item_list
{
    int size;
    item* item_instance;
} items;

// Utility to print an array of items.
void pitem(const item* arr, const size_t len) {
    printf("\n");
    for (int ii=0; ii<len; ii++) {
        printf("Item:%d\tDescription:%s\n", arr[ii].id, arr[ii].desc);
    }
    return;
}

// Utility to print an array of items.
void pitems(const items itms) {
    printf("\n");
    for (int ii=0; ii<itms.size; ii++) {
        printf("Item:%d\tDescription:%s\n", itms.item_instance[ii].id, itms.item_instance[ii].desc);
    }
    return;
}

item* updateInventory(item * arr1, const size_t len1, const item* arr2, const size_t len2) {

    item* retlist = (item*) malloc(sizeof(item) * (len1 + len2));

    int ii=0;
    for (; ii<len1; ii++) {
        retlist[ii] = arr1[ii];
    }

    for (int jj=0; jj<len2; jj++) {
        retlist[ii++] = arr2[jj];
    }

    return retlist;

    
}

void updateInventory1(items* it1, const items it2) {

    int ii=it1->size;
    for (int jj=0; jj<it2.size; jj++) {
        it1->item_instance[ii++] = it2.item_instance[jj];
    }

    it1->size = ii;

    return;

    
}

void main() {
    printf("\nStarting\n");

    item item1 = {10, "Milk"};
    item item2 = {20, "Egg"};
    item itemlist[] = {item1, item2};
    //pitem(itemlist, sizeof(itemlist)/sizeof(item));

    items items1;
    items1.size = sizeof(itemlist)/sizeof(item);
    items1.item_instance = itemlist;
    pitems(items1);

    item newitem1 = {30, "Apple"};
    item newitem2 = {32, "Oranges"};
    item updatelist[] = {newitem1, newitem2};
    //pitem(updatelist, sizeof(updatelist)/sizeof(item));

    items items2;
    items2.size = sizeof(updatelist)/sizeof(item);
    items2.item_instance = updatelist;
    pitems(items2);


    //item* retlist = updateInventory(itemlist, sizeof(itemlist)/sizeof(item), updatelist, sizeof(updatelist)/sizeof(item));
    //pitem(retlist, 4);


    updateInventory1(&items1, items2);
    pitems(items1);
    printf("\nEnding\n");
    return;
}
