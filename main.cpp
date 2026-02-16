#include <iostream>
#include "src/hello.hpp"

static void run_test(const char* s1, const char* s2) {
    int result = strcmp_case_insensitive(s1, s2);

    std::cout << "The comparison of \""
              << s1 << "\" and \""
              << s2 << "\" returns "
              << result << ".\n";
}

int main() {
    // Example-style tests
    run_test("String one", "string two");
    run_test("String one", "string one");
    run_test("String two", "string one");

    std::cout << "\n--- Edge Cases ---\n";
    run_test("", "");
    run_test("", "a");
    run_test("A", "");
    run_test("abc", "AbC");
    run_test("abc", "abD");
    run_test("a", "Aardvark");
    run_test("hi!", "hi?");

    return 0;
}
