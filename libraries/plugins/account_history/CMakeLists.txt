file(GLOB HEADERS "include/moonstone/account_history/*.hpp")

add_library( moonstone_account_history 
             account_history_plugin.cpp
           )

target_link_libraries( moonstone_account_history moonstone_chain moonstone_app )
target_include_directories( moonstone_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( account_history_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   moonstone_account_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/moonstone/account_history" )

