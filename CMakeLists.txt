cmake_minimum_required (VERSION 3.20)

project (Zelda LANGUAGES CXX VERSION 0.1)

include(CTest)
enable_testing()

include(${CMAKE_SOURCE_DIR}/cmake/option.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/CompilerWarnings.cmake)

set_choice (CMAKE_BUILD_TYPE "Debug;Release;MinSizeRel;RelWithDebInfo" "Debug" "Choose type of build")

set (SRCS
	src/main.cpp
)

set (HEADERS
    
)

set (ASSETS
    assets/link.png
)

if (MINGW)
    set (CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

    if (${CMAKE_BUILD_TYPE} MATCHES "Debug" OR ${CMAKE_BUILD_TYPE} MATCHES "RelWithDebInfo")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
endif (MINGW)

message(STATUS "${CMAKE_MODULE_PATH}")

find_package(SDL2pp REQUIRED)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set_sanitizer ()

add_executable(${PROJECT_NAME} ${SRCS} ${HEADERS})
#set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${HEADERS})
target_link_libraries(${PROJECT_NAME} SDL2pp::SDL2pp)
set_target_warnings(${PROJECT_NAME})

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME} DESTINATION .)
install(DIRECTORY assets/ DESTINATION assets)

foreach(df ${ASSETS})
    file(COPY ${df} DESTINATION ${CMAKE_BINARY_DIR}/assets)
endforeach()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)