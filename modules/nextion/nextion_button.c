#include "modnextion.h"
/*
// Auto-generated MicroPython class for Button

################################################################################
                    nextion Button Implementation
################################################################################
*/
typedef struct _nextion_button_obj_t {
    mp_obj_base_t base;
    struct NexObject button;
    mp_obj_t pop_callback_obj;
    mp_obj_t push_callback_obj;
} button_obj_t;

mp_obj_t nextion_Button_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    button_obj_t *self = mp_obj_malloc(button_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of Button called\n");
    if (n_args != 3) {
        mp_raise_msg(&mp_type_ValueError, "Expected 3 arguments");
    }
    CreateNexObject(self->button,(uint8_t)mp_obj_get_int(args[0]),(uint8_t)mp_obj_get_int(args[1]),mp_obj_str_get_str(args[2]));
    return MP_OBJ_FROM_PTR(self);
}


static mp_obj_t nextion_Button_infos(mp_obj_t self_in) {
    button_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement infos method logic here
    mp_printf(&mp_plat_print, "Nextion Button Object\n");
    mp_printf(&mp_plat_print, "Name : %s\n",self->button.__name);
    mp_printf(&mp_plat_print, "Page ID : %u\n",self->button.__pid);
    mp_printf(&mp_plat_print, "Component ID : %u\n",self->button.__cid);
    return mp_const_none;
}




static mp_obj_t nextion_Button_getText(mp_obj_t self_in, mp_obj_t len) {
    button_obj_t *self = MP_OBJ_TO_PTR(self_in);

    // Ruft die maximale Länge als Integer ab
    uint16_t m_len = (uint16_t)mp_obj_get_int(len);

    // Begrenze die Länge auf die maximale Puffergröße, um Überläufe zu vermeiden
    if (m_len > 127) {
        mp_printf(&mp_plat_print, "Warnung: Länge %d überschreitet das Pufferlimit von 127 Zeichen. Gekürzt auf 127.\n", m_len);
        m_len = 127;
    }

    char buff[128] = {0}; // Initialisiert den Puffer mit Nullen

    // Ruft den Text vom Button ab
    if (NexButton_getText(&self->button, buff, m_len)) {
        mp_printf(&mp_plat_print, "Button-Text abgerufen: %s\n", buff);
        return mp_obj_new_str(buff, strlen(buff)); // Gibt den tatsächlichen Text als MicroPython-String zurück
    } else {
        mp_printf(&mp_plat_print, "Fehler: Konnte den Button-Text nicht abrufen\n");
        return mp_const_none;
    }
}





static mp_obj_t nextion_Button_setText(mp_obj_t self_in, mp_obj_t buffer) {
    button_obj_t *self = MP_OBJ_TO_PTR(self_in);

    // Konvertiert das MicroPython-Objekt in einen C-String
    const char *Text = mp_obj_str_get_str(buffer);

    // Optional: Überprüft die maximale Länge des Textes
    size_t max_length = 127; // Angenommen, 127 Zeichen sind das Limit
    if (strlen(Text) > max_length) {
        mp_printf(&mp_plat_print, "Warnung: Text ist länger als %zu Zeichen und wird abgeschnitten.\n", max_length);
    }

    // Setzt den Text auf den Button
    if (NexButton_setText(&self->button, Text)) {
        mp_printf(&mp_plat_print, "Button-Text erfolgreich auf '%s' gesetzt\n", Text);
    } else {
        mp_printf(&mp_plat_print, "Fehler: Konnte den Button-Text nicht setzen\n");
    }

    return mp_const_none;
}



/*
################################################################################
                End nextion Button Implementation
################################################################################
*/

/*
################################################################################
                       Button Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Button_infos_obj, nextion_Button_infos);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Button_getText_obj, nextion_Button_getText);
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Button_setText_obj, nextion_Button_setText);

/*
################################################################################
                      End Button Declarations
################################################################################
*/


/*
################################################################################
                          Define Button
################################################################################
*/
static const mp_rom_map_elem_t button_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_infos), MP_ROM_PTR(&nextion_Button_infos_obj) },
    { MP_ROM_QSTR(MP_QSTR_getText), MP_ROM_PTR(&nextion_Button_getText_obj) },
    { MP_ROM_QSTR(MP_QSTR_setText), MP_ROM_PTR(&nextion_Button_setText_obj) },
};
static MP_DEFINE_CONST_DICT(button_locals_dict, button_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    button_type,
    MP_QSTR_Button,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_Button_make_new,
    locals_dict, &button_locals_dict
);
/*
################################################################################
                         End Define Button
################################################################################
*/
