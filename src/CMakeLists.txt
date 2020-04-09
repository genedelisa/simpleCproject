cmake_minimum_required (VERSION 3.10.3)

# do not glob! just use ls -1
set(SOURCE_FILES 
    main.c
    logger.c
    sigz.c
)

add_executable(main 
    ${SOURCE_FILES}
)

set_target_properties(main
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_compile_features(main
    PUBLIC
        c_std_11
)

# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_COMPILER_ID.html
target_compile_options(main
	PRIVATE

# Apple Clang    
    #https://clang.llvm.org/docs/DiagnosticsReference.html#wall
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wall>"

    #https://clang.llvm.org/docs/DiagnosticsReference.html#wextra
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wextra>"

    # https://clang.llvm.org/docs/UsersManual.html#cmdoption-pedantic
    "$<$<CXX_COMPILER_ID:AppleClang>:-pedantic>"

    # complains that argc and argv are not used. so shut up about that.
    "$<$<CXX_COMPILER_ID:AppleClang>:-Wno-unused-parameter>"

    #https://clang.llvm.org/docs/UsersManual.html#cmdoption-g
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-g3>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-O0>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:DEBUG>>:-DDEBUG>"

     "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-DNDEBUG>"
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-O3>"
    #https://clang.llvm.org/docs/UsersManual.html#cmdoption-g0
    "$<$<AND:$<CXX_COMPILER_ID:AppleClang>,$<CONFIG:RELEASE>>:-g0>"

# Microsoft
#   https://msdn.microsoft.com/en-us/library/thxezb7y.aspx#Anchor_1
    $<$<CXX_COMPILER_ID:MSVC>:/W4>

# GNU
#   https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#index-Wall-316
    $<$<CXX_COMPILER_ID:GNU>:-fembed-bitcode>
    "$<$<AND:$<CXX_COMPILER_ID:GNU>,$<CONFIG:DEBUG>>:-fno-omit-frame-pointer>"

# Non Apple Clang    
#   http://clang.llvm.org/docs/DiagnosticsReference.html#wall
    $<$<CXX_COMPILER_ID:Clang>:-Wall>
    $<$<CXX_COMPILER_ID:Clang>:-Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-pedantic> 

)

# If you want to add a library. Here's is curses for fun.
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
# needs to be after add_executable
target_link_libraries(main ${CURSES_LIBRARIES})
 