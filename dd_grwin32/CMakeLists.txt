set(HEADERS
  ddgrWin32.h
  ddgrWin32DX.h
  ddgrWin32GDI.h)
set(CPPS
  ddgrWin32API.cpp
  ddgrWin32DX.cpp
  ddgrWin32GDI.cpp
  ddgrWin32Init.cpp)

add_library(dd_grwin32 STATIC ${HEADERS} ${CPPS})
