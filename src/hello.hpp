#ifndef HELLO_HPP
#define HELLO_HPP

// Case-insensitive strcmp-like comparison.
// Returns:
//   < 0 if s1 < s2
//   = 0 if s1 == s2
//   > 0 if s1 > s2
//
// Optional arguments:
//   skip_spaces : if true, spaces are ignored during comparison
//   max_chars   : if >= 0, only the first max_chars characters are compared
//                 (default -1 means compare the entire string)
int strcmp_case_insensitive(const char* s1, const char* s2,
                            bool skip_spaces = false,
                            int  max_chars   = -1);

#endif