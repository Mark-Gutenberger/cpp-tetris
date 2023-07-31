file(GLOB_RECURSE
	exe_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE
	headers "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)
file(GLOB_RECURSE
	test_sources "tests/*.cpp"
)

set(public_link_targets "")
set(private_link_targets ncurses)
