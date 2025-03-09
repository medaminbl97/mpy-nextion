import yaml


yaml_file = "classes.yml"
with open(yaml_file, 'r') as f:
    data = yaml.safe_load(f)

module_name = data['module']

# Templates for different files
to_module_funcs_c = """
/*
// Auto-generated MicroPython class for {class_name}

################################################################################
                    {module_name} {class_name} Implementation
################################################################################
*/
typedef struct _{module_name}_{struct_name}_obj_t {{
    mp_obj_base_t base;
}} {struct_name}_obj_t;

mp_obj_t {module_name}_{class_name}_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {{
    {struct_name}_obj_t *self = mp_obj_malloc({struct_name}_obj_t, type);
    mp_printf(&mp_plat_print, "Constructor of {class_name} called\\n");
    if (self == NULL) {{
        mp_raise_msg(&mp_type_MemoryError, "Failed to allocate {class_name} object");
    }}
    return MP_OBJ_FROM_PTR(self);
}}

{methods}
/*
################################################################################
                End {module_name} {class_name} Implementation
################################################################################
*/
"""

to_modmodule_h = """
/*
################################################################################
                       {class_name} Declarations
################################################################################
*/
{extern_methods}

/*
################################################################################
                      End {class_name} Declarations
################################################################################
*/

"""

to_modmodule_c = """
/*
################################################################################
                          Define {class_name}
################################################################################
*/
static const mp_rom_map_elem_t {struct_name}_locals_dict_table[] = {{
{method_mappings}
}};
static MP_DEFINE_CONST_DICT({struct_name}_locals_dict, {struct_name}_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    {struct_name}_type,
    MP_QSTR_{class_name},
    MP_TYPE_FLAG_NONE,
    make_new, {module_name}_{class_name}_make_new,
    locals_dict, &{struct_name}_locals_dict
);
/*
################################################################################
                         End Define {class_name}
################################################################################
*/
"""

METHOD_TEMPLATE = """
static mp_obj_t {module_name}_{class_name}_{method_name}(mp_obj_t self_in{method_args}) {{
    {struct_name}_obj_t *self = MP_OBJ_TO_PTR(self_in);
    // TODO: Implement {method_name} method logic here
    mp_printf(&mp_plat_print, "Called {method_name} method\\n");
    return mp_const_none;
}}
"""

def get_template(module_name : str, classes : list, extern_types : list):
    return f"""
#include "mod{module_name}.h"

/*  
########################################
            {module_name.capitalize()} Module
########################################
*/

{"\n".join(extern_types)}

// Define module and its classes
static const mp_rom_map_elem_t {module_name}_module_globals_table[] = {{
    {{MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_{module_name})}},
    {",\n    ".join(classes)}
}};
static MP_DEFINE_CONST_DICT({module_name}_module_globals, {module_name}_module_globals_table);

// Define module object.
const mp_obj_module_t {module_name}_user_cmodule = {{
    .base = {{ &mp_type_module }},
    .globals = (mp_obj_dict_t *)&{module_name}_module_globals,
}};

// Register the module to make it available in Python.
MP_REGISTER_MODULE(MP_QSTR_{module_name}, {module_name}_user_cmodule);

/*  
########################################
           End {module_name.capitalize()} Module
########################################
*/
"""


def generate_methods(class_name, struct_name, methods):
    method_strings = []
    extern_methods = []
    method_mappings = []

    for method in methods:
        method_name = method['name']
        args = ", ".join(f"mp_obj_t {arg}" for arg in method.get('args', []))
        method_args = f", {args}" if args else ""
        arg_count = len(method.get('args', [])) + 1
        method_body = f"// {method_name} method logic here"
        method_strings.append(METHOD_TEMPLATE.format(
            class_name=class_name,
            struct_name=struct_name,
            method_name=method_name,
            method_args=method_args,
            method_body=method_body,
            arg_count=arg_count,
            module_name=module_name
        ))
        extern_methods.append(f"static MP_DEFINE_CONST_FUN_OBJ_{arg_count}({module_name}_{class_name}_{method_name}_obj, {module_name}_{class_name}_{method_name});")
        method_mappings.append(f"    {{ MP_ROM_QSTR(MP_QSTR_{method_name}), MP_ROM_PTR(&{module_name}_{class_name}_{method_name}_obj) }},")

    return "\n".join(method_strings), "\n".join(extern_methods), "\n".join(method_mappings)


extern_types = []
classes = []

def generate_class(class_data):
    class_name = class_data['name']
    struct_name = class_name.lower()
    
    extern_types.append(f"extern const mp_obj_type_t {struct_name}_type;")
    classes.append(f"{{MP_ROM_QSTR(MP_QSTR_{class_name}), MP_ROM_PTR(&{struct_name}_type)}}")
    methods, extern_methods, method_mappings = generate_methods(class_name, struct_name, class_data['methods'])
    return (
        to_module_funcs_c.format(
            class_name=class_name,
            struct_name=struct_name,
            methods=methods,
            module_name=module_name
        ),
        to_modmodule_h.format(
            class_name=class_name,
            extern_methods=extern_methods,
            module_name=module_name
        ),
        to_modmodule_c.format(
            class_name=class_name,
            struct_name=struct_name,
            method_mappings=method_mappings,
            module_name=module_name
        )
    )


u_in = input("Class Name to be generated: ")

try:
    for class_data in data['classes']:
        if class_data['name'] != u_in and u_in != "all":
            continue
        module_funcs, modmodule_h, modmodule_c = generate_class(class_data)
        with open(f"{module_name}_{class_data['name'].lower()}.c", 'w') as f:
            f.write(f'#include "mod{module_name}.h"')
            f.write(module_funcs)
            f.write(modmodule_h)
            f.write(modmodule_c)
        
        with open(f"mod{module_name}.c", 'w') as f:
            f.write(get_template(module_name, classes, extern_types))
        with open(f"mod{module_name}.h", 'w') as f:
            f.write(
                f"""#ifndef MOD{module_name.upper()}_H
#define MOD{module_name.upper()}_H

#include \"py/obj.h\"\n

#endif                
                """)
except Exception as e:
    import traceback
    print(e)
    print("Error in reading classes.yml file at line:", traceback.extract_tb(e.__traceback__)[-1][1])
    exit(1)
