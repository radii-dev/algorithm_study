file(GLOB SRC_FILES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

foreach(srcfiles ${SRC_FILES})
    get_filename_component(srcnames ${srcfiles} NAME_WE)
    add_executable(${srcnames} ${srcfiles})
    #target_link_libraries(${srcfiles} PUBLIC yourlib)
endforeach()

