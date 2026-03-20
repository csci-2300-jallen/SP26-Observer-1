# cmake/RunAppAndCheck.cmake
cmake_minimum_required(VERSION 3.16)

if(NOT DEFINED APP)
  message(FATAL_ERROR "APP not set")
endif()
if(NOT DEFINED INPUT_FILE)
  message(FATAL_ERROR "INPUT_FILE not set")
endif()

# Optional expected regex list: EXPECT_REGEX_1, EXPECT_REGEX_2, ...
# Optional forbidden regex list: FORBID_REGEX_1, FORBID_REGEX_2, ...
# Optional: NORMALIZE_CASE=ON to lowercase output before matching (default ON)

if(NOT DEFINED NORMALIZE_CASE)
  set(NORMALIZE_CASE ON)
endif()

if(NOT EXISTS "${APP}")
  message(FATAL_ERROR "App not found at: ${APP}")
endif()
if(NOT EXISTS "${INPUT_FILE}")
  message(FATAL_ERROR "Input file not found: ${INPUT_FILE}")
endif()

# Run the app with stdin from INPUT_FILE
execute_process(
  COMMAND "${APP}"
  INPUT_FILE "${INPUT_FILE}"
  RESULT_VARIABLE code
  OUTPUT_VARIABLE out
  ERROR_VARIABLE err
  TIMEOUT 5
)

# Combine stdout+stderr for more robust debugging
set(all "${out}\n${err}")

# Normalize newlines
string(REPLACE "\r\n" "\n" all "${all}")
string(REPLACE "\r" "\n" all "${all}")

# Optionally normalize case (helps tolerate "Congratulations" vs "congratulations")
if(NORMALIZE_CASE)
  string(TOLOWER "${all}" all)
endif()

# Helpful on failure
set(_debug_header "=== APP OUTPUT BEGIN ===\n${all}\n=== APP OUTPUT END ===")

# Non-zero exit is a failure
if(NOT code EQUAL 0)
  message(FATAL_ERROR "App exited with code ${code}\n${_debug_header}")
endif()

# Check required regexes
set(i 1)
while(DEFINED EXPECT_REGEX_${i})
  set(rx "${EXPECT_REGEX_${i}}")
  if(NORMALIZE_CASE)
    string(TOLOWER "${rx}" rx)
  endif()

  string(REGEX MATCH "${rx}" matched "${all}")
  if(NOT matched)
    message(FATAL_ERROR
      "Expected pattern not found (EXPECT_REGEX_${i}): ${EXPECT_REGEX_${i}}\n${_debug_header}"
    )
  endif()
  math(EXPR i "${i}+1")
endwhile()

# Check forbidden regexes (optional)
set(j 1)
while(DEFINED FORBID_REGEX_${j})
  set(fr "${FORBID_REGEX_${j}}")
  if(NORMALIZE_CASE)
    string(TOLOWER "${fr}" fr)
  endif()

  string(REGEX MATCH "${fr}" fmatched "${all}")
  if(fmatched)
    message(FATAL_ERROR
      "Forbidden pattern was found (FORBID_REGEX_${j}): ${FORBID_REGEX_${j}}\n${_debug_header}"
    )
  endif()
  math(EXPR j "${j}+1")
endwhile()
