#include "modnextion.h"
/*
// Auto-generated MicroPython class for Page

################################################################################
                    nextion Page Implementation
################################################################################
*/
typedef struct _nextion_page_obj_t {
    mp_obj_base_t base;
} page_obj_t;

mp_obj_t nextion_Page_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    page_obj_t *self = mp_obj_malloc(page_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of Page called\n");
    if (self == NULL) {
        mp_raise_msg(&mp_type_MemoryError, "Failed to allocate Page object");
    }
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Page_show(mp_obj_t self_in) {
    page_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement show method logic here
    mp_printf(&mp_plat_print, "Called show method\n");
    return mp_const_none;
}

/*
################################################################################
                End nextion Page Implementation
################################################################################
*/

/*
################################################################################
                       Page Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Page_show_obj, nextion_Page_show);

/*
################################################################################
                      End Page Declarations
################################################################################
*/


/*
################################################################################
                          Define Page
################################################################################
*/
static const mp_rom_map_elem_t page_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_show), MP_ROM_PTR(&nextion_Page_show_obj) },
};
static MP_DEFINE_CONST_DICT(page_locals_dict, page_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    page_type,
    MP_QSTR_Page,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_Page_make_new,
    locals_dict, &page_locals_dict
);
/*
################################################################################
                         End Define Page
################################################################################
*/
