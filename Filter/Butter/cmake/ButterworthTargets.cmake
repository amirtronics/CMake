target_include_directories(ButterworthFilter INTERFACE "$<INSTALL_INTERFACE:include>")
target_link_libraries(ButterworthFilter INTERFACE "$<INSTALL_INTERFACE:lib>")

# Additional settings, if needed
# target_compile_options(ButterworthFilter INTERFACE ...)
