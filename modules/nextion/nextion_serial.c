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
    mp_printf(&mp_plat_print, "Received Value : %s \n", c);
    return mp_obj_new_str_via_qstr(&c, 1);
}

static mp_obj_t nextion_Serial_read(mp_obj_t self_in, mp_obj_t len_in) {
    serial_obj_t *self = MP_OBJ_TO_PTR(self_in);

    // Get the length of bytes to read
    unsigned char len = mp_obj_get_int(len_in);
    printf("Requested to read %d bytes\n", len); // Debug print

    // Allocate a buffer to store the received bytes
    char *buf = m_new(char, len + 1); // +1 for null terminator
    printf("Buffer allocated\n"); // Debug print

    // Call Serial_ReadBytes to read the data
    unsigned char bytes_read = Serial_ReadBytes(buf, len);
    printf("Read %d bytes from UART\n", bytes_read); // Debug print

    // Null-terminate the buffer to make it a valid C string
    buf[bytes_read] = '\0';
    printf("Buffer null-terminated\n"); // Debug print

    // Print the received data for inspection
    printf("Received data: %s\n", buf); // Debug print

    // Create a Python string object from the buffer
    mp_obj_t str_obj = mp_obj_new_str(buf, bytes_read);
    printf("Python string object created\n"); // Debug print

    // Free the buffer
    m_del(char, buf, len + 1);
    printf("Buffer freed\n"); // Debug print

    // Return the string object
    return str_obj;
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
static MP_DEFINE_CONST_FUN_OBJ_2(nextion_Serial_read_obj, nextion_Serial_read);

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
    { MP_ROM_QSTR(MP_QSTR_read), MP_ROM_PTR(&nextion_Serial_read_obj) }
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
