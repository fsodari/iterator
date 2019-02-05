add_library(iterator src/iterator.c)
target_include_directories(iterator PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/iterator>
        )
target_include_directories(iterator PRIVATE src)

if(${REPLACE_MALLOC})
    target_compile_options(iterator PRIVATE -include  /usr/local/include/CppUTest/MemoryLeakDetectorMallocMacros.h)
    target_link_libraries(iterator CppUTest CppUTestExt)
endif()

install(TARGETS iterator
        EXPORT iterator-targets
        PUBLIC_HEADER DESTINATION include/iterator
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
install(FILES include/iterator/iterator.h DESTINATION include/iterator)
install(EXPORT iterator-targets
        FILE iterator-config.cmake
        DESTINATION lib/cmake/iterator)

add_executable(iterator_main main.c)
target_include_directories(iterator_main PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_link_libraries(iterator_main iterator)
