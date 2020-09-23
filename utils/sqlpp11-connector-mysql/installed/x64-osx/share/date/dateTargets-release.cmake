#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "date::date-tz" for configuration "Release"
set_property(TARGET date::date-tz APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(date::date-tz PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdate-tz.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS date::date-tz )
list(APPEND _IMPORT_CHECK_FILES_FOR_date::date-tz "${_IMPORT_PREFIX}/lib/libdate-tz.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
