add_executable(listing_2_1 listing_2_1.cpp)
target_compile_options(listing_2_1 PUBLIC ${CODAC_CXX_FLAGS})
target_include_directories(listing_2_1 PUBLIC ${CODAC_INCLUDE_DIRS} ${PKG_CAPD_INCLUDE_DIRS})
target_link_libraries(listing_2_1 PUBLIC ${LIBS})

add_executable(listing_2_2 listing_2_2.cpp)
target_compile_options(listing_2_2 PUBLIC ${CODAC_CXX_FLAGS})
target_include_directories(listing_2_2 PUBLIC ${CODAC_INCLUDE_DIRS} ${PKG_CAPD_INCLUDE_DIRS})
target_link_libraries(listing_2_2 PUBLIC ${LIBS})