include(CMakeListsImpl.cmake)
message("gen-src" ${IMPL_GEN_SRCS})
set(IMPL_SRCS ${IMPL_SRCS}
    "src/impl/KaraCore.h"
    "src/impl/WorldLoader.h" "src/impl/WorldLoader.cpp"
    "src/impl/KaraGameViewPresenter.h" "src/impl/KaraGameViewPresenter.cpp"
    ${IMPL_GEN_SRCS}
    PARENT_SCOPE)
    