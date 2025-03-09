#include "modnextion.h"
/*
// Auto-generated MicroPython class for Nextion

################################################################################
                    nextion Nextion Implementation
################################################################################
*/
typedef struct _nextion_nextion_obj_t {
    mp_obj_base_t base;
} nextion_obj_t;

mp_obj_t nextion_Nextion_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    nextion_obj_t *self = mp_obj_malloc(nextion_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of Nextion called\n");
    if (self == NULL) {
        mp_raise_msg(&mp_type_MemoryError, "Failed to allocate Nextion object");
    }
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Nextion_nexLoop(mp_obj_t self_in) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement nexLoop method logic here
    mp_printf(&mp_plat_print, "Called nexLoop method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_init(mp_obj_t self_in) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement init method logic here
    mp_printf(&mp_plat_print, "Called init method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_infos(mp_obj_t self_in) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement infos method logic here
    mp_printf(&mp_plat_print, "Called infos method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_dettachPush(mp_obj_t self_in, mp_obj_t nex_object) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement dettachPush method logic here
    mp_printf(&mp_plat_print, "Called dettachPush method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_attachPush(mp_obj_t self_in, mp_obj_t nex_object, mp_obj_t callback_func) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement attachPush method logic here
    mp_printf(&mp_plat_print, "Called attachPush method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_detachPop(mp_obj_t self_in, mp_obj_t nex_object) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement detachPop method logic here
    mp_printf(&mp_plat_print, "Called detachPop method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Nextion_attachPop(mp_obj_t self_in, mp_obj_t nex_object, mp_obj_t callback_func) {
    nextion_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement attachPop method logic here
    mp_printf(&mp_plat_print, "Called attachPop method\n");
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
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Nextion_nexLoop_obj, nextion_Nextion_nexLoop);
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
