#include "hello.hpp"
#include <cctype>   // std::tolower, std::isdigit
#include <cstdlib>  // std::strtoul

int strcmp_case_insensitive(const char* s1, const char* s2,
                            bool skip_spaces,
                            int  max_chars) {
    // Handle null pointers safely
    if (s1 == nullptr && s2 == nullptr) return 0;
    if (s1 == nullptr) return -1;
    if (s2 == nullptr) return 1;

    // Edge cases for max_chars:
    //   0        → compare nothing, strings are equal
    //   negative (other than sentinel -1) → treat as 0, strings are equal
    //   -1       → sentinel meaning "compare the entire string"
    if (max_chars == 0)  return 0;
    if (max_chars < -1)  return 0;

    int chars_compared = 0; // tracks characters consumed toward max_chars

    while (true) {
        // ── Add-On 1: Skip Spaces ────────────────────────────────────────
        if (skip_spaces) {
            while (*s1 == ' ') ++s1;
            while (*s2 == ' ') ++s2;
        }

        unsigned char a = static_cast<unsigned char>(*s1);
        unsigned char b = static_cast<unsigned char>(*s2);

        // ── Add-On 2: Maximum Number of Characters ───────────────────────
        // Stop comparing once we have consumed max_chars characters
        if (max_chars != -1 && chars_compared >= max_chars) return 0;

        // ── Add-On 3: Ordered Numbers ────────────────────────────────────
        // When both current characters are digits, parse the full number
        // numerically so that "2" < "50", "20" > "5", etc.
        if (std::isdigit(a) && std::isdigit(b)) {
            char* end1;
            char* end2;
            unsigned long num1 = std::strtoul(s1, &end1, 10);
            unsigned long num2 = std::strtoul(s2, &end2, 10);

            if (num1 != num2)
                return (num1 < num2) ? -1 : 1;

            // Numbers are equal — count the digits consumed toward max_chars
            chars_compared += static_cast<int>(end1 - s1);
            s1 = end1;
            s2 = end2;
            continue;
        }

        // ── Standard case-insensitive character comparison ────────────────
        int la = std::tolower(a);
        int lb = std::tolower(b);

        if (la != lb)
            return la - lb;

        // Both are '\0' — strings are equal
        if (a == '\0') return 0;

        ++s1;
        ++s2;
        ++chars_compared;
    }
}