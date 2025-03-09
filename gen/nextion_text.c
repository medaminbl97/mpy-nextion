#include "modnextion.h"
/*
// Auto-generated MicroPython class for Text

################################################################################
                    nextion Text Implementation
################################################################################
*/
typedef struct _nextion_text_obj_t {
    mp_obj_base_t base;
    struct NexObject text
} text_obj_t;

mp_obj_t nextion_Text_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    text_obj_t *self = mp_obj_malloc(text_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of Text called\n");
    if (n_args != 3) {
        mp_raise_msg(&mp_type_ValueError, "Expected 3 arguments");
    }
    CreateNexObject(self->text,(uint8_t)mp_obj_get_int(args[0]),(uint8_t)mp_obj_get_int(args[1]),mp_obj_str_get_str(args[2]));
    
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Text_infos(mp_obj_t self_in) {
    text_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement infos method logic here
    mp_printf(&mp_plat_print, "Called infos method\n");
    return mp_const_none;
}


static mp_obj_t nextion_Text_getText(mp_obj_t self_in, mp_obj_t len) {
    text_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement getText method logic here
     mp_printf(&mp_plat_print, "Nextion Text Object\n");
    mp_printf(&mp_plat_print, "Name : %s\n",self->text.__name);
    mp_printf(&mp_plat_print, "Page ID : %u\n",self->text.__pid);
    mp_printf(&mp_plat_print, "Component ID : %u\n",self->text.__cid);
    
    return mp_const_none;
}


static mp_obj_t nextion_Text_setText(mp_obj_t self_in, mp_obj_t buffer) {
    text_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement setText method logic here
    mp_printf(&mp_plat_print, "Called setText method\n");
    return mp_const_none;
}

/*
################################################################################
                End nextion Text Implementation
################################################################################
*/

/*
################################################################################
                       Text Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Text_infos_obj, nextion_Text_infos);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Text_getText_obj, nextion_Text_getText);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Text_setText_obj, nextion_Text_setText);

/*
################################################################################
                      End Text Declarations
################################################################################
*/


/*
################################################################################
                          Define Text
################################################################################
*/
static const mp_rom_map_elem_t text_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_infos), MP_ROM_PTR(&nextion_Text_infos_obj) },
    { MP_ROM_QSTR(MP_QSTR_getText), MP_ROM_PTR(&nextion_Text_getText_obj) },
    { MP_ROM_QSTR(MP_QSTR_setText), MP_ROM_PTR(&nextion_Text_setText_obj) },
};
static MP_DEFINE_CONST_DICT(text_locals_dict, text_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    text_type,
    MP_QSTR_Text,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_Text_make_new,
    locals_dict, &text_locals_dict
);
/*
################################################################################
                         End Define Text
################################################################################
*/
