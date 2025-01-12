cmake_minimum_required(VERSION 3.5)
project(E3D LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the root directory containing the source files
set(SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")

# Define directories to exclude (e.g., build, CMake-related folders)
set(EXCLUDE_DIRS "${SOURCE_ROOT}/build" "${SOURCE_ROOT}/CMakeFiles")

# Recursively collect all .cpp and .h files in the directory structure
file(GLOB_RECURSE LIBRARY_SOURCES "${SOURCE_ROOT}/*.cpp")
file(GLOB_RECURSE LIBRARY_HEADERS "${SOURCE_ROOT}/*.h")

# Function to exclude unwanted files based on directories
function(filter_out_excluded_dirs file_list output_list)
    foreach(exclude_dir ${EXCLUDE_DIRS})
        list(FILTER ${file_list} EXCLUDE REGEX "${exclude_dir}/.*")
    endforeach()
    set(${output_list} ${${file_list}} PARENT_SCOPE)
endfunction()

# Apply the filtering function
filter_out_excluded_dirs(LIBRARY_SOURCES FILTERED_LIBRARY_SOURCES)
filter_out_excluded_dirs(LIBRARY_HEADERS FILTERED_LIBRARY_HEADERS)

# Optionally display the list of files found (for debugging purposes)
# message(STATUS "Source Files: ${LIBRARY_SOURCES}")
# message(STATUS "Header Files: ${LIBRARY_HEADERS}")

# Add a library target with the collected source files
add_library(${PROJECT_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})

# Include directories for the library target
# Add the root source directory as an include directory
# You can add additional directories here if needed
# set(LIBRARY_INCLUDE_DIRS "$(ProjectDir)../../../sdks/OpenGL;$(ProjectDir)../../../sdks/FileLib/src;$(ProjectDir)../../../sdks/TexLib;$(ProjectDir)../..;$(ProjectDir)..")
set(LIBRARY_INCLUDE_DIRS "${SOURCE_ROOT}/../../sdks/OpenGL;${SOURCE_ROOT}/../../sdks/FileLib/src;${SOURCE_ROOT}/../../sdks/TexLib;${SOURCE_ROOT}/..;${SOURCE_ROOT}/")
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBRARY_INCLUDE_DIRS})

# Add install rules for the library (optional)
install(TARGETS ${PROJECT_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY ${LIBRARY_INCLUDE_DIRS}/ DESTINATION include FILES_MATCHING PATTERN "*.h")
