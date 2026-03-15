#include <iostream>
#include "src/hello.hpp"

static void run_test(const char* s1, const char* s2,
                     bool skip_spaces = false, int max_chars = -1) {
    int result = strcmp_case_insensitive(s1, s2, skip_spaces, max_chars);

    std::cout << "The comparison of \""
              << s1 << "\" and \""
              << s2 << "\"";

    if (skip_spaces)     std::cout << " (skip spaces)";
    if (max_chars != -1) std::cout << " (max " << max_chars << " chars)";

    std::cout << " returns " << result << ".\n";
}

int main() {

    // ── Base: Case-Insensitive ────────────────────────────────────────────
    std::cout << "--- Base: Case-Insensitive Comparison ---\n";
    run_test("String one", "string two");
    run_test("String one", "string one");
    run_test("String two", "string one");

    // ── Base Edge Cases ───────────────────────────────────────────────────
    std::cout << "\n--- Edge Cases ---\n";
    run_test("", "");
    run_test("", "a");
    run_test("A", "");
    run_test("abc", "AbC");
    run_test("abc", "abD");
    run_test("abD", "abc");
    run_test("a",   "Aardvark");
    run_test("Aardvark", "a");
    run_test("hi!", "hi?");
    run_test("hi?", "hi!");

    // ── Add-On 3: Ordered Numbers ─────────────────────────────────────────
    std::cout << "\n--- Add-On 3: Ordered Numbers ---\n";
    run_test("2",               "50");
    run_test("2",               "10");
    run_test("20",              "5");
    run_test("20",              "1");
    run_test("100",             "100");
    run_test("2 Some String",   "50 Some String");
    run_test("2 Some String",   "10 Some String");
    run_test("20 Some String",  "5 Some String");
    run_test("20 Some String",  "1 Some String");
    run_test("100 Some String", "100 Some String");

    // ── Add-On 1: Skip Spaces ─────────────────────────────────────────────
    std::cout << "\n--- Add-On 1: Skip Spaces ---\n";
    run_test("my cool string",  "mycoolstring",  true);
    run_test("My Cool String",  "MyCoolString",  true);
    run_test("My Cool String",  "mycoolstring",  true);
    run_test("My Cool String ", "mycoolstring",  true);
    run_test(" My Cool String", "mycoolstring",  true);
    run_test("Another string",  "mycoolstring",  true);

    // ── Add-On 2: Max Characters ──────────────────────────────────────────
    std::cout << "\n--- Add-On 2: Max Characters ---\n";
    run_test("Hello World", "Hello Earth", false, 5);   // first 5 equal  → 0
    run_test("Hello World", "Hello Earth", false, 7);   // 7th char differs → non-zero
    run_test("abc",         "abD",         false, 2);   // only "ab"       → 0
    run_test("abc",         "abD",         false, 3);   // full compare    → non-zero
    run_test("Hello",       "Hi",          false, 0);   // max=0           → 0
    run_test("Hello",       "Hi",          false, -2);  // negative        → 0
    run_test("Hi",          "Hello World", false, 20);  // max > length    → compare fully

    // ── Add-On 1 + 2 + 3 Combined ────────────────────────────────────────
    std::cout << "\n--- Add-Ons Combined ---\n";
    run_test("My Cool String", "mycoolstring", true,  5);
    run_test("2 some string",  "50 somestring", true, 10);

    return 0;
}