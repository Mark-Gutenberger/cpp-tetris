#
# Project settings
#

option(${PROJECT_NAME}_USE_ALT_NAMES "Use alternative names for the project, such as naming the include directory all lowercase." ON)


#
# Compiler options
#


option(${PROJECT_NAME}_WARNINGS_AS_ERRORS "Treat compiler warnings as errors." OFF)

#
# Static analyzers
#


option(${PROJECT_NAME}_ENABLE_CLANG_TIDY "Enable static analysis with Clang-Tidy." ON)
option(${PROJECT_NAME}_ENABLE_CPPCHECK "Enable static analysis with Cppcheck." ON)

#
# Code coverage
#


option(${PROJECT_NAME}_ENABLE_CODE_COVERAGE "Enable code coverage through GCC." CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)

#
# Miscelanious options
#

# Generate compile_commands.json for clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(${PROJECT_NAME}_VERBOSE_OUTPUT "Enable verbose output, allowing for a better understanding of each step taken." ON)
option(${PROJECT_NAME}_GENERATE_EXPORT_HEADER "Create a `project_export.h` file containing all exported symbols." OFF)

# Export all symbols when building a shared library
if(BUILD_SHARED_LIBS)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
endif()

option(${PROJECT_NAME}_ENABLE_LTO "Enable Interprocedural Optimization, aka Link Time Optimization (LTO)." OFF)
if(${PROJECT_NAME}_ENABLE_LTO)
include(CheckIPOSupported)
check_ipo_supported(RESULT result OUTPUT output)
if(result)
		set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
		else()
		message(SEND_ERROR "IPO is not supported: ${output}.")
		endif()
endif()

option(${PROJECT_NAME}_ENABLE_CCACHE "Enable the usage of Ccache, in order to speed up rebuild times." ON)
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif()
