#include "modnextion.h"
/*
// Auto-generated MicroPython class for ProgressBar

################################################################################
                    nextion ProgressBar Implementation
################################################################################
*/
typedef struct _nextion_progressbar_obj_t {
    mp_obj_base_t base;
    struct NexObject Progress;
    mp_obj_t pop_callback_obj;
    mp_obj_t push_callback_obj;
} progressbar_obj_t;

mp_obj_t nextion_ProgressBar_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    progressbar_obj_t *self = mp_obj_malloc(progressbar_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of ProgressBar called\n");
    if (self == NULL) {
        mp_raise_msg(&mp_type_MemoryError, "Failed to allocate ProgressBar object");
    }
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_ProgressBar_getValue(mp_obj_t self_in, mp_obj_t number) {
    progressbar_obj_t *self = MP_OBJ_TO_PTR(self_in);
     uint32_t value;
  if (NexProgressBar_getValue(&self->Progress, &value)) {
        mp_printf(&mp_plat_print, "ProgressBar Value: %u\n", value);
        return mp_obj_new_int(value); // Gibt den tatsächlichen Wert zurück
    } 
    else {
        mp_printf(&mp_plat_print, "Fehler: Konnte den Wert des ProgressBars nicht abrufen\n");
        return mp_const_none; // Gibt None zurück, wenn der Abruf fehlschlägt
    }
}



static mp_obj_t nextion_ProgressBar_setValue(mp_obj_t self_in, mp_obj_t number) {
    progressbar_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement setValue method logic here
        int value = mp_obj_get_int(number);

    // Überprüft, ob der Wert im gültigen Bereich liegt (z. B. 0 bis 100)
    if (value < 0 || value > 100) {
        mp_printf(&mp_plat_print, "Fehler: Wert %d außerhalb des gültigen Bereichs (0-100)\n", value);
        return mp_const_none;
    }

        if (NexProgressBar_setValue(&self->Progress, (uint32_t)value)) {
        mp_printf(&mp_plat_print, "ProgressBar-Wert erfolgreich auf %d gesetzt\n", value);
    } else {
        mp_printf(&mp_plat_print, "Fehler: Konnte den Wert des ProgressBars nicht setzen\n");
    }
 

    mp_printf(&mp_plat_print, "Called setValue method\n");
    return mp_const_none;
}

/*
################################################################################
                End nextion ProgressBar Implementation
################################################################################
*/

/*
################################################################################
                       ProgressBar Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_ProgressBar_getValue_obj, nextion_ProgressBar_getValue);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_ProgressBar_setValue_obj, nextion_ProgressBar_setValue);

/*
################################################################################
                      End ProgressBar Declarations
################################################################################
*/


/*
################################################################################
                          Define ProgressBar
################################################################################
*/
static const mp_rom_map_elem_t progressbar_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_getValue), MP_ROM_PTR(&nextion_ProgressBar_getValue_obj) },
    { MP_ROM_QSTR(MP_QSTR_setValue), MP_ROM_PTR(&nextion_ProgressBar_setValue_obj) },
};
static MP_DEFINE_CONST_DICT(progressbar_locals_dict, progressbar_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    progressbar_type,
    MP_QSTR_ProgressBar,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_ProgressBar_make_new,
    locals_dict, &progressbar_locals_dict
);
/*
################################################################################
                         End Define ProgressBar
################################################################################
*/
