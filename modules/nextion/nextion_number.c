#include "modnextion.h"
/*
// Auto-generated MicroPython class for Number

################################################################################
                    nextion Number Implementation
################################################################################
*/
typedef struct _nextion_number_obj_t {
    mp_obj_base_t base;
    struct NexObject number;
    mp_obj_t pop_callback_obj;
    mp_obj_t push_callback_obj;
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


static mp_obj_t nextion_Number_getValue(mp_obj_t self_in, mp_obj_t num) {
    // Konvertiere das Python-Objekt in ein number_obj_t-Pointer
    number_obj_t *self = MP_OBJ_TO_PTR(self_in);

    // Ausgabe zur Überprüfung, dass die Methode aufgerufen wurde
    mp_printf(&mp_plat_print, "Called getValue method\n");

    // Extrahiere die Ganzzahl aus dem mp_obj_t-Objekt
    uint32_t value = 0;

    // Rufe die Funktion auf, um den Wert aus dem Nextion-Objekt zu holen
    if (!NexNumber_getValue(&self->number, &value)) {
        mp_printf(&mp_plat_print, "Error: Failed to get value from Nextion display.\n");
        return mp_obj_new_int_from_uint(0); // Rückgabe 0 bei Fehler
    }

    // Gibt den erhaltenen Wert als MicroPython-Objekt zurück
    return mp_obj_new_int_from_uint(value);
}



static mp_obj_t nextion_Number_setValue(mp_obj_t self_in, mp_obj_t num) {
    // Konvertiere das Python-Objekt in ein number_obj_t-Pointer
    number_obj_t *self = MP_OBJ_TO_PTR(self_in);

    // Ausgabe zur Überprüfung, dass die Methode aufgerufen wurde
    mp_printf(&mp_plat_print, "Called setValue method\n");

    // Extrahiere die Ganzzahl aus dem mp_obj_t-Objekt
    int32_t value = mp_obj_get_int(num);

    // Setze den Wert im Nextion-Objekt und prüfe auf Erfolg
    if (!NexNumber_setValue(&self->number, value)) {
        mp_printf(&mp_plat_print, "Error: Failed to set value on Nextion display.\n");
    }

    // Rückgabe von None, um die Methode als vollständig abzuschließen
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
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Number_getValue_obj, nextion_Number_getValue);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Number_setValue_obj, nextion_Number_setValue);

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
    { MP_ROM_QSTR(MP_QSTR_getValue), MP_ROM_PTR(&nextion_Number_getValue_obj) },
    { MP_ROM_QSTR(MP_QSTR_setValue), MP_ROM_PTR(&nextion_Number_setValue_obj) },
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
