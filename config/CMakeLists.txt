set(CXX_CLANG_TIDY)
add_library(Config GroundConfig.h EnviromentConfig.h FigureCategories.h CarConfig.h EvolutionAlgorithmConfig.h)
set_target_properties(Config PROPERTIES LINKER_LANGUAGE CXX)
