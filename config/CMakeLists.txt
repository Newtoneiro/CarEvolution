set(CXX_CLANG_TIDY)
add_library(Config GroundConfig.h EnviromentConfig.h)
set_target_properties(Config PROPERTIES LINKER_LANGUAGE CXX)
