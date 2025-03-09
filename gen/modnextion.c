
#include "modnextion.h"

/*  
########################################
            Nextion Module
########################################
*/

extern const mp_obj_type_t nextion_type;
extern const mp_obj_type_t button_type;
extern const mp_obj_type_t text_type;
extern const mp_obj_type_t number_type;
extern const mp_obj_type_t page_type;
extern const mp_obj_type_t slider_type;
extern const mp_obj_type_t progressbar_type;

// Define module and its classes
static const mp_rom_map_elem_t nextion_module_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_nextion)},
    {MP_ROM_QSTR(MP_QSTR_Nextion), MP_ROM_PTR(&nextion_type)},
    {MP_ROM_QSTR(MP_QSTR_Button), MP_ROM_PTR(&button_type)},
    {MP_ROM_QSTR(MP_QSTR_Text), MP_ROM_PTR(&text_type)},
    {MP_ROM_QSTR(MP_QSTR_Number), MP_ROM_PTR(&number_type)},
    {MP_ROM_QSTR(MP_QSTR_Page), MP_ROM_PTR(&page_type)},
    {MP_ROM_QSTR(MP_QSTR_Slider), MP_ROM_PTR(&slider_type)},
    {MP_ROM_QSTR(MP_QSTR_ProgressBar), MP_ROM_PTR(&progressbar_type)}
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
