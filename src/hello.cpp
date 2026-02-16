#include "hello.hpp"
#include <cctype> // std::tolower

int strcmp_case_insensitive(const char* s1, const char* s2) {
    // Optional: handle nullptr safely
    if (s1 == nullptr && s2 == nullptr) return 0;
    if (s1 == nullptr) return -1;
    if (s2 == nullptr) return 1;

    while (true) {
        unsigned char a = static_cast<unsigned char>(*s1);
        unsigned char b = static_cast<unsigned char>(*s2);

        int la = std::tolower(a);
        int lb = std::tolower(b);

        if (la != lb) {
            // strcmp-like: return difference at first mismatch
            return la - lb;
        }

        // if both are '\0', strings ended and are equal
        if (a == '\0') return 0;

        ++s1;
        ++s2;
    }
}
