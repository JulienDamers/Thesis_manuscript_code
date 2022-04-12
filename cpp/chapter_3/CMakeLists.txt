add_executable(listing_3_1 listing_3_1.cpp)
target_compile_options(listing_3_1 PUBLIC ${CODAC_CXX_FLAGS})
target_include_directories(listing_3_1 PUBLIC ${CODAC_INCLUDE_DIRS} ${PKG_CAPD_INCLUDE_DIRS})
target_link_libraries(listing_3_1 PUBLIC ${LIBS})

add_executable(listing_3_2 listing_3_2.cpp)
target_compile_options(listing_3_2 PUBLIC ${CODAC_CXX_FLAGS})
target_include_directories(listing_3_2 PUBLIC ${CODAC_INCLUDE_DIRS} ${PKG_CAPD_INCLUDE_DIRS})
target_link_libraries(listing_3_2 PUBLIC ${LIBS})