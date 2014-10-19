include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
    main.cpp
	TestCard.hpp
)

add_executable(test_runner ${SOURCE_FILES})
target_link_libraries(test_runner PokerImpl ${Boost_LIBRARIES})

set (TEST test_runner)
enable_testing()