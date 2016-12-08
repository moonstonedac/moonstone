file(GLOB HEADERS "include/moonstone/market_history/*.hpp")

add_library( moonstone_market_history 
             market_history_plugin.cpp
           )

target_link_libraries( moonstone_market_history moonstone_chain moonstone_app )
target_include_directories( moonstone_market_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( market_history_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   moonstone_market_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/moonstone/market_history" )

