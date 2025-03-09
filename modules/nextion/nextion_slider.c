#include "modnextion.h"
/*
// Auto-generated MicroPython class for Slider

################################################################################
                    nextion Slider Implementation
################################################################################
*/
typedef struct _nextion_slider_obj_t {
    mp_obj_base_t base;
    struct NexObject slider;
    mp_obj_t pop_callback_obj;
    mp_obj_t push_callback_obj;

} slider_obj_t;

mp_obj_t nextion_Slider_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    slider_obj_t *self = mp_obj_malloc(slider_obj_t, type);
    if (n_args != 3) {
        mp_raise_msg(&mp_type_ValueError, "Expected 3 arguments");
    }
    CreateNexObject(self->slider,(uint8_t)mp_obj_get_int(args[0]),(uint8_t)mp_obj_get_int(args[1]),mp_obj_str_get_str(args[2]));
    mp_printf(&mp_plat_print, "Constructor of Slider called\n");
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Slider_getValue(mp_obj_t self_in, mp_obj_t number) {
    slider_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement getValue method logic here
    mp_printf(&mp_plat_print, "Called getValue method\n");
    uint32_t* value=(uint32_t*)MP_OBJ_TO_PTR(value);
    if (NexSlider_getValue(&self->slider, &value)) {
        mp_printf(&mp_plat_print, "Slider-Wert abgerufen: %u\n", value);
        return mp_obj_new_int(value); // Gibt den Wert als MicroPython-Integer zurück
    } else {
        mp_printf(&mp_plat_print, "Fehler: Konnte den Wert des Sliders nicht abrufen\n");
        return mp_const_none;
    }

    
}



static mp_obj_t nextion_Slider_setValue(mp_obj_t self_in, mp_obj_t number) {
    slider_obj_t *self = MP_OBJ_TO_PTR(self_in);

    // Konvertiert das MicroPython-Objekt in einen Integerwert
    int value = mp_obj_get_int(number);

    // Optional: Überprüft, ob der Wert im gültigen Bereich liegt (z. B. 0 bis 100)
    if (value < 0 || value > 100) {
        mp_printf(&mp_plat_print, "Fehler: Wert %d außerhalb des gültigen Bereichs (0-100)\n", value);
        return mp_const_none;
    }

    // Setzt den Wert des Sliders
    if (NexSlider_setValue(&self->slider, (uint32_t)value)) {
        mp_printf(&mp_plat_print, "Slider-Wert erfolgreich auf %d gesetzt\n", value);
    } else {
        mp_printf(&mp_plat_print, "Fehler: Konnte den Wert des Sliders nicht setzen\n");
    }

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
