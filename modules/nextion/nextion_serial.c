#include "modnextion.h"
/*
// Auto-generated MicroPython class for Serial

################################################################################
                    nextion Serial Implementation
################################################################################
*/
typedef struct _nextion_serial_obj_t {
    mp_obj_base_t base;
} serial_obj_t;

mp_obj_t nextion_Serial_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    serial_obj_t *self = mp_obj_malloc(serial_obj_t, type);
    Serial_Init(9600);
    mp_printf(&mp_plat_print, "Uart 4 Initialized !\n");
    return MP_OBJ_FROM_PTR(self);
}

// Method to send data over UART
static mp_obj_t nextion_Serial_send(mp_obj_t self_in, mp_obj_t str_value) {
    serial_obj_t *self = MP_OBJ_TO_PTR(self_in);
    const char *str_to_send = mp_obj_str_get_str(str_value);
    for (const char *c = str_to_send; *c != '\0'; c++) {
        mp_printf(&mp_plat_print, "Sending char : %c \n", *c);
        Serial_Write(*c);
    }
    mp_printf(&mp_plat_print, "Following String sent : %s \n", str_to_send);
    return mp_const_none;
}

// Method to receive data from UART
static mp_obj_t nextion_Serial_rcv(mp_obj_t self_in) {
    serial_obj_t *self = MP_OBJ_TO_PTR(self_in);
    unsigned char c = Serial_Read();
    mp_printf(&mp_plat_print, "Received Value : %c \n", c);
    return mp_obj_new_str_via_qstr(&c, 1);
}
/*
################################################################################
                End nextion Serial Implementation
################################################################################
*/

/*
################################################################################
                       Serial Declarations
################################################################################
*/
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Serial_send_obj, nextion_Serial_send);
static MP_DEFINE_CONST_FUN_OBJ_1(nextion_Serial_rcv_obj, nextion_Serial_rcv);

/*
################################################################################
                      End Serial Declarations
################################################################################
*/


/*
################################################################################
                          Define Serial
################################################################################
*/
static const mp_rom_map_elem_t serial_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_send), MP_ROM_PTR(&nextion_Serial_send_obj) },
    { MP_ROM_QSTR(MP_QSTR_rcv), MP_ROM_PTR(&nextion_Serial_rcv_obj) },
};
static MP_DEFINE_CONST_DICT(serial_locals_dict, serial_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    serial_type,
    MP_QSTR_Serial,
    MP_TYPE_FLAG_NONE,
    make_new, nextion_Serial_make_new,
    locals_dict, &serial_locals_dict
);
/*
################################################################################
                         End Define Serial
################################################################################
*/
