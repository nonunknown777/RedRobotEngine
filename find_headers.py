import os

def find_hpp_files(directory):
    hpp_files = []
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".hpp"):
                hpp_files.append(os.path.join(root, file))
    return hpp_files

def generate_include_list(hpp_files):
    include_list = [f'#include "{os.path.basename(file)}"' for file in hpp_files]
    return include_list

if __name__ == "__main__":
    target_directory = input("Enter the target directory: ")
    
    hpp_files_list = find_hpp_files(target_directory)

    if hpp_files_list:
        include_list = generate_include_list(hpp_files_list)
        print("Generated Include List:")
        for include_statement in include_list:
            print(include_statement)
    else:
        print("No .hpp files found.")
