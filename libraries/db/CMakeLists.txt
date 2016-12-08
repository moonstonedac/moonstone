file(GLOB HEADERS "include/moonstone/db/*.hpp")
add_library( moonstone_db undo_database.cpp index.cpp object_database.cpp ${HEADERS} )
target_link_libraries( moonstone_db fc )
target_include_directories( moonstone_db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   moonstone_db

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/moonstone/db" )
