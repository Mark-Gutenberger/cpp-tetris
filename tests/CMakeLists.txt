foreach(file ${test_sources})
    string(REGEX REPLACE "(.*/)([a-zA-Z0-9_ ]+)(\.cpp)" "\\2" test_name ${file})
    add_executable(${test_name}_Tests ${file})

    # Set the compiler standard
    target_compile_features(${test_name}_Tests PUBLIC cxx_std_17)

    # Setup code coverage if enabled
    if(${CMAKE_PROJECT_NAME}_ENABLE_CODE_COVERAGE)
        target_compile_options(${test_name}_Tests PUBLIC -O0 -g --coverage)
        target_link_options(${test_name}_Tests PUBLIC --coverage)
        message("Code coverage is enabled.")
    endif()

    # Load the unit testing framework
    set(${CMAKE_PROJECT_NAME}_TEST_LIB ${CMAKE_PROJECT_NAME}_LIB)

    find_package(GTest REQUIRED)

    if(${CMAKE_PROJECT_NAME}_USE_GOOGLE_MOCK)
        set(GOOGLE_MOCK_LIBRARIES GTest::gmock GTest::gmock_main)
    endif()

    target_link_libraries(${test_name}_Tests PRIVATE
        GTest::GTest
        GTest::Main
        ${GOOGLE_MOCK_LIBRARIES}
        ${${CMAKE_PROJECT_NAME}_TEST_LIB}
    )

    # Add the unit tests
    add_test(NAME ${test_name} COMMAND ${test_name}_Tests)
endforeach()
