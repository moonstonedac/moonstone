file(GLOB HEADERS "include/moonstone/app/*.hpp")
file(GLOB EGENESIS_HEADERS "../egenesis/include/moonstone/app/*.hpp")

add_library( moonstone_app 
             api.cpp
             application.cpp
             database_api.cpp
             impacted.cpp
             plugin.cpp
             ${HEADERS}
             ${EGENESIS_HEADERS}
           )

target_link_libraries( moonstone_app moonstone_market_history moonstone_account_history moonstone_chain fc moonstone_db moonstone_net moonstone_time moonstone_utilities )
target_include_directories( moonstone_app
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
                            "${CMAKE_CURRENT_SOURCE_DIR}/../egenesis/include" )

if(MSVC)
  set_source_files_properties( application.cpp api.cpp database_api.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

INSTALL( TARGETS
   moonstone_app

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
INSTALL( FILES ${HEADERS} DESTINATION "include/moonstone/app" )
