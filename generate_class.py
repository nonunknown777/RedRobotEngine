import sys
import os

def add_spaces_to_camel_case(input_str):
    result = ''
    for char in input_str:
        if char.isupper():
            result += ' ' + char
        else:
            result += char
    return result.strip()  # Remove leading space if any

def generate_class_files(path, class_name, extends_name):

    header_name = add_spaces_to_camel_case(class_name).upper().replace(" ","_");
    file_name = add_spaces_to_camel_case(class_name).lower().replace(" ", "_");

    extends_file_name = add_spaces_to_camel_case(extends_name).lower().replace(" ", "_");


    # Create .cpp file
    cpp_content = f'''#include "{file_name}.hpp"

{class_name}::{class_name}(std::string name = "{class_name}") : {extends_name}(name) {{
}}

{class_name}::~{class_name}() {{
}}
'''
    cpp_file_name = os.path.join(path, f'{file_name}.cpp')
    with open(cpp_file_name, 'w') as cpp_file:
        cpp_file.write(cpp_content)

    # Create .hpp file
    hpp_content = f'''#ifndef {header_name}_H
#define {header_name}_H

#include "{extends_file_name}.hpp"

class {class_name} : public {extends_name}{{
public:
    {class_name}(std::string name);
    ~{class_name}();
}};

#endif
'''
    hpp_file_name = os.path.join(path, f'{file_name}.hpp')
    with open(hpp_file_name, 'w') as hpp_file:
        hpp_file.write(hpp_content)

    print(f"Files:\n {cpp_file_name}\n  {hpp_file_name}\n generated successfully.")

if __name__ == "__main__":
    if len(sys.argv) != 3 and len(sys.argv) != 4:
        print("Usage: ./generate_class PATH ClassName [ExtendsClass]")
    else:
        script_path = os.path.dirname(os.path.abspath(__file__))
        path = os.path.join(script_path, sys.argv[1])
        class_name = sys.argv[2]
        extends_name = ""
        if len(sys.argv) == 4:
            extends_name = sys.argv[3]

        if not os.path.exists(path):
            os.makedirs(path)

        generate_class_files(path, class_name, extends_name)