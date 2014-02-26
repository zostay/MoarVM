void * MVM_gc_allocate_nursery(MVMThreadContext *tc, size_t size);
void * MVM_gc_allocate_zeroed(MVMThreadContext *tc, size_t size);
MVMSTable * MVM_gc_allocate_stable(MVMThreadContext *tc, const MVMREPROps *repr, MVMObject *how);
MVMObject * MVM_gc_allocate_type_object(MVMThreadContext *tc, MVMSTable *st);
MVMObject * MVM_gc_allocate_object(MVMThreadContext *tc, MVMSTable *st);
void MVM_gc_allocate_gen2_default_set(MVMThreadContext *tc);
void MVM_gc_allocate_gen2_default_clear(MVMThreadContext *tc);
void MVM_gc_allocated_string(MVMThreadContext *tc, size_t amount);

/* Trigger a GC run if we've allocated at least 1gb of strings since the last GC run */
#define MVM_STRING_PRESSURE_THRESHOLD ((MVMuint64)3 * 1024 * 1024 * 1024)

#define MVM_gc_allocate(tc, size) (tc->allocate_in == MVMAllocate_Nursery ? \
    MVM_gc_allocate_nursery(tc, size) : \
    MVM_gc_gen2_allocate_zeroed(tc->gen2, size))
