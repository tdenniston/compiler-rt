# First, add the subdirectories which contain feature-based runtime libraries
# and several convenience helper libraries.

include(AddCompilerRT)
include(SanitizerUtils)

if(COMPILER_RT_HAS_INTERCEPTION)
  add_subdirectory(interception)
endif()

if(COMPILER_RT_HAS_SANITIZER_COMMON)
  add_subdirectory(sanitizer_common)
  add_subdirectory(cfi)
  add_subdirectory(lsan)
  add_subdirectory(ubsan)
endif()

if(COMPILER_RT_HAS_ASAN)
  add_subdirectory(asan)
endif()

add_subdirectory(builtins)

if(COMPILER_RT_HAS_DFSAN)
  add_subdirectory(dfsan)
endif()

if(COMPILER_RT_HAS_MSAN)
  add_subdirectory(msan)
endif()

if(COMPILER_RT_HAS_PROFILE)
  add_subdirectory(profile)
endif()

if(COMPILER_RT_HAS_TSAN)
  add_subdirectory(tsan)
  add_subdirectory(tsan/dd)
endif()

if(COMPILER_RT_HAS_SAFESTACK)
  add_subdirectory(safestack)
endif()
