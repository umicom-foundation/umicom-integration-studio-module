#-----------------------------------------------------------------------------
# Umicom Integration Studio Module
# File: CMakeLists.txt
#
# PURPOSE:
#   Build a thin C23 product composition over Framework-owned application
#   experience, runtime and workbench contracts.
#
# Created by: Sammy Hegab
# Organisation: Umicom Foundation
# Licence: MIT
#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.24)

project(
    IntegrationStudioModule
    VERSION 0.1.0
    DESCRIPTION "Thin Umicom Integration Studio composition over Umicom Framework"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(UMICOM_INTEGRATION_STUDIO_BUILD_CONSOLE
       "Build the native Umicom Integration Studio verification console"
       ON)

include(CTest)
include(GNUInstallDirs)

if(NOT TARGET Umicom::Framework)
    find_package(UmicomFramework CONFIG REQUIRED)
endif()

if(NOT TARGET Umicom::application)
    message(FATAL_ERROR
        "Umicom Integration Studio requires Framework target Umicom::application")
endif()

if(NOT COMMAND umicom_apply_warnings)
    function(umicom_apply_warnings target)
        if(MSVC)
            target_compile_options(${target} PRIVATE /W4)
        else()
            target_compile_options(${target} PRIVATE
                -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
        endif()
    endfunction()
endif()

if(NOT COMMAND umicom_apply_sanitizers)
    function(umicom_apply_sanitizers target)
    endfunction()
endif()

add_library(umicom_integration_studio_module STATIC
    src/application.c
    src/workspace.c
)
add_library(Umicom::integration_studio_module ALIAS umicom_integration_studio_module)

target_include_directories(umicom_integration_studio_module PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(umicom_integration_studio_module PUBLIC
    Umicom::Framework
    Umicom::application
)
umicom_apply_warnings(umicom_integration_studio_module)
umicom_apply_sanitizers(umicom_integration_studio_module)

if(UMICOM_INTEGRATION_STUDIO_BUILD_CONSOLE)
    add_executable(umicom-integration-studio-console
        src/console/main.c)
    target_link_libraries(umicom-integration-studio-console PRIVATE Umicom::integration_studio_module)
    umicom_apply_warnings(umicom-integration-studio-console)
    umicom_apply_sanitizers(umicom-integration-studio-console)
endif()

if(BUILD_TESTING)
    add_executable(integration_studio-application-test
        tests/test_application.c)
    target_link_libraries(integration_studio-application-test PRIVATE Umicom::integration_studio_module)
    umicom_apply_warnings(integration_studio-application-test)
    umicom_apply_sanitizers(integration_studio-application-test)
    add_test(NAME integration-studio.module.application
             COMMAND integration_studio-application-test)

    add_executable(integration_studio-workspace-test
        tests/test_workspace.c)
    target_link_libraries(integration_studio-workspace-test PRIVATE Umicom::integration_studio_module)
    umicom_apply_warnings(integration_studio-workspace-test)
    umicom_apply_sanitizers(integration_studio-workspace-test)
    add_test(NAME integration-studio.module.workspace
             COMMAND integration_studio-workspace-test)
endif()

install(TARGETS umicom_integration_studio_module
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
if(TARGET umicom-integration-studio-console)
    install(TARGETS umicom-integration-studio-console
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES application.umicom.yaml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/umicom/applications/integration-studio)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    install(FILES LICENSE
        DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/integration-studio)
endif()

message(STATUS "Umicom Integration Studio Module version: ${PROJECT_VERSION}")
message(STATUS "Umicom Integration Studio uses Framework-owned application experience")
