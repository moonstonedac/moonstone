file(GLOB HEADERS "include/moonstone/utilities/*.hpp")

set(sources
   key_conversion.cpp
   string_escape.cpp
   tempdir.cpp
   words.cpp
   ${HEADERS})

add_library( moonstone_utilities
             ${sources}
             ${HEADERS} )
target_link_libraries( moonstone_utilities fc )
target_include_directories( moonstone_utilities
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
if (USE_PCH)
  set_target_properties(moonstone_utilities PROPERTIES COTIRE_ADD_UNITY_BUILD FALSE)
  cotire(moonstone_utilities)
endif(USE_PCH)

install( TARGETS
   moonstone_utilities

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/moonstone/utilities" )
