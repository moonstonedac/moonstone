file(GLOB HEADERS "include/moonstone/time/*.hpp")

add_library( moonstone_time
             time.cpp
           )

target_link_libraries( moonstone_time fc )
target_include_directories( moonstone_time
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   moonstone_time

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/moonstone/time" )
