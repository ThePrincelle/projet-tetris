cmake_minimum_required(VERSION 3.7)
include( CMakeParseArguments )

project(TP1_ProgAv LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

function(ADD_PRG)
	set(options OPTIONAL)
	set(oneValueArgs TARGET )
	set(multiValueArgs SOURCES)
	cmake_parse_arguments(ADD_PRG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

	add_executable(${ADD_PRG_TARGET} "")
	target_sources(${ADD_PRG_TARGET} PUBLIC ${ADD_PRG_SOURCES})
	if (${CMAKE_SYSTEM_NAME} MATCHES Linux)
		target_include_directories(${ADD_PRG_TARGET} PUBLIC /usr/include/SDL2)
		target_link_libraries(${ADD_PRG_TARGET} PUBLIC SDL2 SDL2main)
	else()
		target_link_libraries(${ADD_PRG_TARGET} PUBLIC SDL2::SDL2 SDL2::SDL2main)
	endif()
	target_compile_definitions(${ADD_PRG_TARGET} PUBLIC _USE_MATH_DEFINES)
endfunction()

ADD_PRG(TARGET TP_CPP_SDL SOURCES window_surface.h window_surface.cpp surface.h surface.cpp sprite.h sprite.cpp vec2.h vec2.cpp block.h block.cpp form.h form.cpp piece.h piece.cpp timer.h timer.cpp game.h game.cpp main.cpp)



file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/textures.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/background.bmp
		DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)


