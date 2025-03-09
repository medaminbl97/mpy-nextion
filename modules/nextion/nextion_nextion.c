#include "modnextion.h"
/*
// Auto-generated MicroPython class for Nextion

################################################################################
                    nextion Nextion Implementation
################################################################################
*/
typedef struct _nextion_nextion_obj_t {
    mp_obj_base_t base;
    struct NexObject nextion_obj;
    mp_obj_t pop_callback_obj;
    mp_obj_t push_callback_obj;
} nextion_obj_t;

mp_obj_t nextion_Nextion_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    nextion_obj_t *self = mp_obj_malloc(nextion_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of Nextion called\n");
    if (self == NULL) {
        mp_raise_msg(&mp_type_MemoryError, "Failed to allocate Nextion object");
    }
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Nextion_nexLoop(mp_obj_t self_in, mp_obj_t nex_objects) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    
    // Get the length of the list of objects
    size_t len;
    mp_obj_t *items;
    mp_obj_get_array(nex_objects, &len, &items);
    
    // Temporary array to hold NexObject pointers
    struct NexObject *nex_listen_list[len];
    
    // Iterate over the list and extract NexObject from each item
    for (size_t i = 0; i < len; i++) {
        mp_obj_t obj = items[i];
        
        // Assuming each object has a method or attribute returning NexObject*
        nextion_obj_t *nex_obj = MP_OBJ_TO_PTR(obj);
        nex_listen_list[i] = &(nex_obj->nextion_obj);
    }
    for (size_t i = 0; i < len; i++) {
        mp_printf(&mp_plat_print,"Name : %s\n",nex_listen_list[i]->__name);
    }
    // Pass the list to nexLoop
    nexLoop(nex_listen_list);
    return mp_const_none;
}

static mp_obj_t nextion_Nextion_init(mp_obj_t self_in) {
    return nexInit() ? mp_const_true : mp_const_false;
}

static mp_obj_t nextion_Nextion_infos(mp_obj_t self_in) {
    mp_printf(&mp_plat_print, "Called infos method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_dettachPush(mp_obj_t self_in, mp_obj_t nex_object) {
    nextion_obj_t *nex_obj = MP_OBJ_TO_PTR(nex_object);
    NexTouch_detachPush(&(nex_obj->nextion_obj));
    return mp_const_none;
}

void nextion_push_callback_wrapper(void * ptr) {
    nextion_obj_t *nextion = (nextion_obj_t *)ptr;
    if (nextion->push_callback_obj != mp_const_none) {
        mp_call_function_0(nextion->push_callback_obj);
    }
}

static mp_obj_t nextion_Nextion_attachPush(mp_obj_t self_in, mp_obj_t nex_object, mp_obj_t callback_func) {
    nextion_obj_t *nex_obj = MP_OBJ_TO_PTR(nex_object);

    nex_obj->push_callback_obj = callback_func;
    // mp_printf(&mp_plat_print, "Push Callback attached at Page ID %d\n and Component ID %d\n",nex_obj->nextion_obj.__pid,nex_obj->nextion_obj.__cid);
    
    // test callback func
    // nextion_push_callback_wrapper(nex_obj);
    NexTouch_attachPush(&nex_obj->nextion_obj, nextion_push_callback_wrapper, nex_obj);
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_detachPop(mp_obj_t self_in, mp_obj_t nex_object) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    nextion_obj_t *nex_obj = MP_OBJ_TO_PTR(nex_object);
    NexTouch_detachPop(&(nex_obj->nextion_obj));
    return mp_const_none;
}


void nextion_pop_callback_wrapper(void * ptr) {
    nextion_obj_t *nextion = (nextion_obj_t *)ptr;
    if (nextion->pop_callback_obj != mp_const_none) {
        mp_call_function_0(nextion->pop_callback_obj);
    }
}

static mp_obj_t nextion_Nextion_attachPop(mp_obj_t self_in,  mp_obj_t nex_object, mp_obj_t callback_func) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    nextion_obj_t *nex_obj = MP_OBJ_TO_PTR(nex_object);

    nex_obj->pop_callback_obj = callback_func;
    mp_printf(&mp_plat_print, "Pop Callback attached at Page ID %d\n and Component ID %d\n",nex_obj->nextion_obj.__pid,nex_obj->nextion_obj.__cid);
    
    // test callback func
    // nextion_pop_callback_wrapper(nex_obj);
    NexTouch_attachPush(&(self->nextion_obj), nextion_pop_callback_wrapper, nex_obj);
    return mp_const_none;
}




/*
################################################################################
                End nextion Nextion Implementation
################################################################################
*/

/*
################################################################################
                       Nextion Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Nextion_nexLoop_obj, nextion_Nextion_nexLoop);
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Nextion_init_obj, nextion_Nextion_init);
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Nextion_infos_obj, nextion_Nextion_infos);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Nextion_dettachPush_obj, nextion_Nextion_dettachPush);
static MP_DEFINE_CONST_FUN_OBJ_3(nextion_Nextion_attachPush_obj, nextion_Nextion_attachPush);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Nextion_detachPop_obj, nextion_Nextion_detachPop);
static MP_DEFINE_CONST_FUN_OBJ_3(nextion_Nextion_attachPop_obj, nextion_Nextion_attachPop);

/*
################################################################################
                      End Nextion Declarations
################################################################################
*/


/*
################################################################################
                          Define Nextion
################################################################################
*/
static const mp_rom_map_elem_t nextion_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_nexLoop), MP_ROM_PTR(&nextion_Nextion_nexLoop_obj) },
    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&nextion_Nextion_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_infos), MP_ROM_PTR(&nextion_Nextion_infos_obj) },
    { MP_ROM_QSTR(MP_QSTR_dettachPush), MP_ROM_PTR(&nextion_Nextion_dettachPush_obj) },
    { MP_ROM_QSTR(MP_QSTR_attachPush), MP_ROM_PTR(&nextion_Nextion_attachPush_obj) },
    { MP_ROM_QSTR(MP_QSTR_detachPop), MP_ROM_PTR(&nextion_Nextion_detachPop_obj) },
    { MP_ROM_QSTR(MP_QSTR_attachPop), MP_ROM_PTR(&nextion_Nextion_attachPop_obj) },
};
static MP_DEFINE_CONST_DICT(nextion_locals_dict, nextion_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    nextion_type,
    MP_QSTR_Nextion,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_Nextion_make_new,
    locals_dict, &nextion_locals_dict
);
/*
################################################################################
                         End Define Nextion
################################################################################
*/
