file(GLOB HEADERS "include/moonstone/delayed_node/*.hpp")

add_library( moonstone_delayed_node 
             delayed_node_plugin.cpp
           )

target_link_libraries( moonstone_delayed_node moonstone_chain moonstone_app )
target_include_directories( moonstone_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   moonstone_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
