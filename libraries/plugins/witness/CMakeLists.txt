file(GLOB HEADERS "include/moonstone/witness/*.hpp")

add_library( moonstone_witness 
             witness.cpp
           )

target_link_libraries( moonstone_witness moonstone_chain moonstone_app moonstone_time )
target_include_directories( moonstone_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   moonstone_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
