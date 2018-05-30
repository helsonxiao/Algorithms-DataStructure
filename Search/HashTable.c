#define Status int
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768
typedef 
struct HashTable
{
    int *elem;
    int count;
} HashTable;

int m = 0;

Status InitHashTable(HashTable *H)
{
    int i;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return SUCCESS;
}

int Hash(int key)
{
    return key % m;
}

void InsertHash(HashTable *H, int key)
{
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY)
        addr = (addr + 1) % m;

    H->elem[addr] = key;
}

Status SearchHash(HashTable *H, int key, int *addr)
{
    *addr = Hash(key);
    while (H->elem[*addr] != key)
    {
        *addr = (*addr + 1) % m;
        if (*addr == Hash(key) || H->elem[*addr] == NULLKEY)
            return UNSUCCESS;
    }

    return SUCCESS;
}