#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

static int sign_of(int x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

TEST_CASE("case-insensitive ordering like strcmp") {
    REQUIRE(sign_of(strcmp_case_insensitive("String one", "string two")) == -1);
    REQUIRE(sign_of(strcmp_case_insensitive("String one", "string one")) == 0);
    REQUIRE(sign_of(strcmp_case_insensitive("String two", "string one")) == 1);
}

TEST_CASE("edge cases") {
    REQUIRE(sign_of(strcmp_case_insensitive("", "")) == 0);
    REQUIRE(sign_of(strcmp_case_insensitive("", "a")) == -1);
    REQUIRE(sign_of(strcmp_case_insensitive("A", "")) == 1);

    REQUIRE(sign_of(strcmp_case_insensitive("abc", "AbC")) == 0);
    REQUIRE(sign_of(strcmp_case_insensitive("abc", "abD")) == -1);
    REQUIRE(sign_of(strcmp_case_insensitive("abD", "abc")) == 1);

    REQUIRE(sign_of(strcmp_case_insensitive("a", "Aardvark")) == -1);
    REQUIRE(sign_of(strcmp_case_insensitive("Aardvark", "a")) == 1);

    REQUIRE(sign_of(strcmp_case_insensitive("hi!", "hi?")) == -1);
    REQUIRE(sign_of(strcmp_case_insensitive("hi?", "hi!")) == 1);
}
