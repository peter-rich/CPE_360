#include <iostream>

#define IS_FOUND 1

struct entry{
    int val;
    struct entry *next;
};

int hash_function(int element, int bucket_count){
    return (element%bucket_count);
}

int search_element(struct entry **hash_table, int element, int bucket_count){
    
    int is_found = 0;
    int index = hash_function(element, bucket_count);
    
    //descend on the hash_table[index] linked list to see if that element exist.
    //

    return is_found;
}

int insert(struct entry **hash_table, int element, int bucket_count){
    
    return 0;
}

int delete_element(struct entry **hash_table, int element, int bucket_count){
    
    return 0;
}

int construct_hash_table(struct entry **&hash_table, int bucket_count){

    hash_table = new struct entry*[bucket_count];
    
    for (int i = 0; i < bucket_count; i ++)
    {
        hash_table[i] = new struct entry;
        hash_table[i]->val = 0;
        hash_table[i]->next = NULL;
    }

    return 0;
}

int main (int args, char **argv)
{
    std::cout<<"This is a hash table with chaining-based collision handling mechanism\n";

    std::cout<<"/path/to/exe num_of_elements_to_insert bucket_count\n";

    assert(args>=3);

    int num = atoi(argv[1]);
    int bucket_count = atoi(argv[2]);

    struct entry **hash_table;

    assert(0==construct_hash_table (hash_table, bucket_count));

    int element = -1;
    for(int i = 0; i < num; i ++){
        int avalue = rand()%bucket_count;
        element = avalue;
        insert(hash_table, avalue, bucket_count);
    }
    
    if(IS_FOUND == search_element(hash_table, element, bucket_count))
        std::cout<<"Element "<<element<<" exists in the hash table\n";

    delete_element(hash_table, element, bucket_count);

    return 0;
}

