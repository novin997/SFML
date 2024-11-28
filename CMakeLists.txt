cmake_minimum_required(VERSION 3.20)

project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0-rc.1)
FetchContent_MakeAvailable(SFML)

# find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network)

add_executable(CMakeSFMLProject src/main.cpp include/sprite.hpp)

target_include_directories(CMakeSFMLProject PRIVATE include)
target_link_libraries(CMakeSFMLProject PRIVATE SFML::Graphics SFML::Audio SFML::Network)
target_compile_features(CMakeSFMLProject PRIVATE cxx_std_20)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS CMakeSFMLProject)
