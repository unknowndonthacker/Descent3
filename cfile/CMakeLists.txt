set(CPPS
  cfile.cpp
  hogfile.cpp
  inffile.cpp
)

add_library(cfile STATIC ${CPPS})
target_include_directories(cfile PUBLIC
  $<BUILD_INTERFACE:
    ${PROJECT_SOURCE_DIR}/cfile
  >
)
