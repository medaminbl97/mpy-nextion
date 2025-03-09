#include "modnextion.h"
/*
// Auto-generated MicroPython class for Number

################################################################################
                    nextion Number Implementation
################################################################################
*/
typedef struct _nextion_number_obj_t {
    mp_obj_base_t base;
} number_obj_t;

mp_obj_t nextion_Number_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    number_obj_t *self = mp_obj_malloc(number_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of Number called\n");
    if (self == NULL) {
        mp_raise_msg(&mp_type_MemoryError, "Failed to allocate Number object");
    }
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Number_infos(mp_obj_t self_in) {
    number_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement infos method logic here
    mp_printf(&mp_plat_print, "Called infos method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Number_getText(mp_obj_t self_in, mp_obj_t len) {
    number_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement getText method logic here
    mp_printf(&mp_plat_print, "Called getText method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Number_setText(mp_obj_t self_in, mp_obj_t buffer) {
    number_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement setText method logic here
    mp_printf(&mp_plat_print, "Called setText method\n");
    return mp_const_none;
}

/*
################################################################################
                End nextion Number Implementation
################################################################################
*/

/*
################################################################################
                       Number Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Number_infos_obj, nextion_Number_infos);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Number_getText_obj, nextion_Number_getText);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Number_setText_obj, nextion_Number_setText);

/*
################################################################################
                      End Number Declarations
################################################################################
*/


/*
################################################################################
                          Define Number
################################################################################
*/
static const mp_rom_map_elem_t number_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_infos), MP_ROM_PTR(&nextion_Number_infos_obj) },
    { MP_ROM_QSTR(MP_QSTR_getText), MP_ROM_PTR(&nextion_Number_getText_obj) },
    { MP_ROM_QSTR(MP_QSTR_setText), MP_ROM_PTR(&nextion_Number_setText_obj) },
};
static MP_DEFINE_CONST_DICT(number_locals_dict, number_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    number_type,
    MP_QSTR_Number,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_Number_make_new,
    locals_dict, &number_locals_dict
);
/*
################################################################################
                         End Define Number
################################################################################
*/
