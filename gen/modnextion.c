
#include "modnextion.h"

/*  
########################################
            Nextion Module
########################################
*/

extern const mp_obj_type_t serial_type;

// Define module and its classes
static const mp_rom_map_elem_t nextion_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_nextion)},
    {MP_ROM_QSTR(MP_QSTR_Serial), MP_ROM_PTR(&serial_type)}
};
static MP_DEFINE_CONST_DICT(nextion_module_globals, nextion_module_globals_table);

// Define module object.
const mp_obj_module_t nextion_user_cmodule = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&nextion_module_globals,
};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_nextion, nextion_user_cmodule);

/*  
########################################
           End Nextion Module
########################################
*/
