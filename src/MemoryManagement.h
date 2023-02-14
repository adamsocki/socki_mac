
#define Bytes(n) (n)
#define Kilobytes(n) (1024 * Bytes(n))
#define Megabytes(n) (1024 * Kilobytes(n))
#define Gigabytes(n) (1024 * Megabytes(n))


struct MAllocator;

typedef void *AllocateFunc(MAllocator *allocator, uint64 size);
typedef void DeallocateFunc(MAllocator *allocator, void *data);

struct MAllocator {
    AllocateFunc *allocate;
    DeallocateFunc *deallocate;
};

inline void *AllocateMem(MAllocator *allocator, uint64 size) {
    return allocator->allocate(allocator, size);
}

inline void DeallocateMem(MAllocator *allocator, void *data) {
    if (allocator->deallocate == NULL) { return; }
    allocator->deallocate(allocator, data);
}

struct MemoryArena : MAllocator {
    uint32 capacity;
    uint32 size; // in bytes
    void *ptr;
};


void *PushSizeMemoryArena(MemoryArena *arena, uint64 size);

void AllocateMemoryArena(MemoryArena *arena, uint64 capacity) {
    void *(*allocate)(MemoryArena *, uint64) = &PushSizeMemoryArena;
    arena->allocate = (AllocateFunc *)allocate;
    arena->deallocate = NULL;

    // size_t align = 8;
    // arena->used = (arena->used + (align - 1)) & ~(align - 1);

    arena->capacity = capacity;
    arena->size = 0;
    arena->ptr = malloc(capacity);
    memset(arena->ptr, 0, capacity);
}

void *PushSizeMemoryArena(MemoryArena *arena, uint64 size) {
    void *result = (uint8 *)arena->ptr + arena->size;
    arena->size += size;

    assert(arena->size < arena->capacity);

    return result;
}

void ClearMemoryArena(MemoryArena *arena) {
    arena->size = 0;
}