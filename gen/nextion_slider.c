#include "modnextion.h"
/*
// Auto-generated MicroPython class for Slider

################################################################################
                    nextion Slider Implementation
################################################################################
*/
typedef struct _nextion_slider_obj_t {
    mp_obj_base_t base;
} slider_obj_t;

mp_obj_t nextion_Slider_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    slider_obj_t *self = mp_obj_malloc(slider_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of Slider called\n");
    if (self == NULL) {
        mp_raise_msg(&mp_type_MemoryError, "Failed to allocate Slider object");
    }
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Slider_getValue(mp_obj_t self_in, mp_obj_t number) {
    slider_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement getValue method logic here
    mp_printf(&mp_plat_print, "Called getValue method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Slider_setValue(mp_obj_t self_in, mp_obj_t number) {
    slider_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement setValue method logic here
    mp_printf(&mp_plat_print, "Called setValue method\n");
    return mp_const_none;
}

/*
################################################################################
                End nextion Slider Implementation
################################################################################
*/

/*
################################################################################
                       Slider Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Slider_getValue_obj, nextion_Slider_getValue);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Slider_setValue_obj, nextion_Slider_setValue);

/*
################################################################################
                      End Slider Declarations
################################################################################
*/


/*
################################################################################
                          Define Slider
################################################################################
*/
static const mp_rom_map_elem_t slider_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_getValue), MP_ROM_PTR(&nextion_Slider_getValue_obj) },
    { MP_ROM_QSTR(MP_QSTR_setValue), MP_ROM_PTR(&nextion_Slider_setValue_obj) },
};
static MP_DEFINE_CONST_DICT(slider_locals_dict, slider_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    slider_type,
    MP_QSTR_Slider,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_Slider_make_new,
    locals_dict, &slider_locals_dict
);
/*
################################################################################
                         End Define Slider
################################################################################
*/
