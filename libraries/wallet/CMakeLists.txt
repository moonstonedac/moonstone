file(GLOB HEADERS "include/moonstone/wallet/*.hpp")

add_library( moonstone_wallet wallet.cpp ${HEADERS})
target_link_libraries( moonstone_wallet PRIVATE moonstone_app moonstone_net moonstone_chain moonstone_utilities fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
target_include_directories( moonstone_db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( wallet.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   moonstone_wallet

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/moonstone/wallet" )
