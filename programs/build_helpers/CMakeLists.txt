
add_executable( cat-parts cat-parts.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

# we only actually need Boost, but link against FC for now so we don't duplicate it.
target_link_libraries( cat-parts PRIVATE fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

add_executable( member_enumerator member_enumerator.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

# we only actually need Boost, but link against FC for now so we don't duplicate it.
target_link_libraries( member_enumerator PRIVATE fc moonstone_app moonstone_net moonstone_chain moonstone_egenesis_brief moonstone_utilities moonstone_wallet ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )

